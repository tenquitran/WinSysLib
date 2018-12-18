#pragma once


namespace WinSysLib
{
    // Data about the Windows service.
    struct SvcInfo
    {
    public:
        explicit SvcInfo(const CAtlString& svcName);

        // Returns true if the data are valid.
        bool isValid() const;

    private:
        // Service name.
        CAtlString m_serviceName;

        // Display name.
        CAtlString m_displayName;

        // Type of the service.
        ESvcType m_type = { ESvcType::Undefined };

        // Current state of the service.
        ESvcState m_state = { ESvcState::Undefined };

        // Load-order group name.
        CAtlString m_groupName;
    };
}
