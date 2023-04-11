#include "StdAfx.h"

void SetGSConfig()
{
		*(unsigned int*)(0x00535DBE) = GetPrivateProfileIntA("GameServerInfo", "UDPPort",60010,"..\\ServerInfo.dat");

		//Itens Ancient
		if(GetPrivateProfileIntA("GameServer", "Ativar_Itens_Excelentes_e_Ancient", 1, "..\\MarxD\\GameServer.ini") == 1)
		{
			*(BYTE*)(0x00523366) = 0xEB;
		}
}

void CarregarConfigs()
{
		//Aneis
		*(unsigned int*)(0x4CC3EB+3) = GetPrivateProfileIntA("GameServer", "Anel_de_Transformacao1", 2, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x4CC3F4+3) = GetPrivateProfileIntA("GameServer", "Anel_de_Transformacao2", 7, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x4CC3FD+3) = GetPrivateProfileIntA("GameServer", "Anel_de_Transformacao3", 14, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x4CC406+3) = GetPrivateProfileIntA("GameServer", "Anel_de_Transformacao4", 8, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x4CC40F+3) = GetPrivateProfileIntA("GameServer", "Anel_de_Transformacao5", 9, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x4CC418+3) = GetPrivateProfileIntA("GameServer", "Anel_de_Transformacao6", 41, "..\\MarxD\\GameServer.ini");

		//Preços das Joias
		*(unsigned int*)(0x525923+3) = GetPrivateProfileIntA("GameServer", "Preco_do_Bless", 6000000, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x525944+3) = GetPrivateProfileIntA("GameServer", "Preco_do_Soul", 9000000, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x525966+3) = GetPrivateProfileIntA("GameServer", "Preco_do_Chaos", 810000, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x525988+3) = GetPrivateProfileIntA("GameServer", "Preco_do_Life", 45000000, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x5259A9+3) = GetPrivateProfileIntA("GameServer", "Preco_do_Creation", 36000000, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x525A87+3) = GetPrivateProfileIntA("GameServer", "Preco_do_Guardian", 60000000, "..\\MarxD\\GameServer.ini");

		//Guild Alliance
		*(unsigned char*)(0x45967B+2) = GetPrivateProfileIntA("GameServer", "Alianca_Entre_Guilds", 1, "..\\MarxD\\GameServer.ini");

		//Rates soul, soul luck, life
		*(unsigned char*)(0x51246C+3) = GetPrivateProfileIntA("GameServer", "Sucesso_Equipar_Soul", 10, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x51254B+3) = GetPrivateProfileIntA("GameServer", "Sucesso_Equipar_Soul_Com_Luck", 15, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x512CDA+3) = GetPrivateProfileIntA("GameServer", "Sucesso_Equipar_Life", 40, "..\\MarxD\\GameServer.ini");

		//GreatFortitute
		if(GetPrivateProfileIntA("GameServer", "Fixar_Skill_Great_Fortitute", 1, "..\\MarxD\\GameServer.ini"))
		{
			*(unsigned int*)(0x4CBA26+2) = GetPrivateProfileIntA("GameServer", "Taxa_Fortitute_Vit_Porcentagem", 40, "..\\MarxD\\GameServer.ini");
			*(unsigned int*)(0x4CBA2B+1) = GetPrivateProfileIntA("GameServer", "Taxa_Fortitute_Ene_Porcentagem", 40, "..\\MarxD\\GameServer.ini");
		}

		//Fix Soul Barrier Skill
		if(GetPrivateProfileIntA("GameServer", "Fixar_Skill_Soul_Barrier",0, "..\\MarxD\\GameServer.ini"))
		{
			*(unsigned int *)(0x4CBBDB+1) = GetPrivateProfileIntA("GameServer", "Soul_Barrier_Agilidade",50, "..\\MarxD\\GameServer.ini");
			*(unsigned int *)(0x4CBBFB+1) = GetPrivateProfileIntA("GameServer", "Soul_Barrier_Energia",200, "..\\MarxD\\GameServer.ini");
			*(unsigned int *)(0x4CBC70+2) = GetPrivateProfileIntA("GameServer", "Soul_Barrier_Taxa",50, "..\\MarxD\\GameServer.ini");
			*(unsigned int *)(0x4CBC75+1) = GetPrivateProfileIntA("GameServer", "Soul_Barrier_Taxa",50, "..\\MarxD\\GameServer.ini");
		}

}

