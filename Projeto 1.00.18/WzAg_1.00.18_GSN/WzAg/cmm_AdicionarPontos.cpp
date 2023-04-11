#include "StdAfx.h"

bool VerificarPontos(int aIndex, BYTE Tipo)
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

void AdicionarPontos(int aIndex, LPCSTR lpBuffer, int Tipo)
{
	int Pontos = atoi(lpBuffer);
	char TmpMsg[128];
	sprintf_s(TmpMsg, "[Add] Máximo %d pontos!", gObjCustom[aIndex].Limite_Pontos);

	if(GS.cmm_Add_Ativado == 0)
	{
		MsgParaJogador("[Add] Comando desabilitado", aIndex);
		return;
	}

	if(GS.cmm_Add_Level > gObj(aIndex)->Level)
	{
		char levelmsg[100];
		sprintf(levelmsg,"[Add] Level necessário: %d.", GS.cmm_Add_Level);
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

	if(GS.cmm_Add_Custo >gObj(aIndex)->Money)
	{
		char OutputZenFalha[200];
		sprintf_s(OutputZenFalha,"[Add] Necessário %d zen", GS.cmm_Add_Custo);
		MsgParaJogador(OutputZenFalha, aIndex);
		return;
	}

	switch(Tipo)
	{
		case 1: // - Força
			if((gObj(aIndex)->Strength+Pontos) > gObjCustom[aIndex].Limite_Pontos)
			{
				MsgParaJogador(TmpMsg, aIndex);
				return;
			}else
			{
				gObj(aIndex)->Strength += Pontos;
			}
		break;

		case 2: // - Agilidade
			if((gObj(aIndex)->Dexterity+Pontos) > gObjCustom[aIndex].Limite_Pontos)
			{
				MsgParaJogador(TmpMsg, aIndex);
				return;
			}else
			{
				gObj(aIndex)->Dexterity += Pontos;
			}
		break;

		case 3: // - Vitalidade
			if((gObj(aIndex)->Vitality+Pontos) > gObjCustom[aIndex].Limite_Pontos)
			{
				MsgParaJogador(TmpMsg, aIndex);
				return;
			}else
			{
				Set_Life(aIndex, Pontos);
				gObj(aIndex)->Vitality += Pontos;
			}
		break;

		case 4: // - Energia
			if((gObj(aIndex)->Energy+Pontos) > gObjCustom[aIndex].Limite_Pontos)
			{
				MsgParaJogador(TmpMsg, aIndex);
				return;
			}else
			{
				Set_Mana(aIndex, Pontos);
				gObj(aIndex)->Energy += Pontos;
			}
		break;

		case 5: // - Comando
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
			}
		break;
	}

	gObj(aIndex)->LevelUpPoint		-= Pontos;
	gObj(aIndex)->Money				-= GS.cmm_Add_Custo;
	GCMoneySend(aIndex, gObj(aIndex)->Money);
	Atualizar_Personagem(aIndex);
	MsgParaJogador("[Add] Pontos adicionados!", aIndex);
}