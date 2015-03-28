//*************************************************************************//
// IXmlElem.h - Xml Element interface                                     //
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
* This package provides interface that is used by all xml elements
*
* Public Interface:
* =================
*	virtual bool hasContent() = 0;
*	virtual xmlTagC &getContent() = 0;
*	virtual bool hasAttribute( xmlTagC name ) = 0;
*	virtual xmlTagC &getName()=0;
*	virtual std::vector<ITagAttr *> &getAllAttributes()=0;
*	virtual xmlTagC getAttributeValue( const xmlTagC& name )=0;
*	virtual std::vector<IXmlElem *> &getChildren()=0;
*	virtual bool addChild( IXmlElem* xmlTag ) = 0;
*	virtual bool removeChild( IXmlElem* xmlTag ) = 0;
*	virtual void toString(int depth, std::string& xmlStr) = 0;
*	virtual xmlTagC tagString() = 0;
*	xmlTagC getIdAttribute() { return _identityAttributeValue; };
*	void setIdAttributeValue( const xmlTagC& idValue ) { _identityAttributeValue = idValue; };
**
* Required Files:
* ---------------
*   - IXmlElem.h
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
	virtual bool hasAttribute( xmlTagC name ) = 0;
	virtual xmlTagC &getName()=0;
	virtual std::vector<ITagAttr *> &getAllAttributes()=0;
	virtual xmlTagC getAttributeValue( const xmlTagC& name )=0;
	virtual std::vector<IXmlElem *> &getChildren()=0;
	virtual bool addChild( IXmlElem* xmlTag ) = 0;
	virtual bool removeChild( IXmlElem* xmlTag ) = 0;
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