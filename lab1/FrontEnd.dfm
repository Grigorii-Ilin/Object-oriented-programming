object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 446
  ClientWidth = 702
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object paintBox: TPaintBox
    Left = 16
    Top = 8
    Width = 400
    Height = 400
  end
  object btCreate: TButton
    Left = 312
    Top = 414
    Width = 75
    Height = 25
    Caption = #1054#1087#1099#1090
    TabOrder = 0
    OnClick = btCreateClick
  end
  object btByDefault: TButton
    Left = 613
    Top = 400
    Width = 81
    Height = 25
    Caption = #1055#1086' '#1091#1084#1086#1083#1095#1072#1085#1080#1102
    TabOrder = 1
    OnClick = btByDefaultClick
  end
  object seMoveX: TCSpinEdit
    Left = 440
    Top = 304
    Width = 67
    Height = 22
    TabOrder = 2
  end
  object btMove: TButton
    Left = 440
    Top = 400
    Width = 75
    Height = 25
    Caption = #1044#1074#1080#1075#1072#1090#1100
    TabOrder = 3
    OnClick = btMoveClick
  end
  object btRotate: TButton
    Left = 528
    Top = 400
    Width = 75
    Height = 25
    Caption = #1042#1088#1072#1097#1072#1090#1100
    TabOrder = 4
  end
  object seMoveY: TCSpinEdit
    Left = 440
    Top = 332
    Width = 67
    Height = 22
    TabOrder = 5
  end
  object seMoveZ: TCSpinEdit
    Left = 440
    Top = 360
    Width = 67
    Height = 22
    TabOrder = 6
  end
  object Memo1: TMemo
    Left = 440
    Top = 16
    Width = 254
    Height = 282
    TabOrder = 7
  end
end
