#include "stdafx.h"

bool CharCore(int aIndex, LPBYTE Packet)
{
	char * MsgRecv = (char*)Packet+13;

	if(Procurar(MsgRecv, "/limparinv", false))
	{
		for(int i = 12; i<76; i++)
		{
			gObjInventoryDeleteItem(aIndex, i);
			GCInventoryItemDeleteSend(aIndex, i, 1);
		}

		MsgPlayer("[Limpar Inv.] Inventário Limpo!", aIndex);
		return true;
	}

	/*


	*/

	if(Procurar(MsgRecv, "/test", false))
	{
		gObj(aIndex)->Dexterity = 50;
		gObj(aIndex)->LevelUpPoint = 65000;
		Atualizar_Personagem(aIndex);
		return true;
	}

	//*
	if(Procurar(MsgRecv, "/abrirbau", false))
	{
		gObj(aIndex)->m_IfState.use		= 1;
		gObj(aIndex)->m_IfState.type	= 3;
		gObj(aIndex)->m_ShopTime		= 0;

		gObj(aIndex)->m_ReqWarehouseOpen= true;
		gObj(aIndex)->m_IfState.type	= 6;
		gObj(aIndex)->m_IfState.state	= 0;

		gObj(aIndex)->WarehouseCount	= 0;
		GDGetWarehouseList(aIndex, gObj(aIndex)->AccountID);
		return true;
	}
	//*/

	/*
	if(Procurar(MsgRecv, "/teste", false))
	{
		//mssql.Rodar_Query("UPDATE ASUASHUHUAS WHER");
		//GJSetCharacterInfo(gObj(aIndex), aIndex);
		KundunEventItemBoxOpen(gObj(aIndex), gObj(aIndex)->MapNumber, gObj(aIndex)->X, gObj(aIndex)->Y);
		return true;
	}
	/*/

	if(Procurar(MsgRecv, "/resetstat", false))
	{
		if(gObjCustom[aIndex].Vip == 0)
		{
			MsgPlayer("[R. Status] Necessário ser VIP!", aIndex);
			return true;
		}

		int pt = 0;
		pt += gObj(aIndex)->Strength;
		pt += gObj(aIndex)->Dexterity;
		pt += gObj(aIndex)->Vitality;
		pt += gObj(aIndex)->Energy;
		if(gObj(aIndex)->Class == 4) pt += gObj(aIndex)->Leadership;

		gObj(aIndex)->LevelUpPoint	= pt;
		gObj(aIndex)->Strength		= 0;
		gObj(aIndex)->Dexterity		= 0;
		gObj(aIndex)->Vitality		= 0;
		gObj(aIndex)->Energy		= 0;
		if(gObj(aIndex)->Class == 4) gObj(aIndex)->Leadership = 0;
		
		Atualizar_Personagem(aIndex);
		MsgPlayer("[R. Status] Os pontos foram zerados!", aIndex);
		return true;
	}

	if(Procurar(MsgRecv, "/info", false))
	{
		MsgPlayer("[Info] GameServer 0.99.60T por MarxD.", aIndex);
		MsgPlayer("[Info] Exclusivo do www.muover.net", aIndex);
		return true;
	}

	if(Procurar(MsgRecv, "/totalon", false))
	{
		int Total = 0;
		char MsgTO[128];

		for(int i = Obj_Jogadores_Minimo; i < Obj_Jogadores_Maximo; i++)
		{
			if(Jogando(i)) Total++;
		}
		
		sprintf_s(MsgTO, "[T. On] %d jogando agora!", Total);
		MsgPlayer(MsgTO, aIndex);
		return true;
	}

	if(Procurar(MsgRecv, "/ferreiro", false))
	{
		gObjTeleport(aIndex, 0, 119, 141);
		return true;
	}

	if(Procurar(MsgRecv, "/mago", false))
	{
		gObjTeleport(aIndex, 0, 120, 113);
		return true;
	}

	if(Procurar(MsgRecv, "/pvp1", false))
	{
		if(gObj(aIndex)->Level < GS.Level_Minimo_para_PVP)
		{
			char MsgPVP[64];
			sprintf_s(MsgPVP, "[PVP 1] Level mínimo %d!", GS.Level_Minimo_para_PVP);
			MsgPlayer(MsgPVP, aIndex);
			return true;
		}

		gObjTeleport(aIndex, GS.PVP1_Mapa_PVP, (GS.PVP1_CordX-3)+(rand()%7), (GS.PVP1_CordY-3)+(rand()%7));
		MsgPlayer("[PVP 1] Você entrou no PVP!", aIndex);
		return true;
	}

	if(Procurar(MsgRecv, "/pvp2", false))
	{
		if(gObj(aIndex)->Level < GS.Level_Minimo_para_PVP)
		{
			char MsgPVP[64];
			sprintf_s(MsgPVP, "[PVP 2] Level mínimo %d!", GS.Level_Minimo_para_PVP);
			MsgPlayer(MsgPVP, aIndex);
			return true;
		}

		gObjTeleport(aIndex, GS.PVP2_Mapa_PVP, (GS.PVP2_CordX-3)+(rand()%7), (GS.PVP2_CordY-3)+(rand()%7));
		MsgPlayer("[PVP 2] Você entrou no PVP!", aIndex);
		return true;
	}
	
	if(Procurar(MsgRecv, "/move ", false))
	{
		CustomMove(aIndex, (char*)Packet+19);
		return true;
	}

	if(Procurar(MsgRecv, "/rconfig", false))
	{
		cmm_rconfig(aIndex);
		return true;
	}

	if(Procurar(MsgRecv, "/dc ", false))
	{
		cmm_DC(aIndex, (char*)Packet+17);
		return true;
	}
	
	if(Procurar(MsgRecv, "/gmove ", false))
	{
		cmm_gMove(aIndex, (char*)Packet+20);
		return true;
	}

	if(Procurar(MsgRecv, "/puxar ", false))
	{
		cmm_puxar(aIndex, (char*)Packet+20);
		return true;
	}

	if(Procurar(MsgRecv, "/ptodos", false))
	{
		cmm_puxartodos(aIndex);
		return true;
	}

	if(Procurar(MsgRecv, "/drop ", false))
	{
		cmm_drop(aIndex, (char*)Packet+19);
		return true;
	}

	if(Procurar(MsgRecv, "/chuva ", false))
	{
		cmm_chuva(aIndex, (char*)Packet+19);
		return true;
	}

	if(Procurar(MsgRecv, "/bar", false))
	{
		if(gObjCustom[aIndex].Vip == 0)
		{
			MsgPlayer("[Bar] Necessário ser VIP", aIndex);
			return true;
		}

		gObjTeleport(aIndex, 0, 124, 130);
		return true;
	}

	if(Procurar(MsgRecv, "/irbau", false))
	{
		if(gObjCustom[aIndex].Vip == 0)
		{
			MsgPlayer("[Ir Baú] Necessário ser VIP", aIndex);
			return true;
		}

		gObjTeleport(aIndex, 0, 148, 110);
		return true;
	}

	if(Procurar(MsgRecv, "/for", false)) { cmm_AddPontos(aIndex, (char*)Packet+18, 0); return true; }
	if(Procurar(MsgRecv, "/agi", false)) { cmm_AddPontos(aIndex, (char*)Packet+18, 1); return true; }
	if(Procurar(MsgRecv, "/vit", false)) { cmm_AddPontos(aIndex, (char*)Packet+18, 2); return true; }
	if(Procurar(MsgRecv, "/ene", false)) { cmm_AddPontos(aIndex, (char*)Packet+18, 3); return true; }
	if(Procurar(MsgRecv, "/com", false)) { cmm_AddPontos(aIndex, (char*)Packet+18, 4); return true; }

	if(Procurar(MsgRecv, "/f ", false)) { cmm_AddPontos(aIndex, (char*)Packet+16, 0); return true; }
	if(Procurar(MsgRecv, "/a ", false)) { cmm_AddPontos(aIndex, (char*)Packet+16, 1); return true; }
	if(Procurar(MsgRecv, "/v ", false)) { cmm_AddPontos(aIndex, (char*)Packet+16, 2); return true; }
	if(Procurar(MsgRecv, "/e ", false)) { cmm_AddPontos(aIndex, (char*)Packet+16, 3); return true; }
	if(Procurar(MsgRecv, "/c ", false)) { cmm_AddPontos(aIndex, (char*)Packet+16, 4); return true; }
	if(Procurar(MsgRecv, "/l ", false)) { cmm_AddPontos(aIndex, (char*)Packet+16, 4); return true; }

	if(Procurar(MsgRecv, GS.Post, false))
	{
		if(gObjCustom[aIndex].ChatOn) cmm_Post(aIndex, (char*)Packet+13+GS.Post_Len);
		return true;
	}

	if(Procurar(MsgRecv, GS.Bau, false))
	{
		cmm_Bau(aIndex, (char*)Packet+13+GS.Bau_Len);
		return true;
	}

	if(Procurar(MsgRecv, GS.LPK, false))
	{
		cmm_LimparPK(aIndex);
		return true;
	}

	if(Procurar(MsgRecv, GS.Reset, false))
	{
		cmm_Reset(aIndex);
		return true;
	}

	if(Procurar(MsgRecv, GS.MasterReset, false))
	{
		cmm_MasterReset(aIndex);
		return true;
	}

	return false;
}