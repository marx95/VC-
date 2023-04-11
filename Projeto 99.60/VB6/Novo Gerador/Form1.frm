VERSION 5.00
Begin VB.Form Gerador 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Gerador de Atualização - www.MuOver.net"
   ClientHeight    =   2955
   ClientLeft      =   45
   ClientTop       =   375
   ClientWidth     =   4695
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2955
   ScaleWidth      =   4695
   StartUpPosition =   2  'CenterScreen
   Begin VB.CheckBox Comp 
      Caption         =   "Compactar?"
      Height          =   255
      Left            =   120
      TabIndex        =   7
      Top             =   1680
      Value           =   1  'Checked
      Width           =   1335
   End
   Begin Gerador_MuNovus.jcbutton Gerar 
      Height          =   495
      Left            =   1800
      TabIndex        =   5
      Top             =   1680
      Width           =   1095
      _ExtentX        =   1931
      _ExtentY        =   873
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
      Caption         =   "Gerar"
      MousePointer    =   99
      MouseIcon       =   "Form1.frx":1BB2
      PictureEffectOnOver=   0
      PictureEffectOnDown=   0
      CaptionEffects  =   0
      TooltipBackColor=   0
   End
   Begin Gerador_MuNovus.Progressbar_user PB 
      Height          =   255
      Left            =   120
      TabIndex        =   4
      Top             =   2280
      Width           =   4455
      _ExtentX        =   7858
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
      Scrolling       =   1
   End
   Begin VB.OptionButton Option3 
      Caption         =   "Update com CRC"
      Height          =   375
      Left            =   120
      TabIndex        =   3
      Top             =   1200
      Width           =   3495
   End
   Begin VB.OptionButton Option2 
      Caption         =   "Update de Sons e Músicas"
      Height          =   375
      Left            =   120
      TabIndex        =   2
      Top             =   720
      Width           =   3375
   End
   Begin VB.OptionButton Option1 
      Caption         =   "Update Completa"
      Height          =   255
      Left            =   120
      TabIndex        =   1
      Top             =   360
      Width           =   3015
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      BackStyle       =   0  'Transparent
      Caption         =   "Gerador exclusivo do MuOver.net"
      Height          =   235
      Left            =   0
      TabIndex        =   6
      Top             =   0
      Width           =   4935
   End
   Begin VB.Label Info 
      Alignment       =   2  'Center
      BackColor       =   &H00E0E0E0&
      BackStyle       =   0  'Transparent
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   350
      Left            =   0
      TabIndex        =   0
      Top             =   2640
      Width           =   4695
   End
End
Attribute VB_Name = "Gerador"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Form_Load()
    Iniciado = 0
    Gerando = 0
    Option1.Value = True
    Gerar.Enabled = False
    PB.Scrolling = 1
    Call GerarBat
End Sub

Private Sub Form_Paint()
    If Iniciado = 1 Then Exit Sub
    Iniciado = 1
    
    If Len(Dir(App.Path & "/rar.exe")) < 4 Then
        DoEvents
        Info.Caption = "Baixando rar.exe"
        Call DownloadAFile("rar.exe", "http://pgcontrol.com.br/muover/rar.exe", False)
    End If
    
    If Len(Dir(App.Path & "/UnRAR.dll")) < 4 Then
        DoEvents
        Info.Caption = "Baixando UnRAR.dll"
        Call DownloadAFile("UnRAR.dll", "http://pgcontrol.com.br/muover/UnRAR.dll", False)
    End If
    
    Info.Caption = "Clique em Gerar!"
    Gerar.Enabled = True
End Sub

Private Sub Form_Unload(Cancel As Integer)
    If Gerando = 1 Then
        Cancel = 1
        Exit Sub
    End If
    On Error Resume Next
    Call Kill("Listar.bat")
    Call Sleep(500)
    Call ExitProcess(0)
End Sub

