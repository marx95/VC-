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

#define LoadModel					((void(*)(int ModelID, char * Folder, char * Name, int ModelType)) 0x0062B633)
#define LoadTexture					((void(*)(int TextureID, char * Folder, int GLREPEAT, int GLNEAREST, int GLTRUE)) 0x0062B1B7)
#define ITEMGET(x,y)				((x * 512) + y)

void Config();
void Iniciar_Anti_Hack();
void Fix();