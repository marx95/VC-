#include "StdAfx.h"

void SetGSConfig()
{
		GS.GS_Tipo =  GetPrivateProfileIntA("GameServer", "Tipo_de_Sala", 0, "..\\MarxD\\GameServer.ini");

		GetPrivateProfileStringA("Mssql","IP","127.0.0.1", GS.mssql_ip, 25, "..\\MarxD\\Mssql.ini");
		GetPrivateProfileStringA("Mssql","DB","MuOnline", GS.mssql_db, 25, "..\\MarxD\\Mssql.ini");
		GetPrivateProfileStringA("Mssql","Login","sa", GS.mssql_u, 25, "..\\MarxD\\Mssql.ini");
		GetPrivateProfileStringA("Mssql","Senha","", GS.mssql_p, 25, "..\\MarxD\\Mssql.ini");

		char TmpGsNome[25];
		DWORD *Offset = (DWORD*)(0x006BF098);

		switch(GS.GS_Tipo)
		{
		case 0:
			sprintf_s(TmpGsNome, "GS Normal");

			//Muda a cor da faixa do GS
			*(DWORD*)(0x004A9747+1) = RGB(0, 162, 232); //Azul Claro
		break;

		case 1:
			sprintf_s(TmpGsNome, "GS Vip");

			//Muda a cor da faixa do GS
			*(DWORD*)(0x004A9747+1) = RGB(255, 201, 14); //Amarelo (Ouro)
		break;

		case 2:
			sprintf_s(TmpGsNome, "GS Teste");

			//Muda a cor da faixa do GS
			*(DWORD*)(0x004A9747+1) = RGB(237, 28, 36); // Vermelho
		break;
		}
		
		*(BYTE*)(0x004A972D+1) = 0;		//Segundoffset de cor da Faixa do GS

		//Define nome do GameServer
		memset(&Offset[0],0,18);
		memcpy(&Offset[0], TmpGsNome, strlen(TmpGsNome));

		*(unsigned int*)(0x0052112F+1) = GetPrivateProfileIntA("GameServerInfo", "UDPPort",60006,".\\ServerInfo.dat");

		//Itema até +15
		if(GetPrivateProfileIntA("GameServer", "Item_Ate_Level_15", 0, "..\\MarxD\\GameServer.ini"))
		{
			*(BYTE*)(0x00429456) = 0x0F;
		}else {
			*(BYTE*)(0x00429456) = 0x0D;
		}

		//Seta valores originais
		GS.Original_Fortitute_Vit		= *(unsigned int*)(0x004B99DF+1);
		GS.Original_Fortitute_Ene		= *(unsigned int*)(0x004B99FF+1);
		GS.Original_SoulBarrier_Agi		= *(unsigned int *)(0x004B9DEB+1);
		GS.Original_SoulBarrier_Ene		= *(unsigned int *)(0x004B9E0B+1);
		GS.Original_SoulBarrier_Taxa1	= *(unsigned int *)(0x004B9E80+2);
		GS.Original_SoulBarrier_Taxa2	= *(unsigned int *)(0x004B9E85+1);

		//Fixar potion bug
		if (GetPrivateProfileIntA("GameServer", "Fixar_Numero_de_Pocoes", 0, "..\\MarxD\\GameServer.ini") )
		{
			*(BYTE*)(0x0042970F) = 0xEB;
			*(BYTE*)(0x004D304C) = 0xEB;
			*(BYTE*)(0x004D30EE) = 0xEB;
		}else
		{
			*(BYTE*)(0x0042970F) = 0x75;
			*(BYTE*)(0x004D304C) = 0x75;
			*(BYTE*)(0x004D30EE) = 0x75;
		}

		//Partyzen fix
		BYTE cPartyZenFix[] = {0x8B,0x4D,0x0C,0x33,0xC0,0x8A,0x41,0x64,0x83,0xF8, 0x02,0x74,0x05,0x83,0xF8,0x03,
							0x75,0x20,0x8B,0x91,0xB4,0x00,0x00,0x00,0x89,0x55, 0xF8,0xDB,0x45,0xF8,0xD8,0x0D,
							0xC8,0x18,0x6E,0x00,0xE8,0x1C,0x55,0x0B,0x00,0x8B, 0x4D,0x0C,0x89,0x81,0xB4,0x00,
							0x00,0x00,0x5F,0x5E,0x5B,0x8B,0xE5,0x5D,0xC3};

		BYTE cPartyZenBug[] = { 0x5F,0x5E,0x5B,0x8B,0xE5,0x5D,0xC3 } ;
	
		if(GetPrivateProfileIntA("GameServer", "Fixar_o_PartyZen_Bug",0, "..\\MarxD\\GameServer.ini") == 1)
		{
			memcpy((int *)(0x004E3437), cPartyZenFix,sizeof(cPartyZenFix));
		}else{
			memcpy((int *)(0x004E3437), cPartyZenBug,sizeof(cPartyZenBug));
			memset((PBYTE)(0x004E3437+7), 0xCC, 50);
		}

		//Itens Ancient
		if(GetPrivateProfileIntA("GameServer", "Ativar_Itens_Excelentes_e_Ancient", 1, "..\\MarxD\\GameServer.ini") == 1)
		{
			*(BYTE*)(0x0050E556) = 0xEB;
		}

		//Level Maximo
		GS.LevelMaximo = GetPrivateProfileIntA("GameServer", "Level_Maximo", 400, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004C2112+3) = GS.LevelMaximo; // CStatMng::GetMaxStat
		*(unsigned int*)(0x004DC4B5+2) = GS.LevelMaximo; // - gObjLevelUp
		*(unsigned int*)(0x005359AB+1) = GS.LevelMaximo; // - CBloodCastle::LevelUp
		*(unsigned int*)(0x005436DB+1) = GS.LevelMaximo; // - CChaosCastle::LevelUp
		*(unsigned int*)(0x005700CB+1) = GS.LevelMaximo; // -CCrywolfUtil::CrywolfMVPLevelUp
		*(unsigned char*)(0x00521262)  = GS.LevelMaximo+1; // - GameMainInit (Aqui é: LevelMax+1), provavelmente o ExpTable Antigo
}

