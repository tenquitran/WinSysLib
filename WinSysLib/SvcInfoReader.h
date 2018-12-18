#pragma once


namespace WinSysLib
{
    // Stand-alone functions to get information on Windows services.
    class SvcInfoReader
    {
    public:
        // Check service status.
        // Parameters: svcName - service name.
        // Exceptions: std::bad_alloc
        // Returns: service info (use isValid() to check its state.
        static SvcInfo checkServiceStatus(const CAtlString& svcName);
    };
}
