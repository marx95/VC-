#include "Estruturas.h"

void Notice(BYTE btType);
void Fixes_TNotice();

class TNotice
{
public:

        static void MakeNoticeMsg(void * lpNotice, unsigned char btType, char * szNoticeMsg);
        static void MakeNoticeMsgEx(void * lpNotice, unsigned char btType, LPSTR szNoticeMsg, ...);
		PMSG_NOTICE m_Notice;
};