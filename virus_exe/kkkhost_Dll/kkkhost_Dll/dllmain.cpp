// dllmain.cpp: DLL 응용 프로그램의 진입점을 정의합니다.
#include "stdafx.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	DWORD ThreadId;
	HANDLE result;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);		//thread 가 새로 생성될시에 DLLMAIN 을 호출하지 않게 하는 함수 
		result = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Start_DLL_LOOP, 0, 0, &ThreadId);
		break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}


