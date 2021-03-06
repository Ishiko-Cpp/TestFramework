/*
    Copyright (c) 2016-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tests/blob/main/LICENSE.txt
*/

#ifndef _ISHIKO_TESTS_CORE_PROCESSACTION_H_
#define _ISHIKO_TESTS_CORE_PROCESSACTION_H_

#include "TestSetupAction.h"
#include "TestTeardownAction.h"
#include "Ishiko/Process/ChildProcess.h"
#include <string>
#include <memory>

namespace Ishiko
{
namespace Tests
{

class ProcessAction : public TestSetupAction, public TestTeardownAction
{
public:
    typedef std::shared_ptr<ProcessAction> shared_ptr;

    enum EMode
    {
        eWaitForExit,
        eTerminate
    };

    ProcessAction(const std::string& commandLine, EMode mode);
    ~ProcessAction() override;

    void setup() override;
    void teardown() override;

private:
    std::string m_commandLine;
    EMode m_mode;
    Process::ChildProcess m_processHandle;
};

}
}

#endif
