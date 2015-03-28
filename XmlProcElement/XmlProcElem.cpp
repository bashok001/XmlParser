//*************************************************************************//
// XmlProcElem.cpp - Provides operations wrapper on FileSystem in formats    //
//					needed by this app                                     //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyleft © Ashok Bommisetti, 2015                                       //
// No guarantees on anything; But free to modify, copy and distribute      //
// ----------------------------------------------------------------------- //
// Author:      Ashok Bommisetti							               //
// First Published (mm-dd-yyyy): 03-24-2015 			                   //
//*************************************************************************//
#include "XmlProcElem.h"
#include "../XmlTagAttribute/XmlAttr.h"
XmlProcElem::XmlProcElem() {
	_name="";
	_content="";
	_attributes = {};
	_util = new Utilities();
}

XmlProcElem::~XmlProcElem() {
	delete _util;
	_name.clear();
	_content.clear();
}

XmlProcElem& XmlProcElem::operator=( XmlProcElem& xmlProcElem ) {
	_name = xmlProcElem._name;
	_content = xmlProcElem._content;
	_util = new Utilities();
	for( auto attr : xmlProcElem._attributes ) {
		ITagAttr* newAttr = new XmlAttr();
		newAttr = attr;
		_attributes.push_back( newAttr );
	}
	return *this;
}

XmlProcElem& XmlProcElem::operator=( XmlProcElem&& xmlProcElem ) {
	if( this != &xmlProcElem ) {
		delete _util;
		_name.clear();
		_content.clear();
		while( !_attributes.empty() ) delete _attributes.back(), _attributes.pop_back();
		
		_util = new Utilities();
		_name = xmlProcElem._name;
		_content = xmlProcElem._content;
		for( auto attr : xmlProcElem._attributes ) {
			ITagAttr* newAttr = new XmlAttr();
			newAttr = attr;
			_attributes.push_back( newAttr );
		}		
		
		xmlProcElem._util=NULL;
		xmlProcElem._name.clear();
		xmlProcElem._content.clear();
		xmlProcElem._attributes = {};
	}
	return *this;
}

XmlProcElem::XmlProcElem(XmlProcElem& xmlProcElement) {
	_name = xmlProcElement._name;
	_content = xmlProcElement._content;	
	for( auto attr : xmlProcElement._attributes ) {
		ITagAttr* newAttr = new XmlAttr();
		newAttr = attr;
		_attributes.push_back( newAttr );
	}
	_util = new Utilities();
}

XmlProcElem::XmlProcElem( XmlProcElem&& xmlProcElement ) {
	_name = xmlProcElement._name;
	_content = xmlProcElement._content;
	for( auto attr : xmlProcElement._attributes ) {
		ITagAttr* newAttr = new XmlAttr();
		newAttr = attr;
		_attributes.push_back( newAttr );
	}
	_util = new Utilities();

	xmlProcElement._util = NULL;
	xmlProcElement._attributes = {};
	xmlProcElement._name.clear();
	xmlProcElement._content.clear();
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