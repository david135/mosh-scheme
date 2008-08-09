#!/usr/bin/env gosh
(define (proc-name->c-proc-name name)
  (call-with-string-io
   name
   (lambda (in out)
     (define (rec c)
       (cond
        [(eof-object? c)
         (display "Ex" out)]
        [else
         (case c
           [(#\?)
            (display "P" out)
            (rec (read-char in))]
           [(#\!)
            (display "D" out)
            (rec (read-char in))]
           [(#\%)
            (display "internal" out)
            (rec (read-char in))]
           [(#\$)
            (rec (read-char in))]
           [(#\>)
            (let1 c (read-char in)
              (if (char=? #\= c)
                  (begin
                    (display "Ge" out)
                    (rec (read-char in)))
                  (begin
                    (display "Gt" out)
                    (rec c))))]
           [(#\<)
            (let1 c (read-char in)
              (if (char=? #\= c)
                  (begin
                    (display "Le" out)
                    (rec (read-char in)))
                  (begin
                    (display "Lt" out)
                    (rec c))))]
           [(#\!)
            (rec (read-char in))]
           [(#\/)
            (display (char-upcase (read-char in)) out)
            (rec (read-char in))]
           [(#\=)
            (display "Eq" out)
            (rec (read-char in))]
           [(#\-)
            (let1 c  (read-char in)
              (if (char=? #\> c)
                  (display "To" out)
                  (display (char-upcase c) out)))
            (rec (read-char in))]
           [else
            (display c out)
            (rec (read-char in))])]))
     (rec (read-char in)))))

(define (main args)
  (load "./free-vars-decl.scm")
  (print "// Do not edit this file generated by gen-cproc.scm");
  (let1 procs (map symbol->string *free-vars-decl*)
    (format #t "const int cProcNum = ~d;\n" (length procs))
    (display "static const Object cProcs[] = {\n")
    (for-each (lambda (proc) (format #t "     Object::makeCProcedure(~a),\n" (proc-name->c-proc-name proc))) (reverse procs))
    (display "};\n")
;;     (display "#ifdef ENABLE_PROFILER\n")
;;     (display "static const ucs4char* cProcNames[] = {\n")
;;     (for-each (lambda (proc) (format #t "     UC(~s),\n" proc)) (reverse procs))
;;     (display "};\n")
;;     (display "#endif\n")
    0))
