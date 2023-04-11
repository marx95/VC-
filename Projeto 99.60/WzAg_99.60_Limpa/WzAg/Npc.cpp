#include "StdAfx.h"

void ShadowPhantomBuff(int aIndex)
{
	NpcShadowPhantom(gObj(aIndex), gObj(aIndex));
}

bool NpcClick(int aIndex, int NpcIndex)
{
	if(gObj(NpcIndex)->Class == 240)
	{
		char TmpBauMsg[64];
		sprintf_s(TmpBauMsg, "Baú %d aberto!", gObjCustom[aIndex].BauID);
		NpcChat(TmpBauMsg, NpcIndex, aIndex);
		Mssql_Atualiza(aIndex, 5); //Isto interfere no comando de MUDAR BAU -- Cuidado!!
		return false;
	}

	if(gObj(NpcIndex)->Class == 257)
	{
		if(gObj(aIndex)->Level > GS.ShadowP_LevelMax)
		{
			GCServerCmd(aIndex, 0x0D, 0, 0);
			return true;
		}

		ShadowPhantomBuff(aIndex);
		return true;
	}

	if(gObj(NpcIndex)->Class == 247)
	{
		if(GS.NPC_Reset_Ativado == 0)
		{
			NpcChat("Não posso te ajudar agora!", NpcIndex, aIndex);
			return true;
		}
		
		if(VerificarGM(aIndex))
		{
			NpcChat("Staff não pode resetar!", NpcIndex, aIndex);
			return true;
		}

		if(GS.NPC_Reset_Vip == 1)
		{
			NpcChat("Seja VIP para Resetar via NPC!", NpcIndex, aIndex);
			return true;
		}
		
		char TmpMsg[64];
		if(gObj(aIndex)->Level < GS.Reset_Level[gObjCustom[aIndex].Vip])
		{
			sprintf_s(TmpMsg, "Necessário level %d.", GS.Reset_Level[gObjCustom[aIndex].Vip]);
			NpcChat(TmpMsg, NpcIndex, aIndex);
			return true;
		}

		if(gObj(aIndex)->Money < GS.NPC_Reset_Zen)
		{
			sprintf_s(TmpMsg, "Necessário %d zen para Limpar o PK", GS.NPC_Reset_Zen);
			NpcChat(TmpMsg, NpcIndex, aIndex);
			return true;
		}

		Tirar_Zen(aIndex, GS.NPC_Reset_Zen);
		f_Reset(aIndex);

		char MsgRstInfo[128];
		if(gObjCustom[aIndex].Resets == 1) sprintf_s(MsgRstInfo, "Agora Você tem %d Reset!", gObjCustom[aIndex].Resets);
		if(gObjCustom[aIndex].Resets > 1) sprintf_s(MsgRstInfo, "Agora Você tem %d Reset's!", gObjCustom[aIndex].Resets);
		NpcChat(MsgRstInfo, NpcIndex, aIndex);
		return true;
	}

	if(gObj(NpcIndex)->Class == 249)
	{
		if(GS.NPC_LPK_Ativado == 0)
		{
			NpcChat("Não posso te ajudar agora!", NpcIndex, aIndex);
			return true;
		}

		if(GS.NPC_LPK_Vip == 1)
		{
			NpcChat("Seja VIP assim limparei o PK!", NpcIndex, aIndex);
			return true;
		}

		if(gObj(aIndex)->Money < GS.NPC_LPK_Zen)
		{
			char TmpMsg[64];
			sprintf_s(TmpMsg, "Necessário %d zen para Limpar o PK", GS.NPC_LPK_Zen);
			NpcChat(TmpMsg, NpcIndex, aIndex);
			return true;
		}

		Tirar_Zen(aIndex, GS.NPC_LPK_Zen);
		f_LimparPK(aIndex);
		NpcChat("Você foi perdoado!", NpcIndex, aIndex);
		return true;
	}

	return false;
}