# Mosh #
A Fast [R6RS](R6RS.md) Scheme interpreter.

## News ##
  * 2011/6/17 : **0.2.7** released [mosh-0.2.7.tar.gz](http://mosh-scheme.googlecode.com/files/mosh-0.2.7.tar.gz)
  * 2009/11/30 : Switched our code repository to [github](http://github.com/higepon/mosh)
    * We switched only the repository, we continue to use Google code for distribution or issue tracking.

## Features ##
  * Mostly R6RS compliant scheme interpreter.
  * Supports Linux, MacOS X, FreeBSD, NetBSD, Cygwin and Win32.
  * FFI on x86/x64
  * Many SRFIs and bundled libraries like [irregex](http://synthcode.com/scheme/irregex/).
  * Socket communication and POSIX process functions.
  * ...

## Source Code ##
https://github.com/higepon/mosh

## Documents ##
  * [User's Manual](http://mosh.monaos.org)
  * [Roadmap and Directions](RoadmapAndDirections.md)
  * [Developer's ML](http://groups.google.co.jp/group/mosh-developer-discuss)

## Release Note ##
  * 2011/6/17 : **0.2.7 released**
    * [mosh-0.2.7.tar.gz](http://mosh-scheme.googlecode.com/files/mosh-0.2.7.tar.gz)
    * Maintenance release.
    * Mosh will be linked with OpenSSL library when available in Linux/FreeBSD/MacOSX.
    * FFI API(`pointer-ref-*` and `pointer-set-*!` from (mosh ffi)) had changed.
    * SRFI-19 implementation learned the leap second inserted between 2008 and 2009.
    * nmosh user interface learned colour output. Set `NMOSH_CLICOLOR` environment variable to "enable" to enable this.
    * Ruby's ERB like template library (Experimental).
    * Facebook Graph API library (Experimental).
    * `make check` target now works with out-of-tree builds.
    * **New Platform support :**
      * NetBSD (gcc44 is required and specify them as CC and CXX.)
      * Wine 1.3 or later
      * MonaOS
    * **Bug fixes :**
      * VM: `apply` didn't preserve tail-context. See [Issue 204](https://code.google.com/p/mosh-scheme/issues/detail?id=204).
      * psyntax-mosh: Various bug-fixes from Ikarus psyntax. See [Issue 134](https://code.google.com/p/mosh-scheme/issues/detail?id=134).
      * Reader: Number reader now reads 2.2250738585072012e-308 flawlessly. See http://blog.practical-scheme.net/gauche/20110203-bitten-by-floating-point-numbers-again for details.
      * Reader: Fixed [Issue 178](https://code.google.com/p/mosh-scheme/issues/detail?id=178) reported by lp:~weinholt: A symbol immediately followed by string was not accepted by reader.
      * Reader: Fixed [Issue 181](https://code.google.com/p/mosh-scheme/issues/detail?id=181) reported by mrc.mgg: Number datum with "bar" like 1|53 was not accepted by reader. Note that mosh will ignore specified mantissa width.
      * Reader: Fixed [Issue 185](https://code.google.com/p/mosh-scheme/issues/detail?id=185) reported by mrc.mgg: SRFI-62 style datum comment was not accepted by reader in certain cases.
      * REPL: Fixed [Issue 199](https://code.google.com/p/mosh-scheme/issues/detail?id=199) reported by amoebae: Segmentation fault on printing circular object.
      * rnrs: Fixed [Issue 204](https://code.google.com/p/mosh-scheme/issues/detail?id=204): `call-with-values` didn't preserve tail-context.
      * rnrs: Fixed [Issue 183](https://code.google.com/p/mosh-scheme/issues/detail?id=183) and [Issue 186](https://code.google.com/p/mosh-scheme/issues/detail?id=186) (partially): `(display #\tab)` had outputted "x9;" instead of a tab character. Non-displayable chars still not fixed. See [Issue 186](https://code.google.com/p/mosh-scheme/issues/detail?id=186).
      * rnrs: Fixed [Issue 198](https://code.google.com/p/mosh-scheme/issues/detail?id=198) reported by amoebae (partially): `put-string` cannot be called during `put-string` of textual custom output port.
      * rnrs: Fixed [Issue 200](https://code.google.com/p/mosh-scheme/issues/detail?id=200) reported by mrc.mgg: `set-port-position!` to the last index is now acceptable.
      * rnrs: Fixed [Issue 195](https://code.google.com/p/mosh-scheme/issues/detail?id=195) reported by mrc.mgg: psyntax-mosh and nmosh had implemented SRFI-93 version of `with-syntax`.  A patch for psyntax-mosh was contributed by amoebae.
      * match: `match` couldn't match certain pattern.
      * FFI (API Change): `pointer-ref-*` and `pointer-set-*!` index is now scaled by C sizeof(TYPE). i.e. `(pointer-ref-c-pointer ptr num)` is now eqv. of `ptr[num]`. These indices are erroneously scaled by 1(byte) in prior releases.
      * nmosh: Native Win32 port was not able to remove directories.
      * nmosh: Fixed [Issue 201](https://code.google.com/p/mosh-scheme/issues/detail?id=201) reported by mrc.mgg: `assert` was not return any value.
      * nmosh: `library-path` procedure was not compatible with psyntax-mosh's one.
      * SRFI-1: Fixed [Issue 192](https://code.google.com/p/mosh-scheme/issues/detail?id=192): `delete-duplicates` now accepts `(delete-duplicates obj)` form.
      * SRFI-19: Fixed [Issue 188](https://code.google.com/p/mosh-scheme/issues/detail?id=188): SRFI-19 implementation now includes a leap second inserted in 2008-2009.
      * SRFI-26: `cut` and `cute` was not work with `<...>`.
      * SRFI-39: Fixed [Issue 184](https://code.google.com/p/mosh-scheme/issues/detail?id=184): SRFI-39 now implemented with (rnrs) constructs. Former psyntax-mosh used psyntax's `parameterize` which was not compatible with SRFI-39.
      * SRFI-42: `string-ec`, `vector-of-length-ec` and `min-ec` was not properly exported.


---


  * 2010/11/7 : **0.2.6 released**
    * [mosh-0.2.6.tar.gz](http://mosh-scheme.googlecode.com/files/mosh-0.2.6.tar.gz)
    * Maintenace release.
      * Starting from this release, Visual Studio builds are migrated to CMake.
        * See doc/README.CMake for details.
      * New build prerequisites:
        * oniguruma >= 5.9.0
        * CMake >= 2.8.0 (Windows, Visual Studio only)
          * Oniguruma library is unbundled from mosh distribution. Configure script will search oniguruma with following order; 1) using `onig-config' 2) using -lonig gcc option and user specified CFLAGS 3) if oniguruma source distribution is found in a subdir as named `onig' it will be build together.
      * Changes
        * New platform support includes FFI support:
          * Darwin x86\_64
          * FreeBSD amd64
        * New platform support WITHOUT FFI support:
          * Windows amd64 (Experimental)
        * New build environment support:
          * Visual Studio 2010 i386/amd64 (using CMake, experimental)
          * XCode 3.x amd64 (using CMake, experimental)
        * Now mosh REPL handles multiple-values like Gauche. When a procedure return multiple values, REPL will show each values unlike previous version (which discarded values other than the first.)
        * FreeBSD:
          * Use sysctl(3) to implement (mosh-executable-path) instead of procfs.
      * Bug fixes
        * (rnrs)
          * exact-non-negative-integer? had retuned incorrect value.
          * Fixed expt procedure bug reported by Eduardo Cavazos.
          * Fixed [Issue 147](https://code.google.com/p/mosh-scheme/issues/detail?id=147) reported by mrc.mgg: log procedure had returned incorrect value.
          * Fixed [Issue 148](https://code.google.com/p/mosh-scheme/issues/detail?id=148) reported by mrc.mgg: expt procedure is now much more faster than previous release. Now it uses GMP mpz\_pow\_ui when operands are fixnums.
          * Fixed [Issue 149](https://code.google.com/p/mosh-scheme/issues/detail?id=149) reported by mrc.mgg: Reader now handles the "."(period) charactor collectly.
          * Fixed [Issue 154](https://code.google.com/p/mosh-scheme/issues/detail?id=154) reported by tabe.fixedpoint: exact-integer-sqrt procedure now raises error when an inexact integer given.
          * Fixed [Issue 159](https://code.google.com/p/mosh-scheme/issues/detail?id=159) : assoc procedure now checks argments are list of pairs. (assoc '(0)) no longer causes SEGV.
          * Fixed [Issue 161](https://code.google.com/p/mosh-scheme/issues/detail?id=161) reported by tabe.fixedpoint: -(minus) procedure was returned 0 instead of raising an error when applied with 0 argument. Now (-) raises an &assertion error.
          * Fixed [Issue 169](https://code.google.com/p/mosh-scheme/issues/detail?id=169) reported by ianprice90: Reading 0 elements from a port was resulting in an eof-object.
          * Fixed [Issue 170](https://code.google.com/p/mosh-scheme/issues/detail?id=170) reported by ianprice90: Custom binary/text port's close procedure was not called.
          * Fixed [Issue 173](https://code.google.com/p/mosh-scheme/issues/detail?id=173) reported by ianprice90: string->number was returned an EOF object on empty string.
        * (mosh memcached)
          * memcached-set! procedure now collectly sends flags and expiry arguments.
        * (srfi :98)
          * get-environment-variable and get-environment-variables had returned incollect results at MinGW/Cygwin environment.
        * Core
          * Fixed shebang handling bug reported by Eduardo Cavazos.
          * Fixed [Issue 158](https://code.google.com/p/mosh-scheme/issues/detail?id=158): nmosh was not started when $HOME is not set or has wrong value.
            * Fixed [Issue 175](https://code.google.com/p/mosh-scheme/issues/detail?id=175) reported by marcomaggi: C procedures (DeclareProcedureName macro) was not set returning values count properly.
        * Documentation
          * Fixed [Issue 167](https://code.google.com/p/mosh-scheme/issues/detail?id=167) reported by amoebae: (mosh ffi) example was incorrect.
    * Known issues:
      * See http://code.google.com/p/mosh-scheme/issues/list for full list.
      * configure script will complain about
        * configure: WARNING: no configuration information is in libatomic\_ops
      * #t.BLAHBLAH... read as #t instead of raising error.
      * Win32/64 Host:
        * Win64 host support is experimental and lacks FFI support.
        * "make check" or "make test" tests are not work properly.
          * Visual Studio builds are suboptimal for performance due to absense of char32 support and the "computed goto"(used for direct-threading feature.)
          * Visual Studio 2008 SP1 sometimes won't finish their compilation when both link-time code generation(/LTCG) and /Ox are enabled.
          * mosh/nmosh cannot build using MinGW64.
        * MacOS X Host:
          * mosh/nmosh cannot build as an universal binary.
            * Direct-threading is disabled on XCode builds. This will reduce runtime performance. Use ./configure builds for performance.

...[ReleaseHistory](ReleaseHistory.md)