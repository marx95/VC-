VERSION 5.00
Begin VB.Form Inicializador 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Form1"
   ClientHeight    =   1095
   ClientLeft      =   45
   ClientTop       =   375
   ClientWidth     =   6375
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   1095
   ScaleWidth      =   6375
   StartUpPosition =   2  'CenterScreen
   Visible         =   0   'False
   Begin VB.Timer Timer2 
      Enabled         =   0   'False
      Interval        =   2000
      Left            =   5400
      Top             =   120
   End
   Begin VB.Timer Timer1 
      Enabled         =   0   'False
      Interval        =   500
      Left            =   5880
      Top             =   120
   End
   Begin VB.Label Label1 
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
      Width           =   6135
   End
End
Attribute VB_Name = "Inicializador"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Load()
     
    If Len(Command) > 4 Then
        Dim Ultimo As Long
        Ultimo = CLng(ReadINI(App.Path & "/Logs.ini", "Logs", "Total")) + 1
        Call WriteINI(App.Path & "/Logs.ini", "Logs", "Total", (" " & Ultimo))
        Call WriteINI(App.Path & "/Logs.ini", "Logs", ("" & Ultimo), " [" & Now & "] " & Replace(Command, "##", vbNullString))
        Call ExitProcess(0)
    End If
    
    Dim Licenca As String
    Licenca = ReadINI(App.Path & "/Iniciar.ini", "Config", "Licenca ")
    
    Porta_JoinServer = ReadINI(App.Path & "/Iniciar.ini", "Portas", "JoinServer")
    Porta_DataServer = ReadINI(App.Path & "/Iniciar.ini", "Portas", "DataServer")
    Porta_GameServer = ReadINI(App.Path & "/Iniciar.ini", "Portas", "GameServer")
    IP_JoinServer = ReadINI(App.Path & "/Iniciar.ini", "IPs", "JoinServer")
    IP_DataServer = ReadINI(App.Path & "/Iniciar.ini", "IPs", "DataServer")
    
    Me.Caption = "GameServer 0.99.60T do MarxD"
    Me.Visible = True
    Timer1.Interval = 650
    Timer1.Enabled = True
    
    If InStr(1, Command, "pular") Then
        Timer2.Enabled = True
        Exit Sub
    End If
    
    Label1.Caption = "Licença: " & Licenca
    DoEvents
    
    If AbrirLink("http://pgcontrol.com.br/licenca_gs.php?c=" & Licenca) = False Then
        MsgBox "Licença inválida!" & vbNewLine & "Compre ou Renove a Licença do GS!", vbCritical, "O GameServer não pode ser iniciado!"
        Call ExitProcess(0)
    End If
    
    Timer2.Enabled = True
End Sub

Private Sub Timer1_Timer()
    Select Case Len(Me.Caption)
    Case 50
        Me.Caption = "GameServer 0.99.60T do MarxD - Verificando Licença."
    Case 51
        Me.Caption = "GameServer 0.99.60T do MarxD - Verificando Licença.."
    Case 52
        Me.Caption = "GameServer 0.99.60T do MarxD - Verificando Licença..."
    Case Else
       Me.Caption = "GameServer 0.99.60T do MarxD - Verificando Licença"
    End Select
End Sub

Private Sub Timer2_Timer()
    Dim GSCmdLine As String
    Dim ShellInfo As Integer
    
    GSCmdLine = IP_JoinServer & " " & Porta_JoinServer & " " & IP_DataServer & " " & Porta_DataServer & " " & Porta_GameServer & " 282ea683f79392f56b663c7ea4f26cb4"
    ShellInfo = ShellExecute(Inicializador.hWnd, vbNullString, "GameServer.exe", GSCmdLine, vbNullString, 1)
    
    If ShellInfo = 2 Then MsgBox "Falha ao executar o GameServer.exe", vbCritical, "Ocorreu um erro!"
    Call ExitProcess(0)
End Sub
