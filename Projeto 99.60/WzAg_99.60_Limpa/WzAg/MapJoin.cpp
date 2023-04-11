#include "stdafx.h"

void JGGetCharacterInfo_Hook(struct SDHP_DBCHAR_INFORESULT* lpMsg)
{
	int aIndex = lpMsg->Number;

	Pegar_gObjCustom_Character(aIndex, lpMsg->Name, lpMsg->AccountID, lpMsg->Class);
	
	if(lpMsg->LevelUpPoint > 327675) lpMsg->LevelUpPoint = 327675;
	if(lpMsg->Str < 0 || lpMsg->Str > gObjCustom[aIndex].Limite_Pontos) lpMsg->Str = gObjCustom[aIndex].Limite_Pontos;
	if(lpMsg->Dex < 0 || lpMsg->Dex > gObjCustom[aIndex].Limite_Pontos) lpMsg->Dex = gObjCustom[aIndex].Limite_Pontos;
	if(lpMsg->Vit < 0 || lpMsg->Vit > gObjCustom[aIndex].Limite_Pontos) lpMsg->Vit = gObjCustom[aIndex].Limite_Pontos;
	if(lpMsg->Energy < 0 || lpMsg->Energy > gObjCustom[aIndex].Limite_Pontos) lpMsg->Energy = gObjCustom[aIndex].Limite_Pontos;
	if(lpMsg->Leadership < 0 || lpMsg->Leadership > gObjCustom[aIndex].Limite_Pontos) lpMsg->Leadership = gObjCustom[aIndex].Limite_Pontos;

	if(GS.Setar_Zen_ao_Logar == 1) lpMsg->Money = 200000000;
	
	if(VerificarGM(aIndex))
	{
		lpMsg->Str			= gObjCustom[aIndex].Limite_Pontos;
		lpMsg->Dex			= gObjCustom[aIndex].Limite_Pontos;
		lpMsg->Vit			= gObjCustom[aIndex].Limite_Pontos;
		lpMsg->Energy		= gObjCustom[aIndex].Limite_Pontos;
		lpMsg->Leadership	= gObjCustom[aIndex].Limite_Pontos;
		lpMsg->Level		= GS.Level_Maximo;
	}

	JGGetCharacterInfo(lpMsg);
	
	if(VerificarGM(aIndex))
	{
		char MsgTPChar[64];
		sprintf_s(MsgTPChar, "[Info] Você é %s.", TipoPersonagem(aIndex));
		MsgPlayer(MsgTPChar, aIndex);
		//FixarBalaoGM(aIndex);
		ShadowPhantomBuff(aIndex);
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
	
	MsgPlayer(GS.MsgLateral, aIndex);
	MsgPlayer(Msg1, aIndex);
	MsgPlayer(Msg2, aIndex);
	MsgPlayer("[PVP] Para acessar: /pvp1 ou /pvp2.", aIndex);
	MsgCentro(GS.MsgCentro, aIndex);
	MsgSlide(aIndex, GS.MsgLateral, 2);
	if(gObjCustom[aIndex].Vip == 1 && gObj(aIndex)->Level < GS.ShadowP_LevelMax) ShadowPhantomBuff(aIndex);
}