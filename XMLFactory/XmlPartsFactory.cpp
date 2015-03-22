#include "XmlPartsFactory.h"
#include "../XmlCommentElement/XmlCommentElem.h"
#include "../XmlProcElement/XmlProcElem.h"
#include "../XmlTaggedElement/XmlTaggedElem.h"

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

}

#endif