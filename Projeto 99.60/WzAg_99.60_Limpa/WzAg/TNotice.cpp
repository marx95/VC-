#include "stdAfx.h"

void TNotice::MakeNoticeMsg(void * lpNotice, unsigned char btType, char * szNoticeMsg)
{
	PMSG_NOTICE * pNotice = (PMSG_NOTICE *)lpNotice;
	pNotice->type  = btType;
	wsprintf(pNotice->Notice, szNoticeMsg);
	//sprintf_s(pNotice->Notice, "%s", szNoticeMsg);
	PHeadSetB((LPBYTE)pNotice, 0x0D, strlen(pNotice->Notice) + sizeof(PMSG_NOTICE) - sizeof(pNotice->Notice) + 1 );
}

void TNotice::MakeNoticeMsgEx(void * lpNotice, unsigned char btType, char * szNoticeMsg, ...)
{
	PMSG_NOTICE * pNotice = (PMSG_NOTICE *)lpNotice;
	pNotice->type = btType;

	va_list pArguments;
	va_start(pArguments, szNoticeMsg);
	vsprintf((char*)pNotice->Notice, (char*)szNoticeMsg, pArguments);
	va_end(pArguments);

	PHeadSetB((LPBYTE)pNotice, 0x0D, strlen(pNotice->Notice)  + sizeof(PMSG_NOTICE) - sizeof(pNotice->Notice) + 1);
}
/*
void TNotice::SetNoticeProperty(void * lpNotice, BYTE btType, DWORD dwColor, BYTE btCount, WORD wDelay, BYTE btSpeed)
{
        PMSG_NOTICE * pNotice =(PMSG_NOTICE *) lpNotice;

        pNotice->type = btType;
        pNotice->dwColor = dwColor;
        pNotice->btCount = btCount;
        pNotice->wDelay = wDelay;
        pNotice->btSpeed = btSpeed;
}

TNotice::TNotice(BYTE btType)
{
        this->m_Notice.btCount = 1;
        this->m_Notice.btSpeed = 20;
        this->m_Notice.dwColor = _ARGB(255, 255, 200, 80 );
        this->m_Notice.wDelay = 0;
        this->m_Notice.type = btType;
}*/