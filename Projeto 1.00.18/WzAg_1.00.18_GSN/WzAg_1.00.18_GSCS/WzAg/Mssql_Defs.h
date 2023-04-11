#ifndef SQL_H
#define SQL_H

#include "SQLAPI.h"
#include <windows.h>
#include <iostream>

class SQL
{
public:
	SQL(void);
	virtual ~SQL(void);
	void Connect(char* DataBase,char* Acc,char* Password);
	int GetFieldInt(char* Table, char* Field, const char* Optional, ...);
	void Exec(const char* szQuery, ...);
	int GetBufferQueryInt(char* Query,char* BuffName);
	unsigned char* GetBufferQueryBinary(char* Query,char* BuffName);
};

extern SQL * mySql;

#endif