#include "stdafx.h"
#define MAX_MAPS							50
#define ARRAY_SIZE							96
#define dwMapServerInfoMaxMaps				0x0054E442
#define dwDisableCheckXYMapTile				0x004DA678
#define dwMapClassArraySize1				0x00520204
#define dwMapClassArraySize2				0x0052026F
#define dwStartLoadMapPushNew				0x00521B77
#define dwStartLoadMapOffset				0x005212C1
#define dwStartLoadMapLoop					0x00521B2F
#define dwStartLoadMapLoopMax				0x00521B44
#define dwStartLoadMapNameArraySize1		0x00521B64
#define dwStartLoadMapNameArraySize2		0x00521B65
#define dwCheckAttackAreaMaxMap1			0x00501594
#define dwCheckAttackAreaMaxMap2			0x005015BE
#define dwObjSetStateMaxMapLoop				0x004F507F
#define dwCheckTeleportAreaMaxMap			0x00501209
#define dwMaxMapNumberCheck					0x0048F732
#define dwObjSetCharacterMaxMap				0x004D3C5A
#define dwItemGetRequestMaxMap				0x0043595B
#define dwItemSerialCreateRecvMaxMap		0x0042A4DC
#define dwMapServerManagerCheckMove			0x0054ED09

static char MapName[MAX_MAPS][ARRAY_SIZE] =
{
		"..\\Data\\Mapas\\Lorencia.att",			// Lorencia
		"..\\Data\\Mapas\\Dungeon.att",			// Dungeon
		"..\\Data\\Mapas\\Devias.att",				// Devias
		"..\\Data\\Mapas\\Noria.att",				// Noria
		"..\\Data\\Mapas\\LostTower.att",			// LostTower
		"..\\Data\\Mapas\\Exile.att",				// Exile
		"..\\Data\\Mapas\\Stadium.att",			// Stadium
		"..\\Data\\Mapas\\Atlans.att",				// Atlans
		"..\\Data\\Mapas\\Tarkan.att",				// Tarkan
		"..\\Data\\Mapas\\DevilSquare.att",		// DevilSquare 1 ~ 4
		"..\\Data\\Mapas\\Icarus.att",				// Icarus
		"..\\Data\\Mapas\\BloodCastle.att",		// BloodCastle01
		"..\\Data\\Mapas\\BloodCastle.att",		// BloodCastle02
		"..\\Data\\Mapas\\BloodCastle.att",		// BloodCastle03
		"..\\Data\\Mapas\\BloodCastle.att",		// BloodCastle04
		"..\\Data\\Mapas\\BloodCastle.att",		// BloodCastle05
		"..\\Data\\Mapas\\BloodCastle.att",		// BloodCastle06
		"..\\Data\\Mapas\\BloodCastle.att",		// BloodCastle07
		"..\\Data\\Mapas\\ChaosCastle.att",		// ChaosCastle01
		"..\\Data\\Mapas\\ChaosCastle.att",		// ChaosCastle02
		"..\\Data\\Mapas\\ChaosCastle.att",		// ChaosCastle03
		"..\\Data\\Mapas\\ChaosCastle.att",		// ChaosCastle04
		"..\\Data\\Mapas\\ChaosCastle.att",		// ChaosCastle05
		"..\\Data\\Mapas\\ChaosCastle.att",		// ChaosCastle06
		"..\\Data\\Mapas\\Kalima.att",				// Kalima01
		"..\\Data\\Mapas\\Kalima.att",				// Kalima02
		"..\\Data\\Mapas\\Kalima.att",				// Kalima03
		"..\\Data\\Mapas\\Kalima.att",				// Kalima04
		"..\\Data\\Mapas\\Kalima.att",				// Kalima05
		"..\\Data\\Mapas\\Kalima.att",				// Kalima06
		"..\\Data\\Mapas\\ValleyOfLoren.att",		// Valley Of Loren
		"..\\Data\\Mapas\\LandOfTrials.att",		// Land Of Trials
		"..\\Data\\Mapas\\DevilSquare.att",		// DevilSquare 5
		"..\\Data\\Mapas\\Aida.att",				// Aida
		"..\\Data\\Mapas\\Crywolf.att",			// Crywolf
		"..\\Data\\Mapas\\Null.att",				// Null
		"..\\Data\\Mapas\\Kalima.att",				// Kalima07
		"..\\Data\\Mapas\\Kantru1.att",			// Kantru01
		"..\\Data\\Mapas\\Kantru2.att",			// Kantru02
		"..\\Data\\Mapas\\Kantru3.att",			// Kantru03
		"..\\Data\\Mapas\\Silent.att",				// Silent
		"..\\Data\\Mapas\\T42.att",				// T42
		"..\\Data\\Mapas\\T43.att",				// T43
		"..\\Data\\Mapas\\Null.att",				// Null
		"..\\Data\\Mapas\\Null.att",				// Null
		"..\\Data\\Mapas\\IllusionTemple.att",		// IllusionTemple01
		"..\\Data\\Mapas\\IllusionTemple.att",		// IllusionTemple02
		"..\\Data\\Mapas\\IllusionTemple.att",		// IllusionTemple03
		"..\\Data\\Mapas\\IllusionTemple.att",		// IllusionTemple04
		"..\\Data\\Mapas\\IllusionTemple.att",		// IllusionTemple05
};

void MudarLoadMap(){
	SetByte(dwMapServerInfoMaxMaps,			MAX_MAPS);
	SetByte(dwDisableCheckXYMapTile,		0xE9);
	SetByte(dwDisableCheckXYMapTile+1,		0x93);
	SetByte(dwDisableCheckXYMapTile+2,		0x00);
	SetNop(dwDisableCheckXYMapTile+5,		1);
	SetByte(dwMapClassArraySize1,			MAX_MAPS);
	SetByte(dwMapClassArraySize2,			MAX_MAPS);
	SetByte(dwStartLoadMapOffset,			0xE9);
	Hook(dwStartLoadMapLoop,			dwStartLoadMapOffset);
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