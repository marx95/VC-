#include "stdAfx.h"

bool Conectado(int aIndex)
{
	if(aIndex < Obj_Jogadores_Minimo || aIndex > Obj_Jogadores_Maximo) return false;
	if(gObj(aIndex)->Connected > J_Vazio) return true;
	return false;
}

bool Logado(int aIndex)
{
	if(aIndex < Obj_Jogadores_Minimo || aIndex > Obj_Jogadores_Maximo) return false;
	if(gObj(aIndex)->Connected > J_Conectado) return true;
	return false;
}

bool Jogando(int aIndex)
{
	if(aIndex < Obj_Jogadores_Minimo || aIndex > Obj_Jogadores_Maximo) return false;
	if(gObj(aIndex)->Connected == J_Jogando) return true;
	return false;
}

//bool gObjIsConnectedGP(int aIndex)
//{
	//if(aIndex < Obj_Jogadores_Minimo || aIndex > Obj_Jogadores_Maximo) return false;
	//if(gObj(aIndex)->Connected == J_Jogando) return true;
	//return false;
//}

bool No_Duelo(int aIndex1, int aIndex2)
{
	if(aIndex1 < Obj_Jogadores_Minimo || aIndex1 > Obj_Jogadores_Maximo) return false;
	if(aIndex2 < Obj_Jogadores_Minimo || aIndex2 > Obj_Jogadores_Maximo) return false;

	if(gObj(aIndex1)->m_iDuelUser == aIndex2 && gObj(aIndex2)->m_iDuelUser == aIndex1) return true;
	return false;
}

void Set_Life(int aIndex, int Pontos)
{
	if(gObj(aIndex)->Class == 0) gObj(aIndex)->MaxLife += (Pontos * 2);
	if(gObj(aIndex)->Class == 1) gObj(aIndex)->MaxLife += (Pontos * 3);
	if(gObj(aIndex)->Class == 2) gObj(aIndex)->MaxLife += (Pontos * 2);
	if(gObj(aIndex)->Class == 3) gObj(aIndex)->MaxLife += (Pontos * 2);
	if(gObj(aIndex)->Class == 4) gObj(aIndex)->MaxLife += Pontos;
}

void Set_Mana(int aIndex, int Pontos)
{
	if(gObj(aIndex)->Class == 0) gObj(aIndex)->MaxMana += (Pontos * 2);
	if(gObj(aIndex)->Class == 1) gObj(aIndex)->MaxMana += Pontos;
	if(gObj(aIndex)->Class == 2) gObj(aIndex)->MaxMana += (Pontos * 2);
	if(gObj(aIndex)->Class == 3) gObj(aIndex)->MaxMana += (Pontos * 2);
	if(gObj(aIndex)->Class == 4) gObj(aIndex)->MaxMana += Pontos;
}

int Pegar_Pontos_por_Level(int aIndex)
{
	int Pontos = 0;

	switch(gObj(aIndex)->Class)
	{
		case 0: Pontos += GS.Pontos_p_LVL_DW_SM; break;
		case 1: Pontos += GS.Pontos_p_LVL_DK_BK; break;
		case 2: Pontos += GS.Pontos_p_LVL_Elf_ME; break;
		case 3: Pontos += GS.Pontos_p_LVL_MG; break;
		case 4: Pontos += GS.Pontos_p_LVL_DL; break;
	}

	if(gObjCustom[aIndex].Vip == 0) Pontos += GS.Pontos_Soma_Normal;
	if(gObjCustom[aIndex].Vip == 1) Pontos += GS.Pontos_Soma_Vip;
	if(gObj(aIndex)->PlusStatQuestClear > 0) Pontos += GS.Pontos_Soma_Apos_Quest;
	return Pontos;
}

