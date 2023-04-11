#include "StdAfx.h"

StructSets Sets[256];
StructArmamentos Armamentos[256];

void Carregar_Sets()
{
	GS.TotalSets		= 0;
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;
	
	token.ParseFile(std::string("..\\Data\\Lang\\Kor\\Item(Kor).txt"), group);
	group.GetSection(8, section);
	for(int i = 0; i < section.RowCount; i++)
	{
		Sets[GS.TotalSets].Level		= section.Rows[i].GetInt(9);
		Sets[GS.TotalSets].Option		= section.Rows[i].GetInt(6);
		Sets[GS.TotalSets].Index		= section.Rows[i].GetInt(0);
		GS.TotalSets++;
	}
}

void Carregar_Armas()
{
	GS.TotalArmas   = 0;
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string("..\\Data\\Lang\\Kor\\Item(Kor).txt"), group);
	
	for(int i = 0; i < 6; i++)
	{
		group.GetSection(i, section);
		for(int a = 0; a < section.RowCount; a++)
		{
			if(section.Rows[a].GetInt(7) == 1)
			{
				Armamentos[GS.TotalArmas].Drop		= 1;
				Armamentos[GS.TotalArmas].Grupo	= i;
				Armamentos[GS.TotalArmas].Index	= section.Rows[a].GetInt(0);
				Armamentos[GS.TotalArmas].Level	= section.Rows[a].GetInt(9);
				Armamentos[GS.TotalArmas].Option	= section.Rows[a].GetInt(6);
				Armamentos[GS.TotalArmas].Skill	= section.Rows[a].GetInt(2);
				GS.TotalArmas++;
			}
		}
	}
}

void CarregarDropCustom()
{
	//SistemaDrop.cpp
	GS.DropCore_Intervalo		= GetPrivateProfileIntA("DropCustom","Drop_Intervalo", 30,"..\\MarxD\\DropCustom.ini");
	GS.Drop_Sets				= GetPrivateProfileIntA("DropCustom","Taxa_De_Drop_Sets", -1,"..\\MarxD\\DropCustom.ini");
	GS.Drop_Armamentos			= GetPrivateProfileIntA("DropCustom","Taxa_De_Drop_Armamentos", -1,"..\\MarxD\\DropCustom.ini");
	GS.Drop_Itens_Exe			= GetPrivateProfileIntA("DropCustom","Taxa_De_Drop_Itens_Exe", -1,"..\\MarxD\\DropCustom.ini");
	GS.Drop_Itens_Luck			= GetPrivateProfileIntA("DropCustom","Taxa_De_Drop_Itens_com_Luck", -1,"..\\MarxD\\DropCustom.ini");
	GS.Drop_Itens_Option		= GetPrivateProfileIntA("DropCustom","Taxa_De_Drop_Itens_com_Option", -1,"..\\MarxD\\DropCustom.ini");
	GS.Drop_Itens_Skill			= GetPrivateProfileIntA("DropCustom","Taxa_De_Drop_Itens_com_Skill", -1,"..\\MarxD\\DropCustom.ini");
	GS.Drop_Itens_Ancient		= GetPrivateProfileIntA("DropCustom","Taxa_De_Drop_Itens_Ancient", -1,"..\\MarxD\\DropCustom.ini");
	GS.Drop_Miscelandias		= GetPrivateProfileIntA("DropCustom","Taxa_De_Drop_Miscelandias", -1,"..\\MarxD\\DropCustom.ini");
	GS.Drop_Zen					= GetPrivateProfileIntA("DropCustom","Taxa_De_Drop_de_Zen", -1,"..\\MarxD\\DropCustom.ini");

	Carregar_Sets();
	Carregar_Armas();
}

void Dropar_Zen(int aIndex, int MonsterID)
{
	int Level;
	if(gObj(MonsterID)->Level >= 10)	Level = gObj(MonsterID)->Level/10;
	if(gObj(MonsterID)->Level >= 100)	Level = gObj(MonsterID)->Level/100;
	if(Level > 13) Level = 13;
	int Zen = GerarItem(14, 15);
	ItemSerialCreateSend(MonsterID , gObj(MonsterID)->MapNumber, (BYTE)gObj(MonsterID)->X, (BYTE)gObj(MonsterID)->Y, Zen, Level, 0, 0, 0, 0, aIndex, 0, 0);
	return;
}

