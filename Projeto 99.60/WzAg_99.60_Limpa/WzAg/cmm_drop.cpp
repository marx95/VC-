#include "StdAfx.h"

void cmm_drop(int aIndex, char * msg)
{
	if(gObjCustom[aIndex].CtlCode < GS.ADM_CtlCode) return;
	
	int spaces = 0;
	for(int i=0; i<(int)strlen(msg); i++)
	{
		if(msg[i] == ' ') spaces++;
	}

	if(spaces < 6)
	{
		MsgPlayer("[Drop] Tente /drop X1 X2 X3 X4 X5 X6 X7.", aIndex);
		return;
	}

	int ItemGrupo, ItemIndex, ItemLevel, ItemSkill, ItemLuck, ItemOpt, ItemExe;
	sscanf_s(msg , "%d %d %d %d %d %d %d", &ItemGrupo, &ItemIndex, &ItemLevel, &ItemSkill, &ItemLuck, &ItemOpt, &ItemExe);

	if(ItemGrupo < 0 || ItemIndex < 0 || ItemLevel < 0 || ItemLevel > 13 || ItemSkill < 0 || ItemSkill > 1 || ItemOpt < 0 || ItemOpt > 7 || ItemExe < 0 || ItemExe > 55)
	{
		MsgPlayer("[Drop] Tente /drop X1 X2 X3 X4 X5 X6 X7.", aIndex);
		return;
	}

	int ItemNr		= GerarItem(ItemGrupo, ItemIndex);

	ItemSerialCreateSend(aIndex, gObj(aIndex)->MapNumber, (BYTE)gObj(aIndex)->X, (BYTE)gObj(aIndex)->Y, ItemNr, ItemLevel, 55, 0, ItemLuck, ItemOpt, aIndex, ItemExe, 0);
	MsgPlayer("[Drop] Item dropado!", aIndex);
}