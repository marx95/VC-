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
	SetByte(0x0043D05C, 0x81); // Serial 0 Item Sell Fix #2
	SetByte(0x0043D05C+2,0x00); // Serial 0 Item Sell Fix #3
	SetNop(0x0043D061,1);       // Serial 0 Item Sell Fix #4

	SetByte(0x0044D391,0xE9);   // Serial 0 Use Item Fix #1
	SetByte(0x0044D391, 0x97); // Serial 0 Use Item Fix #2
	SetByte(0x0044D391+2,0x00); // Serial 0 Use Item Fix #3
	SetNop(0x0044D396,1);       // Serial 0 Use Item Fix #4

	SetByte(0x004EA82C,0xEB);   // Serial 0 Move Item Fix

	SetByte(0x004404B5,0xE9);   // Serial 0 Personal Shop Fix #1
	SetByte(0x004404B5, 0x9C); // Serial 0 Personal Shop Fix #2
	SetByte(0x004404B5+2, 0x00); // Serial 0 Personal Shop Fix #3
	SetNop(0x004404BA,1);       // Serial 0 Personal Shop Fix #4

	SetByte(0x0044213E,0xE9);   // Serial 0 Personal Shop Sell Fix #1
	SetByte(0x0044213E, 0xA2); // Serial 0 Personal Shop Sell Fix #2
	SetByte(0x0044213E+2,0x00); // Serial 0 Personal Shop Sell Fix #3
	SetNop(0x00442143,1);       // Serial 0 Personal Shop Sell Fix #4
}

void Crack()
{
	// - Data Path
	char NovoPath[] = "..\\Data\\";
	DWORD* DataPathOffset = (DWORD*)(0x007198CC);
	memset(&DataPathOffset[0], 0x00, 17);
	memcpy(&DataPathOffset[0], NovoPath, 9);

	// - Serverinfo.dat
	char NovoSvInfo[] = ".\\ServerInfo.dat";
	DWORD* NovaSvInfoOffset = (DWORD*)(0x007199DC);
	memset(&NovaSvInfoOffset[0], 0x00, 24);
	memcpy(&NovaSvInfoOffset[0], NovoSvInfo, 22);

	//SetByte(0x00520EC8, 0x54);	//Fix PUSH offset da Dir Data Path
	SetByte(0x005424DA, 0xEB);  // Fix M:\ DRIVE MSG BOX, muda para JMP
	//SetByte(0x005424F2, 0xEB);	// Already running
}

