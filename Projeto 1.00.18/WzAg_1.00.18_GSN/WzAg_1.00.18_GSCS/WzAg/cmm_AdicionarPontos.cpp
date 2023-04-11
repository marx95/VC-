#include "StdAfx.h"

bool AdicionarSingle(DWORD aIndex, BYTE Tipo)
{
	switch(Tipo)
	{
		case 0: if(gObj(aIndex)->Strength		>= gObjCustom[aIndex].Limite_Pontos)	return false;	break;		//Str
		case 1: if(gObj(aIndex)->Dexterity		>= gObjCustom[aIndex].Limite_Pontos)	return false;	break;		//Agi
		case 2: if(gObj(aIndex)->Vitality		>= gObjCustom[aIndex].Limite_Pontos)	return false;	break;		//Vit
		case 3: if(gObj(aIndex)->Energy			>= gObjCustom[aIndex].Limite_Pontos)	return false;	break;		//Ene
		case 4: if(gObj(aIndex)->Leadership		>= 32767)	return false;								break;		//Com
	}
	return true;
}

void AdicionarPontos(DWORD aIndex, LPCSTR lpBuffer, DWORD CMD_STATS_TYPE)
{
	int Pontos = atoi(lpBuffer);
	char MsgLimite[128];
	sprintf_s(MsgLimite, "[Add] Máximo %d pontos!", gObjCustom[aIndex].Limite_Pontos);

	if(cmm_Add_Ativado == 0)
	{
		MsgParaJogador("[Add] Comando desabilitado", aIndex);
		return;
	}

	if(cmm_Add_Level > gObj(aIndex)->Level)
	{
		char levelmsg[100];
		sprintf(levelmsg,"[Add] Level necessário: %d.",cmm_Add_Level);
		MsgParaJogador(levelmsg, aIndex);
		return;
	}

	if(strlen(lpBuffer)<1)
	{
		MsgParaJogador("[Add] Digite algum numero!", aIndex);
		return;
	}

	if(Pontos <= 0)
	{
		MsgParaJogador("[Add] Digite algum numero válido!", aIndex);
		return;
	}

	if(gObj(aIndex)->LevelUpPoint < Pontos)
	{
		MsgParaJogador("[Add] Pontos insuficientes", aIndex);
		return;
	}

	if(cmm_Add_Custo >gObj(aIndex)->Money)
	{
		char OutputZenFalha[200];
		sprintf_s(OutputZenFalha,"[Add] Necessário %d zen", cmm_Add_Custo);
		MsgParaJogador(OutputZenFalha, aIndex);
		return;
	}

	switch(CMD_STATS_TYPE)
	{
		case 0: // - Força
			if((gObj(aIndex)->Strength+Pontos) > gObjCustom[aIndex].Limite_Pontos)
			{
				MsgParaJogador(MsgLimite, aIndex);
				return;
			}else
			{
				gObj(aIndex)->Strength += Pontos;
				MsgParaJogador("[Add] Pontos Adicionados, relogue!", aIndex);
			}
		break;

		case 1: // - Agilidade
			if((gObj(aIndex)->Dexterity+Pontos) > gObjCustom[aIndex].Limite_Pontos)
			{
				MsgParaJogador(MsgLimite, aIndex);
				return;
			}else
			{
				gObj(aIndex)->Dexterity += Pontos;
				MsgParaJogador("[Add] Pontos Adicionados, relogue!", aIndex);
			}
		break;

		case 2: // - Vitalidade
			if((gObj(aIndex)->Vitality+Pontos) > gObjCustom[aIndex].Limite_Pontos)
			{
				MsgParaJogador(MsgLimite, aIndex);
				return;
			}else
			{
				gObj(aIndex)->Vitality += Pontos;
				MsgParaJogador("[Add] Pontos Adicionados, relogue!", aIndex);
			}
		break;

		case 3: // - Energia
			if((gObj(aIndex)->Energy+Pontos) > gObjCustom[aIndex].Limite_Pontos)
			{
				MsgParaJogador(MsgLimite, aIndex);
				return;
			}else
			{
				gObj(aIndex)->Energy += Pontos;
				MsgParaJogador("[Add] Pontos Adicionados, relogue!", aIndex);
			}
		break;

		case 4: // - Comando
			if(gObj(aIndex)->DbClass < 0x40)
			{
				MsgParaJogador("[Add] /com é para Dark Lord", aIndex);
				return;
			}

			if((gObj(aIndex)->Leadership+Pontos) > 32767)
			{
				MsgParaJogador("[Add] Máximo 32767 em Comando!", aIndex);
				return;
			}else
			{
				gObj(aIndex)->Leadership += Pontos;
				MsgParaJogador("[Add] Pontos Adicionados, relogue!", aIndex);
			}
		break;
	}

	CalCharacterEx(aIndex);
	gObj(aIndex)->LevelUpPoint		-= Pontos;
	gObj(aIndex)->Money				-= cmm_Add_Custo;
	GCMoneySend(aIndex, gObj(aIndex)->Money);
}