/*
	Copyright (c) 2015-2016 Xavier Leclercq

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

#ifndef _ISHIKO_TESTFRAMEWORK_CORE_TESTTEARDOWNACTION_H_
#define _ISHIKO_TESTFRAMEWORK_CORE_TESTTEARDOWNACTION_H_

#include <boost/filesystem/path.hpp>
#include <vector>

namespace Ishiko
{
namespace TestFramework
{

class TestTeardownAction
{
public:
	TestTeardownAction();
	virtual ~TestTeardownAction();

	virtual void run();
};

class FilesTeardownAction : public TestTeardownAction
{
public:
	FilesTeardownAction();
	virtual ~FilesTeardownAction();

	virtual void run();

	void add(const boost::filesystem::path& path);

private:
	std::vector<boost::filesystem::path> d_files;
};

class DirectoriesTeardownAction : public TestTeardownAction
{
public:
	DirectoriesTeardownAction();
	virtual ~DirectoriesTeardownAction();

	virtual void run();

	void add(const boost::filesystem::path& path);

private:
	std::vector<boost::filesystem::path> d_directories;
};

}
}

#endif