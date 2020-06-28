object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 479
  ClientWidth = 830
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ButtonAdd: TButton
    Left = 200
    Top = 24
    Width = 169
    Height = 41
    Caption = 'Add number (Generate)'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = ButtonAddClick
  end
  object ListBox: TListBox
    Left = 40
    Top = 24
    Width = 105
    Height = 241
    TabStop = False
    ItemHeight = 13
    TabOrder = 1
  end
  object ListBoxPos: TListBox
    Left = 224
    Top = 296
    Width = 121
    Height = 169
    ItemHeight = 13
    TabOrder = 2
  end
  object ListBoxNeg: TListBox
    Left = 512
    Top = 296
    Width = 121
    Height = 169
    ItemHeight = 13
    TabOrder = 3
  end
  object ButtonMake: TButton
    Left = 344
    Top = 224
    Width = 169
    Height = 41
    Caption = 'list separation'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = ButtonMakeClick
  end
  object ButtonDel: TButton
    Left = 200
    Top = 88
    Width = 169
    Height = 41
    Caption = 'Delete first number'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    TabStop = False
    OnClick = ButtonDelClick
  end
  object StaticText1: TStaticText
    Left = 264
    Top = 273
    Width = 47
    Height = 20
    Caption = 'positive'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object StaticText2: TStaticText
    Left = 552
    Top = 273
    Width = 52
    Height = 20
    Caption = 'negative'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
  end
  object Button1: TButton
    Left = 747
    Top = 440
    Width = 75
    Height = 25
    Caption = 'Exit'
    TabOrder = 8
    OnClick = Button1Click
  end
end
