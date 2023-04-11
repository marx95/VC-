#include "StdAfx.h"

void Config()
{
	char NovoSerial[] = "MuOver099Season1";
	char NovaVersao[] = "22345"; // = 1.00.00
	char NovoNome[] = "MuMax!";
	char SSNovo[] = "ScreenShots/MuMax_(%02d_%02d-%02d_%02d)-%04d.jpg";
	_mkdir("ScreenShots");

	//BYTE FixUsoCpu[20] = {0x6A, 0x01, 0xFF, 0x15, 0x5C, 0x61, 0x75, 0x00, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xEB, 0xD1};
	//memset((int*)0x0066248F, 0x00, 20);
	//memcpy((int*)0x0066248F, FixUsoCpu, 20);

	// - Serial do Main
	memset((int*)(0x0066FEF0), 0x00, 17);
	memcpy((int*)(0x0066FEF0), NovoSerial, 17);

	// - Versão do main Exp: 1.00.00
	memset((int*)(0x0066FEE8), 0x00, 6);
	memcpy((int*)(0x0066FEE8), NovaVersao, 6);
	
	// - Nome da Janela
	memcpy((int*)(0x00660FE0), NovoNome, sizeof(NovoNome));
	BYTE NovoJanelaNome[] = {0x68, 0xE0, 0x0F, 0x66, 0x00};
	memcpy((int*)0x004A6FF2, NovoJanelaNome, sizeof(NovoJanelaNome));
	memcpy((int*)0x004A7022, NovoJanelaNome, sizeof(NovoJanelaNome));

	// - Screenshots
	memcpy((int*)(0x00660F9B), SSNovo, sizeof(SSNovo));
	BYTE NovoSSPath[] = {0x68, 0x9B, 0x0F, 0x66, 0x00};
	memcpy((int*)0x0060BE08, NovoSSPath, sizeof(NovoSSPath));

	// - Acentuação no main
	memset((int*)(0x0066F318), 0xA0, 1);

	// - Resoluções
	int Width  = GetPrivateProfileIntA("Config","Width", 800,".\\Config.ini");
	int Height = GetPrivateProfileIntA("Config","Height", 600,".\\Config.ini");

	if(Width < 640 || Width > 1920) Width = 640;
	if(Height < 480 || Height > 1080) Height = 480;
	
	*(unsigned int*)(0x004A750E+6) = Width;
	*(unsigned int*)(0x004A7524+6) = Width;
	*(unsigned int*)(0x004A753A+6) = Width;
	*(unsigned int*)(0x004A7550+6) = Width;
	*(unsigned int*)(0x004A7566+6) = Width;

	*(unsigned int*)(0x004A7518+6) = Height;
	*(unsigned int*)(0x004A752E+6) = Height;
	*(unsigned int*)(0x004A7544+6) = Height;
	*(unsigned int*)(0x004A755A+6) = Height;
	*(unsigned int*)(0x004A7570+6) = Height;
	
	int Tamanho_Fonte = GetPrivateProfileIntA("Config","Tamanho_da_Fonte", 12,".\\Config.ini");
	BYTE FixFonte[4] = {0x6A, 0x05, 0x90, 0x90};
	FixFonte[1] = Tamanho_Fonte;

	// - Fonte com Normal #1
	memcpy((BYTE*)0x004A85E2, FixFonte, 4);

	// - Fonte com Bold #1
	memcpy((BYTE*)0x004A8623, FixFonte, 4);

	// - Fonte com Bold 2 - Este Fix é maior
	memset((BYTE*)0x004A8664, 0x90, 6);
	memcpy((BYTE*)0x004A8664, FixFonte, 4);
	
	
	// - Liberar Itens
	
	*(BYTE*)(0x005E3C27+2) = 0x20; // Sword 
	*(BYTE*)(0x005E3D48+2) = 0x20; // Axe
	*(BYTE*)(0x005E3D73+2) = 0x20; // Mace
	*(BYTE*)(0x005E3DB7+2) = 0x20; // Mace
	*(BYTE*)(0x005E3DE2+2) = 0x20; // Spear
	*(BYTE*)(0x005E3E26+2) = 0x20; // Spear
	*(BYTE*)(0x005E3E80+2) = 0x20; // Staff
	*(BYTE*)(0x005E3F43+2) = 0x20; // Bow

	// - Texturas
	*(BYTE*)(0x005E4D15+2) = 0x20;
	*(BYTE*)(0x005E4FA9+2) = 0x20;
	*(BYTE*)(0x005E4FD1+2) = 0x20;
	*(BYTE*)(0x005E4FF9+2) = 0x20;
	*(BYTE*)(0x005E5042+2) = 0x20;
	*(BYTE*)(0x005E5095+2) = 0x20;
	*(BYTE*)(0x005E520A+2) = 0x20;
	*(BYTE*)(0x005E5232+2) = 0x20;
	*(BYTE*)(0x005E525A+2) = 0x20;
	*(BYTE*)(0x005E4F7A+2) = 0x20;

	//*(BYTE*)(0x005E3F6E+2) = 0x50; // Crossbow
	//*(BYTE*)(0x005E4827+2) = 0x20; // Wing Lv1
	//*(BYTE*)(0x005E48E8+2) = 0x20; // Wing Lv2
	/*
	*(BYTE*)(0x005E21A8+2) = 0x50; // #1 HelmMale, ArmorMale, PantMale, GlooveMale, BootMale
	*(BYTE*)(0x005E26A5+2) = 0x50; // #2 HelmMale, ArmorMale, PantMale, GlooveMale, BootMale
	*(BYTE*)(0x005E2732+2) = 0x50; // #3 HelmMale, ArmorMale, PantMale, GlooveMale, BootMale
	*(BYTE*)(0x005E27B4+2) = 0x50; // #4 HelmMale, ArmorMale, PantMale, GlooveMale, BootMale
	*(BYTE*)(0x005E2226+2) = 0x50; // HelfElf, ArmorElf, PantElf, GlooveElf, BootElf
	*(BYTE*)(0x005E260E+2) = 0x50; // HelmMaleTest, ArmorMaleTest, PantMaleTest, GlooveMaleTest, BootMaleTest
	
	*(BYTE*)(0x005E2E16+2) = 0x50;
	*(BYTE*)(0x005E2EB0+2) = 0x50;
	*(BYTE*)(0x005E212A+2) = 0x50;
	*/
	// - File Corrupt Fix
	*(BYTE*)(0x0040ABE3) = 0xEB;
	*(BYTE*)(0x0040ADD6) = 0xEB;
	*(BYTE*)(0x0052AC84) = 0xEB;
	*(BYTE*)(0x0052AFC4) = 0xEB;
	*(BYTE*)(0x0052BBA3) = 0xEB;
	*(BYTE*)(0x0052C8A3) = 0xEB;
	*(BYTE*)(0x005EC843) = 0xEB;
	*(BYTE*)(0x005EC91D) = 0xEB;
	*(BYTE*)(0x005EC9CC) = 0xEB;
	
}