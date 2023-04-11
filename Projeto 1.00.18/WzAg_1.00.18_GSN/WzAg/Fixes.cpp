#include "StdAfx.h"

void Serial0Fix()
{
	SetByte(0x00437E69,0xEB);   // Serial 0 Item Drop Fix
	SetByte(0x004ED004,0xEB);   // Serial 0 Trade Fix #1
	SetByte(0x004ED661,0xEB);   // Serial 0 Trade Fix #2
	SetByte(0x00437E69,0xEB);   // Serial 0 Item
	SetByte(0x0050A99A,0xEB);   // Serial 0 Lahap Mix Fix
	SetByte(0x0050B14A,0xEB);   // Serial 0 Lahap UnMix Fix

	SetByte(0x0043D05C,0xE9);   // Serial 0 Item Sell Fix #1
	SetByte(0x0043D05C+1,0x81); // Serial 0 Item Sell Fix #2
	SetByte(0x0043D05C+2,0x00); // Serial 0 Item Sell Fix #3
	SetNop(0x0043D061,1);       // Serial 0 Item Sell Fix #4

	SetByte(0x0044D391,0xE9);   // Serial 0 Use Item Fix #1
	SetByte(0x0044D391+1,0x97); // Serial 0 Use Item Fix #2
	SetByte(0x0044D391+2,0x00); // Serial 0 Use Item Fix #3
	SetNop(0x0044D396,1);       // Serial 0 Use Item Fix #4

	SetByte(0x004EA82C,0xEB);   // Serial 0 Move Item Fix

	SetByte(0x004404B5,0xE9);   // Serial 0 Personal Shop Fix #1
	SetByte(0x004404B5+1,0x9C); // Serial 0 Personal Shop Fix #2
	SetByte(0x004404B5+2,0x00); // Serial 0 Personal Shop Fix #3
	SetNop(0x004404BA,1);       // Serial 0 Personal Shop Fix #4

	SetByte(0x0044213E,0xE9);   // Serial 0 Personal Shop Sell Fix #1
	SetByte(0x0044213E+1,0xA2); // Serial 0 Personal Shop Sell Fix #2
	SetByte(0x0044213E+2,0x00); // Serial 0 Personal Shop Sell Fix #3
	SetNop(0x00442143,1);       // Serial 0 Personal Shop Sell Fix #4
}

void Crack()
{
	// - Data Path
	char NovoPath[] = "..\\Data\\";
	DWORD* DataPathOffset = (DWORD*)(0x006C3054);
	memset(&DataPathOffset[0], 0x00, sizeof(NovoPath));
	memcpy(&DataPathOffset[0], NovoPath, sizeof(NovoPath));

	// - Commonserver.cfg
	char NovoCSCFGPath[] = "..\\Data\\Commonserver.cfg";
	DWORD* NovoCSCFGPathOffset = (DWORD*)(0x006B2FE1);
	memcpy(&NovoCSCFGPathOffset[0], NovoCSCFGPath, sizeof(NovoCSCFGPath));
	SetByte(0x0052D6CC, 0x68);
	SetByte(0x0052D6CC+1, 0xE1);
	SetByte(0x0052D6CC+2, 0x2D);
	SetByte(0x0052D6CC+3, 0x6B);
	SetByte(0x0052D6CC+4, 0x00);

	// - Serverinfo.dat
	char NovoSvInfo[] = ".//ServerInfo.dat";
	DWORD* NovaSvInfoOffset = (DWORD*)(0x006C3164);
	memset(&NovaSvInfoOffset[0], 0x00, sizeof(NovoSvInfo));
	memcpy(&NovaSvInfoOffset[0], NovoSvInfo, sizeof(NovoSvInfo));

	SetByte(0x00520EC8, 0x54);	// Fix PUSH offset da Dir Data Path
	SetByte(0x0052D6DA, 0xEB);  // Fix M:\ DRIVE MSG BOX, muda para JMP
	SetByte(0x0052D6F2, 0xEB);	// Already running

	// - Fechar GS sem dar erro
	SetByte(0x0052EABF+2, 0x18);
	SetByte(0x0052EABF+3, 0xBE);
	SetByte(0x0052EACB+2, 0x18);
	SetByte(0x0052EACB+3, 0xBE);
}