bool Dropar_Miscelandias(int aIndex, int MonsterID)
{
	int tmpIndex = 0;
	int tmpGrupo = 0;
	int tmpLevel = 0;

	switch(rand()%12)
	{
		case 0: //Jewel of Chaos
			if(gObj(MonsterID)->Level < 35) return false;
			tmpGrupo = 12;
			tmpIndex = 15; 
			tmpLevel = 0; 
		break;
		case 1: //Jewel of Bless
			if(gObj(MonsterID)->Level < 35) return false;
			tmpGrupo = 14; 
			tmpIndex = 13; 
			tmpLevel = 0; 
		break;
		case 2: //Jewel of Soul
			if(gObj(MonsterID)->Level < 35) return false;
			tmpGrupo = 14;
			tmpIndex = 14;
			tmpLevel = 0;
		break;
		case 3: //Jewel of Life 
			if(gObj(MonsterID)->Level < 35) return false;
			tmpGrupo = 14; 
			tmpIndex = 16; 
			tmpLevel = 0; 
		break;

		case 4: //Jewel of Creation
			if(gObj(MonsterID)->Level < 35) return false;
			tmpGrupo = 14; 
			tmpIndex = 22; 
			tmpLevel = 0; 
		break;

		case 5: //Loch's Feather
			if(gObj(MonsterID)->Level < 90) return false;
			tmpGrupo = 13;
			tmpIndex = 14; 
			tmpLevel = 0; 
		break;
		case 6: //Crest of Monarch
			if(gObj(MonsterID)->Level < 90) return false;
			tmpGrupo = 13; 
			tmpIndex = 14; 
			tmpLevel = 1; 
		break; 
		case 7: //Crystal
			if(gObj(MonsterID)->Level < 90) return false;
			tmpGrupo = 13; 
			tmpIndex = 52; 
			tmpLevel = 0; 
		break; 
		case 8: // Jewel of Harmony 
			if(gObj(MonsterID)->Level < 90) return false;
			tmpGrupo = 14; 
			tmpIndex = 42; 
			tmpLevel = 0; 
		break;
		case 9: //MoonStone Ring
			if(gObj(MonsterID)->MapNumber != 38) return false;
			tmpGrupo = 13; 
			tmpIndex = 38; 
			tmpLevel = 0; 
		break;
		case 10: //Gemstone
			if(gObj(MonsterID)->MapNumber != 37 || gObj(MonsterID)->MapNumber != 38) return false;
			tmpGrupo = 14; 
			tmpIndex = 41; 
			tmpLevel = 0; 
		break;
		case 11: //Jewel of Guardian
			if(gObj(MonsterID)->MapNumber != 38) return false;
			tmpGrupo = 14; 
			tmpIndex = 31; 
			tmpLevel = 0; 
		break;
	}

	int tmpItem = GerarItem(tmpGrupo, tmpIndex);
	if(tmpItem > 0)
	{
		ItemSerialCreateSend(MonsterID, gObj(MonsterID)->MapNumber, (BYTE)gObj(MonsterID)->X, (BYTE)gObj(MonsterID)->Y, tmpItem, tmpLevel, 0, 0, 0, 0, aIndex, 0, 0);
		return true;
	}

	return false;
}

bool Dropar_Sets(int aIndex, int MonsterID)
{

	int rSet		= rand()%GS.TotalSets;
	int Intervalo	= gObj(MonsterID)->Level - Sets[rSet].Level;

	int Tentativas = 0;
	while(Intervalo > GS.DropCore_Intervalo || Sets[rSet].Level > gObj(MonsterID)->Level)
	{
		if(Tentativas > 15) return false; //Isso nao deixa usar muito do processador
		Tentativas++;
		rSet		= rand()%GS.TotalSets;
		Intervalo	= gObj(MonsterID)->Level - Sets[rSet].Level;
	}

	int Grupo			= 7+rand()%5;
	int ItemNr			= GerarItem(Grupo, Sets[rSet].Index);
	int Level			= 0;
	int Luck			= 0;
	int Opt				= 0;
	int Exe				= 0;
	int Anci			= 0;
	int Dur				= 0;

	// - Elmos do Magic-Gladiator FIX
	if(Sets[rSet].Index == 15 || Sets[rSet].Index == 20 || Sets[rSet].Index == 23 || Sets[rSet].Index == 32 || Sets[rSet].Index == 37) return false;

	Level	= rand()%5;
	Dur		= 1 + rand()%79;
	Luck	= Verifica_Luck(aIndex);
	Exe		= Verifica_Exe(aIndex);
	Anci	= Verifica_Anci(aIndex);
	if(Sets[rSet].Option		> 0)	Opt = Verifica_Opt(aIndex);

	//if(Luck == 0 && Opt == 0 && Luck == 0 && Anci == 0 && Exe == 0) return false;
	if(ItemNr > 0)
	{
		ItemSerialCreateSend(MonsterID, gObj(MonsterID)->MapNumber, (BYTE)gObj(MonsterID)->X, (BYTE)gObj(MonsterID)->Y, ItemNr, Level, Dur, 0, Luck, Opt, aIndex, Exe, Anci);
		return true;
	}

	return false;
}

