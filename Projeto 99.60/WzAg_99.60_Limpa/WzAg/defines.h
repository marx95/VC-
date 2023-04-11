#define	GS_BASE							0x00401000
#define Object_Base						0x653DBF8
#define Object_Size						0x1570
#define Obj_Jogadores_Minimo			6400
#define Obj_Jogadores_Maximo			7400
#define MAX_VIEWPORT					75

#define Obj_Vazio						-1
#define Obj_Jogador						1
#define Obj_Monstro						2
#define Obj_Npc							3

#define J_Vazio							0
#define J_Conectado						1
#define J_Logado						2
#define J_Jogando						3

#define DW								0
#define DK								1
#define Elf								2
#define MG								3
#define DL								4

// - gObj - user.h
#define gObjDel							((short(*)(int aIndex)) 0x004BA570)  // - JMP 0x00403689 CALL 0x004BA570
//#define gObjCloseSet					((void(*)(int aIndex, int Flag)) 0x00401681)
#define gObjTeleport					((void(*)(int aIndex, int map, int x, int y)) 0x00402DE7)
#define gObjCalCharacter				((void(*)(int aIndex)) 0x004A4740) // - JMP 00402B99
#define gObjSetBP						((void(*)(int aIndex)) 0x004018DE)
#define gObjCalcMaxLifePower			((void(*)(int aIndex)) 0x00402667)
//#define gObjGameClose					((int(*)(int aIndex)) 0x004BA020) // - JMP 0x00402F77 CALL 0x004BA020
#define gObjClearViewport				((void(*)(struct OBJECTSTRUCT* lpObj)) 0x004029F5)
#define gObjViewportListProtocolCreate	((void(*)(struct OBJECTSTRUCT* lpObj)) 0x00401D3E)
#define gObjGetStatPointState			((void(*)(int aIndex, short& AddPoint, short& MaxAddPoint)) 0x004040C5)
#define gObjAttack						((int(*)(struct OBJECTSTRUCT* lpObj, struct OBJECTSTRUCT* lpTargetObj, class CMagicInf* lpMagic, int magicsend, unsigned char MSBFlag, int AttackDamage, int bCombo)) 0x004C2960) // JMP call 004C2960
#define gObjSetExpPetItem				((void(*)(int aIndex, int exp)) 0x0040349A)
#define gObjNextExpCal					((void(*)(struct OBJECTSTRUCT* lpObj)) 0x00404A11)
#define gObjMagicAdd					((int(*)(struct OBJECTSTRUCT* lpObj, unsigned char aSkill, unsigned char Level)) 0x0040492B)
#define GCMagicListOneSend				((void(*)(int aIndex, char Pos, unsigned char type, unsigned char level, unsigned char skill, unsigned char btListType)) 0x0040245F)
//#define gObjMonsterDieGiveItem			((void(*)(struct OBJECTSTRUCT* lpObj, struct OBJECTSTRUCT* lpTargetObj)) 0x00417220) // Call 00417220 jmp 0x004046CE
#define gObjInventoryDeleteItem			((void(*)(int aIndex, int ItemPos)) 0x00401D39)

