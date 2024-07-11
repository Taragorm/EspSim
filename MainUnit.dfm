object MainForm: TMainForm
  Left = 0
  Top = 0
  Hint = 'foo'
  Caption = 'MainForm'
  ClientHeight = 597
  ClientWidth = 677
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 15
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 677
    Height = 65
    Align = alTop
    Caption = 'Commands'
    TabOrder = 0
    object Start: TButton
      Left = 8
      Top = 24
      Width = 75
      Height = 25
      Caption = 'Start'
      TabOrder = 0
      OnClick = StartClick
    end
  end
  object ScrollBox1: TScrollBox
    Left = 0
    Top = 65
    Width = 677
    Height = 532
    Align = alClient
    TabOrder = 1
    object flowPanel: TFlowPanel
      Left = 0
      Top = 0
      Width = 673
      Height = 528
      Align = alClient
      TabOrder = 0
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 10
    OnTimer = Timer1Timer
    Left = 8
    Top = 544
  end
end
