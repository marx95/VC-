#include "StdAfx.h"

void Config()
{
	char NovoIp[]			= "192.168.0.10";
	char NovoSerial[]		= "MarxDMuNovus104J";
	char NovaVersao[]		= "2274=";
	char NovoNome[]			= "MuOver.net";
	char SSNovo[]			= "ScreenShots/MuOver_(%02d_%02d-%02d_%02d)-%04d.jpg";
	_mkdir("ScreenShots");

	BYTE FixUsoCpu[20] = {0x6A, 0x01, 0xFF, 0x15, 0x5C, 0x61, 0x75, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xEB, 0xD1};
	memset((int*)0x0066248F, 0x00, 20);
	memcpy((int*)0x0066248F, FixUsoCpu, 20);

	DWORD* MainIpOffset = (DWORD*)(0x0076E2EF+1);
	memset(&MainIpOffset[0], 0x00, 16);
	memcpy(&MainIpOffset[0], NovoIp, 14);

	DWORD* MainSerialOffset = (DWORD*)(0x0077F527+1);
	memset(&MainSerialOffset[0], 0x00, 17);
	memcpy(&MainSerialOffset[0], NovoSerial, 17);


	DWORD* MainVersaoOffset = (DWORD*)(0x0077F51F+1);
	memset(&MainVersaoOffset[0], 0x00, 6);
	memcpy(&MainVersaoOffset[0], NovaVersao, 6);

	DWORD* NomeJanelaOffset = (DWORD*)(0x0077E738);
	memset(&NomeJanelaOffset[0], 0x00, 14);
	memcpy(&NomeJanelaOffset[0], NovoNome, 14);

	DWORD* ScreenShotsOffset = (DWORD*)(0x00755F00);
	memset(&ScreenShotsOffset[0], 0x00, 60);
	memcpy(&ScreenShotsOffset[0], SSNovo, 60);

	// - Resoluções
	int Width  = GetPrivateProfileIntA("Config","Width", 800,".\\Config.ini");
	int Height = GetPrivateProfileIntA("Config","Height", 600,".\\Config.ini");

	if(Width < 800 || Width > 1920) Width = 800;
	if(Height < 600 || Height > 1080) Height = 600;

	*(unsigned int*)(0x00648006+6) = Width;
	*(unsigned int*)(0x0064801C+6) = Width;
	*(unsigned int*)(0x00648032+6) = Width;
	*(unsigned int*)(0x00648048+6) = Width;
	*(unsigned int*)(0x0064805E+6) = Width;

	*(unsigned int*)(0x00648010+6) = Height;
	*(unsigned int*)(0x00648026+6) = Height;
	*(unsigned int*)(0x0064803C+6) = Height;
	*(unsigned int*)(0x00648052+6) = Height;
	*(unsigned int*)(0x00648068+6) = Height;

	int Tamanho_Fonte = GetPrivateProfileIntA("Config","Tamanho_da_Fonte", 12,".\\Config.ini");
	BYTE FixFonte[8] = {0x6A, 0x05, 0xFF, 0x15, 0x88, 0x60, 0x75, 0x00};

	// - Fonte com Bold #1
	memset((BYTE*)0x00405C79, 0x90, 10);
	memcpy((BYTE*)0x00405C79, FixFonte, 8);
	*(BYTE*)(0x00405C79+1) = Tamanho_Fonte;

	// - Fonte com Bold #2
	memset((BYTE*)0x00649420, 0x90, 10);
	memcpy((BYTE*)0x00649420, FixFonte, 8);
	*(BYTE*)(0x00649420+1) = Tamanho_Fonte;

	// - Fonte com Bold #3
	memset((BYTE*)0x00649486, 0x90, 12);
	memcpy((BYTE*)0x00649486, FixFonte, 8);
	*(BYTE*)(0x00649486+1) = Tamanho_Fonte;

	// - Fontes Sem Bold #1
	memset((BYTE*)0x006493B9, 0x90, 10);
	memcpy((BYTE*)0x006493B9, FixFonte, 8);
	*(BYTE*)(0x006493B9+1) = Tamanho_Fonte;

	// - Fontes Sem Bold #2
	memset((BYTE*)0x006494EF, 0x90, 13);
	memcpy((BYTE*)0x006494EF, FixFonte, 8);
	*(BYTE*)(0x006494EF+1) = Tamanho_Fonte;

	// - File Corrupted
	*(BYTE*)(0x00496F7A) = 0xEB;
	*(BYTE*)(0x004971AF) = 0xEB;
	*(BYTE*)(0x00533296) = 0xEB;
	*(BYTE*)(0x0053362C) = 0xEB;
	*(BYTE*)(0x00534114) = 0xEB;
	*(BYTE*)(0x00534E7A) = 0xEB;
	*(BYTE*)(0x006397B4) = 0xEB;
	*(BYTE*)(0x006399A7) = 0xEB;
	*(BYTE*)(0x00639A4A) = 0xEB;
	
	return;
	BYTE bosta[6] = {0xF, 0x85, 0x25, 0x01, 0x00, 0x00};
	*(BYTE*)(0x0062B633) = 0xC3;
	memcpy((int*)0x0062B633, bosta, 6);

	//LoadModel(ITEMGET(0, 28),	"Data\\Item", "Sword29",			-1);

	/*
	// - Novos Itens
	BYTE FixItems		   = 0x1F;
	*(BYTE*)(0x0062D612+3) = FixItems; // - swords - 11
	*(BYTE*)(0x0062D6E5+3) = FixItems; // - axe - 9
	*(BYTE*)(0x0062D722+3) = FixItems; // - mace - 7
	*(BYTE*)(0x0062D778+3) = FixItems; // - mace 2 - 5
	*(BYTE*)(0x0062D7CE+3) = FixItems; // - spear - 0A
	*(BYTE*)(0x0062D824+3) = FixItems; // - shields - 0F
	*(BYTE*)(0x0062D893+3) = FixItems; // - staffs - 0x9
	*(BYTE*)(0x0062D91B+3) = FixItems; // - bow - 7
	*(BYTE*)(0x0062D958+3) = FixItems; // - crowssbow - 7
	
	BYTE FixSetItems	   = 0x1E;
	*(BYTE*)(0x0062BB1A+3) = FixSetItems; 	 //helmmale
	*(BYTE*)(0x0062BEE1+3) = FixSetItems;   //helmmale 2
	*(BYTE*)(0x0062BFDB+3) = FixSetItems;   //helmmale 3
	*(BYTE*)(0x0062C0B0+3) = FixSetItems;   //helmmale 4
	
	BYTE FixTextItems	 = 0x1E;
	//*(BYTE*)(0x0062E944+3) = FixTextItems;
	//*(BYTE*)(0x0062EA1E+3) = FixTextItems;
	//*(BYTE*)(0x0062EC1F+3) = FixTextItems;
	//*(BYTE*)(0x0062ECF2+3) = FixTextItems;
	//*(BYTE*)(0x0062ED4D+3) = FixTextItems;
	*(BYTE*)(0x0062EEB5+3) = FixTextItems; // - Swords - 11
	*(BYTE*)(0x0062CD22+3) = FixTextItems; // - ?? - 11
	//*(BYTE*)(0x0062F053+3) = FixTextItems;
	//*(BYTE*)(0x0062F0CD+3) = FixTextItems;
	//*(BYTE*)(0x0062F127+3) = FixTextItems;
	//*(BYTE*)(0x0062F164+3) = FixTextItems;
	//*(BYTE*)(0x0062F1BF+3) = FixTextItems;
	//*(BYTE*)(0x0062F327+3) = FixTextItems;
	///*(BYTE*)(0x0062F364+3) = FixTextItems;
	//*(BYTE*)(0x0062F3A1+3) = FixTextItems;
	//*(BYTE*)(0x0062F3DD+3) = FixTextItems;

	
	*(BYTE*)(0x0062B89D+3) = 0x50;   //helmclass
	*(BYTE*)(0x0062B969+3) = 0x50;   //helmclass2
	*(BYTE*)(0x0062BA4C+3) = 0x50;   //helmclass3
	*(BYTE*)(0x0062BBE8+3) = 0x50;   //helmelf
	*(BYTE*)(0x0062BE15+3) = 0x50;   //helmmaletest
	*/
}