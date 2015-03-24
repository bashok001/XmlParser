	#ifndef XMLPROCELEM_H
#define XMLPROCELEM_H
#include "../XmlTagInterface/IXmlElem.h"
#include "../Utilities/Utilities.h"

class XmlProcElem : public  IXmlElem {

	public:
	XmlProcElem();
	~XmlProcElem();
	
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
	std::list<IXmlElem *> &getChildren() { std::list<IXmlElem *> *empty = new std::list<IXmlElem *>;  return *empty; };
	virtual bool addChild( IXmlElem* xmlTag ) { return false; }
	virtual bool removeChild( IXmlElem* xmlTag ) { return false; }

	xmlTagC	_name;
	xmlTagC _content;
	std::vector<ITagAttr *> _attributes;
	Utilities* _util;
};

#endif