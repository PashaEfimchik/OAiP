object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 437
  ClientWidth = 1065
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
  object LabelHash: TLabel
    Left = 456
    Top = 40
    Width = 76
    Height = 13
    Caption = 'Hash table size:'
  end
  object Memo1: TMemo
    Left = 296
    Top = 59
    Width = 457
    Height = 276
    Lines.Strings = (
      'Memo1')
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object ButtonRandomize: TButton
    Left = 771
    Top = 131
    Width = 118
    Height = 42
    Caption = 'Add random numbers'
    TabOrder = 1
    OnClick = ButtonRandomizeClick
  end
  object ButtonClear: TButton
    Left = 771
    Top = 59
    Width = 118
    Height = 38
    Caption = 'Clear hash table'
    TabOrder = 2
    OnClick = ButtonClearClick
  end
  object ButtonDelete: TButton
    Left = 180
    Top = 131
    Width = 100
    Height = 42
    Caption = 'Delete number'
    TabOrder = 3
    OnClick = ButtonDeleteClick
  end
  object EditNumber: TEdit
    Left = 65
    Top = 152
    Width = 50
    Height = 21
    TabOrder = 4
    Text = 'EditNumber'
    TextHint = 'Number'
    OnClick = EditNumberClick
  end
  object EditHash: TEdit
    Left = 546
    Top = 37
    Width = 21
    Height = 21
    NumbersOnly = True
    TabOrder = 5
    Text = '10'
  end
  object ButtonFindMix: TButton
    Left = 771
    Top = 211
    Width = 118
    Height = 42
    Caption = 'Find max number'
    TabOrder = 6
    OnClick = ButtonFindMaxClick
  end
  object ButtonAdd: TButton
    Left = 180
    Top = 59
    Width = 100
    Height = 38
    Caption = 'Add number'
    TabOrder = 7
    OnClick = ButtonAddClick
  end
  object ButtonFind: TButton
    Left = 180
    Top = 211
    Width = 100
    Height = 42
    Caption = 'Find number'
    TabOrder = 8
    OnClick = ButtonFindClick
  end
end
