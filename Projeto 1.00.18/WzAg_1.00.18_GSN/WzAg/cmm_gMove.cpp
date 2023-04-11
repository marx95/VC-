#include "StdAfx.h"

void gMoveCmm(int aIndex, char *Msg)
{

	if(gObjCustom[aIndex].CtlCode < GS.GM_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[GMove] %s", VerificarCtlCode(aIndex, GS.GM_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	int spaces = 0;
	int TmpLen = strlen(Msg);
	for(int i=0; i<TmpLen; i++)
	{
		if(Msg[i] == ' ')
		spaces++;
	}

	if(spaces < 3)
	{
		MsgParaJogador("[GMove] Tente: /gmove Noma MapaID x y",aIndex);
		return;
	}

	char TmpNome[11];
	int Mapa, pX, pY;
	sscanf(Msg , "%s %d %d %d", &TmpNome, &Mapa, &pX, &pY);

	if(strcmp(TmpNome, gObj(aIndex)->Name) == 0)
	{
		gObjTeleport(aIndex, Mapa, pX, pY);

		char MsgOut[64];
		sprintf_s(MsgOut, "[GMove] %s teleportado!", TmpNome);
		MsgParaJogador(MsgOut,aIndex);
		return;
	}

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3)
		{
			if(Procurar(gObj(i)->Name, TmpNome, true))
			{
				gObjTeleport(i, Mapa, pX, pY);

				char MsgOut[64];
				sprintf_s(MsgOut, "[GMove] %s teleportado!", TmpNome);
				MsgParaJogador(MsgOut,aIndex);
				return;
			}
		}
	}

	MsgParaJogador("[GMove] Jogador não encontrado!",aIndex);
	return;
}