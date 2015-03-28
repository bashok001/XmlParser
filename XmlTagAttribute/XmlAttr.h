//*************************************************************************//
// XmlAttr.h - Implementation of XMLAttr                                   //
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
* This package creates attributes for XML Tags
* 
* Public Interface:
* =================
*   XmlAttr(); //Constructor
*	~XmlAttr(); // Destructor
*	XmlAttr(const XmlAttr& xmlAttribute ); // Copy constructor
*	XmlAttr(XmlAttr&& xmlAttribute ); // Move constructor
*	XmlAttr& XmlAttr::operator=( XmlAttr& xmlAttribute ); //Copy assignment Operator
*	XmlAttr& XmlAttr::operator=( XmlAttr&& xmlAttribute ); // Move assignment operator
*	virtual std::string &getName(); // returns _name 
*	void setName( const std::string& name ); // sets _name
*	virtual std::string& getValue(); //returns _value
*	void setValue( const std::string& value ); //Sets _value
*	virtual const std::string toString();//outputs string from attributes
*
* Required Files:
* ---------------
*   - XmlAttr.h, XmlAttr.cpp
*
* Build Process:
* --------------
*   devenv XMLParser.sln /debug rebuild
*
* Maintenance History:
* --------------------
* Only first version out
*/
#ifndef XMLATTR_H
#define XMLATTR_H

#include "../XmlAttributeInterface/ITagAttr.h"

class XmlAttr : public ITagAttr {
	private:
	std::string _name;
	std::string _value;
	
	public:
	XmlAttr();
	~XmlAttr();
	XmlAttr(const XmlAttr& xmlAttribute );
	XmlAttr(XmlAttr&& xmlAttribute );
	XmlAttr& XmlAttr::operator=( XmlAttr& xmlAttribute );
	XmlAttr& XmlAttr::operator=( XmlAttr&& xmlAttribute );
	virtual std::string &getName();
	void setName( const std::string& name );

	virtual std::string& getValue();
	void setValue( const std::string& value );

	virtual const std::string toString();
};

#endif