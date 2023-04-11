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

BYTE Fixar_ProtocolSend(BYTE aRecv)
{	
	switch(aRecv)
	{
		case 0x1D: return 0xD3; break; // - Andar
		//case 0xD7: return 0x10; break; // - Skill, Não é necessário fixar!
		case 0xD6: return 0xDF; break; // - Dano
		case 0xDC: return 0xD7; break; // - Ataque
	}
	return aRecv;
}

void ProtocolCore_Hook(BYTE protoNum, unsigned char * aRecv, int aLen, int aIndex, BOOL Encrypt, int serial)
{
	if(aRecv[0] == 0xC1)
	{
		BYTE bFix = Fixar_ProtocolCore(aRecv[2]);
		aRecv[2] = bFix;
		protoNum = bFix;
	}

	if(protoNum == 0xF1 || protoNum == 0xF3)
	{
		switch(protoNum)
		{
			case 0x0E: 
				return;
			break;

			//case 0xF1:
			//{
			//	PMSG_DEFAULT2 * lpMsg2 = (PMSG_DEFAULT2 *)aRecv;
				
			//	if(lpMsg2->subcode == 0x03) return; // - Fix CGClientMsg
			//}
			//break;

			case 0xF3:
			{
				PMSG_DEFAULT2 * lpMsg2 = (PMSG_DEFAULT2 *)aRecv;
				
				if(lpMsg2->subcode == 0x00) // - DataServerGetCharListRequest
				{
					Pegar_gObjCustom_AccInfo(aIndex);
				}

				if(lpMsg2->subcode == 0x06)
				{
					if(VerificarPontos(aIndex, aRecv[4]) == false) return;
				}
			}
			break;
		}
	}
	else
	{
		switch(protoNum)
		{
			case 0x00: // - PChatProc
				if(aRecv[13] == '!')
				{
					if(gObjCustom[aIndex].CtlCode < GS.GM_CtlCode) return;
					if(gObjCustom[aIndex].CtlCode == GS.ADM_Player_CtlCode) return;
					char MsgSaidaB[64];
					sprintf_s(MsgSaidaB, "%s: %s", gObj(aIndex)->Name, (char*)aRecv+14);
					MsgParaTodos(MsgSaidaB, 0);
					return;
				}

				if(aRecv[13] == '/')
				{
					if(ChatDataSend(aIndex, aRecv)) return;;
				}

				if(gObjCustom[aIndex].ChatBlock == 1) return;

				break;
			case 0x0E: // - Fix CGLiveClient
				if(gObj(aIndex)->Connected > 1) gObj(aIndex)->ConnectCheckTime = GetTickCount();
				return;
			break;
			case 0x1D: // - Andar
				if(gObjCustom[aIndex].BauAberto == 1)
				{
					Mssql_Atualiza(aIndex, 4);
					MsgParaJogador("[Baú] Fechado!", aIndex);
				}
			break;
			case 0x30: // - NpcClick (GTalkRequest)
				if(NpcClick(aIndex, (aRecv[4] + aRecv[3] * 256))) return;
			break;
			case 0x86:
				if(CGChaosBoxItemMixButtonClick((PMSG_CHAOSMIX *)aRecv, aIndex)) return;
			break;
		}
	}

	ProtocolCore(protoNum, aRecv, aLen, aIndex, Encrypt, serial);
	return;
}

bool DataSend_Hook(int aIndex, PBYTE tpProtocol, DWORD ProtocolLen)
{
	if(tpProtocol[0] == 0xC1) tpProtocol[2] = Fixar_ProtocolSend(tpProtocol[2]);
	return DataSend(aIndex, tpProtocol, ProtocolLen);
}