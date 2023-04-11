#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

struct PWMSG_HEAD {
  /*<thisrel this+0x0>*/ /*|0x1|*/ unsigned char c;
  /*<thisrel this+0x1>*/ /*|0x1|*/ unsigned char sizeH;
  /*<thisrel this+0x2>*/ /*|0x1|*/ unsigned char sizeL;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char headcode;
  //void __thiscall PWMSG_HEAD::set(/*<regrel ebp+0x8>*/ /*|0x4|*/ unsigned char* lpBuf, /*<regrel ebp+0xc>*/ /*|0x1|*/ unsigned char head, /*<regrel ebp+0x10>*/ /*|0x4|*/ int size);
  //void __thiscall PWMSG_HEAD::setE(/*<regrel ebp+0x8>*/ /*|0x4|*/ unsigned char* lpBuf, /*<regrel ebp+0xc>*/ /*|0x1|*/ unsigned char head, /*<regrel ebp+0x10>*/ /*|0x4|*/ int size);
};

struct PBMSG_HEAD	// Packet - Byte Type
{
public:
	void set ( LPBYTE lpBuf, BYTE head, BYTE size)	// line : 18
	{
		lpBuf[0] = 0xC1;
		lpBuf[1] = size;
		lpBuf[2] = head;
	};	// line : 22

	void setE ( LPBYTE lpBuf, BYTE head, BYTE size)	// line : 25
	{
		lpBuf[0] = 0xC3;
		lpBuf[1] = size;
		lpBuf[2] = head;
	};	// line : 29

	BYTE c;
	BYTE size;
	BYTE headcode;
};

struct PMSG_NOTICE
{
	PBMSG_HEAD h;
	BYTE type;	// 3
	BYTE btCount;	// 4
	WORD wDelay;	// 6	
	int dwColor;	// 8
	BYTE btSpeed;	// C
	char Notice[256];	// D
};

struct PMSG_CHAOSMIX
{
	/*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
	/*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char Type;
};

struct PMSG_CHATDATA_NUMBER {
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char NumberL;
  /*<thisrel this+0x5>*/ /*|0x3c|*/ char chatmsg[60];
};

struct PMSG_LEVELUP {
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char subcode;
  /*<thisrel this+0x4>*/ /*|0x2|*/ unsigned short Level;
  /*<thisrel this+0x6>*/ /*|0x2|*/ unsigned short LevelUpPoint;
  /*<thisrel this+0x8>*/ /*|0x2|*/ unsigned short MaxLife;
  /*<thisrel this+0xa>*/ /*|0x2|*/ unsigned short MaxMana;
  /*<thisrel this+0xc>*/ /*|0x2|*/ unsigned short MaxBP;
  /*<thisrel this+0xe>*/ /*|0x2|*/ short AddPoint;
  /*<thisrel this+0x10>*/ /*|0x2|*/ short MaxAddPoint;
};

struct PMSG_LVPOINTADD {
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char subcode;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char Type;
};

struct PMSG_LVPOINTADDRESULT
{
	/*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char subcode;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char ResultType;
  /*<thisrel this+0x6>*/ /*|0x2|*/ unsigned short MaxLifeAndMana;
  /*<thisrel this+0x8>*/ /*|0x2|*/ unsigned short MaxBP;
};

struct PMSG_DEFAULT2 {
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char subcode;
};

