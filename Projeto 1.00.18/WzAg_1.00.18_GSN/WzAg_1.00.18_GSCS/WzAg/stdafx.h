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
#include "WzAg.h"
#include "Tokenizer.h"
#include "DefConfig.h"
#include "Jogador.h"
#include "Funcoes.h"
#include "defines.h"
#include "Fixes.h"
#include "Protocolos.h"
#include "Mssql_Defs.h"
#include "Mssql_Handler.h"
#include "Comandos.h"
#include "Npc.h"
#include "Configs.h"
#include "Mapas.h"
#include "AttackFix.h"
#include "CalCharacter.h"

//Visual Fix
#include "VisualFix_Offsets.h"
#include "Visual.h"

void Iniciar_DLL();