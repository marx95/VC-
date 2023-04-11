#include "StdAfx.h"

void ShadowPhantomBuff(int aIndex)
{
	gObj(aIndex)->m_iSkillNPCHelpTime	= GetTickCount();
    gObj(aIndex)->m_iSkillNPCDefense	= gObj(aIndex)->Level / 5 + 50;      // FORMULA
    gObj(aIndex)->m_iSkillNPCAttack	= gObj(aIndex)->Level / 3 + 45;       // FORMULA
    gObj(aIndex)->m_ViewSkillState		|= 0x2000000;
	GCStateInfoSend(gObj(aIndex), 1, gObj(aIndex)->m_ViewSkillState);
}

void Efeito_Fogos_Artificio(int aIndex) // Foços de Artifício
{
	BYTE Explode[] = {0xC1, 0x07, 0xF3, 0x40, 0x00, 0x00, 0x00};
	Explode[5] = (BYTE)gObj(aIndex)->X;
	Explode[6] = (BYTE)gObj(aIndex)->Y;
	DataSend(aIndex,(PBYTE)Explode,Explode[1]);
}

void Efeito_Fogos_Artificio_Para_Todos_Mesmo_Mapa(int Mapa)
{
	for(int i = Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3)
		{
			if(gObj(i)->MapNumber == Mapa)
			{
				Efeito_Fogos_Artificio(i);
			}
		}
	}
}

void Efeito_Fogos_Artificio_Para_Todos() //Fogos de artificio para todos
{
	for(int i = Obj_Jogadores_Minimo; i<Obj_Jogadores_Maximo; i++)
	{
		if(gObj(i)->Connected == 3)
		{
			Efeito_Fogos_Artificio(i);
		}
	}
}

void Efeito_Aura_Azul(int aIndex)
{
	unsigned char msgAura[9] = {0xc3, 0x09, 0x1E, 40, HIBYTE(aIndex), LOBYTE(aIndex)};
	DataSend(aIndex, msgAura, 9);
}

void Efeito_de_Upar(int aIndex)
{
	GCLevelUpMsgSend(aIndex , 0);
}