Private Sub Gerar_Click()
    If Gerar.Caption = "Fechar" Then
        Call ExitProcess(0)
        Exit Sub
    End If
    
    Dim CRCAtivado As Integer
    Gerando = 1
    CRCAtivado = 0
    Dim ArquivoUpdate As String
    If Option1.Value = True Then ArquivoUpdate = "update_completo"
    If Option2.Value = True Then ArquivoUpdate = "update_sonsmusicas"
    If Option3.Value = True Then
        CRCAtivado = 1
        ArquivoUpdate = "update_crc"
    End If
    
    Option1.Enabled = False
    Option2.Enabled = False
    Option3.Enabled = False
    Gerar.Enabled = False
    Comp.Enabled = False
    
    Call FileCopy(App.Path & "/Listar.bat", App.Path & "/update/Listar.bat")
    Call ShellExecute(hWnd, vbNullString, "Listar.bat", vbNullString, "Update\", 0)
    DoEvents
    
    While Len(Dir(App.Path & "/update/lista.txt")) < 4
        Info.Caption = "Listando arquivos..."
        'MsgBox "Aguarde...", vbInformation, "Aviso!"
        Call Sleep(300)
    Wend
    
    Dim i As Long
    Dim Total As Long
    Dim Lista_de_Arquivos() As String
    Dim Tamanho(0 To 32000) As Long
    Dim ArqCRC(0 To 32000) As String
    Dim OutPath As String
    Dim erro As Long
    
    Open App.Path & "\update\lista.txt" For Input As #1
        Lista_de_Arquivos = Split(Input(FileLen(App.Path & "\update\lista.txt"), #1), vbNewLine)
    Close #1
    Total = UBound(Lista_de_Arquivos)
    PB.Max = Total
    
    For i = 0 To Total
        DoEvents
        PB.Value = i
        Info.Caption = "Compactando... " & i & "/" & Total
        
        While ProcessoExiste("rar.exe")
            Call Sleep(100)
        Wend
        
        If InStr(1, Lista_de_Arquivos(i), ".") Then
            Dim Bug As Integer
            Bug = 0
            
            If InStr(1, LCase(Lista_de_Arquivos(i)), "lista.txt") Then Bug = 1
            If InStr(1, LCase(Lista_de_Arquivos(i)), "listar.bat") Then Bug = 1
            If InStr(1, LCase(Lista_de_Arquivos(i)), "update_completo") Then Bug = 1
            If InStr(1, LCase(Lista_de_Arquivos(i)), "update_sonsmusicas") Then Bug = 1
            If InStr(1, LCase(Lista_de_Arquivos(i)), "update_crc") Then Bug = 1
            If InStr(1, LCase(Lista_de_Arquivos(i)), "unrar") Then Bug = 1
            If InStr(1, LCase(Lista_de_Arquivos(i)), ".db") Then Bug = 1
            If InStr(1, LCase(Lista_de_Arquivos(i)), "muerror.log") Then Bug = 1
            If InStr(1, LCase(Lista_de_Arquivos(i)), ".bak") Then Bug = 1
           ' If InStr(1, LCase(Lista_de_Arquivos(i)), ArquivoUpdate) Then Bug = 1
            If InStr(1, LCase(Lista_de_Arquivos(i)), ".rar") Then
                Bug = 1
                erro = erro + 1
            End If
            
            ArqCRC(i) = mcrc.CRC(Lista_de_Arquivos(i))

            Lista_de_Arquivos(i) = Replace(Lista_de_Arquivos(i), App.Path & "\update\", vbNullString)
            Lista_de_Arquivos(i) = Replace(Lista_de_Arquivos(i), App.Path & "\Update\", vbNullString)
            
            If Bug = 0 Then
                Call ShellExecute(Me.hWnd, vbNullString, App.Path & "/rar.exe", "a -df -m5 " & Lista_de_Arquivos(i) & ".rar " & Lista_de_Arquivos(i), App.Path & "\update\", 0)
            Else
                Lista_de_Arquivos(i) = vbNullString
            End If
        End If
    Next i
    
    Dim Tentativas As Integer
    Tentativas = 0
    PB.Value = Tentativas
    PB.Max = 150
        
    On Error Resume Next
    While Len(Dir(App.Path & "\update\" & Lista_de_Arquivos(Total - 1) & ".rar")) < 4 And Tentativas < 150
        Tentativas = Tentativas + 1
        PB.Value = Tentativas
        DoEvents
        Info.Caption = "Gerando Lista de Update... " '& Tentativas
        Call Sleep(25)
    Wend
    
    Dim ListaDeUpdate As String
    For i = 0 To Total
        If Len(Lista_de_Arquivos(i)) > 4 And InStr(1, Lista_de_Arquivos(i), ".") Then
            On Error Resume Next
            Tamanho(i) = FileLen(App.Path & "\update\" & Lista_de_Arquivos(i) & ".rar")
            
            If CRCAtivado = 0 Then
                Lista_de_Arquivos(i) = Lista_de_Arquivos(i) & ";" & Tamanho(i)
            Else
                Lista_de_Arquivos(i) = Lista_de_Arquivos(i) & ";" & Tamanho(i) & ";" & ArqCRC(i)
            End If
            
            If Len(ListaDeUpdate) < 4 Then
                ListaDeUpdate = ListaDeUpdate & Lista_de_Arquivos(i)
            Else
                ListaDeUpdate = ListaDeUpdate & vbNewLine & Lista_de_Arquivos(i)
            End If
        End If
    Next i
    
    Dim OutFileUpdate As String
    If CRCAtivado = 1 Then
        OutFileUpdate = ArquivoUpdate & ".txt"
    Else
        OutFileUpdate = "update.txt"
    End If
    
    ' - SALVA LISTA DE UPDATE COMPLETA
    OutPath = App.Path & "/update/" & OutFileUpdate
    Open OutPath For Output As #1
        Print #1, ListaDeUpdate
    Close #1
    
    If Comp.Value = 1 Then Call ShellExecute(Me.hWnd, vbNullString, App.Path & "/rar.exe", "a -df -m5 " & ArquivoUpdate & ".rar " & OutFileUpdate, App.Path & "\update\", 0)
    
    On Error Resume Next
    Call Kill("update/lista.txt")
    On Error Resume Next
    Call Kill("update/listar.bat")
    
    If erro > 0 Then
        Info.Caption = "Terminado!"
        MsgBox "Foi encontrado " & erro & " arquivo(s) já compactado(s)!" & vbNewLine & "Eles não foram adicionados na Lista de Atualização!!", vbCritical, "AVISO!"
    Else
        Info.Caption = "Sucesso!"
    End If
    
    Gerar.Caption = "Fechar"
    Gerar.Enabled = True
    Gerando = 0
End Sub

Public Function GerarBat()
    On Error Resume Next
    Call MkDir("update")
    On Error Resume Next
    Call Kill("Listar.bat")
    
    Dim OutPath As String
    
    OutPath = App.Path & "/Listar.bat"
    Open OutPath For Output As #1
        Print #1, "dir /a /-p /o:n /s /b >lista.txt"
    Close #1
End Function