struct SDHP_DBCHAR_INFORESULT {
  /*<thisrel this+0x0>*/ /*|0x4|*/ struct PWMSG_HEAD h;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char result;
  /*<thisrel this+0x6>*/ /*|0x2|*/ short Number;
  /*<thisrel this+0x8>*/ /*|0xa|*/ char AccountID[10];
  /*<thisrel this+0x12>*/ /*|0xb|*/ char Name[11];
  /*<thisrel this+0x1d>*/ /*|0x1|*/ unsigned char Class;
  /*<thisrel this+0x1e>*/ /*|0x2|*/ short Level;
  /*<thisrel this+0x20>*/ /*|0x4|*/ int LevelUpPoint;
  /*<thisrel this+0x24>*/ /*|0x4|*/ int Exp;
  /*<thisrel this+0x28>*/ /*|0x4|*/ int NextExp;
  /*<thisrel this+0x2c>*/ /*|0x4|*/ int Money;
  /*<thisrel this+0x30>*/ /*|0x2|*/ unsigned short Str;
  /*<thisrel this+0x32>*/ /*|0x2|*/ unsigned short Dex;
  /*<thisrel this+0x34>*/ /*|0x2|*/ unsigned short Vit;
  /*<thisrel this+0x36>*/ /*|0x2|*/ unsigned short Energy;
  /*<thisrel this+0x38>*/ /*|0x2|*/ unsigned short Life;
  /*<thisrel this+0x3a>*/ /*|0x2|*/ unsigned short MaxLife;
  /*<thisrel this+0x3c>*/ /*|0x2|*/ unsigned short Mana;
  /*<thisrel this+0x3e>*/ /*|0x2|*/ unsigned short MaxMana;
  /*<thisrel this+0x40>*/ /*|0x438|*/ unsigned char dbInventory[1080];
  /*<thisrel this+0x478>*/ /*|0xb4|*/ unsigned char dbMagicList[180];
  /*<thisrel this+0x52c>*/ /*|0x1|*/ unsigned char MapNumber;
  /*<thisrel this+0x52d>*/ /*|0x1|*/ unsigned char MapX;
  /*<thisrel this+0x52e>*/ /*|0x1|*/ unsigned char MapY;
  /*<thisrel this+0x52f>*/ /*|0x1|*/ unsigned char Dir;
  /*<thisrel this+0x530>*/ /*|0x4|*/ int PkCount;
  /*<thisrel this+0x534>*/ /*|0x4|*/ int PkLevel;
  /*<thisrel this+0x538>*/ /*|0x4|*/ int PkTime;
  /*<thisrel this+0x53c>*/ /*|0x1|*/ unsigned char CtlCode;
  /*<thisrel this+0x53d>*/ /*|0x1|*/ unsigned char DbVersion;
  /*<thisrel this+0x53e>*/ /*|0x1|*/ unsigned char AccountCtlCode;
  /*<thisrel this+0x53f>*/ /*|0x32|*/ unsigned char dbQuest[50];
  /*<thisrel this+0x572>*/ /*|0x2|*/ unsigned short Leadership;
  /*<thisrel this+0x574>*/ /*|0x2|*/ unsigned short ChatLitmitTime;
};
struct PMSG_VIEWPORTDESTROY {
  /*<thisrel this+0x0>*/ /*|0x1|*/ unsigned char NumberH;
  /*<thisrel this+0x1>*/ /*|0x1|*/ unsigned char NumberL;
};
struct PBMSG_COUNT {
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char count;
};

struct PMSG_CHARMAPJOINRESULT
{
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char subcode;
  /*<thisrel this+0x4>*/ /*|0x1|*/ unsigned char MapX;
  /*<thisrel this+0x5>*/ /*|0x1|*/ unsigned char MapY;
  /*<thisrel this+0x6>*/ /*|0x1|*/ unsigned char MapNumber;
  /*<thisrel this+0x7>*/ /*|0x1|*/ unsigned char Dir;
  /*<thisrel this+0x8>*/ /*|0x4|*/ unsigned long Exp;
  /*<thisrel this+0xc>*/ /*|0x4|*/ unsigned long NextExp;
  /*<thisrel this+0x10>*/ /*|0x2|*/ unsigned short LevelUpPoint;
  /*<thisrel this+0x12>*/ /*|0x2|*/ unsigned short Str;
  /*<thisrel this+0x14>*/ /*|0x2|*/ unsigned short Dex;
  /*<thisrel this+0x16>*/ /*|0x2|*/ unsigned short Vit;
  /*<thisrel this+0x18>*/ /*|0x2|*/ unsigned short Energy;
  /*<thisrel this+0x1a>*/ /*|0x2|*/ unsigned short Life;
  /*<thisrel this+0x1c>*/ /*|0x2|*/ unsigned short MaxLife;
  /*<thisrel this+0x1e>*/ /*|0x2|*/ unsigned short Mana;
  /*<thisrel this+0x20>*/ /*|0x2|*/ unsigned short MaxMana;
  /*<thisrel this+0x22>*/ /*|0x2|*/ unsigned short BP;
  /*<thisrel this+0x24>*/ /*|0x2|*/ unsigned short MaxBP;
  /*<thisrel this+0x28>*/ /*|0x4|*/ int Money;
  /*<thisrel this+0x2c>*/ /*|0x1|*/ unsigned char PkLevel;
  /*<thisrel this+0x2d>*/ /*|0x1|*/ unsigned char CtlCode;
  /*<thisrel this+0x2e>*/ /*|0x2|*/ short AddPoint;
  /*<thisrel this+0x30>*/ /*|0x2|*/ short MaxAddPoint;
  /*<thisrel this+0x32>*/ /*|0x2|*/ unsigned short Leadership;
};
#endif

