#!/usr/bin/env gosh
(use gauche.sequence)
(use srfi-1)
(use util.match)

;; same as Object::makeInt
(define (make-int i)
  (+ (ash i 2) 1))

(define (make-instruction i)
  (+ (ash i 5) 14))

(define (make-seq s e)
  (let loop ([s s]
             [ret '()])
    (if (> s e)
        (reverse ret)
        (loop (+ s 1) (cons s ret)))))

(define (print-insn lst)
  (format #t "static void* dispatch_table[~d] = {\n" (make-instruction (length lst)))
  (let1 insn-indexes (map make-instruction (make-seq 0 (- (length lst) 1)))
    (let loop ([i 0]
               [lst lst])
      (cond
       [(null? lst)
        '()]
       [(memq i insn-indexes)
        (format #t "&&LABEL_~a,\n" (car lst))
        (loop (+ i 1) (cdr lst))]
       [else
        (print "&&LABEL_DEFAULT,")
        (loop (+ i 1) lst)])))
  (print "};"))


(define (main args)
  (format #t "// Do not edit this file generated by ~a\n" (first args))
  (print-insn
   (with-input-from-file (second args)
     (lambda ()
       (let loop ([obj (read)]
                  [ret '()])
         (if (eof-object? obj)
             (reverse ret)
             (match obj
               [('define-insn name n)
                (loop (read) (cons name ret))]))))))
  0
)
