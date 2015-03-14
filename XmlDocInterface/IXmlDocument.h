#include "../XmlTagInterface/IXmlTag.h"

class IXmlDocument {
	public:
	virtual IXmlTag* getRoot() = 0;
};