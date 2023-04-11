Attribute VB_Name = "AutoClick"
Public Declare Sub mouse_event Lib "user32" (ByVal dwFlags As Long, ByVal dx As Long, ByVal dy As Long, ByVal cButtons As Long, ByVal dwExtraInfo As Long)
Public Declare Function SetCursorPos Lib "user32" (ByVal X As Long, ByVal Y As Long) As Long
Public Declare Function GetCursorPos Lib "user32" (lpPoint As POINTAPI) As Long
Public Const MOUSEEVENTF_LEFTDOWN = &H2
Public Const MOUSEEVENTF_LEFTUP = &H4
Public Const MOUSEEVENTF_MIDDLEDOWN = &H20
Public Const MOUSEEVENTF_MIDDLEUP = &H40
Public Const MOUSEEVENTF_RIGHTDOWN = &H8
Public Const MOUSEEVENTF_RIGHTUP = &H10
Public Const MOUSEEVENTF_MOVE = &H1
Public Type POINTAPI
X As Long
Y As Long
End Type

Public Function GetX() As Long
Dim n As POINTAPI
GetCursorPos n
GetX = n.X
End Function

Public Function GetY() As Long
Dim n As POINTAPI
GetCursorPos n
GetY = n.Y
End Function

Public Sub LeftClick()
LeftDown
LeftUp
End Sub

Public Sub LeftDown()
mouse_event MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0
End Sub

Public Sub LeftUp()
mouse_event MOUSEEVENTF_LEFTUP, 0, 0, 0, 0
End Sub

Public Sub MiddleClick()
MiddleDown
MiddleUp
End Sub

Public Sub MiddleDown()
mouse_event MOUSEEVENTF_MIDDLEDOWN, 0, 0, 0, 0
End Sub

Public Sub MiddleUp()
mouse_event MOUSEEVENTF_MIDDLEUP, 0, 0, 0, 0
End Sub

Public Sub RightClick()
RightDown
RightUp
End Sub

Public Sub RightDown()
mouse_event MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0

End Sub

Public Sub RightUp()
mouse_event MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0
End Sub

Public Sub MoveMouse(xMove As Long, yMove As Long)
mouse_event MOUSEEVENTF_MOVE, xMove, yMove, 0, 0
End Sub

Public Sub SetMousePos(xPos As Long, yPos As Long)
SetCursorPos xPos, yPos
End Sub

