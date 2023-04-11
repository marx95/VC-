#include "stdafx.h"

struct GsConfig
{
	char MsgBox_Msg[512];
	char MsgBox_Titulo[256];

	char mssql_ip[32];
	char mssql_db[32];
	char mssql_u[32];
	char mssql_p[32];

	int GS_Tipo;
	int Log;
	int Ativar_Reflete;

	unsigned short PontoxMaximos;
	int ShadowP_MaxLevel;
	int LevelMaximo;
	int Experiencia[415];

	//Valores originais
	unsigned int Original_Fortitute_Vit;
	unsigned int Original_Fortitute_Ene;
	
	unsigned int Original_SoulBarrier_Agi;
	unsigned int Original_SoulBarrier_Ene;
	unsigned int Original_SoulBarrier_Taxa1;
	unsigned int Original_SoulBarrier_Taxa2;

	//Sistema de PVP
	int Level_Minimo_para_PVP_Qualquer_Mapa;
	int Level_Minimo_para_PVP;		// - Comando /pvp1 e /pvp2

	// - Comando /pvp1
	int PVP1_Mapa_PVP;					
	int PVP1_Mapa_a_X;
	int PVP1_Mapa_a_Y;
	int PVP1_Mapa_b_X;
	int PVP1_Mapa_b_Y;
	int PVP1_CordX;					// <-Respawn
	int PVP1_CordY;					// <-Respawn

	// - Comando /pvp2
	int PVP2_Mapa_PVP;					
	int PVP2_Mapa_a_X;
	int PVP2_Mapa_a_Y;
	int PVP2_Mapa_b_X;
	int PVP2_Mapa_b_Y;
	int PVP2_CordX;					// <-Respawn
	int PVP2_CordY;					// <-Respawn

	//Noticias
	int Noticias_Ativado;
	int Noticias_Tempo;
	int Noticias_Info;
	char Noticia_A[255];
	char Noticia_B[255];
	char Noticia_C[255];
	char Noticia_D[255];

	char Noticia_E[255];
	char Noticia_F[255];
	char Noticia_G[255];
	char Noticia_H[255];

	char Noticia_I[255];
	char Noticia_J[255];
	char Noticia_K[255];
	char Noticia_L[255];

	char Noticia_M[255];
	char Noticia_N[255];
	char Noticia_O[255];
	char Noticia_P[255];

	char Noticia_Q[255];
	char Noticia_R[255];
	char Noticia_S[255];
	char Noticia_T[255];

	// Limites
	int Limite_Pontos[5];

	//MensagemLateral.cpp
	char MSGLateral[255];
	char MSGLateral_ConnectMsg[255];
	int Skin_GM_Padrao;

	//NPC.cpp
	int NpcRst;
	int MapaRst;

	int NpcPK;
	int MapaPK;

	//Reset.cpp
	int Func_Reset_Ativado;
	int Func_Reset_Limite;
	int Func_Reset_Level_Free;
	int Func_Reset_Custo;
	int Func_Reset_Custo_Vip;
	int Func_Reset_PontosIni_Free;
	int Func_Reset_Pontos_Free;
	int Func_Reset_Level_Vip;
	int Func_Reset_PontosIni_Vip;
	int Func_Reset_Pontos_Vip;
	int Func_Reset_Tipo;

	//DropCore.cpp
	int TotalSets;
	int TotalArmas;
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

	// - Comandos: Comandos.cpp
	char ResetarCmm[25];
	char JInfoCmm[25];
	char DropCmm[25];
	char AjudaCmm[25];
	char LimparPKcmm[25];
	char ReloadTudoCmm[25];
	char ReloadConfigCmm[25];
	char ReloadLojaCmm[25];
	char ReloadMoveCmm[25];
	char ReloadDropCmm[25];
	char CommandCmd[10];
	char CommandEne[10];
	char CommandVit[10];
	char CommandAgi[10];
	char CommandStr[10];
	char CommandPost[10];
	char DivorciarCmm[25];
	char RejeitarCmm[25];
	char AceitarCmm[25];
	char CasarCmm[25];
	char RLCmm[25];
	char RMCmm[25];
	char EvoCmm[25];
	char SkinCmm[25];
	char BauCmm[25];
	char ZenCmm[25];
	char TotalOnlineCmm[25];
	char MudarClasseCmm[25];
	char PuxarCmm[25];
	char PuxarTodosCmm[25];
	char EventoCmm[25];
	char SetEventoCmm[25];
	char GmPuxarTodosCmm[25];
	char cmm_VenderResets[25];
	char cmm_LimparInventario[25];
	char cmm_InvocarMonstro[25];
	char cmm_MasterReset[25];

