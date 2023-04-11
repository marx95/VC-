#include "StdAfx.h"

void EnviarNoticias()
{
	switch(GS.Noticias_Info)
	{
	case 0:
		if(strlen(GS.Noticia_A) > 4) MsgParaTodos(GS.Noticia_A, 0);
		if(strlen(GS.Noticia_B) > 4) MsgParaTodos(GS.Noticia_B, 0);
		if(strlen(GS.Noticia_C) > 4) MsgParaTodos(GS.Noticia_C, 0);
		if(strlen(GS.Noticia_D) > 4) MsgParaTodos(GS.Noticia_D, 0);
		GS.Noticias_Info = 1;
	break;

	case 1:
		if(strlen(GS.Noticia_E) > 4)MsgParaTodos(GS.Noticia_E, 0);
		if(strlen(GS.Noticia_F) > 4)MsgParaTodos(GS.Noticia_F, 0);
		if(strlen(GS.Noticia_G) > 4)MsgParaTodos(GS.Noticia_G, 0);
		if(strlen(GS.Noticia_H) > 4)MsgParaTodos(GS.Noticia_H, 0);
		GS.Noticias_Info = 2;
	break;

	case 2:
		if(strlen(GS.Noticia_I) > 4) MsgParaTodos(GS.Noticia_I, 0);
		if(strlen(GS.Noticia_J) > 4) MsgParaTodos(GS.Noticia_J, 0);
		if(strlen(GS.Noticia_K) > 4) MsgParaTodos(GS.Noticia_K, 0);
		if(strlen(GS.Noticia_L) > 4) MsgParaTodos(GS.Noticia_L, 0);
		GS.Noticias_Info = 3;
	break;

	case 3:
		if(strlen(GS.Noticia_M) > 4) MsgParaTodos(GS.Noticia_M, 0);
		if(strlen(GS.Noticia_N) > 4) MsgParaTodos(GS.Noticia_N, 0);
		if(strlen(GS.Noticia_O) > 4) MsgParaTodos(GS.Noticia_O, 0);
		if(strlen(GS.Noticia_P) > 4) MsgParaTodos(GS.Noticia_P, 0);
		GS.Noticias_Info = 4;
	break;

	case 4:
		if(strlen(GS.Noticia_Q) > 4) MsgParaTodos(GS.Noticia_Q, 0);
		if(strlen(GS.Noticia_R) > 4) MsgParaTodos(GS.Noticia_R, 0);
		if(strlen(GS.Noticia_S) > 4) MsgParaTodos(GS.Noticia_S, 0);
		if(strlen(GS.Noticia_T) > 4) MsgParaTodos(GS.Noticia_T, 0);
		GS.Noticias_Info = 0;
	break;
	}
}

// - Esta função pode lagar o jogo
void Noticias_Timer()
{
	while(true)
	{
		int Liberado = 1;

		for(int i = Obj_Jogadores_Minimo; i < Obj_Jogadores_Maximo; i++)
		{
			if(gObj(i)->Connected == 3)
			{
				if(VerificarGM(i)) Liberado = 0;
			}
		}

		if(Liberado == 1)
		{
			if(GS.Noticias_Tempo == 0) GS.Noticias_Tempo = 5; // Para nao bugar!
			if(GS.Noticias_Ativado == 1) EnviarNoticias();
		}

		Sleep((1000*60)*GS.Noticias_Tempo);
	}
	
}