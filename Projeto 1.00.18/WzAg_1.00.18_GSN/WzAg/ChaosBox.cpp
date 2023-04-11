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
	if(gObj(aIndex)->ChaosLock == 0 && gObj(aIndex)->m_bPShopOpen == 0)
	{
		gObj(aIndex)->ChaosLock = 1;

		int ItemSorteado;
		switch(rand()%3)
		{
			case 0: ItemSorteado = GerarItem(2, 6); break; // Chaos Dragon Axe
			case 1: ItemSorteado = GerarItem(4, 6); break; // Golden Crossbow
			case 2: ItemSorteado = GerarItem(5, 7); break; // Chaos Lightning Staff
		}

		if(Sortear(GS.TaxaSucessoItemChaos))
		{
			ItemSerialCreateSend(aIndex, 0xff, 0, 0, ItemSorteado, (rand()%3), 255, (rand()%2), (rand()%2), 0, -1, 0, 0);
		}else
		{
			ChaosMachineFalhou(aIndex);
		}

		gObj(aIndex)->Money -= 500000;
		GCMoneySend(aIndex, gObj(aIndex)->Money);
		gObj(aIndex)->ChaosLock = 0;
	}else
	{
		MsgParaJogador("Ocorreu algum erro! RELOGUE AGORA!", aIndex);
	}
}

void CriarPrimeiraAsa(int aIndex)
{
	if(gObj(aIndex)->ChaosLock == 0 && gObj(aIndex)->m_bPShopOpen == 0)
	{
		gObj(aIndex)->ChaosLock = 1;
		int ItemSorteado;

		switch(gObj(aIndex)->DbClass)
		{
			case 0: ItemSorteado = GerarItem(12, 1); break; //SM
			case 1: ItemSorteado = GerarItem(12, 1); break; //SM
			case 2: ItemSorteado = GerarItem(12, 1); break; //SM

			case 16: ItemSorteado = GerarItem(12, 2); break; //BK
			case 17: ItemSorteado = GerarItem(12, 2); break; //BK
			case 18: ItemSorteado = GerarItem(12, 2); break; //BK

			case 32: ItemSorteado = GerarItem(12, 0); break; //ELF
			case 33: ItemSorteado = GerarItem(12, 0); break; //ELF
			case 34: ItemSorteado = GerarItem(12, 0); break; //ELF

			case 48: ItemSorteado = GerarItem(12, rand()%3); break; //MG
			case 49: ItemSorteado = GerarItem(12, rand()%3); break; //MG

			case 64: ItemSorteado = GerarItem(12, rand()%3); break; //DL
			case 65: ItemSorteado = GerarItem(12, rand()%3); break; //DL
		}

		if(Sortear(GS.TaxaSucessoPrimeiraAsa))
		{
			ItemSerialCreateSend(aIndex, 0xff, 0, 0, ItemSorteado, (rand()%3), 255, (rand()%2), (rand()%2), 0, -1, 0, 0);
		}else
		{
			ChaosMachineFalhou(aIndex);
		}

		gObj(aIndex)->Money -= 500000;
		GCMoneySend(aIndex, gObj(aIndex)->Money);
		gObj(aIndex)->ChaosLock = 0;
	}else
	{
		MsgParaJogador("Ocorreu algum erro! RELOGUE AGORA!", aIndex);
	}
}

void CriarSegundaAsa(int aIndex)
{
	if(gObj(aIndex)->ChaosLock == 0 && gObj(aIndex)->m_bPShopOpen == 0)
	{
		gObj(aIndex)->ChaosLock = 1;
		int ItemSorteado;
		switch(gObj(aIndex)->DbClass)
		{
			case 0: ItemSorteado = GerarItem(12, 4); break; //SM
			case 1: ItemSorteado = GerarItem(12, 4); break; //SM
			case 2: ItemSorteado = GerarItem(12, 4); break; //SM

			case 16: ItemSorteado = GerarItem(12, 5); break; //BK
			case 17: ItemSorteado = GerarItem(12, 5); break; //BK
			case 18: ItemSorteado = GerarItem(12, 5); break; //BK

			case 32: ItemSorteado = GerarItem(12, 3); break; //ELF
			case 33: ItemSorteado = GerarItem(12, 3); break; //ELF
			case 34: ItemSorteado = GerarItem(12, 3); break; //ELF

			case 48: ItemSorteado = GerarItem(12, 6); break; //MG
			case 49: ItemSorteado = GerarItem(12, 6); break; //MG

			case 64: ItemSorteado = GerarItem(12, 3)+(rand()%4); break; //DL
			case 65: ItemSorteado = GerarItem(12, 3)+(rand()%4); break; //DL
		}

		if(Sortear(GS.TaxaSucessoSegundaAsa))
		{
			ItemSerialCreateSend(aIndex, 0xff, 0, 0, ItemSorteado, (rand()%3), 255, (rand()%2), (rand()%2), 0, -1, 0, 0);
		}else
		{
			ChaosMachineFalhou(aIndex);
		}

		gObj(aIndex)->Money -= 5000000;
		GCMoneySend(aIndex, gObj(aIndex)->Money);
		gObj(aIndex)->ChaosLock = 0;
	}else
	{
		MsgParaJogador("Ocorreu algum erro! RELOGUE AGORA!", aIndex);
	}
}

