#include "StdAfx.h"
#include <dos.h>

void Carrega_NpcMaluco()
{
	GS.Npc_Maluco_Anuncios_Previo	= GetPrivateProfileIntA("Npc_Maluco", "Previa", 5, "..\\MarxD\\Npc_Maluco.ini");	// 10Minutos antes ele começa a anunciar
	if(GS.Npc_Maluco_Anuncios_Previo == 0) GS.Npc_Maluco_Anuncios_Previo = 5;

	GS.Npc_Maluco_Estado			= 0;
	GS.Npc_Maluco_Ativado			= GetPrivateProfileIntA("Npc_Maluco", "Ativado", 0, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Duracao			= GetPrivateProfileIntA("Npc_Maluco", "Duracao", 5, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Setar_Evento		= GetPrivateProfileIntA("Npc_Maluco", "Setar_comando_Evento", 1, "..\\MarxD\\Npc_Maluco.ini");

	GS.Npc_Maluco_Segunda			= GetPrivateProfileIntA("Npc_Maluco", "Segunda", 0, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Terca				= GetPrivateProfileIntA("Npc_Maluco", "Terca", 0, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Quarta			= GetPrivateProfileIntA("Npc_Maluco", "Quarta", 0, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Quinta			= GetPrivateProfileIntA("Npc_Maluco", "Quinta", 0, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Sexta				= GetPrivateProfileIntA("Npc_Maluco", "Sexta", 0, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Sabado			= GetPrivateProfileIntA("Npc_Maluco", "Sabado", 0, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Domingo			= GetPrivateProfileIntA("Npc_Maluco", "Domingo", 0, "..\\MarxD\\Npc_Maluco.ini");

	GS.Npc_Maluco_Hora_Segunda		= GetPrivateProfileIntA("Npc_Maluco", "Segunda_Hora", 15, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Hora_Terca		= GetPrivateProfileIntA("Npc_Maluco", "Terca_Hora", 15, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Hora_Quarta		= GetPrivateProfileIntA("Npc_Maluco", "Quarta_Hora", 15, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Hora_Quinta		= GetPrivateProfileIntA("Npc_Maluco", "Quinta_Hora", 15, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Hora_Sexta		= GetPrivateProfileIntA("Npc_Maluco", "Sexta_Hora", 15, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Hora_Sabado		= GetPrivateProfileIntA("Npc_Maluco", "Sabado_Hora", 15, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Hora_Domingo		= GetPrivateProfileIntA("Npc_Maluco", "Domingo_Hora", 15, "..\\MarxD\\Npc_Maluco.ini");

	GS.Npc_Maluco_Minuto_Segunda	= GetPrivateProfileIntA("Npc_Maluco", "Segunda_Minuto", 15, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Minuto_Terca		= GetPrivateProfileIntA("Npc_Maluco", "Terca_Minuto", 15, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Minuto_Quarta	= GetPrivateProfileIntA("Npc_Maluco", "Quarta_Minuto", 15, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Minuto_Quinta	= GetPrivateProfileIntA("Npc_Maluco", "Quinta_Minuto", 15, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Minuto_Sexta		= GetPrivateProfileIntA("Npc_Maluco", "Sexta_Minuto", 15, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Minuto_Sabado	= GetPrivateProfileIntA("Npc_Maluco", "Sabado_Minuto", 15, "..\\MarxD\\Npc_Maluco.ini");
	GS.Npc_Maluco_Minuto_Domingo	= GetPrivateProfileIntA("Npc_Maluco", "Domingo_Minuto", 15, "..\\MarxD\\Npc_Maluco.ini");
}

void Inicia_NpcMaluco()
{
	char ArquivoAntigo[] = "..\\Data\\Shops\\Shop0.txt";
	char ArquivoNovo[] = "..\\Data\\Shops\\Shop0_orig.txt";
	char ArquivoAntigo_NpcMaluco[64];

	SYSTEMTIME t;
	GetLocalTime(&t);

	sprintf_s(ArquivoAntigo_NpcMaluco, "..\\Data\\Shops\\Shop_NpcMaluco%d.txt", t.wDayOfWeek);

	char ArquivoNovo_NpcMaluco[] = "..\\Data\\Shops\\Shop0.txt";

	rename(ArquivoAntigo, ArquivoNovo);
	rename(ArquivoAntigo_NpcMaluco, ArquivoNovo_NpcMaluco);
	pShopDataLoad();

	MsgParaTodos("[ Evento NpcMaluco Iniciado]", 0);
	char MsgOut[64];
	sprintf_s(MsgOut, "[ Restam %d minuto(s) de NpcMaluco ]", GS.Npc_Maluco_Duracao);
	MsgParaTodos(MsgOut, 0);
	MsgParaTodos("[ Local: Ferreiro de Lorencia ]", 0);
	if(GS.Npc_Maluco_Setar_Evento == 1) MsgParaTodos("[ Digite /evento para participar ]", 0);

	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Status_NpcMaluco),NULL,0,0);
}

void Acaba_NpcMaluco()
{
	char ArquivoAntigo_NpcMaluco[] = "..\\Data\\Shops\\Shop0.txt";
	char ArquivoNovo_NpcMaluco[64];
	SYSTEMTIME t;
	GetLocalTime(&t);
	sprintf_s(ArquivoNovo_NpcMaluco, "..\\Data\\Shops\\Shop_NpcMaluco%d.txt", t.wDayOfWeek);

	char ArquivoAntigo[] = "..\\Data\\Shops\\Shop0_orig.txt";
	char ArquivoNovo[] = "..\\Data\\Shops\\Shop0.txt";

	rename(ArquivoAntigo_NpcMaluco, ArquivoNovo_NpcMaluco);
	rename(ArquivoAntigo, ArquivoNovo);

	pShopDataLoad();

	if(GS.Npc_Maluco_Setar_Evento == 1)
	{
		GS.cmm_Evento_Mapa		= 0;
		GS.cmm_Evento_X		= 0;
		GS.cmm_Evento_Y		= 0;
	}
	MsgParaTodos("[ Evento NpcMaluco Finalizado ]", 0);
}

// - ###################### -     Npc_Maluco_Estado		- ###################### -
// - ###################### - 0 = Não Ocorrendo			- ###################### -
// - ###################### - 1 = Fazendo Anuncios		- ###################### -
// - ###################### - 2 = Ocorrendo				- ###################### -

void Status_NpcMaluco()
{	
	if(GS.Npc_Maluco_Estado == 0) return;
	GS.Npc_Maluco_Duracao--; // <- Fix NpcMaluco um minuto a mais
	while(true)
	{
		Sleep(60000);
		if(GS.Npc_Maluco_Estado == 0)
		{
			ExitThread(0);
			return;
		}

		if(GS.Npc_Maluco_Duracao == 0)
		{
			Acaba_NpcMaluco();
			GS.Noticias_Ativado	= 1;	// Liga as noticias automaticas
			Carrega_NpcMaluco();
			ExitThread(0);
			return;
		}

		char MsgOut[64];
		sprintf_s(MsgOut, "[ Restam %d minuto(s) de NpcMaluco ]", GS.Npc_Maluco_Duracao);
		MsgParaTodos(MsgOut, 0);
		MsgParaTodos("[ Local: Ferreiro de Lorencia ]", 0);
		if(GS.Npc_Maluco_Setar_Evento == 1) MsgParaTodos("[ Digite /evento para participar ]", 0);
		GS.Npc_Maluco_Duracao--;
	}
	
}

void Anuncios_NpcMaluco()
{
	if(GS.Npc_Maluco_Estado == 0) return;

	while(true)
	{
		Sleep(60000);
		if(GS.Npc_Maluco_Estado == 0)
		{
			ExitThread(0);
			return;
		}

		if(GS.Npc_Maluco_Anuncios_Previo == 0)
		{
			GS.Npc_Maluco_Estado = 2;
			Inicia_NpcMaluco();
			ExitThread(0);
			return;
		}

		char MsgOut[64];
		sprintf_s(MsgOut, "[ %d minuto(s) para iniciar o Npc Maluco ]", GS.Npc_Maluco_Anuncios_Previo);
		MsgParaTodos(MsgOut, 0);
		MsgParaTodos("[ Local: Ferreiro de Lorencia ]", 0);
		if(GS.Npc_Maluco_Setar_Evento == 1) MsgParaTodos("[ Digite /evento para participar ]", 0);
		GS.Npc_Maluco_Anuncios_Previo--;
	}
}

void NpcMaluco_Timer()
{
	while(true)
	{
		if(GS.Npc_Maluco_Ativado == 1 && GS.Npc_Maluco_Estado == 0)
		{
			SYSTEMTIME t;
			GetLocalTime(&t);
		
			int Ativado	= 0;
			int Hora	= 0;
			int Minuto	= 0;

			switch(t.wDayOfWeek)
			{
				case 0:  Ativado = GS.Npc_Maluco_Domingo;	Hora = GS.Npc_Maluco_Hora_Domingo;	Minuto = GS.Npc_Maluco_Minuto_Domingo;		break;
				case 1:  Ativado = GS.Npc_Maluco_Segunda;	Hora = GS.Npc_Maluco_Hora_Segunda;	Minuto = GS.Npc_Maluco_Minuto_Segunda;		break;
				case 2:  Ativado = GS.Npc_Maluco_Terca;		Hora = GS.Npc_Maluco_Hora_Terca;	Minuto = GS.Npc_Maluco_Minuto_Terca;		break;
				case 3:  Ativado = GS.Npc_Maluco_Quarta;	Hora = GS.Npc_Maluco_Hora_Quarta;	Minuto = GS.Npc_Maluco_Minuto_Quarta;		break;
				case 4:  Ativado = GS.Npc_Maluco_Quinta;	Hora = GS.Npc_Maluco_Hora_Quinta;	Minuto = GS.Npc_Maluco_Minuto_Quinta;		break;
				case 5:  Ativado = GS.Npc_Maluco_Sexta;		Hora = GS.Npc_Maluco_Hora_Sexta;	Minuto = GS.Npc_Maluco_Minuto_Sexta;		break;
				case 6:  Ativado = GS.Npc_Maluco_Sabado;	Hora = GS.Npc_Maluco_Hora_Sabado;	Minuto = GS.Npc_Maluco_Minuto_Sabado;		break;
			}

			if(Ativado == 1 && (int)t.wHour == Hora && (int)t.wMinute == Minuto)
			{

				GS.Npc_Maluco_Estado	= 1; // - 1 = Fazendo Anuncios
				GS.Noticias_Ativado	= 0; // - Noticias Automáticas in game 

				char MsgOut[64];
				sprintf_s(MsgOut, "[ %d minuto(s) para iniciar o Npc Maluco ]", GS.Npc_Maluco_Anuncios_Previo);
				MsgParaTodos(MsgOut, 0);
				GS.Npc_Maluco_Anuncios_Previo--; // - Para não repetir o Minuto
				MsgParaTodos("[ Local: Ferreiro de Lorencia ]", 0);

				if(GS.Npc_Maluco_Setar_Evento == 1)
				{
					GS.cmm_Evento_Mapa		= 0;
					GS.cmm_Evento_X		= 121;
					GS.cmm_Evento_Y		= 141;
					MsgParaTodos("[ Digite /evento para participar ]", 0);
				}

				CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Anuncios_NpcMaluco),NULL,0,0);
			}
		}

		Sleep(10000);
	}
}