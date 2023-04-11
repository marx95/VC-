#include "StdAfx.h"

void SetarStatus(int aIndex)
{
	unsigned short Classe = gObj(aIndex)->Class;
	int Porcentagem = 0;
	int NumeroInicial = GS.CalCharacter_Numero_Inicial[Classe];
	int Multiplicador = GS.CalCharacter_Multiplicador[Classe];

	// - Força
	if(gObj(aIndex)->Strength >= NumeroInicial)
	{
		if(gObj(aIndex)->Strength > 99) gObj(aIndex)->Strength -= NumeroInicial;
		Porcentagem = gObj(aIndex)->Strength / 100;
		gObj(aIndex)->Strength = NumeroInicial + (Porcentagem * Multiplicador);
	}

	// - Agilidade
	if(gObj(aIndex)->Dexterity >= NumeroInicial)
	{
		if(gObj(aIndex)->Dexterity > 99) gObj(aIndex)->Dexterity -= NumeroInicial;
		Porcentagem = gObj(aIndex)->Dexterity / 100;
		gObj(aIndex)->Dexterity = NumeroInicial + (Porcentagem * Multiplicador);
	}

	// - Vitalidade
	if(gObj(aIndex)->Vitality >= NumeroInicial)
	{
		if(gObj(aIndex)->Vitality > 99) gObj(aIndex)->Vitality -= NumeroInicial;
		Porcentagem = gObj(aIndex)->Vitality / 100;
		gObj(aIndex)->Vitality = NumeroInicial + (Porcentagem * Multiplicador);
	}

	// - Energia
	if(gObj(aIndex)->Energy >= NumeroInicial)
	{
		if(gObj(aIndex)->Energy > 99) gObj(aIndex)->Energy -= NumeroInicial;
		Porcentagem = gObj(aIndex)->Energy / 100;
		gObj(aIndex)->Energy = NumeroInicial + (Porcentagem * Multiplicador);
	}

	if(gObj(aIndex)->DbClass >= 64)
	{
		// - Comando
		if(gObj(aIndex)->Leadership >= NumeroInicial)
		{
			if(gObj(aIndex)->Leadership > 99) gObj(aIndex)->Leadership -= NumeroInicial;
			Porcentagem = gObj(aIndex)->Leadership / 100;
			gObj(aIndex)->Leadership = NumeroInicial + (Porcentagem * Multiplicador);
		}
	}
}

void CalCharacterEx(int aIndex)
{
	unsigned short Str_Antiga = gObj(aIndex)->Strength;
	unsigned short Agi_Antiga = gObj(aIndex)->Dexterity;
	unsigned short Vit_Antiga = gObj(aIndex)->Vitality;
	unsigned short Ene_Antiga = gObj(aIndex)->Energy;
	unsigned short Com_Antiga = gObj(aIndex)->Leadership;

	SetarStatus(aIndex);

	/* -- Agi Fix
	int agiFix = gObj(aIndex)->Dexterity;
	if(agiFix > 5000 && agiFix < 7000)	agiFix = 5000;
	if(agiFix > 8000 && agiFix < 11000) agiFix = 8000;
	if(agiFix > 13000 && agiFix < 23000) agiFix = 13000;

	if(agiFix > 28000) agiFix = 28000;
	gObj(aIndex)->Dexterity = agiFix;
	/*/

	if(gObj(aIndex)->Mana > 32000)		gObj(aIndex)->Mana		= 32000;
	if(gObj(aIndex)->MaxMana > 32000)	gObj(aIndex)->MaxMana	= 32000;
	gObjCalCharacter(aIndex);

	if(GS.Ativar_DanoReflete == 0) gObj(aIndex)->DamageReflect = 0;

	gObj(aIndex)->Strength		= Str_Antiga;
	gObj(aIndex)->Dexterity		= Agi_Antiga;
	gObj(aIndex)->Vitality		= Vit_Antiga;
	gObj(aIndex)->Energy		= Ene_Antiga;
	gObj(aIndex)->Leadership	= Com_Antiga;
}

void gObjCalCharacter_Hook(int aIndex)
{
	if(VerificarGM(aIndex))
	{
		gObj(aIndex)->Strength		= gObjCustom[aIndex].Limite_Pontos;
		gObj(aIndex)->Dexterity		= gObjCustom[aIndex].Limite_Pontos;
		gObj(aIndex)->Vitality		= gObjCustom[aIndex].Limite_Pontos;
		gObj(aIndex)->Energy		= gObjCustom[aIndex].Limite_Pontos;
		gObj(aIndex)->Leadership	= gObjCustom[aIndex].Limite_Pontos;
		gObjCalCharacter(aIndex);
		return;
	}

	CalCharacterEx(aIndex);
}