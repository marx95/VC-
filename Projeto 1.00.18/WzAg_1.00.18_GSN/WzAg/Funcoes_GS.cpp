#include "StdAfx.h"

void PHeadSetB(LPBYTE lpBuf, BYTE head, int size)
{
        lpBuf[0] =0xC1;         // Packets
        lpBuf[1] =size;
        lpBuf[2] =head;
}

void PHeadSubSetB(LPBYTE lpBuf, BYTE head, BYTE sub, int size)
{
        lpBuf[0] =0xC1; // Packets
        lpBuf[1] =size;
        lpBuf[2] =head;
        lpBuf[3] =sub;

}

bool No_Duelo(int aIndex1, int aIndex2)
{
	if(aIndex1 < Obj_Jogadores_Minimo || aIndex1 > Obj_Jogadores_Maximo) return false;
	if(aIndex2 < Obj_Jogadores_Minimo || aIndex2 > Obj_Jogadores_Maximo) return false;

	if(gObj(aIndex1)->m_iDuelUser == aIndex2 && gObj(aIndex2)->m_iDuelUser == aIndex1) return true;
	return false;
}

int VerTotalOnline()
{
	int Total = 0;
	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3) Total++;
	}
	return Total;
}

bool Sortear(int Taxa)
{
	if(Taxa == 0)	return false;
	if(Taxa == 100)	return true;

	int Erro = rand()%100;
	if(Erro > Taxa) return false;
	return true;
}

void Set_Life(int aIndex, int Pontos)
{
	if(gObj(aIndex)->DbClass == 0  || gObj(aIndex)->DbClass == 1  || gObj(aIndex)->DbClass == 2)   gObj(aIndex)->MaxLife += (Pontos * 2);
	if(gObj(aIndex)->DbClass == 16 || gObj(aIndex)->DbClass == 17 || gObj(aIndex)->DbClass == 18)  gObj(aIndex)->MaxLife += (Pontos * 3);
	if(gObj(aIndex)->DbClass == 32 || gObj(aIndex)->DbClass == 33 || gObj(aIndex)->DbClass == 34 ) gObj(aIndex)->MaxLife += (Pontos * 2);
	if(gObj(aIndex)->DbClass == 48 || gObj(aIndex)->DbClass == 49) gObj(aIndex)->MaxLife += (Pontos * 2);
	if(gObj(aIndex)->DbClass == 64 || gObj(aIndex)->DbClass == 65) gObj(aIndex)->MaxLife += Pontos;
}

void Set_Mana(int aIndex, int Pontos)
{
	if(gObj(aIndex)->DbClass == 0  || gObj(aIndex)->DbClass == 1  || gObj(aIndex)->DbClass == 2)   gObj(aIndex)->MaxMana += (Pontos * 2);
	if(gObj(aIndex)->DbClass == 16 || gObj(aIndex)->DbClass == 17 || gObj(aIndex)->DbClass == 18)  gObj(aIndex)->MaxMana += Pontos;
	if(gObj(aIndex)->DbClass == 32 || gObj(aIndex)->DbClass == 33 || gObj(aIndex)->DbClass == 34 ) gObj(aIndex)->MaxMana += (Pontos * 2);
	if(gObj(aIndex)->DbClass == 48 || gObj(aIndex)->DbClass == 49) gObj(aIndex)->MaxMana += (Pontos * 2);
	if(gObj(aIndex)->DbClass == 64 || gObj(aIndex)->DbClass == 65) gObj(aIndex)->MaxMana += Pontos;
}

void Chat(char * Msg, int aIndex)
{
	PMSG_CHATDATA Chat;
	strcpy_s(Chat.chatmsg, sizeof(Chat.chatmsg), Msg);
	Chat.h.size					= 14+strlen(Msg);
	Chat.h.c					= 193;
	Chat.h.headcode				= 0;
	gObj(aIndex)->ChatLitmitTime= 0;
	PChatProc(&Chat, aIndex);
}

void NpcChat(char * Msg, int NpcIndex, int aIndex)
{
	ChatTargetSend(gObj(NpcIndex), Msg, aIndex);
}

