//*************************************************************************//
// XmlProcElem.h - Provides operations wrapper on FileSystem in formats    //
//					needed by this app                                     //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyleft © Ashok Bommisetti, 2015                                       //
// No guarantees on anything; But free to modify, copy and distribute      //
// ----------------------------------------------------------------------- //
// Author:      Ashok Bommisetti							               //
// First Published (mm-dd-yyyy): 03-24-2015 			                   //
//*************************************************************************//
/*
* Package Operations:
* ==================
* This package is intended to help students in CSE687 - Object Oriented Design
* get started with Project #2 - XML Document Model.  It uses C++11 constructs,
* most noteably std::shared_ptr.  The XML Document Model is essentially
* a program-friendly wrapper around an Abstract Syntax Tree (AST) used to
* contain the results of parsing XML markup.
*
* Public Interface:
* =================
*
*
* Required Files:
* ---------------
*   - Display.h, Display.cpp
*
* Build Process:
* --------------
*   devenv XMLParser.sln /debug rebuild
*
* Maintenance History:
* --------------------
* Only first version out
*/
#ifndef XMLPROCELEM_H
#define XMLPROCELEM_H
#include "../XmlTagInterface/IXmlElem.h"
#include "../Utilities/Utilities.h"

class XmlProcElem : public  IXmlElem {

	public:
	XmlProcElem();
	~XmlProcElem();
	XmlProcElem( XmlProcElem& xmlProcElement );
	XmlProcElem( XmlProcElem&& xmlProcElement );
	XmlProcElem& XmlProcElem::operator=( XmlProcElem& xmlProcElem );
	XmlProcElem& XmlProcElem::operator=( XmlProcElem&& xmlProcElem );
	bool hasContent();
	bool hasAttribute( xmlTagC name );
	xmlTagC getAttributeValue( const xmlTagC& name );
	xmlTagC &getName();
	void setName( const xmlTagC& name ) { _name = name; };
	xmlTagC &getContent();
	void setContent( const xmlTagC& content ) { _content = content; };
	void addAttribute( ITagAttr *attr ) { _attributes.push_back(attr); }
	std::vector<ITagAttr *> &getAllAttributes();
	void toString( int depth,std::string& xmlStr );
	xmlTagC tagString();

	private:
	xmlTagC	_name;
	xmlTagC _content;
	std::vector<ITagAttr *> _attributes;
	Utilities* _util;
	std::vector<IXmlElem *> &getChildren() { std::vector<IXmlElem *> *empty = new std::vector<IXmlElem *>;  return *empty; };
	virtual bool addChild( IXmlElem* xmlTag ) { return false; }
	virtual bool removeChild( IXmlElem* xmlTag ) { return false; }
	
};

#endif