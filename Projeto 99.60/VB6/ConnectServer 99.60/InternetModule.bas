Attribute VB_Name = "InternetModule"
Const scUserAgent = "API-Guide test program"
Const INTERNET_OPEN_TYPE_DIRECT = 1
Const INTERNET_OPEN_TYPE_PROXY = 3
Const INTERNET_FLAG_RELOAD = &H80000000

Public Declare Function InternetOpen Lib "wininet" Alias "InternetOpenA" (ByVal sAgent As String, ByVal lAccessType As Long, ByVal sProxyName As String, ByVal sProxyBypass As String, ByVal lFlags As Long) As Long
Public Declare Function InternetCloseHandle Lib "wininet" (ByVal hInet As Long) As Integer
Public Declare Function InternetReadFile Lib "wininet" (ByVal hFile As Long, ByVal sBuffer As String, ByVal lNumBytesToRead As Long, lNumberOfBytesRead As Long) As Integer
Public Declare Function InternetOpenUrl Lib "wininet" Alias "InternetOpenUrlA" (ByVal hInternetSession As Long, ByVal lpszUrl As String, ByVal lpszHeaders As String, ByVal dwHeadersLength As Long, ByVal dwFlags As Long, ByVal dwContext As Long) As Long

Public Sub AbrirLink()
    Dim hOpen As Long
    Dim hFile As Long
    Dim sBuffer As String
    Dim ret As Long
    Dim slink As String
    
    slink = ReadINI(App.Path & "/Config.ini", "Config", "URL_IP")
    sBuffer = Space(1024) 'Create a buffer for the file we're going to download
    hOpen = InternetOpen(scUserAgent, INTERNET_OPEN_TYPE_DIRECT, vbNullString, vbNullString, 0) 'Create an internet connection
    hFile = InternetOpenUrl(hOpen, slink, vbNullString, ByVal 0&, INTERNET_FLAG_RELOAD, ByVal 0&) 'Open the url
    InternetReadFile hFile, sBuffer, 1024, ret 'Read the first 1000 bytes of the file
    InternetCloseHandle hFile 'clean up
    InternetCloseHandle hOpen 'clean up
    sBuffer = LCase(sBuffer)
    
    Dim tmpIP() As String
    tmpIP = Split(sBuffer, "#")
    'Sala_IP = tmpIP(1)
    'Sala_Porta = tmpIP(2)
    
    Call WriteINI(App.Path & "\Config.ini", "Config", "IP_da_Sala", " " & tmpIP(1))
    Call WriteINI(App.Path & "\Config.ini", "Config", "Porta_da_Sala", " " & tmpIP(2))
    Call WriteINI(App.Path & "\Config.ini", "Config", "Ultimo_Refresh", " " & Now)
    Call WriteINI(App.Path & "\Config.ini", "Config", "Total_On", " " & tmpIP(3))
End Sub
