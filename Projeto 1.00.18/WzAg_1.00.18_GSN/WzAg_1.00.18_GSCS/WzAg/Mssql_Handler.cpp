#include "StdAfx.h"
MSSQL_FUNC func_mssql;

void MSSQL_FUNC::Carrega_e_Conecta()
{
	char Buffer[512];
	GetPrivateProfileStringA("MSSQL","IP","127.0.0.1", func_mssql.SQL_Server,50, "..\\MarxD\\Mssql.ini");
	GetPrivateProfileStringA("MSSQL","Login","sa", func_mssql.SQL_User,50, "..\\MarxD\\Mssql.ini");
	GetPrivateProfileStringA("MSSQL","Senha","", func_mssql.SQL_Pass,50, "..\\MarxD\\Mssql.ini");
	GetPrivateProfileStringA("MSSQL","DB","MuOnline", func_mssql.SQL_DBName,50, "..\\MarxD\\Mssql.ini");
	Sleep(25);

	sprintf_s(Buffer,"%s@%s",this->SQL_Server,this->SQL_DBName);
	mySql->Connect(Buffer,this->SQL_User,this->SQL_Pass);

	char NomeDaSala[50];
	char QueryStat[128];
	GetPrivateProfileStringA("GameServerInfo","ServerName","MarxD_GS_1.00.18", NomeDaSala, 50, "..\\MarxD\\ServerInfo.dat");
	sprintf_s(QueryStat, "UPDATE MuOnline.dbo.MEMB_STAT SET ConnectStat = '0' WHERE ServerName='%s'", NomeDaSala);
	this->Rodar_Query(QueryStat);
}

void Verificacao_Mssql(int aIndex)
{
	char Query[256];
	if(gObjCustom[aIndex].casado == 0)
	{
		sprintf_s(Query,"INSERT INTO MuJB.dbo.Casamentos(status, nome, casado_com, Tipo) VALUES('1', '%s', '', '0')", gObj(aIndex)->Name);		
		func_mssql.Rodar_Query(Query);
		gObjCustom[aIndex].casado	= 1;
	}

	if(gObjCustom[aIndex].BauID == 0)
	{
		sprintf_s(Query,"INSERT INTO MuOnline.dbo.Warehouse(BauID, AccountID, Money, DbVersion) VALUES('1', '%s', '0', '3')", gObj(aIndex)->Name);		
		func_mssql.Rodar_Query(Query);

		gObjCustom[aIndex].BauID	= 1;
	}
	
	int Total = mySql->GetFieldInt("MuJB.dbo.Info_Bau","id","WHERE AccountID = '%s'", gObj(aIndex)->AccountID);
	if(Total == 0)
	{
		sprintf_s(Query,"INSERT INTO MuJB.dbo.Info_Bau(AccountID, Aberto) VALUES('%s', '0')", gObj(aIndex)->AccountID);		
		func_mssql.Rodar_Query(Query);
	}

	if(gObjCustom[aIndex].PVP_ID == 0)
	{
		sprintf_s(Query,"INSERT INTO MuJB.dbo.PVP(nome, matou, morreu) VALUES('%s', '0', '0')", gObj(aIndex)->Name);		
		func_mssql.Rodar_Query(Query);

		gObjCustom[aIndex].PVP_ID	= mySql->GetFieldInt("MuJB.dbo.PVP","id","WHERE nome = '%s'", gObj(aIndex)->Name);
	}
}

