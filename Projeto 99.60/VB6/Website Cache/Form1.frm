VERSION 5.00
Object = "{EAB22AC0-30C1-11CF-A7EB-0000C05BAE0B}#1.1#0"; "ieframe.dll"
Begin VB.Form Form1 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "DNS Server & WebSite Cache"
   ClientHeight    =   4935
   ClientLeft      =   45
   ClientTop       =   375
   ClientWidth     =   5295
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   4935
   ScaleWidth      =   5295
   StartUpPosition =   2  'CenterScreen
   Begin VB.TextBox Status 
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Index           =   5
      Left            =   120
      Locked          =   -1  'True
      TabIndex        =   25
      Tag             =   "0"
      Top             =   2040
      Width           =   5055
   End
   Begin VB.CommandButton Atualizar 
      Caption         =   "Atualizar"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   5
      Left            =   960
      TabIndex        =   23
      Top             =   4440
      Width           =   1095
   End
   Begin VB.CommandButton Src 
      Caption         =   "Source"
      Height          =   375
      Index           =   5
      Left            =   120
      TabIndex        =   22
      Top             =   4440
      Width           =   735
   End
   Begin VB.TextBox Text1 
      Height          =   4695
      Left            =   5415
      MultiLine       =   -1  'True
      TabIndex        =   20
      Top             =   120
      Width           =   4765
   End
   Begin VB.CommandButton Src 
      Caption         =   "Source"
      Height          =   375
      Index           =   4
      Left            =   120
      TabIndex        =   19
      Top             =   3960
      Width           =   735
   End
   Begin VB.CommandButton Src 
      Caption         =   "Source"
      Height          =   375
      Index           =   3
      Left            =   120
      TabIndex        =   18
      Top             =   3480
      Width           =   735
   End
   Begin VB.CommandButton Src 
      Caption         =   "Source"
      Height          =   375
      Index           =   2
      Left            =   120
      TabIndex        =   17
      Top             =   3000
      Width           =   735
   End
   Begin VB.CommandButton Src 
      Caption         =   "Source"
      Height          =   375
      Index           =   1
      Left            =   120
      TabIndex        =   16
      Top             =   2520
      Width           =   735
   End
   Begin VB.CommandButton Atualizar 
      Caption         =   "Atualizar"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   4
      Left            =   960
      TabIndex        =   15
      Top             =   3960
      Width           =   1095
   End
   Begin VB.CommandButton Atualizar 
      Caption         =   "Atualizar"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   3
      Left            =   960
      TabIndex        =   14
      Top             =   3480
      Width           =   1095
   End
   Begin VB.CommandButton Atualizar 
      Caption         =   "Atualizar"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   2
      Left            =   960
      TabIndex        =   13
      Top             =   3000
      Width           =   1095
   End
   Begin VB.CommandButton Atualizar 
      Caption         =   "Atualizar"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   1
      Left            =   960
      TabIndex        =   12
      Top             =   2520
      Width           =   1095
   End
   Begin VB.TextBox Status 
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Index           =   4
      Left            =   120
      Locked          =   -1  'True
      TabIndex        =   7
      Tag             =   "0"
      Top             =   1560
      Width           =   5055
   End
   Begin VB.TextBox Status 
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Index           =   3
      Left            =   120
      Locked          =   -1  'True
      TabIndex        =   6
      Tag             =   "0"
      Top             =   1080
      Width           =   5055
   End
   Begin VB.TextBox Status 
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Index           =   2
      Left            =   120
      Locked          =   -1  'True
      TabIndex        =   5
      Tag             =   "0"
      Top             =   600
      Width           =   5055
   End
   Begin VB.TextBox Status 
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   12
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   405
      Index           =   1
      Left            =   120
      Locked          =   -1  'True
      TabIndex        =   4
      Tag             =   "0"
      Top             =   120
      Width           =   5055
   End
   Begin SHDocVwCtl.WebBrowser Browser 
      Height          =   615
      Index           =   4
      Left            =   240
      TabIndex        =   0
      Top             =   7920
      Width           =   5055
      ExtentX         =   8916
      ExtentY         =   1085
      ViewMode        =   0
      Offline         =   0
      Silent          =   0
      RegisterAsBrowser=   0
      RegisterAsDropTarget=   1
      AutoArrange     =   0   'False
      NoClientEdge    =   0   'False
      AlignLeft       =   0   'False
      NoWebView       =   0   'False
      HideFileNames   =   0   'False
      SingleClick     =   0   'False
      SingleSelection =   0   'False
      NoFolders       =   0   'False
      Transparent     =   0   'False
      ViewID          =   "{0057D0E0-3573-11CF-AE69-08002B2E1262}"
      Location        =   ""
   End
   Begin VB.Timer Tempo 
      Enabled         =   0   'False
      Interval        =   1000
      Left            =   5400
      Top             =   5760
   End
   Begin SHDocVwCtl.WebBrowser Browser 
      Height          =   615
      Index           =   1
      Left            =   240
      TabIndex        =   1
      Top             =   5760
      Width           =   5055
      ExtentX         =   8916
      ExtentY         =   1085
      ViewMode        =   0
      Offline         =   0
      Silent          =   0
      RegisterAsBrowser=   0
      RegisterAsDropTarget=   1
      AutoArrange     =   0   'False
      NoClientEdge    =   0   'False
      AlignLeft       =   0   'False
      NoWebView       =   0   'False
      HideFileNames   =   0   'False
      SingleClick     =   0   'False
      SingleSelection =   0   'False
      NoFolders       =   0   'False
      Transparent     =   0   'False
      ViewID          =   "{0057D0E0-3573-11CF-AE69-08002B2E1262}"
      Location        =   ""
   End
   Begin SHDocVwCtl.WebBrowser Browser 
      Height          =   615
      Index           =   2
      Left            =   240
      TabIndex        =   2
      Top             =   6480
      Width           =   5055
      ExtentX         =   8916
      ExtentY         =   1085
      ViewMode        =   0
      Offline         =   0
      Silent          =   0
      RegisterAsBrowser=   0
      RegisterAsDropTarget=   1
      AutoArrange     =   0   'False
      NoClientEdge    =   0   'False
      AlignLeft       =   0   'False
      NoWebView       =   0   'False
      HideFileNames   =   0   'False
      SingleClick     =   0   'False
      SingleSelection =   0   'False
      NoFolders       =   0   'False
      Transparent     =   0   'False
      ViewID          =   "{0057D0E0-3573-11CF-AE69-08002B2E1262}"
      Location        =   ""
   End
   Begin SHDocVwCtl.WebBrowser Browser 
      Height          =   615
      Index           =   3
      Left            =   240
      TabIndex        =   3
      Top             =   7200
      Width           =   5055
      ExtentX         =   8916
      ExtentY         =   1085
      ViewMode        =   0
      Offline         =   0
      Silent          =   0
      RegisterAsBrowser=   0
      RegisterAsDropTarget=   1
      AutoArrange     =   0   'False
      NoClientEdge    =   0   'False
      AlignLeft       =   0   'False
      NoWebView       =   0   'False
      HideFileNames   =   0   'False
      SingleClick     =   0   'False
      SingleSelection =   0   'False
      NoFolders       =   0   'False
      Transparent     =   0   'False
      ViewID          =   "{0057D0E0-3573-11CF-AE69-08002B2E1262}"
      Location        =   ""
   End
   Begin SHDocVwCtl.WebBrowser Browser 
      Height          =   615
      Index           =   5
      Left            =   240
      TabIndex        =   21
      Top             =   8640
      Width           =   5055
      ExtentX         =   8916
      ExtentY         =   1085
      ViewMode        =   0
      Offline         =   0
      Silent          =   0
      RegisterAsBrowser=   0
      RegisterAsDropTarget=   1
      AutoArrange     =   0   'False
      NoClientEdge    =   0   'False
      AlignLeft       =   0   'False
      NoWebView       =   0   'False
      HideFileNames   =   0   'False
      SingleClick     =   0   'False
      SingleSelection =   0   'False
      NoFolders       =   0   'False
      Transparent     =   0   'False
      ViewID          =   "{0057D0E0-3573-11CF-AE69-08002B2E1262}"
      Location        =   ""
   End
   Begin VB.Label Info 
      BackStyle       =   0  'Transparent
      Caption         =   "Carregando..."
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   5
      Left            =   2160
      TabIndex        =   24
      Top             =   4440
      Width           =   3015
   End
   Begin VB.Label Info 
      BackStyle       =   0  'Transparent
      Caption         =   "Carregando..."
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   4
      Left            =   2160
      TabIndex        =   11
      Top             =   3960
      Width           =   3015
   End
   Begin VB.Label Info 
      BackStyle       =   0  'Transparent
      Caption         =   "Carregando..."
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   3
      Left            =   2160
      TabIndex        =   10
      Top             =   3480
      Width           =   3015
   End
   Begin VB.Label Info 
      BackStyle       =   0  'Transparent
      Caption         =   "Carregando..."
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   2
      Left            =   2160
      TabIndex        =   9
      Top             =   3000
      Width           =   3015
   End
   Begin VB.Label Info 
      BackStyle       =   0  'Transparent
      Caption         =   "Carregando..."
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   12
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Index           =   1
      Left            =   2160
      TabIndex        =   8
      Top             =   2520
      Width           =   3015
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub Atualizar_Click(Index As Integer)
    Info(Index).Caption = "Atualizando..."
    Call AtualizarCache(Index)
