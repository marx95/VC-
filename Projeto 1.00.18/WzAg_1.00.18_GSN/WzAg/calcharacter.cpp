#include "StdAfx.h"

void SetarStatus(int aIndex, int NumeroInicial, int Multiplicador)
{
	int Porcentagem = 0;

	// - Força
	if(gObj(aIndex)->Strength >= NumeroInicial)
	{
		Porcentagem = gObj(aIndex)->Strength / 100;
		gObj(aIndex)->Strength = NumeroInicial + (Porcentagem * Multiplicador);
	}

	// - Agilidade
	if(gObj(aIndex)->Dexterity >= NumeroInicial)
	{
		Porcentagem = gObj(aIndex)->Dexterity / 100;
		gObj(aIndex)->Dexterity = NumeroInicial + (Porcentagem * Multiplicador);
	}

	// - Vitalidade
	if(gObj(aIndex)->Vitality >= NumeroInicial)
	{
		Porcentagem = gObj(aIndex)->Vitality / 100;
		gObj(aIndex)->Vitality = NumeroInicial + (Porcentagem * Multiplicador);
	}

	// - Energia
	if(gObj(aIndex)->Energy >= NumeroInicial)
	{
		Porcentagem = gObj(aIndex)->Energy / 100;
		gObj(aIndex)->Energy = NumeroInicial + (Porcentagem * Multiplicador);
	}

	if(gObj(aIndex)->Class == 4)
	{
		// - Comando
		if(gObj(aIndex)->Leadership >= NumeroInicial)
		{
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

	int Numero_Inicial			= GS.CC_NumeroInicial[(gObj(aIndex)->DbClass >> 4)];
	int Multiplicador			= GS.CC_Multiplicador[(gObj(aIndex)->DbClass >> 4)];

	SetarStatus(aIndex, Numero_Inicial, Multiplicador);
	gObjCalCharacter(aIndex);
	if(GS.Ativar_Reflete == 0) gObj(aIndex)->DamageReflect = 0;

	gObj(aIndex)->Strength		= Str_Antiga;
	gObj(aIndex)->Dexterity		= Agi_Antiga;
	gObj(aIndex)->Vitality		= Vit_Antiga;
	gObj(aIndex)->Energy		= Ene_Antiga;
	gObj(aIndex)->Leadership	= Com_Antiga;
}

void gObjCalCharacter_Hook(int aIndex)
{
	if(VerificarGM(aIndex)) gObjCalCharacter(aIndex);
	CalCharacterEx(aIndex);
}