#include "stdafx.h"

void GCDiePlayerSend_Hook(struct OBJECTSTRUCT* lpObj, int TargetIndex, unsigned char skill, int KillerIndex)
{
	if(gObj(TargetIndex)->Type == 1 && gObj(KillerIndex)->Type == 1)
	{
		if(TargetIndex != KillerIndex)
		{
			char NomeVitima[11];
			char NomeMatador[11];
			char MsgA[64];
			char MsgB[64];

			sprintf_s(NomeVitima, "%s", gObj(TargetIndex)->Name);
			sprintf_s(NomeMatador, "%s", gObj(KillerIndex)->Name);
			sprintf_s(MsgA, "[PVP] Você matou %s!", NomeVitima);
			sprintf_s(MsgB, "[PVP] %s matou você!", NomeMatador);

			MsgPlayer(MsgA, KillerIndex);
			MsgPlayer(MsgB, TargetIndex);

			Mssql_Atualiza(TargetIndex, 7);	// - Vítima
			Mssql_Atualiza(KillerIndex, 6);	// - Matador
		}
	}

	unsigned long Exp = gObj(TargetIndex)->Experience;
	GCDiePlayerSend(lpObj, TargetIndex, skill, KillerIndex);
	gObj(TargetIndex)->Experience = Exp;
}