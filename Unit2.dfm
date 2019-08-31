object fr_GameWindow: Tfr_GameWindow
  Left = 351
  Top = 218
  BorderIcons = [biSystemMenu]
  BorderStyle = bsToolWindow
  Caption = 'PingPong v1.0 by dev-tommy'
  ClientHeight = 601
  ClientWidth = 1157
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object im_Game: TImage
    Left = 0
    Top = 0
    Width = 1157
    Height = 601
    Align = alClient
  end
  object tm_PlayerOne: TTimer
    Enabled = False
    Interval = 200
    Left = 16
    Top = 24
  end
  object tm_PlayerTwo: TTimer
    Enabled = False
    Interval = 200
    Left = 56
    Top = 24
  end
  object tm_Ball: TTimer
    Enabled = False
    Interval = 20
    Left = 96
    Top = 24
  end
end
