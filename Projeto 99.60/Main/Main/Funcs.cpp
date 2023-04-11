#include "StdAfx.h"

char *Deixar_Minusculo(char *Var)
{
	int Tam = strlen(Var);
	for(int i = 0; i < Tam; i++)
	{
		if(isupper(Var[i])) Var[i] = tolower(Var[i]);
	}
	return Var;
}

void Pegar_Nome_Janela_Topo()
{
	HWND hwnd;
	hwnd = GetForegroundWindow();
	long Tamanho = 1+GetWindowTextLength(hwnd);
	GetWindowText(hwnd, AntiHack.Janela_Topo, Tamanho);
	sprintf_s(AntiHack.Janela_Topo, "%s", AntiHack.Janela_Topo);
}

bool Procurar(char *OndeProcurar, char *Pesquisar, bool CaseSensitive)
{	
	int TotalEncontrado		= 0;
	int TamanhoOndeP		= strlen(OndeProcurar);
	int TamanhoPesq			= strlen(Pesquisar);
	int h = 0;

	if(TamanhoPesq > TamanhoOndeP) return false;
	for(int i = 0; i < TamanhoOndeP; i++)
	{
		char CaractereA = OndeProcurar[i];
		char CaractereB = Pesquisar[h];
		if(!CaseSensitive) CaractereA = tolower(OndeProcurar[h]);
		if(!CaseSensitive) CaractereB = tolower(Pesquisar[h]);

		if(CaractereA == CaractereB) 
		{
			TotalEncontrado++;
			h++;
		}else
		{
			TotalEncontrado = 0;
			h = 0;
		}
		if(TotalEncontrado >= TamanhoPesq) return true;
	}
	if(TotalEncontrado >= TamanhoPesq) return true;
	return false;
}