struct StructSets
{
	int Level;
	int Option;
	int Index;
};

struct StructArmamentos
{
	int Grupo;
	int Index;
	int Drop;
	int Level;
	int Option;
	int Skill;
};

extern StructSets Sets[256];
extern StructArmamentos Armamentos[256];

void CarregarDropCustom();
BOOL gEventMonsterItemDrop_Hook(LPOBJ lpObj, LPOBJ lpTargetObj);