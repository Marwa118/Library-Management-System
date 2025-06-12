object Form3: TForm3
  Left = 0
  Top = 0
  Caption = 'Form3'
  ClientHeight = 441
  ClientWidth = 624
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 121
    Top = 0
    Width = 369
    Height = 37
    Alignment = taCenter
    Caption = 'Library Management System'
    Color = clBeige
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Segoe UI'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    Transparent = False
  end
  object Panel1: TPanel
    Left = 8
    Top = 47
    Width = 617
    Height = 50
    TabOrder = 0
    object Button1: TButton
      Left = 24
      Top = 8
      Width = 75
      Height = 33
      Caption = 'Add User'
      TabOrder = 0
      StyleName = 'Windows'
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 169
      Top = 8
      Width = 89
      Height = 33
      Caption = 'Add Resources'
      TabOrder = 1
      StyleName = 'Windows'
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 344
      Top = 8
      Width = 75
      Height = 33
      Caption = 'Borrow'
      TabOrder = 2
      StyleName = 'Windows'
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 512
      Top = 8
      Width = 75
      Height = 33
      Caption = 'Return'
      TabOrder = 3
      StyleName = 'Windows'
      OnClick = Button4Click
    end
  end
  object Panel2: TPanel
    Left = 8
    Top = 103
    Width = 617
    Height = 50
    TabOrder = 1
    object Button5: TButton
      Left = 375
      Top = 8
      Width = 116
      Height = 33
      Caption = 'Search'
      TabOrder = 0
      StyleName = 'Windows'
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 497
      Top = 8
      Width = 111
      Height = 33
      Caption = 'Reset'
      TabOrder = 1
      StyleName = 'Windows'
      OnClick = Button6Click
    end
    object SearchBox1: TSearchBox
      Left = 16
      Top = 8
      Width = 353
      Height = 23
      TabOrder = 2
    end
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 159
    Width = 473
    Height = 218
    DefaultColWidth = 90
    DefaultRowHeight = 40
    DoubleBuffered = False
    FixedColor = clWhite
    RowCount = 1
    FixedRows = 0
    ParentDoubleBuffered = False
    TabOrder = 2
  end
  object Panel3: TPanel
    Left = 8
    Top = 383
    Width = 608
    Height = 50
    TabOrder = 3
    object Button8: TButton
      Left = 137
      Top = 8
      Width = 105
      Height = 33
      Caption = 'Show Overdue'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Segoe UI Semibold'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = Button8Click
    end
    object Button9: TButton
      Left = 273
      Top = 8
      Width = 96
      Height = 33
      Caption = 'Add an Event'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Segoe UI Semibold'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = Button9Click
    end
    object Button11: TButton
      Left = 504
      Top = 8
      Width = 91
      Height = 33
      Caption = 'Exit'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Segoe UI Semibold'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = Button11Click
    end
    object Button7: TButton
      Left = 16
      Top = 8
      Width = 105
      Height = 33
      Caption = 'Save '
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Segoe UI Semibold'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = Button7Click
    end
    object Button10: TButton
      Left = 390
      Top = 8
      Width = 93
      Height = 33
      Caption = 'Show Events'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Segoe UI Semibold'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      OnClick = Button10Click
    end
  end
  object Memo1: TMemo
    Left = 479
    Top = 159
    Width = 146
    Height = 218
    Color = clMenuHighlight
    Lines.Strings = (
      'Memo1')
    TabOrder = 4
  end
end
