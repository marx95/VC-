#ifndef JOGADOR_H
#define JOGADOR_H
#define GS_BASE							0x401000
#define gObjOffset						0x03D9C5F8 
#define gObjSize						0x197C
#define Obj_Jogadores_Minimo			2500
#define Obj_Jogadores_Maximo			4000
#define Obj_Monstros_Min				0
#define Obj_Monstros_Max				1500

#define OBJECT_POINTER(aIndex) ((aIndex * gObjSize) + gObjOffset)

struct ItemStruct
{
	/*0x0>	|0x4|*/ unsigned long m_Number;
	/*0x4>	|0x1|*/ char m_serial;
	/*0x6>	|0x2|*/ short m_Type;
	/*0x8>	|0x2|*/ short m_Level;
	/*0xa>	|0x1|*/ unsigned char m_Part;
	/*0xb>	|0x1|*/ unsigned char m_Class;
	/*0xc>	|0x1|*/ unsigned char m_TwoHand;
	/*0xd>	|0x1|*/ unsigned char m_AttackSpeed;
	/*0xe>	|0x1|*/ unsigned char m_WalkSpeed;
	/*0x10>	|0x2|*/ unsigned short m_DamageMin;
	/*0x12>	|0x2|*/ unsigned short m_DamageMax;
	/*0x14>	|0x1|*/ unsigned char m_SuccessfulBlocking;
	/*0x16>	|0x2|*/ unsigned short m_Defense;
	/*0x18>	|0x2|*/ unsigned short m_MagicDefense;
	/*0x1a>	|0x1|*/ unsigned char m_Speed;
	/*0x1c>	|0x2|*/ unsigned short m_DamageMinOrigin;
	/*0x1e>	|0x2|*/ unsigned short m_DefenseOrigin;
	/*0x20>	|0x2|*/ unsigned short m_Magic;
	/*0x24>	|0x4|*/ float m_Durability;
	/*0x28>	|0x2|*/ unsigned short m_DurabilitySmall;
	/*0x2c>	|0x4|*/ float m_BaseDurability;
	/*0x30>	|0x1|*/ unsigned char m_SpecialNum;
	/*0x31>	|0x8|*/ unsigned char m_Special[8];
	/*0x39>	|0x8|*/ unsigned char m_SpecialValue[8];
	/*0x42>	|0x2|*/ unsigned short m_RequireStrength;
	/*0x44>	|0x2|*/ unsigned short m_RequireDexterity;
	/*0x46>	|0x2|*/ unsigned short m_RequireEnergy;
	/*0x48>	|0x2|*/ unsigned short m_RequireLevel;
	/*0x4a>	|0x2|*/ unsigned short m_RequireVitality;
	/*0x4c>	|0x2|*/ unsigned short m_RequireLeaderShip;
	/*0x4e>	|0x2|*/ unsigned short m_Leadership;
	/*0x50>	|0x5|*/ unsigned char m_RequireClass[5];
	/*0x55>	|0x7|*/ unsigned char m_Resistance[7];
	/*0x5c>	|0x4|*/ int m_Value;
	/*0x60>	|0x4|*/ unsigned long m_SellMoney;
	/*0x64>	|0x4|*/ unsigned long m_BuyMoney;
	/*0x68>	|0x4|*/ int m_iPShopValue;
	/*0x6c>	|0x1|*/ unsigned char m_bItemExist;
	/*0x70>	|0x4|*/ int m_OldSellMoney;
	/*0x74>	|0x4|*/ int m_OldBuyMoney;
	/*0x78>	|0x1|*/ unsigned char m_Option1;
	/*0x79>	|0x1|*/ unsigned char m_Option2;
	/*0x7a>	|0x1|*/ unsigned char m_Option3;
	/*0x7b>	|0x1|*/ unsigned char m_NewOption;
	/*0x7c>	|0x10|*/float m_DurabilityState[4];
	/*0x8c>	|0x4|*/ float m_CurrentDurabilityState;
	/*0x90>	|0x1|*/ unsigned char m_SkillChange;
	/*0x91>	|0x1|*/ unsigned char m_QuestItem;
	/*0x92>	|0x1|*/ unsigned char m_SetOption;
	/*0x93>	|0x1|*/ unsigned char m_SetAddStat;
	/*0x94>	|0x1|*/ unsigned char m_IsValidItem;
	/*0x95>	|0x7|*/ unsigned char m_SkillResistance[7];
	/*0x9c>	|0x4|*/ int m_IsLoadPetItemInfo;
	/*0xa0>	|0x4|*/ int m_PetItem_Level;
	/*0xa4>	|0x4|*/ int m_PetItem_Exp;
	/*0xa8>	|0x1|*/ unsigned char m_JewelOfHarmonyOption;
	/*0xaa>	|0x2|*/ unsigned short m_HJOpStrength;
	/*0xac>	|0x2|*/ unsigned short m_HJOpDexterity;
	/*0xae>	|0x1|*/ unsigned char m_ItemOptionEx;
};