void FixarBalaoGM(int aIndex)
{
	if(VerificarGM(aIndex))
	{
		gObj(aIndex)->m_ViewSkillState |= 0x1000000;
		GCStateInfoSend(gObj(aIndex), 1, gObj(aIndex)->m_ViewSkillState);
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
	if(CtlCode <= GS.SUB_CtlCode)			return "Necessário ser Sub-Administrador.";
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
	if(CtlCode <= GS.SUB_CtlCode)			return "Sub-Administrador";
	if(CtlCode <= GS.ADM_CtlCode)			return "Administrador";
	if(CtlCode <= GS.ADM_Player_CtlCode)	return "ADM-Player";
	return "Jogador";
}

void MsgParaTodos(char * Texto, int Tipo)
{
	// tipo = 0			Mensagem no CENTRO da tela
	// tipo = 1			Mensagem no CANTO da tela
	// tipo = 2			Mensagem Guild
	if(Tipo > 2)
	{
		return;
	}

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3) GCServerMsgStringSend(Texto, i, Tipo);
	}
}

void MensagemNaBarraSlide(DWORD PlayerID, LPCTSTR szText, int Color)
{
	if(strlen(szText) < 4) return;

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

	DataSend(PlayerID,(PBYTE)buff,buff[1]);
}

void MsgParaJogador(char *Msg, int aIndex)
{
	if(strlen(Msg) < 4) return;
	MsgColorida(Msg, aIndex, 0, 2);
}

void MsgParaJogadorCentro(char *Msg, int aIndex)
{
	if(strlen(Msg) < 4) return;
	GCServerMsgStringSend(Msg, aIndex, 0);
}

void MsgParaServer(char *Msg, int aIndex)
{
	if(strlen(Msg) < 4) return;
	MsgColorida(Msg, aIndex, 1, 2);
}

void MsgColorida(LPSTR Msg, int aIndex, int Tipo, int Cor)
{
	if(strlen(Msg) < 4) return;

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
		if(gObj(aIndex)->Connected == 3) DataSend(aIndex, Buffer, Buffer[1]);
	}else
	{
		for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++){
		if(gObj(i)->Connected == 3)
		{
			DataSend(i, Buffer, Buffer[1]);
		}
	}
	}
}

int GerarItem(int Grupo, int Index)
{
	return ((Grupo * 512) + Index);
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

	return;
	for(int i = Obj_Jogadores_Minimo; i < Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 1)
		{
			if(gObj(i)->MapNumber == gObj(aIndex)->MapNumber)
			{
				gObjClearViewport(gObj(i));
			}
		}
	}
	
	for(int i = 0; i < 75; i++)
	{
		if(gObj(aIndex)->VpPlayer2[i].type == 1)
		{
			if(gObj(aIndex)->VpPlayer2[i].index > 0)
			{
				int tmpIndex = gObj(aIndex)->VpPlayer2[i].index;
				gObjClearViewport(gObj(tmpIndex));
			}
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

	gObjGetStatPointState(aIndex, AddPoint, MaxAddPoint, MinusPoint, MaxMinusPoint);
	pjMsg.AddPoint = AddPoint;
	pjMsg.MaxAddPoint = MaxAddPoint;
	pjMsg.wMinusPoint = MinusPoint;
	pjMsg.wMaxMinusPoint = MaxMinusPoint;
	
	DataSend(aIndex, (UCHAR*)&pjMsg, pjMsg.h.size);

	GCItemListSend(aIndex);
	GCMagicListMultiSend(gObj(aIndex), 0);
	CGRequestQuestInfo(aIndex);
	DGGuildMemberInfoRequest(aIndex);
	FriendListRequest(aIndex);
	CalCharacterEx(aIndex);
	
	for(int i = Obj_Jogadores_Minimo; i < Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3)
		{
			if(gObj(i)->MapNumber == gObj(aIndex)->MapNumber)
			{
				gObjClearViewport(gObj(i));
			}
		}
	}
}