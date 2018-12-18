#include "stdafx.h"

#include "../WinSysLib/WinSysLib.h"

//////////////////////////////////////////////////////////////////////////

using namespace WinSysLib;

//////////////////////////////////////////////////////////////////////////


int _tmain(int argc, _TCHAR* argv[])
{
    //ESvcType type = ESvcType::Win32OwnProcess | ESvcType::InteractiveProcess;

    // TODO: temp
    CAtlString svcName = L"W32Time";
    SvcInfo svcInfo = SvcInfoReader::checkServiceStatus(svcName);

    //int m = ServicesInfo::tmpGetN();

    //int n = A::getN();

	return 0;
}

