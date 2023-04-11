#include "stdafx.h"

void cmm_rconfig(int aIndex)
{
	if(gObjCustom[aIndex].CtlCode < GS.ADM_CtlCode) return;
		
	MsgServer("Server: Recarregando as configurações...", aIndex, 1);
	Sleep(5);
	Ler_GSC();
	pShopDataLoad();
	Sleep(5);
	GameMonsterAllCloseAndReLoad();
	Sleep(5);
	MsgServer("Server: Configurações regarregadas!", aIndex, 1);

	// - Re-Calcula o CalCharacter
	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(Jogando(i)) CalCharacterEx(i);
	}

	MsgPlayer("[R. Config] Sucesso!", aIndex);
}