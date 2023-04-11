struct ObjectStructCustom {
	int Vip;
	int Creditos;
	int Golds;
	int Cashs;

	int Resets;
	int Mrs;
	int CtlCode;

	int BauID;
	bool Bau_Aberto;
	int Bau_Delay;

	int ExpDelayCount;

	int Limite_Pontos;
	bool ChatOn;

	bool Level_Max_Msg;
	int SVIni_Count;

	// - Sistema de Drop
	int Intervalo_Sets;
	int Intervalo_Armamentos;
	int Intervalo_Option;
	int Intervalo_Skill;
	int Intervalo_Luck;
	int Intervalo_Exe;
	int Intervalo_Anci;
	int Intervalo_Misc;
	int Intervalo_Zen;
	bool Drop_Soul;
	bool Drop_Life;
	bool Drop_Bless;
	bool Drop_Creation;
	bool Drop_Chaos;
	bool Drop_Lochs;
	bool Drop_Crest;
};
extern ObjectStructCustom gObjCustom[7400];

struct GameServer {

	// - Sistema Drop
	int DropCore_Intervalo;
	int Drop_Sets;
	int Drop_Armamentos;
	int Drop_Itens_Exe;
	int Drop_Itens_Luck;
	int Drop_Itens_Option;
	int Drop_Itens_Skill;
	int Drop_Itens_Ancient;
	int Drop_Miscelandias;
	int Drop_Zen;

	// - GS
	int Log;
	int Kundun_MaxItens;
	char mssql_ip[25];
	char mssql_db[25];
	char mssql_u[25];
	char mssql_p[25];
	char MsgBox_Msg[1024];
	char MsgBox_Titulo[128];
	unsigned long Experiencia[402];
	bool Cnn_Liberado;
	int Porta_UDP;
	int Level_Maximo;
	int ShadowP_LevelMax;
	int MaxUsers;
	int Ativar_DanoReflete;
	int Setar_Zen_ao_Logar;
	long g_iUserNumber; // - JoinServer
	char Nome_Sala[10]; // - JoinServer
	char Main_Serial[20];
	char Main_Version[10];

	int DV_CtlCode;
	int GM_CtlCode;
	int ADM_CtlCode;
	int SUB_CtlCode;
	int ADM_Player_CtlCode;

	char MsgCentro[64];
	char MsgLateral[64];

	int Limite_Pontos[5];

	int Mix_ItemChaos;
	int Mix_Asa1;
	int Mix_Asa2;
	int Mix_CapaDL;

	int Reset_Tipo;
	int Reset_Pontos[2];
	int Reset_Pontos_Somatoria[2];
	int Pontos_Iniciais[2];
	int Reset_Level[2];

	int Pontos_p_LVL_DW_SM;
	int Pontos_p_LVL_DK_BK;
	int Pontos_p_LVL_Elf_ME;
	int Pontos_p_LVL_MG;
	int Pontos_p_LVL_DL;
	int Pontos_Soma_Normal;
	int Pontos_Soma_Vip;
	int Pontos_Soma_Apos_Quest;

	// - AttackArea
	int Level_Minimo_para_PVP_Qualquer_Mapa;
	int Level_Minimo_para_PVP;
	int PVP1_Mapa_PVP;
	int PVP1_Mapa_a_X;
	int PVP1_Mapa_b_X;
	int PVP1_Mapa_a_Y;
	int PVP1_Mapa_b_Y;
	int PVP2_Mapa_PVP;
	int PVP2_Mapa_a_X;
	int PVP2_Mapa_b_X;
	int PVP2_Mapa_a_Y;
	int PVP2_Mapa_b_Y;
	int PVP1_CordX;
	int PVP1_CordY;
	int PVP2_CordX;
	int PVP2_CordY;

	// - AutoXP
	int AutoXP_Ativado;
	int AutoXP_Porcentagem;
	int AutoXP_Delay;
	int AutoXP_Vip;

	//Sistema Drop
	int TotalSets;
	int TotalArmas;

	// - CalCharacter
	int DW_SM_NumeroInicial;
	int DK_BK_NumeroInicial;
	int Elf_ME_NumeroInicial;
	int MG_NumeroInicial;
	int DL_NumeroInicial;

	int CalCharacter_Numero_Inicial[5];
	int CalCharacter_Multiplicador[5];

	int DW_SM_Multiplicador;
	int DK_BK_Multiplicador;
	int Elf_ME_Multiplicador;
	int MG_Multiplicador;
	int DL_Multiplicador;

	// - NPC's
	int NPC_LPK_Ativado;
	int NPC_LPK_Vip;
	int NPC_LPK_Zen;

	int NPC_Reset_Ativado;
	int NPC_Reset_Vip;
	int NPC_Reset_Zen;

	// - Comandos
	int Add_Ativado;
	int Add_Vip;
	int Add_Zen;

	char Post[16];
	int Post_Ativado;
	int Post_ResetsMin;
	int Post_Len;
	int Post_Vip;
	int Post_Zen;

	char Bau[16];
	int Bau_Ativado;
	int Bau_Len;
	int Bau_Vip;
	int Bau_Zen;
	int Bau_Total_Free;
	int Bau_Total_Vip;

	char LPK[16];
	int LPK_Ativado;
	int LPK_Vip;
	int LPK_Zen;

	char Reset[16];
	int Reset_Ativado;
	int Reset_Vip;
	int Reset_Zen;
	int Reset_SVIni_Ativado;
	int Reset_SVIni_MaxResets;

	char MasterReset[16];
	int MasterReset_Ativado;
	int MasterReset_Vip;
	int MasterReset_Zen;
	int MasterReset_Resets;
	int MasterReset_Premio_Gold[2];
	int MasterReset_Premio_Cash[2];
};
extern GameServer GS;