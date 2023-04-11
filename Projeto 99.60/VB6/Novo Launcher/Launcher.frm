VERSION 5.00
Begin VB.Form Launcher 
   BorderStyle     =   3  'Fixed Dialog
   ClientHeight    =   7215
   ClientLeft      =   45
   ClientTop       =   375
   ClientWidth     =   7815
   Icon            =   "Launcher.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   7215
   ScaleWidth      =   7815
   StartUpPosition =   2  'CenterScreen
   Begin VB.Timer LiberarSleep 
      Enabled         =   0   'False
      Interval        =   800
      Left            =   7320
      Top             =   720
   End
   Begin VB.Timer Timer1 
      Interval        =   100
      Left            =   7320
      Top             =   240
   End
   Begin LauncherMuMax.jcbutton Baixar 
      Height          =   375
      Left            =   480
      TabIndex        =   24
      Top             =   4560
      Visible         =   0   'False
      Width           =   1935
      _ExtentX        =   3413
      _ExtentY        =   661
      ButtonStyle     =   8
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BackColor       =   12632256
      Caption         =   "jcbutton"
      MousePointer    =   99
      MouseIcon       =   "Launcher.frx":1BB2
      PicturePushOnHover=   -1  'True
      CaptionEffects  =   0
      ColorScheme     =   3
   End
   Begin VB.HScrollBar Volume 
      Height          =   200
      Left            =   480
      Max             =   9
      TabIndex        =   21
      Top             =   4080
      Visible         =   0   'False
      Width           =   1935
   End
   Begin VB.CheckBox Check4 
      BackColor       =   &H00FFFFFF&
      Caption         =   "Ativar AutoClick"
      Height          =   255
      Left            =   5160
      TabIndex        =   20
      Top             =   1320
      Visible         =   0   'False
      Width           =   2055
   End
   Begin VB.CheckBox Check3 
      BackColor       =   &H00FFFFFF&
      Caption         =   "Modo Janela"
      Height          =   255
      Left            =   5160
      TabIndex        =   19
      Top             =   960
      Visible         =   0   'False
      Width           =   2055
   End
   Begin VB.ComboBox Combo3 
      Height          =   315
      ItemData        =   "Launcher.frx":1ECC
      Left            =   5160
      List            =   "Launcher.frx":1EEC
      Style           =   2  'Dropdown List
      TabIndex        =   18
      Top             =   2400
      Visible         =   0   'False
      Width           =   1695
   End
   Begin VB.CheckBox Check2 
      BackColor       =   &H00FFFFFF&
      Caption         =   "Músicas"
      Height          =   375
      Left            =   480
      TabIndex        =   17
      Top             =   3720
      Visible         =   0   'False
      Width           =   1695
   End
   Begin VB.CheckBox Check1 
      BackColor       =   &H00FFFFFF&
      Caption         =   "Efeitos Sonoros"
      Height          =   255
      Left            =   480
      TabIndex        =   16
      Top             =   3480
      Visible         =   0   'False
      Width           =   1695
   End
   Begin VB.ComboBox Combo2 
      Height          =   315
      ItemData        =   "Launcher.frx":1F0C
      Left            =   2280
      List            =   "Launcher.frx":1F16
      Style           =   2  'Dropdown List
      TabIndex        =   15
      Top             =   2280
      Visible         =   0   'False
      Width           =   975
   End
   Begin VB.ComboBox Combo1 
      Height          =   315
      ItemData        =   "Launcher.frx":1F2C
      Left            =   480
      List            =   "Launcher.frx":1F4B
      Style           =   2  'Dropdown List
      TabIndex        =   14
      Top             =   2280
      Visible         =   0   'False
      Width           =   1695
   End
   Begin VB.TextBox Login 
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      Height          =   285
      Left            =   480
      TabIndex        =   13
      Top             =   1080
      Visible         =   0   'False
      Width           =   1695
   End
   Begin LauncherMuMax.jcbutton FecharBT 
      Height          =   375
      Left            =   5880
      TabIndex        =   3
      Top             =   6720
      Width           =   1815
      _ExtentX        =   3201
      _ExtentY        =   661
      ButtonStyle     =   8
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BackColor       =   12632256
      Caption         =   "jcbutton"
      MousePointer    =   99
      MouseIcon       =   "Launcher.frx":1FAA
      CaptionEffects  =   0
      ColorScheme     =   3
   End
   Begin LauncherMuMax.jcbutton SiteBT 
      Height          =   375
      Left            =   3960
      TabIndex        =   2
      Top             =   6720
      Width           =   1815
      _ExtentX        =   3201
      _ExtentY        =   661
      ButtonStyle     =   8
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BackColor       =   12632256
      Caption         =   "jcbutton"
      MousePointer    =   99
      MouseIcon       =   "Launcher.frx":22C4
      CaptionEffects  =   0
      ColorScheme     =   3
   End
   Begin LauncherMuMax.jcbutton OpcoesBT 
      Height          =   375
      Left            =   2040
      TabIndex        =   1
      Top             =   6720
      Width           =   1815
      _ExtentX        =   3201
      _ExtentY        =   661
      ButtonStyle     =   8
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BackColor       =   12632256
      Caption         =   "jcbutton"
      MousePointer    =   99
      MouseIcon       =   "Launcher.frx":25DE
      CaptionEffects  =   0
      ColorScheme     =   3
   End
   Begin LauncherMuMax.jcbutton JogarBT 
      Height          =   375
      Left            =   120
      TabIndex        =   0
      Top             =   6720
      Width           =   1815
      _ExtentX        =   3201
      _ExtentY        =   661
      ButtonStyle     =   8
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      BackColor       =   12632256
      Caption         =   "jcbutton"
      MousePointer    =   99
      MouseIcon       =   "Launcher.frx":28F8
      CaptionEffects  =   0
      ColorScheme     =   3
   End
   Begin LauncherMuMax.Progressbar_user pbDownload 
      Height          =   255
      Left            =   120
      TabIndex        =   26
      Top             =   6360
      Width           =   7575
      _ExtentX        =   13361
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
      Color           =   4210752
      Scrolling       =   3
   End
   Begin LauncherMuMax.Progressbar_user pbTotal 
      Height          =   255
      Left            =   120
      TabIndex        =   27
      Top             =   5760
      Width           =   7575
      _ExtentX        =   13361
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
      Color           =   8421504
      Scrolling       =   3
   End
   Begin VB.Label lbDownload 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      ForeColor       =   &H00000000&
      Height          =   255
      Left            =   240
      TabIndex        =   29
      Top             =   6120
      Width           =   7335
   End
   Begin VB.Label lbTotal 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      Height          =   315
      Left            =   240
      TabIndex        =   28
      Top             =   5520
      Width           =   7320
   End
   Begin VB.Label LauncherMsg 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      Height          =   255
      Left            =   240
      TabIndex        =   25
      Top             =   5160
      Visible         =   0   'False
      Width           =   7335
   End
   Begin VB.Label Label11 
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "Outras Opções"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   300
      Left            =   5040
      TabIndex        =   23
      Top             =   3240
      Visible         =   0   'False
      Width           =   1800
   End
   Begin VB.Label Label10 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      Height          =   255
      Left            =   480
      TabIndex        =   22
      Top             =   4320
      Width           =   1935
   End
   Begin VB.Label Label9 
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "F10 - Para os click's"
      Height          =   195
      Left            =   5160
      TabIndex        =   12
      Top             =   4320
      Visible         =   0   'False
      Width           =   1425
   End
   Begin VB.Label Label8 
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "F9 - Oculta a janela"
      Height          =   195
      Left            =   5160
      TabIndex        =   11
      Top             =   4080
      Visible         =   0   'False
      Width           =   1380
   End
   Begin VB.Label Label7 
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "F8 - Simula o click direito"
      Height          =   195
      Left            =   5160
      TabIndex        =   10
      Top             =   3840
      Visible         =   0   'False
      Width           =   1755
   End
   Begin VB.Label Label6 
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "F7 - Simula o click esquerdo"
      Height          =   195
      Left            =   5160
      TabIndex        =   9
      Top             =   3600
      Visible         =   0   'False
      Width           =   1995
   End
   Begin VB.Label Label5 
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "Outras opções"
      Height          =   195
      Left            =   5040
      TabIndex        =   8
      Top             =   720
      Visible         =   0   'False
      Width           =   1035
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "Tamanho da Fonte do Jogo"
      Height          =   195
      Left            =   5040
      TabIndex        =   7
      Top             =   2040
      Visible         =   0   'False
      Width           =   1965
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "Opções de audio"
      Height          =   195
      Left            =   360
      TabIndex        =   6
      Top             =   3120
      Visible         =   0   'False
      Width           =   1215
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "Selecione a resoluçao de acordo com seu monitor"
      Height          =   195
      Left            =   360
      TabIndex        =   5
      Top             =   1920
      Visible         =   0   'False
      Width           =   3540
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "Digite o login para ser preenchido automaticamente"
      Height          =   195
      Left            =   360
      TabIndex        =   4
      Top             =   720
      Visible         =   0   'False
      Width           =   3630
   End
