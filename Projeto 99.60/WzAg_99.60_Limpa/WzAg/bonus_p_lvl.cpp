#include "StdAfx.h"

//bool gObjLevelUp_Hook(LPOBJ lpObj, int addexp, int iMonsterType, int iEventType)
unsigned char gObjLevelUp_Hook(struct OBJECTSTRUCT* lpObj, int addexp)
{
	
	int aIndex = lpObj->m_Index;

	if(gObj(aIndex)->Level >= GS.Level_Maximo)
	{
		gObj(aIndex)->Experience = GS.Experiencia[(gObj(aIndex)->Level-1)];
		if(gObjCustom[aIndex].Level_Max_Msg) return false;
		gObjCustom[aIndex].Level_Max_Msg = true;
		GCServerMsgStringSend("Você chegou no level máximo!", aIndex, 1);
		return false;
	}

	gObjSetExpPetItem(aIndex, addexp);

	if(gObj(aIndex)->Experience > gObj(aIndex)->NextExp)
	{
		int NExp = 0;
		int NecessarioAtualizar = 0;

		while(gObj(aIndex)->Experience > gObj(aIndex)->NextExp)
		{
			NecessarioAtualizar = 1;
			NExp = gObj(aIndex)->Experience - gObj(aIndex)->NextExp;
			gObj(aIndex)->Experience = gObj(aIndex)->NextExp;
			gObj(aIndex)->Level++;

			gObj(aIndex)->LevelUpPoint += Pegar_Pontos_por_Level(aIndex);

			//gObjNextExpCal_Hook(lpObj);	
			gObjNextExpCal(lpObj);

			Set_Life(aIndex, 1);
			Set_Mana(aIndex, 1);
			gObj(aIndex)->Life = gObj(aIndex)->MaxLife;
			gObj(aIndex)->Mana = gObj(aIndex)->MaxMana;

			if(gObj(aIndex)->Class == 2) // Elf
			{
				if(gObj(aIndex)->ChangeUP > 0)
				{
					int iAddSkillPosition = gObjMagicAdd(lpObj, 0x4D, 0);
					if(gObjMagicAdd(lpObj,0x4D,0) > 0) GCMagicListOneSend(aIndex, iAddSkillPosition, 0x4D, 0xDC, 0, 0);
				}
			}

			if(NExp > 0) gObj(aIndex)->Experience += NExp;
		}

		if(NecessarioAtualizar == 1)
		{
			GCReFillSend(aIndex, WORD(gObj(aIndex)->MaxLife + gObj(aIndex)->AddLife), 0xFE, 0);
			gObjSetBP(aIndex);
			GCManaSend(aIndex, short(gObj(aIndex)->MaxMana + gObj(aIndex)->AddMana), 0xFE, 0, gObj(aIndex)->MaxBP);
			CalCharacterEx(aIndex);
			gObjCalcMaxLifePower(aIndex);
			GCLevelUpMsgSend(aIndex, 1);
		}
	}
	return true;
}