object Form_Login: TForm_Login
  Left = 0
  Top = 0
  Caption = 'Login'
  ClientHeight = 142
  ClientWidth = 412
  Color = clActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'JetBrains Mono'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu1
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  TextHeight = 16
  object Label1: TLabel
    Left = 24
    Top = 19
    Width = 63
    Height = 16
    Caption = 'Username:'
  end
  object Label2: TLabel
    Left = 208
    Top = 21
    Width = 63
    Height = 16
    Caption = 'Password:'
  end
  object LabelErrorLogin: TLabel
    Left = 90
    Top = 19
    Width = 112
    Height = 14
    AutoSize = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object LabelErrorPassword: TLabel
    Left = 277
    Top = 19
    Width = 109
    Height = 14
    AutoSize = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -12
    Font.Name = 'Segoe UI'
    Font.Style = []
    ParentFont = False
  end
  object EditUsername: TEdit
    Left = 24
    Top = 40
    Width = 178
    Height = 24
    TabOrder = 0
  end
  object EditPassword: TEdit
    Left = 208
    Top = 39
    Width = 178
    Height = 24
    PasswordChar = #8226
    TabOrder = 1
  end
  object BtnLogin: TButton
    Left = 24
    Top = 69
    Width = 75
    Height = 25
    Caption = 'Login'
    TabOrder = 2
    OnClick = BtnLoginClick
  end
  object BtnRegister: TButton
    Left = 24
    Top = 100
    Width = 97
    Height = 25
    Caption = 'Register'
    ModalResult = 1
    TabOrder = 3
    OnClick = BtnRegisterClick
  end
  object Button3: TButton
    Left = 311
    Top = 69
    Width = 75
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 4
  end
  object LoginSaveCheck: TCheckBox
    Left = 105
    Top = 73
    Width = 106
    Height = 17
    Caption = 'Remember me'
    TabOrder = 5
  end
  object MainMenu1: TMainMenu
    Left = 72
    Top = 72
    object LanguageLoginClick: TMenuItem
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
    object ExitBtnNavLogin: TMenuItem
      Caption = 'Exit'
      OnClick = ExitBtnNavLoginClick
    end
  end
end