struct tagInterfaceState
{
	DWORD use   : 2;
	DWORD state : 4;
	DWORD type  : 10;
};

struct OBJECTSTRUCT 
{
	int		m_Index;
	int		Connected;
	char	LoginMsgSnd;
	char	LoginMsgCount;
	char	CloseCount;
	char	CloseType;
	int		bEnableDelCharacter;
	int		PerSocketContext;
	UINT	m_socket;
	char	Ip_addr[16];
	int		UserNumber;
	int		DBNumber;
	BYTE	Magumsa;
	DWORD	AutoSaveTime;
	DWORD	ConnectCheckTime;
	DWORD	CheckTick;
	BYTE	CheckSpeedHack;
	DWORD	CheckTick2;
	BYTE	CheckTickCount;
	DWORD	SaveTimeForStatics;
	int		iPingTime;
	BYTE	m_TimeCount;
	DWORD	m_dwPKTimer;
	short	CheckSumTableNum;
	DWORD	CheckSumTime;
	WORD	Type;
	BYTE	Live;
	char	CharacterPos;
	char	AccountID[11];
	char	Name[11];
	char	LastJoominNumber[14];
	BYTE	PlusStatQuestClear;
	BYTE	ComboSkillquestClear;
	short	m_Filler0x8e;
	char	comboSkill[0xc];
	WORD	Class;
	BYTE	DbClass;
	BYTE	ChangeUP;
	short	Level;
	int		LevelUpPoint;
	int		iFruitPoint;
	DWORD	Experience;
	DWORD	NextExp;
	int		Money;
	unsigned short Strength;
	unsigned short Dexterity;
	unsigned short Vitality;
	unsigned short Energy;
	float	Life;
	float	MaxLife;
	int		m_iScriptMaxLife;
	float	FillLife;
	float	FillLifeMax;
	float	Mana;
	float	MaxMana;
	WORD	Leadership;
	WORD	AddLeadership;
	WORD	ChatLitmitTime;
	BYTE	ChatLimitTimeSec;
	BYTE	FillLifeCount;
	unsigned short	AddStrength;
	unsigned short	AddDexterity;
	unsigned short	AddVitality;
	unsigned short	AddEnergy;
	int		BP;
	int		MaxBP;
	int		AddBP;
	float	VitalityToLife;
	float	EnergyToMana;
	char	m_PK_Count;
	char	m_PK_Level;
	int		m_PK_Time;
	short	X;
	short	Y;
	BYTE	Dir;
	BYTE	MapNumber;
	int		AddLife;
	int		AddMana;
	int		iShield;
	int		iMaxShield;
	int		iAddShield;
	int		iFillShieldMax;
	int		iFillShield;
	int		iFillShieldCount;
	DWORD	dwShieldAutoRefillTimer;
	BYTE	DamageMinus;
	BYTE	DamageReflect;
	short	MonsterDieGetMoney;
	BYTE	MonsterDieGetLife;
	BYTE	MonsterDieGetMana;
	BYTE	StartX;
	BYTE	StartY;
	short	m_OldX;
	short	m_OldY;
	short	TX;
	short	TY;
	short	MTX;
	short	MTY;
	int		PathCount;
	int		PathCur;
	char	PathStartEnd;
	short	PathOri[15];
	short	PathX[15];
	short	PathY[15];
	char	PathDir[15];
	DWORD	PathTime;
	char	m_MoveGateNumber;
	DWORD	Authority;
	DWORD	AuthorityCode;
	DWORD	Penalty;
	BYTE	m_cAccountItemBlock;
	int		m_ActState;
	BYTE	m_ActionNumber;
	DWORD	m_State;
	char	m_StateSub;
	BYTE	m_Rest;
	char	m_ViewState;
	int		m_ViewSkillState;
	DWORD	m_LastMoveTime;
	DWORD	m_LastAttackTime;
	BYTE	m_FriendServerOnline;
	int		m_DetectSpeedHackTime;
	DWORD	m_SumLastAttackTime;
	DWORD	m_DetectCount;
	int		m_DetectedHackKickCount;
	int		m_SpeedHackPenalty;
	BYTE	m_AttackSpeedHackDetectedCount;
	DWORD	m_PacketCheckTime;
	BYTE	m_ShopTime;
	DWORD	m_TotalAttackTime;
	int		m_TotalAttackCount;
	DWORD	TeleportTime;
	char	Teleport;
	char	KillerType;
	char	DieRegen;
	char	RegenOk;
	BYTE	RegenMapNumber;
	BYTE	RegenMapX;
	BYTE	RegenMapY;
	DWORD	RegenTime;
	DWORD	MaxRegenTime;
	short	m_PosNum;
	DWORD	LifeRefillTimer;
	DWORD	CurActionTime;
	DWORD	NextActionTime;
	DWORD	DelayActionTime;
	char	DelayLevel;
	char	m_PoisonType;
	char	m_IceType;
	char	m_PoisonBeattackCount;
	char	m_ColdBeattackCount;
	char	m_ImmuneToMagicCount;
	char	m_ImmuneToHarmCount;
	char	m_iMonsterBattleDelay;
	char	m_cKalimaGateExist;
	int		m_iKalimaGateIndex;
	char	m_cKalimaGateEnterCount;
	OBJECTSTRUCT* lpAttackObj;
	short	m_SkillNumber;
	DWORD	m_SkillTime;
	BYTE	m_bAttackerKilled;
	char	m_ManaFillCount;
	char	m_LifeFillCount;
	int		SelfDefense[5];
	DWORD	SelfDefenseTime[5];
	DWORD	MySelfDefenseTime;
	char	m_Drink;
	int		m_SkillDefense;
	char	m_SkillDefenseTime;
	int		m_SkillAttack;
	char	m_SkillAttackTime;
	int		m_SkillAttack2;
	char	m_SkillAttackTime2;
	int		m_SkillAddLife;
	int		m_SkillAddLifeTime;
	int		m_SkillHarden;
	int		m_SkillHardenTime;
	int		m_SkillMagumReduceDefense;
	int		m_SkillMagumReduceDefenseTime;
	int		PartyNumber;
	int		PartyTargetUser;
	int		GuildNumber;
	int		lpGuild;
	char	GuildName[11];
	int		GuildStatus;
	int		iGuildUnionTimeStamp;
	int		m_RecallMon;
	int		m_Change;
	short	TargetNumber;
	short	TargetShopNumber;
	short	ShopNumber;
	short	LastAttackerID;
	int		m_AttackDamageMin;
	int		m_AttackDamageMax;
	int		m_MagicDamageMin;
	int		m_MagicDamageMax;
	int		m_AttackDamageLeft;
	int		m_AttackDamageRight;
	int		m_AttackDamageMaxLeft;
	int		m_AttackDamageMinLeft;
	int		m_AttackDamageMaxRight;
	int		m_AttackDamageMinRight;
	int		m_AttackRating;
	int		m_AttackSpeed;
	int		m_MagicSpeed;
	int		m_Defense;
	int		m_MagicDefense;
	int		m_SuccessfulBlocking;
	short	m_MoveSpeed;
	short	m_MoveRange;
	short	m_AttackRange;
	short	m_AttackType;
	short	m_ViewRange;
	short	m_Attribute;
	short	m_ItemRate;
	short	m_MoneyRate;
	int		m_CriticalDamage;
	int		m_ExcelentDamage;
	int		m_lpMagicBack;
	int		Magic;
	char	MagicCount;
	BYTE	UseMagicNumber;
	DWORD	UseMagicTime;
	char	UseMagicCount;
	short	OSAttackSerial;
	BYTE	SASCount;
	DWORD	SkillAttackTime;
	BYTE	CharSet[18];
	BYTE	m_Resistance[7];
	BYTE	m_AddResistance[7];
	int		FrustrumX[4];
	int		FrustrumY[4];
	char	VpPlayer[900];
	char	VpPlayer2[900];
	int		VPCount;
	int		VPCount2;
	char	sHD[480];
	short	sHDCount;
	struct tagInterfaceState m_IfState;
	DWORD	m_InterfaceTime;
	ItemStruct	*pInventory;
	BYTE	*pInventoryMap;
	char	*pInventoryCount;
	char	pTransaction;
	ItemStruct	*Inventory1;
	BYTE	*InventoryMap1;
	char	InventoryCount1;
	ItemStruct	*Inventory2;
	BYTE*	InventoryMap2;
	char	InventoryCount2;
	ItemStruct	*Trade;
	BYTE	*TradeMap;
	int		TradeMoney;
	BYTE	TradeOk;
	ItemStruct	*pWarehouse;
	BYTE	*pWarehouseMap;
	char	WarehouseCount;
	char	m_Filler0xced;
	short	WarehousePW;
	BYTE	WarehouseLock;
	BYTE	WarehouseUnfailLock;
	int		WarehouseMoney;
	int		WarehouseSave;
	ItemStruct	*pChaosBox;
	BYTE	*pChaosBoxMap;
	int		ChaosMoney;
	int		ChaosSuccessRate;
	int		ChaosLock;
	DWORD	m_Option;
	int		m_nEventScore;
	int		m_nEventExp;
	int		m_nEventMoney;
	BYTE	m_bDevilSquareIndex;
	BYTE	m_bDevilSquareAuth;
	char	m_cBloodCastleIndex;
	char	m_cBloodCastleSubIndex;
	int		m_iBloodCastleEXP;
	BYTE	m_bBloodCastleComplete;
	char	m_cChaosCastleIndex;
	char	m_cChaosCastleSubIndex;
	int		m_iChaosCastleBlowTime;
	char	m_cKillUserCount;
	char	m_cKillMonsterCount;
	int		m_iDuelUserReserved;
	int		m_iDuelUserRequested;
	int		m_iDuelUser;
	BYTE	m_btDuelScore;
	int		m_iDuelTickCount;
	BYTE	m_bPShopOpen;
	BYTE	m_bPShopTransaction;
	BYTE	m_bPShopItemChange;
	BYTE	m_bPShopRedrawAbs;
	char	m_szPShopText[36];
	BYTE	m_bPShopWantDeal;
	int		m_iPShopDealerIndex;
	char	m_szPShopDealerName[10];
	CRITICAL_SECTION m_critPShopTrade;
	int		m_iVpPShopPlayer[75];
	WORD	m_wVpPShopPlayerCount;
	BYTE	IsInBattleGround;
	BYTE	HaveWeaponInHand;
	short	EventChipCount;
	int		MutoNumber;
	int		UseEventServer;
	BYTE	LoadWareHouseInfo;
	int		iStoneCount;
	BYTE	m_Quest[50];
	BYTE	m_SendQuestInfo;
	int		m_SkyBossMonSheildLinkIndex;
	int		m_SkyBossMonSheild;
	int		m_SkyBossMonSheildTime;
	int		m_MaxLifePower;
	int		m_WizardSkillDefense;
	int		m_WizardSkillDefenseTime;
	int		m_PacketChecksumTime;
	int		m_CheckLifeTime;
	BYTE	m_MoveOtherServer;
	char	BackName[11];
	char	m_BossGoldDerconMapNumber;
	BYTE	m_InWebzen;
	char	m_LastTeleportTime;
	BYTE	m_ClientHackLogCount;
	int		m_bIsInMonsterHerd;
	int		m_bIsMonsterAttackFirst;
	int		m_lpMonsterHerd;
	char	NPggCSAuth[0x2c];
	BYTE	m_bSentGGAuth;
	DWORD	m_NPggCheckSumSendTime;
	int		fSkillFrustrumX[4];
	int		fSkillFrustrumY[4];
	BYTE	SkillHellFire2State;
	BYTE	SkillHellFire2Count;
	DWORD	SkillHellFire2Time;
	BYTE	m_ReqWarehouseOpen;
	int		m_NotAttackAreaCount;
	short	SetOpAddSkillAttack;
	short	SetOpAddExDamage;
	short	SetOpAddExDamageSuccessRate;
	short	SetOpAddCriticalDamage;
	short	SetOpAddCriticalDamageSuccessRate;
	short	SetOpIncAGValue;
	short	SetOpAddDamage;
	short	SetOpAddMinAttackDamage;
	short	SetOpAddMaxAttackDamage;
	short	SetOpAddAttackDamage;
	short	SetOpAddDefence;
	short	SetOpAddDefenceRate;
	short	SetOpAddMagicPower;
	BYTE	SetOpIgnoreDefense;
	BYTE	SetOpDoubleDamage;
	BYTE	SetOpTwoHandSwordImproveDamage;
	BYTE	SetOpImproveSuccessAttackRate;
	BYTE	SetOpReflectionDamage;
	BYTE	SetOpImproveSheldDefence;
	BYTE	SetOpDecreaseAG;
	BYTE	SetOpImproveItemDropRate;
	BYTE	IsFullSetItem;
	char	DurMagicKeyChecker[0x12c];
	WORD	SkillRecallParty_Time;
	BYTE	SkillRecallParty_MapNumber;
	BYTE	SkillRecallParty_X;
	BYTE	SkillRecallParty_Y;
	WORD	SkillAddCriticalDamageTime;
	WORD	SkillAddCriticalDamage;
	BYTE	bIsChaosMixCompleted;
	BYTE	SkillLongSpearChange;
	char	SkillDelay[0x404];
	int		iObjectSecTimer;
	BYTE	m_bMapSvrMoveQuit;
	BYTE	m_bMapSvrMoveReq;
	DWORD	m_dwMapSvrQuitTick;
	short	m_sPrevMapSvrCode;
	short	m_sDestMapNumber;
	BYTE	m_btDestX;
	BYTE	m_btDestY;
	BYTE	m_bIsCastleNPCUpgradeCompleted;
	BYTE	m_btWeaponState;
	int		m_iWeaponUser;
	BYTE	m_btKillCount;
	int		m_iSkillStunTime;
	int		m_iSkillBrandOfSkillTime;
	int		m_iSkillInvisibleTime;
	int		m_iSkillManaSwellTime;
	int		m_iSkillManaSwell;
	int		m_iAccumulatedDamage;
	int		m_iPotionBlessTime;
	int		m_iPotionSoulTime;
	int		m_iAccumulatedCrownAccessTime;
	char	m_MonsterSkillElementInfo[0x50];
	int		m_iBasicAI;
	int		m_iCurrentAI;
	int		m_iCurrentAIState;
	int		m_iLastAIRunTime;
	int		m_iGroupNumber;
	int		m_iSubGroupNumber;
	int		m_iGroupMemberGuid;
	int		m_iRegenType;
	char	m_Agro[0x324];
	int		m_iLastAutomataRuntime;
	int		m_iLastAutomataDelay;
	int		m_iCrywolfMVPScore;
	DWORD	m_dwLastCheckTick;
	int		m_iAutoRecuperationTime;
	int		m_iSkillNPCHelpTime;
	int		m_iSkillNPCDefense;
	int		m_iSkillNPCAttack;
	int		m_iMuseElfInfinityArrowSkillTime;
	int		m_iSkillDistanceErrorCount;
	DWORD	m_dwSkillDistanceErrorTick;
	char	m_JewelOfHarmonyEffect[0x26];
	char	m_ItemOptionExFor380[0x10];
	int		m_bKanturuEntranceByNPC;
	WORD	m_wItemEffectType;
	int		m_iItemEffectValidTime;
	WORD	m_wCashPoint;
	int		m_iPeriodItemEffectIndex;
	WORD	m_wExprienceRate;
	WORD	m_wItemDropRate;
	BYTE	m_btMoveMapBound;
	BYTE	m_Filler0x1965[0x17];
};
typedef OBJECTSTRUCT * LPOBJ;
__forceinline LPOBJ gObj(int aIndex)
{
	return (LPOBJ)((aIndex * gObjSize) + gObjOffset);
}

struct CustomStruct{
	int		Resets;
	int		MasterResets;
	int		Vip;
	int		Creditos;
	int		CtlCode;
	int		BauAberto;
	int		Bau_Delay;
	int		BauID;	
	int		casado;
	int		ListaNegra;
	int		PostBlock;
	int		PostDelay;
	int		Limite_Pontos;
	int		PedidoCasamento;
	int		PVP_ID;

	int		Add;
	int		AddPontos;
	int		AddLock;

	int		Acumulado_Intervalo;
	int		Acumulado;
};
extern CustomStruct gObjCustom[Obj_Jogadores_Maximo];

#endif