
typedef struct MoveStruct
{
	char	Nome[32];
	int		Mapa;
	int		X;
	int		Y;
	int		Level;
	int		Rand;
	int		Custo;
}MoveStruct;

extern MoveStruct Move[512];
extern int TotalMove;
void CarregarMove();
void CustomMove(int aIndex, char* Nome);