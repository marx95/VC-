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
		MsgParaJogador("[3� Classe] Comando desabilitado.",aIndex);
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
			sprintf_s(MsgCtlCode, "[3� Classe] %s", VerificarCtlCode(aIndex, GS.cmm_Evo_CtlCode));
			MsgParaJogador(MsgCtlCode, aIndex);
		}
		return;
	}

	if(GS.cmm_Evo_Custo > gObj(aIndex)->Money)
	{
		char OutputZenFalha[200];
		if(Tipo == 0) 
		{
			sprintf_s(OutputZenFalha,"Necess�rio %d zen.", GS.cmm_Evo_Custo);
			NpcChat(OutputZenFalha, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		}else
		{
			sprintf_s(OutputZenFalha,"[3� Classe] Necess�rio %d zen.", GS.cmm_Evo_Custo);
			MsgParaJogador(OutputZenFalha, aIndex);
		}
		return;
	}

	if(gObjCustom[aIndex].Vip < GS.cmm_Evo_Vip)
	{
		if(Tipo == 0) NpcChat("Necess�rio ser Vip.", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[3� Classe] Necess�rio ser Vip.",aIndex);
		return;
	}

	if (GS.cmm_Evo_Level > gObj(aIndex)->Level)
	{
		char Erro[200];
		if(Tipo == 0) 
		{
			sprintf_s(Erro,"Level necess�rio %d", GS.cmm_Evo_Level);
			NpcChat(Erro, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		}else
		{
			sprintf_s(Erro,"[3� Classe] Level necess�rio %d", GS.cmm_Evo_Level);
			MsgParaJogador(Erro, aIndex);
		}
		return;
	}

	if(GS.cmm_Evo_SegundaClasse == 1)
	{
		switch(TmpClass)
		{
		case 0:
			if(Tipo == 0) sprintf_s(TmpMsg,"� preciso ser Soul-Master para evoluir");
			if(Tipo == 1) sprintf_s(TmpMsg,"[3� Classe] � preciso ser Soul-Master para evoluir");
			if(Tipo == 0) NpcChat(TmpMsg, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
			if(Tipo == 1) MsgParaJogador(TmpMsg, aIndex);
			return;
		break;
		case 16:
			if(Tipo == 0) sprintf_s(TmpMsg,"� preciso ser Blade-Knight para evoluir");
			if(Tipo == 1) sprintf_s(TmpMsg,"[3� Classe] � preciso ser Blade-Knight para evoluir");
			if(Tipo == 0) NpcChat(TmpMsg, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
			if(Tipo == 1) MsgParaJogador(TmpMsg, aIndex);
			return;
		break;
		case 32:
			if(Tipo == 0) sprintf_s(TmpMsg,"� preciso ser Muse-Elf para evoluir");
			if(Tipo == 1) sprintf_s(TmpMsg,"[3� Classe] � preciso ser Muse-Elf para evoluir");
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
		if(Tipo == 0) NpcChat("Voc� j� � Grand-Master!", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[3� Classe] Voc� j� � Grand-Master!", aIndex);
		return;
	break;

	case 16:
		gObj(aIndex)->DbClass += 2;
	break;
	case 17:
		gObj(aIndex)->DbClass += 1;
	break;
	case 18:
		if(Tipo == 0) NpcChat("Voc� j� � Blade-Master!", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[3� Classe] Voc� j� � Blade-Master!", aIndex);
		return;
	break;

	case 32:
		gObj(aIndex)->DbClass += 2;
	break;
	case 33:
		gObj(aIndex)->DbClass += 1;
	break;
	case 34:
		if(Tipo == 0) NpcChat("Voc� j� � Hight-Elf!", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[3� Classe] Voc� j� � Hight-Elf!", aIndex);
		return;
	break;

	case 48:
		gObj(aIndex)->DbClass += 1;
		break;
	case 49:
		if(Tipo == 0) NpcChat("Voc� j� � Duel-Master!", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[3� Classe] Voc� j� � Duel-Master!", aIndex);
		return;
	break;

	case 64:
		gObj(aIndex)->DbClass += 1;
		break;
	case 65:
		if(Tipo == 0) NpcChat("Voc� j� � Lord-Emperor!", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		if(Tipo == 1) MsgParaJogador("[3� Classe] Voc� j� � Lord-Emperor!", aIndex);
		return;
	break;
	}

	gObj(aIndex)->Money -= GS.cmm_Evo_Custo;
	GCMoneySend(aIndex, gObj(aIndex)->Money);

	if(Tipo == 0) NpcChat("Voc� evoluiu, relogando...", gObjCustom[aIndex].UltimoNpcIndex, aIndex);
	if(Tipo == 1) MsgParaJogador("[3� Classe] Voc� evoluiu, relogando...", aIndex);
	gObjCloseSet(aIndex, 1);
}