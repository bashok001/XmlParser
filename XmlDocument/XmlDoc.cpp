#include "XmlDoc.h"

XmlDoc::XmlDoc() {
	_docRoot = NULL;
}

XmlDoc::~XmlDoc() {
	
}

IXmlTag *XmlDoc::getRoot() {
	return _docRoot;
}

void XmlDoc::setDocRoot( IXmlTag *docRoot ) {
	_docRoot = docRoot;
}

std::string XmlDoc::toString() {
	_docRoot->toString();
}

#ifdef TEST_XMLDOC

int main(){
	
}

#endif