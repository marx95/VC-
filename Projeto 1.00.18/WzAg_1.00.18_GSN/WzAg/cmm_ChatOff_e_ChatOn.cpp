#include "StdAfx.h"

void ChatOff(int aIndex, char *Nome)
{

	if(gObjCustom[aIndex].CtlCode < GS.GM_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[C. Off] %s", VerificarCtlCode(aIndex, GS.GM_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3)
		{
			if(Procurar(gObj(i)->Name, Nome, true))
			{
				gObjCustom[i].ChatBlock = 1;
				MsgParaJogador("[ChatOff] Jogador desabilitado!",aIndex);
				return;
			}
		}
	}

	MsgParaJogador("[ChatOff] Jogador não encontrado!",aIndex);
}

void ChatOn(int aIndex, char *Nome)
{

	if(gObjCustom[aIndex].CtlCode < GS.GM_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[C. On] %s", VerificarCtlCode(aIndex, GS.GM_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3)
		{
			if(Procurar(gObj(i)->Name, Nome, true))
			{
				gObjCustom[i].ChatBlock = 0;
				MsgParaJogador("[ChatOff] Jogador habilitado!",aIndex);
				return;
			}
		}
	}

	MsgParaJogador("[ChatOn] Jogador não encontrado!",aIndex);
}