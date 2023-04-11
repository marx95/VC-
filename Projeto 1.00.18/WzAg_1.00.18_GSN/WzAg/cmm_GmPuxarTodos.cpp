#include "StdAfx.h"

void GmPuxarTodos(int aIndex)
{
	if(GS.cmm_GmPuxarTodos_Ativado == 0)
	{
		MsgParaJogador("[GM P. Todos] Comando desabilitado",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_GmPuxarTodos_CtlCode){
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[GM P. Todos] %s", VerificarCtlCode(aIndex, GS.cmm_GmPuxarTodos_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3 && gObjCustom[i].CtlCode >= GS.GM_CtlCode && gObjCustom[i].CtlCode <= GS.ADM_CtlCode)
		{
			gObjTeleport(i, gObj(aIndex)->MapNumber, gObj(aIndex)->X, gObj(aIndex)->Y);
		}
	}

	MsgParaJogador("[GM P. Todos] A staff foi puxada!", aIndex);
}