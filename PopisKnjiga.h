
// ******************************************************************************************************************** //
//                                                                                                                    
//                                                  XML Data Binding                                                  
//                                                                                                                    
//         Generated on: 20/04/2024 22:28:25                                                                          
//       Generated from: C:\Users\PC\OneDrive\Documents\Embarcadero\Studio\Projects\Finalni_Projekt\PopisKnjiga.xml   
//   Settings stored in: C:\Users\PC\OneDrive\Documents\Embarcadero\Studio\Projects\Finalni_Projekt\PopisKnjiga.xdb   
//                                                                                                                    
// ******************************************************************************************************************** //

#ifndef   PopisKnjigaH
#define   PopisKnjigaH

#include <System.hpp>
#include <System.Variants.hpp>
#include <System.SysUtils.hpp>
#include <Xml.Xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.XMLDoc.hpp>
#include <XMLNodeImp.h>
#include <Xml.xmlutil.hpp>


// Forward Decls 

__interface IXMLpopisType;
typedef System::DelphiInterface<IXMLpopisType> _di_IXMLpopisType;
__interface IXMLknjigaType;
typedef System::DelphiInterface<IXMLknjigaType> _di_IXMLknjigaType;

// IXMLpopisType 

__interface INTERFACE_UUID("{B403BF51-485E-49FB-8132-1D108357D5A1}") IXMLpopisType : public Xml::Xmlintf::IXMLNodeCollection
{
public:
public:
  // Property Accessors 
  virtual _di_IXMLknjigaType __fastcall Get_knjiga(const int Index) = 0;
  // Methods & Properties 
  virtual _di_IXMLknjigaType __fastcall Add() = 0;
  virtual _di_IXMLknjigaType __fastcall Insert(const int Index) = 0;
  __property _di_IXMLknjigaType knjiga[const int Index] = { read=Get_knjiga };/* default */
};

// IXMLknjigaType 

__interface INTERFACE_UUID("{EC747D89-96A8-4ED2-9938-7C5202E27044}") IXMLknjigaType : public Xml::Xmlintf::IXMLNode
{
public:
  // Property Accessors 
  virtual int __fastcall Get_id() = 0;
  virtual System::UnicodeString __fastcall Get_naziv() = 0;
  virtual System::UnicodeString __fastcall Get_zanr() = 0;
  virtual System::UnicodeString __fastcall Get_autor() = 0;
  virtual int __fastcall Get_stranice() = 0;
  virtual void __fastcall Set_id(const int Value) = 0;
  virtual void __fastcall Set_naziv(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_zanr(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_autor(const System::UnicodeString Value) = 0;
  virtual void __fastcall Set_stranice(const int Value) = 0;
  // Methods & Properties 
  __property int id = { read=Get_id, write=Set_id };
  __property System::UnicodeString naziv = { read=Get_naziv, write=Set_naziv };
  __property System::UnicodeString zanr = { read=Get_zanr, write=Set_zanr };
  __property System::UnicodeString autor = { read=Get_autor, write=Set_autor };
  __property int stranice = { read=Get_stranice, write=Set_stranice };
};

// Forward Decls 

class TXMLpopisType;
class TXMLknjigaType;

// TXMLpopisType 

class TXMLpopisType : public Xml::Xmldoc::TXMLNodeCollection, public IXMLpopisType
{
  __IXMLNODECOLLECTION_IMPL__
protected:
  // IXMLpopisType 
  virtual _di_IXMLknjigaType __fastcall Get_knjiga(const int Index);
  virtual _di_IXMLknjigaType __fastcall Add();
  virtual _di_IXMLknjigaType __fastcall Insert(const int Index);
public:
  virtual void __fastcall AfterConstruction(void);
};

// TXMLknjigaType 

class TXMLknjigaType : public Xml::Xmldoc::TXMLNode, public IXMLknjigaType
{
  __IXMLNODE_IMPL__
protected:
  // IXMLknjigaType 
  virtual int __fastcall Get_id();
  virtual System::UnicodeString __fastcall Get_naziv();
  virtual System::UnicodeString __fastcall Get_zanr();
  virtual System::UnicodeString __fastcall Get_autor();
  virtual int __fastcall Get_stranice();
  virtual void __fastcall Set_id(const int Value);
  virtual void __fastcall Set_naziv(const System::UnicodeString Value);
  virtual void __fastcall Set_zanr(const System::UnicodeString Value);
  virtual void __fastcall Set_autor(const System::UnicodeString Value);
  virtual void __fastcall Set_stranice(const int Value);
};

// Global Functions 

_di_IXMLpopisType __fastcall Getpopis(Xml::Xmlintf::_di_IXMLDocument Doc);
_di_IXMLpopisType __fastcall Getpopis(Xml::Xmldoc::TXMLDocument *Doc);
_di_IXMLpopisType __fastcall Loadpopis(const System::UnicodeString& FileName);
_di_IXMLpopisType __fastcall  Newpopis();

#define TargetNamespace ""

#endif