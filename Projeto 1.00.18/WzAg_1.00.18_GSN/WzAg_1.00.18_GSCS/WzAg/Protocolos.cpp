#include "StdAfx.h"

BYTE Fixar_ProtocolCore(BYTE aRecv)
{
	switch(aRecv)
	{
		case 0xD3: return 0x1D; break; // - Andar
		case 0x10: return 0xD7; break; // - Skill
		case 0xDF: return 0xD6; break; // - Dano
		case 0xD7: return 0xDC; break; // - Ataque
	}
	return aRecv;
}

void ProtocolCore_Hook(BYTE protoNum, unsigned char * aRecv, int aLen, int aIndex, BOOL Encrypt, int serial)
{
	if(aRecv[0] == 0xC1) 
	{
		BYTE btFix = Fixar_ProtocolCore(aRecv[2]);
		aRecv[2] = btFix;
		protoNum = btFix;
	}

	switch(aRecv[0])
		{
		case 0xC1:
			switch(aRecv[2])
			{
			case 0x00:
				if(aRecv[13] == '/') ChatDataSend(aIndex, aRecv);
			break;
			case 0x03:
				func_mssql.Pegar_gObjCustom(aIndex);
				MsgParaJogadorCentro("Você está no servidor Castle-Siege", aIndex);
			break;
			case 0x1D:
				if(gObjCustom[aIndex].BauAberto == 1) func_mssql.Atualiza(aIndex, 4); //Isto interfere no comando de MUDAR BAU -- Cuidado!!
			break;
			case 0x30:
				if(NpcClick(aIndex,(aRecv[4] + aRecv[3] * 256)) == false) return;
			break;
			case 0xF3:
				if(aRecv[3] == 0x06)
				{
					if(gObjCustom[aIndex].Limite_Pontos)
					{
						if(AdicionarSingle(aIndex, aRecv[4]) == false) return;
					}
				}
			break;
			}
		}

	ProtocolCore(protoNum, aRecv, aLen, aIndex, Encrypt, serial);
}

BYTE Fixar_ProtocolSend(BYTE aRecv)
{
	switch(aRecv)
	{
		case 0x1D: return 0xD3; break; // - Andar
		case 0xD7: return aRecv; break; // - Skill, Não é necessário fixar!
		case 0xD6: return 0xDF; break; // - Dano
		case 0xDC: return 0xD7; break; // - Ataque
	}
	return aRecv;
}

bool DataSend_Hook(int aIndex, unsigned char* lpMsg, DWORD dwSize)
{
	if(lpMsg[0] == 0xC1) lpMsg[2] = Fixar_ProtocolSend(lpMsg[2]);
	return DataSend(aIndex, lpMsg, dwSize);
}