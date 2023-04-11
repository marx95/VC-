#include "StdAfx.h"

void PersonagemInfo(int aIndex, char NomeBusca[15])
{

	if(GS.cmm_PINFO_Ativado == 0)
	{
		MsgParaJogador("[J. Info] Comando desabilitado",aIndex);
		return;
	}

	if(gObjCustom[aIndex].CtlCode < GS.cmm_PINFO_CtlCode)
	{
		char MsgCtlCode[64];
		sprintf_s(MsgCtlCode, "[J. Info] %s", VerificarCtlCode(aIndex, GS.cmm_PINFO_CtlCode));
		MsgParaJogador(MsgCtlCode, aIndex);
		return;
	}

	if(strlen(NomeBusca) < 4 || NomeBusca[0] == 0 || sizeof(NomeBusca) < 1)
	{
		MsgParaJogador("[J. Info] Digite o nome de uma pessoa.",aIndex);
		return;
	}

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3)
			{
				if(Procurar(gObj(i)->Name, NomeBusca, true))
				{
					char Msg1[64];
					char Msg2[64];
					char Msg3[64];
					char Msg4[64];
					char Msg5[64];
					char TipoVip[10];

					if(gObjCustom[i].Vip == 0) sprintf_s(TipoVip,"%s","Free");
					if(gObjCustom[i].Vip == 1) sprintf_s(TipoVip,"%s","Vip");

					sprintf_s(Msg1, "[J. Info] Personagem: %s.", gObj(i)->Name);
					sprintf_s(Msg2, "[J. Info] Login: %s.", gObj(i)->AccountID);
					sprintf_s(Msg3, "[J. Info] IP: %s.", gObj(i)->Ip_addr);
					sprintf_s(Msg4, "[J. Info] Tipo: %s (%d Dias restantes).", TipoVip, gObjCustom[i].Creditos);
					sprintf_s(Msg5, "[J. Info] CtlCode: %s.", TipoPersonagem(aIndex));
					MsgParaJogador(Msg1,aIndex);
					MsgParaJogador(Msg2,aIndex);
					MsgParaJogador(Msg3,aIndex);
					MsgParaJogador(Msg4,aIndex);
					MsgParaJogador(Msg5,aIndex);
					return;
				}
		}
	}
	MsgParaJogador("[P. Info] Nenhum jogador encontrado!",aIndex);
}