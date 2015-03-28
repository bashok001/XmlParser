//*************************************************************************//
// XmlTaggedElem.cpp - Provides operations wrapper on FileSystem in formats    //
//					needed by this app                                     //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyleft © Ashok Bommisetti, 2015                                       //
// No guarantees on anything; But free to modify, copy and distribute      //
// ----------------------------------------------------------------------- //
// Author:      Ashok Bommisetti							               //
// First Published (mm-dd-yyyy): 03-24-2015 			                   //
//*************************************************************************//
#include "XmlTaggedElem.h"
#include "../XmlTagAttribute/XmlAttr.h"

XmlTaggedElem::XmlTaggedElem() {
	_name = "";
	_content = "";
	_children = std::vector<IXmlElem *>( {} );
	_attributes = std::vector<ITagAttr *>( {} );
	_util = new Utilities;
}

XmlTaggedElem::~XmlTaggedElem() {
	_name.clear();
	_content.clear();
	delete _util;
}

XmlTaggedElem::XmlTaggedElem( XmlTaggedElem& xmlTagElem ) {
	_name = xmlTagElem._name;
	_content = xmlTagElem._content;
	for( auto attr : xmlTagElem._attributes ) {
		ITagAttr* newAttr = new XmlAttr();
		newAttr = attr;
		_attributes.push_back( newAttr );
	}
	for( auto child : xmlTagElem._children ) {
		IXmlElem* newXmlElem = new XmlTaggedElem();
		newXmlElem = child;
		_children.push_back( newXmlElem );
	}
	_util = new Utilities();
}

XmlTaggedElem& XmlTaggedElem::operator=( XmlTaggedElem& xmlTaggedElem ) {
	_name = xmlTaggedElem._name;
	_content = xmlTaggedElem._content;

	for( auto attr : xmlTaggedElem._attributes ) {
		ITagAttr* newAttr = new XmlAttr();
		newAttr = attr;
		_attributes.push_back( newAttr );
	}

	for( auto child : xmlTaggedElem._children ) {
		IXmlElem* newXmlElem = new XmlTaggedElem();
		newXmlElem = child;
		_children.push_back( newXmlElem );
	}

	_util = new Utilities;

	return *this;
}

XmlTaggedElem& XmlTaggedElem::operator=( XmlTaggedElem&& xmlTaggedElem ) {
	if( this != &xmlTaggedElem ) {
		_name.clear();
		_content.clear();
		delete _util;
		while( !_attributes.empty() ) delete _attributes.back(),_attributes.pop_back();
		while( !_children.empty() ) delete _children.back(),_children.pop_back();

		_name = xmlTaggedElem._name;
		_content = xmlTaggedElem._content;
		for( auto attr : xmlTaggedElem._attributes ) {
			ITagAttr* newAttr = new XmlAttr();
			newAttr = attr;
			_attributes.push_back( newAttr );
		}
		for( auto child : xmlTaggedElem._children ) {
			IXmlElem* newXmlElem = new XmlTaggedElem();
			newXmlElem = child;
			_children.push_back( newXmlElem );
		}
		_util = new Utilities;

		xmlTaggedElem._name.clear();
		xmlTaggedElem._content.clear();
		xmlTaggedElem._children = std::vector<IXmlElem *>( {} );
		xmlTaggedElem._attributes = std::vector<ITagAttr *>( {} );
		xmlTaggedElem._util = NULL;

	}

	return *this;
}


XmlTaggedElem::XmlTaggedElem( XmlTaggedElem&& xmlTaggedElem ) {
	_name = std::move( xmlTaggedElem._name );
	_content = std::move( xmlTaggedElem._content );
	_children = std::move( xmlTaggedElem._children );
	_attributes = std::move( xmlTaggedElem._attributes );
	_util = std::move( xmlTaggedElem._util );

	xmlTaggedElem._name.clear();
	xmlTaggedElem._content.clear();
	xmlTaggedElem._children = std::vector<IXmlElem *>( {} );
	xmlTaggedElem._attributes = std::vector<ITagAttr *>( {} );
	xmlTaggedElem._util = NULL;
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
	auto position = std::find( _attributes.begin(),_attributes.end(),getAttribute( name ) );
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

std::vector<IXmlElem *> &XmlTaggedElem::getChildren() {
	return _children;
}

bool XmlTaggedElem::addChild( IXmlElem* xmlTag ) {
	if( dynamic_cast< XmlTaggedElem* > ( xmlTag ) ) {
		_children.push_back( xmlTag );
		return true;
	}
	return false;
}

bool XmlTaggedElem::removeChild( IXmlElem* xmlTag ) {
	auto position = std::find( _children.begin(),_children.end(),xmlTag );
	if( position != _children.end() ) {
		_children.erase( position );
		return true;
	}
	return false;
}

XmlTaggedElem::xmlTagC XmlTaggedElem::tagString() {
	std::string tagString;
	tagString.append( "<" + this->getName() + " " );
	std::vector<ITagAttr *> attrs = this->getAllAttributes();
	for( auto attr : attrs ) {
		tagString.append( attr->toString() );
	}
	tagString.append( ">" );
	return tagString;
}

void XmlTaggedElem::toString( int depth,std::string& xmlStr ) {
	std::string indentation = _util->indentString( depth );
	xmlStr.append( indentation + "<" + this->getName() + " " );
	std::vector<ITagAttr *> attrs = this->getAllAttributes();
	for( auto attr : attrs ) {
		xmlStr.append( attr->toString() );
	}
	xmlStr.append( ">" );
	xmlStr.append( indentation + this->getContent() );
	std::vector<IXmlElem *> childTag = this->getChildren();
	auto iter = childTag.begin();
	while( iter != childTag.end() ) {
		IXmlElem *child = *iter;
		xmlStr.append( "\n" );
		child->toString( depth + 1,xmlStr );
		iter++;
	}
	xmlStr.append( "\n" );	
	xmlStr.append( indentation+"</"+this->getName()+">" );
}



#ifdef TEST_XMLTAGGEDELEM
int main() {

}
#endif