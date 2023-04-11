#include "StdAfx.h"

void ChatDataSend(DWORD aIndex,LPBYTE Protocol)
	{
	//Comando Post global
	if(!memcmp(&Protocol[13],CommandPost,strlen(CommandPost)))
	{
		Post(aIndex,(char*)Protocol+14+strlen(CommandPost));
		return;
	}

	//Comandos de add
	//Adicionar em STR
	if(!memcmp(&Protocol[13],CommandStr,strlen(CommandStr)))
	{
		AdicionarPontos(aIndex,(char*)Protocol+14+strlen(CommandStr),0);
		return;
	}

	//Adicionar em Agilidade
	if(!memcmp(&Protocol[13],CommandAgi,strlen(CommandAgi)))
	{
		AdicionarPontos(aIndex,(char*)Protocol+14+strlen(CommandAgi),1);
		return;
	}

	//Adicionar em Vitalidade
	if(!memcmp(&Protocol[13],CommandVit,strlen(CommandVit)))
	{
		AdicionarPontos(aIndex,(char*)Protocol+14+strlen(CommandVit),2);
		return;
	}

	//Adicionar em Energia
	if(!memcmp(&Protocol[13],CommandEne,strlen(CommandEne)))
	{
		AdicionarPontos(aIndex,(char*)Protocol+14+strlen(CommandEne),3);
		return;
	}

	//Adicionar em Comando
	if(!memcmp(&Protocol[13],CommandCmd,strlen(CommandCmd)))
	{
		AdicionarPontos(aIndex,(char*)Protocol+14+strlen(CommandCmd),4);
		return;
	}

	//Comando de informaçoes e creditos
	if(!memcmp(&Protocol[13],"/info",strlen("/info")))
	{
		MsgParaJogador("[Info] GameServer feito por MarxD",aIndex);
		MsgParaJogador("[Info] Base: 1.00.19 GS-CS",aIndex);
		MsgParaJogador("[Info] http://munovus.net",aIndex);
		MsgParaJogador("[Info] Creditos á Hotch_ADM!",aIndex);
		return;
	}

	//Comado /b fala de gm
	if(!memcmp(&Protocol[13], "/b", strlen("/b")))
	{
		if(gObjCustom[aIndex].CtlCode < GM_CtlCode) return;

		GMFala(aIndex, (char*)Protocol+13+strlen("/b"));
		return;
	}

	//ChatOff
	if(!memcmp(&Protocol[13], "/chatoff",strlen("/chatoff")))
	{
		ChatOff(aIndex,(char*)Protocol+14+strlen("/chatoff"));
	}

	//ChatOn
	if(!memcmp(&Protocol[13], "/chaton",strlen("/chaton")))
	{
		ChatOn(aIndex,(char*)Protocol+14+strlen("/chaton"));
	}

	}