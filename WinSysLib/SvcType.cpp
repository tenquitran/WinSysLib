#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace WinSysLib;

//////////////////////////////////////////////////////////////////////////


CAtlString SvcType::toStr(ESvcType val)
{
    switch (val)
    {
    case ESvcType::Undefined:
        return L"Undefined";
    case ESvcType::KernelDriver:
        return L"SERVICE_KERNEL_DRIVER";
    case ESvcType::FileSystemDriver:
        return L"SERVICE_FILE_SYSTEM_DRIVER";
    case ESvcType::Adapter:
        return L"SERVICE_ADAPTER";
    case ESvcType::RecognizedDriver:
        return L"SERVICE_RECOGNIZER_DRIVER";
    case ESvcType::Driver:
        return L"SERVICE_DRIVER";
    case ESvcType::Win32OwnProcess:
        return L"SERVICE_WIN32_OWN_PROCESS";
    case ESvcType::Win32ShareProcess:
        return L"SERVICE_WIN32_SHARE_PROCESS";
    case ESvcType::ServiceWin32:
        return L"SERVICE_WIN32";
    case ESvcType::InteractiveProcess:
        return L"SERVICE_INTERACTIVE_PROCESS";
    case ESvcType::All:
        return L"SERVICE_TYPE_ALL";
    default:
        ATLASSERT(FALSE); return L"";
    }
}

ESvcType SvcType::toSvcType(DWORD val)
{
    switch (val)
    {
    case SERVICE_KERNEL_DRIVER:
        return ESvcType::KernelDriver;
    case SERVICE_FILE_SYSTEM_DRIVER:
        return ESvcType::FileSystemDriver;
    case SERVICE_ADAPTER:
        return ESvcType::Adapter;
    case SERVICE_RECOGNIZER_DRIVER:
        return ESvcType::RecognizedDriver;
    case SERVICE_DRIVER:
        return ESvcType::Driver;
    case SERVICE_WIN32_OWN_PROCESS:
        return ESvcType::Win32OwnProcess;
    case SERVICE_WIN32_SHARE_PROCESS:
        return ESvcType::Win32ShareProcess;
    case SERVICE_WIN32:
        return ESvcType::ServiceWin32;
    case SERVICE_INTERACTIVE_PROCESS:
        return ESvcType::InteractiveProcess;
    case SERVICE_TYPE_ALL:
        return ESvcType::All;
    default:
        ATLASSERT(FALSE); return ESvcType::Undefined;
    }
}
