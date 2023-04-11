#include "stdafx.h"

void cmm_gMove(int aIndex, char * Msg)
{
	if(gObjCustom[aIndex].CtlCode < GS.GM_CtlCode) return;

	int spaces = 0;
	int TmpLen = strlen(Msg);
	for(int i=0; i<TmpLen; i++)
	{
		if(Msg[i] == ' ')
		spaces++;
	}

	if(spaces < 3)
	{
		MsgPlayer("[GMove] Tente: /gmove Nome MapaID x y", aIndex);
		return;
	}

	char TmpNome[11];
	int Mapa, pX, pY;
	sscanf(Msg , "%s %d %d %d", &TmpNome, &Mapa, &pX, &pY);

	if(strlen(TmpNome) < 4)
	{
		MsgPlayer("[GMove] Nick inválido!", aIndex);
		return;
	}

	if(strcmp(TmpNome, gObj(aIndex)->Name) == 0)
	{
		gObjTeleport(aIndex, Mapa, pX, pY);

		char MsgOut[64];
		sprintf_s(MsgOut, "[GMove] Você foi teleportado!", TmpNome);
		MsgPlayer(MsgOut, aIndex);
		return;
	}

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(Jogando(i))
		{
			if(Procurar(gObj(i)->Name, TmpNome, true))
			{
				gObjTeleport(i, Mapa, pX, pY);

				char MsgOut[64];
				sprintf_s(MsgOut, "[GMove] %s teleportado!", TmpNome);
				MsgPlayer(MsgOut, aIndex);
				return;
			}
		}
	}

	MsgPlayer("[GMove] Jogador não encontrado!",aIndex);
	return;
}