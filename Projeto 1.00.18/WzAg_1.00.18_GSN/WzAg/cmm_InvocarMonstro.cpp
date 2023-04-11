#include "StdAfx.h"

void InvocarPET(int aIndex,char * msg)
{
	if(GS.Invocar_Monstro_Ativado == 0)
	{
		MsgParaJogador("[Invocar] Comando desabilitado",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.Invocar_Monstro_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[Invocar] %s", VerificarCtlCode(aIndex, GS.Invocar_Monstro_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	int Monstro = atoi(msg);
	if(Monstro == -1)
	{
		gObjMonsterCallKill(aIndex);
		MsgParaJogador("[Invocar] Seu pet foi Morto!", aIndex);
		return;
	}


	if(Monstro < 0 || Monstro > 414)
	{
		MsgParaJogador("[Invocar] Use: 0 até 414!", aIndex);
		return;
	}

	gObjMonsterCallKill(aIndex);
	gObjMonsterCall(aIndex, Monstro, gObj(aIndex)->X, gObj(aIndex)->Y);

	MsgParaJogador("[Invocar] Summonados com sucesso!",aIndex);
}