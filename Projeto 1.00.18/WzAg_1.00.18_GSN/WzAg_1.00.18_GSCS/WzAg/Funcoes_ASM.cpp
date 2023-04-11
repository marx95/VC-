#include "StdAfx.h"
#define RtlFillMemory(Destination,Length,Fill) memset((Destination),(Fill),(Length))
void HookThis (DWORD dwMyFuncOffset,DWORD dwJmpOffset)
{
	*(DWORD*)(dwJmpOffset+1) = (DWORD)(dwMyFuncOffset) - (dwJmpOffset+5);
}

void SetNop(DWORD dwOffset, int Size)
{
	for(int n=0; n < Size; n++){
	*(BYTE*)(dwOffset+n) = 0x90;
	}
}

void SetRetn(DWORD dwOffset)
{
	*(BYTE*)(dwOffset) = 0xC3;
}

void SetByte(DWORD dwOffset, BYTE btValue)
{
	*(BYTE*)(dwOffset) = btValue;
}

void SetWord(DWORD dwOffset, WORD wValue)
{
	*(PWORD)(dwOffset) = wValue;
}

void SetDWord(DWORD dwOffset, DWORD dwValue){
	*(PDWORD)(dwOffset) = dwValue;
}