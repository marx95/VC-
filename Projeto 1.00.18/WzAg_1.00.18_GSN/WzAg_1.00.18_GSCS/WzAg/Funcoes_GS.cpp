#include "StdAfx.h"

void MsgParaTodos(char * Texto, int Tipo)
{
	// tipo = 0			Mensagem no CENTRO da tela
	// tipo = 1			Mensagem no CANTO da tela
	// tipo = 2			Mensagem Guild
	if(Tipo > 2)
	{
		return;
	}

	for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++){
		if(gObj(i)->Connected == 3)
		{
			GCServerMsgStringSend(Texto, i, Tipo);
		}
	}
}
void DataSendAll(unsigned char* Packet, int Length)
{
	for (int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3)
		{
			DataSend(i, Packet, Length);
		}
	}
}

//MSG A TODOS EM AMARELO
void ServerMsgSend(DWORD wId, int Type, char Sender[20], const char* Message, ...)
{
	char szBuffer[1024];
	va_list pArguments;
	va_start(pArguments, Message);
	vsprintf(szBuffer, Message, pArguments);
	va_end(pArguments);
	BYTE *Packet;
	Packet = (BYTE*) malloc(200);
	memset(Packet, 0x00, 200);
	*Packet = 0xC1;
	if (Type) *(Packet+2) = 0x02;
	else *(Packet+2) = 0x00;
	memcpy((Packet+3), Sender, strlen(Sender));
	memcpy((Packet+13), szBuffer, strlen(szBuffer));
	int Len = (strlen(szBuffer) + 0x13);
	*(Packet+1) = Len;
	if (!wId) DataSendAll(Packet, Len);
	else
	if(gObj(wId)->Connected == 3)
	DataSend(wId,Packet, Len);
	free(Packet);
}

void MensagemNaBarraSlide(DWORD PlayerID, LPCTSTR szText, int Color)
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

	switch(Color){
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

void MsgParaJogador(char *Msg, DWORD aIndex)
{
	MsgColorida(Msg, aIndex, 0, 2);
}

void MsgParaJogadorCentro(char *Msg, DWORD aIndex)
{
	GCServerMsgStringSend(Msg, aIndex, 0);
}

void MsgParaServer(char *Msg, DWORD aIndex)
{
	MsgColorida(Msg, aIndex, 1, 2);
}

void MsgColorida(LPSTR Msg, DWORD aIndex, int Tipo, int Cor)
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
		DataSend(aIndex,(unsigned char*)Buffer,Buffer[1]);
	}else
	{
		for(int i=Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++){
		if(gObj(i)->Connected == 3)
		{
			DataSend(i,(unsigned char*)Buffer,Buffer[1]);
		}
	}
	}
}

void gObjWrite(int aIndex,int gObjParam,long int Value)
{
	*(long int*)(aIndex * gObjSize + GS_BASE + gObjParam) = Value;
}