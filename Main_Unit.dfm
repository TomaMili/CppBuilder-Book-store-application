object Form_Main: TForm_Main
  Left = 100
  Top = 100
  Caption = 'Library'
  ClientHeight = 991
  ClientWidth = 1928
  Color = clActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clBtnText
  Font.Height = -12
  Font.Name = 'JetBrains Mono'
  Font.Style = []
  Menu = MainMenu1
  OnClose = FormClose
  OnCreate = FormCreate
  DesignSize = (
    1928
    991)
  TextHeight = 16
  object Label1: TLabel
    Left = 1644
    Top = 8
    Width = 276
    Height = 27
    Alignment = taRightJustify
    Anchors = [akTop, akRight]
    AutoSize = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -21
    Font.Name = 'JetBrains Mono'
    Font.Style = [fsItalic]
    ParentFont = False
  end
  object Image1: TImage
    Left = 1707
    Top = 734
    Width = 209
    Height = 113
    Proportional = True
  end
  object LabelDownloadState: TLabel
    Left = 1544
    Top = 873
    Width = 157
    Height = 16
    Alignment = taCenter
    AutoSize = False
  end
  object Image2: TImage
    Left = 743
    Top = -159
    Width = 514
    Height = 416
    Center = True
    Proportional = True
  end
  object GroupBoxKnjige: TGroupBox
    Left = 56
    Top = 113
    Width = 897
    Height = 460
    Caption = 'All books'
    TabOrder = 0
    object ListViewGenres: TListView
      Left = 687
      Top = 32
      Width = 197
      Height = 385
      Columns = <
        item
          Caption = 'Genre'
          Width = 136
        end
        item
          Caption = 'Num'
          Width = 40
        end>
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -12
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      ViewStyle = vsReport
    end
  end
  object ListViewKnjige: TListView
    Left = 72
    Top = 145
    Width = 665
    Height = 385
    Columns = <
      item
        Caption = 'Title'
        Width = 180
      end
      item
        Caption = 'Author'
        Width = 160
      end
      item
        Caption = 'Genre'
        Width = 129
      end
      item
        Caption = 'Number of pages'
        Width = 120
      end
      item
        Caption = 'Id'
      end>
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -12
    Font.Name = 'JetBrains Mono'
    Font.Style = []
    RowSelect = True
    ParentFont = False
    TabOrder = 1
    ViewStyle = vsReport
  end
  object BtnLoadBooks: TButton
    Left = 72
    Top = 536
    Width = 75
    Height = 25
    Caption = 'Load'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -12
    Font.Name = 'JetBrains Mono'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = BtnLoadBooksClick
  end
  object BtnDeleteBooks: TButton
    Left = 153
    Top = 536
    Width = 75
    Height = 25
    Caption = 'Delete'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -12
    Font.Name = 'JetBrains Mono'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = BtnDeleteBooksClick
  end
  object BtnUpdateBooks: TButton
    Left = 234
    Top = 536
    Width = 75
    Height = 25
    Caption = 'Update'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -12
    Font.Name = 'JetBrains Mono'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = BtnUpdateBooksClick
  end
  object BtnAddBooks: TButton
    Left = 315
    Top = 536
    Width = 75
    Height = 25
    Caption = 'Add'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -12
    Font.Name = 'JetBrains Mono'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
    OnClick = BtnAddBooksClick
  end
  object GroupBox1: TGroupBox
    Left = 1036
    Top = 113
    Width = 825
    Height = 460
    Caption = 'Returned books'
    DefaultHeaderFont = False
    HeaderFont.Charset = DEFAULT_CHARSET
    HeaderFont.Color = clBtnText
    HeaderFont.Height = -12
    HeaderFont.Name = 'JetBrains Mono'
    HeaderFont.Style = []
    TabOrder = 6
    object ListViewFavKnjige: TListView
      Left = 16
      Top = 32
      Width = 793
      Height = 385
      Columns = <
        item
          Caption = 'Title'
          Width = 160
        end
        item
          Caption = 'Author'
          Width = 160
        end
        item
          Caption = 'Genre'
          Width = 109
        end
        item
          Caption = 'Number of pages'
          Width = 120
        end
        item
          Caption = 'Date'
          Width = 90
        end
        item
          Caption = 'Username'
          Width = 100
        end
        item
          Caption = 'Id'
        end>
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -12
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      RowSelect = True
      ParentFont = False
      TabOrder = 0
      ViewStyle = vsReport
    end
    object BtnAddFavBooks: TButton
      Left = 178
      Top = 423
      Width = 75
      Height = 25
      Caption = 'Add'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -12
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = BtnAddFavBooksClick
    end
    object BtnDeleteFavBooks: TButton
      Left = 97
      Top = 423
      Width = 75
      Height = 25
      Caption = 'Delete'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -12
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = BtnDeleteFavBooksClick
    end
    object BtnLoadFavBooks: TButton
      Left = 16
      Top = 423
      Width = 75
      Height = 25
      Caption = 'Load'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -12
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = BtnLoadFavBooksClick
    end
  end
  object Checkout: TGroupBox
    Left = 56
    Top = 579
    Width = 897
    Height = 404
    Caption = 'Checkout'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -12
    Font.Name = 'JetBrains Mono'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    object CheckoutTotalPriceLabel: TLabel
      Left = 342
      Top = 90
      Width = 132
      Height = 25
      Alignment = taRightJustify
      Caption = 'Total price:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -19
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      ParentFont = False
    end
    object CheckoutPDVLabel: TLabel
      Left = 375
      Top = 59
      Width = 99
      Height = 25
      Alignment = taRightJustify
      Caption = 'PDV rate:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -19
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      ParentFont = False
    end
    object CheckoutPriceLabel: TLabel
      Left = 408
      Top = 28
      Width = 66
      Height = 25
      Alignment = taRightJustify
      Caption = 'Price:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -19
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      ParentFont = False
    end
    object LabelPrice: TLabel
      Left = 480
      Top = 28
      Width = 11
      Height = 25
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -19
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      ParentFont = False
    end
    object LabelPDV: TLabel
      Left = 480
      Top = 59
      Width = 11
      Height = 25
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -19
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      ParentFont = False
    end
    object LabelFullPrice: TLabel
      Left = 480
      Top = 90
      Width = 11
      Height = 25
      Color = clAppWorkSpace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -19
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
    object CheckoutIDLabel: TLabel
      Left = 324
      Top = 269
      Width = 21
      Height = 16
      Caption = 'ID:'
    end
    object CheckoutPaidLabel: TLabel
      Left = 466
      Top = 269
      Width = 63
      Height = 16
      Caption = 'Pla'#263'eno: '
    end
    object ListViewCart: TListView
      Left = 16
      Top = 24
      Width = 302
      Height = 369
      Columns = <
        item
          Caption = 'BookID'
          Width = 70
        end
        item
          Caption = 'Title'
          Width = 128
        end
        item
          Caption = 'Price'
          Width = 100
        end>
      TabOrder = 0
      ViewStyle = vsReport
    end
    object AddBooksToBasketBtn: TButton
      Left = 324
      Top = 321
      Width = 136
      Height = 72
      Caption = 'Add'
      TabOrder = 1
      OnClick = AddBooksToBasketBtnClick
    end
    object PrintBooksFromBasketBtn: TButton
      Left = 466
      Top = 321
      Width = 136
      Height = 72
      Caption = 'Print'
      TabOrder = 2
      OnClick = PrintBooksFromBasketBtnClick
    end
    object artiklKnjigaIDEdit: TEdit
      Left = 324
      Top = 291
      Width = 136
      Height = 24
      NumbersOnly = True
      TabOrder = 3
    end
    object EditPaid: TEdit
      Left = 466
      Top = 291
      Width = 137
      Height = 24
      TabOrder = 4
    end
    object MemoChange: TMemo
      Left = 609
      Top = 24
      Width = 273
      Height = 369
      Alignment = taCenter
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -16
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      Lines.Strings = (
        '')
      ParentFont = False
      ReadOnly = True
      TabOrder = 5
    end
  end
  object GroupBox3: TGroupBox
    Left = 1036
    Top = 579
    Width = 502
    Height = 404
    Caption = 'Receipt'
    TabOrder = 8
    object MemoBill: TMemo
      Left = 16
      Top = 24
      Width = 297
      Height = 340
      Alignment = taCenter
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -13
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      Lines.Strings = (
        '')
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
    object btnSaveReceiptMFT: TButton
      Left = 15
      Top = 370
      Width = 146
      Height = 25
      Caption = 'Save'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -12
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = btnSaveReceiptMFTClick
    end
    object btnReadReceiptMFT: TButton
      Left = 167
      Top = 370
      Width = 146
      Height = 25
      Caption = 'Read'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -12
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = btnReadReceiptMFTClick
    end
    object MemoDigSignature: TMemo
      Left = 319
      Top = 24
      Width = 170
      Height = 312
      Alignment = taCenter
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -9
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      Lines.Strings = (
        '')
      ParentFont = False
      TabOrder = 3
    end
    object BtnValidateReceipt: TButton
      Left = 319
      Top = 370
      Width = 170
      Height = 25
      Caption = 'Validate receipt'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -12
      Font.Name = 'JetBrains Mono'
      Font.Style = []
      ParentFont = False
      TabOrder = 4
      OnClick = BtnValidateReceiptClick
    end
    object EReceiptNum: TEdit
      Left = 319
      Top = 342
      Width = 170
      Height = 24
      TabOrder = 5
    end
  end
  object Button2: TButton
    Left = 1707
    Top = 964
    Width = 209
    Height = 25
    Caption = 'Chat'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -12
    Font.Name = 'JetBrains Mono'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
    OnClick = Button2Click
  end
  object ListBoxNotifications: TListBox
    Left = 1707
    Top = 845
    Width = 209
    Height = 113
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -12
    Font.Name = 'JetBrains Mono'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
  end
  object ComboBox1: TComboBox
    Left = 1544
    Top = 895
    Width = 157
    Height = 24
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -12
    Font.Name = 'JetBrains Mono'
    Font.Style = []
    ItemIndex = 0
    ParentFont = False
    TabOrder = 11
    Text = '50 kb/s'
    OnChange = ComboBox1Change
    Items.Strings = (
      '50 kb/s'
      '100 kb/s'
      '200 kb/s'
      '1000 kb/s')
  end
  object ProgressBar1: TProgressBar
    Left = 1544
    Top = 925
    Width = 157
    Height = 25
    TabOrder = 12
  end
  object BtnDownloadTerms: TButton
    Left = 1544
    Top = 956
    Width = 157
    Height = 26
    Caption = 'Terms of services'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBtnText
    Font.Height = -12
    Font.Name = 'JetBrains Mono'
    Font.Style = []
    ParentFont = False
    TabOrder = 13
    OnClick = BtnDownloadTermsClick
  end
  object MainMenu1: TMainMenu
    Left = 320
    Top = 312
    object LoginMenuClick: TMenuItem
      Caption = 'Login'
      OnClick = LoginMenuClickClick
    end
    object LanguageMenuClick: TMenuItem
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
    object Reservations1: TMenuItem
      Caption = 'Reservations'
      OnClick = Reservations1Click
    end
  end
  object ActionList1: TActionList
    Left = 400
    Top = 312
    object Action1: TAction
      Caption = 'Action1'
    end
    object Action2: TAction
      Caption = 'Action2'
    end
  end
  object PopisKnjiga: TXMLDocument
    Active = True
    FileName = 
      'C:\Users\PC\OneDrive\Documents\Embarcadero\Studio\Projects\Final' +
      'ni_Projekt\PopisKnjiga.xml'
    NodeIndentStr = #9
    Options = [doNodeAutoCreate, doNodeAutoIndent, doAttrNull, doAutoPrefix, doNamespaceDecl, doAutoSave]
    Left = 480
    Top = 312
  end
  object IdInterceptThrottler1: TIdInterceptThrottler
    BitsPerSec = 409600
    RecvBitsPerSec = 409600
    SendBitsPerSec = 409600
    Left = 1568
    Top = 632
  end
  object IdSSLIOHandlerSocketOpenSSL1: TIdSSLIOHandlerSocketOpenSSL
    Intercept = IdInterceptThrottler1
    MaxLineAction = maException
    Port = 0
    DefaultPort = 0
    SSLOptions.Mode = sslmUnassigned
    SSLOptions.VerifyMode = []
    SSLOptions.VerifyDepth = 0
    Left = 1680
    Top = 632
  end
  object TIdHTTP1: TIdHTTP
    Intercept = IdInterceptThrottler1
    IOHandler = IdSSLIOHandlerSocketOpenSSL1
    OnWork = TIdHTTP1Work
    OnWorkBegin = TIdHTTP1WorkBegin
    OnWorkEnd = TIdHTTP1WorkEnd
    ProxyParams.BasicAuthentication = False
    ProxyParams.ProxyPort = 0
    Request.ContentLength = -1
    Request.ContentRangeEnd = -1
    Request.ContentRangeStart = -1
    Request.ContentRangeInstanceLength = -1
    Request.Accept = 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8'
    Request.BasicAuthentication = False
    Request.UserAgent = 'Mozilla/3.0 (compatible; Indy Library)'
    Request.Ranges.Units = 'bytes'
    Request.Ranges = <>
    HTTPOptions = [hoForceEncodeParams]
    Left = 1800
    Top = 632
  end
  object RESTClient1: TRESTClient
    Params = <>
    SynchronizedEvents = False
    Left = 1568
    Top = 696
  end
  object RESTRequest1: TRESTRequest
    Client = RESTClient1
    Params = <
      item
        Name = 'word'
      end>
    Response = RESTResponse1
    SynchronizedEvents = False
    Left = 1616
    Top = 696
  end
  object RESTResponse1: TRESTResponse
    Left = 1664
    Top = 696
  end
end
