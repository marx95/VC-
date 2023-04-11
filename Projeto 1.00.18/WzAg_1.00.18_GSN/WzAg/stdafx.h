#pragma once
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_DEPRECATE
#include <Windows.h>
#include <Iostream>
#include <Time.h>
#include <Conio.h>
#include <Stdio.h>
#include <Tchar.h>
#include <Math.h>
#include <Time.h>
#include <Stdlib.h>
#include <String.h>
#include <direct.h>

//Meus defines
#include "Funcoes.h"
#include "SQLAPI.h"
#include "Mssql_Defs.h"
#include "Mssql_Handler.h"

#include "WzAg.h"
#include "Tokenizer.h"

#include "Jogador.h"
#include "Protocol.h"
#include "Estruturas.h"
#include "DbCharResult.h"

#include "defines.h"
#include "Fixes.h"
#include "Protocolos.h"
#include "MapJoin.h"
#include "Reset.h"
#include "Comandos.h"
#include "Npc.h"
#include "Drop_Funcs.h"
#include "SistemaDrop.h"
#include "Configs.h"
#include "Efeitos.h"
#include "ChaosBox.h"
#include "Mapas.h"
#include "Eventos.h"
#include "Noticias.h"
#include "AttackFix.h"
#include "calcharacter.h"
#include "Npc_Maluco.h"
#include "Move.h"
#include "PVP.h"
#include "sistema_pontos.h"

//Visual Fix
#include "VisualFix_Offsets.h"
#include "Visual.h"

void Iniciar_DLL();