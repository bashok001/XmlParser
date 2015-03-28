//*************************************************************************//
// XmlProcElem.h - Processing Instruction Element                          //
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
* This package is to support creation of processing instruction elements
*
* Public Interface:
* =================
*	XmlProcElem(); //Constructor
*   ~XmlProcElem(); //Destructor
*	XmlProcElem( XmlProcElem& xmlProcElement ); // Copy constructor
*	XmlProcElem( XmlProcElem&& xmlProcElement ); // Move constructor
*	XmlProcElem& XmlProcElem::operator=( XmlProcElem& xmlProcElem ); // Copy Assignment Operator
*	XmlProcElem& XmlProcElem::operator=( XmlProcElem&& xmlProcElem ); // Move Assignment Operator
*	bool hasContent(); // Return true if content is present
*	bool hasAttribute( xmlTagC name ); // Returns true if attribute with 'name' is present
*	xmlTagC getAttributeValue( const xmlTagC& name ); // Returns value of attribute with 'name' 
*	xmlTagC &getName(); // Returns tag name
*	void setName( const xmlTagC& name ) // Setter for tag name
*	xmlTagC &getContent(); //Returns content
*	void setContent( const xmlTagC& content ) //Setter for content
*	void addAttribute( ITagAttr *attr ) // Push into attribute vector
*	std::vector<ITagAttr *> &getAllAttributes(); // Return all attributes
*	void toString( int depth,std::string& xmlStr ); //ToString() filled with descendants
*	xmlTagC tagString(); //Returns tag as string
*
* Required Files:
* ---------------
*   - XmlProcElem.h, XmlProcElem.cpp
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