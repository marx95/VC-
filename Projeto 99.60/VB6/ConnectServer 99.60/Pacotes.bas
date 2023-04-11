Attribute VB_Name = "Pacotes"
Public Function PacotePrimario(Index As Integer) As Boolean
    Dim Pacote(0 To 3) As Byte
    Pacote(0) = &HC1
    Pacote(1) = &H4
    Pacote(2) = &H0
    Pacote(3) = &H1
    
    PacotePrimario = Enviar(Index, Pacote)
End Function

Public Function PacoteListaDeSalas(Index As Integer) As Boolean
    Dim Pacote(10) As Byte
    Pacote(0) = &HC2
    Pacote(1) = &H0
    Pacote(2) = &HB
    Pacote(3) = &HF4
    Pacote(4) = &H6
    Pacote(5) = &H0
    Pacote(6) = &H1 ' - Total de Salas
    Pacote(7) = &H0 ' - ID da Sala
    Pacote(8) = &H0
    Pacote(9) = Val("&H" & Hex(CInt(Total_On))) 'Val("&H" & Total_On) ' - Total Players ON
    Pacote(10) = &H77
        
    PacoteListaDeSalas = Enviar(Index, Pacote)
End Function

Public Function PacoteSalaIPePorta(Index As Integer) As Boolean
    Dim Pacote() As Byte
    Dim Size As Integer
    Dim tmpIP As String
    
    tmpIP = Sala_IP
    If InStr(1, CS.Sock(Index).RemoteHostIP, "10.") Then tmpIP = CS.Sock(0).LocalIP
    If InStr(1, CS.Sock(Index).RemoteHostIP, "127.") Then tmpIP = CS.Sock(0).LocalIP
    If InStr(1, CS.Sock(Index).RemoteHostIP, "192.") Then tmpIP = CS.Sock(0).LocalIP
    
    Size = 8 + Len(tmpIP)
        
    ReDim Pacote(Size - 1)
        
    Pacote(0) = &HC1
    Pacote(1) = Size
    Pacote(2) = &HF4
    Pacote(3) = &H3
        
    For i = 1 To Len(tmpIP)
        Pacote(3 + i) = Val("&H" & StringToHex(Mid(tmpIP, i, 1)))
    Next i
        
    'Pacote(Len(tmpIP) + 4) = &H0
    'Pacote(Len(tmpIP) + 5) = &HAE
    'Pacote(Len(tmpIP) + 6) = &H4
    'Pacote(Len(tmpIP) + 7) = &H3
    'Pacote(Len(tmpIP) + 8) = Val("&H" & Mid(Hex(Sala_Porta), 3, 2)) ' - Porta
    'Pacote(Len(tmpIP) + 9) = Val("&H" & Mid(Hex(Sala_Porta), 1, 2)) ' - Porta
    
    Pacote(Len(tmpIP) + 4) = &H0
    Pacote(Len(tmpIP) + 5) = &H3
    Pacote(Len(tmpIP) + 6) = Val("&H" & Mid(Hex(Sala_Porta), 3, 2)) ' - Porta
    Pacote(Len(tmpIP) + 7) = Val("&H" & Mid(Hex(Sala_Porta), 1, 2)) ' - Porta
    CS.Erros.AddItem tmpIP & ":" & Sala_Porta
    
    PacoteSalaIPePorta = Enviar(Index, Pacote)
End Function

Public Function PacoteVersaoMain(Index As Integer) As Boolean
    Dim Pacote(0 To 11) As Byte
    Pacote(0) = &HC1
    Pacote(1) = &HC
    Pacote(2) = &HF1
    Pacote(3) = &H0
    Pacote(4) = &H1
    Pacote(5) = &H19
    Pacote(6) = &H0
    Pacote(7) = &H31 ' - Versao do Main
    Pacote(8) = &H30
    Pacote(9) = &H30
    Pacote(10) = &H30
    Pacote(11) = &H30 ' - Fim versao do main
        
    PacoteVersaoMain = Enviar(Index, Pacote)
End Function
