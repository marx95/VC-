#include "StdAfx.h"

void ReloadTudo(int aIndex)
{
	if(GS.cmm_RecarregarTudo_Ativado == 0)
	{
		MsgParaJogador("[R. Tudo] Comando desativado!",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_RecarregarTudo_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[R. Tudo] %s", VerificarCtlCode(aIndex, GS.cmm_RecarregarTudo_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	MsgParaTodos("[Server] Recarregando configurações...", 0);
	RecarregarMonstros(aIndex);
	RecarregarLojas(aIndex);
	ReloadConfig(aIndex);
	ReloadDrop(aIndex);
	RecarregarMove(aIndex);

	MsgParaTodos("[Server] Configurações recarregadas!", 0);
}