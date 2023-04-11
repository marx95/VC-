#include "stdafx.h"

void cmm_Reset(int aIndex)
{
	char MsgSaida[128];
	if(GS.Reset_Ativado == 0)
	{
		MsgPlayer("[Reset] Comando Desativado.", aIndex);
		return;
	}
	
	if(VerificarGM(aIndex))
	{
		MsgPlayer("[Reset] Staff não pode resetar!", aIndex);
		return;
	}

	if(gObjCustom[aIndex].Vip < GS.Reset_Vip)
	{
		MsgPlayer("[Reset] Necessário ser VIP.", aIndex);
		return;
	}

	if(gObj(aIndex)->Level < GS.Reset_Level[gObjCustom[aIndex].Vip])
	{
		sprintf_s(MsgSaida, "[Reset] Necessário level %d.", GS.Reset_Level[gObjCustom[aIndex].Vip]);
		MsgPlayer(MsgSaida, aIndex);
		return;
	}

	if(gObj(aIndex)->Money < GS.Reset_Zen)
	{
		sprintf_s(MsgSaida, "[Reset] Necessário %d zen.", GS.Reset_Zen);
		MsgPlayer(MsgSaida, aIndex);
		return;
	}

	if(gObj(aIndex)->MapNumber != 0 && gObj(aIndex)->Class != Elf) gObjTeleport(aIndex, 0, 142, 134);

	Tirar_Zen(aIndex, GS.Reset_Zen);
	f_Reset(aIndex);

	char MsgRstInfo[128];
	if(gObjCustom[aIndex].Resets == 1) sprintf_s(MsgRstInfo, "Agora Você tem %d Reset!", gObjCustom[aIndex].Resets);
	if(gObjCustom[aIndex].Resets > 1) sprintf_s(MsgRstInfo, "Agora Você tem %d Reset's!", gObjCustom[aIndex].Resets);
	MsgPlayer(MsgRstInfo, aIndex);
}