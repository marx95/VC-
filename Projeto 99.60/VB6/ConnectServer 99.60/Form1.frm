VERSION 5.00
Object = "{248DD890-BB45-11CF-9ABC-0080C7E7B78D}#1.0#0"; "MSWINSCK.OCX"
Begin VB.Form CS 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "ConnectServer do MuNovus.net @ MarxD"
   ClientHeight    =   4455
   ClientLeft      =   45
   ClientTop       =   375
   ClientWidth     =   7335
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4455
   ScaleWidth      =   7335
   StartUpPosition =   2  'CenterScreen
   Begin VB.Timer Timer_Estado 
      Interval        =   1000
      Left            =   960
      Top             =   720
   End
   Begin VB.Timer RefreshShellTimer 
      Enabled         =   0   'False
      Interval        =   50
      Left            =   480
      Top             =   720
   End
   Begin Project1.jcbutton RecarregarIP 
      Height          =   375
      Left            =   3720
      TabIndex        =   3
      Top             =   120
      Width           =   3495
      _ExtentX        =   6165
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
      Caption         =   "Recarregar IP via URL"
      MousePointer    =   99
      MouseIcon       =   "Form1.frx":1BB2
      PictureEffectOnOver=   0
      PictureEffectOnDown=   0
      CaptionEffects  =   0
      TooltipBackColor=   0
   End
   Begin VB.Timer RefreshTimer 
      Enabled         =   0   'False
      Interval        =   50
      Left            =   0
      Top             =   720
   End
   Begin Project1.jcbutton RecarregarC 
      Height          =   375
      Left            =   120
      TabIndex        =   2
      Top             =   120
      Width           =   3495
      _ExtentX        =   6165
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
      Caption         =   "Recarregar Configurações"
      MousePointer    =   99
      MouseIcon       =   "Form1.frx":1ECC
      PictureEffectOnOver=   0
      PictureEffectOnDown=   0
      CaptionEffects  =   0
      TooltipBackColor=   0
   End
   Begin VB.ListBox Erros 
      Appearance      =   0  'Flat
      Height          =   3735
      Left            =   3720
      TabIndex        =   1
      Top             =   600
      Width           =   3495
   End
   Begin VB.ListBox Info 
      Appearance      =   0  'Flat
      BeginProperty DataFormat 
         Type            =   0
         Format          =   "0"
         HaveTrueFalseNull=   0
         FirstDayOfWeek  =   0
         FirstWeekOfYear =   0
         LCID            =   1046
         SubFormatType   =   0
      EndProperty
      Enabled         =   0   'False
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   3735
      Left            =   120
      TabIndex        =   0
      Top             =   600
      Width           =   3495
   End
   Begin MSWinsockLib.Winsock Sock 
      Index           =   0
      Left            =   0
      Top             =   120
      _ExtentX        =   741
      _ExtentY        =   741
      _Version        =   393216
   End
End
Attribute VB_Name = "CS"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Private Sub Form_Load()
    Sala_IP = "xxx.xxx.xxx.xxx"
    Sala_Porta = "55901"
    
    Call CarregarConfigs
    
    Dim i As Integer
    For i = CMin To CMax
        Load Sock(i)
    Next i
    
    Sock(0).LocalPort = Porta_CS
    Sock(0).Listen
    
    RefreshShellTimer.Enabled = True
End Sub

Private Sub Form_unload(cancel As Integer)
    Call ExitProcess(0)
End Sub

Private Sub RecarregarC_Click()
    Call CarregarConfigs
End Sub

Private Sub RecarregarIP_Click()
    Call ShellRefresh
End Sub

Private Sub RefreshShellTimer_Timer()
    RefreshShellTimer.Interval = 20000
    If ShellAtivado = "1" Then Call ShellRefresh
    If RefreshTimer.Enabled = False Then RefreshTimer.Enabled = True
    
    Sala_IP = ReadINI(App.Path & "/Config.ini", "Config", "IP_da_Sala")
    Sala_Porta = ReadINI(App.Path & "/Config.ini", "Config", "Porta_da_Sala")
    UltimoReload = ReadINI(App.Path & "/Config.ini", "Config", "Ultimo_Refresh")
    Total_On = ReadINI(App.Path & "/Config.ini", "Config", "Total_On")
