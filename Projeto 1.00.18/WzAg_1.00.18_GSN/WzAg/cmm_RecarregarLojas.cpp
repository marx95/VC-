#include "StdAfx.h"

void RecarregarLojas(int aIndex)
{
	if(GS.cmm_RecarregarLojas_Ativado == 0)
	{
		MsgParaJogador("[R. Lojas] Comando desabilitado",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_RecarregarLojas_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[R. Lojas] %s", VerificarCtlCode(aIndex, GS.cmm_RecarregarLojas_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	pShopDataLoad();
	MsgParaJogador("[R. Lojas] Lojas recarregadas!",aIndex);
}