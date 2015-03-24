//*************************************************************************//
// XmlTaggedElem.h - Provides operations wrapper on FileSystem in formats    //
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
#ifndef XMLTAGGEDELEM_H
#define XMLTAGGEDELEM_H

#include "../XmlTagInterface/IXmlElem.h"
#include "../Utilities/Utilities.h"

class XmlTaggedElem : public  IXmlElem {

	public:
	XmlTaggedElem();
	XmlTaggedElem( const std::string& tagName ) :_name( tagName ) {};
	~XmlTaggedElem();
	XmlTaggedElem( XmlTaggedElem& xmlTagElem );
	XmlTaggedElem& XmlTaggedElem::operator=( XmlTaggedElem& xmlTaggedElem );
	XmlTaggedElem& XmlTaggedElem::operator=( XmlTaggedElem&& xmlTaggedElem );
	bool hasAttribute( xmlTagC name );
	ITagAttr* getAttribute( const xmlTagC& name );
	xmlTagC getAttributeValue( const xmlTagC& name );
	void addAttribute( ITagAttr *attr ) { _attributes.push_back( attr ); }
	bool removeAttribute( const xmlTagC& name );
	std::vector<ITagAttr *> &getAllAttributes();

	xmlTagC &getName();
	void setName( const xmlTagC& name ) { _name = name; }

	bool hasContent();
	xmlTagC &getContent();
	void setContent( const xmlTagC& content ) { _content = content; }

	std::list<IXmlElem *> &getChildren();
	bool addChild( IXmlElem* xmlTag );
	bool removeChild( IXmlElem* xmlTag );

	void toString( int depth,std::string& xmlStr );
	xmlTagC tagString();

	private:
	xmlTagC	_name;
	xmlTagC _content;
	std::list<IXmlElem *> _children;
	std::vector<ITagAttr *> _attributes;
	Utilities* _util;
};

#endif