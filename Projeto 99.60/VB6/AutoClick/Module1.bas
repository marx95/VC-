Attribute VB_Name = "Globals"
Public Declare Function FindWindow Lib "user32" Alias "FindWindowA" (ByVal lpClassName As String, ByVal lpWindowName As String) As Long
Public Declare Function SendMessage Lib "user32" Alias "SendMessageA" (ByVal hwnd As Long, ByVal wMsg As Long, ByVal wParam As Integer, ByVal lParam As Any) As Long

' - TratarJanela
Public Declare Function PostMessage Lib "user32" Alias "PostMessageA" (ByVal hwnd As Long, ByVal wMsg As Long, ByVal wParam As Long, lParam As Any) As Long
Public Declare Sub SetWindowPos Lib "user32" (ByVal hwnd As Long, ByVal hWndInsertAfter As Integer, ByVal X As Integer, ByVal Y As Integer, ByVal cx As Integer, ByVal cy As Integer, ByVal wFlags As Integer)
Public Declare Function ShowWindow Lib "user32" (ByVal hwnd As Long, ByVal nCmdShow As Long) As Long
Public Declare Function SetForegroundWindow Lib "user32" (ByVal hwnd As Long) As Long

'AutoClick Declares
Public Const WM_LBUTTONUP As Long = &H202
Public Const WM_LBUTTONDOWN As Long = &H201
Public Const WM_RBUTTONDOWN = &H204
Public Const WM_RBUTTONUP = &H205
Public Declare Function GetAsyncKeyState Lib "user32" (ByVal vKey As KeyCodeConstants) As Long

Public Declare Function ShellExecute Lib "shell32.dll" Alias "ShellExecuteA" (ByVal hwnd As Long, ByVal lpOperation As String, ByVal lpFile As String, ByVal lpParameters As String, ByVal lpDirectory As String, ByVal nShowCmd As Long) As Long

Global JanelaID As Long
Global NomeJanela As String
Global EsquerdoAtivado As Integer
Global DireitoAtivado As Integer
Global JanelaEscondida As Integer
Global Bordas As Integer
Global AutoClick_Ativado As Integer
Global Topo As Integer

Public Function ApertarTeclas(ByVal vKey As KeyCodeConstants) As Boolean
On Error Resume Next
   ApertarTeclas = GetAsyncKeyState(vKey) And &H8000
End Function

Public Function FicarClicandoEsquerdo()
    'Call SendMessage(JanelaID, WM_LBUTTONDOWN, 0, StrPtr(O))
    'Call SendMessage(JanelaID, WM_LBUTTONUP, 0, StrPtr(O))
    SendMessage JanelaID, WM_RBUTTONUP, 0, StrPtr(O)
    SendMessage JanelaID, WM_RBUTTONDOWN, 0, StrPtr(O)
End Function

Public Function ColocaNoTopo()
 If Topo = 1 And JanelaID > 0 Then
        Call SetWindowPos(JanelaID, -2, 0, 0, 0, 0, &H2 Or &H1) ' - Traz para Frente
    End If
End Function

Public Function EsconderJanela(OqueFazer As Integer)
    If OqueFazer = 0 Then
        'SetWindowPos JanelaID, -2, 0, 0, 0, 0, &H2 Or &H1
        ShowWindow JanelaID, 0
        Exit Function
    End If
    
    If OqueFazer = 1 Then
        ShowWindow JanelaID, 5
        Call ColocaNoTopo
        Exit Function
    End If
End Function
