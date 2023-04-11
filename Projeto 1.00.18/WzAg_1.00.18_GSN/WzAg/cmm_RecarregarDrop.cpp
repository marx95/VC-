#include "StdAfx.h"

void ReloadDrop(int aIndex)
{
	if(GS.cmm_RecarregarDrop_Ativado == 0)
	{
		MsgParaJogador("[R. Drop] Comando desativado!",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_RecarregarDrop_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[R. Drop] %s", VerificarCtlCode(aIndex, GS.cmm_RecarregarDrop_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}
	CarregarDropCustom();
	MsgParaJogador("[R. Drop] Drop Custom recarregado!",aIndex);
}