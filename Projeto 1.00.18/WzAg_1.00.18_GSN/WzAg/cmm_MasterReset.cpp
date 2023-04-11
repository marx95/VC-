#include "stdafx.h"

void MasterReset(int aIndex)
{
	if(GS.cmm_MR_Ativado == 0)
	{
		MsgParaJogador("[MR] Comando desabilitado", aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_MR_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[MR] %s", VerificarCtlCode(aIndex, GS.cmm_MR_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	if(GS.cmm_MR_Custo > gObj(aIndex)->Money)
	{
		char OutputZenFalha[200];
		sprintf_s(OutputZenFalha,"[MR] Necessário %d zen", GS.cmm_MR_Custo);
		MsgParaJogador(OutputZenFalha, aIndex);
		return;
	}

	if(GS.cmm_MR_Resets_Necessario > gObjCustom[aIndex].Resets)
	{
		char MsgNeedRr[200];
		sprintf_s(MsgNeedRr,"[MR] Necessário %d Resets.", GS.cmm_MR_Resets_Necessario);
		MsgParaJogador(MsgNeedRr, aIndex);
		return;
	}

	int PontosIniciais;
	char QueryMR[256];
	if(gObjCustom[aIndex].Vip == 0)
	{
		PontosIniciais			= GS.Func_Reset_PontosIni_Free;
		if(GS.cmm_MR_Recompensa_Tipo == 0) sprintf_s(QueryMR, "UPDATE Memb_Info SET golds=golds+%d WHERE Memb___ID='%s'", GS.cmm_MR_Recompensa_Free, gObj(aIndex)->AccountID);
		if(GS.cmm_MR_Recompensa_Tipo == 1) sprintf_s(QueryMR, "UPDATE Memb_Info SET bonus=bonus+%d WHERE Memb___ID='%s'", GS.cmm_MR_Recompensa_Free, gObj(aIndex)->AccountID);

	}
	else
	{
		PontosIniciais			= GS.Func_Reset_PontosIni_Vip;
		if(GS.cmm_MR_Recompensa_Tipo == 0) sprintf_s(QueryMR, "UPDATE Memb_Info SET golds=golds+%d WHERE Memb___ID='%s'", GS.cmm_MR_Recompensa_Vip, gObj(aIndex)->AccountID);
		if(GS.cmm_MR_Recompensa_Tipo == 1) sprintf_s(QueryMR, "UPDATE Memb_Info SET bonus=bonus+%d WHERE Memb___ID='%s'", GS.cmm_MR_Recompensa_Vip, gObj(aIndex)->AccountID);

	}

	DbConnection.Executar(QueryMR);

	gObj(aIndex)->Level			= 1;
	gObj(aIndex)->Experience	= 0;
	gObj(aIndex)->Money		   -= GS.cmm_MR_Custo;
	gObj(aIndex)->Strength		= PontosIniciais;
	gObj(aIndex)->Dexterity		= PontosIniciais;
	gObj(aIndex)->Vitality		= PontosIniciais;
	gObj(aIndex)->Energy		= PontosIniciais;
	gObj(aIndex)->Leadership	= PontosIniciais;
	gObj(aIndex)->LevelUpPoint	= 0;

	Mssql_Atualiza(aIndex, 12);
	gObjCloseSet(aIndex, 1);
}