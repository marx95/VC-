#include "stdafx.h"

void Fixes_TNotice()
{
	Hook((DWORD)(TNotice::MakeNoticeMsg), 0x00402194);
	Hook((DWORD)(TNotice::MakeNoticeMsgEx), 0x00401C12);
}	