void gObjViewportListProtocolDestroy_AP(int aIndex)
{
	PMSG_VIEWPORTDESTROY pViewportDestroy;
	PBMSG_COUNT pCount;

	const int lsendbuf = sizeof(pViewportDestroy) + sizeof(pCount) + 1;
	int lOfs,count;

	BYTE sendBuf[lsendbuf];
	count = 0;
	lOfs  = 4;

	pViewportDestroy.NumberH = SET_NUMBERH(aIndex);
	pViewportDestroy.NumberL = SET_NUMBERL(aIndex);

	memcpy(&sendBuf[lOfs],&pViewportDestroy,sizeof(pViewportDestroy));

	lOfs  += 2;
	count += 1;

	pCount.h.c			= 0xC1;
	pCount.h.headcode	= 20;
	pCount.h.size		= lOfs;
	pCount.count		= count;

	memcpy(sendBuf,&pCount,sizeof(pCount));
	DataSend(aIndex, sendBuf, lOfs);

	for(int i = Obj_Jogadores_Minimo; i < Obj_Jogadores_Maximo; i++)
	{
		if(Jogando(i))
		{
			if(gObj(i)->MapNumber == gObj(aIndex)->MapNumber) gObjClearViewport(gObj(i));
		}
	}

}

void Atualizar_Personagem(int aIndex)
{
	gObjViewportListProtocolDestroy_AP(aIndex);
		
	PMSG_CHARMAPJOINRESULT pjMsg;
	pjMsg.h.c			= 0xC3;
	pjMsg.h.headcode	= 0xF3;
	pjMsg.h.size		= sizeof(PMSG_CHARMAPJOINRESULT);
	pjMsg.subcode		= 0x03;
	pjMsg.MapX			= (BYTE)gObj(aIndex)->X;
	pjMsg.MapY			= (BYTE)gObj(aIndex)->Y;
	pjMsg.MapNumber		= gObj(aIndex)->MapNumber;
	pjMsg.Dir			= gObj(aIndex)->Dir;
	pjMsg.Exp			= gObj(aIndex)->Experience;
	pjMsg.NextExp		= gObj(aIndex)->NextExp;
	pjMsg.LevelUpPoint	= gObj(aIndex)->LevelUpPoint;
	pjMsg.Str			= gObj(aIndex)->Strength;
	pjMsg.Dex			= gObj(aIndex)->Dexterity;
	pjMsg.Vit			= gObj(aIndex)->Vitality;
	pjMsg.Energy		= gObj(aIndex)->Energy;
	pjMsg.Money			= gObj(aIndex)->Money;
	pjMsg.PkLevel		= gObj(aIndex)->m_PK_Level;
	pjMsg.Life			= (WORD)gObj(aIndex)->Life;
	pjMsg.MaxLife		= WORD(gObj(aIndex)->AddLife + gObj(aIndex)->MaxLife);
	pjMsg.Mana			= (WORD)gObj(aIndex)->Mana;
	pjMsg.MaxMana		= WORD(gObj(aIndex)->AddMana + gObj(aIndex)->MaxMana);
	pjMsg.BP			= gObj(aIndex)->BP;
	pjMsg.MaxBP			= gObj(aIndex)->MaxBP + gObj(aIndex)->AddBP;
	pjMsg.Leadership	= gObj(aIndex)->Leadership;

	short AddPoint		= 0;
	short MaxAddPoint	= 0;
	short MinusPoint	= 0;
	short MaxMinusPoint = 0;
	
	gObjGetStatPointState(gObj(aIndex)->m_Index, AddPoint, MaxAddPoint);
	pjMsg.AddPoint		= AddPoint;
	pjMsg.MaxAddPoint	= MaxAddPoint;
	
	DataSend(aIndex, (UCHAR*)&pjMsg, pjMsg.h.size);

	GCItemListSend(aIndex);
	GCMagicListMultiSend(gObj(aIndex), 0);
	CGRequestQuestInfo(aIndex);
	DGGuildMemberInfoRequest(aIndex);
	FriendListRequest(aIndex);
	CalCharacterEx(aIndex);

	gObjViewportListProtocolCreate(gObj(aIndex));
}

