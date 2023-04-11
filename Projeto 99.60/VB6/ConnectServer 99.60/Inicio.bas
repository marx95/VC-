Attribute VB_Name = "Inicio"
Public Sub Main()
    If Command = "Refresh" = False Then
        If App.PrevInstance = True Then End
    End If
    
    Dim TmpPathCS     As String
    Dim TmpRegCS      As String
    Dim PrecisaReiniciar    As Integer

    TmpPathCS = App.Path & "\" & App.EXEName & ".exe"
    TmpRegCS = GetSettingString(HKEY_CURRENT_USER, "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers", TmpPathCS)

    If Len(TmpRegCS) < Len("RUNASADMIN DisableNXShowUI") Then
        Call SaveSettingString(HKEY_CURRENT_USER, "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers", TmpPathCS, "RUNASADMIN DisableNXShowUI")
        PrecisaReiniciar = 1 ' - Atenção, somente o Launcher precisa ser reiniciado, atualiza.exe e antihack.exe são executados depois do launcher (Toda a vez)
    End If
    
    If PrecisaReiniciar = 1 Then
        On Error Resume Next
        Shell App.EXEName & ".exe " & Command, vbNormalFocus
        Call ExitProcess(0)
        Exit Sub
    End If
    
    If Command = "Refresh" Then
        Call AbrirLink
        Call ExitProcess(0)
    End If
    
    Dim mcrc As New CRC
    
    If mcrc.CRC(App.Path & "/MSWINSCK.OCX") <> "-574999508" Then
        MsgBox "O CS irá baixar o módulo Winsock, aguarde!", vbInformation, "Aviso"
        Call DownloadAFile(App.Path & "/MSWINSCK.OCX", "http://mujambalaya.xpg.com.br/MSWINSCK.rar", False, False)
    End If
    CS.Show
End Sub