End
Attribute VB_Name = "Launcher"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Public WithEvents m_WebControl As VBControlExtender
Attribute m_WebControl.VB_VarHelpID = -1

Private Sub NavegarNoticias()
    If ErroNoNavegador = 1 Then Exit Sub
    On Error GoTo Erro_Browser
    m_WebControl.object.Navigate LinkNoticias
Exit Sub

Erro_Browser:
    ErroNoNavegador = 1
    m_WebControl.Visible = False
    LauncherMsg.Caption = "Falha ao carregar navegador de notícias! Reinicie o computador para resolver!"
End Sub

Private Sub Baixar_Click()
    Call ShellExecute(Launcher.hWnd, vbNullString, "Launcher.exe", "sonsmusicas", vbNullString, 0)
    Call Fechar
End Sub

Private Sub FecharBT_Click()
    Call Fechar
End Sub

Private Sub Form_Load()
    Status = 0 ' - Veja no timer1 a  descricao de cada
    
    NomeJanela = "MuMax - Aqui tudo é Legalizado!"
    
    LinkNoticias = "http://pgcontrol.com.br/muonline/site/noticias.php"
    LinkSite = "http://pgcontrol.com.br/muonline"
    
    LinkDirUpdate = "http://pgcontrol.com.br/muonline/update/"
    LinkDLL = "http://pgcontrol.com.br/muonline/update/UnRAR.dll"
    
    Me.Caption = NomeJanela
    Me.BackColor = &HFFFFFF
    Label1.BackStyle = 0
    Label2.BackStyle = 0
    Label3.BackStyle = 0
    Label4.BackStyle = 0
    Label5.BackStyle = 0
    Label6.BackStyle = 0
    Label7.BackStyle = 0
    Label8.BackStyle = 0
    Label9.BackStyle = 0
    Label10.BackStyle = 0
    Label11.BackStyle = 0
    lbTotal.BackStyle = 0
    lbDownload.BackStyle = 0
    LauncherMsg.BackStyle = 0
    Check1.BackColor = &HFFFFFF
    Check2.BackColor = &HFFFFFF
    Check3.BackColor = &HFFFFFF
    Check4.BackColor = &HFFFFFF
    pbTotal.Color = &H404040
    pbDownload.Color = &H404040
    pbTotal.ShowText = True
    pbDownload.ShowText = True
    pbTotal.Scrolling = 3
    pbDownload.Scrolling = 3
    
    Baixar.ButtonStyle = 8
    JogarBT.ButtonStyle = 8
    OpcoesBT.ButtonStyle = 8
    SiteBT.ButtonStyle = 8
    FecharBT.ButtonStyle = 8
    
    Baixar.BackColor = &HC0C0C0
    JogarBT.BackColor = &HC0C0C0
    OpcoesBT.BackColor = &HC0C0C0
    SiteBT.BackColor = &HC0C0C0
    FecharBT.BackColor = &HC0C0C0
    
    Baixar.Caption = "Baixar Sons e Músicas"
    JogarBT.Caption = "Jogar"
    OpcoesBT.Caption = "Opções"
    SiteBT.Caption = "Site"
    FecharBT.Caption = "Fechar"


    LauncherMsg = "MarxD Launcher (v2.00." & App.Revision & ") - Exclusivo do MuMax"
    
    Set m_WebControl = Controls.Add("Shell.Explorer.2", "webctl", Launcher)
    m_WebControl.Move 120, 120, 7575, 5295
    m_WebControl.Visible = False
    Call NavegarNoticias
    
    ' - Inicio da update
    lbTotal.Caption = "Verificando atualização..."
    JogarBT.Enabled = False
    OpcoesBT.Enabled = False
    
    Status = 1
