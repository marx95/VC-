VERSION 5.00
Begin VB.Form Update 
   BorderStyle     =   1  'Fixed Single
   ClientHeight    =   2895
   ClientLeft      =   45
   ClientTop       =   375
   ClientWidth     =   5535
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   2895
   ScaleWidth      =   5535
   StartUpPosition =   2  'CenterScreen
   Begin Launcher_MuNovus.jcbutton FecharBT 
      Height          =   495
      Left            =   3360
      TabIndex        =   0
      Top             =   2040
      Width           =   1815
      _ExtentX        =   3201
      _ExtentY        =   873
      ButtonStyle     =   13
      BeginProperty Font {0BE35203-8F91-11CE-9DE3-00AA004BB851} 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Caption         =   "Fechar"
      MousePointer    =   99
      MouseIcon       =   "Form1.frx":1BB2
      CaptionEffects  =   0
   End
   Begin VB.Label lbSite 
      Alignment       =   2  'Center
      Caption         =   "www.munovus.net"
      Height          =   255
      Left            =   480
      TabIndex        =   1
      Top             =   2160
      Width           =   2655
   End
End
Attribute VB_Name = "Update"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
