#ifndef XMLTAGGEDELEM_H
#define XMLTAGGEDELEM_H

#include "../XmlTagInterface/IXmlElem.h"
#include "../Utilities/Utilities.h"

class XmlTaggedElem : public  IXmlElem {

	public:
	XmlTaggedElem();
	~XmlTaggedElem();
	
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
	IXmlElem* addChild( IXmlElem* xmlTag );
	IXmlElem* removeChild( IXmlElem* xmlTag );

	void toString( int depth,std::string& xmlStr );

	private:
	xmlTagC	_name;
	xmlTagC _content;
	std::list<IXmlElem *> _children;
	std::vector<ITagAttr *> _attributes;
	Utilities* _util;
};

#endif