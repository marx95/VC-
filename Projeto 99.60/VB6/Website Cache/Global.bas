Attribute VB_Name = "Global"
Global Contador(8) As Integer
Global Limite(8) As Integer
Global Ativado(8) As Integer
Global Link(8) As String
Global Atualizando(8) As Integer


Public Function SetarTempo(lol As Integer) As String

Dim horas As Integer
Dim minutos As Integer
Dim segundos As Integer

Dim hor As String
Dim min As String
Dim sec As String

horas = lol / 3600
minutos = (lol Mod 3600) / 60
segundos = (lol Mod 3600) Mod 60

hor = horas
min = minutos
sec = segundos

'If minutos = 1 Then minutos = 0
If Len(hor) = 1 Then hor = "0" & hor
If Len(min) = 1 Then min = "0" & min
If Len(sec) = 1 Then sec = "0" & sec

SetarTempo = hor & ":" & min & ":" & sec

End Function
