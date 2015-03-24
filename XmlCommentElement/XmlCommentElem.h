//*************************************************************************//
// XmlCommentElem.h - Provides operations wrapper on FileSystem in formats    //
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
#ifndef XMLCOMMENTELEM_H
#define XMLCOMMENTELEM_H
#include "../XmlTagInterface/IXmlElem.h"
#include "../Utilities/Utilities.h"

class XmlCommentElem : public  IXmlElem {

	public:
	XmlCommentElem();
	~XmlCommentElem();
	XmlCommentElem( XmlCommentElem& xmlCommentElem );
	XmlCommentElem& XmlCommentElem::operator=( XmlCommentElem& xmlCommentElem );
	XmlCommentElem& XmlCommentElem::operator=( XmlCommentElem&& xmlCommentElem );
	bool hasContent();
	xmlTagC &getContent();
	void setContent( const xmlTagC& comment ) { _content = comment; };
	void toString( int depth,std::string& xmlStr );
	xmlTagC tagString();

	private:
	xmlTagC _content;
	Utilities* _util;

	bool hasAttribute( IXmlElem::xmlTagC name ) { return false; }
	std::vector<ITagAttr *> &getAllAttributes() { std::vector<ITagAttr *> *empty = new std::vector<ITagAttr *>;  return *empty; }
	std::list<IXmlElem *> &getChildren() { std::list<IXmlElem *> *empty = new std::list<IXmlElem *>;  return *empty; }
	IXmlElem::xmlTagC &getName() { return _content; }
	IXmlElem::xmlTagC getAttributeValue( const xmlTagC& name ) { return ""; }
	bool addChild( IXmlElem* xmlTag ) { return false; }
	bool removeChild( IXmlElem* xmlTag ) { return false; }
};

#endif