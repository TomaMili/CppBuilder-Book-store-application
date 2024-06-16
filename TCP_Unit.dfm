object Form_TCP: TForm_TCP
  Left = 0
  Top = 0
  Caption = 'Form_TCP'
  ClientHeight = 263
  ClientWidth = 654
  Color = clActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'JetBrains Mono'
  Font.Style = []
  Menu = MainMenu1
  OnShow = FormShow
  TextHeight = 16
  object Label1: TLabel
    Left = 24
    Top = 8
    Width = 35
    Height = 16
    Alignment = taRightJustify
    Caption = 'Host:'
  end
  object Label2: TLabel
    Left = 17
    Top = 226
    Width = 56
    Height = 16
    Alignment = taRightJustify
    Caption = 'Message:'
  end
  object Image1: TImage
    Left = 360
    Top = 64
    Width = 273
    Height = 152
    Center = True
    Proportional = True
  end
  object EditMessage: TEdit
    Left = 79
    Top = 223
    Width = 179
    Height = 24
    TabOrder = 0
  end
  object Button1: TButton
    Left = 264
    Top = 222
    Width = 75
    Height = 25
    Caption = 'Send'
    TabOrder = 1
    OnClick = Button1Click
  end
  object EditHost: TEdit
    Left = 24
    Top = 26
    Width = 155
    Height = 24
    TabOrder = 2
    Text = 'localhost'
  end
  object BtnCon: TButton
    Left = 185
    Top = 27
    Width = 154
    Height = 23
    Caption = 'Connect'
    TabOrder = 3
    OnClick = BtnConClick
  end
  object ListBox1: TListBox
    Left = 24
    Top = 64
    Width = 315
    Height = 153
    TabOrder = 4
  end
  object ButtonSendFile: TButton
    Left = 360
    Top = 222
    Width = 129
    Height = 25
    Caption = 'Send file'
    TabOrder = 5
    OnClick = ButtonSendFileClick
  end
  object C1: TIdTCPClient
    ConnectTimeout = 0
    Port = 12457
    ReadTimeout = -1
    Left = 384
    Top = 80
  end
  object S1: TIdTCPServer
    Active = True
    Bindings = <
      item
        IP = '0.0.0.0'
        Port = 12457
      end>
    DefaultPort = 12457
    OnExecute = S1Execute
    Left = 440
    Top = 80
  end
  object fileDialog: TOpenDialog
    DefaultExt = 'bmp'
    Title = 'Select an Image'
    Left = 496
    Top = 80
  end
  object UDPClient: TIdUDPClient
    Active = True
    Host = '127.0.0.1'
    Port = 12345
    Left = 408
    Top = 24
  end
  object UDPServer: TIdUDPServer
    Active = True
    BroadcastEnabled = True
    Bindings = <>
    DefaultPort = 12345
    OnUDPRead = UDPServerUDPRead
    Left = 480
    Top = 24
  end
  object MainMenu1: TMainMenu
    Left = 536
    Top = 32
    object Language1: TMenuItem
      Caption = 'Language'
      object EN: TMenuItem
        Caption = 'Eng'
        OnClick = ENClick
      end
      object HR: TMenuItem
        Caption = 'Hrv'
        OnClick = HRClick
      end
    end
  end
end
