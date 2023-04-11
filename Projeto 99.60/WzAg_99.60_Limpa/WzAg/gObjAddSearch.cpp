#include "stdafx.h"

short gObjAddSearch_Hook(unsigned int aSocket, char* ip)
{
	if(!GS.Cnn_Liberado)					return -1;
	if(VerTotalConectado() > GS.MaxUsers)	return -1;

	for(int i = Obj_Jogadores_Minimo; i < Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == J_Vazio)
		{
			gObj(i)->Connected = J_Conectado;
			return i;
		}
	}

	//GCJoinSocketResult(4, aSocket); // - Desconectado do servidor
	return -1;
	
	/*///////////////////// CORRIGIR vvv
	if(VerTotalConectado() > GS.MaxUsers)
	{
		if(IsIP(ip) == 0) GCJoinSocketResult(4, aSocket); // - Server Cheio
	}
	else
	{
		for(int i = Obj_Jogadores_Minimo; i < Obj_Jogadores_Maximo; i++)
		{
			if(gObj(i)->Connected == J_Vazio)
			{
				gObj(i)->Connected = J_Conectado;
				return i;
			}
		}

		if(IsIP(ip) == 0) GCJoinSocketResult(4, aSocket); // - Server Cheio
	}

	return -1;*/
}