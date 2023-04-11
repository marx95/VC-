#include "stdafx.h"

void cmm_LimparPK(int aIndex)
{
	char MsgSaida[128];
	if(GS.LPK_Ativado == 0)
	{
		MsgPlayer("[Limpar PK] Comando Desativado.", aIndex);
		return;
	}
	
	if(gObjCustom[aIndex].Vip < GS.LPK_Vip)
	{
		MsgPlayer("[Limpar PK] Necessário ser VIP.", aIndex);
		return;
	}

	if(gObj(aIndex)->Money < GS.LPK_Zen)
	{
		sprintf_s(MsgSaida, "[Limpar PK] Necessário %d zen.", GS.LPK_Zen);
		MsgPlayer(MsgSaida, aIndex);
		return;
	}

	Tirar_Zen(aIndex, GS.LPK_Zen);
	f_LimparPK(aIndex);
	MsgPlayer("[Limpar PK] Você foi perdoado!", aIndex);
}