void MSSQL_FUNC::Pegar_gObjCustom(int aIndex)
{
	gObjCustom[aIndex].Resets				= mySql->GetFieldInt("MuOnline.dbo.Character", "Resets",	"Where Name = '%s'",		gObj(aIndex)->Name);
	gObjCustom[aIndex].MasterResets			= mySql->GetFieldInt("MuOnline.dbo.Character", "Mrs",		"Where Name = '%s'",		gObj(aIndex)->Name);
	gObjCustom[aIndex].CtlCode				= mySql->GetFieldInt("MuOnline.dbo.Character", "Tipo",		"WHERE Name = '%s'",		gObj(aIndex)->Name);

	gObjCustom[aIndex].Vip					= mySql->GetFieldInt("MuOnline.dbo.MEMB_INFO", "vip",		"WHERE memb___id = '%s'",	gObj(aIndex)->AccountID);
	gObjCustom[aIndex].Creditos				= mySql->GetFieldInt("MuOnline.dbo.MEMB_INFO", "Creditos",	"WHERE memb___id = '%s'",	gObj(aIndex)->AccountID);
	
	gObjCustom[aIndex].casado				= mySql->GetFieldInt("MuJB.dbo.Casamentos","status",		"WHERE nome = '%s'",		gObj(aIndex)->Name);
	gObjCustom[aIndex].ListaNegra			= mySql->GetFieldInt("MuJB.dbo.Lista_Negra","id",			"WHERE ip = '%s'",			gObj(aIndex)->Ip_addr);
	gObjCustom[aIndex].BauID				= mySql->GetFieldInt("MuOnline.dbo.Warehouse","BauID",		"WHERE AccountID = '%s'",	gObj(aIndex)->AccountID);
	gObjCustom[aIndex].PVP_ID				= mySql->GetFieldInt("MuJB.dbo.PVP","id",					"WHERE nome = '%s'",		gObj(aIndex)->Name);

	Verificacao_Mssql(aIndex);

	gObjCustom[aIndex].BauAberto			= 0;
	gObjCustom[aIndex].PedidoCasamento		= 0;
	gObjCustom[aIndex].PostBlock			= 0;
	gObjCustom[aIndex].Bau_Delay			= 0;

	gObjCustom[aIndex].Acumulado_Intervalo	= 1;
	gObjCustom[aIndex].Acumulado			= 0;

	switch(gObj(aIndex)->DbClass)
	{
		case 0:  gObjCustom[aIndex].Limite_Pontos = Limite_SM; break;
		case 1:  gObjCustom[aIndex].Limite_Pontos = Limite_SM; break;
		case 2:  gObjCustom[aIndex].Limite_Pontos = Limite_SM; break;

		case 16: gObjCustom[aIndex].Limite_Pontos = Limite_BK; break;
		case 17: gObjCustom[aIndex].Limite_Pontos = Limite_BK; break;
		case 18: gObjCustom[aIndex].Limite_Pontos = Limite_BK; break;

		case 32: gObjCustom[aIndex].Limite_Pontos = Limite_ME; break;
		case 33: gObjCustom[aIndex].Limite_Pontos = Limite_ME; break;
		case 34: gObjCustom[aIndex].Limite_Pontos = Limite_ME; break;

		case 48: gObjCustom[aIndex].Limite_Pontos = Limite_MG; break;
		case 49: gObjCustom[aIndex].Limite_Pontos = Limite_MG; break;

		case 64: gObjCustom[aIndex].Limite_Pontos = Limite_DL; break;
		case 65: gObjCustom[aIndex].Limite_Pontos = Limite_DL; break;
	}

	this->Atualiza(aIndex, 4); // - Bau para Livre(Bau Fechado)
}

void MSSQL_FUNC::Rodar_Query(char Query[512]){
	mySql->Exec(Query);
}

void MSSQL_FUNC::Atualiza(DWORD aIndex, unsigned int Number)
{
	char Buffer[512];
	switch(Number)
	{
	default: return; break;
	case 1: break;
	case 2: break;
	case 3: break;
	case 4: //Atualiza para Bau Livre
		sprintf_s(Buffer,"UPDATE MuJB.dbo.Info_Bau SET Aberto=0 where AccountID='%s'", gObj(aIndex)->AccountID);
		gObjCustom[aIndex].BauAberto = 0;
		break;
	case 5: //Atualiza para Bau Travado
		sprintf_s(Buffer,"UPDATE MuJB.dbo.Info_Bau SET Aberto=1 where AccountID='%s'", gObj(aIndex)->AccountID);
		gObjCustom[aIndex].BauAberto = 1;
		break;
	}

	mySql->Exec(Buffer);
}