#include <vector>
#include <list>

#include "../XmlAttributeInterface/ITagAttr.h"
class IXmlTag {
	using xmlTagC = std::string;

	public:
	virtual bool hasContent() = 0;
	virtual bool hasAttribute( xmlTagC name ) = 0;

	virtual xmlTagC &getName() = 0;
	virtual std::vector<ITagAttr *> &getAllAttributes() = 0;
	virtual xmlTagC &getContent() = 0;
	virtual std::list<IXmlTag *> &getChildren() = 0;

	virtual xmlTagC getAttributeValue( const xmlTagC& name ) = 0;

	virtual void addChild( IXmlTag* xmlTag ) = 0;
	virtual void removeChild( IXmlTag* xmlTag ) = 0;

	virtual xmlTagC toString() = 0;
	
	xmlTagC getIdAttribute() { return _identityAttributeValue; };
	void setIdAttributeValue( const xmlTagC& idValue ) { _identityAttributeValue = idValue; };

	private:
	xmlTagC _identityAttributeValue;
};
