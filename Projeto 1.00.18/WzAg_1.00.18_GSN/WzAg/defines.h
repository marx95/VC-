#define GS_BASE							0x401000
#define gObjOffset						0x660F078
#define gObjSize						0x1968
#define Obj_Jogadores_Minimo			6400
#define Obj_Jogadores_Maximo			7400
#define Obj_Monstros_Min				0
#define Obj_Monstros_Max				5800

#define CLASS_WIZARD					0x0
#define CLASS_KNIGHT					0x1
#define CLASS_ELF						0x2
#define CLASS_MAGUMSA					0x3
#define CLASS_DARKLORD					0x4

#define MAX_VIEWPORT					75

#define Obj_Vazio						-1
#define Obj_Jogador						1
#define Obj_Monstro						2
#define Obj_Npc							3

#define J_Vazio							0
#define J_Conectado						1
#define J_Logado						2
#define J_Jogando						3

// - User.h
#define gObjCloseSet					((void(*)(int aIndex, int flag))0x004D0F00)
#define gObjTeleport					((void(*)(int aIndex, int map, int x, int y)) 0x00402CA7)
#define gObjMonsterCallKill				((void(*)(int Index)) 0x004016CC)
#define gObjCalCharacter				((void(*)(int aIndex)) 0x004C2650) // - Call [0x004C2650] Jmp [0x00402B08]
#define gObjSetBP						((void(*)(int aIndex)) 0x00401C99)
//#define gObjViewportClose				((void(*)(LPOBJ lpObj)) 0x0040296E)
#define gObjClearViewport				((void(*)(LPOBJ lpObj)) 0x00405F1A)
//#define gObjViewportListCreate			((void(*)(short aIndex)) 0x00403864)
#define gObjViewportListProtocolCreate	((void(*)(LPOBJ lpObj)) 0x00405560)
//#define gObjViewportListProtocolDestroy	((void(*)(LPOBJ lpObj)) 0x00405263)
//#define gObjUserDie						((void(*)(LPOBJ lpObj, LPOBJ lpTargetObj)) 0x004063E3)
#define gObjGetStatPointState			((void(*)(int aIndex, short& AddPoint, short& MaxAddPoint, short& MinusPoint, short& MaxMinusPoint)) 0x00404917)
//#define gObjMoveGate					((int(*)(int aIndex, int gt)) 0x004FAAD0)
#define gObjMonsterCall					((int(*)(int aIndex, int MonsterType, int x, int y)) 0x00401D2A) 
#define gObjAttack						((int(*)(LPOBJ lpObj, LPOBJ lpTargetObj, class CMagicInf* lpMagic, int magicsend, unsigned char MSBFlag, int AttackDamage, BOOL bCombo)) 0x004E2850) // - call [0x004E2850] jmp[0x00405E7A]
//#define gObjGameClose					((BOOL(*)(int aIndex)) 0x004D93F0) // call[004D93F0] jmp [0x00402DAB]
#define gObjMagicAdd					((int(*)(LPOBJ lpObj, unsigned char aSkill, unsigned char Level)) 0x00405173)
//#define gObjAdd							((short(*)(unsigned int, char* ip, int aIndex)) 0x004D82B0)
//#define gObjLevelUp						((bool(*)(LPOBJ lpObj, int addexp, int iMonsterType, int iEventType)) 0x004DC440)	// call[0x004DC440] jmp[0x00405F51]
#define gObjInventoryDeleteItem			((BYTE(*)(int aIndex, int itempos)) 0x0040209F)
//#define gObjSetMonster					((BOOL(*)(int aIndex, int MonsterClass)) 0x004D6E90) // call[004D6E90] jmp[00405CA9]
#define gObjInventoryDeleteItem			((BYTE(*)(int aIndex, int itempos)) 0x0040209F)
#define gObjNextExpCal					((void(*)(LPOBJ lpObj)) 0x004DDBA0)	// call[004DDBA0] jmp[004052AE]
#define gObjSetExpPetItem				((void(*)(int aIndex, int exp)) 0x00403427)
#define gObjCalcShieldPoint				((void(*)(LPOBJ lpObj)) 0x004026E9)
#define gObjCalcMaxLifePower			((void(*)(int aIndex)) 0x00405C0E)

