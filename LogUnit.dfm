object LogForm: TLogForm
  Left = 0
  Top = 0
  Caption = 'LogForm'
  ClientHeight = 433
  ClientWidth = 622
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  DesignSize = (
    622
    433)
  TextHeight = 15
  object clearButton: TButton
    Left = 32
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Clear'
    TabOrder = 0
    OnClick = clearButtonClick
  end
  object log: TMemo
    Left = 8
    Top = 47
    Width = 594
    Height = 378
    Anchors = [akLeft, akTop, akRight, akBottom]
    ScrollBars = ssBoth
    TabOrder = 1
  end
end
