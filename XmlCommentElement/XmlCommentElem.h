#ifndef XMLCOMMENTELEM_H
#define XMLCOMMENTELEM_H
#include "../XmlTagInterface/IXmlElem.h"
#include "../Utilities/Utilities.h"

class XmlCommentElem : public  IXmlElem {

	public:
	XmlCommentElem();
	~XmlCommentElem();
	
	bool hasContent();
	xmlTagC &getContent();
	void setContent( const xmlTagC& comment ) { _content = comment; };
	void toString( int depth,std::string& xmlStr );

	private:
	xmlTagC _content;
	Utilities* _util;

	bool hasAttribute( IXmlElem::xmlTagC name ) { return false; }
	std::vector<ITagAttr *> &getAllAttributes() { std::vector<ITagAttr *> *empty = new std::vector<ITagAttr *>;  return *empty; }
	std::list<IXmlElem *> &getChildren() { std::list<IXmlElem *> *empty = new std::list<IXmlElem *>;  return *empty; }
	IXmlElem::xmlTagC &getName() { return _content; }
	IXmlElem::xmlTagC getAttributeValue( const xmlTagC& name ) { return ""; }
	IXmlElem* addChild( IXmlElem* xmlTag ) { return NULL; }
	IXmlElem* removeChild( IXmlElem* xmlTag ) { return NULL; }
};

#endif