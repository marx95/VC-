#include "StdAfx.h"

void Post(DWORD aIndex,char * msg)
{
	if(gObjCustom[aIndex].PostBlock == 1) return;

	if(cmm_Post_Ativado == 0)
	{
		MsgParaJogador("[Post] Comando desabilitado", aIndex);
		return;
	}

	if(cmm_Post_Level > gObj(aIndex)->Level)
	{
		char levelmsg[100];
		sprintf(levelmsg,"[Post] Level necessário: %d.",cmm_Post_Level);
		MsgParaJogador(levelmsg, aIndex);
		return;
	}

	if(gObjCustom[aIndex].Resets < cmm_Post_Resets && gObjCustom[aIndex].CtlCode == 0)
	{
		char msgresets[100];
		sprintf(msgresets,"[Post] Resets necessários: %d.", cmm_Post_Resets);
		MsgParaJogador(msgresets, aIndex);
		return;
	}

	if(cmm_Post_Custo > gObj(aIndex)->Money)
	{
		char OutputZenFalha[200];
		sprintf_s(OutputZenFalha,"[Add] Necessário %d zen", cmm_Post_Custo);
		MsgParaJogador(OutputZenFalha, aIndex);
		return;
	}

	if(strlen(msg) < 2 || msg[0] == 0 || sizeof(msg) < 2)
	{
		MsgParaJogador("[Post] Tente: /post <msg>", aIndex);
		return;
	}

	char MsgPost[255];
	sprintf_s(MsgPost, "%s [Post]: %s", gObj(aIndex)->Name, msg);
	int Cor = 1;
	if(gObjCustom[aIndex].CtlCode != 0) Cor = 0;
	MsgColorida(MsgPost, aIndex, 1, Cor);

	gObj(aIndex)->Money -= cmm_Post_Custo;
	GCMoneySend(aIndex, gObj(aIndex)->Money);
}