#include "StdAfx.h"

void cmm_chuva(int aIndex, char * msg)
{
	if(gObjCustom[aIndex].CtlCode < GS.ADM_CtlCode) return;
	if(gObjCustom[aIndex].CtlCode == GS.ADM_Player_CtlCode) return;

	if(strlen(msg) == 0)
	{
		MsgPlayer("[Chuva] Tente /chuva X (Onde X é o numero de itens!", aIndex);
		return;
	}

	int Total = 0;
	sscanf_s(msg , "%d", &Total);

	if(Total == 0 || Total > 15)
	{
		MsgPlayer("[Chuva] Dígite um número válido! Max 15 Itens!!!", aIndex);
		return;
	}

	for(int i = 0; i < Total; i++)
	{

		int X = (gObj(aIndex)->X - (Total /2)) + rand()%(Total+1);
		int Y = (gObj(aIndex)->Y - (Total /2)) + rand()%(Total+1);
		KundunEventItemBoxOpen(gObj(aIndex), gObj(aIndex)->MapNumber, X, Y);
	}

	MsgPlayer("[Chuva] Tempestade terminada!", aIndex);
}