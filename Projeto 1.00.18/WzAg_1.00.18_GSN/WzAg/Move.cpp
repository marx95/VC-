#include "StdAfx.h"

MoveStruct Move[512];
int TotalMove;

void CarregarMove()
{
	//Sistema começa a partir daqui
	TotalMove = 0;
	Tokenizer          token;
	TokenizerGroup     group;
	TokenizerSection   section;

	token.ParseFile(std::string("..\\MarxD\\Move.txt"), group);

	if(group.GetSection(0, section))
	{
		for(int a = 0; a < section.RowCount; a++)
		{
			for(int i = 0; i < 32; i++)
			{
				Move[TotalMove].Nome[i] = 0x00;
			}

			sprintf_s(Move[TotalMove].Nome, "%s", section.Rows[a].GetStringPtr(0));
			Move[TotalMove].Mapa	= section.Rows[a].GetInt(1);
			Move[TotalMove].X		= section.Rows[a].GetInt(2);
			Move[TotalMove].Y		= section.Rows[a].GetInt(3);
			Move[TotalMove].Level	= section.Rows[a].GetInt(4);
			Move[TotalMove].Rand	= section.Rows[a].GetInt(5);
			Move[TotalMove].Custo	= section.Rows[a].GetInt(6);
			TotalMove++;
		}
	}
	
}

void CustomMove(int aIndex, char* Nome)
{
	//ATENÇAO
	// Return True = Para quando nao deixar teleportar e nao deixar retornar o pacote á função original!
	// Return False = Deixa o pacote ir á função original!
	// - Anti-Hack Check's
	if(gObj(aIndex)->TargetNumber != -1 && gObj(aIndex)->pTransaction == 1)
	{
		MsgParaJogador("[Anti-Hack] Tentando fazer Dupe?", aIndex);
		return;
	}else
	{
		int Dupe = 0;
		switch(gObj(aIndex)->m_IfState)
		{
			case 1:	  Dupe = 1; break;
			case 389: Dupe = 1; break;
			case 769: Dupe = 1; break;
			case 829: Dupe = 1; break;
		}

		if(Dupe == 1)
		{
			MsgParaJogador("[Anti-Hack] Tentando fazer Dupe?", aIndex);
			return;
		}
	}

	// - PK Check's
	if(gObj(aIndex)->m_PK_Level < 0)
	{
		MsgParaJogador("[Move] PK não pode mover!", aIndex);
		return;
	}

	// - Inicio do sistema de Move
	for(int i = 0; i < TotalMove; i++)
	{
		if(Procurar(Move[i].Nome, Nome, false))
		{
			int LevelMinimo = Move[i].Level;
			if(gObj(aIndex)->DbClass == 48 ||gObj(aIndex)->DbClass == 49 ||gObj(aIndex)->DbClass == 64 || gObj(aIndex)->DbClass == 65)
			{
				LevelMinimo = (Move[i].Level*65)/100;
			}

			if(gObj(aIndex)->Level < LevelMinimo)
			{
				char MsgMove[64];
				sprintf_s(MsgMove, "[%s] Necessário level %d.", Move[i].Nome, LevelMinimo);
				MsgParaJogador(MsgMove, aIndex);
				return;
			}

			if(gObj(aIndex)->Money < Move[i].Custo)
			{
				char MsgCusto[64];
				sprintf_s(MsgCusto, "[Move] Necessário %d zen.", Move[i].Custo);
				MsgParaJogador(MsgCusto, aIndex);
				return;
			}

			int rndX = Move[i].X;
			int rndY = Move[i].Y;

			if(Move[i].Rand == 1)
			{
				rndX = (rndX - 3) + rand()%7;
				rndY = (rndY - 3) + rand()%7;
			}

			gObj(aIndex)->Money -= Move[i].Custo;
			GCMoneySend(aIndex,gObj(aIndex)->Money);
			gObjTeleport(aIndex, Move[i].Mapa, rndX, rndY);
			return;
		}
	}
}