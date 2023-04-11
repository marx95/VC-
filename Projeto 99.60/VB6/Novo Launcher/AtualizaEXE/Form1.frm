VERSION 5.00
Begin VB.Form Atualizar 
   BackColor       =   &H00FFFFFF&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "MuMax - Atualizando..."
   ClientHeight    =   3000
   ClientLeft      =   45
   ClientTop       =   375
   ClientWidth     =   5250
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   3000
   ScaleWidth      =   5250
   StartUpPosition =   2  'CenterScreen
   Begin AtualizadorPj.jcbutton Fechar 
      Height          =   375
      Left            =   3720
      TabIndex        =   3
      Top             =   2520
      Width           =   1335
      _ExtentX        =   2355
      _ExtentY        =   661
      ButtonStyle     =   13
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BackColor       =   0
      Caption         =   "Fechar"
      PictureEffectOnOver=   0
      PictureEffectOnDown=   0
      CaptionEffects  =   0
      TooltipBackColor=   0
   End
   Begin VB.Timer Timer3 
      Enabled         =   0   'False
      Interval        =   250
      Left            =   1080
      Top             =   1800
   End
   Begin VB.Timer Timer2 
      Enabled         =   0   'False
      Interval        =   250
      Left            =   600
      Top             =   1800
   End
   Begin VB.Timer Timer1 
      Interval        =   150
      Left            =   120
      Top             =   1800
   End
   Begin VB.Label SiteCap 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "www.mumax.tk"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   120
      MouseIcon       =   "Form1.frx":1BB2
      MousePointer    =   99  'Custom
      TabIndex        =   4
      Top             =   2640
      Width           =   3495
   End
   Begin VB.Label Info 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   255
      Left            =   360
      TabIndex        =   2
      Top             =   1440
      Width           =   4455
   End
   Begin VB.Label Label2 
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "Aguarde"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   315
      Left            =   2280
      TabIndex        =   1
      Top             =   1440
      Width           =   1575
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      Caption         =   "Atualizando o Launcher.exe"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   285
      Left            =   285
      TabIndex        =   0
      Top             =   120
      Width           =   4635
   End
End
Attribute VB_Name = "Atualizar"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Fechar_Click()
    Call FecharAtualiza
End Sub

Private Sub Form_Load()
    Me.BackColor = &HFFFFFF
    If Command$ = vbNullString Or App.PrevInstance = True Then End

    While ProcessoExiste("Launcher.exe")
        Call FecharProcesso("Launcher.exe")
    Wend

    Me.Caption = "Atualizando..."
    Me.Width = 5340
    Me.Height = 3420

    Timer2.Enabled = True
End Sub

Private Sub SiteCap_Click()
    Call ShellExecute(Me.hWnd, vbNullString, "http://mumax.tk", vbNullString, vbNullString, 1)
End Sub

Private Sub Timer1_Timer()
    Pontos = Pontos + 1
    Label2.Caption = Label2.Caption & "."

    If Pontos > 4 Then
        Pontos = 0
        Label2.Caption = "Aguarde"
    End If
End Sub

Private Sub Timer2_Timer()
    Timer2.Enabled = False

    Call DownloadAFile(App.Path & "\NovoLauncher.rar", Command, False, False)
    Call RARExtract("NovoLauncher.rar", "")
    On Error Resume Next
    Call Kill("NovoLauncher.rar")

    Timer3.Enabled = True
End Sub

Private Sub Timer3_Timer()
    Dim ShellInfo As Integer
    Timer3.Enabled = False
    
    On Error Resume Next
    ShellInfo = ShellExecute(Me.hWnd, vbNullString, "Launcher.exe", vbNullString, vbNullString, 1)
    Select Case ShellInfo
    Case 2
        Info.Caption = "Falha ao abrir o Launcher.exe"
        Timer1.Enabled = False
        Label2.Caption = "Falha!"
        Exit Sub
        
    Case 42
        Call FecharAtualiza
    End Select
End Sub

Public Function FecharAtualiza()
        End
End Function
