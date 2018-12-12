#pragma once


namespace WinSysLib
{
    // Windows service state.
    enum class ESvcState : DWORD {
        Undefined       = 0,
        ContinuePending = SERVICE_CONTINUE_PENDING,    // the service is about to continue
        PausePending    = SERVICE_PAUSE_PENDING,       // the service is pausing
        Paused          = SERVICE_PAUSED,              // the service is paused
        Running         = SERVICE_RUNNING,             // the service is running
        StartPending    = SERVICE_START_PENDING,       // the service is starting
        StopPending     = SERVICE_STOP_PENDING,        // the service is stopping
        Stopped         = SERVICE_STOPPED,             // the service has stopped
    };


    // Converter for ESvcState values.
    class SvcState
    {
    public:
        // Convert ESvcState value to string.
        static CAtlString toStr(ESvcState val);

        // Convert Windows service state value (DWORD) to ESvcState.
        static ESvcState toSvcType(DWORD val);
    };
}
