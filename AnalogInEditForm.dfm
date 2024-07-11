object AnalogInEdit: TAnalogInEdit
  Left = 0
  Top = 0
  Caption = 'AnalogInEdit'
  ClientHeight = 122
  ClientWidth = 359
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnClose = FormClose
  OnShow = FormShow
  DesignSize = (
    359
    122)
  TextHeight = 15
  object unitsLabel: TLabel
    Left = 144
    Top = 8
    Width = 34
    Height = 15
    Caption = '(units)'
  end
  object minLabel: TLabel
    Left = 8
    Top = 88
    Width = 49
    Height = 15
    Caption = 'minLabel'
  end
  object maxLabel: TLabel
    Left = 288
    Top = 88
    Width = 51
    Height = 15
    Alignment = taRightJustify
    Anchors = [akTop, akRight]
    Caption = 'maxLabel'
    ExplicitLeft = 300
  end
  object errorLabel: TLabel
    Left = 8
    Top = 37
    Width = 22
    Height = 15
    Caption = '(err)'
    Color = clMaroon
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object trackBar: TTrackBar
    Left = 8
    Top = 58
    Width = 331
    Height = 45
    Anchors = [akLeft, akTop, akRight]
    TabOrder = 0
    OnTracking = trackBarTracking
  end
  object edit: TEdit
    Left = 8
    Top = 8
    Width = 121
    Height = 23
    TabOrder = 1
    Text = 'edit'
  end
  object applyButton: TButton
    Left = 184
    Top = 8
    Width = 49
    Height = 25
    Caption = 'Apply'
    Default = True
    TabOrder = 2
    OnClick = applyButtonClick
  end
  object revertButton: TButton
    Left = 239
    Top = 8
    Width = 50
    Height = 25
    Caption = 'Revert'
    TabOrder = 3
    OnClick = revertButtonClick
  end
end
