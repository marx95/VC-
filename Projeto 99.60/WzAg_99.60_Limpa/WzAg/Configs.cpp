#include "StdAfx.h"

void Ler_GSC()
{
	GetPrivateProfileStringA("GameServerInfo","ServerName","MarxD_GS_99.60T", GS.Nome_Sala, 10, ".\\Data\\ServerInfo.dat");
	GetPrivateProfileStringA("GameServerInfo","ClientExeSerial","ServidorMuOnline", GS.Main_Serial, 20, "..\\Data\\Lang\\Chs\\commonloc.cfg");
	GetPrivateProfileStringA("GameServerInfo","ClientExeVersion","1.00.00", GS.Main_Version, 10, "..\\Data\\Lang\\Chs\\commonloc.cfg");

	GetPrivateProfileStringA("GameServer","Msg_lateral","MarxD_GS_99.60T", GS.MsgLateral, 64, ".\\Data\\GameServer.ini");
	GetPrivateProfileStringA("GameServer","Msg_Central","MarxD_GS_99.60T", GS.MsgCentro, 64, ".\\Data\\GameServer.ini");

	GS.Porta_UDP		= GetPrivateProfileIntA("GameServerInfo", "UDP_Port", 60006, ".\\Data\\ServerInfo.dat");
	GS.Level_Maximo		= GetPrivateProfileIntA("GameServer", "Level_Maximo", 400, ".\\Data\\GameServer.ini");
	GS.ShadowP_LevelMax	= GetPrivateProfileIntA("GameServer", "Level_Maximo_Elf_Buffer", 400, ".\\Data\\GameServer.ini");

	GS.Ativar_DanoReflete= GetPrivateProfileIntA("GameServer", "Dano_Reflete_Ativado", 0, ".\\Data\\GameServer.ini");
	GS.Setar_Zen_ao_Logar= GetPrivateProfileIntA("GameServer", "Setar_Zen_ao_Logar", 0, ".\\Data\\GameServer.ini");
	GS.Log = GetPrivateProfileIntA("GameServer", "Log_Ativado", 1, ".\\Data\\GameServer.ini");
	
	GS.Kundun_MaxItens	= GetPrivateProfileIntA("GameServer", "Nr_de_Itens_ao_Matar_o_Kundun", 3, ".\\Data\\GameServer.ini");
	if(GS.Kundun_MaxItens < 0 || GS.Kundun_MaxItens > 10) GS.Kundun_MaxItens = 3;

	GS.DV_CtlCode			= GetPrivateProfileIntA("GameServer", "Divulgador_CtlCode", 26, ".\\Data\\GameServer.ini");
	GS.GM_CtlCode			= GetPrivateProfileIntA("GameServer", "GameMaster_CtlCode", 28, ".\\Data\\GameServer.ini");
	GS.SUB_CtlCode			= GetPrivateProfileIntA("GameServer", "Sub-Administrador_CtlCode", 30, ".\\Data\\GameServer.ini");
	GS.ADM_CtlCode			= GetPrivateProfileIntA("GameServer", "Adminsitrador_CtlCode", 32, ".\\Data\\GameServer.ini");
	GS.ADM_Player_CtlCode	= GetPrivateProfileIntA("GameServer", "Adminsitrador_Jogador_CtlCode", 34, ".\\Data\\GameServer.ini");

	GS.Limite_Pontos[0]	= GetPrivateProfileIntA("DW_SM", "Limite_Pontos", 32767, ".\\Data\\Classes.ini");
	GS.Limite_Pontos[1]	= GetPrivateProfileIntA("DK_BK", "Limite_Pontos", 32767, ".\\Data\\Classes.ini");
	GS.Limite_Pontos[2]	= GetPrivateProfileIntA("Elf_ME", "Limite_Pontos", 32767, ".\\Data\\Classes.ini");
	GS.Limite_Pontos[3]	= GetPrivateProfileIntA("MG", "Limite_Pontos", 32767, ".\\Data\\Classes.ini");
	GS.Limite_Pontos[4]	= GetPrivateProfileIntA("DL", "Limite_Pontos", 32767, ".\\Data\\Classes.ini");

	GS.Mix_Asa1			= GetPrivateProfileIntA("GameServer", "Mix_Asa_Level_1", 100, ".\\Data\\GameServer.ini");
	GS.Mix_Asa2			= GetPrivateProfileIntA("GameServer", "Mix_Asa_Level_1", 100, ".\\Data\\GameServer.ini");
	GS.Mix_ItemChaos	= GetPrivateProfileIntA("GameServer", "Mix_Item_Chaos", 100, ".\\Data\\GameServer.ini");
	GS.Mix_CapaDL		= GetPrivateProfileIntA("GameServer", "Mix_Capa_DL", 100, ".\\Data\\GameServer.ini");

	GS.Reset_Tipo			= GetPrivateProfileIntA("Reset", "Tipo", 0, ".\\Data\\Reset.ini");
	GS.Reset_Pontos[0]		= GetPrivateProfileIntA("Reset", "Pontos_Por_Reset_Free", 400, ".\\Data\\Reset.ini");
	GS.Reset_Pontos[1]		= GetPrivateProfileIntA("Reset", "Pontos_Por_Reset_Vip", 400, ".\\Data\\Reset.ini");

	GS.Reset_Pontos_Somatoria[0]= GetPrivateProfileIntA("Reset", "Somatoria_de_Pontos_Free", 0, ".\\Data\\Reset.ini");
	GS.Reset_Pontos_Somatoria[1]= GetPrivateProfileIntA("Reset", "Somatoria_de_Pontos_Vip", 0, ".\\Data\\Reset.ini");

	GS.Pontos_Iniciais[0]	= GetPrivateProfileIntA("Reset", "Pontos_Iniciais_Free", 50, ".\\Data\\Reset.ini");
	GS.Pontos_Iniciais[1]	= GetPrivateProfileIntA("Reset", "Pontos_Iniciais_Vip", 50, ".\\Data\\Reset.ini");
	GS.Reset_Level[0]		= GetPrivateProfileIntA("Reset", "Reset_Level_Free", 400, ".\\Data\\Reset.ini");
	GS.Reset_Level[1]		= GetPrivateProfileIntA("Reset", "Reset_Level_Vip", 400, ".\\Data\\Reset.ini");

	GS.Reset_SVIni_Ativado	= GetPrivateProfileIntA("Server_Iniciante", "Ativado", 0, ".\\Data\\Reset.ini");
	GS.Reset_SVIni_MaxResets= GetPrivateProfileIntA("Server_Iniciante", "Resets_Maximo", 10, ".\\Data\\Reset.ini");

	// - NPC's
	GS.NPC_LPK_Ativado		= GetPrivateProfileIntA("LimparPK", "Ativado", 1, ".\\Data\\Npc.ini");
	GS.NPC_LPK_Vip			= GetPrivateProfileIntA("LimparPK", "Somente_Vip", 0, ".\\Data\\Npc.ini");
	GS.NPC_LPK_Zen			= GetPrivateProfileIntA("LimparPK", "Zen", 0, ".\\Data\\Npc.ini");

	GS.NPC_Reset_Ativado	= GetPrivateProfileIntA("Reset", "Ativado", 1, ".\\Data\\Npc.ini");
	GS.NPC_Reset_Vip		= GetPrivateProfileIntA("Reset", "Somente_Vip", 0, ".\\Data\\Npc.ini");
	GS.NPC_Reset_Zen		= GetPrivateProfileIntA("Reset", "Zen", 0, ".\\Data\\Npc.ini");

	// - COMANDOS
	GS.Add_Ativado		= GetPrivateProfileIntA("Add", "Ativado", 1, ".\\Data\\Comandos.ini");
	GS.Add_Vip			= GetPrivateProfileIntA("Add", "Somente_Vip", 0, ".\\Data\\Comandos.ini");
	GS.Add_Zen			= GetPrivateProfileIntA("Add", "Zen", 0, ".\\Data\\Comandos.ini");

	GetPrivateProfileStringA("Post","Comando","/post", GS.Post, 16, ".\\Data\\Comandos.ini");
	GS.Post_Ativado		= GetPrivateProfileIntA("Post", "Ativado", 1, ".\\Data\\Comandos.ini");
	GS.Post_ResetsMin	= GetPrivateProfileIntA("Post", "Resets_Minimos", 0, ".\\Data\\Comandos.ini");
	GS.Post_Vip			= GetPrivateProfileIntA("Post", "Somente_Vip", 0, ".\\Data\\Comandos.ini");
	GS.Post_Zen			= GetPrivateProfileIntA("Post", "Zen", 0, ".\\Data\\Comandos.ini");
	GS.Post_Len			= strlen(GS.Post)+1;

	GetPrivateProfileStringA("Bau","Comando","/bau", GS.Bau, 16, ".\\Data\\Comandos.ini");
	GS.Bau_Ativado		= GetPrivateProfileIntA("Bau", "Ativado", 1, ".\\Data\\Comandos.ini");
	GS.Bau_Vip			= GetPrivateProfileIntA("Bau", "Somente_Vip", 0, ".\\Data\\Comandos.ini");
	GS.Bau_Zen			= GetPrivateProfileIntA("Bau", "Zen", 0, ".\\Data\\Comandos.ini");
	GS.Bau_Total_Free	= GetPrivateProfileIntA("Bau", "Quantidade_Free", 0, ".\\Data\\Comandos.ini");
	GS.Bau_Total_Vip	= GetPrivateProfileIntA("Bau", "Quantidade_Vip", 0, ".\\Data\\Comandos.ini");
	GS.Bau_Len			= strlen(GS.Bau)+1;

	GetPrivateProfileStringA("LimparPK","Comando","/limparpk", GS.LPK, 16, ".\\Data\\Comandos.ini");
	GS.LPK_Ativado		= GetPrivateProfileIntA("LimparPK", "Ativado", 1, ".\\Data\\Comandos.ini");
	GS.LPK_Vip			= GetPrivateProfileIntA("LimparPK", "Somente_Vip", 0, ".\\Data\\Comandos.ini");
	GS.LPK_Zen			= GetPrivateProfileIntA("LimparPK", "Zen", 0, ".\\Data\\Comandos.ini");

	GetPrivateProfileStringA("Reset","Comando","/reset", GS.Reset, 16, ".\\Data\\Comandos.ini");
	GS.Reset_Ativado	= GetPrivateProfileIntA("Reset", "Ativado", 1, ".\\Data\\Comandos.ini");
	GS.Reset_Vip		= GetPrivateProfileIntA("Reset", "Somente_Vip", 0, ".\\Data\\Comandos.ini");
	GS.Reset_Zen		= GetPrivateProfileIntA("Reset", "Zen", 0, ".\\Data\\Comandos.ini");

	GetPrivateProfileStringA("MasterReset","Comando","/masterreset", GS.MasterReset, 16, ".\\Data\\Comandos.ini");
	GS.MasterReset_Ativado	= GetPrivateProfileIntA("MasterReset", "Ativado", 1, ".\\Data\\Comandos.ini");
	GS.MasterReset_Vip		= GetPrivateProfileIntA("MasterReset", "Somente_Vip", 0, ".\\Data\\Comandos.ini");
	GS.MasterReset_Zen		= GetPrivateProfileIntA("MasterReset", "Zen", 0, ".\\Data\\Comandos.ini");
	GS.MasterReset_Resets	= GetPrivateProfileIntA("MasterReset", "Resets_Minimos", 0, ".\\Data\\Comandos.ini");

	GS.MasterReset_Premio_Gold[0]	= GetPrivateProfileIntA("MasterReset", "Premio_Gold_Free", 0, ".\\Data\\Comandos.ini");
	GS.MasterReset_Premio_Gold[1]	= GetPrivateProfileIntA("MasterReset", "Premio_Gold_Vip", 0, ".\\Data\\Comandos.ini");

	GS.MasterReset_Premio_Cash[0]	= GetPrivateProfileIntA("MasterReset", "Premio_Cash_Free", 0, ".\\Data\\Comandos.ini");
	GS.MasterReset_Premio_Cash[1]	= GetPrivateProfileIntA("MasterReset", "Premio_Cash_Vip", 0, ".\\Data\\Comandos.ini");

	//SistemaDrop.cpp
	GS.DropCore_Intervalo		= GetPrivateProfileIntA("Drop","Drop_Intervalo", 30,".\\Data\\Drop.ini");
	GS.Drop_Sets				= GetPrivateProfileIntA("Drop","Taxa_De_Drop_Sets", -1,".\\Data\\Drop.ini");
	GS.Drop_Armamentos			= GetPrivateProfileIntA("Drop","Taxa_De_Drop_Armamentos", -1,".\\Data\\Drop.ini");
	GS.Drop_Itens_Exe			= GetPrivateProfileIntA("Drop","Taxa_De_Drop_Itens_Exe", -1,".\\Data\\Drop.ini");
	GS.Drop_Itens_Luck			= GetPrivateProfileIntA("Drop","Taxa_De_Drop_Itens_com_Luck", -1,".\\Data\\Drop.ini");
	GS.Drop_Itens_Option		= GetPrivateProfileIntA("Drop","Taxa_De_Drop_Itens_com_Option", -1,".\\Data\\Drop.ini");
	GS.Drop_Itens_Skill			= GetPrivateProfileIntA("Drop","Taxa_De_Drop_Itens_com_Skill", -1,".\\Data\\Drop.ini");
	GS.Drop_Itens_Ancient		= GetPrivateProfileIntA("Drop","Taxa_De_Drop_Itens_Ancient", -1,".\\Data\\Drop.ini");
	GS.Drop_Miscelandias		= GetPrivateProfileIntA("Drop","Taxa_De_Drop_Miscelandias", -1,".\\Data\\Drop.ini");
	GS.Drop_Zen					= GetPrivateProfileIntA("Drop","Taxa_De_Drop_de_Zen", -1,".\\Data\\Drop.ini");

	GS.CalCharacter_Numero_Inicial[0]		= GetPrivateProfileIntA("DW_SM","Numero_Inicial", 3000,".\\Data\\Classes.ini");
	GS.CalCharacter_Numero_Inicial[1]		= GetPrivateProfileIntA("DK_BK","Numero_Inicial", 3000,".\\Data\\Classes.ini");
	GS.CalCharacter_Numero_Inicial[2]		= GetPrivateProfileIntA("Elf_ME","Numero_Inicial", 3000,".\\Data\\Classes.ini");
	GS.CalCharacter_Numero_Inicial[3]		= GetPrivateProfileIntA("MG","Numero_Inicial", 3000,".\\Data\\Classes.ini");
	GS.CalCharacter_Numero_Inicial[4]		= GetPrivateProfileIntA("DL","Numero_Inicial", 3000,".\\Data\\Classes.ini");

	GS.CalCharacter_Multiplicador[0]	= GetPrivateProfileIntA("DW_SM","Multiplicador", 10,".\\Data\\Classes.ini");
	GS.CalCharacter_Multiplicador[1]	= GetPrivateProfileIntA("DK_BK","Multiplicador", 10,".\\Data\\Classes.ini");
	GS.CalCharacter_Multiplicador[2]	= GetPrivateProfileIntA("Elf_ME","Multiplicador", 10,".\\Data\\Classes.ini");
	GS.CalCharacter_Multiplicador[3]	= GetPrivateProfileIntA("MG","Multiplicador", 10,".\\Data\\Classes.ini");
	GS.CalCharacter_Multiplicador[4]	= GetPrivateProfileIntA("DL","Multiplicador", 10,".\\Data\\Classes.ini");

	for(int i = 0; i < 4; i++)
	{
		if(GS.CalCharacter_Numero_Inicial[i] < 1 || GS.CalCharacter_Numero_Inicial[i] > 65535) GS.CalCharacter_Numero_Inicial[i] = 1000;
		if(GS.CalCharacter_Multiplicador[i] < 1 || GS.CalCharacter_Multiplicador[i] > 100) GS.CalCharacter_Multiplicador[i] = 15;
	}

	// - AutoXP
	GS.AutoXP_Ativado	= GetPrivateProfileIntA("AutoXP","Ativado", 1,".\\Data\\AutoXP.ini");
	GS.AutoXP_Delay		= GetPrivateProfileIntA("AutoXP","Delay", 10,".\\Data\\AutoXP.ini");
	GS.AutoXP_Porcentagem	= GetPrivateProfileIntA("AutoXP","Porcentagem", 2,".\\Data\\AutoXP.ini");
	if(GS.AutoXP_Porcentagem <= 0 || GS.AutoXP_Porcentagem > 100) GS.AutoXP_Porcentagem = 50;
	GS.AutoXP_Vip		= GetPrivateProfileIntA("AutoXP","Somente_Vip", 1,".\\Data\\AutoXP.ini");

	// - Sistema_pontos.cpp
	GS.Pontos_p_LVL_DW_SM		= GetPrivateProfileIntA("Sistema_de_Pontos","DW_SM", 5,".\\Data\\Pontos_por_Level.ini");
	GS.Pontos_p_LVL_DK_BK		= GetPrivateProfileIntA("Sistema_de_Pontos","DK_BK", 5,".\\Data\\Pontos_por_Level.ini");
	GS.Pontos_p_LVL_Elf_ME		= GetPrivateProfileIntA("Sistema_de_Pontos","Elf_ME", 5,".\\Data\\Pontos_por_Level.ini");
	GS.Pontos_p_LVL_MG			= GetPrivateProfileIntA("Sistema_de_Pontos","MG", 7,".\\Data\\Pontos_por_Level.ini");
	GS.Pontos_p_LVL_DL			= GetPrivateProfileIntA("Sistema_de_Pontos","DL", 7,".\\Data\\Pontos_por_Level.ini");
	GS.Pontos_Soma_Normal		= GetPrivateProfileIntA("Sistema_de_Pontos","Soma_Free", 0,".\\Data\\Pontos_por_Level.ini");
	GS.Pontos_Soma_Vip			= GetPrivateProfileIntA("Sistema_de_Pontos","Soma_Vip", 1,".\\Data\\Pontos_por_Level.ini");
	GS.Pontos_Soma_Apos_Quest	= GetPrivateProfileIntA("Sistema_de_Pontos","Soma_Apos_Quest_do_Marlon", 1,".\\Data\\Pontos_por_Level.ini");

	//Sistema de PVP
	GS.Level_Minimo_para_PVP_Qualquer_Mapa = GetPrivateProfileIntA("PVP","Level_Minimo_para_PVP_qualquer_Mapa", 350,".\\Data\\PVP.ini");
	GS.Level_Minimo_para_PVP = GetPrivateProfileIntA("PVP","Level_Minimo_para_PVP", 200,".\\Data\\PVP.ini"); // - /pvp1 e /pvp2

	GS.PVP1_Mapa_PVP = GetPrivateProfileIntA("PVP_1","Mapa", 2,".\\Data\\PVP.ini");
	GS.PVP1_Mapa_a_X = GetPrivateProfileIntA("PVP_1","Posicao_A_X", 13,".\\Data\\PVP.ini");
	GS.PVP1_Mapa_a_Y = GetPrivateProfileIntA("PVP_1","Posicao_A_Y", 8,".\\Data\\PVP.ini");
	GS.PVP1_Mapa_b_X = GetPrivateProfileIntA("PVP_1","Posicao_B_X", 41,".\\Data\\PVP.ini");
	GS.PVP1_Mapa_b_Y = GetPrivateProfileIntA("PVP_1","Posicao_B_Y", 45,".\\Data\\PVP.ini");
	GS.PVP1_CordX	 = GetPrivateProfileIntA("PVP_1","Respawn_X", 115,".\\Data\\PVP.ini");
	GS.PVP1_CordY	 = GetPrivateProfileIntA("PVP_1","Respawn_Y", 115,".\\Data\\PVP.ini");

	GS.PVP2_Mapa_PVP = GetPrivateProfileIntA("PVP_2","Mapa", 2,".\\Data\\PVP.ini");
	GS.PVP2_Mapa_a_X = GetPrivateProfileIntA("PVP_2","Posicao_A_X", 13,".\\Data\\PVP.ini");
	GS.PVP2_Mapa_a_Y = GetPrivateProfileIntA("PVP_2","Posicao_A_Y", 8,".\\Data\\PVP.ini");
	GS.PVP2_Mapa_b_X = GetPrivateProfileIntA("PVP_2","Posicao_B_X", 41,".\\Data\\PVP.ini");
	GS.PVP2_Mapa_b_Y = GetPrivateProfileIntA("PVP_2","Posicao_B_Y", 45,".\\Data\\PVP.ini");
	GS.PVP2_CordX	 = GetPrivateProfileIntA("PVP_2","Respawn_X", 115,".\\Data\\PVP.ini");
	GS.PVP2_CordY	 = GetPrivateProfileIntA("PVP_2","Respawn_Y", 115,".\\Data\\PVP.ini");

	CarregarDropCustom();
	CarregarMove();

	//Rates soul, soul luck, life
	//*(unsigned char*)(0x004D9FAB+3)= GetPrivateProfileIntA("GameServer", "Sucesso_Equipar_Soul", 10, ".\\Data\\GameServer.ini");
	//*(unsigned char*)(0x004D9FCC+3)= GetPrivateProfileIntA("GameServer", "Sucesso_Equipar_Soul_Com_Luck", 15, ".\\Data\\GameServer.ini");
	//*(unsigned char*)(0x004DA69A+3)= GetPrivateProfileIntA("GameServer", "Sucesso_Equipar_Life", 40, ".\\Data\\GameServer.ini");

	*(BYTE*)(0x004D9FAB+3) = 0x00;
	*(BYTE*)(0x004D9FCC+3) = 0x00;
	*(BYTE*)(0x004DA69A+3) = 0x00;

	//BloodCastle Itens
	//*(unsigned char*)(0x0050A0CA+1) = GetPrivateProfileIntA("GameServer", "BloodCastle_Item_Drop_Grupo", 12, ".\\Data\\GameServer.ini");
	//*(unsigned char*)(0x0050A0C8+1) = GetPrivateProfileIntA("GameServer", "BloodCastle_Item_Drop_ID", 15, ".\\Data\\GameServer.ini");
	//*(unsigned char*)(0x0050A0E7+1) = GetPrivateProfileIntA("GameServer", "BloodCastle_Item_Drop_Level", 0, ".\\Data\\GameServer.ini");

	*(BYTE*)(0x0050A0CA+1) = 0x0E; // - Grupo
	*(BYTE*)(0x0050A0C8+1) = 0x0B; // - Index
	*(BYTE*)(0x0050A0E7+1) = 0x0C; // - Level
	
	*(unsigned int *)(0x0049D0EB+1) = GetPrivateProfileIntA("DW_SM","SoulBarrier_Divisor_de_Agilidade", 100,".\\Data\\Classes.ini");
	*(unsigned int *)(0x0049D10B+1) = GetPrivateProfileIntA("DW_SM","SoulBarrier_Divisor_de_Energia", 200,".\\Data\\Classes.ini");

	*(unsigned int *)(0x0049CD0F+1) = GetPrivateProfileIntA("DK_BK","GreatFortitute_Divisor_de_Vitalidade", 100,".\\Data\\Classes.ini");
	*(unsigned int *)(0x0049CD2F+1) = GetPrivateProfileIntA("DK_BK","GreatFortitute_Divisor_de_Energia", 200,".\\Data\\Classes.ini");
}