void GCLevelUpMsgSend(int aIndex, int iSendEffect)
{
	if(aIndex < Obj_Jogadores_Minimo || aIndex > Obj_Jogadores_Maximo) return;
	short AddPoint		= 0;
	short MaxAddPoint	= 0;
	short MinusPoint	= 0;
	short MaxMinusPoint	= 0;

	gObjGetStatPointState(aIndex, AddPoint, MaxAddPoint);
	
	PMSG_LEVELUP pMsg;

	PHeadSubSetB((LPBYTE)&pMsg, 0xF3, 0x05, sizeof(pMsg));
	pMsg.Level			= gObj(aIndex)->Level;
	pMsg.LevelUpPoint	= gObj(aIndex)->LevelUpPoint;
	pMsg.MaxLife		= WORD((double)gObj(aIndex)->MaxLife+(double)gObj(aIndex)->AddLife);
	pMsg.MaxMana		= WORD((double)gObj(aIndex)->MaxMana+(double)gObj(aIndex)->AddMana);
	pMsg.MaxBP			= gObj(aIndex)->MaxBP + gObj(aIndex)->AddBP;
	pMsg.AddPoint		= AddPoint;
	pMsg.MaxAddPoint	= MaxAddPoint;

	DataSend(aIndex, (LPBYTE)&pMsg, pMsg.h.size);

	if(iSendEffect == 1) GCSendEffectInfo(aIndex, 0x10);
}

void f_Reset(int aIndex)
{
	gObjCustom[aIndex].Level_Max_Msg=false;
	gObj(aIndex)->Level			= 1;
	gObj(aIndex)->Experience	= 0;
	gObj(aIndex)->NextExp		= GS.Experiencia[1];
	gObjCustom[aIndex].Resets++;

	int TipoAcc = gObjCustom[aIndex].Vip;
	if(GS.Reset_Tipo == 1)
	{
		gObj(aIndex)->LevelUpPoint	= (gObjCustom[aIndex].Resets * GS.Reset_Pontos[TipoAcc]);
		gObj(aIndex)->Strength		= GS.Pontos_Iniciais[TipoAcc];
		gObj(aIndex)->Dexterity		= GS.Pontos_Iniciais[TipoAcc];
		gObj(aIndex)->Vitality		= GS.Pontos_Iniciais[TipoAcc];
		gObj(aIndex)->Energy		= GS.Pontos_Iniciais[TipoAcc];
	}

	gObj(aIndex)->LevelUpPoint+= GS.Reset_Pontos_Somatoria[TipoAcc];

	if(gObj(aIndex)->Class == Elf) gObjTeleport(aIndex, 3, 171, 87);
	GCLevelUpMsgSend(aIndex, 1);
	Atualizar_Personagem(aIndex);
	if(TipoAcc == 1) ShadowPhantomBuff(aIndex);
	Mssql_Atualiza(aIndex, 1);
	GJSetCharacterInfo(gObj(aIndex), aIndex);
}

void f_LimparPK(int aIndex)
{
	if(gObj(aIndex)->m_PK_Level >= 5)
	{
		gObj(aIndex)->m_PK_Level = 3;
		GCPkLevelSend(aIndex, 3);
	}
}

bool VerificarGM(int aIndex)
{
	//if(gObjCustom[aIndex].CtlCode == GS.DV_CtlCode)			return true;
	if(gObjCustom[aIndex].CtlCode == GS.GM_CtlCode)			return true;
	if(gObjCustom[aIndex].CtlCode == GS.SUB_CtlCode)		return true;
	if(gObjCustom[aIndex].CtlCode == GS.ADM_CtlCode)		return true;
	return false;
}

char * VerificarCtlCode(int aIndex, int CtlCode)
{
	if(CtlCode == 0)						return "Necessário ser ???.";
	if(CtlCode <= GS.DV_CtlCode)			return "Necessário ser Divulgador.";
	if(CtlCode <= GS.GM_CtlCode)			return "Necessário ser GameMaster.";
	if(CtlCode <= GS.SUB_CtlCode)			return "Necessário ser Sub-ADM.";
	if(CtlCode <= GS.ADM_CtlCode)			return "Necessário ser Administrador.";
	if(CtlCode <= GS.ADM_Player_CtlCode)	return "Necessário ser ADM ou ADM-Player.";
	return "CtlCode Desconhecido!";
}

char * TipoPersonagem(int aIndex)
{
	int CtlCode = gObjCustom[aIndex].CtlCode;
	if(CtlCode == 0)						return "Jogador";
	if(CtlCode <= GS.DV_CtlCode)			return "Divulgador";
	if(CtlCode <= GS.GM_CtlCode)			return "GameMaster";
	if(CtlCode <= GS.SUB_CtlCode)			return "Sub-ADM";
	if(CtlCode <= GS.ADM_CtlCode)			return "Administrador";
	if(CtlCode <= GS.ADM_Player_CtlCode)	return "ADM-Player";
	return "Jogador";
}

