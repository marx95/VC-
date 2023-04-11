#include "StdAfx.h"

AntiHackStruct AntiHack;
HacksStruct Hack[256];

int HackDetectado			= 0;
int HackID					= 0;
int TotalHacks				= 193;
long Player_BMD_CRC			= -920371964;
long Terrain1_ATT_CRC		= 535145003;
long Main_EXE_CRC			= -1800687343;
char CmdLine[]				= "MarxD_Munovus_AntiHack2";

void Carrega_Lista_Hack()
{
	sprintf_s(Hack[0].Nome, "%s", "MuCheat");
	sprintf_s(Hack[1].Nome, "%s", "CharBlaster");
	sprintf_s(Hack[2].Nome, "%s", "VaultBlaster");
	sprintf_s(Hack[3].Nome, "%s", "MuPie");
	sprintf_s(Hack[4].Nome, "%s", "CapoteCheat(Elismar)");
	sprintf_s(Hack[5].Nome, "%s", "Ultimate Cheat II ");
	sprintf_s(Hack[6].Nome, "%s", "MUVNBOT");
	sprintf_s(Hack[7].Nome, "%s", "Ultimate Mu Philipines Cheat II");
	sprintf_s(Hack[8].Nome, "%s", "Chaos Bot 2.1.0");
	sprintf_s(Hack[9].Nome, "%s", "FunnyHacking v.0.3");
	sprintf_s(Hack[10].Nome, "%s", "Danger Write Address v1.0");
	sprintf_s(Hack[11].Nome, "%s", "Speed Hack Simplifier");
	sprintf_s(Hack[12].Nome, "%s", "Lucifer's WRath");
	sprintf_s(Hack[13].Nome, "%s", "SpeedHack");
	sprintf_s(Hack[14].Nome, "%s", "WildProxyS3 EP2");
	sprintf_s(Hack[15].Nome, "%s", "Version 2.0 Bot and Doku");
	sprintf_s(Hack[16].Nome, "%s", "Destroyer v1.1");
	sprintf_s(Hack[17].Nome, "%s", "ZhyperMU Main.exe [W/o Protection]");
	sprintf_s(Hack[18].Nome, "%s", "ultimatecheat_mobius");
	sprintf_s(Hack[19].Nome, "%s", "Hastymu ver0.2");
	sprintf_s(Hack[20].Nome, "%s", "Catastrphe");
	sprintf_s(Hack[21].Nome, "%s", "HastyMu ver0.1.4");
	sprintf_s(Hack[22].Nome, "%s", "Speed Hack by Ziomal ver0.8");
	sprintf_s(Hack[23].Nome, "%s", "wildproxy01");
	sprintf_s(Hack[24].Nome, "%s", "wildproxy02");
	sprintf_s(Hack[25].Nome, "%s", "Travis Minimizer");
	sprintf_s(Hack[26].Nome, "%s", "Spiff MU Launcher");
	sprintf_s(Hack[27].Nome, "%s", "SpeedHack97x");
	sprintf_s(Hack[28].Nome, "%s", "Pinnacle");
	sprintf_s(Hack[29].Nome, "%s", "MuBot");
	sprintf_s(Hack[30].Nome, "%s", "Hit Hack+Main");
	sprintf_s(Hack[31].Nome, "%s", "HCC");
	sprintf_s(Hack[32].Nome, "%s", "Hahamu ver1.6");
	sprintf_s(Hack[33].Nome, "%s", "AutoRepair ver1.10");
	sprintf_s(Hack[34].Nome, "%s", "AutoClicker ver3");
	sprintf_s(Hack[35].Nome, "%s", "AEbot");
	sprintf_s(Hack[36].Nome, "%s", "99.62t simply Hack");
	sprintf_s(Hack[37].Nome, "%s", "Catastrophe v0.");
	sprintf_s(Hack[38].Nome, "%s", "WPePro");
	sprintf_s(Hack[39].Nome, "%s", "Permit");
	sprintf_s(Hack[40].Nome, "%s", "T Search");
	sprintf_s(Hack[41].Nome, "%s", "Speed Gear");
	sprintf_s(Hack[42].Nome, "%s", "WildProxy v1.0");
	sprintf_s(Hack[43].Nome, "%s", "WildProxy v0.");
	sprintf_s(Hack[44].Nome, "%s", "Speed Hack Simplifier 1.0");
	sprintf_s(Hack[45].Nome, "%s", "Speed Hack Simplifier 1.");
	sprintf_s(Hack[46].Nome, "%s", "Cheat Happens v3.9b");
	sprintf_s(Hack[47].Nome, "%s", "!xSpeed.net");
	sprintf_s(Hack[48].Nome, "%s", "!xSpeed.net 6");
	sprintf_s(Hack[49].Nome, "%s", "Cheat Engine 5.");
	sprintf_s(Hack[50].Nome, "%s", "UoPilot");
	sprintf_s(Hack[51].Nome, "%s", "Speed Hack 99.62t");
	sprintf_s(Hack[52].Nome, "%s", "SpotHack 1.1");
	sprintf_s(Hack[53].Nome, "%s", "MJB Perfect DL Bot");
	sprintf_s(Hack[54].Nome, "%s", "HahaMu 1.16");
	sprintf_s(Hack[55].Nome, "%s", "Game Speed Changer");
	//sprintf_s(Hack[56].Nome, "%s", "eXpLoRer");
	sprintf_s(Hack[57].Nome, "%s", "Xelerator 1.4");
	sprintf_s(Hack[58].Nome, "%s", "Capotecheat(deltacholl)");
	sprintf_s(Hack[59].Nome, "%s", "Cheat4Fun v0.9 Beta");
	sprintf_s(Hack[60].Nome, "%s", "AutoBuff D-C");
	sprintf_s(Hack[61].Nome, "%s", "HastyMu v0.");
	sprintf_s(Hack[62].Nome, "%s", "HastyMu 1.1.0");
	sprintf_s(Hack[63].Nome, "%s", "MuPie HG");
	sprintf_s(Hack[64].Nome, "%s", "Lipsum");
	sprintf_s(Hack[65].Nome, "%s", "FunnyZhyper v5");
	sprintf_s(Hack[66].Nome, "%s", "MuPie v2 Beta");
	sprintf_s(Hack[67].Nome, "%s", "Auto_Buff v5 Hack Rat");
	sprintf_s(Hack[68].Nome, "%s", "Auto_Buff v9 Hack Rat");
	//sprintf_s(Hack[69].Nome, "%s", "Minimizer");
	sprintf_s(Hack[70].Nome, "%s", "AE/HYBRID AEBOT 0.9");
	sprintf_s(Hack[71].Nome, "%s", "Jewel Drop Beta");
	sprintf_s(Hack[72].Nome, "%s", "Chaos Bot 2.1.0");
	sprintf_s(Hack[73].Nome, "%s", "MU-SS4 Speed Hack 1.2");
	sprintf_s(Hack[74].Nome, "%s", "Bot MG-DK-ELF");
	sprintf_s(Hack[75].Nome, "%s", "Comercio Bot");
	sprintf_s(Hack[76].Nome, "%s", "Dizzys Auto Buff");
	sprintf_s(Hack[77].Nome, "%s", "GodMode");
	sprintf_s(Hack[78].Nome, "%s", "Mu Cheater 16");
	sprintf_s(Hack[79].Nome, "%s", "MU Utilidades");
	sprintf_s(Hack[80].Nome, "%s", "MuBot");
	sprintf_s(Hack[81].Nome, "%s", "Snd Bot 1.5");
	sprintf_s(Hack[82].Nome, "%s", "SpotHack 1.1");
	sprintf_s(Hack[83].Nome, "%s", "Godlike");
	sprintf_s(Hack[84].Nome, "%s", "Mu Philiphinas Cheat II");
	sprintf_s(Hack[85].Nome, "%s", "ZhyperMu Packet Editor");
	sprintf_s(Hack[86].Nome, "%s", "D-C DupeHack 1.0");
	sprintf_s(Hack[87].Nome, "%s", "Auto Combo");
	sprintf_s(Hack[88].Nome, "%s", "AIO Bots (Collection)");
	sprintf_s(Hack[89].Nome, "%s", "Nsauditor 1.9.1 (Packet Tool)");
	sprintf_s(Hack[90].Nome, "%s", "Super Bot");
	sprintf_s(Hack[91].Nome, "%s", "!xSpeedPro");
	sprintf_s(Hack[92].Nome, "%s", "Game Speed Changer");
	sprintf_s(Hack[93].Nome, "%s", "Speed Hack 99.62t");
	sprintf_s(Hack[94].Nome, "%s", "GOLD&Dupe 97d");
	sprintf_s(Hack[95].Nome, "%s", "D-C Bypass Public Version");
	sprintf_s(Hack[96].Nome, "%s", "Ultimate Cheat");
	sprintf_s(Hack[97].Nome, "%s", "ArtMoney SE v7.31");
	sprintf_s(Hack[98].Nome, "%s", "JoyToKey");
	sprintf_s(Hack[99].Nome, "%s", "codez");
	sprintf_s(Hack[100].Nome, "%s", "Novo Minimize");
	sprintf_s(Hack[101].Nome, "%s", "Mush");
	sprintf_s(Hack[102].Nome, "%s", "NoNameMini");
	sprintf_s(Hack[103].Nome, "%s", "Tablet2");
	sprintf_s(Hack[104].Nome, "%s", "Dupe-Full");
	sprintf_s(Hack[105].Nome, "%s", "Razor_Code");
	sprintf_s(Hack[106].Nome, "%s", "Process Explorer 11.33");
	sprintf_s(Hack[107].Nome, "%s", "Perfect AutoPotion");
	sprintf_s(Hack[108].Nome, "%s", "ModzMu");
	sprintf_s(Hack[109].Nome, "%s", "Injector");
	sprintf_s(Hack[110].Nome, "%s", "Hit Count");
	sprintf_s(Hack[111].Nome, "%s", "GPROXY");
	sprintf_s(Hack[112].Nome, "%s", "Mu Bypassor 1.0.0.0");
	sprintf_s(Hack[113].Nome, "%s", "Hide Toolz 2.1");
	sprintf_s(Hack[114].Nome, "%s", "Mu MultiHack 97+99 by Hack-RaT");
	sprintf_s(Hack[115].Nome, "%s", "Mensajes_JoinServer_Spa");
	sprintf_s(Hack[116].Nome, "%s", "CapoteCheat(deltacholl)");
	sprintf_s(Hack[117].Nome, "%s", "Redox Packer Editor");
	sprintf_s(Hack[118].Nome, "%s", "Game Gears 2009");
	sprintf_s(Hack[119].Nome, "%s", "Game Speed Adjuster 1.0");
	sprintf_s(Hack[120].Nome, "%s", "SpeederXP 1.80");
	sprintf_s(Hack[121].Nome, "%s", "SpeederXP 2.");
	sprintf_s(Hack[122].Nome, "%s", "Game Speeder 1.0");
	sprintf_s(Hack[123].Nome, "%s", "Game Speed Changer 6.3");
	sprintf_s(Hack[124].Nome, "%s", "Game Speed Controller 1.0.0.1");
	sprintf_s(Hack[125].Nome, "%s", "GameWiz32 1.43");
	sprintf_s(Hack[126].Nome, "%s", "Quick Maro 6.60");
	sprintf_s(Hack[127].Nome, "%s", "Xelerator 2.0");
	sprintf_s(Hack[128].Nome, "%s", "Speed Gear 7.");
	sprintf_s(Hack[129].Nome, "%s", "A Speeder 2008.4.265010");
	sprintf_s(Hack[130].Nome, "%s", "Crazy Speeder 1.05");
	sprintf_s(Hack[131].Nome, "%s", "Quick Memory Editor 5.5");
	sprintf_s(Hack[132].Nome, "%s", "ArtMoney SE v7.3");
	sprintf_s(Hack[133].Nome, "%s", "Ultimate Global Mu Online Cheat II");
	sprintf_s(Hack[134].Nome, "%s", "Snd.Bot 1.8");
	sprintf_s(Hack[135].Nome, "%s", "Mu Proxy 1.0");
	sprintf_s(Hack[136].Nome, "%s", "Speed Hack by Ziomal 0.8");
	sprintf_s(Hack[137].Nome, "%s", "G-Unot v.1");
	sprintf_s(Hack[138].Nome, "%s", "G-Unot v.2");
	sprintf_s(Hack[139].Nome, "%s", "Bypass");
	sprintf_s(Hack[140].Nome, "%s", "MU Proxy Packet Editor v.1.0");
	sprintf_s(Hack[141].Nome, "%s", "D-C Utiles By Wanted");
	sprintf_s(Hack[142].Nome, "%s", "[Hasty MU v0.3] - Plus Thai");
	sprintf_s(Hack[143].Nome, "%s", "Cheat Para MuEasy Dupe de itens.Desenvolvido por LoukoWH!");
	sprintf_s(Hack[144].Nome, "%s", "Mu Online Gold Hack");
	sprintf_s(Hack[145].Nome, "%s", "WwW.TuX-Hack.NeT");
	sprintf_s(Hack[146].Nome, "%s", "www.webcheats.com.br");
	sprintf_s(Hack[147].Nome, "%s", "Web Cheats Atualizador 16/05");
	sprintf_s(Hack[148].Nome, "%s", "process Hacker");
	sprintf_s(Hack[149].Nome, "%s", "doshttp");
	sprintf_s(Hack[150].Nome, "%s", "decompiler");
	sprintf_s(Hack[151].Nome, "%s", "modzmu");
	sprintf_s(Hack[152].Nome, "%s", "spy++");
	sprintf_s(Hack[153].Nome, "%s", "biatch");
	sprintf_s(Hack[154].Nome, "%s", "MoonLight Engine");
	sprintf_s(Hack[155].Nome, "%s", "ant ban");
	sprintf_s(Hack[156].Nome, "%s", "dark team");
	sprintf_s(Hack[157].Nome, "%s", "sistema de login");
	sprintf_s(Hack[158].Nome, "%s", "full item");
	sprintf_s(Hack[159].Nome, "%s", "muproxy");
	sprintf_s(Hack[160].Nome, "%s", "xelerator");
	sprintf_s(Hack[161].Nome, "%s", "visual basic");
	sprintf_s(Hack[162].Nome, "%s", "delphi");
	sprintf_s(Hack[163].Nome, "%s", "speed Hack");
	sprintf_s(Hack[164].Nome, "%s", "dupe Hack");
	//sprintf_s(Hack[165].Nome, "%s", "Hack");
	sprintf_s(Hack[166].Nome, "%s", "guild Hack");
	sprintf_s(Hack[167].Nome, "%s", "v7.33");
	sprintf_s(Hack[168].Nome, "%s", "move Hack");
	sprintf_s(Hack[169].Nome, "%s", "trainer");
	sprintf_s(Hack[170].Nome, "%s", "sysinternals");
	sprintf_s(Hack[171].Nome, "%s", "process explorer");
	sprintf_s(Hack[172].Nome, "%s", "hastymu");
	sprintf_s(Hack[173].Nome, "%s", "ViCtor_5");
	sprintf_s(Hack[174].Nome, "%s", "artmoney");
	sprintf_s(Hack[175].Nome, "%s", "webHacke");
	sprintf_s(Hack[176].Nome, "%s", "speeder");
	sprintf_s(Hack[177].Nome, "%s", "ocult process");
	sprintf_s(Hack[178].Nome, "%s", "wpe");
	sprintf_s(Hack[179].Nome, "%s", "t engine");
	sprintf_s(Hack[180].Nome, "%s", "injeti");
	sprintf_s(Hack[181].Nome, "%s", "WebMaste-Hack");
	sprintf_s(Hack[182].Nome, "%s", "winsock packet");
	sprintf_s(Hack[183].Nome, "%s", "force Hacke");
	sprintf_s(Hack[184].Nome, "%s", "mu Hack editor");
	sprintf_s(Hack[185].Nome, "%s", "Hack-Master");
	sprintf_s(Hack[186].Nome, "%s", "Hacker team");
	sprintf_s(Hack[187].Nome, "%s", "akuma");
	sprintf_s(Hack[188].Nome, "%s", "trapaceador");
	sprintf_s(Hack[189].Nome, "%s", "adjuster");
	sprintf_s(Hack[190].Nome, "%s", "packet");
	sprintf_s(Hack[191].Nome, "%s", "saruen");
	sprintf_s(Hack[192].Nome, "%s", "Revolution Master");
	sprintf_s(Hack[193].Nome, "%s", "flood");
	//sprintf_s(Hack[].Nome, "%s",	"");

	for(int i = 0; i < TotalHacks; i++)
	{
		if(strlen(Hack[i].Nome) > 2)
		{
			Hack[i].Ativado = 1;
			sprintf_s(Hack[i].Nome, "%s", Deixar_Minusculo(Hack[i].Nome));
		}else
		{
			Hack[i].Ativado = 0;
		}
	}
}

