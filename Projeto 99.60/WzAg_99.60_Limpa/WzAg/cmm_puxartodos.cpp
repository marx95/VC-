#include "stdafx.h"

void cmm_puxartodos(int aIndex)
{
	if(gObjCustom[aIndex].CtlCode < GS.GM_CtlCode) return;

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(Jogando(i))
		{
			if(!VerificarGM(i)) gObjTeleport(i, gObj(aIndex)->MapNumber, gObj(aIndex)->X, gObj(aIndex)->Y);
		}
	}

	MsgPlayer("[GMove] Todos foram puxados!",aIndex);
	return;
}