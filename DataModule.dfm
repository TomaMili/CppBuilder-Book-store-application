object Data_Module: TData_Module
  Height = 354
  Width = 772
  object MainConnection: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source=C:\Us' +
      'ers\PC\OneDrive\Documents\Embarcadero\Studio\Projects\Finalni_Pr' +
      'ojekt\student.mdb;Mode=Share Deny None;Persist Security Info=Fal' +
      'se;Jet OLEDB:System database="";Jet OLEDB:Registry Path="";Jet O' +
      'LEDB:Database Password="";Jet OLEDB:Engine Type=5;Jet OLEDB:Data' +
      'base Locking Mode=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLED' +
      'B:Global Bulk Transactions=1;Jet OLEDB:New Database Password="";' +
      'Jet OLEDB:Create System Database=False;Jet OLEDB:Encrypt Databas' +
      'e=False;Jet OLEDB:Don'#39't Copy Locale on Compact=False;Jet OLEDB:C' +
      'ompact Without Replica Repair=False;Jet OLEDB:SFP=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 184
    Top = 160
  end
  object TBooks: TADOTable
    Active = True
    Connection = MainConnection
    CursorType = ctStatic
    IndexFieldNames = 'ID'
    TableName = 'Knjige'
    Left = 264
    Top = 96
    object TBooksID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object TBooksNaziv: TWideStringField
      FieldName = 'Naziv'
      Size = 255
    end
    object TBooksBrStranica: TIntegerField
      FieldName = 'BrStranica'
    end
    object TBooksAutor: TWideStringField
      FieldName = 'Autor'
      Size = 255
    end
    object TBooksZanr: TWideStringField
      FieldName = 'Zanr'
      Size = 255
    end
    object TBooksIDKnjiga: TIntegerField
      FieldName = 'IDKnjiga'
    end
  end
  object DBooks: TDataSource
    DataSet = TBooks
    Left = 264
    Top = 200
  end
  object TRezervations: TADOTable
    Active = True
    Connection = MainConnection
    CursorType = ctStatic
    OnCalcFields = TRezervationsCalcFields
    TableName = 'Rezervacije'
    Left = 376
    Top = 96
    object TRezervationsID: TAutoIncField
      FieldName = 'ID'
      ReadOnly = True
    end
    object TRezervationsDatumOd: TDateTimeField
      FieldName = 'DatumOd'
    end
    object TRezervationsIDKnjige: TIntegerField
      FieldName = 'IDKnjige'
    end
    object TRezervationsIDUseri: TIntegerField
      FieldName = 'IDUseri'
    end
    object TRezervationsDatumDo: TDateTimeField
      FieldName = 'DatumDo'
    end
    object TRezervationsCijena: TBCDField
      FieldName = 'Cijena'
      Precision = 19
    end
    object TRezervationsTrajanjeRezervacije: TIntegerField
      FieldKind = fkCalculated
      FieldName = 'TrajanjeRezervacije'
      Calculated = True
    end
    object TRezervationsIme: TStringField
      FieldKind = fkLookup
      FieldName = 'Ime'
      LookupDataSet = TUsers
      LookupKeyFields = 'IDUseri'
      LookupResultField = 'Ime'
      KeyFields = 'IDUseri'
      Lookup = True
    end
  end
  object TUsers: TADOTable
    Active = True
    Connection = MainConnection
    CursorType = ctStatic
    TableName = 'Useri'
    Left = 472
    Top = 96
    object TUsersIme: TWideStringField
      FieldName = 'Ime'
      Size = 50
    end
    object TUsersPrezime: TWideStringField
      FieldName = 'Prezime'
      Size = 50
    end
    object TUsersIDUseri: TAutoIncField
      FieldName = 'IDUseri'
      ReadOnly = True
    end
    object TUsersSlika: TBlobField
      FieldName = 'Slika'
    end
  end
  object DRezervations: TDataSource
    DataSet = TRezervations
    Left = 376
    Top = 200
  end
  object DUsers: TDataSource
    DataSet = TUsers
    Left = 472
    Top = 200
  end
end
