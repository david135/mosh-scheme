# Source Repository #

https://github.com/higepon/mosh

# Build from Git Source #

([Release tarballs](http://code.google.com/p/mosh-scheme/downloads/list) and [mosh-current](http://storage.osdev.info/pub/mosh/mosh-current.tar.gz) are already "bootstrapped". If you build from them, you can just `./configure && make && make install`. BSD users: use `gmake`.)

You will need some additional tool if you build Mosh from Git source.

Install subversion, re2c, bison, autoconf, automake, Gauche and latest mosh-current tarball release ( http://storage.osdev.info/pub/mosh/mosh-current.tar.gz ) then `./gen-git-build.sh`.

See [README](https://github.com/higepon/mosh/blob/master/README.md) for details.

`gen-git-build.sh` is not "fail-proof". Please run `git clean` if you failed something in generation process.