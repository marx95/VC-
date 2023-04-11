Attribute VB_Name = "threads"
Private Declare Function CreateThread Lib "kernel32" (lpThreadAttributes As Any, ByVal dwStackSize As Long, ByVal lpStartAddress As Long, lpParameter As Any, ByVal dwCreationFlags As Long, lpThreadID As Long) As Long
'Private Declare Function TerminateThread Lib "kernel32" (ByVal hThread As Long, ByVal dwExitCode As Long) As Long
'Public Declare Sub Sleep Lib "kernel32" (ByVal dwMilliseconds As Long)
'Private Declare Function CloseHandle Lib "kernel32" (ByVal hObject As Long) As Long

Global ThreadID(1000) As Long
Global uThread As Long

Public Function CriarThread() As Boolean
    uThread = uThread + 1
    
    ThreadID(uThread) = CreateThread(ByVal 0&, ByVal 0&, AddressOf PegarIP, ByVal 0&, ByVal 0&, 1)
End Function

Public Sub PegarIP()
    While True
        
        Sleep (9000)
   Wend
End Sub
