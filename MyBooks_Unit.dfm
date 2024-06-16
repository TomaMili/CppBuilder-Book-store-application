object Form_MyBooks: TForm_MyBooks
  Left = 102
  Top = 21
  Caption = 'Form_MyBooks'
  ClientHeight = 990
  ClientWidth = 1299
  Color = clActiveCaption
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'JetBrains Mono'
  Font.Style = []
  Menu = MainMenu1
  Position = poDesigned
  OnShow = FormShow
  TextHeight = 16
  object Users: TGroupBox
    Left = 24
    Top = 32
    Width = 1257
    Height = 225
    Caption = 'Users'
    TabOrder = 0
    object ReservationsUsersNameLabel: TLabel
      Left = 695
      Top = 58
      Width = 35
      Height = 16
      Caption = 'Name:'
    end
    object ReservationsUsersSurnameLabel: TLabel
      Left = 695
      Top = 115
      Width = 56
      Height = 16
      Caption = 'Surname:'
    end
    object DBGrid1: TDBGrid
      Left = 16
      Top = 27
      Width = 673
      Height = 185
      DataSource = Data_Module.DUsers
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgMultiSelect, dgTitleClick, dgTitleHotTrack]
      ReadOnly = True
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -12
      TitleFont.Name = 'JetBrains Mono'
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = 'Ime'
          Width = 290
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'Prezime'
          Width = 290
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'IDUseri'
          Width = 57
          Visible = True
        end>
    end
    object EditUsersName: TEdit
      Left = 695
      Top = 77
      Width = 154
      Height = 24
      TabOrder = 1
    end
    object EditUsersSurname: TEdit
      Left = 695
      Top = 136
      Width = 154
      Height = 24
      TabOrder = 2
    end
    object BtnSaveTUser: TButton
      Left = 695
      Top = 184
      Width = 75
      Height = 25
      Caption = 'Save'
      TabOrder = 3
      OnClick = BtnSaveTUserClick
    end
    object BtnDeleteTUser: TButton
      Left = 776
      Top = 184
      Width = 73
      Height = 25
      Caption = 'Delete'
      TabOrder = 4
      OnClick = BtnDeleteTUserClick
    end
    object BtnEditTUser: TButton
      Left = 855
      Top = 184
      Width = 75
      Height = 25
      Caption = 'Edit'
      TabOrder = 5
      OnClick = BtnEditTUserClick
    end
    object BtnReadTUser: TButton
      Left = 936
      Top = 184
      Width = 75
      Height = 25
      Caption = 'Read'
      TabOrder = 6
      OnClick = BtnReadTUserClick
    end
    object DBImage1: TDBImage
      Left = 1028
      Top = 16
      Width = 205
      Height = 161
      DataField = 'Slika'
      DataSource = Data_Module.DUsers
      Proportional = True
      TabOrder = 7
    end
    object BtnLoadImageTUser: TButton
      Left = 1028
      Top = 183
      Width = 99
      Height = 25
      Caption = 'Load'
      TabOrder = 8
      OnClick = BtnLoadImageTUserClick
    end
    object BtnDeleteImageTUser: TButton
      Left = 1133
      Top = 183
      Width = 100
      Height = 25
      Caption = 'Delete'
      TabOrder = 9
      OnClick = BtnDeleteImageTUserClick
    end
  end
  object Books: TGroupBox
    Left = 24
    Top = 263
    Width = 1257
    Height = 225
    Caption = 'Books'
    TabOrder = 1
    object ReservationsBooksIDLabel: TLabel
      Left = 919
      Top = 123
      Width = 56
      Height = 16
      Caption = 'Book ID:'
    end
    object ReservationsBooksGenreLabel: TLabel
      Left = 919
      Top = 24
      Width = 49
      Height = 16
      Caption = 'Genre: '
    end
    object DBGrid2: TDBGrid
      Left = 16
      Top = 24
      Width = 889
      Height = 185
      DataSource = Data_Module.DBooks
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgMultiSelect, dgTitleClick, dgTitleHotTrack]
      ReadOnly = True
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -12
      TitleFont.Name = 'JetBrains Mono'
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = 'ID'
          Width = 50
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'Naziv'
          Width = 200
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'Autor'
          Width = 210
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'Zanr'
          Width = 180
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'BrStranica'
          Width = 125
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'IDKnjiga'
          Width = 85
          Visible = True
        end>
    end
    object BtnSaveTBooks: TButton
      Left = 919
      Top = 184
      Width = 75
      Height = 25
      Caption = 'Save'
      TabOrder = 1
      OnClick = BtnSaveTBooksClick
    end
    object EditBooksID: TEdit
      Left = 919
      Top = 144
      Width = 154
      Height = 24
      NumbersOnly = True
      TabOrder = 2
    end
    object BtnDeleteTBooks: TButton
      Left = 1000
      Top = 184
      Width = 73
      Height = 25
      Caption = 'Delete'
      TabOrder = 3
      OnClick = BtnDeleteTBooksClick
    end
    object BtnEditTBooks: TButton
      Left = 1079
      Top = 184
      Width = 75
      Height = 25
      Caption = 'Edit'
      TabOrder = 4
      OnClick = BtnEditTBooksClick
    end
    object BtnReadTBooks: TButton
      Left = 1160
      Top = 184
      Width = 75
      Height = 25
      Caption = 'Read'
      TabOrder = 5
      OnClick = BtnReadTBooksClick
    end
    object btnSortGenre: TButton
      Left = 492
      Top = 24
      Width = 181
      Height = 21
      Caption = 'Genre'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 6
      OnClick = btnSortGenreClick
    end
    object btnSortAuthor: TButton
      Left = 280
      Top = 24
      Width = 217
      Height = 21
      Caption = 'Author'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      OnClick = btnSortAuthorClick
    end
    object btnSortNumPages: TButton
      Left = 672
      Top = 24
      Width = 129
      Height = 21
      Caption = 'Pages'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 8
      OnClick = btnSortNumPagesClick
    end
    object btnSortBookID: TButton
      Left = 800
      Top = 24
      Width = 84
      Height = 21
      Caption = 'BookID'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 9
      OnClick = btnSortBookIDClick
    end
    object btnSortTitle: TButton
      Left = 80
      Top = 24
      Width = 201
      Height = 21
      Caption = 'Title'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 10
      OnClick = btnSortTitleClick
    end
    object btnSortID: TButton
      Left = 29
      Top = 24
      Width = 51
      Height = 21
      Caption = 'ID'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Segoe UI'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 11
      OnClick = btnSortIDClick
    end
    object filterTextBox: TEdit
      Left = 919
      Top = 45
      Width = 154
      Height = 24
      TabOrder = 12
    end
    object filterCheckBox: TCheckBox
      Left = 1088
      Top = 48
      Width = 66
      Height = 17
      Caption = 'Filter'
      TabOrder = 13
      OnClick = filterCheckBoxClick
    end
  end
  object Reservations: TGroupBox
    Left = 24
    Top = 494
    Width = 1257
    Height = 235
    Caption = 'Reservations'
    TabOrder = 2
    object ReservationsReservationsToLabel: TLabel
      Left = 1112
      Top = 139
      Width = 21
      Height = 16
      Caption = 'To:'
    end
    object ReservationsReservationsFromLabel: TLabel
      Left = 1112
      Top = 83
      Width = 35
      Height = 16
      Caption = 'From:'
    end
    object DBGrid3: TDBGrid
      Left = 16
      Top = 24
      Width = 1073
      Height = 177
      DataSource = Data_Module.DRezervations
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgMultiSelect, dgTitleClick, dgTitleHotTrack]
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -12
      TitleFont.Name = 'JetBrains Mono'
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = 'ID'
          Width = 60
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'Ime'
          Width = 180
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'DatumOd'
          Width = 200
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'DatumDo'
          Width = 200
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'Cijena'
          Width = 143
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'TrajanjeRezervacije'
          Width = 150
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'IDKnjige'
          Width = 100
          Visible = True
        end>
    end
    object EditDateToRes: TDatePicker
      Left = 1112
      Top = 160
      Width = 121
      Height = 25
      Date = 45423.000000000000000000
      DateFormat = 'dd/mm/yyyy'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      TabOrder = 1
    end
    object EditDateFromRes: TDatePicker
      Left = 1112
      Top = 104
      Width = 121
      Height = 25
      Date = 45423.000000000000000000
      DateFormat = 'dd/mm/yyyy'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Segoe UI'
      Font.Style = []
      TabOrder = 2
    end
    object BtnSaveDB: TButton
      Left = 16
      Top = 207
      Width = 75
      Height = 25
      Caption = 'Save'
      TabOrder = 3
      OnClick = BtnSaveDBClick
    end
    object BtnDeleteDB: TButton
      Left = 97
      Top = 207
      Width = 75
      Height = 25
      Caption = 'Delete'
      TabOrder = 4
      OnClick = BtnDeleteDBClick
    end
    object BtnEditDB: TButton
      Left = 178
      Top = 207
      Width = 75
      Height = 25
      Caption = 'Edit'
      TabOrder = 5
      OnClick = BtnEditDBClick
    end
    object BtnReadDB: TButton
      Left = 259
      Top = 207
      Width = 75
      Height = 25
      Caption = 'Read'
      TabOrder = 6
      OnClick = BtnReadDBClick
    end
    object btnShowReport: TButton
      Left = 919
      Top = 207
      Width = 170
      Height = 25
      Caption = 'Print'
      TabOrder = 7
      OnClick = btnShowReportClick
    end
  end
  object MemoWordSearch: TMemo
    Left = 242
    Top = 732
    Width = 793
    Height = 221
    Alignment = taCenter
    TabOrder = 3
  end
  object EWordSearch: TEdit
    Left = 845
    Top = 959
    Width = 190
    Height = 24
    TabOrder = 4
  end
  object BtnWordSearch: TButton
    Left = 242
    Top = 957
    Width = 190
    Height = 25
    Caption = 'Search'
    TabOrder = 5
    OnClick = BtnWordSearchClick
  end
  object frxReport1: TfrxReport
    Version = '2022.2.7'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick, pbCopy, pbSelection]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 45426.005637025500000000
    ReportOptions.LastChange = 45427.936875370370000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 472
    Top = 120
    Datasets = <
      item
        DataSet = frxReservations
        DataSetName = 'frxReservations'
      end
      item
        DataSet = frxUsers
        DataSetName = 'frxUsers'
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 215.900000000000000000
      PaperHeight = 279.400000000000000000
      PaperSize = 1
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Frame.Typ = []
      MirrorMode = []
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 94.488250000000000000
        Top = 18.897650000000000000
        Width = 740.409927000000000000
        object Memo1: TfrxMemoView
          Align = baCenter
          AllowVectorExport = True
          Left = 273.826948500000000000
          Width = 192.756030000000000000
          Height = 37.795300000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -27
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'REZERVACIJE')
          ParentFont = False
        end
      end
      object MasterData2: TfrxMasterData
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 124.724490000000000000
        Top = 173.858380000000000000
        Width = 740.409927000000000000
        DataSet = frxReservations
        DataSetName = 'frxReservations'
        RowCount = 0
        object Memo2: TfrxMemoView
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 45.354360000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Ime: ')
          ParentFont = False
        end
        object Memo4: TfrxMemoView
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 15.118120000000000000
          Width = 113.385900000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Rezervacija ID:')
          ParentFont = False
        end
        object frxReservationsDatumOd: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 551.811380000000000000
          Top = 15.118120000000000000
          Width = 71.811070000000000000
          Height = 18.897650000000000000
          DataField = 'DatumOd'
          DataSet = frxReservations
          DataSetName = 'frxReservations'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxReservations."DatumOd"]')
        end
        object frxReservationsDatumDo: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 638.740570000000000000
          Top = 15.118120000000000000
          Width = 177.637910000000000000
          Height = 18.897650000000000000
          DataField = 'DatumDo'
          DataSet = frxReservations
          DataSetName = 'frxReservations'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxReservations."DatumDo"]')
        end
        object Memo5: TfrxMemoView
          AllowVectorExport = True
          Left = 627.401980000000000000
          Top = 15.118120000000000000
          Width = 30.236240000000000000
          Height = 22.677180000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            '-')
        end
        object frxReservationsCijena: TfrxMemoView
          IndexTag = 1
          Anchors = [fraTop, fraRight]
          AllowVectorExport = True
          Left = 551.811380000000000000
          Top = 45.354360000000000000
          Width = 37.795300000000000000
          Height = 18.897650000000000000
          DataField = 'Cijena'
          DataSet = frxReservations
          DataSetName = 'frxReservations'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxReservations."Cijena"]')
        end
        object Memo6: TfrxMemoView
          AllowVectorExport = True
          Left = 574.488560000000000000
          Top = 45.354360000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            #8364)
        end
        object Memo7: TfrxMemoView
          AllowVectorExport = True
          Left = 400.630180000000000000
          Top = 15.118120000000000000
          Width = 158.740260000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Razdoblje rezervacije:')
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          AllowVectorExport = True
          Left = 400.630180000000000000
          Top = 45.354360000000000000
          Width = 52.913420000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'Cijena:')
          ParentFont = False
        end
        object Memo9: TfrxMemoView
          AllowVectorExport = True
          Left = 400.630180000000000000
          Top = 79.370130000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'ID Knjige:')
          ParentFont = False
        end
        object frxReservationsIDKnjige: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 551.811380000000000000
          Top = 79.370130000000000000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          DataField = 'IDKnjige'
          DataSet = frxReservations
          DataSetName = 'frxReservations'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxReservations."IDKnjige"]')
        end
        object Line1: TfrxLineView
          AllowVectorExport = True
          Top = 124.724490000000000000
          Width = 740.787880000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line2: TfrxLineView
          AllowVectorExport = True
          Width = 740.787880000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line3: TfrxLineView
          AllowVectorExport = True
          Top = 124.724490000000000000
          Height = -124.724490000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object Line4: TfrxLineView
          AllowVectorExport = True
          Left = 740.787880000000000000
          Top = 124.724490000000000000
          Height = -124.724490000000000000
          Color = clBlack
          Frame.Typ = []
          Diagonal = True
        end
        object frxReservationsIme: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 120.944960000000000000
          Top = 45.354360000000000000
          Width = 158.740260000000000000
          Height = 18.897650000000000000
          DataField = 'Ime'
          DataSet = frxReservations
          DataSetName = 'frxReservations'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxReservations."Ime"]')
        end
        object frxReservationsID: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 120.944960000000000000
          Top = 15.118120000000000000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          DataField = 'ID'
          DataSet = frxReservations
          DataSetName = 'frxReservations'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxReservations."ID"]')
        end
        object Memo10: TfrxMemoView
          AllowVectorExport = True
          Left = 7.559060000000000000
          Top = 79.370130000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Frame.Typ = []
          Memo.UTF8W = (
            'User ID:')
          ParentFont = False
        end
        object frxReservationsIDUseri: TfrxMemoView
          IndexTag = 1
          AllowVectorExport = True
          Left = 120.944960000000000000
          Top = 79.370130000000000000
          Width = 79.370130000000000000
          Height = 18.897650000000000000
          DataField = 'IDUseri'
          DataSet = frxReservations
          DataSetName = 'frxReservations'
          Frame.Typ = []
          Memo.UTF8W = (
            '[frxReservations."IDUseri"]')
        end
      end
      object ReportSummary1: TfrxReportSummary
        FillType = ftBrush
        FillGap.Top = 0
        FillGap.Left = 0
        FillGap.Bottom = 0
        FillGap.Right = 0
        Frame.Typ = []
        Height = 52.913420000000000000
        Top = 359.055350000000000000
        Width = 740.409927000000000000
        object Memo11: TfrxMemoView
          AllowVectorExport = True
          Left = 540.472790000000000000
          Top = 30.236240000000000000
          Width = 117.165430000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            'Izvje'#353'taj generiran:')
        end
        object Memo12: TfrxMemoView
          AllowVectorExport = True
          Left = 657.638220000000000000
          Top = 30.236240000000000000
          Width = 83.149660000000000000
          Height = 18.897650000000000000
          Frame.Typ = []
          Memo.UTF8W = (
            '[Date]')
        end
      end
    end
  end
  object frxReservations: TfrxDBDataset
    UserName = 'frxReservations'
    CloseDataSource = False
    DataSet = Data_Module.TRezervations
    BCDToCurrency = False
    DataSetOptions = []
    Left = 472
    Top = 64
  end
  object frxPDFExport1: TfrxPDFExport
    UseFileCache = True
    ShowProgress = True
    OverwritePrompt = False
    DataOnly = False
    EmbedFontsIfProtected = False
    InteractiveFormsFontSubset = 'A-Z,a-z,0-9,#43-#47 '
    OpenAfterExport = False
    PrintOptimized = False
    Outline = False
    Background = False
    HTMLTags = True
    Quality = 95
    Author = 'FastReport'
    Subject = 'FastReport PDF export'
    Creator = 'FastReport'
    ProtectionFlags = [ePrint, eModify, eCopy, eAnnot]
    HideToolbar = False
    HideMenubar = False
    HideWindowUI = False
    FitWindow = False
    CenterWindow = False
    PrintScaling = False
    PdfA = False
    PDFStandard = psNone
    PDFVersion = pv17
    Left = 584
    Top = 56
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = '*.bmp'
    Left = 584
    Top = 192
  end
  object frxUsers: TfrxDBDataset
    UserName = 'frxUsers'
    CloseDataSource = False
    DataSet = Data_Module.TUsers
    BCDToCurrency = False
    DataSetOptions = []
    Left = 472
    Top = 184
  end
  object MainMenu1: TMainMenu
    Left = 584
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
    object ExitBtnNav: TMenuItem
      Caption = 'Exit'
      OnClick = ExitBtnNavClick
    end
  end
  object RESTClient1: TRESTClient
    Params = <>
    SynchronizedEvents = False
    Left = 1112
    Top = 752
  end
  object RESTRequest1: TRESTRequest
    Client = RESTClient1
    Params = <>
    Response = RESTResponse1
    SynchronizedEvents = False
    Left = 1152
    Top = 816
  end
  object RESTResponse1: TRESTResponse
    Left = 1240
    Top = 816
  end
  object BindingsList1: TBindingsList
    Methods = <>
    OutputConverters = <>
    Left = 20
    Top = 5
  end
end
