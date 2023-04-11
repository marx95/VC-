#include "StdAfx.h"

void Ajuda(int aIndex)
{
	if(GS.cmm_Ajuda_Ativado == 0)
	{
		GCServerMsgStringSend("[Ajuda] Comando desativado!",aIndex,1);
		return;
	}

	if(strlen(GS.cmm_Ajuda_TmpMsg1) > 4) MsgParaJogador(GS.cmm_Ajuda_TmpMsg1, aIndex);
	if(strlen(GS.cmm_Ajuda_TmpMsg2) > 4) MsgParaJogador(GS.cmm_Ajuda_TmpMsg2, aIndex);
	if(strlen(GS.cmm_Ajuda_TmpMsg3) > 4) MsgParaJogador(GS.cmm_Ajuda_TmpMsg3, aIndex);
	if(strlen(GS.cmm_Ajuda_TmpMsg4) > 4) MsgParaJogador(GS.cmm_Ajuda_TmpMsg4, aIndex);
	if(strlen(GS.cmm_Ajuda_TmpMsg5) > 4) MsgParaJogador(GS.cmm_Ajuda_TmpMsg5, aIndex);
}