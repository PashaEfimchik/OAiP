object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 538
  ClientWidth = 963
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
    Left = 51
    Top = 60
    Width = 55
    Height = 13
    Caption = 'Edit Name: '
  end
  object Label2: TLabel
    Left = 51
    Top = 155
    Width = 47
    Height = 13
    Caption = 'Edit Age: '
  end
  object Label3: TLabel
    Left = 28
    Top = 203
    Width = 70
    Height = 13
    Caption = 'EditDiagnosis: '
  end
  object Label4: TLabel
    Left = 27
    Top = 251
    Width = 71
    Height = 13
    Caption = 'Number ward: '
  end
  object EditName: TEdit
    Left = 112
    Top = 57
    Width = 121
    Height = 21
    TabOrder = 0
    Text = 'EditName'
  end
  object RadioGroupSex: TRadioGroup
    Left = 51
    Top = 86
    Width = 201
    Height = 41
    Caption = 'Select Sex:'
    Columns = 2
    Items.Strings = (
      'Men'
      'Women')
    TabOrder = 1
    TabStop = True
  end
  object EditAge: TEdit
    Left = 112
    Top = 152
    Width = 121
    Height = 21
    MaxLength = 3
    NumbersOnly = True
    TabOrder = 2
    Text = 'EditAge'
    TextHint = 'Edit age'
  end
  object EditDiag: TEdit
    Left = 112
    Top = 200
    Width = 121
    Height = 21
    TabOrder = 3
    Text = 'EditDiag'
  end
  object EditWard: TEdit
    Left = 112
    Top = 248
    Width = 121
    Height = 21
    NumbersOnly = True
    TabOrder = 4
    Text = 'EditWard'
    TextHint = 'Number ward'
  end
  object ButtonSaveChanges: TButton
    Left = 273
    Top = 84
    Width = 120
    Height = 37
    Caption = 'Add / Save'
    TabOrder = 5
    OnClick = ButtonSaveChangesClick
  end
  object ButtonDelete: TButton
    Left = 273
    Top = 143
    Width = 120
    Height = 40
    Caption = 'Delete'
    TabOrder = 6
    TabStop = False
    OnClick = ButtonDeleteClick
  end
  object ComboBoxSearch: TComboBox
    Left = 440
    Top = 57
    Width = 113
    Height = 21
    TabOrder = 7
    Text = 'Sort'
    OnChange = ButtonSearchClick
    Items.Strings = (
      'Ward'
      'Diagnosis'
      'Name')
  end
  object EditSearch: TEdit
    Left = 559
    Top = 57
    Width = 201
    Height = 21
    TabOrder = 8
    Text = 'EditSearch'
    TextHint = 'Search by ward'
    OnChange = ButtonSearchClick
  end
  object ListBox: TListBox
    Left = 440
    Top = 86
    Width = 401
    Height = 274
    ItemHeight = 13
    TabOrder = 9
    OnClick = ListBoxClick
  end
  object ButtonOpenDialog: TButton
    Left = 847
    Top = 238
    Width = 89
    Height = 41
    Caption = 'Open'
    TabOrder = 10
    OnClick = ButtonOpenDialogClick
  end
  object ButtonSaveDialog: TButton
    Left = 847
    Top = 304
    Width = 89
    Height = 41
    Caption = 'Save'
    TabOrder = 11
    OnClick = ButtonSaveDialogClock
  end
  object ButtonFlushList: TButton
    Left = 766
    Top = 55
    Width = 75
    Height = 25
    Caption = 'Release'
    TabOrder = 12
    OnClick = ButtonFlushListClick
  end
  object CheckBoxAddPatient: TCheckBox
    Left = 536
    Top = 24
    Width = 97
    Height = 17
    Caption = 'Add new patient'
    Checked = True
    State = cbChecked
    TabOrder = 13
    OnClick = CheckBoxAddPatientClick
  end
  object RadioButtonList: TRadioGroup
    Left = 847
    Top = 86
    Width = 74
    Height = 105
    BiDiMode = bdLeftToRight
    Caption = 'List patient'
    Items.Strings = (
      'Patients'
      'Update')
    ParentBiDiMode = False
    TabOrder = 14
    OnClick = RadioButtonListClick
  end
  object OpenDialog: TOpenDialog
    Left = 928
  end
  object SaveDialog: TSaveDialog
    DefaultExt = 'txt'
    Left = 888
  end
end
