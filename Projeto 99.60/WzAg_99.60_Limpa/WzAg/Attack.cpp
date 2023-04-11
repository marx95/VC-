#include "StdAfx.h"

int gObjAttack_Hook(struct OBJECTSTRUCT* lpObj, struct OBJECTSTRUCT* lpTargetObj, class CMagicInf* lpMagic, int magicsend, unsigned char MSBFlag, int AttackDamage, int bCombo)
{
	if(lpTargetObj->Type == 2) return gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
	if(lpTargetObj->Type == 3) return false;

	if(lpObj->Type == 1 && lpTargetObj->Type == 1)
	{
		int aIndex		= lpObj->m_Index;
		int TargetIndex = lpTargetObj->m_Index;

		if(No_Duelo(aIndex, TargetIndex)) // Se estiver em Duelo, deixa...
		{
			return gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
		}

		if(VerificarGM(aIndex)) // Se for GM o atacante, deixa...
		{
			return gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
		}

		if(VerificarGM(TargetIndex)) // Se o alvo for GM, não deixa...
		{
			return false;
		}

		if(gObj(aIndex)->Level >= GS.Level_Minimo_para_PVP_Qualquer_Mapa && gObj(TargetIndex)->Level >= GS.Level_Minimo_para_PVP_Qualquer_Mapa)
		{
			return gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
		}

		// - PVP1
		if(gObj(TargetIndex)->MapNumber == GS.PVP1_Mapa_PVP) //Atenção, verificação é feita pelo Alvo (SEMPRE)
		{
			int Liberado_PVP1 = 0;
			if(gObj(TargetIndex)->X >= GS.PVP1_Mapa_a_X && gObj(TargetIndex)->X <= GS.PVP1_Mapa_b_X) Liberado_PVP1++;
			if(gObj(TargetIndex)->Y >= GS.PVP1_Mapa_a_Y && gObj(TargetIndex)->Y <= GS.PVP1_Mapa_b_Y) Liberado_PVP1++;
			if(Liberado_PVP1 == 2) return gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
		}

		// - PVP2
		if(gObj(TargetIndex)->MapNumber == GS.PVP2_Mapa_PVP) //Atenção, verificação é feita pelo Alvo (SEMPRE)
		{
			int Liberado_PVP2 = 0;
			if(gObj(TargetIndex)->X >= GS.PVP2_Mapa_a_X && gObj(TargetIndex)->X <= GS.PVP2_Mapa_b_X) Liberado_PVP2++;
			if(gObj(TargetIndex)->Y >= GS.PVP2_Mapa_a_Y && gObj(TargetIndex)->Y <= GS.PVP2_Mapa_b_Y) Liberado_PVP2++;
			if(Liberado_PVP2 == 2) return gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
		}

		if(gObj(TargetIndex)->MapNumber >= 18 && gObj(TargetIndex)->MapNumber <= 23)
		{
			return gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
		}

		return false;
	}

	return gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
}