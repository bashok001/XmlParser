#include "XmlPartsFactory.h"
#include "../XmlCommentElement/XmlCommentElem.h"
#include "../XmlProcElement/XmlProcElem.h"
#include "../XmlTaggedElement/XmlTaggedElem.h"
#include <iostream>

IXmlElem* XmlPartsFactory::getXmlElement( int typeOfXmlElem ) {
	switch( typeOfXmlElem ) {
		case 1:
			return new XmlProcElem();
			break;
		case 2:
			return new XmlCommentElem();
			break;
		case 3:
			return new XmlTaggedElem();
			break;
		default:
			return new XmlTaggedElem();
			break;
	}
}

#ifdef TEST_XMLPARTSFACTORY
int main() {
	if( XmlProcElem* xmlProcElement = dynamic_cast< XmlProcElem* > ( XmlPartsFactory::getXmlElement( 1 ) ) ) {
		std::cout << "Proc element success\n";
	}
	if( XmlCommentElem* xmlCommentElem = dynamic_cast< XmlCommentElem* > ( XmlPartsFactory::getXmlElement( 2 ) ) ) {
		std::cout << "Comment element success\n";
	}
	if( XmlTaggedElem* xmlTaggedElem = dynamic_cast< XmlTaggedElem* > ( XmlPartsFactory::getXmlElement( 3 ) ) ) {
		std::cout << "Tag element success\n";
	}
	if( XmlTaggedElem* xmlTaggedElem = dynamic_cast< XmlTaggedElem* > ( XmlPartsFactory::getXmlElement( 4 ) ) ) {
		std::cout << "Tag element success\n";
	}
}

#endif