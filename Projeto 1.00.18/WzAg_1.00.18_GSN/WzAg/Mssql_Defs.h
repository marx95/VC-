#pragma once

#include "stdafx.h"
#pragma pack(push, 4)

class CDbConnection
{
private:
	SAConnection *MuDb;
	SACommand *MuDbCmd;

	CRITICAL_SECTION	m_CriticalSection;

public:
	CDbConnection(void);
	~CDbConnection(void);

	bool	Connect();
	long	PegarInt(char * Coluna, char * Tabela, char * Optional, ...);
	bool	Executar(char * Query);

	void	Disconnect();

	void Lock()
	{
		EnterCriticalSection(&this->m_CriticalSection);
	}

	void Unlock()
	{
		LeaveCriticalSection(&this->m_CriticalSection);
	}
};

#pragma pack(pop)

extern CDbConnection DbConnection;