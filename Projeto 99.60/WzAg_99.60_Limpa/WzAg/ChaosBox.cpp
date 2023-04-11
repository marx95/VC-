#include "stdafx.h"

void ChaosMachineFalhou(int aIndex)
{
	ChaosBoxInit(gObj(aIndex));
	GCUserChaosBoxSend(gObj(aIndex), 0);
	BYTE btMsg[10] = {0xC1, 0x0A, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
	DataSend(aIndex, (LPBYTE)&btMsg, btMsg[1]);
}

void CriarItemChaos(int aIndex)
{
	gObj(aIndex)->ChaosLock = 1;

	int ItemSorteado;
	switch(rand()%3)
	{
		case 0: ItemSorteado = GerarItem(2, 6); break; // Chaos Dragon Axe
		case 1: ItemSorteado = GerarItem(4, 6); break; // Golden Crossbow
		case 2: ItemSorteado = GerarItem(5, 7); break; // Chaos Lightning Staff
	}

	if(Sortear(GS.Mix_ItemChaos))
	{
		ItemSerialCreateSend(aIndex, 0xff, 0, 0, ItemSorteado, (rand()%3), 255, (rand()%2), (rand()%2), 0, -1, 0, 0);
	}else
	{
		ChaosMachineFalhou(aIndex);
	}

	Tirar_Zen(aIndex, 5000000);
	gObj(aIndex)->ChaosLock = 0;
}

void CriarPrimeiraAsa(int aIndex)
{
	gObj(aIndex)->ChaosLock = 1;
	int ItemSorteado;

	switch(gObj(aIndex)->Class)
	{
		case 0: ItemSorteado = GerarItem(12, 1); break; //SM
		case 1: ItemSorteado = GerarItem(12, 2); break; //BK
		case 2: ItemSorteado = GerarItem(12, 0); break; //ELF
		case 3: ItemSorteado = GerarItem(12, rand()%3); break; //MG
		case 4: ItemSorteado = GerarItem(12, rand()%3); break; //DL
	}

	if(Sortear(GS.Mix_Asa1))
	{
		ItemSerialCreateSend(aIndex, 0xff, 0, 0, ItemSorteado, (rand()%3), 255, (rand()%2), (rand()%2), 0, -1, 0, 0);
	}else
	{
		ChaosMachineFalhou(aIndex);
	}

	Tirar_Zen(aIndex, 5000000);
	gObj(aIndex)->ChaosLock = 0;
}

void CriarSegundaAsa(int aIndex)
{
	gObj(aIndex)->ChaosLock = 1;

	int ItemSorteado;
	switch(gObj(aIndex)->Class)
	{
		case 0: ItemSorteado = GerarItem(12, 4); break; //SM
		case 1: ItemSorteado = GerarItem(12, 5); break; //BK
		case 2: ItemSorteado = GerarItem(12, 3); break; //ELF
		case 3: ItemSorteado = GerarItem(12, 6); break; //MG
		case 4: ItemSorteado = GerarItem(12, 3)+(rand()%4); break; //DL
	}

	if(Sortear(GS.Mix_Asa2))
	{
		ItemSerialCreateSend(aIndex, 0xff, 0, 0, ItemSorteado, (rand()%3), 255, (rand()%2), (rand()%2), 0, -1, 0, 0);
	}else
	{
		ChaosMachineFalhou(aIndex);
	}

	Tirar_Zen(aIndex, 5000000);
	gObj(aIndex)->ChaosLock = 0;
}

void CriarCapaDL(int aIndex)
{
	gObj(aIndex)->ChaosLock = 1;

	if(Sortear(GS.Mix_CapaDL))
	{
		ItemSerialCreateSend(aIndex, 0xff, 0, 0, GerarItem(13, 30), (rand()%3), 255, (rand()%2), (rand()%2), 0, -1, 0, 0);
	}else
	{
		ChaosMachineFalhou(aIndex);
	}

	Tirar_Zen(aIndex, 5000000);
	gObj(aIndex)->ChaosLock = 0;
}

bool CGChaosBoxItemMixButtonClick(struct PMSG_CHAOSMIX* aRecv, int aIndex)
{
	if(!Jogando(aIndex)) return true;

	if(aRecv->Type == 0x01)
	{
		CriarItemChaos(aIndex);
		return true;
	}

	if(aRecv->Type == 0x0B)
	{
		CriarPrimeiraAsa(aIndex);
		return true;
	}

	if(aRecv->Type == 0x18)
	{
		CriarCapaDL(aIndex);
		return true;
	}

	if(aRecv->Type == 0x07)
	{
		CriarSegundaAsa(aIndex);
		return true;
	}

	return false;
}
