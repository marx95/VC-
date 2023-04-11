#include "StdAfx.h"

bool NpcClick (int aIndex, int NpcID)
{
	gObjCustom[aIndex].UltimoNpcIndex = NpcID;

	if(gObj(NpcID)->Class == 240)
	{
		char TmpBauMsg[64];
		sprintf_s(TmpBauMsg, "Baú %d aberto!", gObjCustom[aIndex].BauID);
		NpcChat(TmpBauMsg, gObjCustom[aIndex].UltimoNpcIndex, aIndex);
		Mssql_Atualiza(aIndex, 5); //Isto interfere no comando de MUDAR BAU -- Cuidado!!
		return false;
	}

	if(gObj(NpcID)->Class == 257)
	{
		if(gObj(aIndex)->Level > GS.ShadowP_MaxLevel)	
		{
			GCServerCmd(aIndex, 0x0D, 0, 0);
			return true;
		}

		ShadowPhantomBuff(aIndex);
		return true;
	}

	if(gObj(NpcID)->Class == 406) // -Priesxt sevin
	{
		Evoluir(aIndex, 0);
		return true;
	}

	if(gObj(NpcID)->MapNumber == GS.MapaRst && gObj(NpcID)->Class == GS.NpcRst)
	{
		Reset(aIndex, 0);
		return true;
	}

	if(gObj(NpcID)->MapNumber == GS.MapaPK && gObj(NpcID)->Class == GS.NpcPK)
	{
		LimparPK(aIndex, 0);
		return true;
	}

	return false;
}