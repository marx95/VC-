#include "StdAfx.h"

void MostrarMSGDragonEvento() 
{
	__asm
	{
		pushad
		mov EAX, MostrarMsgDeDragoesDourados
		CALL EAX
		popad
	}

	MsgParaTodos("Invas�o de Drag�es Dourados, Proteja as cidades!", 0);
}

void FixEventos()
{
	_asm
		{
			pushad
			mov eax, MostrarMsgDeDragoesDouradosHook
			mov ecx, offset MostrarMSGDragonEvento
			sub ecx, MostrarMsgDeDragoesDouradosHook+4
			mov [eax],ecx
			popad
		}

}