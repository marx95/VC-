VERSION 5.00
Begin VB.Form Splash 
   BorderStyle     =   0  'None
   Caption         =   "MuMax"
   ClientHeight    =   6405
   ClientLeft      =   0
   ClientTop       =   0
   ClientWidth     =   10230
   Icon            =   "Splash.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   Picture         =   "Splash.frx":1BB2
   ScaleHeight     =   6405
   ScaleWidth      =   10230
   StartUpPosition =   2  'CenterScreen
   Begin VB.Timer Start 
      Enabled         =   0   'False
      Interval        =   250
      Left            =   6840
      Top             =   240
   End
   Begin VB.Timer PBT 
      Enabled         =   0   'False
      Interval        =   50
      Left            =   6360
      Top             =   240
   End
   Begin VB.Timer Slide 
      Enabled         =   0   'False
      Interval        =   50
      Left            =   5880
      Top             =   240
   End
   Begin MuMaxAH.Progressbar_user PB 
      Height          =   255
      Left            =   480
      TabIndex        =   1
      Top             =   3480
      Visible         =   0   'False
      Width           =   4695
      _ExtentX        =   8281
      _ExtentY        =   450
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BrushStyle      =   0
      Color           =   192
      Scrolling       =   9
   End
   Begin MuMaxAH.jcbutton Fechar 
      Height          =   300
      Left            =   4440
      TabIndex        =   0
      Top             =   3520
      Visible         =   0   'False
      Width           =   855
      _ExtentX        =   1508
      _ExtentY        =   529
      ButtonStyle     =   10
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BackColor       =   192
      Caption         =   "Fechar"
      ForeColor       =   16777215
      ForeColorHover  =   4210752
      MousePointer    =   99
      MouseIcon       =   "Splash.frx":69A74
      PictureEffectOnOver=   0
      PictureEffectOnDown=   0
      CaptionEffects  =   0
      TooltipBackColor=   0
      ColorScheme     =   3
   End
   Begin VB.Label Deslizante 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Info"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   195
      Left            =   480
      TabIndex        =   5
      Top             =   2640
      Visible         =   0   'False
      Width           =   345
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "Atenção: O uso de Hack's ou a Modificação ilegal do Cliente pode causar o cancelamento de sua conta!"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   495
      Left            =   480
      TabIndex        =   4
      Top             =   3000
      Width           =   4695
   End
   Begin VB.Label MsgInfo 
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   855
      Left            =   480
      TabIndex        =   3
      Top             =   1560
      Visible         =   0   'False
      Width           =   4815
   End
   Begin VB.Label Titulo 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "Titulo_Test"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   15.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   495
      Left            =   480
      TabIndex        =   2
      Top             =   960
      Visible         =   0   'False
      Width           =   4815
   End
End
Attribute VB_Name = "Splash"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Fechar_Click()
    If Liberado = 0 Then Exit Sub
    End
End Sub

Public Function Mover(Botao As Integer, FormHwnd As Long) As Long
    If Botao = 1 Then
        Call ReleaseCapture
        Mover = SendMessage(FormHwnd, WM_NCLBUTTONDOWN, HTCAPTION, 0&)
    End If
End Function

Private Sub Form_Load()
    Teste = False
    
    If Teste = False Then
        If App.EXEName <> "AntiHack" Then
            MsgBox "AntiHack.exe foi renomeado!", vbExclamation, "Erro"
            End
        End If
    End If
    
    ServerCmdLine = "AH_MarxD" ' - Para acessar o AntiHack.exe e Pagina do AntiHack
    MainCmdLine = "" ' - Definido na antihack.php
    MainExe = "" ' - Definido na antihack.php
    
    If InStr(1, Command, ServerCmdLine) = False Then End
    
    Me.Width = 380 * 15
    Me.Height = 280 * 15
    PB.Scrolling = 9
    PB.Color = &HC0&
    Fechar.BackColor = &HC0&
    
    Fechar.Visible = True
    Deslizante.Caption = "Conectando ao servidor..."
    Deslizante.Visible = True
    Slide.Enabled = True
    
    Start.Enabled = True
End Sub

Public Sub IniciarJogo()
    PBT.Enabled = False
    
    If 2 = (ShellExecute(Me.hWnd, vbNullString, MainExe, MainCmdLine, vbNullString, 1)) Then
        MsgBox "Falha ao executar o jogo!" + vbNewLine + "Abra o Launcher e espere atualizar.", vbExclamation, "Ocorreu um Erro!"
    End If

    End
End Sub

Private Sub PBT_Timer()
    PB.Visible = True
    
    If PB.Value < 85 Then
        PB.Value = PB.Value + 6
    Else
        If PB.Value < 100 Then PB.Value = PB.Value + 1
    End If
    
    If PB.Value = 100 Then Call IniciarJogo
End Sub

Private Sub Slide_Timer()
    If (Deslizante.Left + Deslizante.Width) >= 5160 Then Deslizante.Left = 480
    Deslizante.Left = Deslizante.Left + 50
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Call Mover(Button, hWnd)
End Sub

Private Sub Start_Timer()
    Start.Enabled = False
    
    Dim CommandLine() As String
    Dim mcrc As New CRC
    
    Dim CRC_A As String
    Dim CRC_B As String
    Dim CRC_C As String
    
    CRC_A = Replace(mcrc.CRC(App.Path & "/Main.dll"), "-", vbNullString)
    CRC_B = Replace(mcrc.CRC(App.Path & "/AntiHack.exe"), "-", vbNullString)
    CRC_C = Replace(mcrc.CRC(App.Path & "/Main.exe"), "-", vbNullString)
    
    CommandLine = Split(Command, "#")
    Liberado = 0
    Funcao = CommandLine(1)
    
    Select Case Funcao
        Case 0
            Liberado = 1
            Call AbrirLink("http://pgcontrol.com.br/muonline/site/antihack.php?f=0&crc=" & CRC_A & "|" & CRC_B & "|" & CRC_C)
        Case 1
            CmdTitulo = CommandLine(2)
            CmdMsgInfo = CommandLine(3)
            CmdDetectado = CommandLine(4)
            
            Deslizante.Visible = True
            Deslizante.Caption = "Enviando relatório..."
            Slide.Enabled = True
            
            Titulo.Visible = True
            Titulo.Caption = CmdTitulo
            
            MsgInfo.Visible = True
            MsgInfo.Caption = CmdMsgInfo
            
            Call AbrirLink("http://pgcontrol.com.br/muonline/site/antihack.php?f=1&detectado=" & CmdDetectado)
            Fechar.Visible = True
    End Select
End Sub

Private Sub Titulo_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Call Mover(Button, hWnd)
End Sub

Private Sub Deslizante_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Call Mover(Button, hWnd)
End Sub

Private Sub Label1_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Call Mover(Button, hWnd)
End Sub

Private Sub MsgInfo_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
    Call Mover(Button, hWnd)
End Sub
