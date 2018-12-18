#include "stdafx.h"

//////////////////////////////////////////////////////////////////////////

using namespace WinSysLib;

//////////////////////////////////////////////////////////////////////////


SvcInfo SvcInfoReader::checkServiceStatus(const CAtlString& svcName)
{
    // TODO: add exception handling and remove the exception handling specification from the function's comment in the header.

    DWORD err = {};

    SvcInfo svcInfo(svcName);

    //SERVICE_STATUS_PROCESS status = {};

    Scm scm(true);

    // TODO: temp
#if 1

#if 0
    SC_HANDLE hScm = OpenSCManager(
        nullptr,                /* Computer name or NULL for local computer */
        SERVICES_ACTIVE_DATABASE,      /* SCM database name */
        SC_MANAGER_CREATE_SERVICE);    /* ... or SC_MANAGER_ALL_ACCESS, etc. */
    if (!hScm)
    {
        err = GetLastError();
        /* ... error, use GetLastError() */
    }
#endif

    SC_HANDLE hService = OpenService(scm, svcName, GENERIC_READ);
    if (!hService)
    {
        err = GetLastError();
        //goto cleanup;
    }
#endif

    BOOL res = FALSE;

    // Current and required buffer size (in bytes).
    DWORD cbBuff = {};
    DWORD cbRequired = {};

    std::unique_ptr<BYTE[]> spBuff;

    while (  !(res = QueryServiceStatusEx(hService, 
                                          SC_STATUS_PROCESS_INFO, 
                                          (spBuff ? spBuff.get() : nullptr), 
                                          cbBuff, 
                                          &cbRequired))
            && ERROR_INSUFFICIENT_BUFFER == (err = GetLastError()))
    {
        cbBuff = cbRequired;

        spBuff.reset();
        spBuff = std::make_unique<BYTE[]>(cbBuff);
    }

    if (!res)
    {
        // TODO: log the error and exit
        ;
    }

    SERVICE_STATUS_PROCESS *pStatus = (SERVICE_STATUS_PROCESS *)spBuff.get();

    // TODO: fill in the data
    ;

    // TODO: temp
#if 1
    CloseServiceHandle(hService);

    //CloseServiceHandle(hScm);
#endif

    return svcInfo;
}
