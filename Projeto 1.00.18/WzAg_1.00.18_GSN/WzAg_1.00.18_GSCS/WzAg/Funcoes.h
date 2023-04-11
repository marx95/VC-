//Defines ASM
#define ASM_FUNC(_NAME) __declspec(naked) void _NAME()
#define GET_ADDR(_func) ((DWORD)&_func)
#define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w)           ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))

//Funçoes ASM
void HookThis(DWORD dwMyFuncOffset,DWORD dwJmpOffset);
void SetNop(DWORD dwOffset, int Size);
void SetRetn(DWORD dwOffset);
void SetByte(DWORD dwOffset, BYTE btValue);
void SetWord(DWORD dwOffset, WORD wValue);
void SetDWord(DWORD dwOffset, DWORD dwValue);

//Funçoes GS
void MsgParaTodos(char * Texto, int Tipo);
void DataSendAll(unsigned char* Packet, int Length);
void ServerMsgSend(DWORD wId, int Type, char Sender[20], const char* Message, ...);
void MensagemNaBarraSlide(DWORD PlayerID, LPCTSTR szText, int Color);
void MsgColorida(LPSTR Msg, DWORD aIndex, int Tipo, int Cor);
void MsgParaJogador(char *Msg, DWORD aIndex);
void MsgParaJogadorCentro(char *Msg, DWORD aIndex);
void MsgParaServer(char *Msg, DWORD aIndex);
void gObjWrite(int aIndex,int gObjParam,long int Value);