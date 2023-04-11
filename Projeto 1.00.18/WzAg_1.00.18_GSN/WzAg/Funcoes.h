//Defines ASM
#define ASM_FUNC(_NAME) __declspec(naked) void _NAME()
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
void SetRetn(DWORD dwOffset);
void SetByte(DWORD dwOffset, BYTE btValue);
void SetWord(DWORD dwOffset, WORD wValue);
void SetDWord(DWORD dwOffset, DWORD dwValue);

//Funçoes GS
void PHeadSetB(LPBYTE lpBuf, BYTE head, int size);
void PHeadSubSetB(LPBYTE lpBuf, BYTE head, BYTE sub, int size);
bool No_Duelo(int aIndex1, int aIndex2);
int VerTotalOnline();
bool Sortear(int Taxa);
void Set_Life(int aIndex, int Pontos);
void Set_Mana(int aIndex, int Pontos);
void Chat(char * Msg, int aIndex);
void NpcChat(char * Msg, int NpcIndex, int aIndex);
bool VerificarGM(int aIndex);
void FixarBalaoGM(int aIndex);
char * VerificarCtlCode(int aIndex, int CtlCode);
char * TipoPersonagem(int aIndex);
void MsgParaTodos(char * Texto, int Tipo);
void MensagemNaBarraSlide(DWORD PlayerID, LPCTSTR szText, int Color);
void MsgColorida(LPSTR Msg, int aIndex, int Tipo, int Cor);
void MsgParaJogador(char *Msg, int aIndex);
void MsgParaJogadorCentro(char *Msg, int aIndex);
void MsgParaServer(char *Msg, int aIndex);
int GerarItem(int Grupo, int Index);
bool Procurar(char *OndeProcurar, char *Pesquisar, bool CaseSensitive);
void GS_MsgBox();
void GSMsgBox(char * Titulo, char * Msg);
void gObjViewportListProtocolDestroy_AP(int aIndex);
void Atualizar_Personagem(int aIndex);