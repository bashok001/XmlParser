#include "XmlDoc.h"
#include <iostream>

XmlDoc::XmlDoc() {
	_docRoot = NULL;
	_procElem = {};
	_prologue = {};
	_epilogue = {};
	_util = new Utilities();
	_valid = false;
}

XmlDoc::~XmlDoc() {
	delete _util;
}

IXmlElem *XmlDoc::getRoot() {
	return _docRoot;
}

void XmlDoc::setDocRoot( IXmlElem *docRoot ) {
	_docRoot = docRoot;
}

std::list<IXmlElem *> XmlDoc::getProcessingInstr() {
	return _procElem;
}

void XmlDoc::setProcElem( IXmlElem * procElem ) {
	_procElem.push_back( procElem );
}

std::list<IXmlElem*> XmlDoc::getPrologue() {
	return _prologue;
}

void XmlDoc::setPrologue( std::list<IXmlElem*> prologueElems ) {
	for( auto prologElem : prologueElems )
		_prologue.push_back( prologElem );
}

std::list<IXmlElem*> XmlDoc::getEpilogue() {
	return _epilogue;
}

void XmlDoc::setEpilogue( std::list<IXmlElem*> epilogueElems ) {
	for( auto epilogElem : epilogueElems )
		_epilogue.push_back( epilogElem );
}

IXmlElem* XmlDoc::findElementbyTagId( const std::string& tagIdVal ) {
	IXmlElem* resultSet = recursiveFind( tagIdVal,_docRoot );
	return resultSet;
}

IXmlElem* XmlDoc::recursiveFind( const std::string& tagIdVal,IXmlElem* elem ) {
	IXmlElem* result = NULL;
	if( _util->equalsIgnoreCase( elem->getIdAttribute(),tagIdVal ) ) {
		result = elem;
	}

std::list<IXmlElem *> childList = elem->getChildren();
	for( auto child : childList ) {
		if( result == NULL ) {
			IXmlElem* tempResults = recursiveFind( tagIdVal,child );
			result = tempResults;
		}
	}
	return result;
}

std::vector<IXmlElem*> XmlDoc::findElementsbyTagName( const std::string& tagIdVal ) {
	return recursiveElemsFind( tagIdVal,_docRoot );
}

std::vector<IXmlElem*> XmlDoc::recursiveElemsFind( const std::string& tagName,IXmlElem* elem ) {
	std::vector<IXmlElem*> resultVector = {};
	if( _util->equalsIgnoreCase( elem->getName(),tagName ) ) {
		resultVector.push_back( elem );
	}

	std::list<IXmlElem *> childList = elem->getChildren();
	for( auto child : childList ) {
		std::vector<IXmlElem*> tempResults = recursiveElemsFind( tagName,child );
		for( auto result : tempResults )
			resultVector.push_back( result );
	}
	return resultVector;
}

std::string XmlDoc::toString( int depth ) {
	if( _valid ) {
		std::string xmlStr;
		//Processing instructions
		for( auto procElem : _procElem ) {
			xmlStr.append( "\n" );
			if( procElem != NULL )
				procElem->toString( depth,xmlStr );
		}

		//Preceding Comments
		for( auto prologElem : _prologue ) {
			xmlStr.append( "\n" );
			if( prologElem != NULL )
				prologElem->toString( depth,xmlStr );
		}
		xmlStr.append( "\n" );
		//Root Element
		if( _docRoot != NULL )
			_docRoot->toString( 0,xmlStr );
		xmlStr.append( "\n" );
		//Ending Comments
		for( auto epilogElem : _epilogue ) {
			xmlStr.append( "\n" );
			if( epilogElem != NULL )
				epilogElem->toString( depth,xmlStr );
		}
		return xmlStr;
	} else
		return "Not a valid XML. \n";
	//TODO EXCEPTION

}

#ifdef TEST_XMLDOC

int main(){
	std::cout << "Working\n";
	XmlDoc xmldoc;
	std::cout << xmldoc.isValid() << "\n";
	xmldoc.setValid();
	std::cout << xmldoc.isValid() << "\n";
	std::cout << xmldoc.toString(0);
}

#endif