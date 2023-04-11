#include "StdAfx.h"
	int GS_Tipo;
	unsigned short PontoxMaximos;

	// Limites
	int Limite_BK;
	int Limite_SM;
	int Limite_ME;
	int Limite_MG;
	int Limite_DL;

	// - Comandos: Comandos.cpp
	char AjudaCmm[25];
	char ReloadConfigCmm[25];
	char CommandCmd[10];
	char CommandEne[10];
	char CommandVit[10];
	char CommandAgi[10];
	char CommandStr[10];
	char CommandPost[10];

	//Definições presentes em varios comandos
	int Max_65K;

	// - Comandos: cmm_AdicionarPontos.cpp
	int cmm_Add_Ativado;
	int cmm_Add_Level;
	int cmm_Add_Custo;

	// - CalCharacter
	int DK_BK_BM_NumeroInicial;
	int DK_BK_BM_Multiplicador;
	int DW_SM_GM_NumeroInicial;
	int DW_SM_GM_Multiplicador;
	int Elf_ME_HE_NumeroInicial;
	int Elf_ME_HE_Multiplicador;
	int MG_DM_NumeroInicial;
	int MG_DM_Multiplicador;
	int DL_LE_NumeroInicial;
	int DL_LE_Multiplicador;

	//GM & ADM DEFS
	int DV_CtlCode;
	int GM_CtlCode;
	int SUB_CtlCode;
	int ADM_CtlCode;
	int ADM_Player_CtlCode;

	int cmm_Ajuda_Ativado;
	char cmm_Ajuda_TmpMsg1[128];
	char cmm_Ajuda_TmpMsg2[128];
	char cmm_Ajuda_TmpMsg3[128];
	char cmm_Ajuda_TmpMsg4[128];
	char cmm_Ajuda_TmpMsg5[128];

	int cmm_Post_Ativado;
	int cmm_Post_Level;
	int cmm_Post_Resets;
	int cmm_Post_Custo;