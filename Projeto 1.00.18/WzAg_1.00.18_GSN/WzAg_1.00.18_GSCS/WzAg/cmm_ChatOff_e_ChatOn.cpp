#include "StdAfx.h"

void ChatOff(DWORD aIndex, char *Nome)
{
	if(gObjCustom[aIndex].CtlCode < GM_CtlCode) return;

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3)
		{
			if(!memcmp(Nome, gObj(i)->Name, strlen(gObj(i)->Name)) && strlen(Nome) == strlen(gObj(i)->Name))
			{
				gObjCustom[i].PostBlock = 1;
				MsgParaJogador("[ChatOff] Jogador desabilitado!",aIndex);
				return;
			}
		}
	}

	MsgParaJogador("[ChatOff] Jogador não encontrado!",aIndex);
}

void ChatOn(DWORD aIndex, char *Nome)
{
	if(gObjCustom[aIndex].CtlCode < GM_CtlCode) return;

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3)
		{
			if(!memcmp(Nome, gObj(i)->Name, strlen(gObj(i)->Name)) && strlen(Nome) == strlen(gObj(i)->Name))
			{
				gObjCustom[i].PostBlock = 0;
				MsgParaJogador("[ChatOff] Jogador habilitado!",aIndex);
				return;
			}
		}
	}

	MsgParaJogador("[ChatOn] Jogador não encontrado!",aIndex);
}