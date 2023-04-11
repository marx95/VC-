#include "StdAfx.h"

void Post_Timer()
{
	while(true)
	{
		Sleep(1000);
		for(int i = Obj_Jogadores_Minimo; i < Obj_Jogadores_Maximo; i++)
		{
			if(gObj(i)->Connected == 3)
			{
				if(gObjCustom[i].PostDelay > 0) gObjCustom[i].PostDelay--;
			}
		}
	}
}

void Post(int aIndex,char * msg)
{
	if(gObjCustom[aIndex].ChatBlock == 1) return;

	if(GS.cmm_Post_Ativado == 0)
	{
		MsgParaJogador("[Post] Comando desabilitado", aIndex);
		return;
	}

	if(GS.cmm_Post_Level > gObj(aIndex)->Level)
	{
		char levelmsg[100];
		sprintf(levelmsg,"[Post] Level necessário: %d.", GS.cmm_Post_Level);
		MsgParaJogador(levelmsg, aIndex);
		return;
	}

	if(gObjCustom[aIndex].Resets < GS.cmm_Post_Resets && gObjCustom[aIndex].CtlCode == 0)
	{
		char msgresets[100];
		sprintf(msgresets,"[Post] Resets necessários: %d.", GS.cmm_Post_Resets);
		MsgParaJogador(msgresets, aIndex);
		return;
	}

	if(gObjCustom[aIndex].PostDelay > 0)
	{
		char MsgOutDelay[64];
		sprintf_s(MsgOutDelay, "[Post] Espere %d segundo(s)!", gObjCustom[aIndex].PostDelay);
		MsgParaJogador(MsgOutDelay, aIndex);
		return;
	}

	if(GS.cmm_Post_Custo > gObj(aIndex)->Money)
	{
		char OutputZenFalha[200];
		sprintf_s(OutputZenFalha,"[Add] Necessário %d zen", GS.cmm_Post_Custo);
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
	if(VerificarGM(aIndex)) Cor = 0;
	MsgColorida(MsgPost, aIndex, 1, Cor);

	gObjCustom[aIndex].PostDelay = GS.cmm_Post_Delay;
	gObj(aIndex)->Money -= GS.cmm_Post_Custo;
	GCMoneySend(aIndex, gObj(aIndex)->Money);
}