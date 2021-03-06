/*
    Copyright (c) 2016-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tests/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_TESTS_TESTS_CORE_TESTSETUPACTIONSTESTS_TESTSETUPACTIONSTESTS_H_
#define _ISHIKO_TESTS_TESTS_CORE_TESTSETUPACTIONSTESTS_TESTSETUPACTIONSTESTS_H_

#include <Ishiko/Tests/Core.h>

class TestSetupActionsTests : public Ishiko::Tests::TestSequence
{
public:
    TestSetupActionsTests(const Ishiko::Tests::TestNumber& number, const Ishiko::Tests::TestEnvironment& environment);
};

#endif
