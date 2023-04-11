Attribute VB_Name = "Inicio_Verificacoes"
Public Sub Main()
    If App.EXEName <> "Launcher" Then
        MsgBox "O executavel do Launcher foi renomeado!", vbCritical, "Ocorreu um erro!"
        Call Fechar
        Exit Sub
    End If
    
    If App.PrevInstance = True Then
        Dim erro As Integer
        erro = 1
        If Command = "reiniciar" Then erro = 0
        If Command = "sonsmusicas" Then erro = 0
        
        If erro = 1 Then
            MsgBox "O Launcher já está em execução!", vbCritical, "Ocorreu um erro!"
            Call Fechar
            Exit Sub
        End If
    End If

    If Command = "reiniciar" Then
        Dim Tent As Integer
        Tent = 0
        While ProcessoExiste("Atualiza.exe") = True
            Tent = Tent + 1
            If Tent > 100 Then
                MsgBox "Falha ao fechar o Atualiza.exe", vbCritical, "Ocorreu um erro!"
                Call Fechar
                Exit Sub
            End If
            
            Call KillProcess("Atualiza.exe")
            Call Sleep(50)
        Wend
    End If
    
    Call VerificaAdminDep
    Call VerProcessos
    Call Launcher.Show
End Sub

Private Sub VerificaAdminDep()
    Dim TmpPathLauncher     As String
    Dim TmpPathAtualiza     As String
    Dim TmpPathAntiHack     As String
    Dim TmpPathMain         As String

    Dim TmpRegLauncher      As String
    Dim TmpRegAtualiza      As String
    Dim TmpRegAntiHack      As String
    Dim TmpRegMain          As String
    Dim PrecisaReiniciar    As Integer

    TmpPathLauncher = App.Path & "\Launcher.exe"
    TmpPathAtualiza = App.Path & "\Atualiza.exe"
    TmpPathAntiHack = App.Path & "\AntiHack.exe"
    TmpPathMain = App.Path & "\Main.exe"

    TmpRegLauncher = GetSettingString(HKEY_CURRENT_USER, "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers", TmpPathLauncher)
    TmpRegAtualiza = GetSettingString(HKEY_CURRENT_USER, "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers", TmpPathAtualiza)
    TmpRegAntiHack = GetSettingString(HKEY_CURRENT_USER, "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers", TmpPathAntiHack)
    TmpRegMain = GetSettingString(HKEY_CURRENT_USER, "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers", TmpPathMain)

    If Len(TmpRegLauncher) < Len("RUNASADMIN DisableNXShowUI") Then
        Call SaveSettingString(HKEY_CURRENT_USER, "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers", TmpPathLauncher, "RUNASADMIN DisableNXShowUI")
        PrecisaReiniciar = 1 ' - Atenção, somente o Launcher precisa ser reiniciado, atualiza.exe e antihack.exe são executados depois do launcher (Toda a vez)
    End If

    If Len(TmpRegAtualiza) < Len("RUNASADMIN DisableNXShowUI") Then
        Call SaveSettingString(HKEY_CURRENT_USER, "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers", TmpPathAtualiza, "RUNASADMIN DisableNXShowUI")
    End If

    If Len(TmpRegAntiHack) < Len("RUNASADMIN DisableNXShowUI") Then
        Call SaveSettingString(HKEY_CURRENT_USER, "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers", TmpPathAntiHack, "RUNASADMIN DisableNXShowUI")
    End If

    If Len(TmpRegMain) < Len("RUNASADMIN DisableNXShowUI") Then
        Call SaveSettingString(HKEY_CURRENT_USER, "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers", TmpPathMain, "RUNASADMIN DisableNXShowUI")
    End If
    
    If PrecisaReiniciar = 1 Then
        Call ReiniciarLauncher
        Exit Sub
    End If
End Sub

Private Sub ReiniciarLauncher()
    'Call ShellExecute(Me.hWnd, vbNullString, App.EXEName & ".exe", "reiniciar", vbNullString, 0)
    Call MsgBox("O Launcher será Reiniciado!" + vbNewLine + "Caso não reinicie sozinho, reabra pelo Atalho.", vbInformation, "Aviso")
    Shell "Launcher.exe reiniciar", vbNormalFocus
    Call Fechar
End Sub

Public Sub VerProcessos()
    If ProcessoExiste("Main.exe") Then Call KillProcess("Main.exe")
    If ProcessoExiste("AutoClick.exe") Then Call KillProcess("AutoClick.exe")
    If ProcessoExiste("Atualiza.exe") Then Call KillProcess("Atualiza.exe")
End Sub

