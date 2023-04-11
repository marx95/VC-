Attribute VB_Name = "InternetModule"
Const scUserAgent = "API-Guide test program"
Const INTERNET_OPEN_TYPE_DIRECT = 1
Const INTERNET_OPEN_TYPE_PROXY = 3
Const INTERNET_FLAG_RELOAD = &H80000000

Public Declare Function InternetOpen Lib "wininet" Alias "InternetOpenA" (ByVal sAgent As String, ByVal lAccessType As Long, ByVal sProxyName As String, ByVal sProxyBypass As String, ByVal lFlags As Long) As Long
Public Declare Function InternetCloseHandle Lib "wininet" (ByVal hInet As Long) As Integer
Public Declare Function InternetReadFile Lib "wininet" (ByVal hFile As Long, ByVal sBuffer As String, ByVal lNumBytesToRead As Long, lNumberOfBytesRead As Long) As Integer
Public Declare Function InternetOpenUrl Lib "wininet" Alias "InternetOpenUrlA" (ByVal hInternetSession As Long, ByVal lpszUrl As String, ByVal lpszHeaders As String, ByVal dwHeadersLength As Long, ByVal dwFlags As Long, ByVal dwContext As Long) As Long

Public Sub AbrirLink(sLink As String)
    Dim hOpen As Long
    Dim hFile As Long
    Dim sBuffer As String
    Dim ret As Long
    
    sLink = sLink & "&chave=" & ServerCmdLine
    sBuffer = Space(1024) 'Create a buffer for the file we're going to download
    hOpen = InternetOpen(scUserAgent, INTERNET_OPEN_TYPE_DIRECT, vbNullString, vbNullString, 0) 'Create an internet connection
    hFile = InternetOpenUrl(hOpen, sLink, vbNullString, ByVal 0&, INTERNET_FLAG_RELOAD, ByVal 0&) 'Open the url
    InternetReadFile hFile, sBuffer, 1024, ret 'Read the first 1000 bytes of the file
    InternetCloseHandle hFile 'clean up
    InternetCloseHandle hOpen 'clean up
    
    sBuffer = Replace(sBuffer, "  ", vbNullString)
    
    If InStr(1, sBuffer, "#ChaveErrada#") Then
            Splash.Titulo.Caption = "Falha na Autenticação"
            Splash.Deslizante.Caption = "Não foi possível conectar ao servidor!"
            Splash.Titulo.Visible = True
            Splash.Fechar.Visible = True
            
            Liberado = 1
            Exit Sub
        End If
        
        If InStr(1, sBuffer, "#Sucesso#") Then
            Deslizante.Caption = "Relátorio Enviado!"
            Liberado = 1
            Exit Sub
        End If
        
        If InStr(1, sBuffer, "#LoginTravado#") Then
            sBuffer = Replace(sBuffer, "#LoginTravado#", vbNullString)
            
            Dim Msgs() As String
            Msgs = Split(sBuffer, "#")
            
            Splash.Titulo.Caption = Msgs(0)
            Splash.MsgInfo.Caption = Msgs(1)
            Splash.Deslizante.Caption = Msgs(0)
            
            Splash.PB.Visible = False
            Splash.Titulo.Visible = True
            Splash.MsgInfo.Visible = True
            Splash.Fechar.Visible = True
            Splash.Deslizante.Visible = True
            Splash.Slide.Enabled = True
            
            Liberado = 1
            Exit Sub
        End If
        
        If InStr(1, sBuffer, "#LoginLiberado#") Then
            Dim splitSrc() As String
            splitSrc = Split(sBuffer, "#")
            
            MainExe = splitSrc(2)
            MainCmdLine = "connect /u" & splitSrc(3) & " /p" & splitSrc(4) & " " & ServerCmdLine

            Splash.PB.Visible = True
            Splash.Fechar.Visible = False
            Splash.Deslizante.Visible = False
            Splash.Deslizante.Caption = ""
            
            Splash.Slide.Enabled = False
            Splash.PBT.Enabled = True
        End If
End Sub
