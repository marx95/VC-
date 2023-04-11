Attribute VB_Name = "Global"
Public Declare Sub Sleep Lib "kernel32.dll" (ByVal dwMilliseconds As Long)
Public Declare Sub ExitProcess Lib "kernel32" (ByVal uExitCode As Long)
Public Declare Function ShellExecute Lib "shell32.dll" Alias "ShellExecuteA" (ByVal hWnd As Long, ByVal lpOperation As String, ByVal lpFile As String, ByVal lpParameters As String, ByVal lpDirectory As String, ByVal nShowCmd As Long) As Long

Global CMin As Integer
Global CMax As Integer

Global Sala_IP As String
Global Sala_Porta As String
Global Porta_CS As String
Global UltimoReload As String
Global ShellAtivado As String
Global Total_On As String

Global Estado(0 To 10000) As Integer
Global Counter(0 To 10000) As Integer
Global Counter_Limite(0 To 10000) As Integer

Public Sub ShellRefresh()
    Call ShellExecute(CS.hWnd, vbNullString, App.EXEName & ".exe", "Refresh", vbNullString, 0)
End Sub
Public Sub CarregarConfigs()
    CMin = 1
    CMax = ReadINI(App.Path & "/Config.ini", "Config", "Clientes_Maximos")
    If CMax > 10000 Then CMax = 10000
    
    ShellAtivado = ReadINI(App.Path & "/Config.ini", "Config", "URL_IP_Ativado")
    If ShellAtivado = "0" Then
        Sala_IP = ReadINI(App.Path & "/Config.ini", "Config", "IP_da_Sala")
        Sala_Porta = ReadINI(App.Path & "/Config.ini", "Config", "Porta_da_Sala")
        Total_On = 16
        CS.RecarregarIP.Enabled = False
    Else
        Call ShellRefresh
        CS.RecarregarIP.Enabled = True
    End If
    
    Porta_CS = ReadINI(App.Path & "/Config.ini", "Config", "Porta_CS")
End Sub

Public Function StringToHex(ByVal StrToHex As String) As String
    Dim strTemp   As String
    Dim strReturn As String
    Dim i         As Long
    
    For i = 1 To Len(StrToHex)
        strTemp = Hex$(Asc(Mid$(StrToHex, i, 1)))
        If Len(strTemp) = 1 Then strTemp = "0" & strTemp
        If strReturn = "" Then
        strReturn = strReturn & strTemp
        Else
        strReturn = strReturn & Space$(1) & strTemp
        End If
    Next i
    
    StringToHex = strReturn
End Function

Public Function HexToString(ByVal HexToStr As String) As String
    Dim strTemp   As String
    Dim strReturn As String
    Dim i         As Long
    
    For i = 1 To Len(HexToStr) Step 3
        strTemp = Chr$(Val("&H" & Mid$(HexToStr, i, 2)))
        strReturn = strReturn & strTemp
    Next i
    
    HexToString = strReturn
End Function

Public Function Enviar(Index As Integer, Data() As Byte) As Boolean
    
    If CS.Sock(Index).State = 7 Then
        DoEvents
        
        On Error GoTo ErroEnv
        CS.Sock(Index).SendData Data
        Enviar = True
        Exit Function
    End If
    
    Enviar = False
    Exit Function
    
ErroEnv:     Enviar = False
End Function
