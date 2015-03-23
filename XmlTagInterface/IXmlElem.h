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

	virtual std::list<IXmlElem *> &getChildren()=0;
	virtual void addChild( IXmlElem* xmlTag )=0;
	virtual void removeChild( IXmlElem* xmlTag )=0;
	//End
	virtual void toString(int depth, std::string& xmlStr) = 0;

	xmlTagC getIdAttribute() { return _identityAttributeValue; };
	void setIdAttributeValue( const xmlTagC& idValue ) { _identityAttributeValue = idValue; };

	private:
	xmlTagC	_name;
	xmlTagC _content;
	std::list<IXmlElem *> _children;
	std::vector<ITagAttr *> _attributes;
	xmlTagC _identityAttributeValue;
};
#endif