void CriarCapaDL(int aIndex)
{
	if(gObj(aIndex)->ChaosLock == 0 && gObj(aIndex)->m_bPShopOpen == 0)
	{
		gObj(aIndex)->ChaosLock = 1;

		if(Sortear(GS.TaxaSucessoCapaDL))
		{
			ItemSerialCreateSend(aIndex, 0xff, 0, 0, GerarItem(13, 30), (rand()%3), 255, (rand()%2), (rand()%2), 0, -1, 0, 0);
		}else
		{
			ChaosMachineFalhou(aIndex);
		}

		gObj(aIndex)->Money -= 5000000;
		GCMoneySend(aIndex, gObj(aIndex)->Money);
		gObj(aIndex)->ChaosLock = 0;
	}else
	{
		MsgParaJogador("Ocorreu algum erro! RELOGUE AGORA!", aIndex);
	}
}

void CriarFeatherOfCondor(int aIndex) 
{
	if((gObj(aIndex)->ChaosLock == 0) && (gObj(aIndex)->m_bPShopOpen == 0)) 
	{
		gObj(aIndex)->ChaosLock = 1;

		if(Sortear(GS.TaxaSucessoFeatherOfCondor))
		{
			ItemSerialCreateSend(aIndex, 0xff, 0, 0, GerarItem(13, 53), 0, 255, 0, 0, 0, -1, 0, 0);
		}else
		{
			ChaosMachineFalhou(aIndex);
		}

		gObj(aIndex)->Money -= 2000000;
		GCMoneySend(aIndex, gObj(aIndex)->Money);
		gObj(aIndex)->ChaosLock = 0;
	}else
	{
		MsgParaJogador("Ocorreu algum erro! RELOGUE AGORA!", aIndex);
	}
}

void CriarTerceiraAsa(int aIndex) 
{
	if((gObj(aIndex)->ChaosLock == 0) && (gObj(aIndex)->m_bPShopOpen == 0)) 
	{
		gObj(aIndex)->ChaosLock = 1;

		int ItemSorteado;
		switch(gObj(aIndex)->DbClass)
		{
			case 0: ItemSorteado = GerarItem(12, 37); break; //SM
			case 1: ItemSorteado = GerarItem(12, 37); break; //SM
			case 2: ItemSorteado = GerarItem(12, 37); break; //SM

			case 16: ItemSorteado = GerarItem(12, 36); break; //BK
			case 17: ItemSorteado = GerarItem(12, 36); break; //BK
			case 18: ItemSorteado = GerarItem(12, 36); break; //BK

			case 32: ItemSorteado = GerarItem(12, 38); break; //ELF
			case 33: ItemSorteado = GerarItem(12, 38); break; //ELF
			case 34: ItemSorteado = GerarItem(12, 38); break; //ELF

			case 48: ItemSorteado = GerarItem(12, 39); break; //MG
			case 49: ItemSorteado = GerarItem(12, 39); break; //MG

			case 64: ItemSorteado = GerarItem(12, 40); break; //DL
			case 65: ItemSorteado = GerarItem(12, 40); break; //DL
		}

		if(Sortear(GS.TaxaSucessoTerceiraAsa))
		{
			ItemSerialCreateSend(aIndex, 0xff, 0, 0, ItemSorteado, (rand()%3), 255, (rand()%2), (rand()%2), 0, -1, 0, 0);
		}else
		{
			ChaosMachineFalhou(aIndex);
		}

		gObj(aIndex)->Money -= 3000000;
		GCMoneySend(aIndex, gObj(aIndex)->Money);
		gObj(aIndex)->ChaosLock = 0;
	}else
	{
		MsgParaJogador("Ocorreu algum erro! RELOGUE AGORA!", aIndex);
	}
}

bool CGChaosBoxItemMixButtonClick(PMSG_CHAOSMIX* aRecv, int aIndex)
{
	if(aRecv->Type == 0x01) { CriarItemChaos(aIndex);		return true; }
	if(aRecv->Type == 0x0b) { CriarPrimeiraAsa(aIndex);		return true; }
	if(aRecv->Type == 0x07) { CriarSegundaAsa(aIndex);		return true; }
	if(aRecv->Type == 18)	{ CriarCapaDL(aIndex);			return true; }
	if(aRecv->Type == 26)	{ CriarFeatherOfCondor(aIndex); return true; }
	if(aRecv->Type == 27)	{ CriarTerceiraAsa(aIndex);		return true; }
	return false;
}
