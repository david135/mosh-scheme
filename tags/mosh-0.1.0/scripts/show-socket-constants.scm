(import (rnrs)
        (mosh socket))

(define (print x)
  (display x)
  (newline))

(print AF_INET)
(print AF_INET6)
(print AF_UNSPEC)
(print SOCK_STREAM)
(print SOCK_DGRAM)
(print AI_ADDRCONFIG)
(print AI_ALL)
(print AI_CANONNAME)
(print AI_NUMERICHOST)
(print AI_NUMERICSERV)
(print AI_PASSIVE)
(print AI_V4MAPPED)
(print IPPROTO_TCP)
(print IPPROTO_UDP)
(print IPPROTO_RAW)
(print SHUT_RD)
(print SHUT_WR)
(print SHUT_RDWR)
