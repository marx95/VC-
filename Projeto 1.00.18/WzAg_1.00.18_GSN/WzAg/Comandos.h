// - Sistema de Add Pontos
bool VerificarPontos(int aIndex, BYTE Tipo);
void AdicionarPontos(int aIndex, LPCSTR lpBuffer, int Tipo);

// - Sistema de MudarBau
void MudarBau_Timer();
void MudarBau(int aIndex, char * Msg);

// - Sistema de Post
void Post(int aIndex,char * msg);
void Post_Timer();

// - Comandos
bool ChatDataSend(int aIndex,LPBYTE Protocol);
void LimparPK(int aIndex, int Tipo);
void Ajuda(int aIndex);
void ReloadConfig(int aIndex);
void ReloadDrop(int aIndex);
void ReloadTudo(int aIndex);
void DroparItem(int aIndex,char * msg);
void PersonagemInfo(int aIndex, char NomeBusca[25]);
void Resetar(int aIndex);
void Zen(int aIndex, int Tipo);
void MudarSkin(int aIndex, char * Msg);
void Evoluir(int aIndex, int Tipo);
void RecarregarMonstros(int aIndex);
void RecarregarLojas(int aIndex);
void RecarregarMove(int aIndex);
void Casar(int aIndex, char *Nome);
void AceitarRejeitar(int aIndex, int Tipo);
void Divorciar(int aIndex);
void TotalOnline(int aIndex);
void MudarClasse(int aIndex, char *Classe);
void Puxar(int aIndex, char *Nome);
void PuxarTodos(int aIndex);
void GmPuxarTodos(int aIndex);
void SetarEvento(int aIndex, char *Info);
void GMFala(int aIndex, char *Msg);
void LimparInventario(int aIndex);
void gMoveCmm(int aIndex, char *Msg);
void InvocarPET(int aIndex,char * msg);
void ChatOff(int aIndex, char *Nome);
void ChatOn(int aIndex, char *Nome);
void MasterReset(int aIndex);