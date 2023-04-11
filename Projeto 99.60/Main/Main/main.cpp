#include "StdAfx.h"

extern "C" _declspec(dllexport) void MarxD()
{
	return;
}

HANDLE m_DllModule;
BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch(ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			m_DllModule = hModule;
			Config();
			Iniciar_Anti_Hack();
		break;		 
	}
	return TRUE;						  
}
