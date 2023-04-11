#include "StdAfx.h"

// - TIPO
// - 0 = Npc
// - 1 = Comando

void LimparPK(int aIndex, int Tipo)
{

	if(GS.cmm_LimparPK_Ativado == 0)
	{
		if(Tipo == 0) NpcChat("Comando Desabilitado.", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[LimparPK] Comando Desabilitado.",aIndex);
		return;
	}

	if(GS.cmm_LimparPK_Level > gObj(aIndex)->Level)
	{
		char levelmsg[100];
		if(Tipo == 0) 
		{
			sprintf(levelmsg,"Level necessário: %d.", GS.cmm_LimparPK_Level);
			NpcChat(levelmsg, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		}else
		{
			sprintf(levelmsg,"[Limpar PK] Level necessário: %d.", GS.cmm_LimparPK_Level);
			MsgParaJogador(levelmsg,aIndex);
		}
		return;
	}

	int Custo;
	if(gObjCustom[aIndex].Vip == 0) Custo = GS.cmm_LimparPK_Custo;
	if(gObjCustom[aIndex].Vip == 1) Custo = GS.cmm_LimparPK_Custo_Vip;

	if(Custo > gObj(aIndex)->Money)
	{
		char OutputZenFalha[200];
		if(Tipo == 0) 
		{
			sprintf_s(OutputZenFalha,"Necessário %d zen.", Custo);
			NpcChat(OutputZenFalha, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		}else
		{
			sprintf_s(OutputZenFalha,"[Limpar PK] Necessário %d zen", Custo);
			MsgParaJogador(OutputZenFalha,aIndex);
		}
		return;
	}

	if(Tipo == 1 && gObjCustom[aIndex].Vip == 0)
	{
		MsgParaJogador("[Limpar PK] Necessário ser Vip",aIndex);
		return;
	}
	if(Tipo == 0) NpcChat("Você foi Perdoado!", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
	if(Tipo == 1) MsgParaJogador("[Limpar PK] Limpo com Sucesso!",aIndex);

	gObj(aIndex)->Money			-= GS.cmm_LimparPK_Custo;
	gObj(aIndex)->m_PK_Level	 = 3;
	//gObj(aIndex)->m_PK_Count	 = 0; //Total de pessoas q o player matou
	gObj(aIndex)->m_PK_Time		 = 0;
	GCPkLevelSend(aIndex, 3);
	GCMoneySend(aIndex, gObj(aIndex)->Money);
}