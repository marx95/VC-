#include "StdAfx.h"

bool ChatDataSend(int aIndex, LPBYTE Protocol)
{
	char * MsgRecv = (char*)Protocol+13;	

	if(Procurar(MsgRecv, "/move ", false))
	{
		CustomMove(aIndex, (char*)Protocol+19);
		return true;
	}

	// - Comando Post global
	if(Procurar(MsgRecv, GS.CommandPost, false))
	{
		Post(aIndex,(char*)Protocol+14+strlen(GS.CommandPost));
		return true;
	}

	// - Comandos de add
	int AddTipo		= 0;
	int AddLen		= 0;
	if(Procurar(MsgRecv, GS.CommandStr, false)) { AddTipo = 1; AddLen = strlen(GS.CommandStr);					}
	if(Procurar(MsgRecv, GS.CommandAgi, false)) { AddTipo = 2; AddLen = strlen(GS.CommandAgi);					}
	if(Procurar(MsgRecv, GS.CommandVit, false)) { AddTipo = 3; AddLen = strlen(GS.CommandVit);					}
	if(Procurar(MsgRecv, GS.CommandEne, false)) { AddTipo = 4; AddLen = strlen(GS.CommandEne);					}
	if(Procurar(MsgRecv, GS.CommandCmd, false)) { AddTipo = 5; AddLen = strlen(GS.CommandCmd);					}
	if(AddTipo > 0)								{ AdicionarPontos(aIndex, MsgRecv+1+AddLen, AddTipo); return true;	}

	//- Comando ReloadDrop
	if(Procurar(MsgRecv, GS.ReloadDropCmm, false))
	{
		ReloadDrop(aIndex);
		return true;
	}

	// - Comando ReloadMove
	if(Procurar(MsgRecv, GS.ReloadMoveCmm, false))
	{
		RecarregarMove(aIndex);
		return true;
	}

	// - Comando Recarregar todas as INI's
	if(Procurar(MsgRecv, GS.ReloadConfigCmm, false))
	{
		ReloadConfig(aIndex);
		return true;
	}

	// - Comando Reload Tudo (Monstros, INI's, Lojas, etc)
	if(Procurar(MsgRecv, GS.ReloadTudoCmm, false))
	{
		ReloadTudo(aIndex);
		return true;
	}

	// - Comando Limpar PK
	if(Procurar(MsgRecv, GS.LimparPKcmm, false))
	{
		LimparPK(aIndex, 1);
		return true;
	}

	// - Comando de Ajuda
	if(Procurar(MsgRecv, GS.AjudaCmm, false))
	{
		Ajuda(aIndex);
		return true;
	}

	// - Comando de informaçoes e creditos
	if(Procurar(MsgRecv, "/info", false))
	{
		MsgParaJogador("[Info] GameServer feito por MarxD",aIndex);
		MsgParaJogador("[Info] Base: 1.00.18 GS",aIndex);
		MsgParaJogador("[Info] http://muover.net",aIndex);
		MsgParaJogador("[Info] Creditos á Hotch_ADM!",aIndex);
		return true;
	}

	// - Comando de drop de itens
	if(Procurar(MsgRecv, GS.DropCmm, false))
	{
		DroparItem(aIndex, MsgRecv+1+strlen(GS.DropCmm));
		return true;
	}

	// - Comando PlayerInfo
	if(Procurar(MsgRecv, GS.JInfoCmm, false))
	{
		PersonagemInfo(aIndex, MsgRecv+1+strlen(GS.JInfoCmm));
		return true;
	}

	// - Comando Resetar
	if(Procurar(MsgRecv, GS.ResetarCmm, false))
	{
		Resetar(aIndex);
		return true;
	}

	// - Comando zen
	if(Procurar(MsgRecv, GS.ZenCmm, false))
	{
		Zen(aIndex, 1);
		return true;
	}

	// - Comando mudarbau
	if(Procurar(MsgRecv, GS.BauCmm, false))
	{
		MudarBau(aIndex, MsgRecv+1+strlen(GS.BauCmm));
		return true;
	}

	// - Comando Skin
	if(Procurar(MsgRecv, GS.SkinCmm, false))
	{
		MudarSkin(aIndex, MsgRecv+1+strlen(GS.SkinCmm));
		return true;
	}

	// - Comando Evoluir
	if(Procurar(MsgRecv, GS.EvoCmm, false))
	{
		Evoluir(aIndex, 1);
		return true;
	}

	// - Comando Recarregar Monstros
	if(Procurar(MsgRecv, GS.RMCmm, false))
	{
		RecarregarMonstros(aIndex);
		return true;
	}

	// - Comando Recarregar Lojas
	if(Procurar(MsgRecv, GS.RLCmm, false))
	{
		RecarregarLojas(aIndex);
		return true;
	}

	// - Comando Casar
	if(Procurar(MsgRecv, GS.CasarCmm, false))
	{
		Casar(aIndex, MsgRecv+1+strlen(GS.CasarCmm));
		return true;
	}

	// - Comando Aceitar
	if(Procurar(MsgRecv, GS.AceitarCmm, false))
	{
		AceitarRejeitar(aIndex, 0);
		return true;
	}

	// - Comando Rejeitar
	if(Procurar(MsgRecv, GS.RejeitarCmm, false))
	{
		AceitarRejeitar(aIndex, 1);
		return true;
	}

	// - Comando Divorciar
	if(Procurar(MsgRecv, GS.DivorciarCmm, false))
	{
		Divorciar(aIndex);
		return true;
	}

	// - Comando TotalOnline
	if(Procurar(MsgRecv, GS.TotalOnlineCmm, false))
	{
		TotalOnline(aIndex);
		return true;
	}

	// - Comando MudarClasse
	if(Procurar(MsgRecv, GS.MudarClasseCmm, false))
	{
		MudarClasse(aIndex, MsgRecv+1+strlen(GS.MudarClasseCmm));
		return true;
	}

	// - Comando MasterReset
	if(Procurar(MsgRecv, GS.cmm_MasterReset, false))
	{
		MasterReset(aIndex);
		return true;
	}

	
	// - /bar
	if(Procurar(MsgRecv, "/bar", false))
	{
		if(gObjCustom[aIndex].Vip == 0)
		{
			MsgParaJogador("[Bar] Necessário ser Vip!", aIndex);
			return true;
		}

		if(gObj(aIndex)->Money < 25000)
		{
			MsgParaJogador("[Bar] Necessário 25000 Zen!", aIndex);
			return true;
		}

		gObj(aIndex)->Money -= 25000;
		GCMoneySend(aIndex, gObj(aIndex)->Money);
		gObjTeleport(aIndex, 0, 125, 131);
		return true;
	}

	// - /irbau
	if(Procurar(MsgRecv, "/irbau", false))
	{
		if(gObjCustom[aIndex].Vip == 0)
		{
			MsgParaJogador("[Ir Baú] Necessário ser Vip!", aIndex);
			return true;
		}

		if(gObj(aIndex)->Money < 25000)
		{
			MsgParaJogador("[Ir Baú] Necessário 25000 Zen!", aIndex);
			return true;
		}

		gObj(aIndex)->Money -= 25000;
		GCMoneySend(aIndex, gObj(aIndex)->Money);
		gObjTeleport(aIndex, 0, 150, 110);
		return true;
	}

	// - /globin
	if(Procurar(MsgRecv, "/goblin", false))
	{
		if(gObjCustom[aIndex].Vip == 0)
		{
			MsgParaJogador("[Goblin] Necessário ser Vip!", aIndex);
			return true;
		}

		if(gObj(aIndex)->Money < 25000)
		{
			MsgParaJogador("[Goblin] Necessário 25000 Zen!", aIndex);
			return true;
		}

		gObj(aIndex)->Money -= 25000;
		GCMoneySend(aIndex, gObj(aIndex)->Money);
		gObjTeleport(aIndex, 3, 180, 99);
		return true;
	}

	// - /pvp1
	if(Procurar(MsgRecv, "/pvp1", false))
	{
		if(gObj(aIndex)->Level < GS.Level_Minimo_para_PVP)
		{
			char MsgTmpLvMin[64];
			sprintf_s(MsgTmpLvMin, "[PVP1] Level necessário: %d,", GS.Level_Minimo_para_PVP);
			MsgParaJogador(MsgTmpLvMin, aIndex);
			return true;
		}

		MsgParaJogador("[PVP1] Você entrou no PVP!", aIndex);
		int PosX = (GS.PVP1_CordX-2)+rand()%5;
		int PosY = (GS.PVP1_CordX-2)+rand()%5;
		gObjTeleport(aIndex, GS.PVP1_Mapa_PVP, PosX, PosY);
		return true;
	}

	// - /pvp2
	if(Procurar(MsgRecv, "/pvp2", false))
	{
		if(gObj(aIndex)->Level < GS.Level_Minimo_para_PVP)
		{
			char MsgTmpLvMin[64];
			sprintf_s(MsgTmpLvMin, "[PVP2] Level necessário: %d,", GS.Level_Minimo_para_PVP);
			MsgParaJogador(MsgTmpLvMin, aIndex);
			return true;
		}

		MsgParaJogador("[PVP2] Você entrou no PVP!", aIndex);
		int PosX = (GS.PVP2_CordX-2)+rand()%5;
		int PosY = (GS.PVP2_CordX-2)+rand()%5;
		gObjTeleport(aIndex, GS.PVP2_Mapa_PVP, PosX, PosY);
		return true;
	}

	// - /salagm
	if(Procurar(MsgRecv, "/salagm", false))
	{
		if(gObjCustom[aIndex].CtlCode < GS.GM_CtlCode)
		{
			char MsgCtlCode[64];
			sprintf_s(MsgCtlCode, "[Sala GM] %s", VerificarCtlCode(aIndex, GS.GM_CtlCode));
			MsgParaJogador(MsgCtlCode, aIndex);
			return true;
		}

		gObjTeleport(aIndex, 40, 225, 31);
		return true;
	}

	// - Comando Puxar <personagem>
	if(Procurar(MsgRecv, GS.PuxarCmm, false))
	{
		Puxar(aIndex, MsgRecv+1+strlen(GS.PuxarCmm));
		return true;
	}

	// - Comando PuxarTodos
	if(Procurar(MsgRecv, GS.PuxarTodosCmm, false))
	{
		PuxarTodos(aIndex);
		return true;
	}

	// - Comando GmPuxarTodos
	if(Procurar(MsgRecv, GS.GmPuxarTodosCmm, false))
	{
		GmPuxarTodos(aIndex);
		return true;
	}

	// - Comando evento
	if(Procurar(MsgRecv, GS.EventoCmm, false))
	{
		if(GS.cmm_Evento_X == 0 || GS.cmm_Evento_Y == 0)
		{
			MsgParaJogador("[Evento] Nenhum evento no momento.", aIndex);
			return true;
		}

		gObjTeleport(aIndex, GS.cmm_Evento_Mapa, GS.cmm_Evento_X, GS.cmm_Evento_Y);
		MsgParaJogador("[Evento] Você foi ao evento.", aIndex);
		return true;
	}

	// - Comando setevento
	if(Procurar(MsgRecv, GS.SetEventoCmm, false))
	{
		SetarEvento(aIndex, MsgRecv+1+strlen(GS.SetEventoCmm));
		return true;
	}

	// - /gmove
	if(Procurar(MsgRecv, "/gmove ", false))
	{
		gMoveCmm(aIndex, MsgRecv+strlen("/gmove "));
		return true;
	}

	// - Comando Limpar Inventario
	if(Procurar(MsgRecv, GS.cmm_LimparInventario, false))
	{
		LimparInventario(aIndex);
		return true;
	}

	// - Comando Summonar Monstros
	if(Procurar(MsgRecv, GS.cmm_InvocarMonstro, false))
	{
		InvocarPET(aIndex, MsgRecv+1+strlen(GS.cmm_InvocarMonstro));
		return true;
	}

	// - ChatOff
	if(Procurar(MsgRecv, "/chatoff ", false))
	{
		ChatOff(aIndex, MsgRecv+strlen("/chatoff "));
		return true;
	}

	// - ChatOn
	if(Procurar(MsgRecv, "/chaton ", false))
	{
		ChatOn(aIndex, MsgRecv+strlen("/chaton "));
		return true;
	}
		return false;
	}