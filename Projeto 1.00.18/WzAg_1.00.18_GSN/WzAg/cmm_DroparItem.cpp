#include "StdAfx.h"

void DroparItem(int aIndex, char * msg)
{

	if(GS.cmm_Dropar_Ativado == 0)
	{
		MsgParaJogador("[Drop] Comando desabilitado",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_Dropar_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[Drop] %s", VerificarCtlCode(aIndex, GS.cmm_Dropar_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}
	
	int spaces = 0;
	int TmpLen = strlen(msg);
	for(int i=0; i<TmpLen; i++)
	{
		if(msg[i] == ' ') spaces++;
	}

	if(spaces < 7)
	{
		MsgParaJogador("[Drop] Tente /drop X1 X2 X3 X4 X5 X6 X7",aIndex);
		return;
	}

	BYTE ItemType, ItemNr, ItemLevel, ItemSkill, ItemLuck, ItemOpt, ItemExc;
	sscanf_s(msg , "%d %d %d %d %d %d %d", &ItemType, &ItemNr, &ItemLevel, &ItemSkill, &ItemLuck, &ItemOpt, &ItemExc);

	if(ItemType < 0 || ItemLevel < 0 || ItemLevel > 13 || ItemSkill < 0 || ItemSkill > 1 || ItemOpt < 0 || ItemOpt > 7 || ItemExc < 0 || ItemExc > 48)
	{
		MsgParaJogador("[Drop] Tente /drop X1 X2 X3 X4 X5 X6 X7",aIndex);
		return;
	}

	int Item = GerarItem(ItemType, ItemNr);
	ItemSerialCreateSend(aIndex , gObj(aIndex)->MapNumber, (BYTE)gObj(aIndex)->X, (BYTE)gObj(aIndex)->Y, Item, ItemLevel , 0, ItemSkill, ItemLuck, ItemOpt, aIndex, ItemExc, 0);
	MsgParaJogador("[Drop] Item dropado!",aIndex);
}