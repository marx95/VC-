struct AntiHackStruct
{
	char Janela_Topo[1024];
	bool HackDetectado;
	bool ListaCarregada;
	int HackID;
	int TotalHacks;
	long Player_BMD_CRC;
	long Terrain1_ATT_CRC;
	long Main_EXE_CRC;
	long Skill_BMD_CRC;
	char CmdLine[64];
	char NomeJanela[64];
};
extern AntiHackStruct AntiHack;

struct HacksStruct
{
	char Nome[128];
};
extern HacksStruct Hack[128];