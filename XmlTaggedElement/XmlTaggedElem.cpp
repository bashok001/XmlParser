#include "XmlTaggedElem.h"
#include "../XmlTagAttribute/XmlAttr.h"

XmlTaggedElem::XmlTaggedElem() {
	_name = "";
	_content = "";
	_children = std::list<IXmlElem *>( {} );
	_attributes = std::vector<ITagAttr *>( {} );
	_util = new Utilities;
}

XmlTaggedElem::~XmlTaggedElem() {
	delete _util;
}

bool XmlTaggedElem::hasContent() {
	return ( _content.length() != 0 );
}

bool XmlTaggedElem::hasAttribute( xmlTagC name ) {
	ITagAttr* attr = getAttribute( name );
	if( attr != NULL ) {
		return true;
	}
	return false;
}

XmlTaggedElem::xmlTagC XmlTaggedElem::getAttributeValue( const xmlTagC& name ) {
	ITagAttr* attr = getAttribute( name );
	if( attr != NULL ) {
		return attr->getValue();
	}
	return NULL;
}

ITagAttr* XmlTaggedElem::getAttribute( const xmlTagC& name ) {
	for( auto attribute : _attributes ) {
		if( _util->equalsIgnoreCase( attribute->getName(),name ) )
			return attribute;
	}
	return NULL;
}

bool XmlTaggedElem::removeAttribute( const xmlTagC& name ) {
	auto position = std::find( _attributes.begin(),_attributes.end(), getAttribute(name));
	if( position != _attributes.end() ) {
		_attributes.erase( position );
		return true;
	}
	return false;
}

XmlTaggedElem::xmlTagC &XmlTaggedElem::getName() {
	return _name;
}

XmlTaggedElem::xmlTagC &XmlTaggedElem::getContent() {
	return _content;
}

std::vector<ITagAttr *> &XmlTaggedElem::getAllAttributes() {
	return _attributes;
}

std::list<IXmlElem *> &XmlTaggedElem::getChildren() {
	return _children;
}

IXmlElem* XmlTaggedElem::addChild( IXmlElem* xmlTag ) {
	_children.push_back( xmlTag );
	return xmlTag;
}

IXmlElem* XmlTaggedElem::removeChild( IXmlElem* xmlTag ) {
	_children.remove( xmlTag );
	return this;
}

void XmlTaggedElem::toString( int depth,std::string& xmlStr ) {
	std::string indentation = _util->indentString( depth );

	xmlStr.append( indentation+"<" + this->getName() + " " );
	std::vector<ITagAttr *> attrs = this->getAllAttributes();
	for( auto attr : attrs ) {
		xmlStr.append( attr->toString() );
	}
	xmlStr.append( ">" );
	
	xmlStr.append(indentation+this->getContent() );
	std::list<IXmlElem *> childTag=this->getChildren();
	auto iter = childTag.begin();
	while( iter != childTag.end() ) {
		IXmlElem *child = *iter;
		xmlStr.append( "\n" );
		child->toString( depth + 1, xmlStr );
		iter++;
	}
	xmlStr.append( "\n" );
	
	xmlStr.append( indentation+"</"+this->getName()+">" );
}

#ifdef TEST_XMLTAGGEDELEM
int main() {

}
#endif