//*************************************************************************//
// XmlTaggedElem.h - XML Tagged element                                     //
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
* This package is to support creation of tagged elements
*
* Public Interface:
* =================
*	XmlTaggedElem(); //Constructor
*   ~XmlTaggedElem(); //Destructor
*	XmlTaggedElem( XmlTaggedElem& XmlTaggedElement ); // Copy constructor
*	XmlTaggedElem( XmlTaggedElem&& XmlTaggedElement ); // Move constructor
*	XmlTaggedElem& XmlTaggedElem::operator=( XmlTaggedElem& XmlTaggedElem ); // Copy Assignment Operator
*	XmlTaggedElem& XmlTaggedElem::operator=( XmlTaggedElem&& XmlTaggedElem ); // Move Assignment Operator
*	bool hasContent(); // Return true if content is present
*	bool hasAttribute( xmlTagC name ); // Returns true if attribute with 'name' is present
*	xmlTagC getAttributeValue( const xmlTagC& name ); // Returns value of attribute with 'name' 
*	xmlTagC &getName(); // Returns tag name
*	void setName( const xmlTagC& name ) // Setter for tag name
*	xmlTagC &getContent(); //Returns content
*	void setContent( const xmlTagC& content ) //Setter for content
*	void addAttribute( ITagAttr *attr ) // Push into attribute vector
*	std::vector<ITagAttr *> &getAllAttributes(); // Return all attributes
*	std::vector<IXmlElem *> &getChildren(); // Return all children
*	bool addChild( IXmlElem* xmlTag ); // Add a child to this element
*	bool removeChild( IXmlElem* xmlTag );	// Remove a child from this element
*	void toString( int depth,std::string& xmlStr ); //ToString() filled with descendants
*	xmlTagC tagString(); //Returns tag as string
*
* Required Files:
* ---------------
*   - XmlTaggedElem.h, XmlTaggedElem.cpp
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
	XmlTaggedElem( XmlTaggedElem&& oldXmlTagElem );
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

	std::vector<IXmlElem *> &getChildren();
	bool addChild( IXmlElem* xmlTag );
	bool removeChild( IXmlElem* xmlTag );

	void toString( int depth,std::string& xmlStr );
	xmlTagC tagString();

	private:
	xmlTagC	_name;
	xmlTagC _content;
	std::vector<IXmlElem *> _children;
	std::vector<ITagAttr *> _attributes;
	Utilities* _util;
};

#endif