	// - Comandos: cmm_Aceitar.cpp e Casamento.cpp
	int cmm_Casamento_e_AceitarRejeitar_Ativado;
	int cmm_Casamento_e_AceitarRejeitar_Custo;
	int cmm_Casamento_e_AceitarRejeitar_Level;

	// - Comandos: cmm_AdicionarPontos.cpp
	int cmm_Add_Ativado;
	int cmm_Add_Level;
	int cmm_Add_Custo;
	int cmm_Add_Delay;

	// - Comandos: cmm_Ajuda.cpp
	int cmm_Ajuda_Ativado;
	char cmm_Ajuda_TmpMsg1[255];
	char cmm_Ajuda_TmpMsg2[255];
	char cmm_Ajuda_TmpMsg3[255];
	char cmm_Ajuda_TmpMsg4[255];
	char cmm_Ajuda_TmpMsg5[255];

	// - Comandos: cmm_Divorciar.cpp
	int cmm_Divorcio_Ativado;
	int cmm_Divorcio_Level;
	int cmm_Divorcio_Custo;

	// - Comandos: cmm_DroparItem.cpp
	int cmm_Dropar_Ativado;
	int cmm_Dropar_CtlCode;

	// - Comandos: cmm_Evo.cpp
	int cmm_Evo_Ativado;
	int cmm_Evo_Ativado_Npc;
	int cmm_Evo_CtlCode;
	int cmm_Evo_Custo;
	int cmm_Evo_SegundaClasse;
	int cmm_Evo_Vip;
	int cmm_Evo_Level;

	// - Comandos: cmm_LimparPK.cpp
	int cmm_LimparPK_Ativado;
	int cmm_LimparPK_Level;
	int cmm_LimparPK_Custo;
	int cmm_LimparPK_Custo_Vip;

	// - Comandos: cmm_MudarBau.cpp
	int cmm_MudarBau_Ativado;
	int cmm_MudarBau_CtlCode;
	int cmm_MudarBau_Vip_Free;
	int cmm_MudarBau_Vip_Noob;
	int cmm_MudarBau_Vip_Pro;
	int cmm_MudarBau_Custo;
	int cmm_MudarBau_Ativado_Free;
	int cmm_MudarBau_Ativado_Vip;
	int cmm_MudarBau_Total_Free;
	int cmm_MudarBau_Total_Vip;
	int cmm_MudarBau_Delay;

	// - Comandos: cmm_PersonagemInfo.cpp
	int cmm_PINFO_Ativado;
	int cmm_PINFO_CtlCode;

	// - Comandos: cmm_Post.cpp
	int cmm_Post_Ativado;
	int cmm_Post_Level;
	int cmm_Post_Resets;
	int cmm_Post_Custo;
	int cmm_Post_Delay;

	// - Comandos: cmm_RecarregarConfig.cpp
	int cmm_RecarregarConfig_Ativado;
	int cmm_RecarregarConfig_CtlCode;

	// - Comandos: cmm_RecarregarDrop.cpp
	int cmm_RecarregarDrop_Ativado;
	int cmm_RecarregarDrop_CtlCode;

	// - Comandos: cmm_RecarregarLojas.cpp
	int cmm_RecarregarLojas_Ativado;
	int cmm_RecarregarLojas_CtlCode;

	// - Comandos: cmm_RecarregarMove.cpp
	int cmm_RecarregarMove_Ativado;
	int cmm_RecarregarMove_CtlCode;

	// - Comandos: cmm_RecarregarMonstros.cpp
	int cmm_RecarregarMonstros_Ativado;
	int cmm_RecarregarMonstros_CtlCode;

	// - Comandos: cmm_RecarregarTudo.cpp
	int cmm_RecarregarTudo_Ativado;
	int cmm_RecarregarTudo_CtlCode;

	// - Comandos: cmm_Resetar.cpp
	int cmm_Resetar_Ativado;
	int cmm_Resetar_CtlCode;
	int cmm_Resetar_Vip;

