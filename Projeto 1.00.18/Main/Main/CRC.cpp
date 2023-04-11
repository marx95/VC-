#include "StdAfx.h"

unsigned long PegarCheckSum(char* PathFilename)
{
        FILE* File;
        unsigned long CheckSum = 0;
        unsigned long Data = 0;
        unsigned long Count = 0;

        if ((File = fopen(PathFilename, "rb")) != NULL)
        {
                while (fread(&Data, 1, sizeof(unsigned long), File) != FALSE)
                {
                        CheckSum ^= Data + ++Count;
                        Data = 0;
                }
                fclose(File);
        }
        return CheckSum;
}