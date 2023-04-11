//Defines ASM
#define GET_ADDR(_func)		((DWORD)&_func)
#define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w)           ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))
__inline DWORD _ARGB(BYTE a, BYTE r, BYTE g, BYTE b){ return a*16777216 + b*65536 + g*256 + r;}; // in tnotice.h : line 8
#define SET_NUMBERH(x) ( (BYTE)((DWORD)(x)>>(DWORD)8) )
#define SET_NUMBERL(x) ( (BYTE)((DWORD)(x) & 0xFF) )
#define SET_NUMBERHW(x) ( (WORD)((DWORD)(x)>>(DWORD)16) )
#define SET_NUMBERLW(x) ( (WORD)((DWORD)(x) & 0xFFFF) )

//Funçoes ASM
void Hook(DWORD dwMyFuncOffset,DWORD dwJmpOffset);
void SetNop(DWORD dwOffset, int Size);
void SetRet(DWORD dwOffset);
void SetByte(DWORD dwOffset, BYTE btValue);
void SetWord(DWORD dwOffset, WORD wValue);
void SetDWord(DWORD dwOffset, DWORD dwValue);

//Funçoes GS
bool Conectado(int aIndex);
bool Logado(int aIndex);
bool Jogando(int aIndex);
//bool gObjIsConnectedGP(int aIndex);
bool No_Duelo(int aIndex1, int aIndex2);
void Set_Life(int aIndex, int Pontos);
void Set_Mana(int aIndex, int Pontos);
int Pegar_Pontos_por_Level(int aIndex);
void gObjViewportListProtocolDestroy_AP(int aIndex);
void Atualizar_Personagem(int aIndex);
void GCLevelUpMsgSend(int aIndex, int iSendEffect);
void f_Reset(int aIndex);
void f_LimparPK(int aIndex);
bool VerificarGM(int aIndex);
char * VerificarCtlCode(int aIndex, int CtlCode);
char * TipoPersonagem(int aIndex);
//void FixarBalaoGM(int aIndex);
int VerTotalConectado();
int VerTotalLogado();
int VerTotalJogando();
bool Sortear(int Taxa);
void Setar_Zen(int aIndex, unsigned long Zen);
void Dar_Zen(int aIndex, unsigned long Zen);
void Tirar_Zen(int aIndex, unsigned long  Zen);

void PHeadSetB(LPBYTE lpBuf, BYTE head, int size);
void PHeadSubSetB(LPBYTE lpBuf, BYTE head, BYTE sub, int size);

void MsgSlide(int aIndex, LPCTSTR szText, int Color);
void MsgColorida(LPSTR Msg, int aIndex, int Tipo, int Cor);
void MsgPlayer(char *Msg, int aIndex);
void MsgCentro(char *Msg, int aIndex);
void MsgServer(char *Msg, int aIndex, int Tipo);
void NpcChat(char * Msg, int NpcIndex, int aIndex);

int GerarItem(int Grupo, int Index);
bool Procurar(char *OndeProcurar, char *Pesquisar, bool CaseSensitive);
//void Desconectar_Jogadores();

void GS_MsgBox();
void GSMsgBox(char * Titulo, char * Msg);