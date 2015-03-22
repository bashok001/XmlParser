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

XmlCommentElem::xmlTagC XmlCommentElem::toString(int depth) {
	XmlCommentElem::xmlTagC xmlStr;
	xmlStr.append(_util->indentString( depth ));
	xmlStr.append( "<!-- " );
	xmlStr.append( _content );
	xmlStr.append( " -->" );

	return xmlStr;
}


#ifdef TEST_XMLCOMMENTELEM
int main() {

}
#endif