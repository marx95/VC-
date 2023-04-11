#include "StdAfx.h"

void RecarregarMonstros(int aIndex)
{

	if(GS.cmm_RecarregarMonstros_Ativado == 0)
	{
		MsgParaJogador("[R. Monstros] Comando desabilitado",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_RecarregarMonstros_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[R. Monstros] %s", VerificarCtlCode(aIndex, GS.cmm_RecarregarMonstros_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	GameMonsterAllCloseAndReLoad();
	MsgParaJogador("[R. Monstros] Monstros recarregados!",aIndex);
}