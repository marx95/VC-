#include "stdafx.h"

struct CItem {

  // static data ------------------------------------

  // non-static data --------------------------------
  /*<thisrel this+0x0>*/ /*|0x4|*/ unsigned long m_Number;
  /*<thisrel this+0x4>*/ /*|0x1|*/ char m_serial;
  /*<thisrel this+0x6>*/ /*|0x2|*/ short m_Type;
  /*<thisrel this+0x8>*/ /*|0x2|*/ short m_Level;
  /*<thisrel this+0xa>*/ /*|0x1|*/ unsigned char m_Part;
  /*<thisrel this+0xb>*/ /*|0x1|*/ unsigned char m_Class;
  /*<thisrel this+0xc>*/ /*|0x1|*/ unsigned char m_TwoHand;
  /*<thisrel this+0xd>*/ /*|0x1|*/ unsigned char m_AttackSpeed;
  /*<thisrel this+0xe>*/ /*|0x1|*/ unsigned char m_WalkSpeed;
  /*<thisrel this+0x10>*/ /*|0x2|*/ unsigned short m_DamageMin;
  /*<thisrel this+0x12>*/ /*|0x2|*/ unsigned short m_DamageMax;
  /*<thisrel this+0x14>*/ /*|0x1|*/ unsigned char m_SuccessfulBlocking;
  /*<thisrel this+0x16>*/ /*|0x2|*/ unsigned short m_Defense;
  /*<thisrel this+0x18>*/ /*|0x2|*/ unsigned short m_MagicDefense;
  /*<thisrel this+0x1a>*/ /*|0x1|*/ unsigned char m_Speed;
  /*<thisrel this+0x1c>*/ /*|0x2|*/ unsigned short m_DamageMinOrigin;
  /*<thisrel this+0x1e>*/ /*|0x2|*/ unsigned short m_DefenseOrigin;
  /*<thisrel this+0x20>*/ /*|0x2|*/ unsigned short m_Magic;
  /*<thisrel this+0x24>*/ /*|0x4|*/ float m_Durability;
  /*<thisrel this+0x28>*/ /*|0x2|*/ unsigned short m_DurabilitySmall;
  /*<thisrel this+0x2c>*/ /*|0x4|*/ float m_BaseDurability;
  /*<thisrel this+0x30>*/ /*|0x1|*/ unsigned char m_SpecialNum;
  /*<thisrel this+0x31>*/ /*|0x8|*/ unsigned char m_Special[8];
  /*<thisrel this+0x39>*/ /*|0x8|*/ unsigned char m_SpecialValue[8];
  /*<thisrel this+0x42>*/ /*|0x2|*/ unsigned short m_RequireStrength;
  /*<thisrel this+0x44>*/ /*|0x2|*/ unsigned short m_RequireDexterity;
  /*<thisrel this+0x46>*/ /*|0x2|*/ unsigned short m_RequireEnergy;
  /*<thisrel this+0x48>*/ /*|0x2|*/ unsigned short m_RequireLevel;
  /*<thisrel this+0x4a>*/ /*|0x2|*/ unsigned short m_RequireLeaderShip;
  /*<thisrel this+0x4c>*/ /*|0x2|*/ unsigned short m_Leadership;
  /*<thisrel this+0x4e>*/ /*|0x5|*/ unsigned char m_RequireClass[5];
  /*<thisrel this+0x53>*/ /*|0x7|*/ unsigned char m_Resistance[7];
  /*<thisrel this+0x5c>*/ /*|0x4|*/ int m_Value;
  /*<thisrel this+0x60>*/ /*|0x4|*/ unsigned long m_SellMoney;
  /*<thisrel this+0x64>*/ /*|0x4|*/ unsigned long m_BuyMoney;
  /*<thisrel this+0x68>*/ /*|0x4|*/ int m_iPShopValue;
  /*<thisrel this+0x6c>*/ /*|0x1|*/ unsigned char m_bItemExist;
  /*<thisrel this+0x70>*/ /*|0x4|*/ int m_OldSellMoney;
  /*<thisrel this+0x74>*/ /*|0x4|*/ int m_OldBuyMoney;
  /*<thisrel this+0x78>*/ /*|0x1|*/ unsigned char m_Option1;
  /*<thisrel this+0x79>*/ /*|0x1|*/ unsigned char m_Option2;
  /*<thisrel this+0x7a>*/ /*|0x1|*/ unsigned char m_Option3;
  /*<thisrel this+0x7b>*/ /*|0x1|*/ unsigned char m_NewOption;
  /*<thisrel this+0x7c>*/ /*|0x10|*/ float m_DurabilityState[4];
  /*<thisrel this+0x8c>*/ /*|0x4|*/ float m_CurrentDurabilityState;
  /*<thisrel this+0x90>*/ /*|0x1|*/ unsigned char m_SkillChange;
  /*<thisrel this+0x91>*/ /*|0x1|*/ unsigned char m_QuestItem;
  /*<thisrel this+0x92>*/ /*|0x1|*/ unsigned char m_SetOption;
  /*<thisrel this+0x93>*/ /*|0x1|*/ unsigned char m_SetAddStat;
  /*<thisrel this+0x94>*/ /*|0x1|*/ unsigned char m_IsValidItem;
  /*<thisrel this+0x95>*/ /*|0x7|*/ unsigned char m_SkillResistance[7];
  /*<thisrel this+0x9c>*/ /*|0x4|*/ int m_IsLoadPetItemInfo;
  /*<thisrel this+0xa0>*/ /*|0x4|*/ int m_PetItem_Level;
  /*<thisrel this+0xa4>*/ /*|0x4|*/ int m_PetItem_Exp;
};