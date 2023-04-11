#include "StdAfx.h"

bool NpcClick (int aIndex, int NpcID)
{		
		if(gObj(NpcID)->Class == 240)
		{
			char TmpBauMsg[128];
			sprintf_s(TmpBauMsg, "[Baú] Baú %d aberto!", gObjCustom[aIndex].BauID);
			MsgParaJogador(TmpBauMsg, aIndex);
			func_mssql.Atualiza(aIndex, 5); //Isto interfere no comando de MUDAR BAU -- Cuidado!!
			return true;
		}
		return true;
}