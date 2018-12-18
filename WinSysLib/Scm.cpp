#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace WinSysLib;

//////////////////////////////////////////////////////////////////////////


Scm::Scm(bool readOnly)
{
    DWORD access = (readOnly ? GENERIC_READ : SC_MANAGER_ALL_ACCESS);

    m_hScm = OpenSCManager(
        nullptr,    // local machine
        SERVICES_ACTIVE_DATABASE, 
        access);

    if (!m_hScm)
    {
        // TODO: throw exception with the error code (use GetLastError())
        ATLASSERT(FALSE);
    }
}

Scm::~Scm()
{
    if (m_hScm)
    {
#if _DEBUG
        BOOL res = 
#endif
        CloseServiceHandle(m_hScm);

        // TODO: log the error
        ATLASSERT(res);
    }
}
