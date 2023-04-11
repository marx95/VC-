#include "stdafx.h"

void BuxConvert(char* buf, int size)
{
	unsigned char bBuxCode[3]={0xFC, 0xCF, 0xAB};
	for (int n=0;n<size;n++)
	{
		buf[n]^=bBuxCode[n%3] ;		// Nice trick from WebZen
	}
}

/*void DCAccLogada(char * Login, int aIndex)
{
	for(int i = Obj_Jogadores_Minimo; i < Obj_Jogadores_Maximo; i++)
	{
		if(i != aIndex)
		{
			if(Logado(i))
			{
				if(Procurar(gObj(i)->AccountID, Login, false))
				{
					MsgCentro("[Aviso] Outra Tentativa de Login!!!", i);
					CloseClient(i);
					return;
				}
			}
		}
	}
}*/

short gObjDel_Hook(int aIndex)
{
	if(strlen(gObj(aIndex)->AccountID) > 4)
	{
		if(Logado(aIndex)) Mssql_Atualiza(aIndex, 11);
	}

	return gObjDel(aIndex);
}

void CSPJoinIdPassRequest_Hook(PMSG_IDPASS* lpMsg, int aIndex)
{
	/*
	############## Explicação .result ###############
	pResult.result = 0; // Senha Errada ou Senha Nula
	pResult.result = 1; // - TUDO OK PARA LOGAR
	pResult.result = 2; // Conta inexistente
	pResult.result = 3; // Conta Conectada
	pResult.result = 5; //  Conta Bloqueada
	pResult.result = 6; //  Nova Versao = Serial ou Main Invalidos
	pResult.result = 8; //  Tentativas de login excedido
	*/

	// -Verificação Versao Main & Serial
	char TmpMainVersion[7];
	char TmpSerial[16];
	TmpMainVersion[0] = lpMsg->CliVersion[0];
	TmpMainVersion[1] = 0x2e; //'.';
	TmpMainVersion[2] = lpMsg->CliVersion[1];
	TmpMainVersion[3] = lpMsg->CliVersion[2];
	TmpMainVersion[4] = 0x2e; //'.';
	TmpMainVersion[5] = lpMsg->CliVersion[3];
	TmpMainVersion[6] = lpMsg->CliVersion[4];
	strncpy(TmpSerial, (char*)lpMsg->CliSerial, 16);

	if(!Procurar(TmpMainVersion, GS.Main_Version, true))
	{
		GCJoinResult(0x6 , aIndex);
		CloseClient(aIndex);
		return;
	}

	if(!Procurar(TmpSerial, GS.Main_Serial, true))
	{
		GCJoinResult(0x6 , aIndex);
		CloseClient(aIndex);
		return;
	}
	//

	char Login[10];
	char Senha[10];
	BuxConvert(lpMsg->Id, 10);
	BuxConvert(lpMsg->Pass, 10);

	strncpy(Login, lpMsg->Id, 10);
	strncpy(Senha, lpMsg->Pass, 10);

	gObj(aIndex)->CheckTick				= lpMsg->TickCount;
	gObj(aIndex)->CheckTick2			= GetTickCount();
	gObj(aIndex)->ConnectCheckTime		= GetTickCount();
	gObj(aIndex)->CheckSpeedHack		= true;
	gObj(aIndex)->ConnectCheckTime		= GetTickCount();
	gObj(aIndex)->LoginMsgSnd			= 1;
	gObj(aIndex)->LoginMsgCount++;
	gObj(aIndex)->m_cAccountItemBlock	= 0;
	gObj(aIndex)->m_bMapSvrMoveReq		= false;
	gObj(aIndex)->m_sPrevMapSvrCode		= -1; 
	gObj(aIndex)->m_sDestMapNumber		= -1;
	gObj(aIndex)->m_btDestX				= 0;
	gObj(aIndex)->m_btDestY				= 0;
	gObj(aIndex)->AccountID[11]			= 0;
	strncpy(gObj(aIndex)->AccountID, Login, 10);

	// - Minhas Verificações

	if(gObj(aIndex)->LoginMsgCount > 3)
	{
		MsgCentro("[Limite de 3 tentatívas excedido!]", aIndex);
		CloseClient(aIndex);
		return;
	}

	SDHP_IDPASSRESULT pResult;
	int DbNumber;

	// - Verifica Login e senha
	DbNumber = DbConnection.PegarInt("memb_guid", "MEMB_INFO", "WHERE memb___id = '%s' AND memb__pwd = '%s'", Login, Senha);
	
	if(DbNumber < 1) // - Conta Inexistente OU Senha Errada
	{
		pResult.result = 2;
		GCJoinResult(pResult.result , aIndex);
		return;
	}

	pResult.DBNumber = DbNumber;
	//

	//- Verifica se a Conta ta Bloqueada!
	int Block = DbConnection.PegarInt("Bloc_Code", "MEMB_INFO", "WHERE memb___id = '%s'", Login);
	if(Block == 1)
	{
		pResult.result = 5;
		GCJoinResult(pResult.result , aIndex);
		return;
	}
	//

	// - Verifica se a Conta está Conectada!
	int UpUP = DbConnection.PegarInt("UpUp", "MEMB_STAT", "WHERE memb___id = '%s'", Login);
	if(UpUP == 0) // - Inserção na DB
	{
		char TmpCnnQ[512];
		sprintf_s(TmpCnnQ, "INSERT INTO MEMB_STAT(memb___id, UpStat, UpUp) VALUES('%s', 0, 1)", gObj(aIndex)->AccountID);
		DbConnection.Executar(TmpCnnQ);
	}

	int CnnStat = DbConnection.PegarInt("UpStat", "MEMB_STAT", "WHERE memb___id = '%s'", Login);
	if(CnnStat > 0) // - Conta Conectada
	{
		pResult.result = 3;
		GCJoinResult(pResult.result , aIndex);
		return;
	}
	//

	// - JoominNumber x sno_numb
	GS.g_iUserNumber++;
	//int sno_numb = DbConnection.PegarInt("sno__numb", "MEMB_INFO", "WHERE memb___id = '%s'", lpMsg->Id);
	sprintf_s(pResult.JoominNumber, "%d", "0            ");
	pResult.UserNumber = GS.g_iUserNumber;
	//

	// Copy Data
	pResult.h.c = 0xC1;
	pResult.h.size = sizeof(SDHP_IDPASSRESULT);
	pResult.h.headcode = 0x01;
	memcpy(pResult.Id, Login, 10);
	pResult.Number = aIndex;
	pResult.result = 1;

	Mssql_Atualiza(aIndex, 10);		// - Connect Stat
	gObj(aIndex)->Connected = 2;	// - Importante para poder Enviar Lista de Chars
	GCJoinResult(pResult.result , aIndex);
}