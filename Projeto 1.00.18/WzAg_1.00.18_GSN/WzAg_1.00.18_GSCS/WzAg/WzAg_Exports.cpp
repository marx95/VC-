#include "stdafx.h"

void ChecarVirtualProtect()
{
	DWORD OldProtect;
	if(!VirtualProtect(LPVOID(GS_BASE), 3911813, PAGE_EXECUTE_READWRITE, &OldProtect))
	{
		MessageBox(0, "Falha ao Iniciar as configurações da DLL", "WzAg.dll - MarxD", 0);
		::ExitProcess(0);
	}
}

extern "C" _declspec(dllexport) int AGSetInfo(int Language,char * Partition,int un0,char * SrvVer,char* SrvName, int SrvType,char * Addr7)  
{
	ChecarVirtualProtect();
	return WzAG.AGSetInfo(Language, Partition, un0, SrvVer, SrvName, SrvType, Addr7);
}

extern "C" _declspec(dllexport) int AGGetClientVersion(int unknown,char * VerBuff,char * SerialBuff) 
{
	ChecarVirtualProtect();
	return WzAG.AGGetClientVersion(unknown, VerBuff, SerialBuff) ;
}

extern "C" _declspec(dllexport) int AGSetSubInfo() 
{
	ChecarVirtualProtect();
	return WzAG.AGSetSubInfo();
}

extern "C" _declspec(dllexport) void AGGetKey(HANDLE handle,char* key,int startindex,int len)
{
	ChecarVirtualProtect();
	WzAG.AGGetKey(handle, key, startindex, len);
}

extern "C" _declspec(dllexport) int AGRequestData(int NoneUse,int GetType)
{
	ChecarVirtualProtect();
	return WzAG.AGRequestData(NoneUse, GetType);
}

extern "C" _declspec(dllexport) int AGGetDataBufferSize() 
{
	ChecarVirtualProtect();
	return WzAG.AGGetDataBufferSize();
}

extern "C" _declspec(dllexport) char * AGGetDataBuffer() 
{
	ChecarVirtualProtect();
	return WzAG.AGGetDataBuffer();
}

extern "C" _declspec(dllexport) int AGConnectSetFS() 
{
	ChecarVirtualProtect();
	return WzAG.AGConnectSetFS();
}

extern "C" _declspec(dllexport) int AGReleaseHandle() 
{
	ChecarVirtualProtect();
	return WzAG.AGReleaseHandle();
}

extern "C" _declspec(dllexport) void GameServerInfo()
{
	ChecarVirtualProtect();
	Iniciar_DLL();
}