#include <vector>
#include <list>

#include "../XmlAttributeInterface/ITagAttr.h"
class IXmlElem {

	public:
	using xmlTagC = std::string;
	virtual bool hasContent() = 0;
	virtual bool hasAttribute( xmlTagC name ) = 0;

	virtual xmlTagC &getName() = 0;
	virtual std::vector<ITagAttr *> &getAllAttributes() = 0;
	virtual xmlTagC &getContent() = 0;

	virtual xmlTagC getAttributeValue( const xmlTagC& name ) = 0;

	virtual std::list<IXmlElem *> &getChildren() { return std::list < IXmlElem * > {};  };
	virtual void addChild( IXmlElem* xmlTag ) {};
	virtual void removeChild( IXmlElem* xmlTag ) {};

	virtual xmlTagC toString() = 0;

	xmlTagC getIdAttribute() { return _identityAttributeValue; };
	void setIdAttributeValue( const xmlTagC& idValue ) { _identityAttributeValue = idValue; };

	private:
	xmlTagC _identityAttributeValue;
};