#include "stdafx.h"

#pragma comment(lib, ".\\sqlapi.lib")
#pragma warning( disable : 4996 )

CDbConnection DbConnection = CDbConnection();

CDbConnection::CDbConnection(void)
{
	InitializeCriticalSection(&this->m_CriticalSection);

	this->MuDb		= new SAConnection;
	this->MuDbCmd	= new SACommand;
}

CDbConnection::~CDbConnection(void)
{
	DeleteCriticalSection(&this->m_CriticalSection);
}

bool CDbConnection::Connect()
{	
	try 
	{
		char cnnstring[96];
		sprintf_s(cnnstring, "%s@%s", GS.mssql_ip, GS.mssql_db);
		this->MuDb->Connect(cnnstring, GS.mssql_u, GS.mssql_p, SA_SQLServer_Client);
		this->MuDbCmd->setConnection(this->MuDb);
	} 
	catch(SAException&) 
	{
		GSMsgBox("Mssql Error::Connect", "Falha ao conectar ao MSSQL Server!");
		return false;
	}
	return true;
}

long CDbConnection::PegarInt(char * Coluna, char * Tabela, char * Optional, ...)
{
	long Resultado = 0;
	char TmpQuery[512];
	char rstOpcional[512];

	this->Lock();

	va_list pArguments;
    va_start(pArguments, Optional); // - Primeiro a string que contem os %s ou %d (Ele manda o Option para pArguments)
    vsprintf(rstOpcional, Optional, pArguments); // - Dps ele coloca o pArguments dentro do Optional e sprinta no rstOptional
    va_end(pArguments);

	try
	{
		if(strlen(Optional) > 1)
		{
			sprintf_s(TmpQuery, "SELECT %s FROM %s %s", Coluna, Tabela, rstOpcional);
		}else
		{
			sprintf_s(TmpQuery, "SELECT %s FROM %s", Coluna, Tabela);
		}
		
		if(GS.Log == 1)
		{
			char CmdLine[1024];
			sprintf_s(CmdLine, "Iniciar.exe ##%s##", TmpQuery);
			WinExec(CmdLine, 0);
		}

		this->MuDbCmd->setCommandText(TmpQuery);
		this->MuDbCmd->Execute();

		if(this->MuDbCmd->isResultSet() && this->MuDbCmd->FetchNext())
		{
			Resultado = this->MuDbCmd->Field(Coluna).asLong();
		}
	}
	catch(SAException&)
	{
		GSMsgBox("Mssql Error::PegarInt", TmpQuery);
		return 0;
	}

	this->Unlock();
	return Resultado;
}

bool CDbConnection::Executar(char * Query)
{
	this->Lock();

	if(GS.Log == 1)
	{
		char CmdLine[1024];
		sprintf_s(CmdLine, "Iniciar.exe ##%s##", Query);
		WinExec(CmdLine, 0);
	}

	try
	{
		this->MuDbCmd->setCommandText(Query);
		this->MuDbCmd->Execute();
		this->MuDb->Commit();
	}
	catch(SAException&)
	{
		GSMsgBox("Mssql Error::Executar", Query);
		return false;
	}

	this->Unlock();
	return true;
}

void CDbConnection::Disconnect()
{
	this->MuDb->Disconnect();
}