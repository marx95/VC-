#include "StdAfx.h"

void SetarStatus(int aIndex, int NumeroInicial, int Multiplicador)
{
	// - Força
	if(gObj(aIndex)->Strength > NumeroInicial)
	{
		int Porcentagem = gObj(aIndex)->Strength / 100;
		gObj(aIndex)->Strength = NumeroInicial + (Porcentagem * Multiplicador);
	}

	// - Agilidade
	if(gObj(aIndex)->Dexterity > NumeroInicial)
	{
		int Porcentagem = gObj(aIndex)->Dexterity / 100;
		gObj(aIndex)->Dexterity = NumeroInicial + (Porcentagem * Multiplicador);
	}

	// - Vitalidade
	if(gObj(aIndex)->Vitality > NumeroInicial)
	{
		int Porcentagem = gObj(aIndex)->Vitality / 100;
		gObj(aIndex)->Vitality = NumeroInicial + (Porcentagem * Multiplicador);
	}

	// - Energia
	if(gObj(aIndex)->Energy > NumeroInicial)
	{
		int Porcentagem = gObj(aIndex)->Energy / 100;
		gObj(aIndex)->Energy = NumeroInicial + (Porcentagem * Multiplicador);
	}

	if(gObj(aIndex)->DbClass >= 64)
	{
		// - Comando
		if(gObj(aIndex)->Leadership > NumeroInicial)
		{
			int Porcentagem = gObj(aIndex)->Leadership / 100;
			gObj(aIndex)->Leadership = NumeroInicial + (Porcentagem * Multiplicador);
		}
	}
}

void CalCharacterEx(int aIndex)
{
	int Str_Antiga				= gObj(aIndex)->Strength;
	int Agi_Antiga				= gObj(aIndex)->Dexterity;
	int Vit_Antiga				= gObj(aIndex)->Vitality;
	int Ene_Antiga				= gObj(aIndex)->Energy;
	int Com_Antiga				= gObj(aIndex)->Leadership;

	switch(gObj(aIndex)->DbClass)
	{
		case 0:  SetarStatus(aIndex, DW_SM_GM_NumeroInicial, DW_SM_GM_Multiplicador);	break;
		case 1:  SetarStatus(aIndex, DW_SM_GM_NumeroInicial, DW_SM_GM_Multiplicador);	break;
		case 2:  SetarStatus(aIndex, DW_SM_GM_NumeroInicial, DW_SM_GM_Multiplicador);	break;
		case 16: SetarStatus(aIndex, DK_BK_BM_NumeroInicial, DK_BK_BM_Multiplicador);	break;
		case 17: SetarStatus(aIndex, DK_BK_BM_NumeroInicial, DK_BK_BM_Multiplicador);	break;
		case 18: SetarStatus(aIndex, DK_BK_BM_NumeroInicial, DK_BK_BM_Multiplicador);	break;
		case 32: SetarStatus(aIndex, Elf_ME_HE_NumeroInicial, Elf_ME_HE_Multiplicador); break;
		case 33: SetarStatus(aIndex, Elf_ME_HE_NumeroInicial, Elf_ME_HE_Multiplicador); break;
		case 34: SetarStatus(aIndex, Elf_ME_HE_NumeroInicial, Elf_ME_HE_Multiplicador); break;
		case 48: SetarStatus(aIndex, MG_DM_NumeroInicial, MG_DM_Multiplicador);			break;
		case 49: SetarStatus(aIndex, MG_DM_NumeroInicial, MG_DM_Multiplicador);			break;
		case 64: SetarStatus(aIndex, DL_LE_NumeroInicial, DL_LE_Multiplicador);			break;
		case 65: SetarStatus(aIndex, DL_LE_NumeroInicial, DL_LE_Multiplicador);			break;
	}

	gObjCalCharacter(aIndex);
	gObj(aIndex)->Strength		= Str_Antiga;
	gObj(aIndex)->Dexterity		= Agi_Antiga;
	gObj(aIndex)->Vitality		= Vit_Antiga;
	gObj(aIndex)->Energy		= Ene_Antiga;
	gObj(aIndex)->Leadership	= Com_Antiga;
}

void CalCharacterHook(int aIndex)
{
	CalCharacterEx(aIndex);
}