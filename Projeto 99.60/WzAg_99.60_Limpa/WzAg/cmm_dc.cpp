#include "stdafx.h"

void cmm_DC(int aIndex, char * TmpNome)
{
	if(gObjCustom[aIndex].CtlCode < GS.ADM_CtlCode) return;
	
	if(strlen(TmpNome) < 4)
	{
		MsgPlayer("[DC] Nick inválido!", aIndex);
		return;
	}

	if(strcmp(TmpNome, gObj(aIndex)->Name) == 0)
	{
		MsgPlayer("[DC] Impossível /dc em você mesmo!", aIndex);
		return;
	}

	for(int i = Obj_Jogadores_Minimo; i < Obj_Jogadores_Maximo; i++)
	{
		if(aIndex != i)
		{
			if(Jogando(i))
			{
				if(Procurar(gObj(i)->Name, TmpNome, true))
				{
					char MsgDC[64];
					CloseClient(i);
					sprintf_s(MsgDC, "[DC] %s desconectado!", TmpNome);
					MsgPlayer(MsgDC, aIndex);
					return;
				}
			}
		}
	}

	MsgPlayer("[DC] Jogador não encontrado!", aIndex);
	return;
}