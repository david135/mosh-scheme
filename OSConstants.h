// Do not edit, this file is generated from os-constants.scm
#ifdef AF_INET
osConstants->set(Symbol::intern(UC("AF_INET")), Bignum::makeInteger((long int)AF_INET));
#endif
#ifdef AF_INET6
osConstants->set(Symbol::intern(UC("AF_INET6")), Bignum::makeInteger((long int)AF_INET6));
#endif
#ifdef AF_UNSPEC
osConstants->set(Symbol::intern(UC("AF_UNSPEC")), Bignum::makeInteger((long int)AF_UNSPEC));
#endif
#ifdef SOCK_STREAM
osConstants->set(Symbol::intern(UC("SOCK_STREAM")), Bignum::makeInteger((long int)SOCK_STREAM));
#endif
#ifdef SOCK_DGRAM
osConstants->set(Symbol::intern(UC("SOCK_DGRAM")), Bignum::makeInteger((long int)SOCK_DGRAM));
#endif
#ifdef SOCK_RAW
osConstants->set(Symbol::intern(UC("SOCK_RAW")), Bignum::makeInteger((long int)SOCK_RAW));
#endif
#ifdef AI_ADDRCONFIG
osConstants->set(Symbol::intern(UC("AI_ADDRCONFIG")), Bignum::makeInteger((long int)AI_ADDRCONFIG));
#endif
#ifdef AI_ALL
osConstants->set(Symbol::intern(UC("AI_ALL")), Bignum::makeInteger((long int)AI_ALL));
#endif
#ifdef AI_CANONNAME
osConstants->set(Symbol::intern(UC("AI_CANONNAME")), Bignum::makeInteger((long int)AI_CANONNAME));
#endif
#ifdef AI_NUMERICHOST
osConstants->set(Symbol::intern(UC("AI_NUMERICHOST")), Bignum::makeInteger((long int)AI_NUMERICHOST));
#endif
#ifdef AI_NUMERICSERV
osConstants->set(Symbol::intern(UC("AI_NUMERICSERV")), Bignum::makeInteger((long int)AI_NUMERICSERV));
#endif
#ifdef AI_PASSIVE
osConstants->set(Symbol::intern(UC("AI_PASSIVE")), Bignum::makeInteger((long int)AI_PASSIVE));
#endif
#ifdef AI_V4MAPPED
osConstants->set(Symbol::intern(UC("AI_V4MAPPED")), Bignum::makeInteger((long int)AI_V4MAPPED));
#endif
#ifdef IPPROTO_TCP
osConstants->set(Symbol::intern(UC("IPPROTO_TCP")), Bignum::makeInteger((long int)IPPROTO_TCP));
#endif
#ifdef IPPROTO_UDP
osConstants->set(Symbol::intern(UC("IPPROTO_UDP")), Bignum::makeInteger((long int)IPPROTO_UDP));
#endif
#ifdef IPPROTO_RAW
osConstants->set(Symbol::intern(UC("IPPROTO_RAW")), Bignum::makeInteger((long int)IPPROTO_RAW));
#endif
#ifdef SHUT_RD
osConstants->set(Symbol::intern(UC("SHUT_RD")), Bignum::makeInteger((long int)SHUT_RD));
#endif
#ifdef SHUT_WR
osConstants->set(Symbol::intern(UC("SHUT_WR")), Bignum::makeInteger((long int)SHUT_WR));
#endif
#ifdef SHUT_RDWR
osConstants->set(Symbol::intern(UC("SHUT_RDWR")), Bignum::makeInteger((long int)SHUT_RDWR));
#endif
osConstants->set(Symbol::intern(UC("size-of-char")), Bignum::makeInteger(sizeof(char)));
osConstants->set(Symbol::intern(UC("size-of-bool")), Bignum::makeInteger(sizeof(bool)));
osConstants->set(Symbol::intern(UC("size-of-short")), Bignum::makeInteger(sizeof(short)));
osConstants->set(Symbol::intern(UC("size-of-int")), Bignum::makeInteger(sizeof(int)));
osConstants->set(Symbol::intern(UC("size-of-long")), Bignum::makeInteger(sizeof(long)));
osConstants->set(Symbol::intern(UC("size-of-void*")), Bignum::makeInteger(sizeof(void*)));
osConstants->set(Symbol::intern(UC("size-of-size_t")), Bignum::makeInteger(sizeof(size_t)));
{
    struct x { char y; char z; };
    osConstants->set(Symbol::intern(UC("align-of-char")), Object::makeFixnum(offsetof(x, z)));
}
{
    struct x { char y; bool z; };
    osConstants->set(Symbol::intern(UC("align-of-bool")), Object::makeFixnum(offsetof(x, z)));
}
{
    struct x { char y; short z; };
    osConstants->set(Symbol::intern(UC("align-of-short")), Object::makeFixnum(offsetof(x, z)));
}
{
    struct x { char y; int z; };
    osConstants->set(Symbol::intern(UC("align-of-int")), Object::makeFixnum(offsetof(x, z)));
}
{
    struct x { char y; long z; };
    osConstants->set(Symbol::intern(UC("align-of-long")), Object::makeFixnum(offsetof(x, z)));
}
{
    struct x { char y; void* z; };
    osConstants->set(Symbol::intern(UC("align-of-void*")), Object::makeFixnum(offsetof(x, z)));
}
{
    struct x { char y; size_t z; };
    osConstants->set(Symbol::intern(UC("align-of-size_t")), Object::makeFixnum(offsetof(x, z)));
}
{
    struct x { char y; float z; };
    osConstants->set(Symbol::intern(UC("align-of-float")), Object::makeFixnum(offsetof(x, z)));
}
{
    struct x { char y; double z; };
    osConstants->set(Symbol::intern(UC("align-of-double")), Object::makeFixnum(offsetof(x, z)));
}
{
    struct x { char y; int8_t z; };
    osConstants->set(Symbol::intern(UC("align-of-int8_t")), Object::makeFixnum(offsetof(x, z)));
}
{
    struct x { char y; int16_t z; };
    osConstants->set(Symbol::intern(UC("align-of-int16_t")), Object::makeFixnum(offsetof(x, z)));
}
{
    struct x { char y; int32_t z; };
    osConstants->set(Symbol::intern(UC("align-of-int32_t")), Object::makeFixnum(offsetof(x, z)));
}
{
    struct x { char y; int64_t z; };
    osConstants->set(Symbol::intern(UC("align-of-int64_t")), Object::makeFixnum(offsetof(x, z)));
}
