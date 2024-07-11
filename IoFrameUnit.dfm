object IoFrame: TIoFrame
  Left = 0
  Top = 0
  Width = 192
  Height = 50
  TabOrder = 0
  DesignSize = (
    192
    50)
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 192
    Height = 42
    Anchors = [akLeft, akTop, akRight, akBottom]
    Caption = 'GroupBox1'
    TabOrder = 0
    DesignSize = (
      192
      42)
    object FlowPanel1: TFlowPanel
      Left = 3
      Top = 16
      Width = 186
      Height = 26
      Anchors = [akLeft, akTop, akRight, akBottom]
      TabOrder = 0
      object edit: TEdit
        Left = 1
        Top = 1
        Width = 71
        Height = 23
        ReadOnly = True
        TabOrder = 0
        Text = '0'
        OnClick = editClick
      end
      object shape: TShape
        Left = 72
        Top = 1
        Width = 23
        Height = 24
        Pen.Color = clGreen
        Pen.Width = 3
        Shape = stRoundSquare
        OnMouseUp = shapeMouseUp
      end
      object unitsLabel: TLabel
        Left = 95
        Top = 1
        Width = 54
        Height = 15
        Caption = 'unitsLabel'
      end
    end
  end
end