End Sub

Private Sub RefreshTimer_Timer()
    RefreshTimer.Interval = 1000
    
    CS.Info.Clear
    CS.Info.AddItem "[ConnectServer do MuNovus.net]"
    CS.Info.AddItem "> Por MarxD - versão 1.0." & App.Revision
    CS.Info.AddItem ""
    
    CS.Info.AddItem "[ConnectServer]"
    CS.Info.AddItem "IP [Lan]: " & CS.Sock(0).LocalIP
    If ShellAtivado = 1 Then CS.Info.AddItem "IP [Wan]: " & Sala_IP
    CS.Info.AddItem "Porta: " & CS.Sock(0).LocalPort
    CS.Info.AddItem ""
    
    CS.Info.AddItem "Slots Máximos: " & CMax
    
    CS.Info.AddItem ""
    
    CS.Info.AddItem "[GameServer 01]"
    CS.Info.AddItem "IP [Lan]: " & CS.Sock(0).LocalIP
    If ShellAtivado = 1 Then CS.Info.AddItem "IP [Wan]: " & Sala_IP
    CS.Info.AddItem "Porta: " & Sala_Porta
    CS.Info.AddItem "Total On: " & Total_On
    CS.Info.AddItem ""
    CS.Info.AddItem "Ultima Atualização: " & UltimoReload
End Sub

Private Sub Sock_ConnectionRequest(Index As Integer, ByVal requestID As Long)
    Dim i As Integer
    For i = CMin To CMax
        If Sock(i).State = 0 Then
            
            Dim Enviado As Integer
            Dim Tent As Integer
            
            Sock(i).Accept requestID
            DoEvents
            
            While Enviado = 0
                If Tent > 250 Then Exit Sub
                Tent = Tent + 1
                
                If Sock(i).State = 7 Then
                    Call PacotePrimario(i)
                    Enviado = 1
                    Exit Sub
                End If
            Wend
            
            Exit Sub
        End If
    Next i
End Sub

Private Sub Sock_DataArrival(Index As Integer, ByVal bytesTotal As Long)
    Dim PacoteRec As String
    Dim PacoteSplit() As String

    Sock(Index).GetData PacoteRec
    PacoteSplit() = Split(StringToHex(PacoteRec), " ")
    
    If PacoteSplit(3) = "06" Then
        Call PacoteListaDeSalas(Index)
    End If
    
    If PacoteSplit(3) = "03" Then ' - envia ip e porta da sala
        Estado(Index) = 1
        Call PacoteSalaIPePorta(Index)
        Call PacoteVersaoMain(Index)
    End If
End Sub

Private Sub Sock_Error(Index As Integer, ByVal Number As Integer, Description As String, ByVal Scode As Long, ByVal Source As String, ByVal HelpFile As String, ByVal HelpContext As Long, CancelDisplay As Boolean)
    If Number = 10053 Then Exit Sub
    If Erros.ListCount > 64 Then Erros.Clear
    
    On Error Resume Next
    Erros.AddItem "Index " & Index & ": Nr " & Number & " - Desc: " & Description
End Sub

Private Sub Timer_Estado_Timer()
    Dim i As Integer
    For i = 1 To CMax
        If Sock(i).State = 0 Then
            Estado(i) = 0
            Counter(i) = 0
            Counter_Limite(i) = 0
        Else
        
            Counter_Limite(i) = Counter_Limite(i) + 1
            If Counter_Limite(i) > 29 Then
                On Error Resume Next
                Sock(i).Close
            Else
                If Estado(i) = 1 Then
                    Counter(i) = Counter(i) + 1
                    If Counter(i) > 9 Then
                        Counter(i) = 0
                        Call PacoteSalaIPePorta(i)
                    End If
                End If
            End If
            
        End If
    Next i
End Sub
