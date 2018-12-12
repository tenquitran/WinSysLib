#pragma once


namespace WinSysLib
{
    // Data about the Windows service.
    struct SvcInfo
    {
    public:
        SvcInfo();
        
    private:
        // Service name, or registration name.
        CAtlString m_serviceName;

        // Display name.
        CAtlString m_displayName;

        // Type of the service.
        ESvcType m_type;

        // Current state of the service.
        ESvcState m_state;

        // Load-order group name.
        CAtlString m_groupName;
    };
}
