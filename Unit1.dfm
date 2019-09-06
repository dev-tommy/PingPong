object fr_ConfigWindow: Tfr_ConfigWindow
  Left = 930
  Top = 363
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsToolWindow
  Caption = 'PingPong (alfa) by dev-tommy'
  ClientHeight = 593
  ClientWidth = 345
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -21
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsStayOnTop
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 25
  object lb_GameName: TLabel
    Left = 48
    Top = 16
    Width = 250
    Height = 73
    Caption = 'PingPong'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clMaroon
    Font.Height = -64
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object bt_NewGame: TButton
    Left = 64
    Top = 440
    Width = 217
    Height = 65
    Caption = 'NOWA GRA'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -32
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 0
    OnClick = bt_NewGameClick
  end
  object pn_GameOptions: TPanel
    Left = 64
    Top = 120
    Width = 217
    Height = 289
    TabOrder = 1
    object rg_GameMode: TRadioGroup
      Left = 16
      Top = 8
      Width = 185
      Height = 105
      Caption = 'Rodzaj gry'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold, fsItalic]
      ItemIndex = 0
      Items.Strings = (
        'Gracz vs Gracz'
        'Gracz vs CPU')
      ParentFont = False
      TabOrder = 0
      OnClick = rg_GameModeClick
    end
    object rg_DifficultyLevel: TRadioGroup
      Left = 16
      Top = 136
      Width = 185
      Height = 137
      Caption = 'Poziom trudno'#347'ci'
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -21
      Font.Name = 'Times New Roman'
      Font.Style = [fsBold, fsItalic]
      ItemIndex = 1
      Items.Strings = (
        #321'atwy'
        #346'redni'
        'Trudny')
      ParentFont = False
      TabOrder = 1
    end
  end
  object bt_CloseGame: TButton
    Left = 88
    Top = 528
    Width = 169
    Height = 41
    Caption = 'ZAKO'#323'CZ'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -32
    Font.Name = 'Times New Roman'
    Font.Style = [fsItalic]
    ParentFont = False
    TabOrder = 2
    OnClick = bt_CloseGameClick
  end
end