End Sub

Private Sub Form_Unload(Cancel As Integer)
    Call Fechar
End Sub

Private Sub JogarBT_Click()
    Dim ShellInfo As Integer
    ShellInfo = ShellExecute(Launcher.hWnd, vbNullString, "AntiHack.exe", "AH_MarxD#0", vbNullString, 1)
   ' ShellInfo = ShellExecute(Launcher.hWnd, vbNullString, "Main.exe", "connect /u212.124.107.116 /p44405 AH_MarxD", vbNullString, 1)
    
    If ShellInfo = 2 Then
        JogarBT.Enabled = False
        MsgBox "Falha ao executar o AntiHack.exe" + vbNewLine + "Re-abra o Launcher e espere atualizar!", vbCritical, "Ocorreu um erro!"
    End If

    Call Fechar
End Sub

Private Sub LiberarSleep_Timer()
    LiberarSleep.Enabled = False
    JogarBT.Enabled = Enabled
    OpcoesBT.Enabled = Enabled
    pbTotal.Visible = False
    pbDownload.Visible = False
    lbTotal.Visible = False
    lbDownload.Visible = False
    m_WebControl.Move 120, 120, 7575, 6495
End Sub

Private Sub OpcoesBT_Click()
    If OpcoesBT.Caption = "Opções" Then
        OpcoesBT.Caption = "Aplicar"
        Call Carregar
        JogarBT.Enabled = False
        m_WebControl.Visible = False
        Label1.Visible = True
        Label2.Visible = True
        Label3.Visible = True
        Label4.Visible = True
        Label5.Visible = True
        Label6.Visible = True
        Label7.Visible = True
        Label8.Visible = True
        Label9.Visible = True
        Label10.Visible = True
        Label11.Visible = True
        LauncherMsg.Visible = True
        Login.Visible = True
        Combo1.Visible = True
        Combo2.Visible = True
        Combo3.Visible = True
        Check1.Visible = True
        Check2.Visible = True
        Check3.Visible = True
        Check4.Visible = True
        Volume.Visible = True
        Baixar.Visible = True
    Else
        Call Salvar
        OpcoesBT.Caption = "Opções"
        JogarBT.Enabled = True
        m_WebControl.Visible = True
        Label1.Visible = False
        Label2.Visible = False
        Label3.Visible = False
        Label4.Visible = False
        Label5.Visible = False
        Label6.Visible = False
        Label7.Visible = False
        Label8.Visible = False
        Label9.Visible = False
        Label10.Visible = False
        Label11.Visible = False
        LauncherMsg.Visible = False
        Login.Visible = False
        Combo1.Visible = False
        Combo2.Visible = False
        Combo3.Visible = False
        Check1.Visible = False
        Check2.Visible = False
        Check3.Visible = False
        Check4.Visible = False
        Volume.Visible = False
        Baixar.Visible = False
    End If
