#include "StdAfx.h"

// - TIPO
// - 0 = Npc
// - 1 = Comando

void Reset(int aIndex, int Tipo)
{
	if(VerificarGM(aIndex))
	{
		if(Tipo == 0) NpcChat("Staff não pode resetar.", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[Reset] Staff não pode resetar.",aIndex);
		return;
	}

	if(GS.Func_Reset_Ativado == 0)
	{
		if(Tipo == 0) NpcChat("Função desabilitada.", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[Reset] Função desabilitada.",aIndex);
		return;
	}

	if(gObj(aIndex)->MySelfDefenseTime > 0)
	{
		if(Tipo == 0) NpcChat("SelfDefense ativado, relogue por favor!", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[Reset] SelfDefense ativado, relogue por favor!", aIndex);
		return;
	}
	
	int Pontos;
	int LevelReset;
	int PontosIniciais;

	if(gObjCustom[aIndex].Vip == 0)
	{
		LevelReset			= GS.Func_Reset_Level_Free;
		PontosIniciais		= GS.Func_Reset_PontosIni_Free;
		Pontos				= GS.Func_Reset_Pontos_Free;
	}
	else
	{
		LevelReset			= GS.Func_Reset_Level_Vip;
		PontosIniciais		= GS.Func_Reset_PontosIni_Vip;
		Pontos				= GS.Func_Reset_Pontos_Vip;
	}

	if(gObj(aIndex)->Level < LevelReset)
	{
		char levelmsg[100];
		if(Tipo == 0) 
		{
			sprintf(levelmsg,"Level necessário: %d.", LevelReset);
			NpcChat(levelmsg, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		}else
		{
			sprintf(levelmsg,"[Reset] Level necessário: %d.", LevelReset);
			MsgParaJogador(levelmsg, aIndex);
		}
		return;
	}

	int Custo;
	if(gObjCustom[aIndex].Vip == 0) Custo = GS.Func_Reset_Custo;
	if(gObjCustom[aIndex].Vip == 1) Custo = GS.Func_Reset_Custo_Vip;

	if(gObj(aIndex)->Money < Custo)
	{
		char Msg[100];
		if(Tipo == 0) 
		{
			sprintf(Msg, "Necessário %d zen.", Custo);
			NpcChat(Msg, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		}else
		{
			sprintf(Msg, "[Reset] Necessário %d zen.", Custo);
			MsgParaJogador(Msg,aIndex);
		}
		return;
	}
	if(VerificarGM(gObjCustom[aIndex].CtlCode))
	{
		if(Tipo == 0) NpcChat("GameMaster não pode resetar.", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[Reset] GameMaster não pode resetar.", aIndex);
		return;
	}

	if(GS.Func_Reset_Limite > 0)
	{
		if(gObjCustom[aIndex].Resets >= GS.Func_Reset_Limite)
		{
			if(Tipo == 0) NpcChat("Você chegou no Limite de Resets!", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
			if(Tipo == 1) MsgParaJogador("[Reset] Você chegou no Limite de Resets!", aIndex);
			return;
		}
	}

	gObjCustom[aIndex].Resets  += 1;
	gObj(aIndex)->Level			= 1;
	gObj(aIndex)->Experience	= 0;
	gObj(aIndex)->Money		   -= Custo;
	GCMoneySend(aIndex, gObj(aIndex)->Money);

	if(GS.Func_Reset_Tipo == 0)
	{
		gObj(aIndex)->Strength		= PontosIniciais;
		gObj(aIndex)->Dexterity		= PontosIniciais;
		gObj(aIndex)->Vitality		= PontosIniciais;
		gObj(aIndex)->Energy		= PontosIniciais;
		gObj(aIndex)->Leadership	= PontosIniciais;
		gObj(aIndex)->LevelUpPoint	= gObjCustom[aIndex].Resets*Pontos;
	}

	Mssql_Atualiza(aIndex, 1);
	
	if(gObj(aIndex)->Class == CLASS_ELF) 
	{
		gObjTeleport(aIndex, 3, 171, 87);
	}else
	{
		if(gObj(aIndex)->MapNumber != 0) gObjTeleport(aIndex, 0, 140, 135);
	}

	GCLevelUpMsgSend(aIndex, 1);
	Atualizar_Personagem(aIndex);
	GJSetCharacterInfo(gObj(aIndex), aIndex, 0);

	char MsgRstInfo[128];
	if(gObjCustom[aIndex].Resets == 1) sprintf_s(MsgRstInfo, "Agora Você tem %d Reset!", gObjCustom[aIndex].Resets);
	if(gObjCustom[aIndex].Resets > 1) sprintf_s(MsgRstInfo, "Agora Você tem %d Reset's!", gObjCustom[aIndex].Resets);
	MsgParaJogador(MsgRstInfo, aIndex);
}