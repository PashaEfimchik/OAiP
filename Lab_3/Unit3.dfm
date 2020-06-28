object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 506
  ClientWidth = 847
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 88
    Top = 56
    Width = 34
    Height = 13
    Caption = 'Name: '
  end
  object Label2: TLabel
    Left = 88
    Top = 96
    Width = 33
    Height = 13
    Caption = 'Count:'
  end
  object Label3: TLabel
    Left = 40
    Top = 136
    Width = 94
    Height = 13
    Caption = 'Workshop number: '
  end
  object EditName: TEdit
    Left = 136
    Top = 53
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'EditName'
  end
  object EditCount: TEdit
    Left = 136
    Top = 93
    Width = 121
    Height = 21
    NumbersOnly = True
    TabOrder = 1
    Text = 'EditCount'
  end
  object EditNumber: TEdit
    Left = 136
    Top = 133
    Width = 121
    Height = 21
    NumbersOnly = True
    TabOrder = 2
    Text = 'EditNumber'
  end
  object ButtonSaveChanges: TButton
    Left = 296
    Top = 51
    Width = 75
    Height = 25
    Caption = 'Add / Save'
    TabOrder = 3
    OnClick = ButtonSaveChangesClick
  end
  object ButtonDelete: TButton
    Left = 296
    Top = 96
    Width = 75
    Height = 25
    Caption = 'Delete'
    TabOrder = 4
    TabStop = False
    OnClick = ButtonDeleteClick
  end
  object ComboBoxSearch: TComboBox
    Left = 40
    Top = 208
    Width = 145
    Height = 21
    TabOrder = 5
    Text = 'Search by'
    OnChange = ComboBoxSearchChange
    Items.Strings = (
      'Name'
      'Workshop number'
      'Count')
  end
  object EditSearch: TEdit
    Left = 223
    Top = 208
    Width = 121
    Height = 21
    TabOrder = 6
    Text = 'EditSearch'
    TextHint = 'Key search'
    OnChange = ButtonSearchClick
  end
  object ListBox: TListBox
    Left = 416
    Top = 33
    Width = 186
    Height = 241
    TabStop = False
    ItemHeight = 13
    TabOrder = 7
    OnClick = ListBoxClick
  end
  object ButtonOpenDialog: TButton
    Left = 24
    Top = 388
    Width = 75
    Height = 25
    Caption = 'Open'
    TabOrder = 8
    OnClick = ButtonOpenDialogClick
  end
  object ButtonSaveDialog: TButton
    Left = 24
    Top = 432
    Width = 75
    Height = 25
    Caption = 'Save'
    TabOrder = 9
    OnClick = ButtonSaveDialogClick
  end
  object ButtonFlushList: TButton
    Left = 608
    Top = 33
    Width = 75
    Height = 25
    Caption = 'Release'
    TabOrder = 10
    OnClick = ButtonFlushListClick
  end
  object CheckBoxAddProduct: TCheckBox
    Left = 416
    Top = 8
    Width = 97
    Height = 17
    Caption = 'Add new product'
    Checked = True
    State = cbChecked
    TabOrder = 11
    OnClick = CheckBoxAddProductClick
  end
  object OpenDialog: TOpenDialog
    Left = 704
    Top = 448
  end
  object SaveDialog: TSaveDialog
    Left = 664
    Top = 448
  end
end
