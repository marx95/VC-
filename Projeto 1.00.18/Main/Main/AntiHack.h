struct AntiHackStruct
{
	char Janela_Topo[512];
	int Main_Congelado;
};
extern AntiHackStruct AntiHack;

struct HacksStruct
{
	int Ativado;
	char Nome[128];
};
extern HacksStruct Hack[256];