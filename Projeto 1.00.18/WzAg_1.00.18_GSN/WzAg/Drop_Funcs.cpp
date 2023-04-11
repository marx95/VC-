#include "stdafx.h"

int Radom2ExcOptGen()
{
	int ItemExc = 1;
	int DDvi = 1 + rand()%21;
	if(DDvi == 1)ItemExc = 1;
	if(DDvi == 2)ItemExc = 2;
	if(DDvi == 3)ItemExc = 4;
	if(DDvi == 4)ItemExc = 8;
	if(DDvi == 5)ItemExc = 16;
	if(DDvi == 6)ItemExc = 32;
	if(DDvi == 7)ItemExc = 3;
	if(DDvi == 8)ItemExc = 5;
	if(DDvi == 9)ItemExc = 6;
	if(DDvi == 10)ItemExc = 9;
	if(DDvi == 11)ItemExc = 10;
	if(DDvi == 12)ItemExc = 12;
	if(DDvi == 13)ItemExc = 17;
	if(DDvi == 14)ItemExc = 18;
	if(DDvi == 15)ItemExc = 20;
	if(DDvi == 16)ItemExc = 24;
	if(DDvi == 17)ItemExc = 33;
	if(DDvi == 18)ItemExc = 34;
	if(DDvi == 19)ItemExc = 36;
	if(DDvi == 20)ItemExc = 40;
	if(DDvi == 21)ItemExc = 48;
	return ItemExc;
}

bool Verifica_Zen(int aIndex)
{
	if(GS.Drop_Zen == -1) return false;

	if(gObjCustom[aIndex].Intervalo_Zen >= GS.Drop_Zen)
	{
		gObjCustom[aIndex].Intervalo_Zen = 0;
		return true;
	}

	return false;
}

bool Verifica_Sets(int aIndex)
{
	if(GS.Drop_Sets == -1) return false;

	if(gObjCustom[aIndex].Intervalo_Sets >= GS.Drop_Sets)
	{
		gObjCustom[aIndex].Intervalo_Sets = 0;
		return true;
	}

	return false;
}

bool Verifica_Armamentos(int aIndex)
{
	if(GS.Drop_Armamentos == -1) return false;

	if(gObjCustom[aIndex].Intervalo_Armamentos >= GS.Drop_Armamentos)
	{
		gObjCustom[aIndex].Intervalo_Armamentos = 0;
		return true;
	}

	return false;
}

bool Verifica_Miscelandias(int aIndex)
{
	if(GS.Drop_Miscelandias == -1) return false;

	if(gObjCustom[aIndex].Intervalo_Misc >= GS.Drop_Miscelandias)
	{
		gObjCustom[aIndex].Intervalo_Misc = 0;
		return true;
	}

	return false;
}

int Verifica_Luck(int aIndex)
{
	if(GS.Drop_Itens_Luck == -1) return 0;

	if(gObjCustom[aIndex].Intervalo_Luck >= GS.Drop_Itens_Luck)
	{
		gObjCustom[aIndex].Intervalo_Luck = 0;
		return 1;
	}

	return 0;
}

int Verifica_Skill(int aIndex)
{
	if(GS.Drop_Itens_Skill == -1) return 0;

	if(gObjCustom[aIndex].Intervalo_Skill >= GS.Drop_Itens_Skill)
	{
		gObjCustom[aIndex].Intervalo_Skill = 0;
		return 1;
	}

	return 0;
}

int Verifica_Opt(int aIndex)
{
	if(GS.Drop_Itens_Option == -1) return 0;

	if(gObjCustom[aIndex].Intervalo_Option >= GS.Drop_Itens_Option)
	{
		gObjCustom[aIndex].Intervalo_Option = 0;
		return 1;
	}

	return 0;
}

int Verifica_Exe(int aIndex)
{
	if(GS.Drop_Itens_Exe == -1) return 0;

	if(gObjCustom[aIndex].Intervalo_Exe >= GS.Drop_Itens_Exe)
	{
		gObjCustom[aIndex].Intervalo_Exe = 0;
		return Radom2ExcOptGen();
	}

	return 0;
}

int Verifica_Anci(int aIndex)
{
	if(GS.Drop_Itens_Ancient == -1) return 0;

	if(gObjCustom[aIndex].Intervalo_Anci >= GS.Drop_Itens_Ancient)
	{
		gObjCustom[aIndex].Intervalo_Anci = 0;
		int ADiv = rand()%3;
		if(ADiv == 0) return 0;
		if(ADiv == 1) return 5;
		if(ADiv == 2) return 10;
	}

	return 0;
}