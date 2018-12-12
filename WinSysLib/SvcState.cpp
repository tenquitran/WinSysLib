#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace WinSysLib;

//////////////////////////////////////////////////////////////////////////


CAtlString SvcState::toStr(ESvcState val)
{
    switch (val)
    {
    case ESvcState::Undefined:
        return L"Undefined";
    case ESvcState::ContinuePending:
        return L"SERVICE_CONTINUE_PENDING";
    case ESvcState::PausePending:
        return L"SERVICE_PAUSE_PENDING";
    case ESvcState::Paused:
        return L"SERVICE_PAUSED";
    case ESvcState::Running:
        return L"SERVICE_RUNNING";
    case ESvcState::StartPending:
        return L"SERVICE_START_PENDING";
    case ESvcState::StopPending:
        return L"SERVICE_STOP_PENDING";
    case ESvcState::Stopped:
        return L"SERVICE_STOPPED";
    default:
        ATLASSERT(FALSE); return L"";
    }
}

ESvcState SvcState::toSvcType(DWORD val)
{
    switch (val)
    {
    case SERVICE_CONTINUE_PENDING:
        return ESvcState::ContinuePending;
    case SERVICE_PAUSE_PENDING:
        return ESvcState::PausePending;
    case SERVICE_PAUSED:
        return ESvcState::Paused;
    case SERVICE_RUNNING:
        return ESvcState::Running;
    case SERVICE_START_PENDING:
        return ESvcState::StartPending;
    case SERVICE_STOP_PENDING:
        return ESvcState::StopPending;
    case SERVICE_STOPPED:
        return ESvcState::Stopped;
    default:
        ATLASSERT(FALSE); return ESvcState::Undefined;
    }
}
