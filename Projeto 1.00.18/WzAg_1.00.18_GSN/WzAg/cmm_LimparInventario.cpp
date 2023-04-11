#include "StdAfx.h"

void LimparInventario(int aIndex)
{
	if(GS.cmm_LimparInventario_Ativado == 0)
	{
		MsgParaJogador("[Limpar Inv.] Comando desabilitado", aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_LimparInventario_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[Limpar Inv.] %s", VerificarCtlCode(aIndex, GS.cmm_LimparInventario_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	if(gObjCustom[aIndex].Vip < GS.cmm_LimparInventario_Vip)
	{
		MsgParaJogador("[Limpar Inv.] Necessário ser Vip",aIndex);
		return;
	}

	if(GS.cmm_LimparInventario_Custo > gObj(aIndex)->Money)
	{
		char OutputZenFalha[200];
		sprintf_s(OutputZenFalha,"[Limpar Inv.] Necessário %d zen", GS.cmm_LimparInventario_Custo);
		MsgParaJogador(OutputZenFalha, aIndex);
		return;
	}

	//Verifica o inventario
	for(int i = 12; i<76; i++)
	{
		if(gObj(aIndex)->pInventory[i].m_Type != -1)
		{
			gObjInventoryDeleteItem(aIndex, i);
			GCInventoryItemDeleteSend(aIndex, i, 1);
		}
	}

	gObj(aIndex)->Money -= GS.cmm_LimparInventario_Custo;
	GCMoneySend(aIndex, gObj(aIndex)->Money);

	MsgParaJogador("[Limpar Inv.] Limpo com sucesso!", aIndex);
}