bool Dropar_Armamentos(int aIndex, int MonsterID)
{
	int rArma = rand()%GS.TotalArmas;
	int Intervalo	= gObj(MonsterID)->Level - Armamentos[rArma].Level;

	int Tentativas = 0;
	while(Intervalo > GS.DropCore_Intervalo || Armamentos[rArma].Level > gObj(MonsterID)->Level)
	{
		if(Tentativas > 15) return false; //Isso nao deixa usar muito do processador
		Tentativas++;
		rArma = rand()%GS.TotalArmas;
		Intervalo	= gObj(MonsterID)->Level - Armamentos[rArma].Level;
	}

	int ItemNr			= GerarItem(Armamentos[rArma].Grupo, Armamentos[rArma].Index);
	int Level			= 0;
	int Luck			= 0;
	int Opt				= 0;
	int Exe				= 0;
	int Anci			= 0;
	int Dur				= 0;
	int Skill			= 0;

	Level	= rand()%5;
	Dur		= 1 + rand()%79;
	Luck	= Verifica_Luck(aIndex);
	if(Armamentos[rArma].Skill	> 0) Skill	= Verifica_Skill(aIndex);
	if(Armamentos[rArma].Option	> 0) Opt	= Verifica_Opt(aIndex);
	Exe		= Verifica_Exe(aIndex);
	Anci	= Verifica_Anci(aIndex);

	//if(Luck == 0 && Opt == 0 && Luck == 0 && Anci == 0 && Exe == 0) return false;
	if(ItemNr > 0)
	{
		ItemSerialCreateSend(MonsterID, gObj(MonsterID)->MapNumber, (BYTE)gObj(MonsterID)->X, (BYTE)gObj(MonsterID)->Y, ItemNr, Level, Dur, Skill, Luck, Opt, aIndex, Exe, Anci);
		return true;
	}
	return false;
}

void ExecutarDropCustom(int aIndex, int MonsterID)
{
	if(GS.Drop_Itens_Ancient >= 0)	gObjCustom[aIndex].Intervalo_Anci++;
	if(GS.Drop_Itens_Exe >= 0)		gObjCustom[aIndex].Intervalo_Exe++;
	if(GS.Drop_Itens_Option >= 0)	gObjCustom[aIndex].Intervalo_Option++;
	if(GS.Drop_Itens_Skill >= 0)	gObjCustom[aIndex].Intervalo_Skill++;
	if(GS.Drop_Itens_Luck >= 0)		gObjCustom[aIndex].Intervalo_Luck++;
	if(GS.Drop_Miscelandias >= 0)	gObjCustom[aIndex].Intervalo_Misc++;
	if(GS.Drop_Armamentos >= 0)		gObjCustom[aIndex].Intervalo_Armamentos++;
	if(GS.Drop_Sets >= 0)			gObjCustom[aIndex].Intervalo_Sets++;
	if(GS.Drop_Itens_Ancient >= 0)	gObjCustom[aIndex].Intervalo_Zen++;

	if(Verifica_Zen(aIndex))
	{
		Dropar_Zen(aIndex, MonsterID);
		return;
	}

	if(Verifica_Miscelandias(aIndex))
	{
		if(Dropar_Miscelandias(aIndex, MonsterID)) return;
	}

	if(Verifica_Sets(aIndex))
	{
		if(Dropar_Sets(aIndex, MonsterID)) return;
	}

	if(Verifica_Armamentos(aIndex))
	{
		if(Dropar_Armamentos(aIndex, MonsterID)) return;
	}
}

BOOL gEventMonsterItemDrop_Hook(LPOBJ lpObj, LPOBJ lpTargetObj)
{
	int aMonsterIndex	= lpObj->m_Index;
	int aIndex			= lpTargetObj->m_Index;
	ExecutarDropCustom(aIndex, aMonsterIndex);
	return true;
}