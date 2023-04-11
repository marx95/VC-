#include "StdAfx.h"

BYTE ProtocolCore_Fix(BYTE aRecv)
{
	switch(aRecv)
	{
		case 0xD7: return 0xD9; break; // - Andar
		case 0xD0: return 0xDC; break; // - Dano
		case 0xD9: return 0x15; break; // - Ataque
		//case 0x1D: return 0x1D; break; // - Skill
	}

	return aRecv;
}

void ProtocolCore_Hook(unsigned char protoNum, unsigned char * aRecv, int aLen, int aIndex, int Encrypt, int serial)
{

	if(aRecv[0] == 0xC1 || aRecv[0] == 0xC3)
	{
		BYTE btFix = ProtocolCore_Fix(aRecv[2]);
		protoNum = btFix;
		aRecv[2] = btFix;
	}

	if(protoNum == 0xF1 || protoNum == 0xF3)
	{
		switch(protoNum)
		{
			case 0x0E: 
				return;
			break;

			case 0xF1:
			{
				PMSG_DEFAULT2 * lpMsg2 = (PMSG_DEFAULT2 *)aRecv;
				
				if(lpMsg2->subcode == 0x03) return; // - Fix CGClientMsg
			}
			break;

			case 0xF3:
			{
				PMSG_DEFAULT2 * lpMsg2 = (PMSG_DEFAULT2 *)aRecv;
				
				if(lpMsg2->subcode == 0x00) // - DataServerGetCharListRequest
				{
					Pegar_gObjCustom_AccInfo(aIndex);
				}

				if(lpMsg2->subcode == 0x06)
				{
					if(Verificar_Pontos(aIndex, aRecv[4]) == false) return;
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
					MsgServer(MsgSaidaB, aIndex, 1);
					return;
				}

				if(aRecv[13] == '/')
				{
					if(CharCore(aIndex, aRecv)) return;
				}

				if(aRecv[13] == '@')
				{

					if(Procurar(((char*)aRecv+13), "@warp", false))
					{
						if(gObjCustom[aIndex].Vip == 0)
						{
							if(!VerificarGM(aIndex)) return;
						}

						int Map = gObj(aIndex)->MapNumber;
						if(Map == 5) { MsgPlayer("Server: Warp não autorizado!", aIndex); return; }
						if(Map == 9) { MsgPlayer("Server: Warp não autorizado!", aIndex); return; }
						if(Map >= 11 && Map <= 16) { MsgPlayer("Server: Warp não autorizado!", aIndex); return; }
						if(Map >= 18 && Map <= 31) { MsgPlayer("Server: Warp não autorizado!", aIndex); return; }
						
						gObjTeleport(aIndex, Map, rand()%256, rand()%256);
						MsgPlayer("Server: Teleportado!", aIndex);
						return;
					}
				}

				if(gObjCustom[aIndex].ChatOn == false) return;
			break;
			case 0x0E: // - Fix CGLiveClient
				if(gObj(aIndex)->Connected > J_Conectado) gObj(aIndex)->ConnectCheckTime = GetTickCount();
				return;
			break;
			case 0xD9: // - Andar
				if(gObjCustom[aIndex].Bau_Aberto)
				{
					Mssql_Atualiza(aIndex, 4);
					MsgPlayer("[Baú] Fechado!", aIndex);
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
}