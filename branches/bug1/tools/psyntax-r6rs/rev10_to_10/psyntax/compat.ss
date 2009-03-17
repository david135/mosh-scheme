;;; Copyright (c) 2006, 2007 Abdulaziz Ghuloum and Kent Dybvig
;;;
;;; Permission is hereby granted, free of charge, to any person obtaining a
;;; copy of this software and associated documentation files (the "Software"),
;;; to deal in the Software without restriction, including without limitation
;;; the rights to use, copy, modify, merge, publish, distribute, sublicense,
;;; and/or sell copies of the Software, and to permit persons to whom the
;;; Software is furnished to do so, subject to the following conditions:
;;;
;;; The above copyright notice and this permission notice shall be included in
;;; all copies or substantial portions of the Software.
;;;
;;; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
;;; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
;;; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
;;; THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
;;; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
;;; FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
;;; DEALINGS IN THE SOFTWARE.

(library (psyntax compat)
  (export make-parameter parameterize define-record compile-core
          gensym void eval-core symbol-value set-symbol-value! file-options-spec
          read-annotated annotation? annotation-expression annotation-source
          load-serialized-library serialize-library
          annotation-stripped make-record-printer read-library-source-file)
  (import
    (rnrs)
    (rnrs mutable-pairs)
    (only (system) get-environment-variable)
    (except (mosh) make-parameter parameterize)
    (only (psyntax system $bootstrap)
          void #;gensym eval-core set-symbol-value! symbol-value)) ;; removed compile-core for mosh


(define (make-gensym-counter i)
  (define (inc)
    (set! i (+ i 1))
    i)
  inc)

(define gen-sym-start
  (let ([v (get-environment-variable "MOSH_GENSYM_START")])
    (if v
        (string->number v)
        0)))

(define gen-sym-counter (make-gensym-counter gen-sym-start))

(define (gensym . x)
  (string->symbol
  (if (null? x)
      (format "K~a" (gen-sym-counter))
      (format "K~a@~a" (gen-sym-counter) (car x)))))


  ;; defined for mosh
  (define read-annotated read)
;  (define (annotation-stripped x) (set-source-info! x #f))
  (define (annotation-stripped x) (annotation-expression x)) ;; what is difference between annotation-stripped and annotation-expression?
  (define (annotation? x) (source-info x))
;  (define (annotation? x) #f)
  (define (annotation-source x) (source-info x))
;  (define (annotation-source x) x)
  (define (annotation-expression x)
    (if (pair? x)
        (cons (car x) (cdr x))
        (display "line:46\n")))

(define (scm->fasl filename)
  (string-append filename ".fasl"))

(define (fasl-save filename obj)
  (call-with-port (open-file-output-port filename) (lambda (port) ((symbol-value 'fasl-write!) obj port))))

(define (fasl-load filename)
  (call-with-port (open-file-input-port filename) (symbol-value 'fasl-read!)))

;; (define (fasl-save filename obj)
;;   (call-with-port (open-output-file filename) (lambda (port) (write obj port))))

;; (define (fasl-load filename)
;;   (call-with-port (open-input-file filename) read))


;; (define (serialize-library filename obj)
;;   (format #t "serialize-library ~a\n..." filename)
;;   (let ([fasl-file (scm->fasl filename)])
;;     (when (file-exists? fasl-file)
;;       (delete-file fasl-file))
;;     (guard [c (#t (format #t "Warning:serialize-library failed " filename)
;;                   (when (file-exists? fasl-file)
;;                     (delete-file fasl-file))
;;                   #f)]
;;            (fasl-save fasl-file obj)
;;            (display "OK\n"))))

;; (define (load-serialized-library filename obj)
;;   (let ([fasl-file (scm->fasl filename)])
;;     ;; todo we may use file-newer? directory.
;;     (if (and (file-exists? fasl-file) ((symbol-value 'file-newer?) fasl-file filename))
;;         (let* ([expanded2core (symbol-value 'expanded2core)]
;;                [code (fasl-load fasl-file)]
;;                [pivot (cddddr (cddddr code))]
;;                [visit (expanded2core (car pivot))]
;;                [visit-proc (lambda () (eval-core visit))])
;;           (set-car! pivot visit-proc)
;;           (let* ([pivot (cdr pivot)]
;;                  [invoke (expanded2core (car pivot))])
;;             (set-car! pivot (lambda () (eval-core invoke)))
;;             (apply obj code))
;;           #t)
;;         #f)))

(define (serialize-library filename obj)
  (format #t "serialize-library ~a\n..." filename)
  (let* ([expanded2core (symbol-value 'expanded2core)]
         [compile (symbol-value 'compile-w/o-halt)]
         [code obj]
         [pivot (cddddr (cddddr code))]
         [visit (compile (expanded2core (car pivot)))])
    (set-car! pivot visit)
    (let* ([pivot (cdr pivot)]
           [invoke (compile (expanded2core (car pivot)))])
      (set-car! pivot invoke)))
  (let ([fasl-file (scm->fasl filename)])
    (when (file-exists? fasl-file)
      (delete-file fasl-file))
    (guard [c (#t (format #t "Warning:serialize-library failed ~a" filename c)
                  (when (file-exists? fasl-file)
                    (delete-file fasl-file))
                  #f)]
           (fasl-save fasl-file obj)
           #;(let ([restored (fasl-load fasl-file)])
             (unless (equal? obj restored)
                 (let loop ([x obj]
                            [y restored])
                   (cond
                    [(or (null? x) (null? y)) '()]
                    [else
                     (if (equal? (car x) (car y))
                         (loop (cdr x) (cdr y))
                         (begin
                           (unless (and (flonum? (car x)) (flonum? (car y)))
                             (format #t "fasl read/write have inconsistent state : wrong ~a : ~a\n"
                                                          (car x)
                                                          (car y))
                             (assertion-violation 'scmc2fasl
                                                  (format "fasl read/write have inconsistent state : wrong ~a : ~a\n"
                                                          (car x)
                                                          (car y))))
                           (loop (cdr x) (cdr y))))]
                       ))
                 ))
           (display "OK\n"))))

(define (load-serialized-library filename obj)
  (let ([fasl-file (scm->fasl filename)])
    ;; todo we may use file-newer? directory.
    (if (and (file-exists? fasl-file) ((symbol-value 'file-newer?) fasl-file filename))
        (let* ([expanded2core (symbol-value 'expanded2core)]
               [eval-compiled-core (symbol-value 'eval-compiled!)]
               [code (fasl-load fasl-file)]
               [pivot (cddddr (cddddr code))]
               [visit (car pivot)]
               [visit-proc (lambda () (eval-compiled-core visit))])
          (set-car! pivot visit-proc)
          (let* ([pivot (cdr pivot)]
                 [invoke (car pivot)])
            (set-car! pivot (lambda () (eval-compiled-core invoke)))
            (apply obj code))
          #t)
        #f)))


  (define (make-record-printer name printer)
    (lambda x
      (display "record printer")
      (for-each display x)))
  ;; defined for mosh end

  (define (compile-core . x)
    (apply error 'comile-core "not implementated" x))

  (define (read-library-source-file file-name)
        (with-input-from-file file-name read-annotated))

  (define make-parameter
    (case-lambda
      ((x) (make-parameter x (lambda (x) x)))
      ((x fender)
;       (assert (procedure? fender))
       (let ((x (fender x)))
         (case-lambda
           (() x)
           ((v) (set! x (fender v))))))))

  (define-syntax parameterize
    (lambda (x)
      (syntax-case x ()
        ((_ () b b* ...) (syntax (let () b b* ...)))
        ((_ ((olhs* orhs*) ...) b b* ...)
         (with-syntax (((lhs* ...) (generate-temporaries (syntax (olhs* ...))))
                       ((rhs* ...) (generate-temporaries (syntax (olhs* ...)))))
           (syntax (let ((lhs* olhs*) ...
                   (rhs* orhs*) ...)
               (let ((swap
                      (lambda ()
                        (let ((t (lhs*)))
                          (lhs* rhs*)
                          (set! rhs* t))
                        ...)))
                 (dynamic-wind
                   swap
                   (lambda () b b* ...)
                   swap)))))))))

(define-syntax define-record
  (lambda (x)
      (define (syn->str s)
          (symbol->string
              (syntax->datum s)))
    (define (gen-getter id)
      (lambda (fld)
        (datum->syntax id
          (string->symbol
            (string-append (syn->str id) "-" (syn->str fld))))))
    (define (gen-setter id)
      (lambda (fld)
        (datum->syntax id
          (string->symbol
            (string-append "set-" (syn->str id) "-" (syn->str fld) "!")))))
    (syntax-case x ()
      [(_ name (field* ...) printer)
       #`(begin 
           (define-record name (field* ...)) 
           (define rp (make-record-printer 'name printer)))]
      [(_ name (field* ...))
       (with-syntax ([(getter* ...)
                      (map (gen-getter #'name) #'(field* ...))]
                     [(setter* ...)
                      (map (gen-setter #'name) #'(field* ...))])
         #`(define-record-type name
             (sealed #t) ; for better performance
             (opaque #t) ; for security
             (nongenerative) ; for sanity
             (fields (mutable field* getter* setter*) ...)))])))

  (define (file-options-spec x) x)
)