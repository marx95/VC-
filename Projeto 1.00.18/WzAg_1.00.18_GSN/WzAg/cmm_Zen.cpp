#include "StdAfx.h"

void Zen(int aIndex, int Tipo)
{
	char Msg[255];

	if(GS.cmm_Zen_Ativado == 0 && Tipo == 1)
	{
		MsgParaJogador("[Zen] Comando desabilitado",aIndex);
		return;
	}

	if(GS.cmm_Zen_Ativado == 0) return;

	if(gObjCustom[aIndex].CtlCode < GS.cmm_Zen_CtlCode && Tipo == 1)
	{
		sprintf_s(Msg, "[Zen] %s", VerificarCtlCode(aIndex, GS.cmm_Zen_CtlCode));
		MsgParaJogador(Msg, aIndex);
		return;
	}

	if(gObjCustom[aIndex].Vip < GS.cmm_Zen_Vip && Tipo == 1)
	{
		MsgParaJogador("[Zen] Necessário ser Vip.",aIndex);
		return;
	}

	gObj(aIndex)->Money = GS.cmm_Zen_TmpZen;
	GCMoneySend(aIndex, gObj(aIndex)->Money);

	if(Tipo == 1)
	{
		sprintf(Msg, "[Zen] Atualizado para %d!", GS.cmm_Zen_TmpZen);
		MsgParaJogador(Msg,aIndex);
	}
	
}