// - GC - protocol.h
#define GCServerMsgStringSend			((void(*)(char* szMsg, int aIndex, unsigned char type)) 0x00402C84)
//#define GCStateInfoSend					((void(*)(struct OBJECTSTRUCT* lpObj, unsigned char state, int ViewSkillState)) 0x00403E9A)
#define GCMoneySend						((void(*)(int aIndex, unsigned long money)) 0x00403D7D)
#define GCPkLevelSend					((void(*)(int aIndex, unsigned char pklevel)) 0x00404859)
#define GCServerCmd						((void(*)(int aIndex, unsigned char type, unsigned char Cmd1, unsigned char Cmd2)) 0x004016B3)
#define GCReFillSend					((void(*)(int aIndex, unsigned short Life, unsigned char Ipos, unsigned char flag)) 0x00404313)
#define GCManaSend						((void(*)(int aIndex, short Mana, unsigned char Ipos, unsigned char flag,  unsigned short BP))	0x0040299B)
#define GCUserChaosBoxSend				((void(*)(struct OBJECTSTRUCT* lpObj, int iChaosBoxType)) 0x0040489A)
#define GCDiePlayerSend					((void(*)(struct OBJECTSTRUCT* lpObj, int TargetIndex, unsigned char skill, int KillerIndex)) 0x0043EA00) // - JMP 0x00401082 -- CALL 0x0043EA00
#define GCSendEffectInfo				((void(*)(int aIndex, unsigned char Effect)) 0x00403E31)
//#define GCJoinSocketResult				((void(*)(unsigned char result, unsigned int Socket)) 0x00401339)
#define GCMagicListMultiSend			((void(*)(struct OBJECTSTRUCT* lpObj, unsigned char btListType)) 0x00403D2D)
#define GCItemListSend					((void(*)(int aIndex)) 0x00403ECC)
#define CGRequestQuestInfo				((void(*)(int aIndex)) 0x00404A57)
#define GCJoinResult					((void(*)(unsigned char result, int aIndex)) 0x00401564)
#define GCInventoryItemDeleteSend		((void(*)(int aIndex, unsigned char pos, unsigned char flag)) 0x00403693)

// - GJ GC - DSProtocol.h
#define GJSetCharacterInfo				((void(*)(struct OBJECTSTRUCT* lpObj, int aIndex)) 0x00401E92)

// - DG - EDSProtocol.h
#define DGGuildMemberInfoRequest		((void(*)(int aIndex)) 0x00403148)
#define FriendListRequest				((void(*)(int aIndex)) 0x0040429B)

// - Testados OK
#define ItemSerialCreateSend			((void(*)(int aIndex, unsigned char MapNumber, unsigned char x, unsigned char y, int type, unsigned char level, unsigned char dur, unsigned char Op1, unsigned char Op2, unsigned char Op3, int LootIndex, unsigned char NewOption, unsigned char SetOption)) 0x00403698)
#define GameMonsterAllCloseAndReLoad	((void(*)()) 0x00403D1E)
#define pShopDataLoad					((int(*)()) 0x004031DE)
#define ChaosBoxInit					((int(*)(struct OBJECTSTRUCT* lpObj)) 0x0040402F)
#define DataSend						((int(*)(int aIndex, unsigned char* lpMsg, unsigned long dwSize)) 0x00401A7D) // JMP 00401A7D - Call 0x00474F40
#define ProtocolCore					((void(*)(unsigned char protoNum, unsigned char * aRecv, int aLen, int aIndex, int Encrypt, int serial)) 0x00426D40) // - JMP 0x004033E6 -- CALL 0x00426D40
#define CloseClient						((void(*)(int aIndex)) 0x00401032)
//#define IsIP							((int(*)(char* ip)) 0x00403576)
#define JGGetCharacterInfo				((void(*)(struct SDHP_DBCHAR_INFORESULT* lpMsg)) 0x0041FC90) // JMP 0x00401FDC - Call 0x0041FC90
#define NpcShadowPhantom				((int(*)(struct OBJECTSTRUCT* lpNpc, struct OBJECTSTRUCT* lpObj)) 0x0040237E)
//#define MsgSendV2						((void(*)(struct OBJECTSTRUCT* lpObj, unsigned char* Msg, int size)) 0x00401DF2) 
//#define QuestInfoSave					((void(*)(struct OBJECTSTRUCT* lpObj)) 0x0040315C)
#define DataServerGetCharListRequest	((void(*)(short aIndex)) 0x00403C06)
#define GDGetWarehouseList				((void(*)(int aIndex, char* AccountID)) 0x0040302B)


#define KundunEventItemBoxOpen			((void(*)(struct OBJECTSTRUCT* lpObj, unsigned char btMapNumber, unsigned char cX, unsigned char cY)) 0x00401B04)