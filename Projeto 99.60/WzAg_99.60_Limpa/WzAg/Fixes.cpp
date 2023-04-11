#include "stdAfx.h"

void Crack()
{
	// [ c:\muproject\data\ ] para [ ..\data\ ]
	char NovoPath[] = "..\\Data\\";
	DWORD* DataPathOffset = (DWORD*)(0x00616928);

	memset(&DataPathOffset[0], 0x00, 18);
	memcpy(&DataPathOffset[0], NovoPath, sizeof(NovoPath));
	
	//*(BYTE*)0x004FDA07 = 0xEB;	/* JMP na função MDrive								*/
	*(BYTE*)0x004FDA1E = 0xEB;		/* JMP na função MDrive								*/
	*(BYTE*)0x004FD9D9 = 0xEB;		/* JMP na MsgBox Already running					*/
	*(BYTE*)0x004F5558 = 0x28;		/* Seta o byte da para a pasta ..\Data\				*/
	*(BYTE*)0x004F7FF9 = 0xEB;		/* JMP para Nao setar o nome dos itens novamente!	*/

	// [ ..\data\serverinfo.dat ] para [ .\\Data\\ServerInfo.dat ]
	char NovoSvInfo[] = ".\\Data\\ServerInfo.dat";
	DWORD* NovaSvInfoOffset = (DWORD*)(0x00616A38);
	memset(&NovaSvInfoOffset[0], 0x00, 22);
	memcpy(&NovaSvInfoOffset[0], NovoSvInfo, sizeof(NovoSvInfo));
}

