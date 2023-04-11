#include "StdAfx.h"

void Pegar_gObjCustom_Character(int aIndex, char * Nome, char * Conta, unsigned char Classe)
{
	// - Character
	gObjCustom[aIndex].Bau_Delay			= 0;
	gObjCustom[aIndex].ChatOn				= true;
	gObjCustom[aIndex].Resets				= DbConnection.PegarInt("Resets",	"Character", "WHERE Name = '%s'", Nome);
	gObjCustom[aIndex].Mrs					= DbConnection.PegarInt("Mrs",		"Character", "WHERE Name = '%s'", Nome);
	gObjCustom[aIndex].CtlCode				= DbConnection.PegarInt("Tipo",		"Character", "WHERE Name = '%s'", Nome);
	gObjCustom[aIndex].Limite_Pontos		= GS.Limite_Pontos[(Classe >> 4)];
	gObjCustom[aIndex].ExpDelayCount		= 0;
	gObjCustom[aIndex].Level_Max_Msg		= false;
	gObjCustom[aIndex].SVIni_Count			= 0;

	// - Sistema de Drop
	gObjCustom[aIndex].Intervalo_Sets		= 0;
	gObjCustom[aIndex].Intervalo_Armamentos	= 0;
	gObjCustom[aIndex].Intervalo_Option		= 0;
	gObjCustom[aIndex].Intervalo_Skill		= 0;
	gObjCustom[aIndex].Intervalo_Luck		= 0;
	gObjCustom[aIndex].Intervalo_Exe		= 0;
	gObjCustom[aIndex].Intervalo_Anci		= 0;
	gObjCustom[aIndex].Intervalo_Misc		= 0;
	gObjCustom[aIndex].Intervalo_Zen		= 0;

	gObjCustom[aIndex].Drop_Soul			= false;
	gObjCustom[aIndex].Drop_Life			= false;
	gObjCustom[aIndex].Drop_Bless			= false;
	gObjCustom[aIndex].Drop_Creation		= false;
	gObjCustom[aIndex].Drop_Chaos			= false;
	gObjCustom[aIndex].Drop_Lochs			= false;
	gObjCustom[aIndex].Drop_Crest			= false;

	Mssql_Atualiza(aIndex, 4); // - Baú Fechado
}

void Pegar_gObjCustom_AccInfo(int aIndex)
{
	gObjCustom[aIndex].Vip					= DbConnection.PegarInt("Vip",			"MEMB_INFO", "WHERE memb___id = '%s'", gObj(aIndex)->AccountID);
	gObjCustom[aIndex].Creditos				= DbConnection.PegarInt("Creditos",		"MEMB_INFO", "WHERE memb___id = '%s'", gObj(aIndex)->AccountID);
	gObjCustom[aIndex].Golds				= DbConnection.PegarInt("Golds",		"MEMB_INFO", "WHERE memb___id = '%s'", gObj(aIndex)->AccountID);
	gObjCustom[aIndex].Cashs				= DbConnection.PegarInt("Cashs",		"MEMB_INFO", "WHERE memb___id = '%s'", gObj(aIndex)->AccountID);
	gObjCustom[aIndex].BauID				= DbConnection.PegarInt("BauID",		"Warehouse", "WHERE AccountID = '%s'", gObj(aIndex)->AccountID);

	if(gObjCustom[aIndex].BauID == 0)
	{
		char Query[512];
		sprintf_s(Query,"INSERT INTO Warehouse(BauID, AccountID, AccountID2, Money, DbVersion) VALUES('1', '%s', '%s', '0', '2')", gObj(aIndex)->AccountID, gObj(aIndex)->AccountID);		
		DbConnection.Executar(Query); // ISTO é BOOL
		gObjCustom[aIndex].BauID	= 1;
	}
}

void Mssql_Atualiza(int aIndex, int Func)
{
	char Query[1024];
	switch(Func)
	{
	default: return; break;
	case 1: //Resets
		sprintf_s(Query,"UPDATE Character SET Resets=Resets+1, ResetsD=ResetsD+1, ResetsS=ResetsS+1, ResetsM=ResetsM+1 WHERE Name = '%s'", gObj(aIndex)->Name);
	break;
	//2
	//3
	case 4: //Atualiza para Bau Livre
		sprintf_s(Query,"UPDATE Memb_Info SET Bau_Aberto=0 WHERE memb___id='%s'", gObj(aIndex)->AccountID);
		gObjCustom[aIndex].Bau_Aberto = false;
	break;
	case 5: //Atualiza para Bau Travado
		sprintf_s(Query,"UPDATE Memb_Info SET Bau_Aberto=1 WHERE memb___id='%s'", gObj(aIndex)->AccountID);
		gObjCustom[aIndex].Bau_Aberto = true;
	break;
	case 6: // - Atualiza Tabela de PVP (Matou +1)
		sprintf_s(Query,"UPDATE Character SET matou=matou+1, matoud=matoud+1, matous=matous+1, matoum=matoum+1 WHERE Name='%s'", gObj(aIndex)->Name);
	break;
	case 7: // - Atualiza Tabela de PVP (Morreu +1)
		sprintf_s(Query,"UPDATE Character SET morreu=morreu+1, morreud=morreud+1, morreus=morreus+1, morreum=morreum+1 WHERE Name='%s'", gObj(aIndex)->Name);
	break;
	case 8: // - MR
		sprintf_s(Query,"UPDATE Character SET Resets=0, Mrs=Mrs+1 WHERE Name='%s'", gObj(aIndex)->Name);
	break;
	case 9: // - WZ_CONNECT_MEMB
		//sprintf_s(Query,"EXEC WZ_CONNECT_MEMB '%s','%s','%s'", gObj(aIndex)->AccountID, GS.Nome_Sala, gObj(aIndex)->Ip_addr);
		return;
	break;
	case 10: // - Novo Connect (WZ_CONNECT_MEMB)
		sprintf_s(Query,"UPDATE MEMB_STAT SET UpStat=5, ConnectStat=1, ServerName='%s' WHERE memb___id='%s'", GS.Nome_Sala, gObj(aIndex)->AccountID);
	break;
	case 11: // - Novo Disconnect (WZ_DISCONNECT_MEMB)
		sprintf_s(Query,"UPDATE MEMB_STAT SET UpStat=0, ConnectStat=0 WHERE memb___id='%s'", gObj(aIndex)->AccountID);
	break;
	}

	DbConnection.Executar(Query);
}