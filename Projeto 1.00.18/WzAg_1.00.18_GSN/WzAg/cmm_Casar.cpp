#include "StdAfx.h"

void Casar(int aIndex, char *Nome)
{

	if(GS.cmm_Casamento_e_AceitarRejeitar_Ativado == 0)
	{
		MsgParaJogador("[Casamento] Comando desabilitado", aIndex);
		return;
	}

	if(GS.Noticias_Ativado == 0)
	{
		MsgParaJogador("[Casamento] Desabilitado no momento!", aIndex);
		return;
	}

	if(gObjCustom[aIndex].casado == 1)
	{
		MsgParaJogador("[Casamento] Você já está casado!", aIndex);
		return;
	}

	if(GS.cmm_Casamento_e_AceitarRejeitar_Level > gObj(aIndex)->Level)
	{
		char levelmsg[100];
		sprintf(levelmsg,"[Casamento] Level necessário: %d.", GS.cmm_Casamento_e_AceitarRejeitar_Level);
		MsgParaJogador(levelmsg, aIndex);
		return;
	}

	if(GS.cmm_Casamento_e_AceitarRejeitar_Custo > gObj(aIndex)->Money)
	{
		char zenMsg[200];
		sprintf_s(zenMsg,"[Casamento] Necessário %d zen", GS.cmm_Casamento_e_AceitarRejeitar_Custo);
		MsgParaJogador(zenMsg, aIndex);
		return;
	}

	if(strlen(Nome) < 4 || Nome[0] == 0 || sizeof(Nome) < 4){
		MsgParaJogador("[Casamento] Digite o nome de uma pessoa.", aIndex);
		return;
	}

	if(gObj(aIndex)->DbClass == 0x20 || gObj(aIndex)->DbClass == 0x21 || gObj(aIndex)->DbClass == 0x22)
	{
		MsgParaJogador("[Casamento] Somente Homens podem propor o casamento!", aIndex);
		return;
	}

	if(!memcmp(Nome, gObj(aIndex)->Name, strlen(gObj(aIndex)->Name)) && strlen(Nome) == strlen(gObj(aIndex)->Name))
	{
		MsgParaJogador("[Casamento] Você não pode casar com você mesmo!", aIndex);
		return;
	}

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3)
		{
			if(Procurar(gObj(i)->Name, Nome, true))
			{
				if(gObjCustom[i].casado == 2) // Se ela esta casada?
				{
					char CasadoMsg[100];
					sprintf(CasadoMsg,"[Casamento] %s já está casada.", gObj(i)->Name);
					MsgParaJogador(CasadoMsg, aIndex);
					return;
				}

				if(GS.cmm_Casamento_e_AceitarRejeitar_Level > gObj(i)->Level){ //Level da esposa
					char levelmsg2[100];
					sprintf(levelmsg2,"[Casamento] A Noiva não tem o level necessário: %d.",GS.cmm_Casamento_e_AceitarRejeitar_Level);
					MsgParaJogador(levelmsg2, aIndex);
					return;
				}

				if(GS.cmm_Casamento_e_AceitarRejeitar_Custo > gObj(i)->Money){ //Money da esposa
					char zenMsg2[100];
					sprintf(zenMsg2,"[Casamento] A Noiva não tem o Zen necessário: %d.", GS.cmm_Casamento_e_AceitarRejeitar_Custo);
					MsgParaJogador(zenMsg2, aIndex);
					return;
				}

				gObjCustom[i].PedidoCasamento = aIndex;
				char MsgPedidoEnviado[255];
				char MsgPedidoAceitarNegar[255];

				sprintf_s(MsgPedidoAceitarNegar, "[Casamento] Para aceitar: %s e para Rejeitar: %s", GS.AceitarCmm, GS.RejeitarCmm);

				//Aqui diz ao jogador q pediu em casamento
				sprintf_s(MsgPedidoEnviado, "[Casamento] Pedido de casamento enviado para: %s", gObj(i)->Name);
				MsgParaJogador(MsgPedidoEnviado, aIndex);

				//Aqui diz a noiva que tal jogador quer se casar com ela
				sprintf_s(MsgPedidoEnviado, "[Casamento] %s, você quer casar com %s?", gObj(i)->Name, gObj(aIndex)->Name);
				MsgParaJogador(MsgPedidoEnviado, i);
				MsgParaJogador(MsgPedidoAceitarNegar, i);

				//Aqui manda mensagem ao server
				sprintf_s(MsgPedidoEnviado, "| %s pediu %s em casamento |", gObj(aIndex)->Name, gObj(i)->Name);
				MsgParaTodos(MsgPedidoEnviado, 0);
				sprintf_s(MsgPedidoEnviado, "| %s e %s vão se casar |", gObj(aIndex)->Name, gObj(i)->Name);
				MsgParaTodos(MsgPedidoEnviado, 0);
				return;
			}
		}
	}

	char MsgFalhaPedido[255];
	sprintf_s(MsgFalhaPedido, "[Casamento] %s parece estár offline...", Nome);
	MsgColorida(MsgFalhaPedido, aIndex, 0, 2);
}