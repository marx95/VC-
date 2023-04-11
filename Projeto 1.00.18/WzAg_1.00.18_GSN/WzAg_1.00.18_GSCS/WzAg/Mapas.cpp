#include "stdafx.h"
#define MAX_MAPS							50
#define ARRAY_SIZE							96
#define dwMapServerInfoMaxMaps				0x00585522
#define dwDisableCheckXYMapTile				0x004EC678
#define dwMapClassArraySize1				0x00534E34
#define dwMapClassArraySize2				0x00534E9F
#define dwStartLoadMapPushNew				0x00536805
#define dwStartLoadMapOffset				0x00535F4F
#define dwStartLoadMapLoop					0x005367BD
#define dwStartLoadMapLoopMax				0x005367D2
#define dwStartLoadMapNameArraySize1		0x005367F2
#define dwStartLoadMapNameArraySize2		0x005367F3
#define dwCheckAttackAreaMaxMap1			0x00515084
#define dwCheckAttackAreaMaxMap2			0x005150AE
#define dwObjSetStateMaxMapLoop				0x005080CA
#define dwCheckTeleportAreaMaxMap			0x00514CF9
#define dwMaxMapNumberCheck					0x004A0902
#define dwObjSetCharacterMaxMap				0x004E5ADA
#define dwItemGetRequestMaxMap				0x0043899B
#define dwItemSerialCreateRecvMaxMap		0x0042BEBC
#define dwMapServerManagerCheckMove			0x00585DE9

static char MapName[MAX_MAPS][ARRAY_SIZE] =
{
		"..\\MarxD\\Mapas\\Lorencia.att",			// Lorencia
		"..\\MarxD\\Mapas\\Dungeon.att",			// Dungeon
		"..\\MarxD\\Mapas\\Devias.att",			// Devias
		"..\\MarxD\\Mapas\\Noria.att",			// Noria
		"..\\MarxD\\Mapas\\LostTower.att",		// LostTower
		"..\\MarxD\\Mapas\\Exile.att",			// Exile
		"..\\MarxD\\Mapas\\Stadium.att",			// Stadium
		"..\\MarxD\\Mapas\\Atlans.att",			// Atlans
		"..\\MarxD\\Mapas\\Tarkan.att",			// Tarkan
		"..\\MarxD\\Mapas\\DevilSquare.att",		// DevilSquare 1 ~ 4
		"..\\MarxD\\Mapas\\Icarus.att",			// Icarus
		"..\\MarxD\\Mapas\\BloodCastle.att",		// BloodCastle01
		"..\\MarxD\\Mapas\\BloodCastle.att",		// BloodCastle02
		"..\\MarxD\\Mapas\\BloodCastle.att",		// BloodCastle03
		"..\\MarxD\\Mapas\\BloodCastle.att",		// BloodCastle04
		"..\\MarxD\\Mapas\\BloodCastle.att",		// BloodCastle05
		"..\\MarxD\\Mapas\\BloodCastle.att",		// BloodCastle06
		"..\\MarxD\\Mapas\\BloodCastle.att",		// BloodCastle07
		"..\\MarxD\\Mapas\\ChaosCastle.att",		// ChaosCastle01
		"..\\MarxD\\Mapas\\ChaosCastle.att",		// ChaosCastle02
		"..\\MarxD\\Mapas\\ChaosCastle.att",		// ChaosCastle03
		"..\\MarxD\\Mapas\\ChaosCastle.att",		// ChaosCastle04
		"..\\MarxD\\Mapas\\ChaosCastle.att",		// ChaosCastle05
		"..\\MarxD\\Mapas\\ChaosCastle.att",		// ChaosCastle06
		"..\\MarxD\\Mapas\\Kalima.att",			// Kalima01
		"..\\MarxD\\Mapas\\Kalima.att",			// Kalima02
		"..\\MarxD\\Mapas\\Kalima.att",			// Kalima03
		"..\\MarxD\\Mapas\\Kalima.att",			// Kalima04
		"..\\MarxD\\Mapas\\Kalima.att",			// Kalima05
		"..\\MarxD\\Mapas\\Kalima.att",			// Kalima06
		"..\\MarxD\\Mapas\\ValleyOfLoren.att",	// Valley Of Loren
		"..\\MarxD\\Mapas\\LandOfTrials.att",		// Land Of Trials
		"..\\MarxD\\Mapas\\DevilSquare.att",		// DevilSquare 5
		"..\\MarxD\\Mapas\\Aida.att",				// Aida
		"..\\MarxD\\Mapas\\Crywolf.att",			// Crywolf
		"..\\MarxD\\Mapas\\Null.att",				// Null
		"..\\MarxD\\Mapas\\Kalima.att",			// Kalima07
		"..\\MarxD\\Mapas\\Kantru1.att",			// Kantru01
		"..\\MarxD\\Mapas\\Kantru2.att",			// Kantru02
		"..\\MarxD\\Mapas\\Kantru3.att",			// Kantru03
		"..\\MarxD\\Mapas\\Silent.att",			// Silent
		"..\\MarxD\\Mapas\\T42.att",				// T42
		"..\\MarxD\\Mapas\\T43.att",				// T43
		"..\\MarxD\\Mapas\\Null.att",				// Null
		"..\\MarxD\\Mapas\\Null.att",				// Null
		"..\\MarxD\\Mapas\\IllusionTemple.att",	// IllusionTemple01
		"..\\MarxD\\Mapas\\IllusionTemple.att",	// IllusionTemple02
		"..\\MarxD\\Mapas\\IllusionTemple.att",	// IllusionTemple03
		"..\\MarxD\\Mapas\\IllusionTemple.att",	// IllusionTemple04
		"..\\MarxD\\Mapas\\IllusionTemple.att",	// IllusionTemple05
};