// - Protocol.h
#define GCStateInfoSend					((void(*)(LPOBJ lpObj, unsigned char state, int ViewSkillState)) 0x00404296)
#define GCLevelUpMsgSend				((void(*)(int aIndex, int iSendEffect)) 0x004348E0)
#define GCMoneySend						((void(*)(int aIndex, unsigned long money)) 0x004355B0)
#define GCServerMsgStringSend			((void(*)(char* szMsg, int aIndex, BYTE type)) 0x004060FA)
#define GCPkLevelSend					((void(*)(int aIndex, unsigned char pklevel)) 0x00405056)
#define GCInventoryItemDeleteSend		((void(*)(int aIndex, BYTE pos, unsigned char flag)) 0x004036F2)
#define GCReFillSend					((void(*)(int aIndex, WORD Life, BYTE Ipos, unsigned char flag,  WORD wShield)) 0x00404994)
#define GCManaSend						((void(*)(int aIndex, short Mana, BYTE Ipos, unsigned char flag, WORD BP))	0x004029B4)
//#define GCDamageSend					((void(*)(int aIndex, int TargetIndex, int AttackDamage, int MSBFlag, int MSBDamage, int iShieldDamage)) 0x0040383C)
//#define CGLevelUpPointAdd				((void(*)(PMSG_LVPOINTADD* lpMsg, int aIndex)) 0x00403d32) 
#define GCMagicListOneSend				((void(*)(int aIndex, char Pos, unsigned char type, unsigned char level, unsigned char skill, BYTE btListType)) 0x00402617)
#define GCDiePlayerSend					((void(*)(LPOBJ lpObj, int TargetIndex, BYTE skill, int KillerIndex)) 0x0044A600) // call[0044A600] jmp [0x004010C8]
#define GCItemListSend					((void(*)(int aIndex)) 0x004042E1)
#define GCMagicListMultiSend			((void(*)(LPOBJ lpObj, BYTE btListType)) 0x0040406B)
#define CGRequestQuestInfo				((void(*)(int aIndex)) 0x0040530D)
//#define CGChaosBoxItemMixButtonClick	((void(*)(PMSG_CHAOSMIX* aRecv, int aIndex)) 0x004484F0) // call[0x004484F0] jmp[0x00405BEB]
#define GCUserChaosBoxSend				((void(*)(LPOBJ lpObj, int iChaosBoxType)) 0x004050AB)
#define PChatProc						((void(*)(PMSG_CHATDATA* lpChat, short aIndex)) 0x0040119A)
//#define	CGCloseWindow					((void(*)(int aIndex)) 0x00404BD8)
//#define	CGSetQuestState					((void(*)(PMSG_SETQUEST* lpMsg, int aIndex)) 0x00452A10) // call [0x00452A10] jmp[004032D3]
//#define GCSendQuestPrize				((void(*)(int aIndex, unsigned char Type, unsigned char Count)) 0x00402D7E)
#define GCServerCmd						((void(*)(int aIndex, BYTE type, unsigned char Cmd1, unsigned char Cmd2)) 0x00401997)
//#define GCSendEffectInfo				((void(*)(int aIndex, BYTE type)) 0x00404200)
//#define GCKillPlayerExpSend				((void(*)(int aIndex, int TargetIndex, int exp, int AttackDamage, int MSBFlag)) 0x0040322E)

// - DSProtocol.cpp
#define GJSetCharacterInfo				((void(*)(LPOBJ lpObj, int aIndex, BOOL bMapServerMove)) 0x00428B70) // - call[00428B70] jmp[00403F3A]
#define JGGetCharacterInfo				((void(*)(SDHP_DBCHAR_INFORESULT* lpMsg)) 0x00428050) // - call[0x00428050] jmp[0x00402257]

// - Outros
#define ChaosBoxInit					((BOOL(*)(LPOBJ lpObj)) 0x004044E4)
#define ItemSerialCreateSend			((void(*)(int aIndex, BYTE MapNumber, BYTE x, BYTE y, int type, BYTE level, BYTE dur, BYTE Op1, BYTE Op2, BYTE Op3, int LootIndex, BYTE NewOption, BYTE SetOption)) 0x004036F7)
#define DataSend						((bool(*)(int aIndex, unsigned char* lpMsg, DWORD dwSize)) 0x0048BEF0) // - call[0x0048BEF0] jmp [0x0040533F]
#define ProtocolCore					((void(*)(BYTE protoNum, unsigned char * aRecv, int aLen, int aIndex, BOOL Encrypt, int serial)) 0x0042FCB0) // - call[0x0042FCB0] jmp[0x00403314]
#define CloseClient						((void(*)(int aIndex)) 0x0048CB60)
#define GameMonsterAllCloseAndReLoad	((void(*)()) 0x00404052)
#define pShopDataLoad					((void(*)()) 0x00402fea)
//#define CreateFrustrum					((void(*)(int x, int y, int aIndex)) 0x0040238D)
#define DGGuildMemberInfoRequest		((void(*)(int aIndex)) 0x00402F36)
#define FriendListRequest				((void(*)(int aIndex)) 0x0040484F)
#define ChatTargetSend					((void(*)(LPOBJ lpObj, char* szChat, int aIndex)) 0x00402A27)
