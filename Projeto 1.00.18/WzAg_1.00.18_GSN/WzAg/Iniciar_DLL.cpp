#include "StdAfx.h"

void Iniciar_DLL()
{	
	_mkdir("Log");
	_mkdir("KANTURU_TEST_LOG");
	_mkdir("KUNDUN_EVENT_GM_LOG");
	_mkdir("KUNDUN_EVENT_LOG");
	_mkdir("SERVER_CONN_STATE_LOG");

	Fixes();
	FixEventos();
	MudarLoadMap();
	SetGSConfig();						// - Define valores dos offsets que nao podem ser recarregados

	CarregarConfigs();					// - Define valores dos offsets que podem ser recarregados
	CarregarDefinicoesConfigs();		// - Define as variaveis globais
	CarregarDropCustom();
	CarregarMove();

	GS.Experiencia[0]=0;
	int LevelOver_N=1;

	for(int n=1; n<401; n++)
	{
		GS.Experiencia[n] = (((n+9)*n)*n)*10;

		if(n > 255)
		{
			GS.Experiencia[n] += ((((LevelOver_N+9)*LevelOver_N)*LevelOver_N)*1000);
			LevelOver_N++;
		}
	}

	Hook((DWORD)(ProtocolCore_Hook),					0x00403314);
	Hook((DWORD)(DataSend_Hook),						0x0040533F);
	Hook((DWORD)(gObjCalCharacter_Hook),				0x00402B08);
	Hook((DWORD)(gEventMonsterItemDrop_Hook),			0x00404E4E);
	Hook((DWORD)(gObjAttack_Hook),						0x00405E7A);
	Hook((DWORD)(GCDiePlayerSend_Hook),					0x004010C8);
	Hook((DWORD)(JGGetCharacterInfo_Hook),				0x00402257);
	Hook((DWORD)(gObjLevelUp_Hook),						0x00405F51);

	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(NpcMaluco_Timer),NULL,0,0);
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Noticias_Timer),NULL,0,0);
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(MudarBau_Timer),NULL,0,0);
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Post_Timer),NULL,0,0);

	DbConnection.Connect();
	DbConnection.Executar("UPDATE MEMB_STAT SET ConnectStat='0'");
}