End Sub

Private Sub Browser_DocumentComplete(Index As Integer, ByVal pDisp As Object, URL As Variant)
    Dim Source As String
    On Error Resume Next
    Source = Browser(Index).Document.documentelement.innerhtml
    Source = Replace(Source, "<TITLE>", "")
    Source = Replace(Source, "</TITLE>", "")
    Source = Replace(Source, "<HEAD>", "")
    Source = Replace(Source, "</HEAD>", "")
    Source = Replace(Source, "<BODY>", "")
    Source = Replace(Source, "</BODY>", "")
    Source = Replace(Source, vbNewLine, vbNullString)
    Atualizando(Index) = 0

    If InStr(1, Source, "Sucesso") Then
        Info(Index).Caption = "Sucesso"
    Else
        Info(Index).Caption = "Falha!"
        Contador(Index) = Limite(Index) - 5
    End If
        
    If Ativado(Index) = 1 Then Atualizar(Index).Enabled = True
End Sub

Private Sub Form_Load()
    Me.Width = 5385
    Dim i As Integer
    For i = 1 To 5
        Atualizar(i).Caption = "Link " & i
        If i < 5 Then Link(i) = ReadINI(App.Path & "/Config.ini", "Cache", "Link_" & i)
        If i = 5 Then Link(i) = ReadINI(App.Path & "/Config.ini", "Cache", "Link_DNS_IP")
        
        If Len(Link(i)) > 12 Then
            Ativado(i) = 1
            If i < 5 Then Limite(i) = ReadINI(App.Path & "/Config.ini", "Cache", "Tempo_" & i) * 60
            If i = 5 Then Limite(i) = 15
            Contador(i) = 0
            Call AtualizarCache(i)
        Else
            Call Browser(i).Navigate("about:blank")
            Status(i).Text = "Desativado"
            Status(i).Enabled = False
            Atualizar(i).Enabled = False
            Info(i).Visible = False
        End If
    Next i
    
    Atualizar(5).Caption = "IP Server"
    Tempo.Enabled = True
