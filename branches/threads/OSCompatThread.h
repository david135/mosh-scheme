/*
 * OSCompatThread.h -
 *
 *   Copyright (c) 2009  Higepon(Taro Minowa)  <higepon@users.sourceforge.jp>
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *   TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  $Id: OSCompatThread.h 261 2008-07-25 06:16:44Z higepon $
 */

#ifndef SCHEME_OSCOMPAT_THREAD_
#define SCHEME_OSCOMPAT_THREAD_


#ifdef __APPLE__
#define pthread_yield sched_yield
#endif
#include "scheme.h"

// Check sanity
// Boehm GC redirects pthread_create => GC_pthread_create with C macro.
#ifndef pthread_create
#error "pthread_create redirect does not exist"
#endif

// Check sanity
#ifdef __APPLE__
#  ifndef GC_DARWIN_THREADS
#    error "fatal"
#  endif
#elif defined(__FreeBSD__)
#  ifndef GC_FREEBSD_THREADS
#    error "fatal"
#  endif
#elif defined(__linux__)
#  ifdef GC_DARWIN_THREADS
#    error "fatal"
#endif
#  ifndef GC_LINUX_THREADS
#    error "fatal"
#  endif
#endif

// If you add new thread support for new operating system
// See and adde some macro to scheme.h, just before include gc.h

namespace scheme {

    class Mutex : public gc_cleanup
    {
    private:
        pthread_mutex_t mutex_;

    public:
        Mutex()
        {
            pthread_mutexattr_t mattr;
            pthread_mutexattr_init(&mattr);
            pthread_mutexattr_settype(&mattr, PTHREAD_MUTEX_RECURSIVE);
            pthread_mutex_init(&mutex_, &mattr);
            pthread_mutexattr_destroy(&mattr);
        }

        ~Mutex()
        {
            pthread_mutex_destroy(&mutex_);
        }

        void lock()
        {
            pthread_mutex_lock(&mutex_);
        }

        void unlock()
        {
            pthread_mutex_unlock(&mutex_);
        }

        bool tryLock()
        {
            return pthread_mutex_trylock(&mutex_) == 0;
        }
    };

    class Thread EXTEND_GC
    {
    private:
        static pthread_key_t selfKey;
        static pthread_key_t specficKey;
    public:
        static void initialize()
        {
            if (pthread_key_create(&selfKey, NULL) != 0) {
                fprintf(stderr, "fatal : Thread::init\n");
                ::exit(-1);
            }
            if (pthread_key_create(&specficKey, NULL) != 0) {
                fprintf(stderr, "fatal : Thread::init\n");
                ::exit(-1);
            }
            // Add dummy
            if (pthread_setspecific(selfKey, new Thread) != 0) {
                fprintf(stderr, "fatal : Thread store self\n");
                ::exit(-1);
            }
        }

        static Thread* self()
        {
            volatile void* value = pthread_getspecific(selfKey);
            MOSH_ASSERT(value != NULL);
            return (Thread*)value;
        }

        static void setSpecific(void* value)
        {
            pthread_setspecific(specficKey, value);
        }

        static void* getSpecific()
        {
            return pthread_getspecific(specficKey);
        }

        Thread() : lastError_(0)
        {
        }

        bool create(void* (*start)(void*), void* arg);

        bool join(void** returnValue)
        {
            if (GC_pthread_join(thread_, returnValue) == 0) {
                return true;
            } else {
                setLastError();
                return false;
            }
        }

        static void yield()
        {
            pthread_yield();
        }

        static void exit(void* exitValue)
        {
            pthread_exit(exitValue);
        }


    private:
        void setLastError()
        {
            lastError_ = errno;
        }

        pthread_t thread_;
        int lastError_;

    };

}; // namespace scheme

#endif // SCHEME_OSCOMPAT_THREAD_