void Fixes()
{
	Crack();
	SetByte(0x004D0FA2, 0xEB);	// - Self Defence Fix
	SetByte(0x0042FD6D, 0xEB);  //Socket Serial Error
	SetNop(0x004DC861, 5);		//Fix Trava quando Loga *HOT*
	SetRetn(0x00402B9E);		//Destroy GIOCP
	SetByte(0x0043185E, 0xEB);	//Client Attack Speed
	SetByte(0x0055DF9C, 0xFF);	//MonsterAIElement() error
	SetByte(0x00434524, 0xEB);	//Deletar Personagem - Sem precisar da ID
	SetNop(0x005264C5, 29);		//ChaosCardProbability
	SetByte(0x004EA2E5, 0xEB);	//Fix Colocar Itens na Chaos Machine
	SetByte(0x004D1115, 0x01);	//Fix 5 segundos ao sair do jogo/relogar/sel char
	SetNop(0x0044521A,6);		//Deletar Guild - Sem precisar da ID
	SetNop(0x00445370, 2);		// Fix Sair Guild
	SetByte(0x0051B716,0x07);	//GMWarp
	SetByte(0x0048A0C0, 0xC3);	// Error-L10 [NEW] - por Haziel
	SetByte(0x0048AA9E, 0xEB);	//-- Fixes sp2 [NEW] - por Haziel
	SetRetn(0x004049CB);		//Message box Error
	SetByte(0x0043177E, 0xEB);	// - Time synchronization poorness caused to block connection
	SetNop(0x004DF3E2, 15);		// - Exp Quando Morre
	Serial0Fix();

	SetNop(0x0042A2EE, 6);	// Monster Item Drop Request
	SetNop(0x0042AE2B, 6);	// Monster Item Drop
	SetNop(0x00490EC5, 6);	// Item has Disappeares
	SetNop(0x00490149, 6);	// Can't throw away the item
	SetNop(0x004DC4A2, 6);	// Experience : Map (0x0x0x0x00)
	SetNop(0x004DC769, 6);	// Level Up

	 //-- Fixes Disconnects [NEW] - por Haziel
	SetNop(0x0048AC47, 5);
	SetNop(0x0048C11C, 5);
	SetNop(0x0048C1BF, 5);
	SetNop(0x0048C2E8, 5);

	 
	//Memory error
	SetRetn(0x0040635C);
	SetNop(0x0040635D,4);
	

	//Attack Speed
	memset((PBYTE) 0x0043183F, 0xE9, 1); 
	memset((PBYTE) 0x00431840, 0x2F, 1); 
	memset((PBYTE) 0x00431841, 0x01, 1); 
	memset((PBYTE) 0x00431842, 0x00, 2); 
	memset((PBYTE) 0x00431843, 0x00, 2); 
	memset((PBYTE) 0x00431844, 0x90, 1); 

	//SpeedHack
	memset((PBYTE) 0x00403DFF, 0xC3, 1 );
	memset((PBYTE) 0x00403E00, 0x90, 4 ); 
	memset((PBYTE) 0x0044A0DC, 0x90, 6 );

	//Fix Crash no bau Corvo e Cavalo
	memset((PBYTE) 0x0042BE36+2, 0x00, 2);
	memset((PBYTE) 0x0042BE58+1, 0x00, 2);

	//Remove Autoridade do Nick Webzen
	memset((PBYTE) 0x004D537C+6, 0x01, 1);
	memset((PBYTE) 0x0042BE58+1, 0x01, 1);
	memset((PBYTE) 0x004D53BD+6, 0x01, 1);

	//Potion Bug
	SetNop(0x00429711,8);
	SetNop(0x004D304E,8);
	SetByte(0x004D30EE, 0xEB);	//PotionBug para SG

	//CheckSum
	SetRetn(0x004021E4);		//CheckSum
	SetByte(0x00431C38,0xEB);	//CheckSum

	//PKBug
	SetByte(0x004B638A,0xEB);
	SetByte(0x004B665C,0xEB);
	SetByte(0x004B6687,0xEB);

	//3ª classe entrando no jogo
	SetByte(0x004D3A73, 0xEB);

	//Fix da 3ª classe na lista de personagens
	SetByte(0x004259FD, 0xE9);
	Hook(GET_ADDR(FixCharListClass), 0x004259FD);
	SetNop(0x004259FD+5, 1);

	//Fix da 3ª asa na lista de personagens
	SetByte(0x00426CF3, 0xE9);
	Hook(GET_ADDR(FixCharListWings), 0x00426CF3);
	SetNop(0x00426CF3+5, 1);
	SetNop(0x004273A4, 7);

	//Fix do Fenrir na lista de personagens
	SetByte(0x00427416, 0xE9);
	Hook(GET_ADDR(FixCharListFenrir), 0x00427416);
	SetNop(0x00427416+5, 1);

	Hook(GET_ADDR(FixCharSet), 0x0040378D);			//Fix CharSet
	SetNop(0x004F7240, 21);							//Fix Viewport
	SetNop(0x004F728C, 33);							//Fix Viewport
	SetNop(0x004F812B, 18);							//Fix Viewport
	SetNop(0x004F82D3, 20);							//Fix Viewport
	SetNop(0x004F831F, 33);							//Fix Viewport
	SetWord(0x0051E73F, 0x12EB);					//Desabilita Movereq check
	SetWord(0x004FB595, 0x1828);					//Entrar no mapa com as novas asas
	SetByte(0x00512801, 2);							//Habilita nova classe usar equipamentos
	SetByte(0x0048421C, 2);							//Habilita nova classe usar skills
	SetByte(0x005085B3, false);						//Serial 0 Check - Fix

	//Novas Asas lvlup - bless, soul, life
	SetWord(0x004FE30A, 0x1828);
	SetWord(0x004FE850, 0x1828);
	SetWord(0x004FF010, 0x1828);

	//Novas asas - luck e opções excelentes
	SetWord(0x0050F512, 0x1828);
	SetWord(0x0050FDEB, 0x1828);
	SetByte(0x0050F713,	0x7D);

	//Upar itens até +28
	SetByte(0x004FF1E7, 7); // +28
	SetByte(0x004D2E85, 7); // +28
	SetByte(0x00514ED7, 7); // JOL
	SetByte(0x00429501, 7); // +28

	//Repair asas lvl3
	BYTE cFix1[7]  = {0xE9,0xEC,0x01,0x00,0x00,0x90,0x90};
	BYTE cFix2[41] = {0x81,0x7D,0xF0,0x24,0x18,0x00,0x00,0x7C,0x0E,0x81,0x7D,0xF0,0x28,0x1C,0x00,0x00,0x7F,0x05,0xE9,0x2E,0xFE,0xFF,0xFF,0x81,0x7D,0xF0,0x00,0x1C,0x00,0x00,0x0F,0x8D,0x33,0xFE,0xFF,0xFF,0xE9,0xEF,0xFD,0xFF,0xFF};
	memcpy((BYTE *)0x0043DD6B, cFix1 , sizeof(cFix1));
	memcpy((BYTE *)0x0043DF5C, cFix2 , sizeof(cFix2));

	// - FIX 65K
	BYTE ByteFix = 0xB7;
	*(BYTE*)(0x44F25F) = ByteFix;
	*(BYTE*)(0x4D3673) = ByteFix;
	*(BYTE*)(0x503B91) = ByteFix;
	*(BYTE*)(0x53F19A) = ByteFix;
	*(BYTE*)(0x53F393) = ByteFix;
	*(BYTE*)(0x53F5DC) = ByteFix;
	*(BYTE*)(0x581A1B) = ByteFix;
	*(BYTE*)(0x488298) = ByteFix;
	*(BYTE*)(0x4B1DB5) = ByteFix;
	*(BYTE*)(0x4B21A2) = ByteFix;
	*(BYTE*)(0x4B22A0) = ByteFix;
	*(BYTE*)(0x4B2273) = ByteFix;
	*(BYTE*)(0x4B22C8) = ByteFix;
	*(BYTE*)(0x4B37E2) = ByteFix;
	*(BYTE*)(0x4B4A46) = ByteFix;
	*(BYTE*)(0x4B4AD8) = ByteFix;
	*(BYTE*)(0x4B5400) = ByteFix;
	*(BYTE*)(0x4B6B62) = ByteFix;
	*(BYTE*)(0x4B6BFC) = ByteFix;
	*(BYTE*)(0x4C2A8A) = ByteFix;
	*(BYTE*)(0x4C70A3) = ByteFix;
	*(BYTE*)(0x4C7A4D) = ByteFix;
	*(BYTE*)(0x4C7C34) = ByteFix;
	*(BYTE*)(0x4C940F) = ByteFix;
	*(BYTE*)(0x4D61F2) = ByteFix;
	*(BYTE*)(0x4E7D67) = ByteFix;
	*(BYTE*)(0x502314) = ByteFix;
	*(BYTE*)(0x50258E) = ByteFix;
	*(BYTE*)(0x50277E) = ByteFix;
	*(BYTE*)(0x44F2CC) = ByteFix;
	*(BYTE*)(0x4D3698) = ByteFix;
	*(BYTE*)(0x503B52) = ByteFix;
	*(BYTE*)(0x53F186) = ByteFix;
	*(BYTE*)(0x53F37F) = ByteFix;
	*(BYTE*)(0x53F5C8) = ByteFix;
	*(BYTE*)(0x581A0A) = ByteFix;
	*(BYTE*)(0x4B1DCE) = ByteFix;
	*(BYTE*)(0x4B21B6) = ByteFix;
	*(BYTE*)(0x4B221E) = ByteFix;
	*(BYTE*)(0x4B2287) = ByteFix;
	*(BYTE*)(0x4B22DC) = ByteFix;
	*(BYTE*)(0x4B6B42) = ByteFix;
	*(BYTE*)(0x4B6BDC) = ByteFix;
	*(BYTE*)(0x4B6E96) = ByteFix;
	*(BYTE*)(0x4B6ED9) = ByteFix;
	*(BYTE*)(0x4B6F12) = ByteFix;
	*(BYTE*)(0x4B6F52) = ByteFix;
	*(BYTE*)(0x4B6F91) = ByteFix;
	*(BYTE*)(0x4B6FC2) = ByteFix;
	*(BYTE*)(0x4B6FFD) = ByteFix;
	*(BYTE*)(0x4B7038) = ByteFix;
	*(BYTE*)(0x4B7073) = ByteFix;
	*(BYTE*)(0x4B70AE) = ByteFix;
	*(BYTE*)(0x4B9DD8) = ByteFix;
	*(BYTE*)(0x4C2AA3) = ByteFix;
	*(BYTE*)(0x4C706D) = ByteFix;
	*(BYTE*)(0x4C710F) = ByteFix;
	*(BYTE*)(0x4C7A92) = ByteFix;
	*(BYTE*)(0x4C7C4A) = ByteFix;
	*(BYTE*)(0x4C9428) = ByteFix;
	*(BYTE*)(0x4CA9E6) = ByteFix;
	*(BYTE*)(0x4CAA29) = ByteFix;
	*(BYTE*)(0x4CAA62) = ByteFix;
	*(BYTE*)(0x4CAAA2) = ByteFix;
	*(BYTE*)(0x4CAAE1) = ByteFix;
	*(BYTE*)(0x4CAB12) = ByteFix;
	*(BYTE*)(0x4CAB4D) = ByteFix;
	*(BYTE*)(0x4CAB88) = ByteFix;
	*(BYTE*)(0x4CABC3) = ByteFix;
	*(BYTE*)(0x4CABFE) = ByteFix;
	*(BYTE*)(0x4D61E7) = ByteFix;
	*(BYTE*)(0x4E7D9F) = ByteFix;
	*(BYTE*)(0x50231E) = ByteFix;
	*(BYTE*)(0x502598) = ByteFix;
	*(BYTE*)(0x502788) = ByteFix;
	*(BYTE*)(0x4D36BD) = ByteFix;
	*(BYTE*)(0x503B10) = ByteFix;
	*(BYTE*)(0x53F172) = ByteFix;
	*(BYTE*)(0x53F36B) = ByteFix;
	*(BYTE*)(0x53F5B4) = ByteFix;
	*(BYTE*)(0x5819F9) = ByteFix;
	*(BYTE*)(0x4B1DE7) = ByteFix;
	*(BYTE*)(0x4B21CA) = ByteFix;
	*(BYTE*)(0x4B2232) = ByteFix;
	*(BYTE*)(0x4B229B) = ByteFix;
	*(BYTE*)(0x4B22F0) = ByteFix;
	*(BYTE*)(0x4B99CC) = ByteFix;
	*(BYTE*)(0x4C2ABC) = ByteFix;
	*(BYTE*)(0x4C7145) = ByteFix;
	*(BYTE*)(0x4C7B52) = ByteFix;
	*(BYTE*)(0x4C7C62) = ByteFix;
	*(BYTE*)(0x4C9441) = ByteFix;
	*(BYTE*)(0x4D47BD) = ByteFix;
	*(BYTE*)(0x4D61DC) = ByteFix;
	*(BYTE*)(0x4E7E0E) = ByteFix;
	*(BYTE*)(0x50232A) = ByteFix;
	*(BYTE*)(0x5025A4) = ByteFix;
	*(BYTE*)(0x502794) = ByteFix;
	*(BYTE*)(0x50441B) = ByteFix;
	*(BYTE*)(0x50443E) = ByteFix;
	*(BYTE*)(0x504461) = ByteFix;
	*(BYTE*)(0x504484) = ByteFix;
	*(BYTE*)(0x4D36E2) = ByteFix;
	*(BYTE*)(0x503ACE) = ByteFix;
	*(BYTE*)(0x53F15E) = ByteFix;
	*(BYTE*)(0x53F357) = ByteFix;
	*(BYTE*)(0x53F5A0) = ByteFix;
	*(BYTE*)(0x5819E8) = ByteFix;
	*(BYTE*)(0x4B1E00) = ByteFix;
	*(BYTE*)(0x4B21DE) = ByteFix;
	*(BYTE*)(0x4B2246) = ByteFix;
	*(BYTE*)(0x4B22AF) = ByteFix;
	*(BYTE*)(0x4B2304) = ByteFix;
	*(BYTE*)(0x4B2BDB) = ByteFix;
	*(BYTE*)(0x4B4AF8) = ByteFix;
	*(BYTE*)(0x4B99EC) = ByteFix;
	*(BYTE*)(0x4B9A16) = ByteFix;
	*(BYTE*)(0x4B9DF8) = ByteFix;
	*(BYTE*)(0x4B9E2D) = ByteFix;
	*(BYTE*)(0x4B9FA6) = ByteFix;
	*(BYTE*)(0x4BA237) = ByteFix;
	*(BYTE*)(0x4BA9F1) = ByteFix;
	*(BYTE*)(0x4BAB33) = ByteFix;
	*(BYTE*)(0x4BDC9A) = ByteFix;
	*(BYTE*)(0x4BDCBD) = ByteFix;
	*(BYTE*)(0x4C2AD5) = ByteFix;
	*(BYTE*)(0x4C70D9) = ByteFix;
	*(BYTE*)(0x4C7AD7) = ByteFix;
	*(BYTE*)(0x4C7C7A) = ByteFix;
	*(BYTE*)(0x4C945A) = ByteFix;
	*(BYTE*)(0x4D485C) = ByteFix;
	*(BYTE*)(0x4D61D1) = ByteFix;
	*(BYTE*)(0x4E7E38) = ByteFix;
	*(BYTE*)(0x4FD676) = ByteFix;
	*(BYTE*)(0x4FDB22) = ByteFix;
	*(BYTE*)(0x4FE0AD) = ByteFix;
	*(BYTE*)(0x502336) = ByteFix;
	*(BYTE*)(0x5025B0) = ByteFix;
	*(BYTE*)(0x5027A0) = ByteFix;

}