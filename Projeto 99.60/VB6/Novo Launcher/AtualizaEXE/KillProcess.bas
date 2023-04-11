Attribute VB_Name = "KillProcess"
Option Explicit

Private Declare Function SendMessage Lib "user32" Alias "SendMessageA" (ByVal hWnd As Long, ByVal wMsg As Long, ByVal wParam As Long, ByVal lParam As Long) As Long
Private Declare Function ReleaseCapture Lib "user32" () As Long

Public Function FecharProcesso(ByVal processName As String)

    Dim oWMI As Object
    Dim oServices As Object
    Dim oService As Object
    Dim oWMIServices As Object
    Dim oWMIService As Object
   
    Dim Ret As Long
    Dim sService As String
    Dim servicename As String
   
    Set oWMI = GetObject("winmgmts:")
    Set oServices = oWMI.InstancesOf("win32_process")
   
    For Each oService In oServices
        servicename = LCase(Trim(CStr(oService.Name) & ""))
   
        If InStr(1, servicename, LCase(processName), vbTextCompare) > 0 Then
            Ret = oService.Terminate
        End If
    Next
   
    Set oServices = Nothing
    Set oWMI = Nothing
End Function
