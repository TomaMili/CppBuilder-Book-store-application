object Form_BookInput: TForm_BookInput
  Left = 0
  Top = 0
  Caption = 'Book input'
  ClientHeight = 190
  ClientWidth = 418
  Color = clActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'JetBrains Mono'
  Font.Style = []
  Menu = MainMenu1
  OnClose = FormClose
  OnShow = FormShow
  TextHeight = 16
  object BookInputTitleLabel: TLabel
    Left = 24
    Top = 19
    Width = 42
    Height = 16
    Caption = 'Title:'
  end
  object BookInputAuthorLabel: TLabel
    Left = 24
    Top = 75
    Width = 49
    Height = 16
    Caption = 'Author:'
  end
  object BookInputPagesLabel: TLabel
    Left = 232
    Top = 19
    Width = 112
    Height = 16
    Caption = 'Number of pages:'
  end
  object BookInputGenreLabel: TLabel
    Left = 232
    Top = 75
    Width = 42
    Height = 16
    Caption = 'Genre:'
  end
  object TitleInput: TEdit
    Left = 24
    Top = 41
    Width = 161
    Height = 24
    TabOrder = 0
  end
  object AuthorInput: TEdit
    Left = 24
    Top = 96
    Width = 161
    Height = 24
    TabOrder = 1
  end
  object PageNumberInput: TEdit
    Left = 232
    Top = 40
    Width = 145
    Height = 24
    NumbersOnly = True
    TabOrder = 2
  end
  object BtnInputSave: TButton
    Left = 24
    Top = 136
    Width = 353
    Height = 25
    Caption = 'Save'
    ModalResult = 1
    TabOrder = 3
    OnClick = BtnInputSaveClick
  end
  object GenreInput: TEdit
    Left = 232
    Top = 96
    Width = 145
    Height = 24
    TabOrder = 4
  end
  object MainMenu1: TMainMenu
    Left = 240
    Top = 128
    object Language1: TMenuItem
      Caption = 'Language'
      object Eng1: TMenuItem
        Caption = 'Eng'
        OnClick = Eng1Click
      end
      object Hrv1: TMenuItem
        Caption = 'Hrv'
        OnClick = Hrv1Click
      end
    end
  end
end
