object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 589
  ClientWidth = 1035
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object TreeView1: TTreeView
    Left = 32
    Top = 8
    Width = 209
    Height = 209
    Indent = 19
    ReadOnly = True
    TabOrder = 0
  end
  object StringGrid1: TStringGrid
    Left = 32
    Top = 329
    Width = 129
    Height = 240
    ColCount = 2
    FixedCols = 0
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goEditing]
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object ButtonAdd: TButton
    Left = 424
    Top = 16
    Width = 105
    Height = 41
    Caption = 'Add new Tree'
    TabOrder = 2
    OnClick = ButtonAddClick
  end
  object ButtonClear: TButton
    Left = 32
    Top = 249
    Width = 105
    Height = 41
    Caption = 'Clear'
    TabOrder = 3
    OnClick = ButtonClearClick
  end
  object ButtonDelete: TButton
    Left = 528
    Top = 99
    Width = 105
    Height = 41
    Caption = 'Delete'
    TabOrder = 4
    OnClick = ButtonDeleteClick
  end
  object EditKey: TEdit
    Left = 264
    Top = 26
    Width = 121
    Height = 21
    MaxLength = 9
    NumbersOnly = True
    ParentShowHint = False
    ShowHint = False
    TabOrder = 5
    Text = 'EditKey'
    TextHint = 'New key'
  end
  object EditValue: TEdit
    Left = 264
    Top = 82
    Width = 121
    Height = 21
    ParentShowHint = False
    ShowHint = False
    TabOrder = 6
    Text = 'EditValue'
    TextHint = 'New value'
  end
  object Button1: TButton
    Left = 264
    Top = 168
    Width = 99
    Height = 41
    Caption = 'StringGrid -> Tree'
    TabOrder = 7
    OnClick = ButtonMoveClick
  end
  object EditDelKey: TEdit
    Left = 586
    Top = 72
    Width = 121
    Height = 21
    MaxLength = 9
    NumbersOnly = True
    ParentShowHint = False
    ShowHint = False
    TabOrder = 8
    Text = 'EditDelKey'
    TextHint = 'Key to find / dlete'
  end
  object ButtonNew: TButton
    Left = 167
    Top = 329
    Width = 103
    Height = 41
    Caption = 'New empty cell'
    TabOrder = 9
    OnClick = ButtonNewClick
  end
  object ButtonRandom: TButton
    Left = 167
    Top = 400
    Width = 103
    Height = 41
    Caption = 'New random cell'
    TabOrder = 10
    OnClick = ButtonRandomClick
  end
  object StringGridLevels: TStringGrid
    Left = 191
    Top = 521
    Width = 362
    Height = 48
    ColCount = 2
    RowCount = 2
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
    ScrollBars = ssNone
    TabOrder = 11
    RowHeights = (
      23
      24)
  end
  object Memo1: TMemo
    Left = 554
    Top = 303
    Width = 215
    Height = 138
    Lines.Strings = (
      'Memo1')
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 12
  end
  object RadioGroup1: TRadioGroup
    Left = 775
    Top = 311
    Width = 185
    Height = 105
    Caption = 'Diversion'
    Items.Strings = (
      'direct'
      'reverse'
      'increasing')
    TabOrder = 13
    OnClick = RadioGroup1Click
  end
  object ButtonFind: TButton
    Left = 648
    Top = 99
    Width = 121
    Height = 41
    Caption = 'Find'
    TabOrder = 14
    OnClick = ButtonFindClick
  end
end
