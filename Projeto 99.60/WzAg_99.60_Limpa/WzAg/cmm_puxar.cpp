#include "stdafx.h"

void cmm_puxar(int aIndex, char * Nick)
{
	if(gObjCustom[aIndex].CtlCode < GS.GM_CtlCode) return;

	if(strlen(Nick) < 4)
	{
		MsgPlayer("[Puxar] Nick inválido!", aIndex);
		return;
	}

	if(strcmp(Nick, gObj(aIndex)->Name) == 0)
	{
		MsgPlayer("[Puxar] Impossível se puxar!", aIndex);
		return;
	}

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(Jogando(i))
		{
			if(aIndex != i)
			{
				if(Procurar(gObj(i)->Name, Nick, true))
				{
					gObjTeleport(i, gObj(aIndex)->MapNumber, gObj(aIndex)->X, gObj(aIndex)->Y);

					char MsgOut[64];
					sprintf_s(MsgOut, "[Puxar] %s puxado!", Nick);
					MsgPlayer(MsgOut, aIndex);
					return;
				}
			}
		}
	}

	MsgPlayer("[Puxar] Jogador não encontrado!",aIndex);
	return;
}