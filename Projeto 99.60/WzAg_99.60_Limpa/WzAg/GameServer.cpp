#include "stdafx.h"

void JoinServer_Timer()
{
	while(true)
	{
		Sleep(60000); // 1 MINUTO
		
		for(int aIndex = Obj_Jogadores_Minimo; aIndex < Obj_Jogadores_Maximo; aIndex++)
		{
			if(Logado(aIndex)) Mssql_Atualiza(aIndex, 10);
		}

		DbConnection.Executar("UPDATE MEMB_STAT SET ConnectStat = 1, UpStat=UpStat-1 WHERE UpStat > 0");
		DbConnection.Executar("UPDATE MEMB_STAT SET ConnectStat = 0 WHERE ConnectStat = 1 AND UpStat = 0");
	}
}

void GS_Timer()
{
	while(true)
	{
		Sleep(1000);
		for(int aIndex = Obj_Jogadores_Minimo; aIndex < Obj_Jogadores_Maximo; aIndex++)
		{
			if(Logado(aIndex)) gObj(aIndex)->ConnectCheckTime = GetTickCount();

			if(Jogando(aIndex))
			{
				// - Bau Delay
				if(gObjCustom[aIndex].Bau_Delay > 0) gObjCustom[aIndex].Bau_Delay--;
					
				// - AutoXP Inicio
				if(GS.AutoXP_Ativado == 1)
				{
					if(gObjCustom[aIndex].Vip >= GS.AutoXP_Vip)
					{
						if(gObj(aIndex)->Level < GS.Level_Maximo)
						{
							// - Exp a Cada X Segundos
							gObjCustom[aIndex].ExpDelayCount++;
							if(gObjCustom[aIndex].ExpDelayCount > GS.AutoXP_Delay)
							{
								if(gObj(aIndex)->NextExp > gObj(aIndex)->Experience)
								{
									unsigned long Exp = gObj(aIndex)->NextExp - gObj(aIndex)->Experience;
									if(Exp < 100) Exp = 100;
									Exp = ((Exp / 100) * GS.AutoXP_Porcentagem) + (1 + rand()%GS.AutoXP_Porcentagem);

									if(Exp > 0)
									{
										gObjCustom[aIndex].ExpDelayCount = 0;
										gObj(aIndex)->Experience		+= Exp;

										char AutoXPMsg[128];
										sprintf_s(AutoXPMsg, "[Auto XP] Obtido %d Exp.", Exp);
										MsgPlayer(AutoXPMsg, aIndex);

										gObjLevelUp_Hook(gObj(aIndex), Exp);
									}
								}
							}
						}
					}
				}
				// - AutoXP Fim

				// - Server Iniciante
				if(GS.Reset_SVIni_Ativado == 1)
				{
					if(gObjCustom[aIndex].Resets > GS.Reset_SVIni_MaxResets)
					{
						if(gObjCustom[aIndex].SVIni_Count == 0)
						{
							MsgCentro("[Servidor Iniciante]", aIndex);
							MsgCentro("Você excedeu o máximo de Reset's", aIndex);
							MsgCentro("Entre em outra Sala!", aIndex);
						}
						gObjCustom[aIndex].SVIni_Count++;

						if(gObjCustom[aIndex].SVIni_Count == 4) CloseClient(aIndex);
					}
				}
				// - Server Iniciante Fim
			}
		}
	}
}

CRITICAL_SECTION			m_CriticalSectionGS;
#define	ModoLicenciado		false

void IniciarDLL()
{
	if(ModoLicenciado)
	{
		if(!Procurar(GetCommandLine(), "282ea683f79392f56b663c7ea4f26cb4", true))
		{
			MessageBox(0, "Inicie o GameServer pelo Iniciar.exe", "Ocorreu um erro!", 0);
			ExitProcess(0);
		}
	}

	InitializeCriticalSection(&m_CriticalSectionGS);

	_mkdir("Log");
	_mkdir("Kundun_Event_Log");
	_mkdir("Kundun_Event_GM_Log");

	GS.Cnn_Liberado = false;

	Fixes();
	Fixes_TNotice();

	Ler_GSC();
	SetGSConfig();

	GS.Experiencia[0]=0;
	int LevelOver_N=1;

	for(int n=1; n<401; n++)
	{
		GS.Experiencia[n] = (((n+9)*n)*n)*10;

		if(n > 255)
		{
			GS.Experiencia[n] += ((((LevelOver_N+9)*LevelOver_N)*LevelOver_N)*1000);
			LevelOver_N++;
		}
	}

	Hook((DWORD)(ProtocolCore_Hook), 0x004033E6);
	Hook((DWORD)(GCDiePlayerSend_Hook), 0x00401082);
	Hook((DWORD)(gObjMonsterDieGiveItem_Hook), 0x0040107D);
	Hook((DWORD)(gObjAddSearch_Hook), 0x00404570);				// - Erro de varias conexoes simultaneas
	Hook((DWORD)(JGGetCharacterInfo_Hook), 0x00401FDC);
	Hook((DWORD)(gObjCalCharacter_Hook), 0x00402B99);
	Hook((DWORD)(gObjLevelUp_Hook), 0x00403F17);
	Hook((DWORD)(gObjAttack_Hook), 0x00402919);
	Hook((DWORD)(CSPJoinIdPassRequest_Hook), 0x004022A2); // - JoinServerFix
	Hook((DWORD)(gObjDel_Hook), 0x00403689);  // - JoinServerFix

	CreateThread(0, 0, LPTHREAD_START_ROUTINE(GS_Timer), 0, 0, 0);
	CreateThread(0, 0, LPTHREAD_START_ROUTINE(JoinServer_Timer), 0, 0, 0);

	DbConnection.Connect();

	GS.Cnn_Liberado		= true;
	GS.g_iUserNumber	= 0;
}