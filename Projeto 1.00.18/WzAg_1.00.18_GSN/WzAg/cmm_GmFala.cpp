#include "StdAfx.h"

void GMFala(int aIndex, char *Msg)
{

	if(strlen(Msg) < 2) return;
	char MsgSaida[255];
	sprintf_s(MsgSaida, "%s: %s", gObj(aIndex)->Name, Msg);
	MsgParaTodos(MsgSaida, 0);
}