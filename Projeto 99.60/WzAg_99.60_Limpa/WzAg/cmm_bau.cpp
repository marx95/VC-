#include "stdafx.h"

void cmm_Bau(int aIndex, char * Msg)
{
	char MsgSaida[128];

	if(GS.Bau_Ativado == 0)
	{
		MsgPlayer("[M. Baú] Comando Desativado.", aIndex);
		return;
	}
	
	if(gObjCustom[aIndex].Vip < GS.Bau_Vip)
	{
		MsgPlayer("[M. Baú] Necessário ser VIP.", aIndex);
		return;
	}

	if(gObj(aIndex)->Money < GS.Bau_Zen)
	{
		sprintf_s(MsgSaida, "[M. Baú] Necessário %d zen.", GS.Bau_Zen);
		MsgPlayer(MsgSaida, aIndex);
		return;
	}

	if(gObjCustom[aIndex].Bau_Aberto)
	{
		MsgPlayer("[M. Baú] Feche e saia de perto do baú!", aIndex);
		return;
	}

	if(gObjCustom[aIndex].Bau_Delay > 0)
	{
		sprintf_s(MsgSaida, "[M. Baú] Espere %d segundo(s).", gObjCustom[aIndex].Bau_Delay);
		MsgPlayer(MsgSaida, aIndex);
		return;
	}

	int Total_Bau;
	if(gObjCustom[aIndex].Vip == 0) Total_Bau = GS.Bau_Total_Free;
	if(gObjCustom[aIndex].Vip == 1) Total_Bau = GS.Bau_Total_Vip;

	if(strlen(Msg) == 0)
	{
		sprintf_s(MsgSaida, "[M. Baú] Tente de 1 até %d!", Total_Bau);
		MsgPlayer(MsgSaida, aIndex);
		return;
	}

	int BauID = atoi(Msg);

	if(BauID <= 0 || BauID > Total_Bau)
	{
		sprintf_s(MsgSaida, "[M. Baú] Tente de 1 até %d!", Total_Bau);
		MsgPlayer(MsgSaida, aIndex);
		return;
	}

	if(BauID == gObjCustom[aIndex].BauID)
	{
		sprintf_s(MsgSaida, "[M. Baú] Baú %d já está aberto!", BauID);
		MsgPlayer(MsgSaida, aIndex);
		return;
	}

	char Buffer[256];
	int Rst = DbConnection.PegarInt("BauID", "Warehouse", "WHERE BauID = '%d' AND AccountID2='%s'", BauID, gObj(aIndex)->AccountID);

	if(Rst == 0)
	{
		sprintf_s(Buffer, "INSERT INTO warehouse(AccountID, AccountID2, BauID, DbVersion, Money, pw) VALUES('', '%s', %d, 2, 0, 0)", gObj(aIndex)->AccountID, BauID);
		DbConnection.Executar(Buffer);
	}

	sprintf_s(Buffer,"UPDATE warehouse SET AccountID='', AccountID2='%s' WHERE AccountID='%s'", gObj(aIndex)->AccountID, gObj(aIndex)->AccountID);
	DbConnection.Executar(Buffer);

	sprintf_s(Buffer,"UPDATE warehouse SET AccountID='%s' WHERE AccountID2='%s' AND BauID='%d'", gObj(aIndex)->AccountID, gObj(aIndex)->AccountID, BauID);
	DbConnection.Executar(Buffer);

	gObjCustom[aIndex].Bau_Delay	= 6;
	gObjCustom[aIndex].BauID		= BauID;
	Tirar_Zen(aIndex, GS.Bau_Zen);
	MsgPlayer("[M. Baú] Trocado com sucesso!",aIndex);
}