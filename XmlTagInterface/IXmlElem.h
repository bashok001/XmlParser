//*************************************************************************//
// IXmlElem.h - Provides operations wrapper on FileSystem in formats    //
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
#ifndef IXMLELEM_H
#define IXMLELEM_H
#include <vector>
#include <list>

#include "../XmlAttributeInterface/ITagAttr.h"
class IXmlElem {

	public:
	using xmlTagC = std::string;
	virtual bool hasContent() = 0;
	virtual xmlTagC &getContent() = 0;

	
	//Start
	virtual bool hasAttribute( xmlTagC name ) = 0;

	virtual xmlTagC &getName()=0;
	virtual std::vector<ITagAttr *> &getAllAttributes()=0;
	virtual xmlTagC getAttributeValue( const xmlTagC& name )=0;

	virtual std::vector<IXmlElem *> &getChildren()=0;
	virtual bool addChild( IXmlElem* xmlTag ) = 0;
	virtual bool removeChild( IXmlElem* xmlTag ) = 0;
	//End
	virtual void toString(int depth, std::string& xmlStr) = 0;
	virtual xmlTagC tagString() = 0;
	xmlTagC getIdAttribute() { return _identityAttributeValue; };
	void setIdAttributeValue( const xmlTagC& idValue ) { _identityAttributeValue = idValue; };

	private:
	xmlTagC	_name;
	xmlTagC _content;
	std::vector<IXmlElem *> _children;
	std::vector<ITagAttr *> _attributes;
	xmlTagC _identityAttributeValue;
};
#endif