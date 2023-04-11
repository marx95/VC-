#include "stdafx.h"
#include "Mssql_Defs.h"
#include "Mssql_Handler.h"

SACommand * cmd = new SACommand();
SAConnection * con = new SAConnection();

char ErrorConnectMsg[64] = "Não foi Possivel Realizar a conexão com o MSSQL";

SQL* mySql = new SQL;

SQL::SQL(void)
{
}
void SQL::Connect(char* DataBase,char* Acc,char* Password)
{
	try
	{
		con->Connect(DataBase,Acc,Password,SA_SQLServer_Client);
		cmd->setConnection(con);
	}
	catch(SAException &x)
	{
		MessageBoxA(NULL, x.ErrText(),ErrorConnectMsg, MB_OK);
		ExitProcess(0);
	}
}

int SQL::GetFieldInt(char* Table, char* Field, const char* Optional, ...)
{
	char Buffer[1024];
	va_list pArguments;
    va_start(pArguments, Optional);
    vsprintf(Buffer, Optional, pArguments);
    va_end(pArguments);
    if (Optional)
	    this->Exec("SELECT %s FROM %s %s;", Field, Table, Buffer);
    else
		this->Exec("SELECT %s FROM %s;", Field, Table);

    if(cmd->isResultSet()) 
    {
	    cmd->FetchNext();
	    int Result = cmd->Field(Field).asLong();
	    return Result;
    }
	return 0;
}

void SQL::Exec(const char* szQuery, ...)
{
	    char szBuffer[1024];
	    va_list pArguments;
	    va_start(pArguments, szQuery);
	    vsprintf(szBuffer, szQuery, pArguments);
	    va_end(pArguments);
	    cmd->setCommandText(szBuffer);
	    cmd->Execute();
		
}
int SQL::GetBufferQueryInt(char* Query,char* BuffName)
{
	int x = -1;
	cmd->setCommandText(Query);
	cmd->Execute();
	if(cmd->isResultSet())
	{
		cmd->FetchNext();
		 x = cmd->Field(BuffName).asLong();
	}
		return x;
}

unsigned char* SQL::GetBufferQueryBinary(char* Query,char* BuffName)
{
	std::string x;
	unsigned char* Result;
	cmd->setCommandText(Query);
	cmd->Execute();
	if(cmd->isResultSet())
	{
		cmd->FetchNext();
		x = cmd->Field(BuffName).asString();
	}
	Result = (unsigned char*)x.c_str();
	return Result;
}
SQL::~SQL(void)
{
}