#include "stdafx.h"

struct SDHP_DBCHAR_INFORESULT
{
        PWMSG_HEAD h;
        unsigned char result;   // 4
        short Number;   // 6
        char AccountID[10];     // 8
        char Name[11];  // 12
        BYTE Class;     // 1D
        short Level;    // 1E
        int LevelUpPoint;       // 20
        int Exp;        // 24
        int NextExp;    // 28
        int Money;      // 2C
        short Str;      // 30
        short Dex;      // 32
        short Vit;      // 34
        short Energy;   // 36
        WORD Life;      // 38
        WORD MaxLife;   // 3A
        WORD Mana;      // 3C
        WORD MaxMana;   // 3E
        BYTE dbInventory[1728]; // 40
        BYTE dbMagicList[180];  // 700
        BYTE MapNumber; // 7B4
        BYTE MapX;      // 7B5
        BYTE MapY;      // 7B6
        BYTE Dir;       // 7B7
        int PkCount;    // 7B8
        int PkLevel;    // 7BC
        int PkTime;     // 7C0
        BYTE CtlCode;   // 7C4
        BYTE DbVersion; // 7C5
        BYTE AccountCtlCode;    // 7C6
        BYTE dbQuest[50];       // 7C7
        WORD Leadership;        // 7FA
        WORD ChatLitmitTime;    // 7FC
        int iFruitPoint;        // 800
};

struct PMSG_CHARMAPJOINRESULT
{
	PBMSG_HEAD h;	// C3:F3:03
	BYTE subcode;	// 3
	BYTE MapX;	// 4
	BYTE MapY;	// 5
	BYTE MapNumber;	// 6
	BYTE Dir;	// 7
	DWORD Exp;	// 8
	DWORD NextExp;	// C
	WORD LevelUpPoint;	// 10
	WORD Str;	// 12
	WORD Dex;	// 14
	WORD Vit;	// 16
	WORD Energy;	// 18
	WORD Life;	// 1A
	WORD MaxLife;	// 1C
	WORD Mana;	// 1E
	WORD MaxMana;	// 20
	WORD wShield;	// 22
	WORD wMaxShield;	// 24
	WORD BP;	// 26
	WORD MaxBP;	// 28
	int Money;	// 2C
	BYTE PkLevel;	// 30
	BYTE CtlCode;	// 31
	short AddPoint;	// 32
	short MaxAddPoint;	// 34
	WORD Leadership;	// 36
	WORD wMinusPoint;	// 38
	WORD wMaxMinusPoint;	// 3A
};