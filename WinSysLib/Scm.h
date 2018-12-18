#pragma once


namespace WinSysLib
{
    // SCM (service control manager) wrapper.
    class Scm
    {
    public:
        // Parameters: readOnly - true for read-only access.
        explicit Scm(bool readOnly);

        virtual ~Scm();

        operator SC_HANDLE()
        {
            return m_hScm;
        }

    private:
        Scm(const Scm&) = delete;
        Scm& operator=(const Scm&) = delete;

    private:
        SC_HANDLE m_hScm = nullptr;
    };
}
