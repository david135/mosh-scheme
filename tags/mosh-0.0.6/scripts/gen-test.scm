#!/usr/bin/env gosh
(use gauche.sequence)
(use util.match)

;; Generate test.scm for C++ from test-data.scm

(define (print-header)
  (print ";; Do not edit this file generated by gen-test.scm")
  (print "(define *test-error* '())")
  (print "(define *test-ret* '())")
)

(define (print-footer)
  (print "(if (null? *test-error*)")
  (print "(display \"passed.\n\")")
  (print "(display *test-error*))"))

(define (print-test p)
  (define (rec expect test)
    (print (format "~s"
                   `(display "test ")))
    (print (format "~s"
                   `(display ',test)))
    (print (format "~s"
                   `(display ", expects ")))
    (print (format "~s"
                   `(display ',expect)))
    (let loop ([t test])
      (if (null? (cdr t))
          (write `(set! *test-ret* ,(car t)))
          (begin
            (write (car t))
            (loop (cdr t)))))
    (write `(if (equal? *test-ret* ',expect)
                (display " ===> ok\n")
                (begin
                  (set! *test-error* (cons (quote ,@test) *test-error*))
                  (display " ===> NG got ")
                  (write *test-ret*)
                  (display "\n")
                  (error "test" "test failed" '(,@test))))))
  (match p
    [('lib expect . test)
     (print '(init-library-table))
     (rec expect test)]
    [('mosh-only expect . test)
     (rec expect test)]
    [('error . test)
     (rec #t (list `(equal? 'error (guard (con [#t 'error])
                                    ,@test))))]
    [(expect . test)
     (rec expect test)]))

(define (main args)
  (print-header)
  (with-input-from-file (cadr args)
    (lambda ()
      (let loop ((obj (read)))
        (cond ((eof-object? obj) '())
              (else
               (print-test obj)
               (loop (read)))))))
  (print-footer)
  (exit 0))