End Sub

Public Function AtualizarCache(Index As Integer)
    If Ativado(Index) = False Then Exit Function
    Atualizar(Index).Enabled = False
    Info(Index).Caption = "Atualizando..."
    Contador(Index) = 0
    Atualizando(Index) = 1
    Call Browser(Index).Navigate(Link(Index))
End Function

Private Sub Form_Unload(Cancel As Integer)
    If MsgBox("Tem certeza que deseja fechar?", vbYesNo, "Fechar?") = vbNo Then Cancel = 1
End Sub


Private Sub Src_Click(Index As Integer)
    If Me.Width > 5385 Then
        Me.Width = 5385
        Exit Sub
    Else
        Me.Width = 10385
        
        Dim Source As String
        On Error GoTo Erro
        Source = Browser(Index).Document.documentelement.innerhtml
        Source = Replace(Source, "<TITLE>", "")
        Source = Replace(Source, "</TITLE>", "")
        Source = Replace(Source, "<HEAD>", "")
        Source = Replace(Source, "</HEAD>", "")
        Source = Replace(Source, "<BODY>", "")
        Source = Replace(Source, "</BODY>", "")
        Source = Replace(Source, vbNewLine, vbNullString)
        Text1.Text = Source
    End If
    Exit Sub
Erro:
End Sub

Private Sub Tempo_Timer()
    Dim i As Integer
    For i = 1 To 5
        If Ativado(i) = 1 Then
            If Atualizando(i) = 0 Then Contador(i) = Contador(i) + 1
            If Contador(i) >= Limite(i) And Atualizando(i) = 0 Then Call AtualizarCache(i)
            
            Dim TmpTempo As Integer
            TmpTempo = (Limite(i) - Contador(i))
            If i < 5 Then Status(i).Text = "Link " & i & ": (" & SetarTempo(TmpTempo) & " / " & SetarTempo(Limite(i)) & ")"
            If i = 5 Then Status(i).Text = "Dns: (" & SetarTempo(TmpTempo) & " / " & SetarTempo(Limite(i)) & ")"
        End If
    Next i
End Sub
