#include "stdafx.h"

void GCDiePlayerSend_Hook(LPOBJ lpObj, int TargetIndex, BYTE skill, int KillerIndex)
{
	if(gObj(TargetIndex)->Type == 1 && gObj(KillerIndex)->Type == 1)
	{
		if(TargetIndex != KillerIndex)
		{
			Mssql_Atualiza(TargetIndex, 11);	// - Vítima
			Mssql_Atualiza(KillerIndex, 10);	// - Matador
		}
	}

	GCDiePlayerSend(lpObj, TargetIndex, skill, KillerIndex);
}