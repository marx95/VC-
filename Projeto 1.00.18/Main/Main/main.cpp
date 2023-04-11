#include "StdAfx.h"

extern "C" _declspec(dllexport) void MarxD()
{
	return;
}

HANDLE m_DllModule;
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved){
switch(ul_reason_for_call)
{
	case DLL_PROCESS_ATTACH:
		m_DllModule = hModule;
		Iniciar_Anti_Hack();
		Config();
		Sleep(100);
		WinExec("AutoClick.exe MuNovus.net", 0);
	break;		 
}
return TRUE;						  
}
