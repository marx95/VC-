void ProtocolCore_Hook(BYTE protoNum, unsigned char * aRecv, int aLen, int aIndex, BOOL Encrypt, int serial);
bool DataSend_Hook(int aIndex, unsigned char* lpMsg, DWORD dwSize);