void Hack_Detectado(char * TituloSplash, char * MsgInfo, char * Detectado)
{
	HackDetectado = 1;
	char TmpSplash[1024];

	sprintf_s(TmpSplash, "AntiHack.exe MarxD_Munovus_AntiHack2#1#%s#%s#%s", TituloSplash, MsgInfo, Detectado);
	WinExec(TmpSplash, 0);
	ExitProcess(0);
}

void Verificar_Crc_Data()
{
	while(true)
	{
		if(HackDetectado == 1) ExitThread(0);
		int Erro = 0;
		if(PegarCheckSum("Main.exe") != Main_EXE_CRC)								Erro = 1;
		if(PegarCheckSum(".\\Data\\Player\\Player.bmd") != Player_BMD_CRC)			Erro = 2;
		if(PegarCheckSum(".\\Data\\World1\\EncTerrain1.att") != Terrain1_ATT_CRC)	Erro = 3;
		switch(Erro)
		{
			case 0: Sleep(1000); break;
			case 1: Hack_Detectado("Modificação do Cliente", "O arquivo 'Main.exe' foi modificado. Abra o Launcher e espere atualizar. Caso ocorra novamente, fale com a nossa equipe pelo Forum.", "Modificação do Main.exe"); break;
			case 2: Hack_Detectado("Modificação do Cliente", "O arquivo 'Player.bmd' foi modificado. Abra o Launcher e espere atualizar. Caso ocorra novamente, fale com a nossa equipe pelo Forum.", "Modificação do Player.bmd"); break;
			case 3: Hack_Detectado("Modificação do Cliente", "O arquivo 'EncTerrain1.att' foi modificado. Abra o Launcher e espere atualizar. Caso ocorra novamente, fale com a nossa equipe pelo Forum.", "Modificação do EncTerrain1.att"); break;
		}
	}
}

