#include "StdAfx.h"

void DivorciarQuery(int aIndex)
{
	char Query[255];
	sprintf_s(Query,"UPDATE Character SET casado_status=0, casado_com='' WHERE Name='%s'", gObj(aIndex)->Name);
	DbConnection.Executar(Query);

	sprintf_s(Query,"UPDATE Character SET casado_status=0, casado_com='' WHERE casado_com='%s'", gObj(aIndex)->Name);
	DbConnection.Executar(Query);
}

void Divorciar(int aIndex)
{

	if(GS.cmm_Divorcio_Ativado == 0)
	{
		MsgParaJogador("[Divorciar] Comando desabilitado", aIndex);
		return;
	}

	if(gObjCustom[aIndex].casado < 2)
	{
		MsgParaJogador("[Divorciar] Voc� n�o est� casado!", aIndex);
		return;
	}

	if(GS.cmm_Divorcio_Level > gObj(aIndex)->Level)
	{
		char levelmsg[100];
		sprintf(levelmsg,"[Divorciar] Level necess�rio: %d.", GS.cmm_Divorcio_Level);
		MsgParaJogador(levelmsg, aIndex);
		return;
	}

	if(GS.cmm_Divorcio_Custo > gObj(aIndex)->Money)
	{
		char OutputZenFalha[200];
		sprintf_s(OutputZenFalha,"[Divorciar] Necess�rio %d zen", GS.cmm_Divorcio_Custo);
		MsgParaJogador(OutputZenFalha,aIndex);
		return;
	}

	DivorciarQuery(aIndex);
	gObjCustom[aIndex].casado = 1;
	gObj(aIndex)->Money -= GS.cmm_Divorcio_Custo;
	GCMoneySend(aIndex,gObj(aIndex)->Money);
	MsgParaJogadorCentro("[ Voc� se divorciou ]", aIndex);
	gObjCloseSet(aIndex,1);

}