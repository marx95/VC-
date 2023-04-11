#include "windows.h"
bool CharCore(int aIndex, LPBYTE Packet);

void cmm_Post(int aIndex, char * Msg);
void cmm_Bau(int aIndex, char * Msg);

bool Verificar_Pontos(int aIndex, BYTE Tipo);
void cmm_AddPontos(int aIndex, char * Msg, int Tipo);

void cmm_LimparPK(int aIndex);
void cmm_Reset(int aIndex);
void cmm_MasterReset(int aIndex);
void cmm_DC(int aIndex, char * TmpNome);
void cmm_gMove(int aIndex, char * Msg);
void cmm_puxar(int aIndex, char * Nick);
void cmm_puxartodos(int aIndex);
void cmm_rconfig(int aIndex);
void cmm_drop(int aIndex, char * msg);
void cmm_chuva(int aIndex, char * msg);