#include "StdAfx.h"

void Resetar(int aIndex)
{
	if(GS.cmm_Resetar_Ativado == 0)
	{
		MsgParaJogador("[Reset] Comando desabilitado",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_Resetar_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[Reset] %s", VerificarCtlCode(aIndex, GS.cmm_Resetar_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	if(gObjCustom[aIndex].Vip < GS.cmm_Resetar_Vip)
	{
		MsgParaJogador("[Reset] Necessário ser Vip.",aIndex);
		return;
	}

	Reset(aIndex, 1);
}