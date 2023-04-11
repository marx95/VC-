#include "StdAfx.h"

void AceitarRejeitarQuerys(int aIndex, char NomeRegistrar[25], int Tipo)
{
	char Query[255];
	sprintf_s(Query,"UPDATE Character SET casado_status=1, casado_com='%s', casado_tipo='%d' WHERE Name='%s'", NomeRegistrar, Tipo, gObj(aIndex)->Name);
	DbConnection.Executar(Query);
	gObjCustom[aIndex].casado = 1;
}

void AceitarRejeitar(int aIndex, int Tipo)
{
	if(GS.cmm_Casamento_e_AceitarRejeitar_Ativado == 0)
	{
		MsgParaJogador("[Casamento] Comando desabilitado", aIndex);
		return;
	}

	// tipo 0 = para aceitar
	// tipo 1 = para rejeitar
	if(gObjCustom[aIndex].PedidoCasamento == 0 || gObjCustom[aIndex].PedidoCasamento < 6400)
	{
		MsgParaJogador("[Casamento] Você não tem nenhum pedido pendente!", aIndex);
		return;
	}
	
	char MsgSaida[255];
	DWORD IndexMarido = gObjCustom[aIndex].PedidoCasamento;

	if(gObj(IndexMarido)->Connected < 3)
	{
		MsgParaJogador("[Casamento] O marido está offline!", aIndex);
		gObjCustom[aIndex].PedidoCasamento = 0;

		sprintf_s(MsgSaida, "| %s foi abandonada no altar |", gObj(aIndex)->Name);
		MsgParaTodos(MsgSaida, 0);
		return;
	}

	switch(Tipo)
	{
	case 0:
		//Para noiva
		sprintf_s(MsgSaida, "[Casamento] Você aceitou %s como seu Marido.", gObj(IndexMarido)->Name);
		MsgParaJogador(MsgSaida, aIndex);

		//Para marido
		sprintf_s(MsgSaida, "[Casamento] %s aceitou seu pedido de casamento.", gObj(aIndex)->Name);
		MsgParaJogador(MsgSaida, aIndex);

		//Para o Server
		sprintf_s(MsgSaida, "| %s Aceitou! |", gObj(aIndex)->Name);
		MsgParaTodos(MsgSaida, 0);

		sprintf_s(MsgSaida, "| %s e %s estão Casados |", gObj(IndexMarido)->Name, gObj(aIndex)->Name);
		MsgParaTodos(MsgSaida, 0);

		Efeito_Fogos_Artificio_Para_Todos_Mesmo_Mapa(2);

		AceitarRejeitarQuerys(aIndex, gObj(IndexMarido)->Name, 1); //Para Esposa
		AceitarRejeitarQuerys(IndexMarido, gObj(aIndex)->Name, 0); //Para Marido

		gObj(aIndex)->Money -= GS.cmm_Casamento_e_AceitarRejeitar_Custo;
		gObj(IndexMarido)->Money -= GS.cmm_Casamento_e_AceitarRejeitar_Custo;
		GCMoneySend(aIndex,gObj(aIndex)->Money);
		GCMoneySend(IndexMarido,gObj(IndexMarido)->Money);
		return;
	break;

	case 1:
		//Para noiva
		sprintf_s(MsgSaida, "[Casamento] Você rejeitou %s como seu Marido.", gObj(IndexMarido)->Name);
		MsgParaJogador(MsgSaida, aIndex);

		//Para marido
		sprintf_s(MsgSaida, "[Casamento] %s recusou seu pedido de casamento.", gObj(aIndex)->Name);
		MsgParaJogador(MsgSaida, aIndex);

		//Para o Server
		sprintf_s(MsgSaida, "| %s Recusou o pedido de casamento! |", gObj(aIndex)->Name);
		MsgParaTodos(MsgSaida, 0);
	break;
	}
}