End Sub

Private Sub SiteBT_Click()
    Call ShellExecute(Launcher.hWnd, vbNullString, LinkSite, vbNullString, vbNullString, 1)
End Sub

Private Sub Timer1_Timer()
    ' Def Status
    ' 0 = Configurando
    ' 1 = Configurado & liberado para iniciar update
    ' 2 = Atualizando
    ' 3 = Atualizaçao finalizada, Sleep de 800ms para exibir a Msg "Atualizaçao Finalizada"
    ' 4 = null
    
    If Status = 1 Then
        Status = 2
        m_WebControl.Visible = True
        Call DelTmp
        Call IniciarUpdate
        Exit Sub
    End If
    
    If Status = 2 Then Exit Sub
    
    If Status = 3 Then
        Timer1.Enabled = False
        
        lbTotal.Caption = "Processo de atualização finalizado!"
        pbTotal.Max = 100
        pbDownload.Max = 100
        pbTotal.Value = 100
        pbDownload.Value = 100
    
        LiberarSleep.Enabled = True
    End If
End Sub

Private Sub Volume_Change()
    On Error Resume Next
    Launcher.Label10.Caption = (Noticias.Volume.Value * 10) & "%"
End Sub

Private Sub Volume_DragOver(Source As Control, x As Single, Y As Single, State As Integer)
    On Error Resume Next
    Launcher.Label10.Caption = (Noticias.Volume.Value * 10) & "%"
