#ifndef XMLPARTSFACTORY_H
#define XMLPARTSFACTORY_H
#include "../XmlTagInterface/IXmlElem.h"

class XmlPartsFactory {
	public:
	static IXmlElem *getXmlElement( int typeOfXmlElem );
};

#endif