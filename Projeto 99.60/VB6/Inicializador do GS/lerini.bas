Attribute VB_Name = "Module1"
Public Declare Function WritePrivateProfileString Lib "kernel32" Alias "WritePrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpString As Any, ByVal lpFileName As String) As Long
Public Declare Function GetPrivateProfileString Lib "kernel32" Alias "GetPrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As Any, ByVal lpDefault As String, ByVal lpReturnedString As String, ByVal nSize As Long, ByVal lpFileName As String) As Long
Public Function ReadINI(ByVal FileName As String, ByVal Section As String, ByVal Key As String) As String
 Dim Ret As String, RetLen As Integer
 Ret = Space$(255)
 RetLen = GetPrivateProfileString(Section, Key, "", Ret, Len(Ret), FileName)
 Ret = Left$(Ret, RetLen)
 ReadINI = Ret
End Function
Public Sub WriteINI(FileName As String, Section As String, Key As String, Text As String)
    WritePrivateProfileString Section, Key, Text, FileName
End Sub