void CarregarConfigs()
{
		//Aneis
		*(unsigned int*)(0x004BA5FB+3) = GetPrivateProfileIntA("GameServer", "Anel_de_Transformacao1", 2, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004BA604+3) = GetPrivateProfileIntA("GameServer", "Anel_de_Transformacao2", 7, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004BA60D+3) = GetPrivateProfileIntA("GameServer", "Anel_de_Transformacao3", 14, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004BA616+3) = GetPrivateProfileIntA("GameServer", "Anel_de_Transformacao4", 8, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004BA61F+3) = GetPrivateProfileIntA("GameServer", "Anel_de_Transformacao5", 9, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004BA628+3) = GetPrivateProfileIntA("GameServer", "Anel_de_Transformacao6", 41, "..\\MarxD\\GameServer.ini");

		//Orbs
		*(unsigned char*)(0x004B9022+1) = GetPrivateProfileIntA("GameServer", "Orbs_de_Summon1", 26, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x004B9053+1) = GetPrivateProfileIntA("GameServer", "Orbs_de_Summon2", 32, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x004B9084+1) = GetPrivateProfileIntA("GameServer", "Orbs_de_Summon3", 21, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x004B90B5+1) = GetPrivateProfileIntA("GameServer", "Orbs_de_Summon4", 20, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x004B90E6+1) = GetPrivateProfileIntA("GameServer", "Orbs_de_Summon5", 10, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x004B9117+1) = GetPrivateProfileIntA("GameServer", "Orbs_de_Summon6", 150, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x004B914B+1) = GetPrivateProfileIntA("GameServer", "Orbs_de_Summon7", 151, "..\\MarxD\\GameServer.ini");

		//Chaos Castle - Jogadores Minimos
		*(unsigned char*)(0x005442F0+3) = GetPrivateProfileIntA("GameServer", "Jogadores_Minimos_No_CC", 2, "..\\MarxD\\GameServer.ini");

		//Preços das Joias
		*(unsigned int*)(0x00510B13+3) = GetPrivateProfileIntA("GameServer", "Preco_do_Bless", 6000000, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x00510B34+3) = GetPrivateProfileIntA("GameServer", "Preco_do_Soul", 9000000, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x00510B56+3) = GetPrivateProfileIntA("GameServer", "Preco_do_Chaos", 810000, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x00510B78+3) = GetPrivateProfileIntA("GameServer", "Preco_do_Life", 45000000, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x00510B99+3) = GetPrivateProfileIntA("GameServer", "Preco_do_Creation", 36000000, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x00510C77+3) = GetPrivateProfileIntA("GameServer", "Preco_do_Guardian", 60000000, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x0049A489+3) = GetPrivateProfileIntA("GameServer", "Preco_do_DarkSpirit", 5000000, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x00499D88+3) = GetPrivateProfileIntA("GameServer", "Preco_do_DarkHorse", 4500000, "..\\MarxD\\GameServer.ini");

		//Guild Alliance
		*(unsigned char*)(0x00457DEB+2) = GetPrivateProfileIntA("GameServer", "Alianca_Entre_Guilds", 1, "..\\MarxD\\GameServer.ini");

		//Rates soul, soul luck, life
		*(unsigned char*)(0x004FEA5B+3) = GetPrivateProfileIntA("GameServer", "Sucesso_Equipar_Soul", 10, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x004FE97C+3) = GetPrivateProfileIntA("GameServer", "Sucesso_Equipar_Soul_Com_Luck", 15, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x004FF1EA+3) = GetPrivateProfileIntA("GameServer", "Sucesso_Equipar_Life", 40, "..\\MarxD\\GameServer.ini");

		//Zen maximo
		DWORD ZenMax;
		*(unsigned int*)(0x005050A5+3) = GetPrivateProfileIntA("GameServer", "Zen_Maximo_no_Inventario", 1000000000, "..\\MarxD\\GameServer.ini");	//Inventario

		ZenMax = GetPrivateProfileIntA("GameServer", "Zen_Maximo_no_Bau", 1000000000, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x00447986+3) = ZenMax;
		*(unsigned int*)(0x00447A7C+3) = ZenMax;
		*(unsigned int*)(0x004479B2+2) = ZenMax;

		//BloodCastle Itens
		*(unsigned char*)(0x0053A1E8+1) = GetPrivateProfileIntA("GameServer", "BloodCastle_Item_Drop_ID", 12, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x0053A1EA+1) = GetPrivateProfileIntA("GameServer", "BloodCastle_Item_Drop_Grupo", 15, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x0053A1FF+1) = GetPrivateProfileIntA("GameServer", "BloodCastle_Item_Drop_Level", 0, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x0053A201+1) = GetPrivateProfileIntA("GameServer", "BloodCastle_Item_Drop_Level", 0, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x0053A203+1) = GetPrivateProfileIntA("GameServer", "BloodCastle_Item_Drop_Level", 0, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x0053A205+1) = GetPrivateProfileIntA("GameServer", "BloodCastle_Item_Drop_Level", 0, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x0053A207+1) = GetPrivateProfileIntA("GameServer", "BloodCastle_Item_Drop_Level", 0, "..\\MarxD\\GameServer.ini");

		//Level's das skills
		*(unsigned int*)(0x00483640+7) = GetPrivateProfileIntA("GameServer", "Level_da_Skill_TwistSlash", 1, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x00483659+7) = GetPrivateProfileIntA("GameServer", "Level_da_Skill_RegefulBlow", 1, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x00483672+7) = GetPrivateProfileIntA("GameServer", "Level_da_Skill_DeathStab", 1, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x0048368B+7) = GetPrivateProfileIntA("GameServer", "Level_da_Skill_Impalling", 1, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004836A4+7) = GetPrivateProfileIntA("GameServer", "Level_da_Skill_Fortitule", 1, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004836D4+7) = GetPrivateProfileIntA("GameServer", "Level_da_Skill_Penetration", 1, "..\\MarxD\\GameServer.ini");
		
		//Chaos Machine
		*(unsigned int*)(0x00496626+6) = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Item_10", 100, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x00496651+6) = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Item_11", 95, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x0049667C+6) = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Item_12", 90, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004966A7+6) = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Item_13", 85, "..\\MarxD\\GameServer.ini");

		*(unsigned char*)(0x004966E5+6) = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Taxa", 80, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004966F1+6) = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Taxa", 80, "..\\MarxD\\GameServer.ini");
		
		*(unsigned char*)(0x00499378+6) = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Item380", 80, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x00499384+6) = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Item380", 80, "..\\MarxD\\GameServer.ini");
		
		*(unsigned int*)(0x00499D69+6) = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_DarkHorse", 50, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x0049A46A+6) = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_DarkSpirit", 50, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004970A2+6) = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Dinorant", 80, "..\\MarxD\\GameServer.ini");
		
		*(unsigned char*)(0x0049937E) = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Ancient1", 80, "..\\MarxD\\GameServer.ini");
    	*(unsigned char*)(0x0049938A) = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Ancient2", 80, "..\\MarxD\\GameServer.ini");

		//Drops
		*(unsigned int*)(0x0041B0F8+1) = GetPrivateProfileIntA("GameServer", "Taxa_de_Drop_Excellent", 100, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x0041B44C+6) = GetPrivateProfileIntA("GameServer", "Taxa_de_Drop_Excellent_com_Skill", 100, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x0041B456+6) = GetPrivateProfileIntA("GameServer", "Taxa_de_Drop_Excellent_com_Luck", 100, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x0041B4A5+6) = GetPrivateProfileIntA("GameServer", "Taxa_de_Drop_com_Skill",100, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x0041B4AF+6) = GetPrivateProfileIntA("GameServer", "Taxa_de_Drop_com_Luck",100, "..\\MarxD\\GameServer.ini");

		//Pontos ganhados por level
		//*(unsigned char*)(0x004DC58C+2) = GetPrivateProfileIntA("GameServer", "Pontos_por_Level_do_DL", 7, "..\\MarxD\\GameServer.ini");
		//*(unsigned char*)(0x004DC5B4+2) = GetPrivateProfileIntA("GameServer", "Pontos_por_Level_do_MG", 7, "..\\MarxD\\GameServer.ini");
		//*(unsigned char*)(0x004DC5CB+2) = GetPrivateProfileIntA("GameServer", "Pontos_por_Level", 5, "..\\MarxD\\GameServer.ini");

		//PartyZen Fix Exp
		*(unsigned int*)(0x004DCF8B) = GetPrivateProfileIntA("GameServer", "Taxa_de_Exp_na_party_com_2_Membro", 180, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004DCFD0) = GetPrivateProfileIntA("GameServer", "Taxa_de_Exp_na_party_com_3_Membro", 180, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004DCF9A) = GetPrivateProfileIntA("GameServer", "Taxa_de_Exp_na_party_com_4_Membro", 180, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004DCFA9) = GetPrivateProfileIntA("GameServer", "Taxa_de_Exp_na_party_com_5_Membro", 180, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004DCFB8) = GetPrivateProfileIntA("GameServer", "Diferenca_de_Exp_na_party_com_3_Membro", 360, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004DCF64) = GetPrivateProfileIntA("GameServer", "Diferenca_de_Exp_na_party_com_4_Membro", 360, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004DCFC7) = GetPrivateProfileIntA("GameServer", "Diferenca_de_Exp_na_party_com_5_Membro", 360, "..\\MarxD\\GameServer.ini");

		//GreatFortitute
		if(GetPrivateProfileIntA("DK_BK_BM", "Fixar_Skill_Great_Fortitute", 1, "..\\MarxD\\Classes.ini"))
		{
			*(unsigned int*)(0x004B99DF+1) = GetPrivateProfileIntA("DK_BK_BM", "Taxa_Fortitute_Vit_Porcentagem", 40, "..\\MarxD\\Classes.ini");
			*(unsigned int*)(0x004B99FF+1) = GetPrivateProfileIntA("DK_BK_BM", "Taxa_Fortitute_Ene_Porcentagem", 40, "..\\MarxD\\Classes.ini");
		}else
		{
			*(unsigned int*)(0x004B99DF+1) = GS.Original_Fortitute_Vit;
			*(unsigned int*)(0x004B99FF+1) = GS.Original_Fortitute_Ene;
		}

		//Ajustes das poçoes
		*(unsigned int*)(0x0044D5CF+3) = GetPrivateProfileIntA("GameServer", "Porc_de_cura_da_Pocao_Maca", 10, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x0044D5D8+3) = GetPrivateProfileIntA("GameServer", "Porc_de_cura_da_Pocao_HP_Pequena", 20, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x0044D5E1+3) = GetPrivateProfileIntA("GameServer", "Porc_de_cura_da_Pocao_HP_Media", 30, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x0044D5EA+3) = GetPrivateProfileIntA("GameServer", "Porc_de_cura_da_Pocao_HP_Grande", 40, "..\\MarxD\\GameServer.ini");

		*(unsigned char*)(0x0044D90B+2) = GetPrivateProfileIntA("GameServer", "Porc_de_cura_da_Mana_Pequena", 20, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x0044D943+2) = GetPrivateProfileIntA("GameServer", "Porc_de_cura_da_Mana_Media", 30, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x0044D97B+2) = GetPrivateProfileIntA("GameServer", "Porc_de_cura_da_Mana_Grande", 40, "..\\MarxD\\GameServer.ini");

		//Fix Soul Barrier Skill
		if(GetPrivateProfileIntA("DW_SM_GM", "Fixar_Skill_Soul_Barrier",0, "..\\MarxD\\Classes.ini"))
		{
			*(unsigned int *)(0x004B9DEB+1) = GetPrivateProfileIntA("DW_SM_GM", "Soul_Barrier_Agilidade",50, "..\\MarxD\\Classes.ini");
			*(unsigned int *)(0x004B9E0B+1) = GetPrivateProfileIntA("DW_SM_GM", "Soul_Barrier_Energia",200, "..\\MarxD\\Classes.ini");
			*(unsigned int *)(0x004B9E80+2) = GetPrivateProfileIntA("DW_SM_GM", "Soul_Barrier_Taxa",50, "..\\MarxD\\Classes.ini");
			*(unsigned int *)(0x004B9E85+1) = GetPrivateProfileIntA("DW_SM_GM", "Soul_Barrier_Taxa",50, "..\\MarxD\\Classes.ini");
		}else
		{
			*(unsigned int *)(0x004B9DEB+1) = GS.Original_SoulBarrier_Agi;
			*(unsigned int *)(0x004B9E0B+1) = GS.Original_SoulBarrier_Ene;
			*(unsigned int *)(0x004B9E80+2) = GS.Original_SoulBarrier_Taxa1;
			*(unsigned int *)(0x004B9E85+1) = GS.Original_SoulBarrier_Taxa2;
		}

		//Golden Mob's
		*(unsigned char*)(0x004695CD+3) = GetPrivateProfileIntA("GameServer", "GoldenDragon_Regenerar_no_Mapa_ID1", 0, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x004695D4+3) = GetPrivateProfileIntA("GameServer", "GoldenDragon_Regenerar_no_Mapa_ID2", 3, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x004695DB+3)  = GetPrivateProfileIntA("GameServer", "GoldenDragon_Regenerar_no_Mapa_ID3", 2, "..\\MarxD\\GameServer.ini");

		*(unsigned char*)(0x00469A4D+3) = GetPrivateProfileIntA("GameServer", "GoldenLizard_Regenerar_No_Mapa", 7, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x00469F1D+3) = GetPrivateProfileIntA("GameServer", "GoldenTantallos_Regenerar_No_Mapa", 8, "..\\MarxD\\GameServer.ini");
		*(unsigned char*)(0x0046913D+3) = GetPrivateProfileIntA("GameServer", "GoldenTaitan_Regenerar_No_Mapa", 2, "..\\MarxD\\GameServer.ini");
		
		*(unsigned char*)(0x00468E53+3) = GetPrivateProfileIntA("GameServer", "GoldenGloben_Regenerar_no_Mapa_ID1", 0, "..\\MarxD\\GameServer.ini");
		*(unsigned int*)(0x00468E5A+3) = GetPrivateProfileIntA("GameServer", "GoldenGloben_Regenerar_no_Mapa_ID2", 3, "..\\MarxD\\GameServer.ini");

		//White Wizard Premio
		*(BYTE*)(0x0046D1C7+1) = GetPrivateProfileIntA("GameServer", "WhiteWizard_Premio_Grupo", 7, "..\\MarxD\\GameServer.ini");
		*(BYTE*)(0x0046D1C9+1) = GetPrivateProfileIntA("GameServer", "WhiteWizard_Premio_ID", 4, "..\\MarxD\\GameServer.ini");

		//Premios Fire Event
		*(BYTE*)(0x0041AB03+1) = GetPrivateProfileIntA("GameServer", "FireEvent_Premio1_Grupo", 13, "..\\MarxD\\GameServer.ini");
		*(BYTE*)(0x0041AB05+1) = GetPrivateProfileIntA("GameServer", "FireEvent_Premio1_ID", 14, "..\\MarxD\\GameServer.ini");
		*(BYTE*)(0x0041AB71+1) = GetPrivateProfileIntA("GameServer", "FireEvent_Premio2_Grupo", 14, "..\\MarxD\\GameServer.ini");
		*(BYTE*)(0x0041AB73+1) = GetPrivateProfileIntA("GameServer", "FireEvent_Premio2_ID", 14, "..\\MarxD\\GameServer.ini");
}