/*
void FixarBalaoGM(int aIndex)
{
	if(VerificarGM(aIndex))
	{
		gObj(aIndex)->m_ViewSkillState |= 0x1000000;
		GCStateInfoSend(gObj(aIndex), 1, 0x1000000);
	}
}*/

int VerTotalConectado()
{
	int TotalOnlineAgora = 0;
	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(Conectado(i)) TotalOnlineAgora++;
	}
	return TotalOnlineAgora;
}

int VerTotalLogado()
{
	int TotalOnlineAgora = 0;
	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(Logado(i)) TotalOnlineAgora++;
	}
	return TotalOnlineAgora;
}

int VerTotalJogando()
{
	int TotalOnlineAgora = 0;
	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(Jogando(i)) TotalOnlineAgora++;
	}
	return TotalOnlineAgora;
}

bool Sortear(int Taxa)
{
	if(Taxa == 0)	return false;
	if(Taxa == 100)	return true;

	int Erro = rand()%100;
	if(Erro > Taxa) return false;
	return true;
}

void Setar_Zen(int aIndex, unsigned long Zen)
{
	gObj(aIndex)->Money = Zen;
	GCMoneySend(aIndex, gObj(aIndex)->Money);
}

void Dar_Zen(int aIndex, unsigned long Zen)
{
	if(gObj(aIndex)->Money + Zen > 2000000000)
	{
		gObj(aIndex)->Money = 100000000;
	}else
	{
		gObj(aIndex)->Money += Zen;
	}

	GCMoneySend(aIndex, gObj(aIndex)->Money);
}

void Tirar_Zen(int aIndex, unsigned long Zen)
{
	if(gObj(aIndex)->Money - Zen < 0)
	{
		gObj(aIndex)->Money = 100000000;
	}else
	{
		gObj(aIndex)->Money -= Zen;
	}

	GCMoneySend(aIndex, gObj(aIndex)->Money);
}

void PHeadSetB(LPBYTE lpBuf, BYTE head, int size)
{
	lpBuf[0] = 0xC1;		// Packets
	lpBuf[1] = size;
	lpBuf[2] = head;
}

void PHeadSubSetB(LPBYTE lpBuf, BYTE head, BYTE sub, int size)
{
        lpBuf[0] =0xC1; // Packets
        lpBuf[1] =size;
        lpBuf[2] =head;
        lpBuf[3] =sub;
}

void MsgSlide(int aIndex, LPCTSTR szText, int Color)
{
	BYTE buff[255-0x0e];
	RtlFillMemory(buff,(255-0x0e),0x20);
	BYTE Len=(BYTE)strlen(szText);

	buff[0]=0xC1;
	buff[1]=Len+0x0E;
	buff[2]=0x0D;
	buff[3]=0x0A;
	buff[4]=0x01;
	buff[5]=0x01;
	buff[6]=0x00;
	buff[7]=0x00;

	switch(Color)
	{
	case 1: // Vermelho
		buff[8]		=	255;
		buff[9]		=	0;
		buff[10]	=	0;		
		break;

	case 2: // Verde
		buff[8]		=	0;
		buff[9]		=	255;
		buff[10]	=	0;		
		break;

	case 3: // Azul Escuro
		buff[8]		=	0;
		buff[9]		=	0;
		buff[10]	=	255;		
		break;
	
	case 4: // Azul Claro
		buff[8]		=	0;
		buff[9]		=	255;
		buff[10]	=	255;		
		break;

	case 5: // Roxo
		buff[8]		=	255;
		buff[9]		=	0;
		buff[10]	=	255;		
		break;

	case 6: // Amarelo
		buff[8]		=	255;
		buff[9]		=	255;
		buff[10]	=	0;		
		break;

	case 7: // Branco
		buff[8]		=	255;
		buff[9]		=	255;
		buff[10]	=	255;		
		break;

	default:

		buff[8]		=	255;
		buff[9]		=	255;
		buff[10]	=	255;		
		break;

	}

	buff[11]=0xFF;
	buff[12]=0x14;

	strncpy((char*)&buff[0x0d],szText,Len);

	buff[Len+0x0d]=0;

	if(Jogando(aIndex)) DataSend(aIndex, (PBYTE)buff,  buff[1]);

}

