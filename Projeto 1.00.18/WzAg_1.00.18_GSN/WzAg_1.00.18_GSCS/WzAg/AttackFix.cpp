#include "StdAfx.h"

INT ObjAttack(LPOBJ lpObj, LPOBJ lpTargetObj, class CMagicInf* lpMagic, int magicsend, unsigned char MSBFlag, int AttackDamage, BOOL bCombo)
{
	if(lpTargetObj->Type == 1)
	{
		int aIndex = lpObj->m_Index;
		int TargetIndex = lpTargetObj->m_Index;

		if(gObjCustom[aIndex].CtlCode >= GM_CtlCode && gObjCustom[aIndex].CtlCode <= ADM_Player_CtlCode) // Se for GM o atacante, ele deixa...
		{
			return gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
		}

		if(gObjCustom[TargetIndex].CtlCode >= GM_CtlCode && gObjCustom[TargetIndex].CtlCode <= ADM_CtlCode) // Se o alvo for GM, não deixa...
		{
			return false;
		}
	}

	return gObjAttack(lpObj, lpTargetObj, lpMagic, magicsend, MSBFlag, AttackDamage, bCombo);
}