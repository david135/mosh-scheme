#!/usr/bin/env gosh
(define (proc-name->c-proc-name name)
  (call-with-string-io name
                       (lambda (in out)
                         (let loop ([c (read-char in)])
                           (cond
                            [(eof-object? c)
                             (display "Ex" out)]
                            [else
                             (case c
                               [(#\?)
                                (display "P" out)]
                               [(#\!) '()]
                               [(#\/)
                                (display (char-upcase (read-char in)) out)]
                               [(#\=)
                                (display "Eq" out)]
                               [(#\-)
                                (let1 c  (read-char in)
                                  (if (char=? #\> c)
                                      (display "To" out)
                                      (display (char-upcase c) out)))]
                               [else
                                (display c out)])
                             (loop (read-char in))])))))

(define (main args)
  (load "./free-vars-decl.scm")
  (print "// Do not edit this file generated by gen-cproc.scm");
  (let1 procs (map symbol->string *free-vars-decl*)
    (format #t "const int cProcNum = ~d;\n" (length procs))
    (display "static const Object cProcs[] = {\n")
    (for-each (lambda (proc) (format #t "     Object::makeCProcedure(~a),\n" (proc-name->c-proc-name proc))) (reverse procs))
    (display "};\n")
  0))