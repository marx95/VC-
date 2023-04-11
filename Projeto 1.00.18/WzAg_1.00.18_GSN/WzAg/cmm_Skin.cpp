#include "StdAfx.h"

void MudarSkin(int aIndex, char * Msg)
{
	int SkinID	= atoi(Msg);

	if(GS.cmm_Skin_Ativado == 0)
	{
		MsgParaJogador("[Skin] Comando desabilitado",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_Skin_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[Skin] %s", VerificarCtlCode(aIndex, GS.cmm_Skin_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	if(SkinID == -2) SkinID = GS.Skin_GM_Padrao;
	if(SkinID > 380)
	{
		MsgParaJogador("[Skin] ID inexistente, tente -2 ou de 0 á 380!", aIndex);
		return;
	}

	gObj(aIndex)->m_Change = SkinID;
	gObjViewportListProtocolCreate(gObj(aIndex));
	MsgParaJogador("[Skin] Skin trocado com sucesso!", aIndex);
}