void ChangeLoadMap(){
	SetByte(dwMapServerInfoMaxMaps,			MAX_MAPS);
	SetByte(dwDisableCheckXYMapTile,		0xE9);
	SetByte(dwDisableCheckXYMapTile+1,		0x93);
	SetByte(dwDisableCheckXYMapTile+2,		0x00);
	SetNop(dwDisableCheckXYMapTile+5,		1);
	SetByte(dwMapClassArraySize1,			MAX_MAPS);
	SetByte(dwMapClassArraySize2,			MAX_MAPS);
	SetByte(dwStartLoadMapOffset,			0xE9);
	HookThis(dwStartLoadMapLoop,			dwStartLoadMapOffset);
	SetByte(dwStartLoadMapLoopMax,			MAX_MAPS);
	SetByte(dwStartLoadMapNameArraySize1,	ARRAY_SIZE);
	SetByte(dwStartLoadMapNameArraySize2,	0x81);
	SetByte(dwStartLoadMapNameArraySize2+1, 0xC1);
	SetDWord(dwStartLoadMapNameArraySize2+2,GET_ADDR(MapName));
	SetByte(dwStartLoadMapNameArraySize2+6, 0x00);
	SetNop(dwStartLoadMapNameArraySize2+6,	12);
	SetByte(dwCheckAttackAreaMaxMap1,		MAX_MAPS);
	SetByte(dwCheckAttackAreaMaxMap2,		MAX_MAPS);
	SetByte(dwObjSetStateMaxMapLoop,		MAX_MAPS-1);
	SetByte(dwCheckTeleportAreaMaxMap,		MAX_MAPS);
	SetByte(dwMaxMapNumberCheck,			MAX_MAPS);
	SetByte(dwObjSetCharacterMaxMap,		MAX_MAPS);
	SetByte(dwItemGetRequestMaxMap,			MAX_MAPS);
	SetByte(dwItemSerialCreateRecvMaxMap,	MAX_MAPS);
	SetByte(dwMapServerInfoMaxMaps,			MAX_MAPS);
	SetByte(dwStartLoadMapPushNew,			0x51);
	SetByte(dwMapServerManagerCheckMove,	0xEB);
}