void Fixes()
{
	Crack();

	// - Data Send Fix
	*(BYTE*)(0x0043E71B+1)	= 0xD9; // - Ataque
	*(BYTE*)(0x0043DFC6+1)	= 0xD0; // - Dano
	*(BYTE*)(0x004BC90A+3)	= 0xD0; // - Dano
	*(BYTE*)(0x004BCD63+3)	= 0xD0; // - Dano
	*(BYTE*)(0x004DD13E+3)	= 0xD0; // - Dano
	*(BYTE*)(0x0043D8CF+1)	= 0xD7; // - Andar

	// - Todos os DC's
	//SetNop(0x00473C88, 6);	// - Error L1 - Socket header error %d, %d (Log)				// - SERVERWORKERTHREAD
	//SetNop(0x00473C97, 5);	// - Error L1 - Socket header error %d, %d (Call CloseClient)	// - SERVERWORKERTHREAD
	//SetNop(0x0047515F, 6);	// - Error Max Msg Send (Log)
	//SetNop(0x0047516C, 5);	// - Error Max Msg Send (Call DC)
	//SetNop(0x004751F5, 6);	// - (%d)error-l2 MAX BUFFER OVER %d %d %d [%s][%s] (Log)
	//SetNop(0x0047520F, 5);	// - (%d)error-l2 MAX BUFFER OVER %d %d %d [%s][%s] (Call DC)
	//SetNop(0x0047531E, 6);	// - (%d)error-l2 MAX BUFFER OVER %d %d %d [%s][%s] (Log)
	//SetNop(0x00475338, 5);	// - (%d)error-l2 MAX BUFFER OVER %d %d %d [%s][%s] (Call DC)

	SetByte(0x004FDC20, 0xEB); // - JoinServer Disable
	SetByte(0x004FDCAB, 0xEB); // - EventServer Disable
	SetByte(0x00460F70, 0xEB); // - Event Server Disable Fix
	SetByte(0x00460FD6, 0xEB); // - Event Server Disable Fix
	SetByte(0x004FDC68, 0xEB); // - RankingServer Disable
	SetByte(0x00453860, 0xEB); // - Ranking Server Disable Fix
	SetByte(0x004538C6, 0xEB); // - Ranking Server Disable Fix

	// - Alguns nops para diminuir o log
	SetNop(0x0042197E, 6);	// - Monster Item Drop Request
	SetNop(0x00422312, 6);	// - Monster Item Drop
	SetNop(0x00479EA5, 6);	// - Item has Disappeared
	SetNop(0x00479105, 6);	// - Can't throw away the item
	SetNop(0x004BCEE8, 6);	// - Experience : Map (0x0x0x0x00)
	SetNop(0x004BD115, 6);	// - Level Up
	SetNop(0x00473C88, 6);  // - Log de Socket Error
	SetNop(0x00473C97, 5);  // - Log de Socket Error
	SetNop(0x00475C4A, 6);  // - Log de Socket Error
	SetNop(0x00475D38, 6);  // - Log de Socket Error
	SetNop(0x00471E44, 6);	// - [Quest] Quest Save [%s] [%s]
	//SetNop(0x00475C4A, 6);	// - Função CloseClient					- Nopeado MSG LOG "error-L1 : CloseClient INVALID_SOCKET"
	SetNop(0x0049CAAE, 6);	// - Log add da Msg "¸¶°Ë»ç ¸ó½ºÅÍ¹æ¾î·Â°¨¼Ò : 10" ao usar FireSlash
	//SetNop(0x00415C4C, 5); // - Kundun Fix

	// - Webzen nick fix
	*(BYTE*)(0x004B640B+6) = 0x01;
	*(BYTE*)(0x004B644C+6) = 0x01;
	*(BYTE*)(0x004B6504+6) = 0x01;

	// - Dark Horse & Raven fix
	*(BYTE*)(0x004232A6+2) = 0x00;
	*(BYTE*)(0x004232A6+3) = 0x00;
	*(BYTE*)(0x004232C8+1) = 0x00;
	*(BYTE*)(0x004232C8+2) = 0x00;

	*(BYTE*)(0x004B2B55+3) = 0x01;		// - Selecionar personagem, server, sair, em 1 segundo
	*(BYTE*)(0x004B29F2) = 0xEB;		// - Deffense Setting ao tentar sair do jogo
	SetNop(0x004BD128, 5);				// - Congelamento ao logar (STAND BY)
	//SetNop(0x004043B8, 5);				// - MsgBox Fix (Não aparecerá MSGBOX's)
	//*(BYTE*)(0x00489540) = 0xC3;		// - MsgBox Fix (Não aparecerá MSGBOX's)
	
	SetNop(0x00402C57, 5);				// - Jmp DestroyGIocp
	*(BYTE*)(0x00402C57) =  0xC3;		// - Jmp DestroyGIocp
	SetNop(0x00402F9F, 5);				// - Jmp MemoryError 0x000000
	*(BYTE*)(0x00402F9F) =  0xC3;		// - Jmp MemoryError 0x000000

	//SetNop(0x00403689, 5);				// - Jmp gObjDel
	//*(BYTE*)(0x00403689) =  0xC3;		// - Jmp gObjDel
	//*(BYTE*)(0x004D267C) = 0xEB;		// - Função gObjSecondProc				- (Logado e Jogando) Jmp na 1º ResponErrorCloseClient() - Disconecta usuarios Logados ?? Não faz sentido
	//*(BYTE*)(0x004D26D2) = 0xEB;		// - Função gObjSecondProc				- (Apenas Conectado) Jmp na 2º ResponErrorCloseClient() - Disconecta Clientes conectados depois de 30Segundos!
	//SetNop(0x004D271F, 5);				// - Funçãp gObjSecondProc				- Nopeia o call da funcão CGameServerAuth::SendInfo
	//*(BYTE*)(0x004D20D6) = 0xEB;		// - Função gObjSecondProc				- Jmp no gObjDel do if(lpObj->m_dwMapSvrQuitTick > 30000)
	//SetNop(0x00475D45, 5);				// - Função ResponErrorCloseClient		- Nopeado: gObjDel 

	*(BYTE*)(0x00499F20) = 0xEB;		// - [%s][%s] Try Attack In Not Attack Area (%s,%d,%d) errortype = %d E [%s][%s][%s] ClientHack Detected : Editing AttackSpeed [%d][%d] [%d][%d]
	*(BYTE*)(0x0043EED2) = 0xEB;		// - Jmp Funçao SpeedHack::gObjCheckArea
	*(BYTE*)(0x00440D44) = 0xEB;		// - CGDurationMagicRecv::SpeedHackCheck
 	*(BYTE*)(0x00428A3A) = 0xEB;		// - CheckSum Bypass					- Jmp 1 [FIX]
 	*(BYTE*)(0x00428A98) = 0xEB;		// - CheckSum Bypass					- Jmp 2 [FIX]
	*(BYTE*)(0x0042B401) = 0xEB;		// - Del Char ID fix
	*(BYTE*)(0x00426DE6) = 0xEB;		// - Função ProtocolCore				- Jmp para Pular o DC & LOG do "Error-L1 : Socket Serial %s %d o_serial:%d serial:%d"
	//*(BYTE*)(0x00475C18) = 0xEB;		// - Função CloseClient					- Jmp para fim da função
	*(BYTE*)(0x004B8ED9) = 0xEB;		// - Função gObjAdd						- Fix para gObjAddSearch_Hook
	*(BYTE*)(0x00523052) = 0xEB;		// - Função NpcShadowPhantom			- Fix Jmp Level

	// - Option +28
 	SetNop(0x00420D3E, 2);
 	SetNop(0x004EBB17, 2);
 	*(BYTE*)(0x004DA697) = 0x07;
 	*(BYTE*)(0x004B457A) = 0x07;

	// - Potion bug fix
 	SetNop(0x00420E7E,8);
 	SetNop(0x004B4656,8);
	
	// - Guild ID fix
 	SetNop(0x004399EA, 6);
	SetNop(0x00439B40, 2);


	// - PCHAT Fix
	BYTE Pchat1[] = {0x8B,0x45,0xF0,0x50,0x8B,0x4D,0x08,0x83,0xC1,0x0D,0x51,
      0x8D,0x95,0x38,0xEE,0xFF,0xFF,0x52,0xE8,0x54,0x11,0x10,
      0x00,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,
      0x90,0x90,0x90,0x90,0x90,0x90,0x90};
	memset((int*)(0x00429400+5),0x00,sizeof(Pchat1));
	memcpy((int*)(0x00429400+5),Pchat1,sizeof(Pchat1));

	SetNop((0x004294A0+13),15);
	SetNop((0x004295C0+11),15);
	SetNop((0x004295F0+10),15);
 
	*(BYTE*)(0x004291B0+10) = 0xE2;
	*(BYTE*)(0x004291B0+11) = 0x1E;
	*(BYTE*)(0x004292B0+8) = 0x01;
	*(BYTE*)(0x004292C0+5) = 0x0C;
	*(BYTE*)(0x00429300+4) = 0x0E;
	*(BYTE*)(0x004293D0+6) = 0x74;
	*(BYTE*)(0x004295F0+6) = 0x0E;
	*(BYTE*)(0x00429640+12) = 0x0F;
	// Fim Fix PchatProc
}