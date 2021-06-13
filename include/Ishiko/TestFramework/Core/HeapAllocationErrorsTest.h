/*
    Copyright (c) 2000-2019 Xavier Leclercq

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
    THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
    IN THE SOFTWARE.
*/

#ifndef _ISHIKO_TESTFRAMEWORK_CORE_HEAPALLOCATIONERRORSTEST_H_
#define _ISHIKO_TESTFRAMEWORK_CORE_HEAPALLOCATIONERRORSTEST_H_

#include "Test.h"
#include "TestSequence.h"

namespace Ishiko
{
namespace Tests
{

class HeapAllocationErrorsTest : public Test
{
public:
    HeapAllocationErrorsTest(const TestNumber& number, const std::string& name,
        void (*runFct)(Test& test));
    HeapAllocationErrorsTest(const TestNumber& number, const std::string& name,
        void (*runFct)(Test& test), const TestEnvironment& environment);

protected:
    void doRun() override;

private:
    class InnerObserver : public Observer
    {
    public:
        InnerObserver(Test& test);

        void onCheckFailed(const Test& source, const std::string& message, const char* file, int line) override;

    private:
        Test& m_test;
    };

    std::shared_ptr<Test> m_test;
    std::shared_ptr<InnerObserver> m_innerObserver;
};

}
}

#endif
