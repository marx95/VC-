#include "StdAfx.h"

void Pegar_gObjCustom_Character(int aIndex, char * Nome, char * Conta, unsigned char Classe)
{
	gObjCustom[aIndex].Resets					= DbConnection.PegarInt("Resets",	"Character", "WHERE Name = '%s'", Nome);
	gObjCustom[aIndex].MasterResets				= DbConnection.PegarInt("Mrs",		"Character", "WHERE Name = '%s'", Nome);
	gObjCustom[aIndex].CtlCode					= DbConnection.PegarInt("Tipo",		"Character", "WHERE Name = '%s'", Nome);	
	gObjCustom[aIndex].casado					= DbConnection.PegarInt("Casado_Status",	"Character", "WHERE Name = '%s'", Nome);
	gObjCustom[aIndex].BauAberto				= 0;
	gObjCustom[aIndex].PedidoCasamento			= 0;
	gObjCustom[aIndex].ChatBlock				= 0;
	gObjCustom[aIndex].Bau_Delay				= 0;
	gObjCustom[aIndex].UltimoNpcIndex			= 0;
	gObjCustom[aIndex].Atualizar_Delay			= 0;
	gObjCustom[aIndex].Necessario_Atualizar		= 0;
	gObjCustom[aIndex].Level_Max_Msg			= 0;
	gObjCustom[aIndex].Limite_Pontos			= GS.Limite_Pontos[(Classe >> 4)];

	if(gObj(aIndex)->DbClass == 32 || gObj(aIndex)->DbClass == 33 || gObj(aIndex)->DbClass == 34)
	{
		int iAddSkillPosition = gObjMagicAdd(gObj(aIndex), 0x4D, 0);
		GCMagicListOneSend(aIndex, iAddSkillPosition, 0x4D, 0xDC, 0, 0);
	}
	
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

	Mssql_Atualiza(aIndex, 4); // - Baú Fechado
}

void Pegar_gObjCustom_AccInfo(int aIndex)
{
	gObjCustom[aIndex].Vip					= DbConnection.PegarInt("Vip",		"MEMB_INFO", "WHERE memb___id = '%s'", gObj(aIndex)->AccountID);
	gObjCustom[aIndex].Creditos				= DbConnection.PegarInt("Creditos",	"MEMB_INFO", "WHERE memb___id = '%s'", gObj(aIndex)->AccountID);
	gObjCustom[aIndex].Golds				= DbConnection.PegarInt("Golds",		"MEMB_INFO", "WHERE memb___id = '%s'", gObj(aIndex)->AccountID);
	gObjCustom[aIndex].Cashs				= DbConnection.PegarInt("Cashs",		"MEMB_INFO", "WHERE memb___id = '%s'", gObj(aIndex)->AccountID);
	gObjCustom[aIndex].BauID				= DbConnection.PegarInt("BauID",		"Warehouse", "WHERE AccountID = '%s'", gObj(aIndex)->AccountID);

	if(gObjCustom[aIndex].BauID == 0)
	{
		char Query[512];
		sprintf_s(Query,"INSERT INTO Warehouse(BauID, AccountID, AccountID2, Money, DbVersion) VALUES('1', '%s', '%s', '0', '2')", gObj(aIndex)->AccountID, gObj(aIndex)->AccountID);		
		DbConnection.Executar(Query);
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
		gObjCustom[aIndex].BauAberto = false;
	break;
	case 5: //Atualiza para Bau Travado
		sprintf_s(Query,"UPDATE Memb_Info SET Bau_Aberto=1 WHERE memb___id='%s'", gObj(aIndex)->AccountID);
		gObjCustom[aIndex].BauAberto = true;
	break;
	//6
	//7
	//8
	//9
	case 10: // - Atualiza Tabela de PVP (Matou +1)
		sprintf_s(Query,"UPDATE Character SET matou=matou+1, matoud=matoud+1, matous=matous+1, matoum=matoum+1 WHERE Name='%s'", gObj(aIndex)->Name);
	break;
	case 11: // - Atualiza Tabela de PVP (Morreu +1)
		sprintf_s(Query,"UPDATE Character SET morreu=morreu+1, morreud=morreud+1, morreus=morreus+1, morreum=morreum+1 WHERE Name='%s'", gObj(aIndex)->Name);
	break;
	case 12: // - MR
		sprintf_s(Query,"UPDATE Character SET Resets=0, Mrs=Mrs+1 WHERE Name='%s'", gObj(aIndex)->Name);
	break;
	}

	DbConnection.Executar(Query);
}