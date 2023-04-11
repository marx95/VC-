#include "StdAfx.h"

void Iniciar_DLL()
{	
	_mkdir("Log");
	_mkdir("CS_PCROOM_USER_LOG");
	_mkdir("KUNDUN_EVENT_GM_LOG");
	_mkdir("KUNDUN_EVENT_LOG");
	_mkdir("KANTURU_TEST_LOG");
	_mkdir("SERVER_CONN_STATE_LOG");

	func_mssql.Carrega_e_Conecta();

	ChangeLoadMap();
	SetGSConfig();						// - Define valores dos offsets que nao podem ser recarregados
	CarregarConfigs();					// - Define valores dos offsets que podem ser recarregados
	CarregarDefinicoesConfigs();		// - Define as variaveis globais
	Fixes();

	HookThis((DWORD)(ProtocolCore_Hook), 0x004036C0);
	HookThis((DWORD)(DataSend_Hook), 0x00405704);
	HookThis((DWORD)(ObjAttack), 0x00406410);
	HookThis((DWORD)(CalCharacterHook), 0x00402FEA);
}