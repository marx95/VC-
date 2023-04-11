Attribute VB_Name = "Funcs_Noticias"
Public Sub Carregar()
    On Error GoTo Erro1
    Launcher.Login.Text = GetSettingString(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "ID")

    On Error GoTo Erro1
    Launcher.Check1.Value = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "SoundOnOff")
    
    On Error GoTo Erro1
    Launcher.Check2.Value = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "MusicOnOff")
    
    On Error GoTo Erro1
    Launcher.Check3.Value = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "WindowMode")
    
    'On Error GoTo Erro1
    'launcher.Check4.Value = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "Topo")

    On Error GoTo Erro1
    Launcher.Check4.Value = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "AutoClick")

    'On Error GoTo Erro1
    'Launcher.Combo1.ListIndex = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "Resolution")

    On Error GoTo Erro1
    Launcher.Combo2.ListIndex = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "ColorDepth")

    On Error GoTo Erro1
    Launcher.Volume.Value = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "VolumeLevel")
    
    On Error Resume Next
    Launcher.Label10.Caption = (Launcher.Volume.Value * 10) & "%"

    On Error GoTo Erro1
    Launcher.Combo3.Text = ReadINI(App.Path & "/Config.ini", "Config", "Tamanho_da_Fonte")
    
    ' - Resoluçoes
    If Screen.Width = (ReadINI(App.Path & "/Config.ini", "Config", "Width") * 15) And Screen.Height = (ReadINI(App.Path & "/Config.ini", "Config", "Height") * 15) Then
        Launcher.Combo1.Text = "AutoSize"
    Else
        On Error GoTo Erro1
        Launcher.Combo1.Text = ReadINI(App.Path & "/Config.ini", "Config", "Width") & "x" & ReadINI(App.Path & "/Config.ini", "Config", "Height")
    End If
    
    Exit Sub

Erro1:
    MsgBox "Ocorreu um erro nas configurações! Foi setado as configurações seguras!", vbCritical, "ERRO!"
    Call ConfigSegura
    Call Carregar
End Sub

Public Sub ConfigSegura()
    Call SaveSettingString(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "ID", "")
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "SoundOnOff", 0)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "MusicOnOff", 0)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "WindowMode", 1)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "Topo", 0)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "AutoClick", 1)
    'Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "Resolution", 1)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "ColorDepth", 1)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "VolumeLevel", 3)
    
    ' - Sistema de Resoluçao
    Call WriteINI(App.Path & "/Config.ini", "Config", "Width", "800")
    Call WriteINI(App.Path & "/Config.ini", "Config", "Height", "600")
    Call WriteINI(App.Path & "/Config.ini", "Config", "Tamanho_da_Fonte", "12")
End Sub

Public Sub Salvar()
    Call SaveSettingString(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "ID", Launcher.Login.Text)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "SoundOnOff", Launcher.Check1.Value)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "MusicOnOff", Launcher.Check2.Value)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "WindowMode", Launcher.Check3.Value)
    'Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "Topo", Launcher.Ck(3).Value)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "AutoClick", Launcher.Check4.Value)
    'Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "Resolution", Launcher.Combo1.ListIndex)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "ColorDepth", Launcher.Combo2.ListIndex)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "VolumeLevel", Launcher.Volume.Value)
    Call WriteINI(App.Path & "/Config.ini", "Config", "Tamanho_da_Fonte", Launcher.Combo3.Text)
    
    ' - Sistema de resoluçao
    If Launcher.Combo1.Text = "AutoSize" Then
        Call WriteINI(App.Path & "/Config.ini", "Config", "Width", (Screen.Width / 15))
        Call WriteINI(App.Path & "/Config.ini", "Config", "Height", (Screen.Height / 15))
    Else
        Dim Resolucao() As String
        Resolucao = Split(Launcher.Combo1.Text, "x")
        Call WriteINI(App.Path & "/Config.ini", "Config", "Width", Resolucao(0))
        Call WriteINI(App.Path & "/Config.ini", "Config", "Height", Resolucao(1))
    End If
End Sub
