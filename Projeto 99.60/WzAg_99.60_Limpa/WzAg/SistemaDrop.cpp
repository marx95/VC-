#include "StdAfx.h"

StructSets Sets[256];
StructArmamentos Armamentos[256];

void Carregar_Sets()
{
	GS.TotalSets		= 0;
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;
	
	token.ParseFile(std::string("..\\Data\\Lang\\Chs\\Item(Chs).txt"), group);
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

	token.ParseFile(std::string("..\\Data\\Lang\\Chs\\Item(Chs).txt"), group);
	
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
				Armamentos[GS.TotalArmas].Option= section.Rows[a].GetInt(6);
				Armamentos[GS.TotalArmas].Skill	= section.Rows[a].GetInt(2);
				GS.TotalArmas++;
			}
		}
	}
}

void CarregarDropCustom()
{
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
	if(gObj(MonsterID)->Level < 35) return false;

	int tmpIndex = 0;
	int tmpGrupo = 0;
	int tmpLevel = 0;

	bool Drop_Misc_Count[7];
	int Drop_Misc_Index = -1;

	Drop_Misc_Count[0] = gObjCustom[aIndex].Drop_Life;
	Drop_Misc_Count[1] = gObjCustom[aIndex].Drop_Bless;
	Drop_Misc_Count[2] = gObjCustom[aIndex].Drop_Soul;
	Drop_Misc_Count[3] = gObjCustom[aIndex].Drop_Chaos;
	Drop_Misc_Count[4] = gObjCustom[aIndex].Drop_Creation;
	Drop_Misc_Count[5] = gObjCustom[aIndex].Drop_Lochs;
	Drop_Misc_Count[6] = gObjCustom[aIndex].Drop_Crest;

	for(int i = 0; i < 6; i++)
	{
		if(Drop_Misc_Index == -1)
		{
			if(!Drop_Misc_Count[i]) Drop_Misc_Index = i;
		}
	}

	if(Drop_Misc_Index == -1)
	{
		gObjCustom[aIndex].Drop_Soul		= false;
		gObjCustom[aIndex].Drop_Life		= false;
		gObjCustom[aIndex].Drop_Bless		= false;
		gObjCustom[aIndex].Drop_Creation	= false;
		gObjCustom[aIndex].Drop_Chaos		= false;
		gObjCustom[aIndex].Drop_Lochs		= false;
		gObjCustom[aIndex].Drop_Crest		= false;
		return false;
	}

	switch(Drop_Misc_Index)
	{
		case 0: //Jewel of Life
			tmpGrupo = 14; 
			tmpIndex = 16; 
			tmpLevel = 0;
			gObjCustom[aIndex].Drop_Life = true;
		break;
		case 1: //Jewel of Bless
			tmpGrupo = 14; 
			tmpIndex = 13; 
			tmpLevel = 0; 
			gObjCustom[aIndex].Drop_Bless = true;
		break;
		case 2: //Jewel of Soul
			tmpGrupo = 14;
			tmpIndex = 14;
			tmpLevel = 0;
			gObjCustom[aIndex].Drop_Soul = true;
		break;
		case 3: //Jewel of Chaos 
			tmpGrupo = 12;
			tmpIndex = 15; 
			tmpLevel = 0; 
			gObjCustom[aIndex].Drop_Chaos = true;
		break;
		case 4: //Jewel of Creation
			tmpGrupo = 14; 
			tmpIndex = 22; 
			tmpLevel = 0; 
			gObjCustom[aIndex].Drop_Creation = true;
		break;
		case 5: //Loch's Feather
			tmpGrupo = 13;
			tmpIndex = 14; 
			tmpLevel = 0; 
			gObjCustom[aIndex].Drop_Lochs = true;
		break;
		case 6: //Crest of Monarch
			tmpGrupo = 13; 
			tmpIndex = 14; 
			tmpLevel = 1; 
			gObjCustom[aIndex].Drop_Crest = true;
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

	int Tentativas	= 0;
	while(Intervalo > GS.DropCore_Intervalo || Sets[rSet].Level > gObj(MonsterID)->Level)
	{
		if(Tentativas > 5) return false; //Isso nao deixa usar muito do processador
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
		if(Tentativas > 5) return false; //Isso nao deixa usar muito do processador
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
	if(GS.Drop_Zen >= 0)			gObjCustom[aIndex].Intervalo_Zen++;

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

void gObjMonsterDieGiveItem_Hook(struct OBJECTSTRUCT* lpObj, struct OBJECTSTRUCT* lpTargetObj)
{
	if(lpObj->Class == 275)
	{
		if(GS.Kundun_MaxItens == 0) return;
		for(int i = 0; i < GS.Kundun_MaxItens; i++)
		{
			int X = (lpObj->X - 3) + rand()%7;
			int Y = (lpObj->Y - 3) + rand()%7;
			KundunEventItemBoxOpen(lpObj, lpObj->MapNumber, X, Y);
		}
		return;
	}

	int aMonsterIndex	= lpObj->m_Index;
	int aIndex			= lpTargetObj->m_Index;
	int ItemGrupo, ItemIndex, ItemLevel, ItemSkill, ItemLuck, ItemOpt, ItemExe, ItemNr;
	ItemLuck	= 0;
	ItemOpt		= 0;
	ItemExe		= 0;

	// - Kundun +3
	ItemGrupo	= 14;
	ItemIndex	= 11;
	ItemLevel	= 10;
	ItemSkill	= 0;
	ItemNr		= GerarItem(ItemGrupo, ItemIndex);

	if(lpObj->Class == 43 ||  lpObj->Class == 78 ||  lpObj->Class == 81) { ItemSerialCreateSend(aIndex, gObj(aIndex)->MapNumber, (BYTE)gObj(aIndex)->X, (BYTE)gObj(aIndex)->Y, ItemNr, ItemLevel, 55, 0, ItemLuck, ItemOpt, aIndex, ItemExe, 0); return; }
	
	// - Kundun +4
	ItemGrupo	= 14;
	ItemIndex	= 11;
	ItemLevel	= 11;
	ItemSkill	= 0;
	ItemNr		= GerarItem(ItemGrupo, ItemIndex);
	if(lpObj->Class == 80 ||  lpObj->Class == 82 ||  lpObj->Class == 236) { ItemSerialCreateSend(aIndex, gObj(aIndex)->MapNumber, (BYTE)gObj(aIndex)->X, (BYTE)gObj(aIndex)->Y, ItemNr, ItemLevel, 55, 0, ItemLuck, ItemOpt, aIndex, ItemExe, 0); return; }

	// - Kundun +5
	ItemGrupo	= 14;
	ItemIndex	= 11;
	ItemLevel	= 12;
	ItemSkill	= 0;
	ItemNr		= GerarItem(ItemGrupo, ItemIndex);
	if(lpObj->Class == 83 ||  lpObj->Class == 53 ||  lpObj->Class == 79) { ItemSerialCreateSend(aIndex, gObj(aIndex)->MapNumber, (BYTE)gObj(aIndex)->X, (BYTE)gObj(aIndex)->Y, ItemNr, ItemLevel, 55, 0, ItemLuck, ItemOpt, aIndex, ItemExe, 0); return; }

	// - White Wizard & Cia
	ItemGrupo	= 14;
	ItemIndex	= 11;
	ItemLevel	= 10 + rand()%3;
	ItemSkill	= 0;
	ItemNr		= GerarItem(ItemGrupo, ItemIndex);
	if(lpObj->Class == 135 ||  lpObj->Class == 136 ||  lpObj->Class == 137) { ItemSerialCreateSend(aIndex, gObj(aIndex)->MapNumber, (BYTE)gObj(aIndex)->X, (BYTE)gObj(aIndex)->Y, ItemNr, ItemLevel, 55, 0, ItemLuck, ItemOpt, aIndex, ItemExe, 0); return; }

	// - RedDragon && Scricker && KundunDemon
	ItemGrupo	= 14;
	ItemIndex	= 11;
	ItemLevel	= 10;
	ItemSkill	= 0;
	ItemNr		= GerarItem(ItemGrupo, ItemIndex);

	if(lpObj->Class == 42 ||  lpObj->Class == 274 ||  lpObj->Class == 337 ||  lpObj->Class == 338) { ItemSerialCreateSend(aIndex, gObj(aIndex)->MapNumber, (BYTE)gObj(aIndex)->X, (BYTE)gObj(aIndex)->Y, ItemNr, ItemLevel, 55, 0, ItemLuck, ItemOpt, aIndex, ItemExe, 0); return; }
	
	// - Chaos Castle
	if(lpObj->Class > 161 && lpObj->Class < 174) { Dropar_Miscelandias(aIndex, aMonsterIndex); return; }
	
	ExecutarDropCustom(aIndex, aMonsterIndex);
}