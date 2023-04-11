#include "stdafx.h"

wzag WzAG;

char * SetarLang()
{
	switch(GetPrivateProfileInt("GameServerInfo", "Language", 0, "..\\Data\\commonserver.cfg"))
	{
		case 0: return "Kor"; break;
		case 1: return "Eng"; break;
		case 2: return "Jpn"; break;
		case 3: return "Chs"; break;
		case 4: return "Twa"; break;
		case 5: return "tha"; break;
		case 6: return "Phi"; break;
		case 7: return "Vtm"; break;
	}
	return "Kor";
}

///////////////////////////////////////////////
//Sistema de Emulação da Autenticação (GSAUTH) *??Não funciona até agora??
///////////////////////////////////////////////
int wzag::AGConnectSetFS() 
{
        _asm{
                xor eax,eax
        }
        return 0;
}

/////////////////////////////////////////////
//Define a versão e serial do cliente
/////////////////////////////////////////////
int wzag::AGGetClientVersion(int unknown,char * VerBuff,char * SerialBuff) 
{
        char ver[0x14];
        char serial[0x14];
		char * Lang = SetarLang();
        char commonlocPath[64];

		sprintf_s(commonlocPath, "..\\data\\lang\\%s\\commonloc.cfg", Lang);
        GetPrivateProfileString("GameServerInfo","ClientExeVersion","",&ver[0],0x14,commonlocPath);
        GetPrivateProfileString("GameServerInfo","ClientExeSerial","",&serial[0],0x14,commonlocPath     );
        memcpy(VerBuff,ver,0x14);
        memcpy(SerialBuff,serial,0x14);
        return 0;
}

char * wzag::AGGetDataBuffer()  
{
        return FileBuffer;
}

int wzag::AGGetDataBufferSize() 
{
        return FileLen;
}

void wzag::AGGetKey(HANDLE handle,char* key,int startindex,int len)
{
        memcpy(key,szServerKey,sizeof(szServerKey));
}

int wzag::AGReleaseHandle() 
{
        _asm{
                xor eax,eax
        }
        return 0;
}

///////////////////////////////////////////////
//Envia a solicitação da Data para o GameServer
///////////////////////////////////////////////
int wzag::AGRequestData(int NoneUse,int GetType)  
{
        char filename[64];
		char * Lang = SetarLang();

        switch (GetType)
        {
        case 0x00:
                sprintf_s(filename, "..\\data\\Lang\\%s\\item(%s).txt", Lang, Lang);
                break;
        case 0x01:
				sprintf_s(filename, "..\\data\\Lang\\%s\\item(%s).txt", Lang, Lang);
                break;
        case 0x02:
				sprintf_s(filename, "..\\data\\Lang\\%s\\skill(%s).txt", Lang, Lang);
                break;
        case 0x03:
				sprintf_s(filename, "..\\data\\Lang\\%s\\skill(%s).txt", Lang, Lang);
                break;
        case 0x04:
				sprintf_s(filename, "..\\data\\Lang\\%s\\quest(%s).txt", Lang, Lang);
                break;
        case 0x05: // - 0x05 Skills sem uso
				sprintf_s(filename, "..\\data\\Lang\\%s\\quest(%s).txt", Lang, Lang);
                break;
        case 0x06:
				sprintf_s(filename, "..\\data\\Lang\\%s\\CheckSum.dat", Lang);
                break;
        case 0x07:
				sprintf_s(filename, "..\\data\\Monster.txt");
                break;
        case 0x08: 
				sprintf_s(filename, "..\\data\\gate.txt");
                break;
        case 0x09:
				sprintf_s(filename, "..\\data\\MonsterSetBase.txt");
                break;
                //Reservado GameGuard
        case 0x0A:
                break;
        case 0x0B:
				sprintf_s(filename, "..\\data\\Shop0.txt");
                break;
        case 0x0C:
               sprintf_s(filename, "..\\data\\Shop1.txt");
                break;
        case 0x0D:
                sprintf_s(filename, "..\\data\\Shop2.txt");
                break;
        case 0x0E:
                sprintf_s(filename, "..\\data\\Shop3.txt");
                break;
        case 0x0F:
                sprintf_s(filename, "..\\data\\Shop4.txt");
                break;
        case 0x10:
                sprintf_s(filename, "..\\data\\Shop5.txt");
                break;
        case 0x11:
                sprintf_s(filename, "..\\data\\Shop6.txt");
                break;
        case 0x12:
                sprintf_s(filename, "..\\data\\Shop7.txt");
                break;
        case 0x13:
               sprintf_s(filename, "..\\data\\Shop8.txt");
                break;
        case 0x14:
                sprintf_s(filename, "..\\data\\Shop9.txt");
                break;
        case 0x15:
                sprintf_s(filename, "..\\data\\Shop10.txt");
                break;          
        case 0x16:
                sprintf_s(filename, "..\\data\\Shop11.txt");
                break;
        case 0x17:
                sprintf_s(filename, "..\\data\\Shop12.txt");
                break;
                //Requerimentos do Move
        case 0x18:
                sprintf_s(filename, "..\\data\\Lang\\%s\\movereq(%s).txt", Lang, Lang);
                break;
        case 0x19:
                sprintf_s(filename, "..\\data\\Lang\\%s\\movereq(%s).txt", Lang, Lang);
                break;
                //Option dos Set Anciente
        case 0x1A:
                sprintf_s(filename, "..\\data\\Lang\\%s\\itemsetoption(%s).txt", Lang, Lang);
                break;
        case 0x1B:
                sprintf_s(filename, "..\\data\\Lang\\%s\\itemsetoption(%s).txt", Lang, Lang);
                break;
                //Tipos de Set Anciente
        case 0x1C:
                sprintf_s(filename, "..\\data\\Lang\\%s\\itemsettype(%s).txt", Lang, Lang);
                break;
        case 0x1D:
                sprintf_s(filename, "..\\data\\Lang\\%s\\itemsettype(%s).txt", Lang, Lang);
                break;
        default:
                sprintf_s(filename, "Falha! - MarxD WzAg.dll");
                ::ExitProcess(0);
                break;

        }
        if(fstream1=fopen(filename,"rb"))
        {
                fseek(fstream1,0,SEEK_END);
                if(FileLen=ftell(fstream1))
                {
                        fseek(fstream1,0,SEEK_SET);
                        if(FileBuffer != NULL)
                                delete[] FileBuffer;

                        FileBuffer = new char[FileLen+1];
                        fread(FileBuffer,FileLen,1,fstream1);
                }
                else
                {
                        MessageBox( NULL, filename,"Erro! - MarxD WzAg.dll", MB_OK );
                        ::ExitProcess(0);
                }
                fclose(fstream1);
        }

        else
        {
                MessageBox( NULL, filename,"Erro! - MarxD WzAg.dll", MB_OK );
                ::ExitProcess(0);
        } 
        return 0;
}

/////////////////////////////////////////////
//Função Principal da DLL WzAG
/////////////////////////////////////////////
int wzag::AGSetInfo(int Language,char * Partition,int un0,char * SrvVer,char* SrvName, int SrvType,char * Addr7)  
{
        Lsrvname	= SrvName;
        Lsrvver		= SrvVer;
        Lpartition	= Partition;
        Laddrarg7	= Addr7;
        return 0;                       
}

int wzag::AGSetSubInfo() 
{
        _asm{
                xor eax,eax
        }
        return 0;
}