void CarregarDefinicoesConfigs()
{
	//Configs.cpp (ChatDataSend)
	GetPrivateProfileStringA("Comandos","Ajuda","/ajuda",AjudaCmm,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Post","/post", CommandPost,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","AddStr","/str", CommandStr,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","AddAgi","/agi", CommandAgi,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","AddVit","/vit", CommandVit,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","AddEne","/ene",CommandEne,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","AddCom","/com",CommandCmd,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Recarregar_Config","/rconfig",ReloadConfigCmm,25,"..\\MarxD\\Comandos.ini");

	//Limites
	Limite_BK = GetPrivateProfileIntA("Classes","Limite_de_Pontos_do_BK", 64000,"..\\MarxD\\Classes.ini");
	Limite_SM = GetPrivateProfileIntA("Classes","Limite_de_Pontos_do_SM", 64000,"..\\MarxD\\Classes.ini");
	Limite_ME = GetPrivateProfileIntA("Classes","Limite_de_Pontos_do_ME", 64000,"..\\MarxD\\Classes.ini");
	Limite_MG = GetPrivateProfileIntA("Classes","Limite_de_Pontos_do_MG", 64000,"..\\MarxD\\Classes.ini");
	Limite_DL = GetPrivateProfileIntA("Classes","Limite_de_Pontos_do_DL", 64000,"..\\MarxD\\Classes.ini");

	//Presente em varios comandos
	Max_65K = GetPrivateProfileIntA("GameServer", "Status_65K_Ativado",1,"..\\MarxD\\GameServer.ini");

	//cmm_AdicionarPontos.cpp
	cmm_Add_Ativado = GetPrivateProfileIntA("Comandos", "Add_Ativado",1,"..\\MarxD\\Comandos.ini");
	cmm_Add_Level = GetPrivateProfileIntA("Comandos","Add_Level",100,"..\\MarxD\\Comandos.ini");
	cmm_Add_Custo = GetPrivateProfileIntA("Comandos","Add_Custo",100000,"..\\MarxD\\Comandos.ini");

	//cmm_Ajuda.cpp
	cmm_Ajuda_Ativado = GetPrivateProfileIntA("Comandos", "Ajuda_Ativado",1,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Ajuda_1","Ajuda 1",cmm_Ajuda_TmpMsg1,200,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Ajuda_2","Ajuda 2",cmm_Ajuda_TmpMsg2,200,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Ajuda_3","Ajuda 3",cmm_Ajuda_TmpMsg3,200,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Ajuda_4","Ajuda 4",cmm_Ajuda_TmpMsg4,200,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Ajuda_5","Ajuda 5",cmm_Ajuda_TmpMsg5,200,"..\\MarxD\\Comandos.ini");

	//cmm_Post.cpp
	cmm_Post_Ativado = GetPrivateProfileIntA("Comandos", "Post_Ativado",1,"..\\MarxD\\Comandos.ini");
	cmm_Post_Level = GetPrivateProfileIntA("Comandos","Post_Level",100,"..\\MarxD\\Comandos.ini");
	cmm_Post_Resets = GetPrivateProfileIntA("Comandos","Post_Resets_Minimos",5,"..\\MarxD\\Comandos.ini");
	cmm_Post_Custo = GetPrivateProfileIntA("Comandos","Post_Custo",100000,"..\\MarxD\\Comandos.ini");

	//Calcharacter
	DK_BK_BM_NumeroInicial	= GetPrivateProfileIntA("DK_BK_BM", "Calcular_a_partir_de", 1000, "..\\MarxD\\Classes.ini");
	DK_BK_BM_Multiplicador	= GetPrivateProfileIntA("DK_BK_BM", "Multiplicador_do_Dano", 15, "..\\MarxD\\Classes.ini");
	DW_SM_GM_NumeroInicial	= GetPrivateProfileIntA("DW_SM_GM", "Calcular_a_partir_de", 1000, "..\\MarxD\\Classes.ini");
	DW_SM_GM_Multiplicador	= GetPrivateProfileIntA("DW_SM_GM", "Multiplicador_do_Dano", 15, "..\\MarxD\\Classes.ini");
	Elf_ME_HE_NumeroInicial	= GetPrivateProfileIntA("Elf_ME_HE", "Calcular_a_partir_de", 1000, "..\\MarxD\\Classes.ini");
	Elf_ME_HE_Multiplicador	= GetPrivateProfileIntA("Elf_ME_HE", "Multiplicador_do_Dano", 15, "..\\MarxD\\Classes.ini");
	MG_DM_NumeroInicial		= GetPrivateProfileIntA("MG_DM", "Calcular_a_partir_de", 1000, "..\\MarxD\\Classes.ini");
	MG_DM_Multiplicador		= GetPrivateProfileIntA("MG_DM", "Multiplicador_do_Dano", 15, "..\\MarxD\\Classes.ini");
	DL_LE_NumeroInicial		= GetPrivateProfileIntA("DL_LE", "Calcular_a_partir_de", 1000, "..\\MarxD\\Classes.ini");
	DL_LE_Multiplicador		= GetPrivateProfileIntA("DL_LE", "Multiplicador_do_Dano", 15, "..\\MarxD\\Classes.ini");

	//GM & ADM DEFS
	DV_CtlCode			= GetPrivateProfileIntA("Comandos","CtlCode_do_Divulgador",28,"..\\MarxD\\Comandos.ini");
	GM_CtlCode			= GetPrivateProfileIntA("Comandos","CtlCode_do_GameMaster",28,"..\\MarxD\\Comandos.ini");
	SUB_CtlCode			= GetPrivateProfileIntA("Comandos","CtlCode_do_SubAdministrador",30,"..\\MarxD\\Comandos.ini");
	ADM_CtlCode			= GetPrivateProfileIntA("Comandos","CtlCode_do_Administrador",32,"..\\MarxD\\Comandos.ini");
	ADM_Player_CtlCode	= GetPrivateProfileIntA("Comandos","CtlCode_do_Administrador_Jogador",34,"..\\MarxD\\Comandos.ini");
}