void MsgColorida(LPSTR Msg, int aIndex, int Tipo, int Cor)
{
	BYTE Buffer[0xFF] = {0};
	BYTE Len=strlen(Msg);
	Buffer[0]=0xC1;

	switch(Cor)
	{
	case 0:					// Verde
		Buffer[1]=Len+15;
		Buffer[2]=0x00;
		Buffer[13]=0x40;
		strncpy((char*)&Buffer[14], Msg, Len);
	break;
	case 1:					// Azul Claro
		Buffer[1]=Len+15;
		Buffer[2]=0x00;
		Buffer[13]=0x7E;
		strncpy((char*)&Buffer[14], Msg, Len);
	break;
	case 2:					// Amarelo
		Buffer[1]=Len+14;
		Buffer[2]=0x02;
		strncpy((char*)&Buffer[13],Msg, Len);
	break;
	}
	
	if(Tipo == 0)
	{
		if(Jogando(aIndex)) DataSend(aIndex,(unsigned char*)Buffer,Buffer[1]);
	}else
	{
		for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
		{
			if(Jogando(i)) DataSend(i,(unsigned char*)Buffer,Buffer[1]);
		}
	}
}

void MsgPlayer(char *Msg, int aIndex)
{
	MsgColorida(Msg, aIndex, 0, 2);
}

void MsgCentro(char *Msg, int aIndex)
{
	GCServerMsgStringSend(Msg, aIndex, 0);
}

void MsgServer(char *Msg, int aIndex, int Tipo)
{
	if(Tipo == 0) MsgColorida(Msg, aIndex, 1, 2);	// - Msg para o Server Lateral
	if(Tipo == 1)									// - Msg para o Server Central
	{
		for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
		{
			if(Jogando(i)) MsgCentro(Msg, i);
		}
	}
}

void NpcChat(char * Msg, int NpcIndex, int aIndex)
{
	int len = strlen(Msg);
	if(len < 1 || len > 100-1) return;

	PMSG_CHATDATA_NUMBER pMsg;

	PHeadSetB((LPBYTE)&pMsg, 0x01, len+6);
	strcpy_s(pMsg.chatmsg, sizeof(pMsg.chatmsg), Msg);
	pMsg.NumberH = SET_NUMBERH(NpcIndex);
	pMsg.NumberL = SET_NUMBERL(NpcIndex);
	pMsg.chatmsg[len+1] = 0;

	DataSend(aIndex, (UCHAR*)&pMsg, pMsg.h.size);
}

int GerarItem(int Grupo, int Index)
{
	return ((Grupo * 32) + Index);
}

bool Procurar(char *OndeProcurar, char *Pesquisar, bool CaseSensitive)
{	
	int TotalEncontrado		= 0;
	int TamanhoOndeP		= strlen(OndeProcurar);
	int TamanhoPesq			= strlen(Pesquisar);
	int h = 0;

	if(TamanhoPesq > TamanhoOndeP) return false;
	for(int i = 0; i < TamanhoOndeP; i++)
	{
		char CaractereA = OndeProcurar[i];
		char CaractereB = Pesquisar[h];
		if(!CaseSensitive) CaractereA = tolower(OndeProcurar[h]);
		if(!CaseSensitive) CaractereB = tolower(Pesquisar[h]);

		if(CaractereA == CaractereB) 
		{
			TotalEncontrado++;
			h++;
		}else
		{
			TotalEncontrado = 0;
			h = 0;
		}
		if(TotalEncontrado >= TamanhoPesq) return true;
	}
	if(TotalEncontrado >= TamanhoPesq) return true;
	return false;
}

/*
void Desconectar_Jogadores()
{
	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(Conectado(i)) CloseClient(i);
	}
}
*/

void GS_MsgBox()
{
	MessageBox(0, GS.MsgBox_Msg, GS.MsgBox_Titulo, 0);
}

void GSMsgBox(char * Titulo, char * Msg)
{
	if(strlen(Titulo) < 4)	return;
	if(strlen(Msg) < 4)		return;

	sprintf_s(GS.MsgBox_Titulo, "%s", Titulo);
	sprintf_s(GS.MsgBox_Msg, "%s", Msg);

	CreateThread(0, 0, LPTHREAD_START_ROUTINE(GS_MsgBox), 0, 0, 0);
}