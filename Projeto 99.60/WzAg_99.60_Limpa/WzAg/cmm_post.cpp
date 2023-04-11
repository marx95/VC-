#include "stdafx.h"

void cmm_Post(int aIndex, char * Msg)
{
	char MsgSaida[128];

	if(GS.Post_Ativado == 0)
	{
		MsgPlayer("[Post] Comando Desativado.", aIndex);
		return;
	}
	
	if(gObjCustom[aIndex].Vip < GS.Post_Vip)
	{
		MsgPlayer("[Post] Necess�rio ser VIP.", aIndex);
		return;
	}

	if(!VerificarGM(aIndex))
	{
		if(gObjCustom[aIndex].Resets < GS.Post_ResetsMin)
		{
			sprintf_s(MsgSaida, "[Post] Necess�rio %d Reset(s).", GS.Post_ResetsMin);
			MsgPlayer(MsgSaida, aIndex);
			return;
		}
	}

	if(gObj(aIndex)->Money < GS.Post_Zen)
	{
		sprintf_s(MsgSaida, "[Post] Necess�rio %d zen.", GS.Post_Zen);
		MsgPlayer(MsgSaida, aIndex);
		return;
	}

	Tirar_Zen(aIndex, GS.Post_Zen);
	sprintf_s(MsgSaida, "%s [Post]: %s", gObj(aIndex)->Name, Msg);
	MsgServer(MsgSaida, aIndex, 0);
}