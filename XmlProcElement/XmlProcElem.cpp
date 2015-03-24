#include "XmlProcElem.h"

XmlProcElem::XmlProcElem() {
	_name="";
	_content="";
	_attributes = {};
	_util = new Utilities();
}

XmlProcElem::~XmlProcElem() {
	delete _util;
}

bool XmlProcElem::hasContent() {
	return false;
}

bool XmlProcElem::hasAttribute( xmlTagC name ) {
	for( auto attribute : _attributes ) {
		if( _util->equalsIgnoreCase( attribute->getName(),name ) )
			return true;
	}
	return false;
}

XmlProcElem::xmlTagC &XmlProcElem::getName() {
	return _name;
}

XmlProcElem::xmlTagC &XmlProcElem::getContent() {
	return _content;
}

std::vector<ITagAttr *> &XmlProcElem::getAllAttributes() {
	return _attributes;
}

XmlProcElem::xmlTagC XmlProcElem::getAttributeValue( const xmlTagC& name ) {
	for( auto attribute : _attributes ) {
		if( _util->equalsIgnoreCase( attribute->getName(),name ) )
			return attribute->getValue();
		}
	return "";
}

XmlProcElem::xmlTagC XmlProcElem::tagString() {
	std::string tagString;
	tagString.append( "<?" );
	tagString.append( _name );
	for( auto attr : _attributes ) {
		tagString.append( attr->toString() );
	}
	tagString.append( " ?>" );

	return tagString;
}

void XmlProcElem::toString( int depth,std::string& xmlStr ) {
	xmlStr.append( _util->indentString( depth ) );
	xmlStr.append( "<?" );
	xmlStr.append( _name );
	for( auto attr : _attributes) {
		xmlStr.append(attr->toString());
	}
	xmlStr.append( " ?>" );
}

#ifdef TEST_XMLPROCELEM

int main(){

}

#endif