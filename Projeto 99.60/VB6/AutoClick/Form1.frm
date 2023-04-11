VERSION 5.00
Begin VB.Form AutoClick 
   BorderStyle     =   0  'None
   Caption         =   "AutoClick"
   ClientHeight    =   735
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   2145
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   735
   ScaleWidth      =   2145
   ShowInTaskbar   =   0   'False
   StartUpPosition =   1  'CenterOwner
   Visible         =   0   'False
   Begin VB.Timer FecharAutoClick 
      Interval        =   1000
      Left            =   1560
      Top             =   120
   End
   Begin VB.Timer Delay 
      Enabled         =   0   'False
      Interval        =   500
      Left            =   600
      Top             =   120
   End
   Begin VB.Timer ClicarEsquerdo 
      Interval        =   45
      Left            =   1080
      Top             =   120
   End
   Begin VB.Timer Timer1 
      Enabled         =   0   'False
      Interval        =   50
      Left            =   120
      Top             =   120
   End
End
Attribute VB_Name = "AutoClick"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub ClicarEsquerdo_Timer()
If EsquerdoAtivado = 0 Then
    Exit Sub
End If

Call FicarClicandoEsquerdo
End Sub

Private Sub Delay_Timer()
    Delay.Enabled = False
    Timer1.Enabled = True
End Sub

Private Sub FecharAutoClick_Timer()
    If ProcessoExiste("Main.exe") = False Then End
End Sub

Private Sub Form_Load()
    If Command = vbNullString Or App.PrevInstance = True Or App.EXEName <> "AutoClick" Then End

    Topo = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "Topo")
    AutoClick_Ativado = GetSettingLong(HKEY_CURRENT_USER, "Software\Webzen\Mu\Config", "AutoClick")
    NomeJanela = Command
    AutoClick.Caption = "AutoClick do " & NomeJanela
    
    Timer1.Enabled = True
End Sub
Private Sub Timer1_Timer()
If JanelaID = 0 Then
    JanelaID = FindWindow(vbNullString, NomeJanela)
    Call ColocaNoTopo
End If

If AutoClick_Ativado = 0 Then End

While ApertarTeclas(vbKeyF7)
    Timer1.Enabled = False
    If EsquerdoAtivado = 0 Then
        EsquerdoAtivado = 1
        Delay.Enabled = True
        Exit Sub
    End If
    If EsquerdoAtivado = 1 Then
        EsquerdoAtivado = 0
        Delay.Enabled = True
        Exit Sub
    End If
Wend
'SendMessage JanelaID, WM_RBUTTONDOWN, 0, StrPtr(O)
While ApertarTeclas(vbKeyF8)
    Timer1.Enabled = False
    If DireitoAtivado = 0 Then
        DireitoAtivado = 1
        SendMessage JanelaID, WM_RBUTTONDOWN, 0, StrPtr(O)
        Delay.Enabled = True
        Exit Sub
    End If
    If DireitoAtivado = 1 Then
        DireitoAtivado = 0
        SendMessage JanelaID, WM_RBUTTONUP, 0, StrPtr(O)
        Delay.Enabled = True
        Exit Sub
    End If
Wend

While ApertarTeclas(vbKeyF9)
    Timer1.Enabled = False
    
    If JanelaEscondida = 0 Then
        Call EsconderJanela(0) ' - 0 para esconder
        JanelaEscondida = 1
        Delay.Enabled = True
        Exit Sub
    End If
    If JanelaEscondida = 1 Then
        Call EsconderJanela(1) ' - 1 para mostrar
        JanelaEscondida = 0
        Delay.Enabled = True
        Exit Sub
    End If
Wend

While ApertarTeclas(vbKeyF10)
    DireitoAtivado = 0
    SendMessage JanelaID, WM_RBUTTONUP, 0, StrPtr(O) ' - desativa direito
    EsquerdoAtivado = 0
Wend
End Sub
