#include "StdAfx.h"

void SetarEvento(int aIndex, char *Info)
{
	if(GS.cmm_Evento_Ativado == 0)
	{
		MsgParaJogador("[Set Evento] Comando desabilitado", aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_Evento_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[Set Evento] %s", VerificarCtlCode(aIndex, GS.cmm_Evento_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	if(strlen(Info) < 3)
	{
		MsgParaJogador("[Set Evento] Tente /setevento Mapa X Y.",aIndex);
		return;
	}

	int Mapa, Tmp_X, Tmp_Y;
	sscanf_s(Info , "%d %d %d", &Mapa, &Tmp_X, &Tmp_Y);
	GS.cmm_Evento_Mapa	= Mapa;
	GS.cmm_Evento_X	= Tmp_X;
	GS.cmm_Evento_Y	= Tmp_Y;

	MsgParaJogador("[Set Evento] Spawn trocada com sucesso!",aIndex);
}