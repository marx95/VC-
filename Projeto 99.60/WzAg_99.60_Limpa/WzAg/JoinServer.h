#include "stdafx.h"

struct PMSG_IDPASS
{
  struct PBMSG_HEAD h;
  unsigned char subcode;
  char Id[10];
  char Pass[10];
  unsigned long TickCount;
  unsigned char CliVersion[5];
  unsigned char CliSerial[16];
};

struct SDHP_IDPASSRESULT
{
  /*<thisrel this+0x0>*/ /*|0x3|*/ struct PBMSG_HEAD h;
  /*<thisrel this+0x3>*/ /*|0x1|*/ unsigned char result;
  /*<thisrel this+0x4>*/ /*|0x2|*/ short Number;
  /*<thisrel this+0x6>*/ /*|0xa|*/ char Id[10];
  /*<thisrel this+0x10>*/ /*|0x4|*/ int UserNumber;
  /*<thisrel this+0x14>*/ /*|0x4|*/ int DBNumber;
  /*<thisrel this+0x18>*/ /*|0xd|*/ char JoominNumber[13];
};

short gObjDel_Hook(int aIndex);
void CSPJoinIdPassRequest_Hook(PMSG_IDPASS* lpMsg, int aIndex);