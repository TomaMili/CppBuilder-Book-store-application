
// ******************************************************************************************************************** //
//                                                                                                                    
//                                                  XML Data Binding                                                  
//                                                                                                                    
//         Generated on: 20/04/2024 22:28:25                                                                          
//       Generated from: C:\Users\PC\OneDrive\Documents\Embarcadero\Studio\Projects\Finalni_Projekt\PopisKnjiga.xml   
//   Settings stored in: C:\Users\PC\OneDrive\Documents\Embarcadero\Studio\Projects\Finalni_Projekt\PopisKnjiga.xdb   
//                                                                                                                    
// ******************************************************************************************************************** //

#include <System.hpp>
#pragma hdrstop

#include "PopisKnjiga.h"


// Global Functions 

_di_IXMLpopisType __fastcall Getpopis(Xml::Xmlintf::_di_IXMLDocument Doc)
{
  return (_di_IXMLpopisType) Doc->GetDocBinding("popis", __classid(TXMLpopisType), TargetNamespace);
};

_di_IXMLpopisType __fastcall Getpopis(Xml::Xmldoc::TXMLDocument *Doc)
{
  Xml::Xmlintf::_di_IXMLDocument DocIntf;
  Doc->GetInterface(DocIntf);
  return Getpopis(DocIntf);
};

_di_IXMLpopisType __fastcall Loadpopis(const System::UnicodeString& FileName)
{
  return (_di_IXMLpopisType) Xml::Xmldoc::LoadXMLDocument(FileName)->GetDocBinding("popis", __classid(TXMLpopisType), TargetNamespace);
};

_di_IXMLpopisType __fastcall  Newpopis()
{
  return (_di_IXMLpopisType) Xml::Xmldoc::NewXMLDocument()->GetDocBinding("popis", __classid(TXMLpopisType), TargetNamespace);
};

// TXMLpopisType 

void __fastcall TXMLpopisType::AfterConstruction(void)
{
  RegisterChildNode(System::UnicodeString("knjiga"), __classid(TXMLknjigaType));
  ItemTag = "knjiga";
  ItemInterface = __uuidof(IXMLknjigaType);
  Xml::Xmldoc::TXMLNodeCollection::AfterConstruction();
};

_di_IXMLknjigaType __fastcall TXMLpopisType::Get_knjiga(const int Index)
{
  return (_di_IXMLknjigaType) List->Nodes[Index];
};

_di_IXMLknjigaType __fastcall TXMLpopisType::Add()
{
  return (_di_IXMLknjigaType) AddItem(-1);
};

_di_IXMLknjigaType __fastcall TXMLpopisType::Insert(const int Index)
{
  return (_di_IXMLknjigaType) AddItem(Index);
};

// TXMLknjigaType 

int __fastcall TXMLknjigaType::Get_id()
{
  return XmlStrToInt(GetChildNodes()->Nodes[System::UnicodeString("id")]->Text);
};

void __fastcall TXMLknjigaType::Set_id(const int Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("id")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLknjigaType::Get_naziv()
{
  return GetChildNodes()->Nodes[System::UnicodeString("naziv")]->Text;
};

void __fastcall TXMLknjigaType::Set_naziv(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("naziv")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLknjigaType::Get_zanr()
{
  return GetChildNodes()->Nodes[System::UnicodeString("zanr")]->Text;
};

void __fastcall TXMLknjigaType::Set_zanr(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("zanr")]->NodeValue = Value;
};

System::UnicodeString __fastcall TXMLknjigaType::Get_autor()
{
  return GetChildNodes()->Nodes[System::UnicodeString("autor")]->Text;
};

void __fastcall TXMLknjigaType::Set_autor(const System::UnicodeString Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("autor")]->NodeValue = Value;
};

int __fastcall TXMLknjigaType::Get_stranice()
{
  return XmlStrToInt(GetChildNodes()->Nodes[System::UnicodeString("stranice")]->Text);
};

void __fastcall TXMLknjigaType::Set_stranice(const int Value)
{
  GetChildNodes()->Nodes[System::UnicodeString("stranice")]->NodeValue = Value;
};