void CarregarDefinicoesConfigs()
{
	GS.Log							=  GetPrivateProfileIntA("GameServer", "Ativar_Logs_na_INI", 0, "..\\MarxD\\GameServer.ini");
	GS.Ativar_Reflete				=  GetPrivateProfileIntA("GameServer", "Ativar_Dano_Reflete", 0, "..\\MarxD\\GameServer.ini");

	// - Npc Maluco
	Carrega_NpcMaluco();

	GS.ShadowP_MaxLevel				= GetPrivateProfileIntA("GameServer", "Level_Maximo_do_Buff_da_Elf", 80, "..\\MarxD\\GameServer.ini");

	//Sistema de PVP
	GS.Level_Minimo_para_PVP_Qualquer_Mapa = GetPrivateProfileIntA("PVP","Level_Minimo_para_PVP_qualquer_Mapa", 350,"..\\MarxD\\PVP.ini");
	GS.Level_Minimo_para_PVP = GetPrivateProfileIntA("PVP","Level_Minimo_para_PVP", 200,"..\\MarxD\\PVP.ini");

	GS.PVP1_Mapa_PVP = GetPrivateProfileIntA("PVP_1","Mapa", 2,"..\\MarxD\\PVP.ini");
	GS.PVP1_Mapa_a_X = GetPrivateProfileIntA("PVP_1","Posicao_A_X", 13,"..\\MarxD\\PVP.ini");
	GS.PVP1_Mapa_a_Y = GetPrivateProfileIntA("PVP_1","Posicao_A_Y", 8,"..\\MarxD\\PVP.ini");
	GS.PVP1_Mapa_b_X = GetPrivateProfileIntA("PVP_1","Posicao_B_X", 41,"..\\MarxD\\PVP.ini");
	GS.PVP1_Mapa_b_Y = GetPrivateProfileIntA("PVP_1","Posicao_B_Y", 45,"..\\MarxD\\PVP.ini");
	GS.PVP1_CordX = GetPrivateProfileIntA("PVP_1","Respawn_X", 115,"..\\MarxD\\PVP.ini");
	GS.PVP1_CordY = GetPrivateProfileIntA("PVP_1","Respawn_Y", 115,"..\\MarxD\\PVP.ini");

	GS.PVP2_Mapa_PVP = GetPrivateProfileIntA("PVP_2","Mapa", 2,"..\\MarxD\\PVP.ini");
	GS.PVP2_Mapa_a_X = GetPrivateProfileIntA("PVP_2","Posicao_A_X", 13,"..\\MarxD\\PVP.ini");
	GS.PVP2_Mapa_a_Y = GetPrivateProfileIntA("PVP_2","Posicao_A_Y", 8,"..\\MarxD\\PVP.ini");
	GS.PVP2_Mapa_b_X = GetPrivateProfileIntA("PVP_2","Posicao_B_X", 41,"..\\MarxD\\PVP.ini");
	GS.PVP2_Mapa_b_Y = GetPrivateProfileIntA("PVP_2","Posicao_B_Y", 45,"..\\MarxD\\PVP.ini");
	GS.PVP2_CordX = GetPrivateProfileIntA("PVP_2","Respawn_X", 115,"..\\MarxD\\PVP.ini");
	GS.PVP2_CordY = GetPrivateProfileIntA("PVP_2","Respawn_Y", 115,"..\\MarxD\\PVP.ini");

	//Limites
	GS.Limite_Pontos[0] = GetPrivateProfileIntA("DK_BK_BM","Limite_de_Pontos", 64000,"..\\MarxD\\Classes.ini");
	GS.Limite_Pontos[1] = GetPrivateProfileIntA("DW_SM_GM","Limite_de_Pontos", 64000,"..\\MarxD\\Classes.ini");
	GS.Limite_Pontos[2] = GetPrivateProfileIntA("Elf_ME_HE","Limite_de_Pontos", 64000,"..\\MarxD\\Classes.ini");
	GS.Limite_Pontos[3] = GetPrivateProfileIntA("MG_DM","Limite_de_Pontos", 64000,"..\\MarxD\\Classes.ini");
	GS.Limite_Pontos[4] = GetPrivateProfileIntA("DL_LE","Limite_de_Pontos", 64000,"..\\MarxD\\Classes.ini");

	//Noticias
	GS.Noticias_Info = 0;
	GS.Noticias_Ativado = GetPrivateProfileIntA("Noticias", "Ativado",0,"..\\MarxD\\Noticias.ini");
	GS.Noticias_Tempo = GetPrivateProfileIntA("Noticias", "Tempo",5,"..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_A","Msg 1", GS.Noticia_A, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_B","Msg 2", GS.Noticia_B, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_C","Msg 3", GS.Noticia_C, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_D","Msg 4", GS.Noticia_D, 255, "..\\MarxD\\Noticias.ini");

	GetPrivateProfileStringA("Noticias","Noticia_E","Msg 5", GS.Noticia_E, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_F","Msg 6", GS.Noticia_F, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_G","Msg 7", GS.Noticia_G, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_H","Msg 8", GS.Noticia_H, 255, "..\\MarxD\\Noticias.ini");

	GetPrivateProfileStringA("Noticias","Noticia_I","Msg 9", GS.Noticia_I, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_J","Msg 10", GS.Noticia_J, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_K","Msg 11", GS.Noticia_K, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_L","Msg 12", GS.Noticia_L, 255, "..\\MarxD\\Noticias.ini");

	GetPrivateProfileStringA("Noticias","Noticia_M","Msg 13", GS.Noticia_M, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_N","Msg 14", GS.Noticia_N, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_O","Msg 15", GS.Noticia_O, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_P","Msg 16", GS.Noticia_P, 255, "..\\MarxD\\Noticias.ini");

	GetPrivateProfileStringA("Noticias","Noticia_Q","Msg 17", GS.Noticia_Q, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_R","Msg 18", GS.Noticia_R, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_S","Msg 19", GS.Noticia_S, 255, "..\\MarxD\\Noticias.ini");
	GetPrivateProfileStringA("Noticias","Noticia_T","Msg 20", GS.Noticia_T, 255, "..\\MarxD\\Noticias.ini");

	//Definições MensagemLateral(MSG Login)
	GetPrivateProfileStringA("GameServer","Mensagem_de_Login_Lateral","Bem-Vindo", GS.MSGLateral, 100, "..\\MarxD\\GameServer.ini");
	GetPrivateProfileStringA("GameServer","Mensagem_de_Login","Projeto GameServer.dll 1.00.18 do MarxD", GS.MSGLateral_ConnectMsg,100,"..\\MarxD\\GameServer.ini");

	//Npc.cpp
	GS.NpcRst = GetPrivateProfileIntA("Reset", "Npc",247,"..\\MarxD\\Reset.ini");
	GS.MapaRst = GetPrivateProfileIntA("Reset", "Mapa",0,"..\\MarxD\\Reset.ini");

	GS.NpcPK = GetPrivateProfileIntA("LimparPK", "Npc",249,"..\\MarxD\\LimparPK.ini");
	GS.MapaPK = GetPrivateProfileIntA("LimparPK", "Mapa",0,"..\\MarxD\\LimparPK.ini");

	//Reset.cpp
	GS.Func_Reset_Ativado			= GetPrivateProfileIntA("Reset", "Ativado",1,"..\\MarxD\\Reset.ini");
	GS.Func_Reset_Level_Free		= GetPrivateProfileIntA("Reset", "Level_de_Reset_Free", 1, "..\\MarxD\\Reset.ini");
	GS.Func_Reset_Custo				= GetPrivateProfileIntA("Reset", "Custo", 1, "..\\MarxD\\Reset.ini");
	GS.Func_Reset_Custo_Vip			= GetPrivateProfileIntA("Reset", "Custo_Vip", 1, "..\\MarxD\\Reset.ini");
	GS.Func_Reset_PontosIni_Free	= GetPrivateProfileIntA("Reset", "Pontos_Iniciais_Free", 1, "..\\MarxD\\Reset.ini");
	GS.Func_Reset_Pontos_Free		= GetPrivateProfileIntA("Reset", "Pontos_por_Reset_Free", 400, "..\\MarxD\\Reset.ini");
	GS.Func_Reset_Level_Vip			= GetPrivateProfileIntA("Reset", "Level_de_Reset_Vip", 1, "..\\MarxD\\Reset.ini");
	GS.Func_Reset_PontosIni_Vip		= GetPrivateProfileIntA("Reset", "Pontos_Iniciais_Vip", 1, "..\\MarxD\\Reset.ini");
	GS.Func_Reset_Pontos_Vip		= GetPrivateProfileIntA("Reset", "Pontos_por_Reset_Vip", 400, "..\\MarxD\\Reset.ini");
	GS.Func_Reset_Tipo				= GetPrivateProfileIntA("Reset", "Tipo", 0, "..\\MarxD\\Reset.ini");
	GS.Func_Reset_Limite			= GetPrivateProfileIntA("Reset", "Limite_de_Resets",0,"..\\MarxD\\Reset.ini");

	//Chaos Box
	GS.TaxaSucessoItemChaos = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Item_Chaos", 80, "..\\MarxD\\GameServer.ini");
	GS.TaxaSucessoPrimeiraAsa = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Asa_Lv1", 80, "..\\MarxD\\GameServer.ini");
	GS.TaxaSucessoSegundaAsa = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Asa_Lv2", 80, "..\\MarxD\\GameServer.ini");
	GS.TaxaSucessoTerceiraAsa = GetPrivateProfileIntA("Comandos", "Chaos_Machine_Mix_Asa_Lv3",60,"..\\MarxD\\Comandos.ini");
	GS.TaxaSucessoCapaDL = GetPrivateProfileIntA("GameServer", "Chaos_Machine_Mix_Capa_DL", 80, "..\\MarxD\\GameServer.ini");
	GS.TaxaSucessoFeatherOfCondor = GetPrivateProfileIntA("Comandos", "Chaos_Machine_Mix_Feather_Of_Condor",65,"..\\MarxD\\Comandos.ini");

	//Configs.cpp (ChatDataSend)
	GetPrivateProfileStringA("Comandos","Ajuda","/ajuda",GS.AjudaCmm,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Resetar","/resetar",GS.ResetarCmm,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Zen","/zen",GS.ZenCmm,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos", "Mudar_Bau", "/bau", GS.BauCmm, 25, "..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos", "Evo", "/evo", GS.EvoCmm, 25, "..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos", "Casamento", "/casar", GS.CasarCmm, 25, "..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos", "Casamento_Aceitar", "/euaceito", GS.AceitarCmm, 25, "..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos", "Casamento_Rejeitar", "/naoaceito", GS.RejeitarCmm, 25, "..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos", "Divorcio", "/divorciar", GS.DivorciarCmm, 25, "..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Post","/post", GS.CommandPost,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","AddStr","/str", GS.CommandStr,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","AddAgi","/agi", GS.CommandAgi,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","AddVit","/vit", GS.CommandVit,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","AddEne","/ene",GS.CommandEne,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","AddCom","/com",GS.CommandCmd,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Limpar_PK","/limparpk",GS.LimparPKcmm,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Total_Online","/totalon",GS.TotalOnlineCmm,25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Mudar_Classe","/classe", GS.MudarClasseCmm, 25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Vender_Resets","/vresets", GS.cmm_VenderResets, 25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Limpar_Inventario","/limparinv", GS.cmm_LimparInventario, 25,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","MasterReset","/masterreset", GS.cmm_MasterReset, 25,"..\\MarxD\\Comandos.ini");

	// - GAME MASTER DEFS
	GetPrivateProfileStringA("Comandos","Personagem_Info","/pinfo",GS.JInfoCmm,25,"..\\MarxD\\Comandos_GM.ini");
	GetPrivateProfileStringA("Comandos","Puxar","/puxar", GS.PuxarCmm, 25,"..\\MarxD\\Comandos_GM.ini");
	GetPrivateProfileStringA("Comandos","Puxar_Todos","/puxartodos", GS.PuxarTodosCmm, 25,"..\\MarxD\\Comandos_GM.ini");
	GetPrivateProfileStringA("Comandos", "Recarregar_Monstros", "/rmonstros", GS.RMCmm, 25, "..\\MarxD\\Comandos_GM.ini");
	GetPrivateProfileStringA("Comandos", "Recarregar_Lojas", "/rlojas", GS.RLCmm, 25, "..\\MarxD\\Comandos_GM.ini");
	GetPrivateProfileStringA("Comandos", "Skin", "/skin", GS.SkinCmm, 25, "..\\MarxD\\Comandos_GM.ini");
	GetPrivateProfileStringA("Comandos","Drop","/drop",GS.DropCmm,25,"..\\MarxD\\Comandos_GM.ini");
	GetPrivateProfileStringA("Comandos","Recarregar_Drop","/rdrop",GS.ReloadDropCmm,25,"..\\MarxD\\Comandos_GM.ini");
	GetPrivateProfileStringA("Comandos","Recarregar_Config","/rconfig",GS.ReloadConfigCmm,25,"..\\MarxD\\Comandos_GM.ini");
	GetPrivateProfileStringA("Comandos","Recarregar_Loja","/rmove",GS.ReloadMoveCmm,25,"..\\MarxD\\Comandos_GM.ini");
	GetPrivateProfileStringA("Comandos","Recarregar_Tudo","/rtudo",GS.ReloadTudoCmm,25,"..\\MarxD\\Comandos_GM.ini");
	GetPrivateProfileStringA("Comandos","Evento","/evento", GS.EventoCmm, 25,"..\\MarxD\\Comandos_GM.ini");
	GetPrivateProfileStringA("Comandos","Set_Evento","/setevento", GS.SetEventoCmm, 25,"..\\MarxD\\Comandos_GM.ini");
	GetPrivateProfileStringA("Comandos","Puxar_Todos_os_GM","/gmrecall", GS.GmPuxarTodosCmm, 25,"..\\MarxD\\Comandos_GM.ini");
	GetPrivateProfileStringA("Comandos","Invocar_Monstros","/invocar", GS.cmm_InvocarMonstro, 25,"..\\MarxD\\Comandos_GM.ini");

	//cmm_LimparInventario.cpp
	GS.cmm_LimparInventario_Ativado = GetPrivateProfileIntA("Comandos", "Limpar_Inventario_Ativado",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_LimparInventario_CtlCode = GetPrivateProfileIntA("Comandos","Limpar_Inventario_CtlCode",0,"..\\MarxD\\Comandos.ini");
	GS.cmm_LimparInventario_Custo	= GetPrivateProfileIntA("Comandos","Limpar_Inventario_Custo",0,"..\\MarxD\\Comandos.ini");
	GS.cmm_LimparInventario_Vip = GetPrivateProfileIntA("Comandos","Limpar_Inventario_Somente_Vip",1,"..\\MarxD\\Comandos.ini");

	//cmm_Aceitar.cpp e Casamento.cpp
	GS.cmm_Casamento_e_AceitarRejeitar_Ativado = GetPrivateProfileIntA("Comandos", "Casamento_Ativado",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_Casamento_e_AceitarRejeitar_Custo = GetPrivateProfileIntA("Comandos","Casamento_Custo",5000000,"..\\MarxD\\Comandos.ini");
	GS.cmm_Casamento_e_AceitarRejeitar_Level = GetPrivateProfileIntA("Comandos","Casamento_Level",150,"..\\MarxD\\Comandos.ini");

	//cmm_AdicionarPontos.cpp
	GS.cmm_Add_Ativado = GetPrivateProfileIntA("Comandos", "Add_Ativado",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_Add_Level = GetPrivateProfileIntA("Comandos","Add_Level",100,"..\\MarxD\\Comandos.ini");
	GS.cmm_Add_Custo = GetPrivateProfileIntA("Comandos","Add_Custo",100000,"..\\MarxD\\Comandos.ini");
	GS.cmm_Add_Delay = GetPrivateProfileIntA("Comandos","Add_Delay",50,"..\\MarxD\\Comandos.ini");

	//cmm_Ajuda.cpp
	GS.cmm_Ajuda_Ativado = GetPrivateProfileIntA("Comandos", "Ajuda_Ativado",1,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Ajuda_1","Ajuda 1",GS.cmm_Ajuda_TmpMsg1,200,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Ajuda_2","Ajuda 2",GS.cmm_Ajuda_TmpMsg2,200,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Ajuda_3","Ajuda 3",GS.cmm_Ajuda_TmpMsg3,200,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Ajuda_4","Ajuda 4",GS.cmm_Ajuda_TmpMsg4,200,"..\\MarxD\\Comandos.ini");
	GetPrivateProfileStringA("Comandos","Ajuda_5","Ajuda 5",GS.cmm_Ajuda_TmpMsg5,200,"..\\MarxD\\Comandos.ini");

	//cmm_Divorciar.cpp
	GS.cmm_Divorcio_Ativado = GetPrivateProfileIntA("Comandos", "Divorcio_Ativado",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_Divorcio_Level = GetPrivateProfileIntA("Comandos","Divorcio_Level",100,"..\\MarxD\\Comandos.ini");
	GS.cmm_Divorcio_Custo = GetPrivateProfileIntA("Comandos","Divorcio_Custo",100000,"..\\MarxD\\Comandos.ini");

	//cmm_DroparItem.cpp
	GS.cmm_Dropar_Ativado = GetPrivateProfileIntA("Comandos", "Drop_Ativado",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_Dropar_CtlCode = GetPrivateProfileIntA("Comandos", "Drop_CtlCode",32,"..\\MarxD\\Comandos.ini");

	//cmm_Evo.cpp
	GS.cmm_Evo_Ativado = GetPrivateProfileIntA("Comandos", "Evo_Ativado",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_Evo_Ativado_Npc = GetPrivateProfileIntA("Comandos", "Evo_Ativado_Npc",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_Evo_CtlCode = GetPrivateProfileIntA("Comandos","Evo_CtlCode",0,"..\\MarxD\\Comandos.ini");
	GS.cmm_Evo_Custo = GetPrivateProfileIntA("Comandos","Evo_Custo",0,"..\\MarxD\\Comandos.ini");
	GS.cmm_Evo_SegundaClasse = GetPrivateProfileIntA("Comandos","Evo_Somente_Segunda_Classe",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_Evo_Vip = GetPrivateProfileIntA("Comandos","Evo_Somente_Vip",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_Evo_Level = GetPrivateProfileIntA("Comandos","Evo_Level", 400,"..\\MarxD\\Comandos.ini");

	//cmm_LimparPK.cpp
	GS.cmm_LimparPK_Ativado = GetPrivateProfileIntA("Comandos", "Limpar_PK_Ativado",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_LimparPK_Level = GetPrivateProfileIntA("Comandos","Limpar_PK_Level",100,"..\\MarxD\\Comandos.ini");
	GS.cmm_LimparPK_Custo = GetPrivateProfileIntA("Comandos","Limpar_PK_Custo",100000,"..\\MarxD\\Comandos.ini");
	GS.cmm_LimparPK_Custo_Vip = GetPrivateProfileIntA("Comandos","Limpar_PK_Custo_Vip",100000,"..\\MarxD\\Comandos.ini");

	//Cmm_MudarBau.cpp
	GS.cmm_MudarBau_Ativado = GetPrivateProfileIntA("Comandos", "Mudar_Bau_Ativado",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_MudarBau_CtlCode = GetPrivateProfileIntA("Comandos","Mudar_Bau_CtlCode",0,"..\\MarxD\\Comandos.ini");
	GS.cmm_MudarBau_Vip_Free = GetPrivateProfileIntA("Comandos","Mudar_Bau_Total_Free",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_MudarBau_Vip_Noob = GetPrivateProfileIntA("Comandos","Mudar_Bau_Total_VipNoob",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_MudarBau_Vip_Pro = GetPrivateProfileIntA("Comandos","Mudar_Bau_Total_VipPro",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_MudarBau_Custo = GetPrivateProfileIntA("Comandos","Mudar_Bau_Custo",0,"..\\MarxD\\Comandos.ini");
	GS.cmm_MudarBau_Ativado_Free = GetPrivateProfileIntA("Comandos", "Mudar_Bau_Ativado_Free",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_MudarBau_Ativado_Vip = GetPrivateProfileIntA("Comandos", "Mudar_Bau_Ativado_Vip",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_MudarBau_Total_Free = GetPrivateProfileIntA("Comandos","Mudar_Bau_Total_Free",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_MudarBau_Total_Vip = GetPrivateProfileIntA("Comandos","Mudar_Bau_Total_Vip",5,"..\\MarxD\\Comandos.ini");
	GS.cmm_MudarBau_Delay = GetPrivateProfileIntA("Comandos","Mudar_Bau_Delay",10,"..\\MarxD\\Comandos.ini");

	//cmm_Post.cpp
	GS.cmm_Post_Ativado = GetPrivateProfileIntA("Comandos", "Post_Ativado",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_Post_Level = GetPrivateProfileIntA("Comandos","Post_Level",100,"..\\MarxD\\Comandos.ini");
	GS.cmm_Post_Resets = GetPrivateProfileIntA("Comandos","Post_Resets_Minimos",5,"..\\MarxD\\Comandos.ini");
	GS.cmm_Post_Custo = GetPrivateProfileIntA("Comandos","Post_Custo",100000,"..\\MarxD\\Comandos.ini");
	GS.cmm_Post_Delay = GetPrivateProfileIntA("Comandos","Post_Delay",10,"..\\MarxD\\Comandos.ini");

	//cmm_Resetar.cpp
	GS.cmm_Resetar_Ativado = GetPrivateProfileIntA("Comandos", "Reset_Ativado",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_Resetar_CtlCode = GetPrivateProfileIntA("Comandos","Reset_CtlCode",0,"..\\MarxD\\Comandos.ini");
	GS.cmm_Resetar_Vip = GetPrivateProfileIntA("Comandos","Resetar_Somente_Vip",1,"..\\MarxD\\Comandos.ini");

	//cmm_Zen.cpp
	GS.cmm_Zen_Ativado = GetPrivateProfileIntA("Comandos", "Zen_Ativado",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_Zen_CtlCode = GetPrivateProfileIntA("Comandos","Zen_CtlCode",0,"..\\MarxD\\Comandos.ini");
	GS.cmm_Zen_Vip = GetPrivateProfileIntA("Comandos","Zen_Somente_Vip",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_Zen_TmpZen = GetPrivateProfileIntA("Comandos","Zen_Quantia",50000000,"..\\MarxD\\Comandos.ini");

	//cmm_TotalOn.cpp
	GS.cmm_TotalOn_Ativado = GetPrivateProfileIntA("Comandos", "Total_Online_Ativado",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_TotalOn_CtlCode = GetPrivateProfileIntA("Comandos","Total_Online_CtlCode",0,"..\\MarxD\\Comandos.ini");

	//cmm_MudarClasse.cpp
	GS.cmm_MudarClasse_Ativado	= GetPrivateProfileIntA("Comandos","Mudar_Classe_Ativado",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_MudarClasse_Level = GetPrivateProfileIntA("Comandos","Mudar_Classe_Level",0,"..\\MarxD\\Comandos.ini");
	GS.cmm_MudarClasse_Custo = GetPrivateProfileIntA("Comandos","Mudar_Classe_Custo",0,"..\\MarxD\\Comandos.ini");
	GS.cmm_MudarClasse_CtlCode = GetPrivateProfileIntA("Comandos","Mudar_Classe_CtlCode",0,"..\\MarxD\\Comandos.ini");
	GS.cmm_MudarClasse_Vip = GetPrivateProfileIntA("Comandos","Mudar_Classe_Somente_Vip",0,"..\\MarxD\\Comandos.ini");

	//cmm_MasterReset.cpp
	GS.cmm_MR_Ativado			= GetPrivateProfileIntA("Comandos","MasterReset_Ativado",1,"..\\MarxD\\Comandos.ini");
	GS.cmm_MR_CtlCode			= GetPrivateProfileIntA("Comandos","MasterReset_CtlCode",0,"..\\MarxD\\Comandos.ini");
	GS.cmm_MR_Custo				= GetPrivateProfileIntA("Comandos","MasterReset_Custo",200000,"..\\MarxD\\Comandos.ini");
	GS.cmm_MR_Recompensa_Tipo	= GetPrivateProfileIntA("Comandos","MasterReset_Tipo",0,"..\\MarxD\\Comandos.ini");
	GS.cmm_MR_Recompensa_Free	= GetPrivateProfileIntA("Comandos","MasterReset_Recompensa_Free",10,"..\\MarxD\\Comandos.ini");
	GS.cmm_MR_Recompensa_Vip	= GetPrivateProfileIntA("Comandos","MasterReset_Recompensa_Vip",15,"..\\MarxD\\Comandos.ini");
	GS.cmm_MR_Resets_Necessario	= GetPrivateProfileIntA("Comandos","MasterReset_Resets_Necessarios",15,"..\\MarxD\\Comandos.ini");

	//Calcharacter
	GS.CC_NumeroInicial[0]		= GetPrivateProfileIntA("DK_BK_BM", "Calcular_a_partir_de", 1000, "..\\MarxD\\Classes.ini");
	GS.CC_NumeroInicial[1]		= GetPrivateProfileIntA("DW_SM_GM", "Calcular_a_partir_de", 1000, "..\\MarxD\\Classes.ini");
	GS.CC_NumeroInicial[2]		= GetPrivateProfileIntA("Elf_ME_HE", "Calcular_a_partir_de", 1000, "..\\MarxD\\Classes.ini");
	GS.CC_NumeroInicial[3]		= GetPrivateProfileIntA("MG_DM", "Calcular_a_partir_de", 1000, "..\\MarxD\\Classes.ini");
	GS.CC_NumeroInicial[4]		= GetPrivateProfileIntA("DL_LE", "Calcular_a_partir_de", 1000, "..\\MarxD\\Classes.ini");

	GS.CC_Multiplicador[0]		= GetPrivateProfileIntA("DK_BK_BM", "Multiplicador_do_Dano", 15, "..\\MarxD\\Classes.ini");
	GS.CC_Multiplicador[1]		= GetPrivateProfileIntA("DW_SM_GM", "Multiplicador_do_Dano", 15, "..\\MarxD\\Classes.ini");
	GS.CC_Multiplicador[2]		= GetPrivateProfileIntA("Elf_ME_HE", "Multiplicador_do_Dano", 15, "..\\MarxD\\Classes.ini");
	GS.CC_Multiplicador[3]		= GetPrivateProfileIntA("MG_DM", "Multiplicador_do_Dano", 15, "..\\MarxD\\Classes.ini");
	GS.CC_Multiplicador[4]		= GetPrivateProfileIntA("DL_LE", "Multiplicador_do_Dano", 15, "..\\MarxD\\Classes.ini");

	//GM & ADM DEFS
	GS.DV_CtlCode			= GetPrivateProfileIntA("Comandos","CtlCode_do_Divulgador",28,"..\\MarxD\\Comandos.ini");
	GS.GM_CtlCode			= GetPrivateProfileIntA("Comandos","CtlCode_do_GameMaster",28,"..\\MarxD\\Comandos.ini");
	GS.SUB_CtlCode			= GetPrivateProfileIntA("Comandos","CtlCode_do_SubAdministrador",30,"..\\MarxD\\Comandos.ini");
	GS.ADM_CtlCode			= GetPrivateProfileIntA("Comandos","CtlCode_do_Administrador",32,"..\\MarxD\\Comandos.ini");
	GS.ADM_Player_CtlCode	= GetPrivateProfileIntA("Comandos","CtlCode_do_Administrador_Jogador",34,"..\\MarxD\\Comandos.ini");

	// - Sistema_pontos.cpp
	GS.Pontos_p_LVL[0]				= GetPrivateProfileIntA("Sistema_de_Pontos","DW_SM_GM", 5,"..\\MarxD\\Pontos_por_Level.ini");
	GS.Pontos_p_LVL[1]				= GetPrivateProfileIntA("Sistema_de_Pontos","DK_BK_BM", 5,"..\\MarxD\\Pontos_por_Level.ini");
	GS.Pontos_p_LVL[2]				= GetPrivateProfileIntA("Sistema_de_Pontos","Elf_ME_HE", 5,"..\\MarxD\\Pontos_por_Level.ini");
	GS.Pontos_p_LVL[3]				= GetPrivateProfileIntA("Sistema_de_Pontos","MG_DM", 7,"..\\MarxD\\Pontos_por_Level.ini");
	GS.Pontos_p_LVL[4]				= GetPrivateProfileIntA("Sistema_de_Pontos","DL_LE", 7,"..\\MarxD\\Pontos_por_Level.ini");
	GS.Pontos_Soma_Normal			= GetPrivateProfileIntA("Sistema_de_Pontos","Soma_Free", 0,"..\\MarxD\\Pontos_por_Level.ini");
	GS.Pontos_Soma_Vip				= GetPrivateProfileIntA("Sistema_de_Pontos","Soma_Vip", 1,"..\\MarxD\\Pontos_por_Level.ini");
	GS.Pontos_Soma_Apos_Quest		= GetPrivateProfileIntA("Sistema_de_Pontos","Soma_Apos_Quest_do_Marlon", 1,"..\\MarxD\\Pontos_por_Level.ini");

	//cmm_PersonagemInfo.cpp
	GS.cmm_PINFO_Ativado = GetPrivateProfileIntA("Comandos", "Jogador_Info_Ativado",1,"..\\MarxD\\Comandos_GM.ini");
	GS.cmm_PINFO_CtlCode = GetPrivateProfileIntA("Comandos", "Jogador_Info_CtlCode",32,"..\\MarxD\\Comandos_GM.ini");

	//cmm_RecarregarConfig.cpp
	GS.cmm_RecarregarConfig_Ativado = GetPrivateProfileIntA("Comandos", "Recarregar_Config_Ativado",1,"..\\MarxD\\Comandos_GM.ini");
	GS.cmm_RecarregarConfig_CtlCode = GetPrivateProfileIntA("Comandos", "Recarregar_Config_CtlCode",32,"..\\MarxD\\Comandos_GM.ini");

	//cmm_RecarregarDrop.cpp
	GS.cmm_RecarregarDrop_Ativado = GetPrivateProfileIntA("Comandos", "Recarregar_Drop_Ativado",1,"..\\MarxD\\Comandos_GM.ini");
	GS.cmm_RecarregarDrop_CtlCode = GetPrivateProfileIntA("Comandos", "Recarregar_Drop_CtlCode",32,"..\\MarxD\\Comandos_GM.ini");

	//cmm_RecarregarLojas.cpp
	GS.cmm_RecarregarLojas_Ativado = GetPrivateProfileIntA("Comandos", "Recarregar_Lojas_Ativado",1,"..\\MarxD\\Comandos_GM.ini");
	GS.cmm_RecarregarLojas_CtlCode = GetPrivateProfileIntA("Comandos", "Recarregar_Lojas_CtlCode",32,"..\\MarxD\\Comandos_GM.ini");

	//cmm_RecarregarMove.cpp
	GS.cmm_RecarregarMove_Ativado = GetPrivateProfileIntA("Comandos", "Recarregar_Move_Ativado",1,"..\\MarxD\\Comandos_GM.ini");
	GS.cmm_RecarregarMove_CtlCode = GetPrivateProfileIntA("Comandos", "Recarregar_Move_CtlCode",32,"..\\MarxD\\Comandos_GM.ini");

	//cmm_RecarregarMonstros.cpp
	GS.cmm_RecarregarMonstros_Ativado = GetPrivateProfileIntA("Comandos", "Recarregar_Monstros_Ativado",1,"..\\MarxD\\Comandos_GM.ini");
	GS.cmm_RecarregarMonstros_CtlCode = GetPrivateProfileIntA("Comandos", "Recarregar_Monstros_CtlCode",32,"..\\MarxD\\Comandos_GM.ini");

	//cmm_RecarregarTudo.cpp
	GS.cmm_RecarregarTudo_Ativado = GetPrivateProfileIntA("Comandos", "Recarregar_Tudo_Ativado",1,"..\\MarxD\\Comandos_GM.ini");
	GS.cmm_RecarregarTudo_CtlCode = GetPrivateProfileIntA("Comandos", "Recarregar_Tudo_CtlCode",32,"..\\MarxD\\Comandos_GM.ini");

	//cmm_Skin.cpp
	GS.cmm_Skin_Ativado = GetPrivateProfileIntA("Comandos", "Skin_Ativado", 1, "..\\MarxD\\Comandos_GM.ini");
	GS.cmm_Skin_CtlCode = GetPrivateProfileIntA("Comandos", "Skin_CtlCode", 0, "..\\MarxD\\Comandos_GM.ini");
	GS.cmm_Skin_Custo	= GetPrivateProfileIntA("Comandos","Skin_Custo", 0, "..\\MarxD\\Comandos_GM.ini");
	GS.Skin_GM_Padrao = GetPrivateProfileIntA("Comandos","Skin_Padrao_GameMaster", 378, "..\\MarxD\\Comandos_GM.ini");

	//cmm_Puxar.cpp
	GS.cmm_Puxar_Ativado	= GetPrivateProfileIntA("Comandos","Puxar_Ativado",1,"..\\MarxD\\Comandos_GM.ini");
	GS.cmm_Puxar_CtlCode = GetPrivateProfileIntA("Comandos","Puxar_CtlCode",0,"..\\MarxD\\Comandos_GM.ini");

	//cmm_PuxarTodos.cpp
	GS.cmm_PuxarTodos_Ativado	= GetPrivateProfileIntA("Comandos","Puxar_Todos_Ativado",1,"..\\MarxD\\Comandos_GM.ini");
	GS.cmm_PuxarTodos_CtlCode = GetPrivateProfileIntA("Comandos","Puxar_Todos_CtlCode",0,"..\\MarxD\\Comandos_GM.ini");

	//cmm_GmPuxarTodos.cpp
	GS.cmm_GmPuxarTodos_Ativado = GetPrivateProfileIntA("Comandos","Puxar_Todos_os_GM_Ativado",1,"..\\MarxD\\Comandos_GM.ini");
	GS.cmm_GmPuxarTodos_CtlCode = GetPrivateProfileIntA("Comandos","Puxar_Todos_os_GM_CtlCode",0,"..\\MarxD\\Comandos_GM.ini");

	//cmm_Evento.cpp
	GS.cmm_Evento_Ativado = GetPrivateProfileIntA("Comandos","Set_Evento_Ativado",1,"..\\MarxD\\Comandos_GM.ini");
	GS.cmm_Evento_CtlCode = GetPrivateProfileIntA("Comandos","Set_Evento_CtlCode",0,"..\\MarxD\\Comandos_GM.ini");
	GS.cmm_Evento_X = 0;
	GS.cmm_Evento_Y = 0;
	GS.cmm_Evento_Mapa = 0;

	// - Comando: cmm_Monstro
	GS.Invocar_Monstro_Ativado = GetPrivateProfileIntA("Comandos","Summonar_Monstros_Ativado",1,"..\\MarxD\\Comandos_GM.ini");
	GS.Invocar_Monstro_CtlCode = GetPrivateProfileIntA("Comandos","Summonar_Monstros_CtlCode",32,"..\\MarxD\\Comandos_GM.ini");
}