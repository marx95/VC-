VERSION 5.00
Begin VB.Form Inicio 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Macro Divulgador - Equipe MuNovus.net"
   ClientHeight    =   1935
   ClientLeft      =   45
   ClientTop       =   375
   ClientWidth     =   5775
   Icon            =   "Inicio.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1935
   ScaleWidth      =   5775
   StartUpPosition =   2  'CenterScreen
   Begin VB.Timer Timer1 
      Enabled         =   0   'False
      Interval        =   50
      Left            =   360
      Top             =   240
   End
   Begin MacroMuNovus.jcbutton jcbutton1 
      Height          =   375
      Left            =   3720
      TabIndex        =   4
      Top             =   960
      Visible         =   0   'False
      Width           =   1695
      _ExtentX        =   2990
      _ExtentY        =   661
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
      BackColor       =   16765357
      Caption         =   "jcbutton"
      MousePointer    =   99
      MouseIcon       =   "Inicio.frx":138CA
      PictureEffectOnOver=   0
      PictureEffectOnDown=   0
      CaptionEffects  =   0
      TooltipBackColor=   0
   End
   Begin VB.TextBox Text1 
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   395
      Left            =   1560
      TabIndex        =   3
      Top             =   960
      Visible         =   0   'False
      Width           =   2055
   End
   Begin MacroMuNovus.Progressbar_user PB 
      Height          =   255
      Left            =   120
      TabIndex        =   1
      Top             =   1560
      Visible         =   0   'False
      Width           =   5535
      _ExtentX        =   9763
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
      Color           =   16750899
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "Seu Login:"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   285
      Left            =   240
      TabIndex        =   2
      Top             =   1005
      Visible         =   0   'False
      Width           =   1140
   End
   Begin VB.Label Status 
      Alignment       =   2  'Center
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   14.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   495
      Left            =   120
      TabIndex        =   0
      Top             =   240
      Width           =   5535
   End
End
Attribute VB_Name = "Inicio"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Function Baixar_OCX()
    Tamanho = 3979680
    Status.Caption = "Baixando Flash10c.ocx - 4MB"
    DoEvents
    Call DownloadAFile(App.Path & "\Flash10c.ocx", "http://munovus.net/arquivos/Flash10c.ocx", True)
    DoEvents
End Function

Private Function Baixar_TXTDV()
    Status.Caption = "Baixando Mensagens..."
    DoEvents
    
    On Error Resume Next
    Call Kill(App.Path & "\msgdv.txt")
    
    Call DownloadAFile(App.Path & "\msgdv.txt", "http://munovus.net/macro/msg_macro_staff.txt", False)
    
    If Len(Dir(App.Path & "\msgdv.txt")) = 0 Then
        MsgBox "Falha ao baixar informações!", vbCritical, "Erro!"
        Call ExitProcess(0)
    Else
        Dim TmpMsgDv() As String
        Open App.Path & "\msgdv.txt" For Input As #1
            Dim TmpMsgs As String
            TmpMsgs = Replace(Input(FileLen(App.Path & "\msgdv.txt"), #1), vbNewLine, vbNullString)
            TmpMsgDv() = Split(TmpMsgs, """")
        Close #1
        
        For i = 0 To UBound(TmpMsgDv)
            If Len(TmpMsgDv(i)) > 4 Then
                MsgDV(MsgMax) = TmpMsgDv(i)
                MsgMax = MsgMax + 1
            End If
        Next i
        MsgMax = MsgMax - 1
    End If
    
    On Error Resume Next
    Call Kill(App.Path & "\msgdv.txt")
End Function

Private Sub Form_Load()
    Timer1.Enabled = True
End Sub

Private Sub jcbutton1_Click()
    If Len(Text1.Text) < 4 Then
        MsgBox "Login inválido!", vbCritical, "Erro!"
        Exit Sub
    End If
    
    Login = Text1.Text
    Me.Visible = False
    Macro.Show
End Sub

Private Sub Timer1_Timer()
    Timer1.Enabled = False
    
    Dim mcrc As New CRC
    If mcrc.CRC(App.Path & "\Flash10c.ocx") <> "-3295212959" Then Call Baixar_OCX
    
    Call Baixar_TXTDV
    
    Status.Caption = "Dígite seu Login"
    jcbutton1.Caption = "Logar"
    
    PB.Visible = False
    Label1.Visible = True
    Text1.Visible = True
    jcbutton1.Visible = True
    Text1.SetFocus
End Sub
