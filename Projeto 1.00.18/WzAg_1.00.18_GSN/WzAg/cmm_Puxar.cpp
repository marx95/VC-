#include "StdAfx.h"

void Puxar(int aIndex, char *Nome)
{
	if(GS.cmm_Puxar_Ativado == 0)
	{
		MsgParaJogador("[Puxar] Comando desabilitado",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_Puxar_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[Puxar] %s", VerificarCtlCode(aIndex, GS.cmm_Puxar_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	if(strlen(Nome) < 4)
	{
		MsgParaJogador("[Puxar] Digite um nome válido!",aIndex);
		return;
	}

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3)
		{
			if(Procurar(gObj(i)->Name, Nome, true))
			{
				MsgParaJogador("[Puxar] Jogador Puxado com sucesso!", aIndex);
				gObjTeleport(i, gObj(aIndex)->MapNumber, gObj(aIndex)->X, gObj(aIndex)->Y);
				return;
			}
		}
	}

	MsgParaJogador("[Puxar] Jogador não encontrado.", aIndex);
}