#include "StdAfx.h"

void TotalOnline(int aIndex)
{
	if(GS.cmm_TotalOn_Ativado == 0)
	{
		MsgParaJogador("[Total On] Comando desabilitado",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_TotalOn_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[Total On] %s", VerificarCtlCode(aIndex, GS.cmm_TotalOn_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	int TotalOnlineAgora = VerTotalOnline();
	
	char MsgOutTotalOn[64];
	sprintf_s(MsgOutTotalOn, "[Total On] %d usuario(s) online!", TotalOnlineAgora);
	MsgParaJogador(MsgOutTotalOn,aIndex);
}