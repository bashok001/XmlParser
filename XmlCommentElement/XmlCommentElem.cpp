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

XmlCommentElem::xmlTagC XmlCommentElem::tagString() {
	std::string tagString;
	tagString.append( "<!-- " );
	tagString.append( _content );
	tagString.append( " -->" );
	return tagString;
}

#ifdef TEST_XMLCOMMENTELEM
int main() {

}
#endif