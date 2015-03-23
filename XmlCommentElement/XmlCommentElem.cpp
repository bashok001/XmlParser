#include "XmlCommentElem.h"

XmlCommentElem::XmlCommentElem() {
	_content = "";
	_util = new Utilities();
}

XmlCommentElem::~XmlCommentElem() {
	delete _util;
}

bool XmlCommentElem::hasContent() {
	return true;
}

XmlCommentElem::xmlTagC &XmlCommentElem::getContent() {
	return _content;
}

void XmlCommentElem::toString( int depth,std::string& xmlStr ) {
	xmlStr.append(_util->indentString( depth ));
	xmlStr.append( "<!-- " );
	xmlStr.append( _content );
	xmlStr.append( " -->" );
}


#ifdef TEST_XMLCOMMENTELEM
int main() {

}
#endif