void Verificar_Hacks()
{
	for(int i = 0; i < TotalHacks; i++)
	{
		if(Hack[i].Ativado == 1)
		{
			if(Procurar(AntiHack.Janela_Topo, Hack[i].Nome, false))
			{
				char Detectado[512];
				sprintf_s(Detectado, "%s$$%s", Hack[i].Nome, AntiHack.Janela_Topo);
				Hack_Detectado("Hack Detectado", "Foi detectado um aplicativo ilegal e o jogo foi fechado.", Detectado);
				ExitThread(0);
			}
		}
	}
}

void AntiHack_Check()
{
    while(true)
	{
		if(HackDetectado == 1) ExitThread(0);
		Pegar_Nome_Janela_Topo();
		if(Procurar(AntiHack.Janela_Topo, "munovus.net", false))
		{
			Sleep(1000);
		}else
		{
			Verificar_Hacks();
			Sleep(150);
		}
	}
}

bool VerificarCmdLine()
{
	if(Procurar(GetCommandLine(), "Palio", true)) return true;
	if(!Procurar(GetCommandLine(), CmdLine, true)) return false;
	return true;
}

void Iniciar_Anti_Hack()
{
	if(!VerificarCmdLine()) ExitProcess(0);
	Carrega_Lista_Hack();
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(Verificar_Crc_Data),NULL,0,0);
	CreateThread(NULL,NULL,LPTHREAD_START_ROUTINE(AntiHack_Check),NULL,0,0);
}