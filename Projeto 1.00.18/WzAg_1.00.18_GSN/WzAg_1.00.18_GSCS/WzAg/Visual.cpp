#include "StdAfx.h"

BYTE ConvertClassToSkin(BYTE Class) {
	switch (Class) {
		case 2:	 return 0x18; break;	//DW
		case 18: return 0x38; break;	//DK
		case 34: return 0x58; break;	//ELF
		case 49: 
		case 50: return 0x78; break;	//MG
		case 65: 
		case 66: return 0x98; break;	//DL
	}
	return (((Class>>4)<<5)&0xE0|((Class&0x0F)<<4)&0x10);
}

BYTE ConvertWingsToSkin(DWORD ItemType) {
	switch (ItemType) {
		case 0x1824: return 0x04; break;	/// DK
		case 0x1825: return 0x08; break;	/// DW
		case 0x1826: return 0x0c; break;	/// ELF
		case 0x1827: return 0x10; break;	/// MG
		case 0x1828: return 0x14; break;	/// DL
		default :    return 0xFF; break;
	}
}

DWORD GetNewWings(DWORD ItemType, LPBYTE lpBuff) {
	if (ItemType >= 0x1824 && ItemType <= 0x1828) {
		lpBuff[0] = ConvertWingsToSkin(ItemType);
	}
	return ItemType;
}

void FixCharSet(int aIndex) {
	gObjMakePreviewCharSet(aIndex);
	gObj(aIndex)->CharSet[0] = ConvertClassToSkin(gObj(aIndex)->DbClass);

	if ((gObj(aIndex)->pInventory[7].m_Type != -1) && (gObj(aIndex)->pInventory[7].m_Type >= 0x1824 && gObj(aIndex)->pInventory[7].m_Type <= 0x1828)) {
		gObj(aIndex)->CharSet[16] = ConvertWingsToSkin(gObj(aIndex)->pInventory[7].m_Type);
	}
	if ((gObj(aIndex)->pInventory[8].m_Type != -1) && (gObj(aIndex)->pInventory[8].m_Type == 0x1A25)) {
		gObj(aIndex)->CharSet[17] = ((gObj(aIndex)->pInventory[8].m_NewOption == 4)?0x03:gObj(aIndex)->CharSet[17]);
	}
}

ASM_FUNC(FixCharListClass) {
	__asm {
		push ecx
		call ConvertClassToSkin
		add esp, 4
		mov dl, al
		jmp dwFixCharListClassReturn
	}
}

ASM_FUNC(FixCharListWings) {
	__asm {
		Lea  Ecx, dword ptr ss:[ebp-0x131]
		Push Ecx
		Push Edx	// ItemIndex
		Call GetNewWings
		And  Edx, 0x800001FF
		Jmp  dwFixCharListWingsReturn
	}
}

ASM_FUNC(FixCharListFenrir) {
	__asm {
		mov byte ptr ss:[ebp-0x188], cl
		cmp cl, 0x04;
		jnz __Skip;
		mov byte ptr ss:[ebp-0x130], 0x01;
	__Skip:
		Jmp dwFixCharListFenrirReturn
	}
}
