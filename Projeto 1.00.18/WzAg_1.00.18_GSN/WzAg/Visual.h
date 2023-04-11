#ifndef VISUAL_H
#define VISUAL_H

void FixCharSet(int aIndex);
DWORD GetNewWings(DWORD ItemType, LPBYTE lpBuff);

BYTE ConvertClassToSkin(BYTE Class);
BYTE ConvertWingsToSkin(DWORD ItemType);
void FixCharListClass();
void FixCharListWings();
void FixCharListFenrir();

#define GS_FUNCTION(_BASENAME, OFFSET) static p##_BASENAME _BASENAME = (p##_BASENAME)(OFFSET)
typedef void (*pgObjMakePreviewCharSet)(int aIndex);
GS_FUNCTION(gObjMakePreviewCharSet,			dwMakePreviewCharFunc);
#endif