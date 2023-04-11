#include "StdAfx.h"

void PuxarTodos(int aIndex)
{
	if(GS.cmm_PuxarTodos_Ativado == 0)
	{
		MsgParaJogador("[Puxar Todos] Comando desabilitado",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_PuxarTodos_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[Puxar Todos] %s", VerificarCtlCode(aIndex, GS.cmm_PuxarTodos_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3 && gObjCustom[i].CtlCode < GS.GM_CtlCode)
		{
			gObjTeleport(i, gObj(aIndex)->MapNumber, gObj(aIndex)->X, gObj(aIndex)->Y);
		}
	}

	MsgParaJogador("[Puxar Todos] Todos foram puxados!", aIndex);
}