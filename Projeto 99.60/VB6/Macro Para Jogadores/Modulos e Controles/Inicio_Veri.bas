Attribute VB_Name = "Inicio_Veri"
Public Sub Main()
    Teste = False
    
    If Teste = False Then
        If App.EXEName <> "MacroMuNovus" Then
            MsgBox "O Executavel foi renomeado!", vbCritical, "Ocorreu um Erro!"
            End
        End If
    End If
    
    If Command = "reiniciar" Then
        Call Sleep(250)
    Else
        If App.PrevInstance Then End
    End If
    
    Dim TmpPathMacro As String
    Dim TmpRegMacro As String
    Dim Reiniciar As Integer
    
    TmpPathMacro = App.Path & "\MacroMuNovus.exe"
    TmpRegMacro = GetSettingString(HKEY_CURRENT_USER, "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers", TmpPathMacro)

    If Len(TmpRegMacro) < Len("RUNASADMIN DisableNXShowUI") Then
        Call SaveSettingString(HKEY_CURRENT_USER, "Software\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers", TmpPathMacro, "RUNASADMIN DisableNXShowUI")
        Reiniciar = 1
    End If
    
    If Teste = False Then
        If Reiniciar = 1 Then
            Call Shell("MacroMuNovus.exe reiniciar", vbNormalFocus)
            Call ExitProcess(0)
            Exit Sub
        End If
    End If
    
    Inicio.Visible = True
End Sub
