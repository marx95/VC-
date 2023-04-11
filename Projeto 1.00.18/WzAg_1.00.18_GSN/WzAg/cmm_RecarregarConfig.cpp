#include "StdAfx.h"

void ReloadConfig(int aIndex)
{
	if(GS.cmm_RecarregarConfig_Ativado == 0)
	{
		MsgParaJogador("[R. Config] Comando desativado!",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_RecarregarConfig_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[R. Config] %s", VerificarCtlCode(aIndex, GS.cmm_RecarregarConfig_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	CarregarDefinicoesConfigs();
	CarregarConfigs();
	Carrega_NpcMaluco();

	// - Re-Calcula o CalCharacter
	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3) CalCharacterEx(i);
	}

	MsgParaJogador("[R. Config] Config. Custom recarregada!",aIndex);
}