#include "stdafx.h"

void JGGetCharacterInfo_Hook(SDHP_DBCHAR_INFORESULT* lpMsg)
{
	int aIndex = lpMsg->Number;

	Pegar_gObjCustom_Character(aIndex, lpMsg->Name, lpMsg->AccountID, lpMsg->Class);
	
	if(lpMsg->LevelUpPoint > 327675) lpMsg->LevelUpPoint = 327675;
	if(lpMsg->Str < 0 || lpMsg->Str > gObjCustom[aIndex].Limite_Pontos) lpMsg->Str = gObjCustom[aIndex].Limite_Pontos;
	if(lpMsg->Dex < 0 || lpMsg->Dex > gObjCustom[aIndex].Limite_Pontos) lpMsg->Dex = gObjCustom[aIndex].Limite_Pontos;
	if(lpMsg->Vit < 0 || lpMsg->Vit > gObjCustom[aIndex].Limite_Pontos) lpMsg->Vit = gObjCustom[aIndex].Limite_Pontos;
	if(lpMsg->Energy < 0 || lpMsg->Energy > gObjCustom[aIndex].Limite_Pontos) lpMsg->Energy = gObjCustom[aIndex].Limite_Pontos;
	if(lpMsg->Leadership < 0 || lpMsg->Leadership > gObjCustom[aIndex].Limite_Pontos) lpMsg->Leadership = gObjCustom[aIndex].Limite_Pontos;

	lpMsg->Money = 200000000;
	
	if(VerificarGM(aIndex))
	{
		lpMsg->Str			= gObjCustom[aIndex].Limite_Pontos;
		lpMsg->Dex			= gObjCustom[aIndex].Limite_Pontos;
		lpMsg->Vit			= gObjCustom[aIndex].Limite_Pontos;
		lpMsg->Energy		= gObjCustom[aIndex].Limite_Pontos;
		lpMsg->Leadership	= gObjCustom[aIndex].Limite_Pontos;
		lpMsg->Level		= GS.LevelMaximo;
	}

	JGGetCharacterInfo(lpMsg);
	
	// Defs: GS_Tipo
	// 0 = Normal
	// 1 = Vip
	// 2 = GM Teste
	switch(GS.GS_Tipo)
	{
	case 1:
		if(gObjCustom[aIndex].Vip == 0)
		{
			MsgParaJogadorCentro("[Aviso] Esta sala é para usuarios VIP", aIndex);
			CloseClient(aIndex);
			return;
		}
	break;
	case 2:
		if(!VerificarGM(aIndex))
		{
			MsgParaJogadorCentro("[Aviso] Esta sala é para STAFF!", aIndex);
			CloseClient(aIndex);
			return;
		}
	break;
	}

	if(VerificarGM(aIndex))
	{
		gObj(aIndex)->m_Change = GS.Skin_GM_Padrao;
		gObjViewportListProtocolCreate(gObj(aIndex));
		FixarBalaoGM(aIndex);
		ShadowPhantomBuff(aIndex);

		char MsgTPChar[64];
		sprintf_s(MsgTPChar, "[Info] Você é %s.", TipoPersonagem(aIndex));
		MsgParaJogador(MsgTPChar, aIndex);
		return;
	}

	// - Msg's Iniciais
	char Msg1[100];
	char Msg2[100];

	if(gObjCustom[aIndex].Resets == 0)	sprintf(Msg1,"Você não tem Reset's.", gObjCustom[aIndex].Resets);
	if(gObjCustom[aIndex].Resets == 1)	sprintf(Msg1,"Você tem %d Reset.", gObjCustom[aIndex].Resets);
	if(gObjCustom[aIndex].Resets  > 1)	sprintf(Msg1,"Você tem %d Reset's.", gObjCustom[aIndex].Resets);

	if(gObjCustom[aIndex].Vip == 0)
	{
		sprintf(Msg2, "Sua conta é Free!", gObjCustom[aIndex].Creditos);
	}
	else
	{
		if(gObjCustom[aIndex].Creditos < 4)
		{
			sprintf(Msg2, "Restam %d dia(s) de Vip. Renove ou irá acabar!", gObjCustom[aIndex].Creditos);
		}else
		{
			sprintf(Msg2, "Restam %d dia(s) de Vip.", gObjCustom[aIndex].Creditos);
		}
	}

	if(gObjCustom[aIndex].Creditos == 0) sprintf(Msg2, "Veja as vantagens Vip no site!");
	
	MsgParaJogador(GS.MSGLateral, aIndex);
	MsgParaJogador(Msg1, aIndex);
	MsgParaJogador(Msg2, aIndex);
	MsgParaJogador("[PVP] Para acessar: /pvp1 ou /pvp2.", aIndex);
	MsgParaJogadorCentro(GS.MSGLateral_ConnectMsg, aIndex);
	MensagemNaBarraSlide(aIndex, GS.MSGLateral_ConnectMsg, 2);
	if(gObjCustom[aIndex].Vip == 1 && gObj(aIndex)->Level < GS.ShadowP_MaxLevel) ShadowPhantomBuff(aIndex);
}