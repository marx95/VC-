Attribute VB_Name = "Defs_N_Funcs"
Public Declare Function ShellExecute Lib "shell32.dll" Alias "ShellExecuteA" (ByVal hWnd As Long, ByVal lpOperation As String, ByVal lpFile As String, ByVal lpParameters As String, ByVal lpDirectory As String, ByVal nShowCmd As Long) As Long
Public Declare Sub Sleep Lib "kernel32.dll" (ByVal dwMilliseconds As Long)
Public Declare Sub ExitProcess Lib "kernel32" (ByVal uExitCode As Long)

Global Status As Integer

Global Lista_de_Arquivos() As String
Global Lista_a_Baixar(0 To 16000) As String
Global Total_a_Baixar As Long

Global Lista_de_Arquivos_CRC() As String
Global Lista_a_Baixar_CRC(0 To 16000) As String
Global Total_a_Baixar_CRC As Long

Global Tamanho As Long
Global Tamanho_do_Arquivo(0 To 16000) As Long
Global Tamanho_do_Arquivo_CRC(0 To 16000) As Long

Global mcrc As New CRC
Global ArquivoUpdate As String

Global LinkSite As String
Global NomeJanela As String
Global LinkDirUpdate As String
Global LinkDLL As String
Global ErroNoNavegador As Long
Global LinkNoticias As String

Public Sub DelTmp()
    Call Deletar("MuError.log")
    Call Deletar("update.txt")
    Call Deletar("update_crc.txt")
End Sub

Public Sub Deletar(Arq As String)
    If Len(Arq) > 0 Then
        On Error GoTo ERRODel
        Call Kill(Arq)
    End If
ERRODel:
End Sub

Public Function Existe(Arq As String) As Boolean
    Arq = Replace(Arq, "/", "\")
    
    If Len(Dir(Arq)) < 4 Then
        Existe = False
        Exit Function
    End If
    Existe = True
End Function

Public Sub Fechar()
    Call DelTmp
    On Error Resume Next
    Set Launcher = Nothing
    Call ExitProcess(0)
End Sub