End Sub

Private Sub Volume_Scroll()
    On Error Resume Next
    Launcher.Label10.Caption = (Noticias.Volume.Value * 10) & "%"
End Sub

Private Sub IniciarUpdate()

    DoEvents
    Dim ErroUnrar As Integer
    If Existe(App.Path & "/UnRAR.dll") = True Then
        If mcrc.CRC(App.Path & "/UnRAR.dll") <> "-540628159" Then ErroUnrar = 1
    Else
        ErroUnrar = 1
    End If

    If ErroUnrar = 1 Then
        lbTotal.Caption = "Baixando UnRAR.dll"
        Tamanho = 155136
        Call DownloadAFile("UnRAR.dll", LinkDLL, False, True)
    End If
    
    If Command = "sonsmusicas" Then
        ArquivoUpdate = "update_sonsmusicas"
        Call DownloadAFile("update_sonsmusicas.rar", LinkDirUpdate & "/update_sonsmusicas.rar", False, False)
        Call RARExtract("update_sonsmusicas.rar", "", "")
        Call Deletar("update_sonsmusicas.rar")
    Else
        ArquivoUpdate = "update_completo"
        Call DownloadAFile("update_completo.rar", LinkDirUpdate & "/update_completo.rar", False, False)
        Call RARExtract("update_completo.rar", "", "")
        Call Deletar("update_completo.rar")
    End If
    
    Call DownloadAFile("update_crc.rar", LinkDirUpdate & "/update_crc.rar", False, False)
    Call RARExtract("update_crc.rar", "", "")
    Call Deletar("update_crc.rar")
    
    If VerificarArquivos Then
        Call BaixarArquivos
    Else
        Status = 3
    End If
    
    If VerificarArquivos_CRC Then
        Call BaixarArquivos_CRC
    Else
        Status = 3
    End If
    
    Call DelTmp
    Status = 3
End Sub

