//*************************************************************************//
// XmlCommentElem.cpp - Comment Element                                     //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyleft © Ashok Bommisetti, 2015                                       //
// No guarantees on anything; But free to modify, copy and distribute      //
// ----------------------------------------------------------------------- //
// Author:      Ashok Bommisetti							               //
// First Published (mm-dd-yyyy): 03-24-2015 			                   //
//*************************************************************************//
#include "XmlCommentElem.h"
#include <iostream>
XmlCommentElem::XmlCommentElem() {
	_content = "";
	_util = new Utilities();
}

XmlCommentElem::XmlCommentElem( XmlCommentElem& xmlCommentElem ) {
	_content = xmlCommentElem._content;
	_util = new Utilities();
}

XmlCommentElem::XmlCommentElem( XmlCommentElem&& xmlCommentElem ):_content("") {
	_content = xmlCommentElem._content;
	_util = new Utilities();
	xmlCommentElem._content.clear();
	xmlCommentElem._util = NULL;
}

XmlCommentElem& XmlCommentElem::operator=( XmlCommentElem& xmlCommentElem ) {
	_content = xmlCommentElem._content;
	_util = new Utilities();
	return *this;
}

XmlCommentElem& XmlCommentElem::operator=( XmlCommentElem&& xmlCommentElem ) {
	if( this != &xmlCommentElem ) {
		delete _util;
		_content.clear();

		_util = new Utilities();
		_content = xmlCommentElem._content;
		
		xmlCommentElem._content.clear();
		xmlCommentElem._util=NULL;
	}
	return *this;
}

XmlCommentElem::~XmlCommentElem() {
	delete _util;
	_content.clear();
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
	XmlCommentElem* xmlc = new XmlCommentElem();
	xmlc->setContent( "Content" );
	std::cout << xmlc->tagString();
}
#endif