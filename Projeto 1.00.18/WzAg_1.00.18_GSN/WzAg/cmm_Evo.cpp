#include "StdAfx.h"

// - TIPO
// - 0 = Npc
// - 1 = Comando

void Evoluir(int aIndex, int Tipo)
{
	char TmpMsg[200];
	BYTE TmpClass = gObj(aIndex)->DbClass;

	if(GS.cmm_Evo_Ativado_Npc == 0 && Tipo == 0)
	{
		NpcChat("Comando desabilitado.", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		return;
	}

	if(GS.cmm_Evo_Ativado == 0 && Tipo == 1)
	{
		MsgParaJogador("[3ª Classe] Comando desabilitado.",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_Evo_CtlCode)
	{
		char MsgCtlCode[64];
		if(Tipo == 0) 
		{
			sprintf_s(MsgCtlCode, "%s", VerificarCtlCode(aIndex, GS.cmm_Evo_CtlCode));
			NpcChat(MsgCtlCode, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		}else
		{
			sprintf_s(MsgCtlCode, "[3ª Classe] %s", VerificarCtlCode(aIndex, GS.cmm_Evo_CtlCode));
			MsgParaJogador(MsgCtlCode, aIndex);
		}
		return;
	}

	if(GS.cmm_Evo_Custo > gObj(aIndex)->Money)
	{
		char OutputZenFalha[200];
		if(Tipo == 0) 
		{
			sprintf_s(OutputZenFalha,"Necessário %d zen.", GS.cmm_Evo_Custo);
			NpcChat(OutputZenFalha, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		}else
		{
			sprintf_s(OutputZenFalha,"[3ª Classe] Necessário %d zen.", GS.cmm_Evo_Custo);
			MsgParaJogador(OutputZenFalha, aIndex);
		}
		return;
	}

	if(gObjCustom[aIndex].Vip < GS.cmm_Evo_Vip)
	{
		if(Tipo == 0) NpcChat("Necessário ser Vip.", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[3ª Classe] Necessário ser Vip.",aIndex);
		return;
	}

	if (GS.cmm_Evo_Level > gObj(aIndex)->Level)
	{
		char Erro[200];
		if(Tipo == 0) 
		{
			sprintf_s(Erro,"Level necessário %d", GS.cmm_Evo_Level);
			NpcChat(Erro, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		}else
		{
			sprintf_s(Erro,"[3ª Classe] Level necessário %d", GS.cmm_Evo_Level);
			MsgParaJogador(Erro, aIndex);
		}
		return;
	}

	if(GS.cmm_Evo_SegundaClasse == 1)
	{
		switch(TmpClass)
		{
		case 0:
			if(Tipo == 0) sprintf_s(TmpMsg,"É preciso ser Soul-Master para evoluir");
			if(Tipo == 1) sprintf_s(TmpMsg,"[3ª Classe] É preciso ser Soul-Master para evoluir");
			if(Tipo == 0) NpcChat(TmpMsg, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
			if(Tipo == 1) MsgParaJogador(TmpMsg, aIndex);
			return;
		break;
		case 16:
			if(Tipo == 0) sprintf_s(TmpMsg,"É preciso ser Blade-Knight para evoluir");
			if(Tipo == 1) sprintf_s(TmpMsg,"[3ª Classe] É preciso ser Blade-Knight para evoluir");
			if(Tipo == 0) NpcChat(TmpMsg, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
			if(Tipo == 1) MsgParaJogador(TmpMsg, aIndex);
			return;
		break;
		case 32:
			if(Tipo == 0) sprintf_s(TmpMsg,"É preciso ser Muse-Elf para evoluir");
			if(Tipo == 1) sprintf_s(TmpMsg,"[3ª Classe] É preciso ser Muse-Elf para evoluir");
			if(Tipo == 0) NpcChat(TmpMsg, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
			if(Tipo == 1) MsgParaJogador(TmpMsg, aIndex);
			return;
		break;
		}
	}

	int TerceiraClasse = 0;

	switch(TmpClass)
	{
	case 0:
		gObj(aIndex)->DbClass += 2;
	break;
	case 1:
		gObj(aIndex)->DbClass += 1;
	break;
	case 2:
		if(Tipo == 0) NpcChat("Você já é Grand-Master!", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[3ª Classe] Você já é Grand-Master!", aIndex);
		return;
	break;

	case 16:
		gObj(aIndex)->DbClass += 2;
	break;
	case 17:
		gObj(aIndex)->DbClass += 1;
	break;
	case 18:
		if(Tipo == 0) NpcChat("Você já é Blade-Master!", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[3ª Classe] Você já é Blade-Master!", aIndex);
		return;
	break;

	case 32:
		gObj(aIndex)->DbClass += 2;
	break;
	case 33:
		gObj(aIndex)->DbClass += 1;
	break;
	case 34:
		if(Tipo == 0) NpcChat("Você já é Hight-Elf!", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[3ª Classe] Você já é Hight-Elf!", aIndex);
		return;
	break;

	case 48:
		gObj(aIndex)->DbClass += 1;
		break;
	case 49:
		if(Tipo == 0) NpcChat("Você já é Duel-Master!", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[3ª Classe] Você já é Duel-Master!", aIndex);
		return;
	break;

	case 64:
		gObj(aIndex)->DbClass += 1;
		break;
	case 65:
		if(Tipo == 0) NpcChat("Você já é Lord-Emperor!", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[3ª Classe] Você já é Lord-Emperor!", aIndex);
		return;
	break;
	}

	gObj(aIndex)->Money -= GS.cmm_Evo_Custo;
	GCMoneySend(aIndex, gObj(aIndex)->Money);

	if(Tipo == 0) NpcChat("Você evoluiu, relogando...", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
	if(Tipo == 1) MsgParaJogador("[3ª Classe] Você evoluiu, relogando...", aIndex);
	gObjCloseSet(aIndex, 1);
}