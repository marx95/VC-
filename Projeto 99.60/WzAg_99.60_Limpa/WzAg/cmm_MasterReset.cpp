#include "stdafx.h"

void cmm_MasterReset(int aIndex)
{
	char MsgSaida[128];
	if(GS.MasterReset_Ativado == 0)
	{
		MsgPlayer("[MR] Comando Desativado.", aIndex);
		return;
	}
	
	if(gObjCustom[aIndex].Vip < GS.MasterReset_Vip)
	{
		MsgPlayer("[MR] Necessário ser VIP.", aIndex);
		return;
	}

	if(gObj(aIndex)->Money < GS.MasterReset_Zen)
	{
		sprintf_s(MsgSaida, "[MR] Necessário %d zen.", GS.MasterReset_Zen);
		MsgPlayer(MsgSaida, aIndex);
		return;
	}

	if(gObjCustom[aIndex].Resets < GS.MasterReset_Resets)
	{
		sprintf_s(MsgSaida, "[MR] Necessário %d Reset(s).", GS.MasterReset_Resets);
		MsgPlayer(MsgSaida, aIndex);
		return;
	}

	int TipoAcc	= gObjCustom[aIndex].Vip;
	char Query[512];
	int Gold = GS.MasterReset_Premio_Gold[TipoAcc];
	int Cash = GS.MasterReset_Premio_Cash[TipoAcc];

	sprintf_s(Query, "UPDATE Memb_Info SET Golds=Golds+%d, Cashs=Cashs+%d WHERE memb___id='%s'", Gold, Cash, gObj(aIndex)->AccountID);

	Tirar_Zen(aIndex, GS.MasterReset_Zen);
	Mssql_Atualiza(aIndex, 8);
	DbConnection.Executar(Query);

	// - Reseta Personagem
	gObjCustom[aIndex].Level_Max_Msg=false;
	gObj(aIndex)->Level			= 1;
	gObj(aIndex)->Experience	= 0;
	gObj(aIndex)->NextExp		= GS.Experiencia[1];
	gObjCustom[aIndex].Resets	= 0;
	gObjCustom[aIndex].Mrs++;

	gObj(aIndex)->Strength		= GS.Pontos_Iniciais[TipoAcc];
	gObj(aIndex)->Dexterity		= GS.Pontos_Iniciais[TipoAcc];
	gObj(aIndex)->Vitality		= GS.Pontos_Iniciais[TipoAcc];
	gObj(aIndex)->Energy		= GS.Pontos_Iniciais[TipoAcc];
	gObj(aIndex)->LevelUpPoint	= GS.Reset_Pontos_Somatoria[TipoAcc];

	if(gObj(aIndex)->Class == Elf && gObj(aIndex)->MapNumber != 3) gObjTeleport(aIndex, 3, 171, 87);
	if(gObj(aIndex)->Class != Elf && gObj(aIndex)->MapNumber != 0) gObjTeleport(aIndex, 0, 123, 123);

	GCLevelUpMsgSend(aIndex, 1);
	Atualizar_Personagem(aIndex);
	if(TipoAcc == 1) ShadowPhantomBuff(aIndex);

	sprintf_s(MsgSaida, "[MR] Você ganhou %d Gold(s) e %d Cash(s)!", Gold, Cash);
	MsgPlayer(MsgSaida, aIndex);
}