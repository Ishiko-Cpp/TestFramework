/*
    Copyright (c) 2005-2019 Xavier Leclercq

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

#include "TestNumber.h"

namespace Ishiko
{
namespace Tests
{

TestNumber::TestNumber()
{
}

TestNumber::TestNumber(int major)
{
    m_number.push_back(major);
}

TestNumber::TestNumber(int major, int minor)
{
    m_number.push_back(major);
    m_number.push_back(minor);
}

size_t TestNumber::depth() const
{
    return m_number.size();
}

int TestNumber::part(size_t i) const
{
    return m_number[i];
}

bool TestNumber::operator ==(const TestNumber& other) const
{
    return (m_number == other.m_number);
}

bool TestNumber::operator !=(const TestNumber& other) const
{
    return (m_number != other.m_number);
}

TestNumber& TestNumber::operator ++()
{
    if (!m_number.empty())
    {
        ++m_number.back();
    }
    return *this;
}

TestNumber TestNumber::operator ++(int)
{
    TestNumber result(*this);
    if (!m_number.empty())
    {
        ++m_number.back();
    }
    return result;
}

TestNumber TestNumber::getDeeperNumber() const
{
    TestNumber result = *this;
    result.m_number.push_back(1);
    return result;
}

}
}
