object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 391
  ClientWidth = 783
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Task: TEdit
    Left = 72
    Top = 163
    Width = 169
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 0
    Text = 'Task'
    TextHint = 'Your Expression'
  end
  object AEdit: TEdit
    Left = 56
    Top = 80
    Width = 41
    Height = 21
    TabOrder = 1
    Text = 'AEdit'
  end
  object BEdit: TEdit
    Left = 183
    Top = 80
    Width = 41
    Height = 21
    TabOrder = 2
    Text = 'BEdit'
  end
  object CEdit: TEdit
    Left = 304
    Top = 80
    Width = 41
    Height = 21
    TabOrder = 3
    Text = 'CEdit'
  end
  object DEdit: TEdit
    Left = 424
    Top = 80
    Width = 41
    Height = 21
    TabOrder = 4
    Text = 'DEdit'
  end
  object EEdit: TEdit
    Left = 536
    Top = 80
    Width = 41
    Height = 21
    TabOrder = 5
    Text = 'EEdit'
  end
  object Result: TEdit
    Left = 304
    Top = 163
    Width = 145
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ReadOnly = True
    ShowHint = True
    TabOrder = 6
    Text = 'Result'
  end
  object SolveButton: TButton
    Left = 513
    Top = 146
    Width = 121
    Height = 43
    Caption = 'Solve'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    OnClick = SolveButtonClick
  end
  object FillVariantButton: TButton
    Left = 670
    Top = 63
    Width = 105
    Height = 51
    Caption = '8th Variant'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = FillVariantButtonClick
  end
  object Notation: TEdit
    Left = 273
    Top = 268
    Width = 120
    Height = 27
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ParentShowHint = False
    ReadOnly = True
    ShowHint = True
    TabOrder = 9
    Text = 'Reverse'
  end
  object StaticText1: TStaticText
    Left = 13
    Top = 78
    Width = 37
    Height = 23
    Caption = 'A = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
  end
  object StaticText2: TStaticText
    Left = 142
    Top = 78
    Width = 35
    Height = 23
    Caption = 'B = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
  end
  object StaticText3: TStaticText
    Left = 263
    Top = 78
    Width = 36
    Height = 23
    Caption = 'C = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 12
  end
  object StaticText4: TStaticText
    Left = 382
    Top = 78
    Width = 37
    Height = 23
    Caption = 'D = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
  end
  object StaticText5: TStaticText
    Left = 496
    Top = 80
    Width = 35
    Height = 23
    Caption = 'E = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 14
  end
  object StaticText6: TStaticText
    Left = 72
    Top = 136
    Width = 55
    Height = 27
    Caption = 'Task: '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 15
  end
  object StaticText7: TStaticText
    Left = 261
    Top = 162
    Width = 30
    Height = 27
    Caption = ' = '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 16
  end
  object StaticText8: TStaticText
    Left = 72
    Top = 272
    Width = 188
    Height = 23
    Caption = 'Reverse Polish Notation ='
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 17
  end
  object Button1: TButton
    Left = 684
    Top = 334
    Width = 91
    Height = 49
    Caption = 'Exit'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 18
    OnClick = Button1Click
  end
  object StaticText9: TStaticText
    Left = 670
    Top = 34
    Width = 76
    Height = 23
    Caption = 'Auto fill : '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 19
  end
end