Private Function VerificarArquivos() As Boolean
    If Existe(App.Path & "\update.txt") = False Then
        VerificarArquivos = False
        Exit Function
    End If
    
    Dim i As Long
    Dim Total As Long
    
    Open App.Path & "\update.txt" For Input As #1
        Lista_de_Arquivos = Split(Input(FileLen(App.Path & "\update.txt"), #1), vbNewLine)
    Close #1
    
    Total = UBound(Lista_de_Arquivos)
    pbTotal.Max = Total
    lbTotal.Caption = "Verificando arquivos..."
    
    For i = 0 To Total
        DoEvents
        pbTotal.Value = i
    
        If Len(Lista_de_Arquivos(i)) > 3 Then
            Dim TmpString() As String
            TmpString = Split(Lista_de_Arquivos(i), ";")
        
            If Existe(App.Path & "/" & TmpString(0)) = False Then
                Lista_a_Baixar(Total_a_Baixar) = TmpString(0)
                Tamanho_do_Arquivo(Total_a_Baixar) = TmpString(1)
                Total_a_Baixar = Total_a_Baixar + 1
         End If
        End If
    Next i
    
    VerificarArquivos = True
End Function

Private Sub BaixarArquivos()
    Dim i As Long
    pbTotal.Max = Total_a_Baixar
    
    For i = 0 To Total_a_Baixar
        If Len(Lista_a_Baixar(i)) > 0 Then
            DoEvents
            pbTotal.Value = i
            lbTotal.Caption = "Baixando arquivo " & i & " de " & Total_a_Baixar & "..."
            Tamanho = Tamanho_do_Arquivo(i)
            Call DownloadAFile(i & ".rar", LinkDirUpdate & "/" & Lista_a_Baixar(i) & ".rar", False, True)
            Call RARExtract(i & ".rar", "", "")
            Call Deletar(i & ".rar")
        End If
    Next i
End Sub

Private Function VerificarArquivos_CRC() As Boolean
    If Existe(App.Path & "\update_crc.txt") = False Then
        VerificarArquivos_CRC = False
        Exit Function
    End If
    
    Dim i As Long
    Dim Total As Long
    
    Open App.Path & "\update_crc.txt" For Input As #1
        Lista_de_Arquivos_CRC = Split(Input(FileLen(App.Path & "\update_crc.txt"), #1), vbNewLine)
    Close #1
    
    Total = UBound(Lista_de_Arquivos_CRC)
    pbTotal.Max = Total
    
    For i = 0 To Total
        DoEvents
        pbTotal.Value = i
        lbTotal.Caption = "Verificando CRC de " & i & "/" & Total & " arquivos..."
        
    
        If Len(Lista_de_Arquivos_CRC(i)) > 3 Then
            Dim TmpString() As String
            TmpString = Split(Lista_de_Arquivos_CRC(i), ";")
            If Existe(App.Path & "/" & TmpString(0)) = False Then
                Lista_a_Baixar_CRC(Total_a_Baixar_CRC) = TmpString(0)
                Tamanho_do_Arquivo_CRC(Total_a_Baixar_CRC) = TmpString(1)
                Total_a_Baixar_CRC = Total_a_Baixar_CRC + 1
            Else
                If mcrc.CRC(App.Path & "/" & TmpString(0)) <> TmpString(2) Then
                    Lista_a_Baixar_CRC(Total_a_Baixar_CRC) = TmpString(0)
                    Tamanho_do_Arquivo_CRC(Total_a_Baixar_CRC) = TmpString(1)
                    Total_a_Baixar_CRC = Total_a_Baixar_CRC + 1
                End If
            End If
        End If
    Next i
    
    VerificarArquivos_CRC = True
End Function

Private Sub BaixarArquivos_CRC()
    Dim i As Long
    pbTotal.Max = Total_a_Baixar_CRC
    
    For i = 0 To Total_a_Baixar_CRC
        pbTotal.Value = i
        If Len(Lista_a_Baixar_CRC(i)) > 0 Then
            DoEvents
            If LCase(Lista_a_Baixar_CRC(i)) = "launcher.exe" Then
                Call ShellExecute(Launcher.hWnd, vbNullString, "Atualiza.exe", LinkDirUpdate & "/Launcher.exe.rar", vbNullString, 0)
                Call Fechar
            End If
            
            lbTotal.Caption = "Baixando arquivo " & i & " de " & Total_a_Baixar_CRC & "..."
            Tamanho = Tamanho_do_Arquivo_CRC(i)
            Call DownloadAFile(i & ".rar", LinkDirUpdate & "/" & Lista_a_Baixar_CRC(i) & ".rar", False, True)
            Call RARExtract(i & ".rar", "", "")
            Call Deletar(i & ".rar")
        End If
    Next i
End Sub

