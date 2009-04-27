(import (rnrs)
        (mosh)
        (match)
        (only (srfi :19) current-date date->string)
        (mosh socket))



(define (irc-bot server port nick channel irc-client)
  (let ([socket (make-client-socket server port)])
    (define (send text)
      (assert (<= (string-length text) 510))
      (socket-send socket (string->utf8 (string-append text "\r\n"))))
    (define (recv)
      (utf8->string (socket-recv socket 512)))
    (define (say text)
      (send (format "PRIVMSG ~a :~a" channel text)))
    (send (format "NICK ~a" nick))
    (send (format "USER ~a 0 * :~a" nick nick))
    (send (format "JOIN ~a" channel))
    (call/cc (lambda (return)
    (let loop ([data (recv)])
      (cond
       [(zero? (string-length data)) '()]
       [(#/:([^!]+).*PRIVMSG[^:]+:(.*)/ data) =>
        (lambda (m)
          (irc-client (list 'PRIVMSG (m 1) (m 2)) return say send))]
       [(#/^PING/ data)
        (send "PONG 0")]
       [(#/:.*433.*Nickname is already in use.*/ data)
        (irc-client (list 'ERROR 433) return say send)
        ])
      (loop (recv)))))
    (socket-close socket)))

(irc-bot "irc.freenode.net" "6666" "kaela" "#higepon"
         (lambda (msg return privmsg send)
           (match msg
             [('PRIVMSG who message)
              (format #t "~a <~a> ~a\n" (date->string (current-date) "~H:~M") who message)]
             [('ERROR 433)
              (error 'irc "Nickname is already in use")]
             [('ERROR e)
              (return e)])))
