Attribute VB_Name = "Modulo_Launcher"
Public Function Aparece()
Launcher.txt(0).Visible = True
Launcher.Combo1.Visible = True
Launcher.Combo2.Visible = True
Launcher.Combo3.Visible = True
Launcher.ScrollB.Visible = True

Launcher.PictureButton1.Visible = False
Launcher.PictureButton2.Visible = False
Launcher.PictureButton5.Visible = True
Launcher.m_WebControl.Visible = False
    
For i = 1 To 17
    Launcher.Lb(i).Visible = True
Next i

For i = 0 To 4
    Launcher.Ck(i).Visible = True
Next i
End Function

Public Function Some()
Launcher.txt(0).Visible = False
Launcher.Combo1.Visible = False
Launcher.Combo2.Visible = False
Launcher.Combo3.Visible = False
Launcher.ScrollB.Visible = False

Launcher.PictureButton1.Visible = True
Launcher.PictureButton2.Visible = True
Launcher.PictureButton5.Visible = False
    
For i = 1 To 17
    Launcher.Lb(i).Visible = False
Next i

For i = 0 To 4
    Launcher.Ck(i).Visible = False
Next i

If ErroNoNavegador = 0 Then
    Launcher.m_WebControl.Visible = True
End If
End Function

Public Function Carregar()
    On Error GoTo Erro1
    Launcher.txt(0).Text = GetSettingString(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "ID")

    On Error GoTo Erro1
    Launcher.Ck(0).Value = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "SoundOnOff")
    
    On Error GoTo Erro1
    Launcher.Ck(1).Value = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "MusicOnOff")
    
    On Error GoTo Erro1
    Launcher.Ck(2).Value = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "WindowMode")
    
    On Error GoTo Erro1
    Launcher.Ck(3).Value = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "Topo")

    On Error GoTo Erro1
    Launcher.Ck(4).Value = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "AutoClick")

    'On Error GoTo Erro1
    'Launcher.Combo1.ListIndex = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "Resolution")

    On Error GoTo Erro1
    Launcher.Combo2.ListIndex = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "ColorDepth")

    On Error GoTo Erro1
    Launcher.ScrollB.Value = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "VolumeLevel")
    
    On Error Resume Next
    Launcher.Lb(16).Caption = (Launcher.ScrollB.Value * 10) & "%"

    On Error GoTo Erro1
    Launcher.Combo3.Text = ReadINI(App.Path & "/Config.ini", "Config", "Tamanho_da_Fonte")
    
    ' - Resoluçoes
    If Screen.Width = (ReadINI(App.Path & "/Config.ini", "Config", "Width") * 15) And Screen.Height = (ReadINI(App.Path & "/Config.ini", "Config", "Height") * 15) Then
        Launcher.Combo1.Text = "AutoSize"
    Else
        On Error GoTo Erro1
        Launcher.Combo1.Text = ReadINI(App.Path & "/Config.ini", "Config", "Width") & "x" & ReadINI(App.Path & "/Config.ini", "Config", "Height")
    End If
    
    Exit Function

Erro1:
    Call ConfigSegura
    Call Carregar
End Function

Public Function ConfigSegura()
    Call SaveSettingString(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "ID", "")
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "SoundOnOff", 0)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "MusicOnOff", 0)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "WindowMode", 0)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "Topo", Launcher.Ck(3).Value)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "AutoClick", 1)
    'Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "Resolution", 1)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "ColorDepth", 1)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "VolumeLevel", 3)
    
    ' - Sistema de Resoluçao
    Call WriteINI(App.Path & "/Config.ini", "Config", "Width", "800")
    Call WriteINI(App.Path & "/Config.ini", "Config", "Height", "600")
    Call WriteINI(App.Path & "/Config.ini", "Config", "Tamanho_da_Fonte", "12")
End Function

Public Function Salvar()
    Call SaveSettingString(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "ID", Launcher.txt(0).Text)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "SoundOnOff", Launcher.Ck(0).Value)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "MusicOnOff", Launcher.Ck(1).Value)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "WindowMode", Launcher.Ck(2).Value)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "Topo", Launcher.Ck(3).Value)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "AutoClick", Launcher.Ck(4).Value)
    'Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "Resolution", Launcher.Combo1.ListIndex)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "ColorDepth", Launcher.Combo2.ListIndex)
    Call SaveSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "VolumeLevel", Launcher.ScrollB.Value)
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
End Function

