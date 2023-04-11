#include "StdAfx.h"

void MudarClasse(int aIndex, char *Classe)
{
	if(GS.cmm_MudarClasse_Ativado == 0)
	{
		MsgParaJogador("[M. Classe] Comando desabilitado", aIndex);
		return;
	}

	if(GS.cmm_MudarClasse_Level > gObj(aIndex)->Level)
	{
		char levelmsg[100];
		sprintf(levelmsg,"[M. Classe] Level necessário: %d.", GS.cmm_MudarClasse_Level);
		MsgParaJogador(levelmsg, aIndex);
		return;
	}

	if(GS.cmm_MudarClasse_Custo > gObj(aIndex)->Money)
	{
		char OutputZenFalha[200];
		sprintf_s(OutputZenFalha,"[M. Classe] Necessário %d zen", GS.cmm_MudarClasse_Custo);
		MsgParaJogador(OutputZenFalha, aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_MudarClasse_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[M. Classe] %s", VerificarCtlCode(aIndex, GS.cmm_MudarClasse_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	if(gObjCustom[aIndex].Vip < GS.cmm_Resetar_Vip)
	{
		MsgParaJogador("[M. Classe] Necessário ser Vip.",aIndex);
		return;
	}

	//Verifica o inventario
	for(int i = 0; i<10; i++)
	{
		if(gObj(aIndex)->pInventory[i].m_Type != -1)
		{
			MsgParaJogador("[M. Classe] Desequipe todos os Itens!",aIndex);
			return;
		}
	}

	int Mudou = 0;
	//Blade Knight
	if(Procurar(Classe, "bk", false))
	{
		if(gObj(aIndex)->DbClass == 17)
		{
			MsgParaJogador("[M. Classe] Você já é Blade Knight.",aIndex);
			return;
		}else
		{
			gObj(aIndex)->DbClass = 17;
			Mudou = 1;
		}
	}

	//Blade Master
	if(Procurar(Classe, "bm", false))
	{
		if(gObj(aIndex)->DbClass == 18)
		{
			MsgParaJogador("[M. Classe] Você já é Blade Master.",aIndex);
			return;
		}else
		{
			gObj(aIndex)->DbClass = 18;
			Mudou = 1;
		}
	}

	//Soul Master
	if(Procurar(Classe, "sm", false))
	{
		if(gObj(aIndex)->DbClass == 1)
		{
			MsgParaJogador("[M. Classe] Você já é Soul Master.",aIndex);
			return;
		}else
		{
			gObj(aIndex)->DbClass = 1;
			Mudou = 1;
		}
	}

	//Grand Master
	if(Procurar(Classe, "gm", false))
	{
		if(gObj(aIndex)->DbClass == 2)
		{
			MsgParaJogador("[M. Classe] Você já é Grand Master.",aIndex);
			return;
		}else
		{
			gObj(aIndex)->DbClass = 2;
			Mudou = 1;
		}
	}

	//Muse Elf
	if(Procurar(Classe, "me", false))
	{
		if(gObj(aIndex)->DbClass == 33)
		{
			MsgParaJogador("[M. Classe] Você já é Muse Elf.",aIndex);
			return;
		}else
		{
			gObj(aIndex)->DbClass = 33;
			Mudou = 1;
		}
	}

	//Hight Elf
	if(Procurar(Classe, "he", false))
	{
		if(gObj(aIndex)->DbClass == 34)
		{
			MsgParaJogador("[M. Classe] Você já é Hight Elf.",aIndex);
			return;
		}else
		{
			gObj(aIndex)->DbClass = 34;
			Mudou = 1;
		}
	}

	//Magic Gladiator
	if(Procurar(Classe, "mg", false))
	{
		if(gObj(aIndex)->DbClass == 48)
		{
			MsgParaJogador("[M. Classe] Você já é Magic Gladiator.",aIndex);
			return;
		}else
		{
			gObj(aIndex)->DbClass = 48;
			Mudou = 1;
		}
	}

	//Duel Master
	if(Procurar(Classe, "dm", false))
	{
		if(gObj(aIndex)->DbClass == 49)
		{
			MsgParaJogador("[M. Classe] Você já é Duel Master.",aIndex);
			return;
		}else
		{
			gObj(aIndex)->DbClass = 49;
			Mudou = 1;
		}
	}

	//Dark Lord
	if(Procurar(Classe, "dl", false))
	{
		if(gObj(aIndex)->DbClass == 64)
		{
			MsgParaJogador("[M. Classe] Você já é Dark Lord.",aIndex);
			return;
		}else
		{
			gObj(aIndex)->DbClass = 64;
			Mudou = 1;
		}
	}

	//Lord Emperror
	if(Procurar(Classe, "le", false))
	{
		if(gObj(aIndex)->DbClass == 65)
		{
			MsgParaJogador("[M. Classe] Você já é Lord Emperror.",aIndex);
			return;
		}else
		{
			gObj(aIndex)->DbClass = 65;
			Mudou = 1;
		}
	}

	if(Mudou == 1)
	{
		gObj(aIndex)->Money -= GS.cmm_MudarClasse_Custo;
		GCMoneySend(aIndex, gObj(aIndex)->Money);
		MsgParaJogador("[M. Classe] Você virou Blade Knight. Relogando...",aIndex);
		gObjCloseSet(aIndex, 1);
		return;
	}
	MsgParaJogador("[M. Classe] Classe inválida!",aIndex);
}