#pragma once
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_DEPRECATE

#include <Windows.h>
#include <WinDef.h>
#include <Iostream>
#include <Time.h>
#include <Conio.h>
#include <Stdio.h>
#include <Tchar.h>
#include <Math.h>
#include <Time.h>
#include <Stdlib.h>
#include <String.h>
#include <fstream>
#include <direct.h>

void GS_Timer();
void IniciarDLL();

// - Mssql
#include "SQLAPI.h"
#include "Mssql_Defs.h"
#include "Mssql_Queryes.h"

// - Estruturas
#include "GS.h"
#include "Usuario.h"
#include "Itens.h"
#include "Estruturas.h"

// - Básico
#include "PVP.h"
#include "WzAG.h"
#include "defines.h"
#include "ProtocolCore.h"
#include "Fixes.h"
#include "Funcoes.h"
#include "TNotice.h"
#include "Configs.h"
#include "Tokenizer.h"
#include "Npc.h"
#include "ChaosBox.h"
#include "Move.h"
#include "SistemaDrop.h"
#include "Drop_Funcs.h"
#include "gObjAddSearch.h"
#include "MapJoin.h"
#include "calcharacter.h"
#include "bonus_p_lvl.h"
#include "Attack.h"
#include "JoinServer.h"

// - ChatCore
#include "ChatCore.h"