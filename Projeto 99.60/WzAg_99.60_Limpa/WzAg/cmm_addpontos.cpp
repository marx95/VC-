#include "stdafx.h"

bool Verificar_Pontos(int aIndex, BYTE Tipo)
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

void cmm_AddPontos(int aIndex, char * Msg, int Tipo)
{
	char MsgSaida[128];

	if(GS.Add_Ativado == 0)
	{
		MsgPlayer("[Add] Comando Desativado.", aIndex);
		return;
	}
	
	if(gObjCustom[aIndex].Vip < GS.Add_Vip)
	{
		MsgPlayer("[Add] Necessário ser VIP.", aIndex);
		return;
	}

	if(gObj(aIndex)->Money < GS.Add_Zen)
	{
		sprintf_s(MsgSaida, "[Add] Necessário %d zen.", GS.Add_Zen);
		MsgPlayer(MsgSaida, aIndex);
		return;
	}

	if(strlen(Msg) == 0)
	{
		MsgPlayer("[Add] Valor inválido!", aIndex);
		return;
	}

	int Pontos = atoi(Msg);

	if(Pontos <= 0)
	{
		MsgPlayer("[Add] Valor inválido!", aIndex);
		return;
	}

	if(gObj(aIndex)->LevelUpPoint < Pontos)
	{
		MsgPlayer("[Add] Pontos insuficientes.", aIndex);
		return;
	}

	if(Tipo == 4 && gObj(aIndex)->Class != 4)
	{
		MsgPlayer("[Add] /com é para Dark Lord", aIndex);
		return;
	}

	if(!Verificar_Pontos(aIndex, Tipo))
	{
		char MsgFalha[64];
		sprintf_s(MsgFalha, "[Add] Você irá passar de %d!", gObjCustom[aIndex].Limite_Pontos);
		MsgPlayer(MsgFalha, aIndex);
		return;
	}

	gObj(aIndex)->LevelUpPoint -= Pontos;
	if(Tipo == 0) gObj(aIndex)->Strength += Pontos;
	if(Tipo == 1) gObj(aIndex)->Dexterity += Pontos;
	if(Tipo == 2)
	{
		gObj(aIndex)->Vitality += Pontos;
		Set_Life(aIndex, Pontos);
		GCReFillSend(aIndex, WORD(gObj(aIndex)->MaxLife + gObj(aIndex)->AddLife), 0xFE, 0);
	}
	if(Tipo == 3)
	{ 
		gObj(aIndex)->Energy += Pontos;
		Set_Mana(aIndex, Pontos);
		GCManaSend(aIndex, short(gObj(aIndex)->MaxMana + gObj(aIndex)->AddMana), 0xFE, 0, gObj(aIndex)->MaxBP);
	}
	if(Tipo == 4) gObj(aIndex)->Leadership += Pontos;

	Tirar_Zen(aIndex, GS.Add_Zen);
	Atualizar_Personagem(aIndex);
	MsgPlayer("[Add] Pontos Adicionados!", aIndex);
}