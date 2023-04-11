#include "StdAfx.h"

void MudarBau_Timer()
{
	while(true)
	{
		Sleep(1000);
		for(int i = Obj_Jogadores_Minimo; i< Obj_Jogadores_Maximo; i++)
		{
			if(gObj(i)->Connected)
			{
				if(gObjCustom[i].Bau_Delay > 0) gObjCustom[i].Bau_Delay--;
			}
		}
	}
}

void MudarBau(int aIndex, char * Msg)
{
	int BauTotal;
	int bauAtivado;
	int MBau = atoi(Msg);

	if(GS.cmm_MudarBau_Ativado == 0)
	{
		MsgParaJogador("[Mudar Baú] Comando desabilitado",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_MudarBau_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[Mudar Baú] %s", VerificarCtlCode(aIndex, GS.cmm_MudarBau_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	if(gObj(aIndex)->Money < GS.cmm_MudarBau_Custo)
	{
		char OutputZenFalha[200];
		sprintf_s(OutputZenFalha,"[Mudar Baú] Necessário %d zen", GS.cmm_MudarBau_Custo);
		MsgParaJogador(OutputZenFalha,aIndex);
		return;
	}

	if(gObjCustom[aIndex].BauAberto == 1)
	{
		MsgParaJogador("[Mudar Baú] Feche e saia de perto do VaultKeeper.",aIndex);
		return;
	}

	if(gObjCustom[aIndex].Bau_Delay > 0)
	{
		char MsgDelayB[64];
		sprintf(MsgDelayB, "[Mudar Baú] Espere %d segundo(s)!", gObjCustom[aIndex].Bau_Delay);
		MsgParaJogador(MsgDelayB, aIndex);
		return;
	}

	switch(gObjCustom[aIndex].Vip)
	{
	case 0:
		bauAtivado = GS.cmm_MudarBau_Ativado_Free;
		if(bauAtivado == 0)
		{
			MsgParaJogador("[Mudar Baú] Comando desabilitado para este tipo de conta!",aIndex);
			return;
		}else
		{
			BauTotal = GS.cmm_MudarBau_Total_Free;
		}
		break;
	case 1:
			bauAtivado = GS.cmm_MudarBau_Ativado_Vip;
		if(bauAtivado == 0)
		{
			MsgParaJogador("[Mudar Baú] Comando desabilitado para este tipo de conta!",aIndex);
			return;
		}else{
			BauTotal = GS.cmm_MudarBau_Total_Vip;
		}
		break;
	}

	if (MBau < 1 || MBau > BauTotal)
	{
		char TmpMsg[128];
		sprintf_s(TmpMsg,"[Mudar Baú] Baú invalido, use: /bau 1 á %d", BauTotal);
		MsgParaJogador(TmpMsg,aIndex);
		return;
	}

	if (gObjCustom[aIndex].BauID == MBau)
	{
		char TmpMsg[128];
		sprintf_s(TmpMsg,"[Mudar Baú] Baú %d já está aberto!", MBau);
		MsgParaJogador(TmpMsg,aIndex);
		return;
	}

	int Rst = DbConnection.PegarInt("BauID", "Warehouse", "WHERE BauID = '%d' AND AccountID2='%s'", MBau, gObj(aIndex)->AccountID);
	if(Rst == 0)
	{
		char Query[256];
		sprintf_s(Query, "INSERT INTO warehouse(AccountID, AccountID2, BauID, DbVersion, Money, pw) VALUES('', '%s', %d, 3, 0, 0)", gObj(aIndex)->AccountID, MBau);
		DbConnection.Executar(Query);
	}

	char Buffer[256];
	sprintf_s(Buffer,"UPDATE warehouse SET AccountID='', AccountID2='%s' where AccountID='%s'", gObj(aIndex)->AccountID, gObj(aIndex)->AccountID);
	DbConnection.Executar(Buffer);

	sprintf_s(Buffer,"UPDATE warehouse SET AccountID='%s' WHERE AccountID2='%s' AND BauID='%d'", gObj(aIndex)->AccountID, gObj(aIndex)->AccountID, MBau);
	DbConnection.Executar(Buffer);

	gObjCustom[aIndex].BauID = MBau;
	gObj(aIndex)->Money -= GS.cmm_MudarBau_Custo;
	GCMoneySend(aIndex, gObj(aIndex)->Money);
	gObjCustom[aIndex].Bau_Delay = GS.cmm_MudarBau_Delay;

	MsgParaJogador("[Mudar Baú] Báu trocado com sucesso!",aIndex);
}