	// - Comandos: cmm_Skin.cpp
	int cmm_Skin_Ativado;
	int cmm_Skin_CtlCode;
	int cmm_Skin_Custo;

	// - Comandos: cmm_Zen.cpp
	int cmm_Zen_Ativado;
	int cmm_Zen_CtlCode;
	int cmm_Zen_Vip;
	int cmm_Zen_TmpZen;

	// - Comandos: cmm_TotalOn.cpp
	int cmm_TotalOn_Ativado;
	int cmm_TotalOn_CtlCode;

	// - Comandos: cmm_MudarClasse.cpp
	int cmm_MudarClasse_Ativado;
	int cmm_MudarClasse_Level;
	int cmm_MudarClasse_Custo;
	int cmm_MudarClasse_CtlCode;
	int cmm_MudarClasse_Vip;

	// - Comandos: cmm_Puxar.cpp
	int cmm_Puxar_Ativado;
	int cmm_Puxar_CtlCode;

	// - Comandos: cmm_PuxarTodos.cpp
	int cmm_PuxarTodos_Ativado;
	int cmm_PuxarTodos_CtlCode;

	// - Comandos: cmm_GmPuxarTodos.cpp
	int cmm_GmPuxarTodos_Ativado;
	int cmm_GmPuxarTodos_CtlCode;

	// - Comandos Evento
	int cmm_Evento_X;
	int cmm_Evento_Y;
	int cmm_Evento_Mapa;
	int cmm_Evento_Ativado;
	int cmm_Evento_CtlCode;

	// - Comando: cmm_Monstro
	int Invocar_Monstro_Ativado;
	int Invocar_Monstro_CtlCode;

	//GM & ADM DEFS
	int DV_CtlCode;
	int GM_CtlCode;
	int SUB_CtlCode;
	int ADM_CtlCode;
	int ADM_Player_CtlCode;

	//Npc Maluco
	int Npc_Maluco_Estado;
	int Npc_Maluco_Ativado;
	int Npc_Maluco_Duracao;
	int Npc_Maluco_Setar_Evento;
	int Npc_Maluco_Anuncios_Previo;
	int Npc_Maluco_Segunda;
	int Npc_Maluco_Terca;
	int Npc_Maluco_Quarta;
	int Npc_Maluco_Quinta;
	int Npc_Maluco_Sexta;
	int Npc_Maluco_Sabado;
	int Npc_Maluco_Domingo;

	int Npc_Maluco_Hora_Segunda;
	int Npc_Maluco_Hora_Terca;
	int Npc_Maluco_Hora_Quarta;
	int Npc_Maluco_Hora_Quinta;
	int Npc_Maluco_Hora_Sexta;
	int Npc_Maluco_Hora_Sabado;
	int Npc_Maluco_Hora_Domingo;

	int Npc_Maluco_Minuto_Segunda;
	int Npc_Maluco_Minuto_Terca;
	int Npc_Maluco_Minuto_Quarta;
	int Npc_Maluco_Minuto_Quinta;
	int Npc_Maluco_Minuto_Sexta;
	int Npc_Maluco_Minuto_Sabado;
	int Npc_Maluco_Minuto_Domingo;

	//Limpar Inventario
	int cmm_LimparInventario_Ativado;
	int cmm_LimparInventario_CtlCode;
	int cmm_LimparInventario_Custo;
	int cmm_LimparInventario_Vip;

	// - cmm_MasterReset
	int cmm_MR_Ativado;
	int cmm_MR_CtlCode;
	int cmm_MR_Custo;
	int cmm_MR_Recompensa_Tipo;
	int cmm_MR_Recompensa_Free;
	int cmm_MR_Recompensa_Vip;
	int cmm_MR_Resets_Necessario;

	// - CalCharacter
	int CC_NumeroInicial[5];
	int CC_Multiplicador[5];
	
	// - ChaosBox
	int TaxaSucessoItemChaos;
	int TaxaSucessoPrimeiraAsa;
	int TaxaSucessoSegundaAsa;
	int TaxaSucessoTerceiraAsa;
	int TaxaSucessoCapaDL;
	int TaxaSucessoFeatherOfCondor;

	// - Pontos por lvl
	int Pontos_p_LVL[5];
	int Pontos_Soma_Normal;
	int Pontos_Soma_Vip;
	int Pontos_Soma_Apos_Quest;
};
extern GsConfig GS;