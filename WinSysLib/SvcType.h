#pragma once


namespace WinSysLib
{
    // Windows service type.
    enum class ESvcType : DWORD {
        Undefined          = 0,
        KernelDriver       = SERVICE_KERNEL_DRIVER,           // driver service
        FileSystemDriver   = SERVICE_FILE_SYSTEM_DRIVER,      // file system driver service
        Adapter            = SERVICE_ADAPTER,
        RecognizedDriver   = SERVICE_RECOGNIZER_DRIVER,
        Driver             = SERVICE_DRIVER,                  // service of type KernelDriver, FileSystemDriver or RecognizedDriver
        Win32OwnProcess    = SERVICE_WIN32_OWN_PROCESS,       // service that runs in its own process
        Win32ShareProcess  = SERVICE_WIN32_SHARE_PROCESS,     // service that shares process with one or several services
        ServiceWin32       = SERVICE_WIN32,                   // service of type Win32OwnProcess or Win32ShareProcess
        InteractiveProcess = SERVICE_INTERACTIVE_PROCESS,     // the service can interact with the desktop
        All                = SERVICE_TYPE_ALL,                // service of type ServiceWin32, Adapter, Driver or InteractiveProcess
    };

    // OR operator for ESvcType.
    inline ESvcType operator |(ESvcType a, ESvcType b)
    {
        return (static_cast<ESvcType>(static_cast<DWORD>(a) | static_cast<DWORD>(b)));
    }

    // Compound assignment OR operator for ESvcType.
    inline ESvcType& operator |=(ESvcType& a, ESvcType b)
    {
        a = a | b;
        return a;
    }


    // Converter for ESvcType values.
    class SvcType
    {
    public:
        // Convert ESvcType value to string.
        static CAtlString toStr(ESvcType val);

        // Convert Windows service type value (DWORD) to ESvcType.
        static ESvcType toSvcType(DWORD val);
    };
}
