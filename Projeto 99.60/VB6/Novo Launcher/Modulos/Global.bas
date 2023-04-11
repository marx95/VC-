Attribute VB_Name = "Global"
Public Declare Function ShellExecute Lib "shell32.dll" Alias "ShellExecuteA" (ByVal hWnd As Long, ByVal lpOperation As String, ByVal lpFile As String, ByVal lpParameters As String, ByVal lpDirectory As String, ByVal nShowCmd As Long) As Long
Public Declare Function FindWindow Lib "user32" Alias "FindWindowA" (ByVal lpszClassName As String, ByVal lpszWindow As String) As Long
Private Declare Function SendMessage Lib "user32" Alias "SendMessageA" (ByVal hWnd As Long, ByVal wMsg As Long, ByVal wParam As Long, lParam As Any) As Long
Private Declare Sub ReleaseCapture Lib "user32" ()
Private Const WM_NCLBUTTONDOWN = &HA1
Private Const HTCAPTION = 2
Public Declare Function LoadCursor Lib "user32" Alias "LoadCursorA" (ByVal hInstance As Long, ByVal lpCursorName As Long) As Long
Public Declare Function SetCursor Lib "user32" (ByVal hCursor As Long) As Long
Public Const IDC_HAND As Long = &H7F89 '32649
Public Declare Function GetAsyncKeyState Lib "user32" (ByVal vKey As Long) As Integer

' - Estilos
Global Fonte As String
Global Cor As String

Global mCrc                                 As New CRC
Global Link                                 As String
Global ArquivoUpdate                        As String
Global NomeServer                           As String
Global Info                                 As String
Global Main                                 As String
Global Visivel                              As Integer
Global ListaDesatualizados                  As String

Global LauncherStatus   As Integer      ' - 0 para executar atualizaçoes, 1 para executando atualizaçoes, 2 para mostrar o Launcher
Global ErroNoNavegador  As Integer      ' - 1 para erro no navegador de noticias

Global Noticia          As String       ' - Link da pagina de noticias
Global LinkDoSite       As String
Global LinkDoCadastro   As String

Global TamanhoTotal     As Long         ' - Isto é o tamanho total do arquivo a ser baixado

Public Function FecharLauncher()
    On Error GoTo ErroA
    Set Update = Nothing

    On Error GoTo ErroA
    Set Launcher = Nothing

    On Error GoTo ErroA
    Set RegistrarFrm = Nothing

    End
    Exit Function
ErroA:
End
End Function

Public Sub DelTemp()
On Error Resume Next
Kill "update.txt"

On Error Resume Next
Kill "update.rar"
End Sub

Public Function MoverFormSemCaption(Botao As Integer, FormHwnd As Long) As Long
    If Botao = 1 Then
    Call ReleaseCapture
    MoverFormSemCaption = SendMessage(FormHwnd, WM_NCLBUTTONDOWN, HTCAPTION, 0&)
    End If
End Function