void Fixes()
{
	Crack();
	
	//Destroy IOCP
	SetNop(0x0040308F, 5);
	SetByte(0x0040308F, 0xC3);

	//WzAg FreeLibrary 0000 Memory Error
	SetNop(0x004069B5, 5);
	SetByte(0x004069B5, 0xC3);

	//Checksum
	SetByte(0x00434C78, 0xEB);

	//Personal ID
	SetByte(0x004EC110, 0xEB);
	SetByte(0x004EC110, 0x27);
	SetNop(0x004EC110+2, 4);

	//3ª classe entrando no jogo
	SetByte(0x004E58F3, 0xEB);

	//Fix da 3ª classe na lista de personagens
	SetByte(0x004273DD, 0xE9);
	HookThis(GET_ADDR(FixCharListClass), 0x004273DD);
	SetNop(0x004273DD+5, 1);

	//Fix da 3ª asa na lista de personagens
	SetByte(0x004286D3, 0xE9);
	HookThis(GET_ADDR(FixCharListWings), 0x004286D3);
	SetNop(0x004286D3+5, 1);
	SetNop(0x00428D84, 7);

	//Fix do Fenrir na lista de personagens
	SetByte(0x00428DF6, 0xE9);
	HookThis(GET_ADDR(FixCharListFenrir), 0x00428DF6);
	SetNop(0x00428DF6+5, 1);

	HookThis(GET_ADDR(FixCharSet), 0x0040394A);			//Fix CharSet
	
	SetNop(0x0050A4C3, 21);							//Fix Viewport
	SetNop(0x0050A50C, 33);							//Fix Viewport
	SetNop(0x0050B3AB, 18);							//Fix Viewport
	SetNop(0x0050B6CD, 20);							//Fix Viewport
	SetNop(0x0050B719, 33);							//Fix Viewport
	
	//SetWord(0x0053336F, 0x12EB);						//Desabilita Movereq check

	SetWord(0x0050F160, 0x1828);						//Entrar no mapa com as novas asas

	SetByte(0x00527611, 2);							//Habilita nova classe usar equipamentos
	SetByte(0x004953EC, 2);							//Habilita nova classe usar skills
	SetByte(0x0051CD93, false);						//Serial 0 Check - Fix
	
	//Novas Asas lvlup - bless, soul, life
	SetWord(0x00511DFA, 0x1828);
	SetWord(0x00512340, 0x1828);
	SetWord(0x00512B00, 0x1828);

	//Novas asas - luck e opções excelentes
	SetWord(0x00524322, 0x1828);
	SetWord(0x00524BFB, 0x1828);
	SetByte(0x00524523,	0x7D);
	
	//Upar itens até +28 BUGADO
	SetNop(0x0042AE98,2);			// - +28
	SetNop(0x0042AEDC,2);			// - JOL
	SetByte(0x00512CD7, 0x7);		// - +28
	SetByte(0x0042AEE1, 0x7);		// - +28
	
	//Repair asas lvl3
	//BYTE cFix1[7]  ={0xE9,0xEC,0x01,0x00,0x00,0x90,0x90};
	//BYTE cFix2[41] ={0x81,0x7D,0xF0,0x24,0x18,0x00,0x00,0x7C,0x0E,0x81,0x7D,0xF0,0x28,0x1C,0x00,0x00,0x7F,0x05,0xE9,0x2E,0xFE,0xFF,0xFF,0x81,0x7D,0xF0,0x00,0x1C,0x00,0x00,0x0F,0x8D,0x33,0xFE,0xFF,0xFF,0xE9,0xEF,0xFD,0xFF,0xFF};
	//memcpy((BYTE *)0x0043DD6B+0, cFix1 , sizeof(cFix1));
	//memcpy((BYTE *)0x0043DF5C+0, cFix2 , sizeof(cFix2));
	
	
	if(GetPrivateProfileInt("GameServer", "Status_65K_Ativado",1,".\\Data\\GameServer.ini") == 1)
	{
		BYTE ByteFix = 0xB7;
		*(BYTE*)(0x00451C0C+1) = ByteFix;
		*(BYTE*)(0x00451C79+1) = ByteFix;
		*(BYTE*)(0x00499467+1) = ByteFix;
		*(BYTE*)(0x004C381E+1) = ByteFix;
		*(BYTE*)(0x004C3837+1) = ByteFix;
		*(BYTE*)(0x004C3850+1) = ByteFix;
		*(BYTE*)(0x004C3869+1) = ByteFix;
		*(BYTE*)(0x004C3C0B+1) = ByteFix;
		*(BYTE*)(0x004C3C1F+1) = ByteFix;
		*(BYTE*)(0x004C3C33+1) = ByteFix;
		*(BYTE*)(0x004C3C47+1) = ByteFix;
		*(BYTE*)(0x004C3C73+1) = ByteFix;
		*(BYTE*)(0x004C3C87+1) = ByteFix;
		*(BYTE*)(0x004C3C9B+1) = ByteFix;
		*(BYTE*)(0x004C3CAF+1) = ByteFix;
		*(BYTE*)(0x004C3CDC+1) = ByteFix;
		*(BYTE*)(0x004C3CF0+1) = ByteFix;
		*(BYTE*)(0x004C3D04+1) = ByteFix;
		*(BYTE*)(0x004C3D18+1) = ByteFix;
		*(BYTE*)(0x004C3D31+1) = ByteFix;
		*(BYTE*)(0x004C3D45+1) = ByteFix;
		*(BYTE*)(0x004C3D59+1) = ByteFix;
		*(BYTE*)(0x004C3D6D+1) = ByteFix;
		*(BYTE*)(0x004C4644+1) = ByteFix;
		*(BYTE*)(0x004C53C1+1) = ByteFix;
		*(BYTE*)(0x004C6695+1) = ByteFix;
		*(BYTE*)(0x004C6727+1) = ByteFix;
		*(BYTE*)(0x004C6747+1) = ByteFix;
		*(BYTE*)(0x004C704F+1) = ByteFix;
		*(BYTE*)(0x004C8931+1) = ByteFix;
		*(BYTE*)(0x004C8951+1) = ByteFix;
		*(BYTE*)(0x004C89CB+1) = ByteFix;
		*(BYTE*)(0x004C89EB+1) = ByteFix;
		*(BYTE*)(0x004C8C85+1) = ByteFix;
		*(BYTE*)(0x004C8CC8+1) = ByteFix;
		*(BYTE*)(0x004C8D01+1) = ByteFix;
		*(BYTE*)(0x004C8D41+1) = ByteFix;
		*(BYTE*)(0x004C8D80+1) = ByteFix;
		*(BYTE*)(0x004C8DB1+1) = ByteFix;
		*(BYTE*)(0x004C8DEC+1) = ByteFix;
		*(BYTE*)(0x004C8E27+1) = ByteFix;
		*(BYTE*)(0x004C8E62+1) = ByteFix;
		*(BYTE*)(0x004C8E9D+1) = ByteFix;
		*(BYTE*)(0x004CB7DB+1) = ByteFix;
		*(BYTE*)(0x004CB805+1) = ByteFix;
		*(BYTE*)(0x004CBBC7+1) = ByteFix;
		*(BYTE*)(0x004CBBE7+1) = ByteFix;
		*(BYTE*)(0x004CBD95+1) = ByteFix;
		*(BYTE*)(0x004CC026+1) = ByteFix;
		*(BYTE*)(0x004CC800+1) = ByteFix;
		*(BYTE*)(0x004CC942+1) = ByteFix;
		*(BYTE*)(0x004CFD49+1) = ByteFix;
		*(BYTE*)(0x004CFD6C+1) = ByteFix;
		*(BYTE*)(0x004D4C67+1) = ByteFix;
		*(BYTE*)(0x004D4C80+1) = ByteFix;
		*(BYTE*)(0x004D4C99+1) = ByteFix;
		*(BYTE*)(0x004D4CB2+1) = ByteFix;
		*(BYTE*)(0x004D925C+1) = ByteFix;
		*(BYTE*)(0x004D9292+1) = ByteFix;
		*(BYTE*)(0x004D92C8+1) = ByteFix;
		*(BYTE*)(0x004D92FE+1) = ByteFix;
		*(BYTE*)(0x004D9334+1) = ByteFix;
		*(BYTE*)(0x004D9C3C+1) = ByteFix;
		*(BYTE*)(0x004D9C81+1) = ByteFix;
		*(BYTE*)(0x004D9CC6+1) = ByteFix;
		*(BYTE*)(0x004D9D41+1) = ByteFix;
		*(BYTE*)(0x004D9E23+1) = ByteFix;
		*(BYTE*)(0x004D9E39+1) = ByteFix;
		*(BYTE*)(0x004D9E51+1) = ByteFix;
		*(BYTE*)(0x004D9E69+1) = ByteFix;
		*(BYTE*)(0x004DB685+1) = ByteFix;
		*(BYTE*)(0x004DB69E+1) = ByteFix;
		*(BYTE*)(0x004DB6B7+1) = ByteFix;
		*(BYTE*)(0x004DB6D0+1) = ByteFix;
		*(BYTE*)(0x004DCD65+1) = ByteFix;
		*(BYTE*)(0x004DCDA8+1) = ByteFix;
		*(BYTE*)(0x004DCDE1+1) = ByteFix;
		*(BYTE*)(0x004DCE21+1) = ByteFix;
		*(BYTE*)(0x004DCE60+1) = ByteFix;
		*(BYTE*)(0x004DCE91+1) = ByteFix;
		*(BYTE*)(0x004DCECC+1) = ByteFix;
		*(BYTE*)(0x004DCF07+1) = ByteFix;
		*(BYTE*)(0x004DCF42+1) = ByteFix;
		*(BYTE*)(0x004DCF7D+1) = ByteFix;
		*(BYTE*)(0x004E54B2+1) = ByteFix;
		*(BYTE*)(0x004E54D7+1) = ByteFix;
		*(BYTE*)(0x004E5521+1) = ByteFix;
		*(BYTE*)(0x004E670F+1) = ByteFix;
		*(BYTE*)(0x004E67AE+1) = ByteFix;
		*(BYTE*)(0x004E81F0+1) = ByteFix;
		*(BYTE*)(0x004E81FB+1) = ByteFix;
		*(BYTE*)(0x004E8206+1) = ByteFix;
		*(BYTE*)(0x004E8211+1) = ByteFix;
		*(BYTE*)(0x004FA9F6+1) = ByteFix;
		*(BYTE*)(0x004FAA2E+1) = ByteFix;
		*(BYTE*)(0x004FAA9D+1) = ByteFix;
		*(BYTE*)(0x004FAAC7+1) = ByteFix;
		*(BYTE*)(0x00511165+1) = ByteFix;
		*(BYTE*)(0x00511611+1) = ByteFix;
		*(BYTE*)(0x00511B9C+1) = ByteFix;
		*(BYTE*)(0x00515D83+1) = ByteFix;
		*(BYTE*)(0x00515D8D+1) = ByteFix;
		*(BYTE*)(0x00515D99+1) = ByteFix;
		*(BYTE*)(0x00515DA5+1) = ByteFix;
		*(BYTE*)(0x00515FFD+1) = ByteFix;
		*(BYTE*)(0x00516007+1) = ByteFix;
		*(BYTE*)(0x00516013+1) = ByteFix;
		*(BYTE*)(0x0051601F+1) = ByteFix;
		*(BYTE*)(0x0051753F+1) = ByteFix;
		*(BYTE*)(0x00517581+1) = ByteFix;
		*(BYTE*)(0x005175C3+1) = ByteFix;
		*(BYTE*)(0x00517602+1) = ByteFix;
		*(BYTE*)(0x00517FD1+1) = ByteFix;
		*(BYTE*)(0x00518010+1) = ByteFix;
		*(BYTE*)(0x0051804F+1) = ByteFix;
		*(BYTE*)(0x0051808B+1) = ByteFix;
		*(BYTE*)(0x00518AAA+1) = ByteFix;
		*(BYTE*)(0x00518ACD+1) = ByteFix;
		*(BYTE*)(0x00518AF0+1) = ByteFix;
		*(BYTE*)(0x00518B13+1) = ByteFix;
		*(BYTE*)(0x005541CD+1) = ByteFix;
		*(BYTE*)(0x005541E1+1) = ByteFix;
		*(BYTE*)(0x005541F5+1) = ByteFix;
		*(BYTE*)(0x00554209+1) = ByteFix;
		*(BYTE*)(0x005543C6+1) = ByteFix;
		*(BYTE*)(0x005543DA+1) = ByteFix;
		*(BYTE*)(0x005543EE+1) = ByteFix;
		*(BYTE*)(0x00554402+1) = ByteFix;
		*(BYTE*)(0x0055460F+1) = ByteFix;
		*(BYTE*)(0x00554623+1) = ByteFix;
		*(BYTE*)(0x00554637+1) = ByteFix;
		*(BYTE*)(0x0055464B+1) = ByteFix;
		*(BYTE*)(0x005B6EB7+1) = ByteFix;
		*(BYTE*)(0x005B6EC8+1) = ByteFix;
		*(BYTE*)(0x005B6ED9+1) = ByteFix;
		*(BYTE*)(0x005B6EEA+1) = ByteFix;
	}
}