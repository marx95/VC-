#pragma once
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_DEPRECATE
#include <Windows.h>
#include <Iostream>
#include <Time.h>
#include <Stdio.h>
#include <String.h>
#include <ShellApi.h>
#include <direct.h>

#pragma comment(lib, "user32.lib")
#pragma warning (disable : 4311 )
#pragma warning (disable : 4800 )

#include "CRC.h"
#include "AntiHack.h"
#include "Funcs.h"

void Config();
void Iniciar_Anti_Hack();
void Fix();

#define LoadItem					((void(*)(WORD,char*,char*,WORD)) 0x005E10E0)
#define LoadTexture					((void(*)(WORD,char*,int,int,int)) 0x005E0CA0)