void SetGSConfig()
{
		GS.MaxUsers = GetPrivateProfileIntA("GameServerInfo", "NumberOfMaxUser", 100, "..\\Data\\Commonserver.cfg");
		GetPrivateProfileStringA("Mssql","IP","127.0.0.1", GS.mssql_ip, 25, ".\\Data\\Mssql.ini");
		GetPrivateProfileStringA("Mssql","DB","MuOnline", GS.mssql_db, 25, ".\\Data\\Mssql.ini");
		GetPrivateProfileStringA("Mssql","Login","sa", GS.mssql_u, 25, ".\\Data\\Mssql.ini");
		GetPrivateProfileStringA("Mssql","Senha","", GS.mssql_p, 25, ".\\Data\\Mssql.ini");

		// - UdpPort
		*(unsigned int*)(0x004F57BF+1)	= GS.Porta_UDP;

		// - Level Maximo
		*(unsigned int*)(0x004A4202+3)	= GS.Level_Maximo;
		*(unsigned int*)(0x004BCEFB+2)	= GS.Level_Maximo;
		*(unsigned int*)(0x005058E0+2)	= GS.Level_Maximo;
		*(unsigned int*)(0x00511990+2)	= GS.Level_Maximo;
		*(unsigned char*)(0x004F58EF+3) = (GS.Level_Maximo+1);
}
