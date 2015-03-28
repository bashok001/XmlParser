//*************************************************************************//
// XmlCommentElem.h - Comment Element                                     //
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
* This package is to support creation of comment elements
*
* Public Interface:
* =================
*	XmlCommentElem() //Constructor
*	~XmlCommentElem() // Destructor
*	XmlCommentElem( XmlCommentElem& xmlCommentElem ) // Copy Constructor
*	XmlCommentElem( XmlCommentElem&& xmlCommentElem ) // Move Constructor
*	XmlCommentElem& XmlCommentElem::operator=( XmlCommentElem& xmlCommentElem ); // Copy Assignment Operator
*	XmlCommentElem& XmlCommentElem::operator=( XmlCommentElem&& xmlCommentElem ); // Move Assignment Operator
*	bool hasContent(); // Returns true if content is present in the comments
*	xmlTagC &getContent(); // Returns content
*	void setContent( const xmlTagC& comment ); // Setter for _content
*	void toString( int depth,std::string& xmlStr ); // toString() descendants 
*	xmlTagC tagString(); // Prints the tag into string
*
* Required Files:
* ---------------
*   - XmlCommentElem.h, XmlCommentElem.cpp
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
	XmlCommentElem( XmlCommentElem&& xmlCommentElem );
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
	std::vector<IXmlElem *> &getChildren() { std::vector<IXmlElem *> *empty = new std::vector<IXmlElem *>;  return *empty; }
	IXmlElem::xmlTagC &getName() { return _content; }
	IXmlElem::xmlTagC getAttributeValue( const xmlTagC& name ) { return ""; }
	bool addChild( IXmlElem* xmlTag ) { return false; }
	bool removeChild( IXmlElem* xmlTag ) { return false; }
};

#endif