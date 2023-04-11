#include "StdAfx.h"

void RecarregarMove(int aIndex)
{
	if(GS.cmm_RecarregarMove_Ativado == 0)
	{
		MsgParaJogador("[R. Move] Comando desabilitado",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_RecarregarMove_CtlCode)
	{
		MsgParaJogador("[R. Move] Comando somente para GameMaster.",aIndex);
		return;
	}

	CarregarMove();
	MsgParaJogador("[R. Move] Move Custom recarregado!",aIndex);
}