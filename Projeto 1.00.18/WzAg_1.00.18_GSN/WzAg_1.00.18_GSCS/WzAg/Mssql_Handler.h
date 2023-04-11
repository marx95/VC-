#ifndef SQLHANDLER_H
#define SQLHANDLER_H

class MSSQL_FUNC
{
public:
	void Carrega_e_Conecta();
	void Pegar_gObjCustom(int aIndex);
	void Atualiza(DWORD aIndex,unsigned int Number);
	void Rodar_Query(char Query[512]);

	char SQL_Server[256];
	char SQL_DBName[256];
	char SQL_User[256];
	char SQL_Pass[255];

};

extern MSSQL_FUNC func_mssql;
#endif