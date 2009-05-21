/*
 * OSCompatThreadTest - Test for OS compatibility thread functions
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
 *  $Id: TestVector.cpp 183 2008-07-04 06:19:28Z higepon $
 */
#include <gtest/gtest.h>

#include "scheme.h"
#include "Object.h"
#include "Object-inl.h"
#include "Pair.h"
#include "Pair-inl.h"
#include "OSCompat.h"
#include "ByteVector.h"
#include "PortProcedures.h"
#include "OSCompatThread.h"

using namespace scheme;

class MoshTest : public testing::Test {
protected:
    virtual void SetUp() {
        mosh_init();
    }
};

static void* return1Func(void* param)
{
    static int ret = 1;
    return &ret;
}

static void* return2Func(void* param)
{
    static int ret = 2;
    return &ret;
}

static void* returnFixnum(void* param)
{
    static Object ret = Object::makeFixnum(*(int*)param + 1234);
    return &ret;
}


TEST_F(MoshTest, simple) {
    Thread thread;
    ASSERT_TRUE(thread.create(return1Func, NULL));
    int* ret;
    ASSERT_TRUE(thread.join((void**)&ret));
    EXPECT_EQ(1, *ret);
}

TEST_F(MoshTest, simpleObject) {
    Thread thread;
    int arg = 2;
    ASSERT_TRUE(thread.create(returnFixnum, &arg));
    Object* ret;
    ASSERT_TRUE(thread.join((void**)&ret));
    EXPECT_EQ(1236, (*ret).toFixnum());
}


TEST_F(MoshTest, twoThreads) {
    Thread thread1;
    ASSERT_TRUE(thread1.create(return1Func, NULL));
    int* ret;
    ASSERT_TRUE(thread1.join((void**)&ret));

    Thread thread2;
    ASSERT_TRUE(thread2.create(return2Func, NULL));
    ASSERT_TRUE(thread2.join((void**)&ret));
    EXPECT_EQ(2, *ret);
}

TEST_F(MoshTest, twoThreads2) {
    Thread thread1;
    ASSERT_TRUE(thread1.create(return1Func, NULL));
    int* ret;

    Thread thread2;
    ASSERT_TRUE(thread2.create(return2Func, NULL));
    ASSERT_TRUE(thread2.join((void**)&ret));
    EXPECT_EQ(2, *ret);
    ASSERT_TRUE(thread1.join((void**)&ret));
    EXPECT_EQ(1, *ret);
}

static void* checkSelf(void* param)
{
    while (Thread::self() == NULL) {
    }
    EXPECT_EQ((Thread*)param, Thread::self());
    return NULL;
}

TEST_F(MoshTest, self) {
    Thread thread;
    ASSERT_TRUE(thread.create(checkSelf, &thread));
    thread.join(NULL);
}

static void* checkYield(void* param)
{
    Thread::yield();
    return NULL;
}

TEST_F(MoshTest, yield) {
    Thread thread;
    ASSERT_TRUE(thread.create(checkYield, &thread));
    thread.join(NULL);
}

static void* checkExit(void* param)
{
    static int ret = -1;
    Thread::exit(&ret);
    return NULL;
}

TEST_F(MoshTest, exit) {
    Thread thread;
    ASSERT_TRUE(thread.create(checkExit, &thread));
    int* ret = 0;
    thread.join((void**)&ret);
    EXPECT_EQ(-1, *ret);
}

static void hoge()
{
    int* value = (int*)Thread::getSpecific();
    EXPECT_EQ(1234, *value);
}

static void* checkSpecific(void* param)
{
    int value = 1234;
    Thread::setSpecific(&value);
    hoge();
    return NULL;
}

TEST_F(MoshTest, checkSpecific) {
    Thread thread;
    ASSERT_TRUE(thread.create(checkSpecific, &thread));
    thread.join(NULL);
}

Mutex* mutex = NULL;

void* checkMutex(void* param)
{
    EXPECT_FALSE(mutex->tryLock());
    return NULL;
}

TEST_F(MoshTest, checkMutex) {
    Thread thread;
    mutex = new Mutex;
    mutex->lock();
    ASSERT_TRUE(thread.create(checkMutex, &thread));
    thread.join(NULL);
    mutex->unlock();
}

Mutex* mutex2 = NULL;

void* checkMutex2(void* param)
{
    EXPECT_TRUE(mutex->tryLock());
    return NULL;
}

TEST_F(MoshTest, checkMutex2) {
    Thread thread;
    mutex2 = new Mutex;
    ASSERT_TRUE(thread.create(checkMutex2, &thread));
    thread.join(NULL);
}

static int value = 0;
static bool valueOK = false;

void* checkCondition(void* param)
{
    Condition* condition = (Condition*)param;
    value = 2;
    valueOK = true;
    EXPECT_TRUE(condition->notify());
    return NULL;
}

TEST_F(MoshTest, conditon) {
    Condition condition;
    Thread thread;
    ASSERT_TRUE(thread.create(checkCondition, &condition));
    while (!valueOK) {
        ASSERT_TRUE(condition.wait());
    }
    EXPECT_EQ(2, value);
}

static int value2 = 0;
static bool valueOK2 = false;

void* checkCondition2(void* param)
{
    Condition* condition = (Condition*)param;
    value2 = 2;
    valueOK2 = true;
    EXPECT_TRUE(condition->notifyAll());
    return NULL;
}

TEST_F(MoshTest, conditon2) {
    Condition condition;
    Thread thread;
    ASSERT_TRUE(thread.create(checkCondition2, &condition));
    while (!valueOK2) {
        ASSERT_TRUE(condition.wait());
    }
    EXPECT_EQ(2, value2);
}

