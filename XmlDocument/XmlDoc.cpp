//*************************************************************************//
// XmlDoc.cpp - Provides XMLDocument                                         //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyleft © Ashok Bommisetti, 2015                                       //
// No guarantees on anything; But free to modify, copy and distribute      //
// ----------------------------------------------------------------------- //
// Author:      Ashok Bommisetti							               //
// First Published (mm-dd-yyyy): 03-24-2015 			                   //
//*************************************************************************//
#include "XmlDoc.h"
#include <iostream>
#include "../XmlProcElement/XmlProcElem.h"
#include "../XmlCommentElement/XmlCommentElem.h"
#include "../XmlTaggedElement/XmlTaggedElem.h"

XmlDoc::XmlDoc() {
	_docRoot = NULL;
	_procElem = {};
	_prologue = {};
	_epilogue = {};
	_util = new Utilities();
	_valid = false;
}

XmlDoc::XmlDoc( XmlDoc&& oldXmlDoc ) {
	_docRoot = std::move( oldXmlDoc._docRoot );
	_procElem = std::move( oldXmlDoc._procElem );
	_prologue = std::move( oldXmlDoc._prologue );
	_epilogue = std::move( oldXmlDoc._epilogue );
	_valid = std::move( oldXmlDoc._valid );
	oldXmlDoc._docRoot = NULL;
	oldXmlDoc._util = NULL;
	oldXmlDoc._procElem = {};
	oldXmlDoc._prologue = {};
	oldXmlDoc._epilogue = {};
	oldXmlDoc._valid = false;
}

XmlDoc& XmlDoc::operator=( XmlDoc& xmlDoc ) {
	_docRoot = xmlDoc._docRoot;
	for( auto proc : xmlDoc._procElem ) {
		IXmlElem* newProc = new XmlProcElem();
		newProc = proc;
		_procElem.push_back( newProc );
	}

	for( auto prologElem : xmlDoc._prologue ) {
		IXmlElem* newProlog = new XmlCommentElem();
		newProlog = prologElem;
		_prologue.push_back( newProlog );
	}

	for( auto epilogElem : xmlDoc._epilogue ) {
		IXmlElem* newEpilog = new XmlCommentElem();
		newEpilog = epilogElem;
		_epilogue.push_back( newEpilog );
	}
	_util = new Utilities();
	_valid = xmlDoc._valid;
	return *this;
}

XmlDoc& XmlDoc::operator=( XmlDoc&& xmlDoc ) {
	if( this != &xmlDoc ) {
		delete _docRoot;
		delete _util;
		while( !_procElem.empty() ) delete _procElem.back(),_procElem.pop_back();
		while( !_prologue.empty() ) delete _prologue.back(),_prologue.pop_back();
		while( !_epilogue.empty() ) delete _epilogue.back(),_epilogue.pop_back();
		_valid = false;

		_docRoot = xmlDoc._docRoot;
		for( auto proc : xmlDoc._procElem ) {
			IXmlElem* newProc = new XmlProcElem();
			newProc = proc;
			_procElem.push_back( newProc );
		}

		for( auto prologElem : xmlDoc._prologue ) {
			IXmlElem* newProlog = new XmlCommentElem();
			newProlog = prologElem;
			_prologue.push_back( newProlog );
		}

		for( auto epilogElem : xmlDoc._epilogue ) {
			IXmlElem* newEpilog = new XmlCommentElem();
			newEpilog = epilogElem;
			_epilogue.push_back( newEpilog );
		}
		_util = new Utilities();
		_valid = xmlDoc._valid;
		
		xmlDoc._docRoot = NULL;
		xmlDoc._util = NULL;
		xmlDoc._procElem = {};
		xmlDoc._prologue = {};
		xmlDoc._epilogue = {};
		xmlDoc._valid = false;

	}

	return *this;
}


XmlDoc::XmlDoc( XmlDoc& xmlDoc ) {
	_docRoot = xmlDoc._docRoot;
	for( auto proc : xmlDoc._procElem ) {
		IXmlElem* newProc = new XmlProcElem();
		newProc = proc;
		_procElem.push_back( newProc );
	}

	for( auto prologElem : xmlDoc._prologue ) {
		IXmlElem* newProlog = new XmlCommentElem();
		newProlog = prologElem;
		_prologue.push_back( newProlog );
	}

	for( auto epilogElem : xmlDoc._epilogue ) {
		IXmlElem* newEpilog = new XmlCommentElem();
		newEpilog = epilogElem;
		_epilogue.push_back( newEpilog );
	}
	_util = new Utilities();
	_valid = xmlDoc._valid;
}

XmlDoc::~XmlDoc() {
	_valid = false;
	/*if(_docRoot != NULL )
		delete _docRoot;
		if( _util != NULL )
		delete _util;*/
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
	IXmlElem* resultSet = recursiveFind( "\""+tagIdVal+"\"",_docRoot );
	return resultSet;
}

IXmlElem* XmlDoc::recursiveFind( const std::string& tagIdVal,IXmlElem* elem ) {
	IXmlElem* result = NULL;
	if( _util->equalsIgnoreCase( elem->getIdAttribute(),tagIdVal ) ) {
		result = elem;
	}

	std::vector<IXmlElem *> childList = elem->getChildren();
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

	std::vector<IXmlElem *> childList = elem->getChildren();
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

int main() {
	std::cout << "Working\n";
	XmlDoc xmldoc;
	std::cout << xmldoc.isValid() << "\n";
	xmldoc.setValid();

	IXmlElem* docroot = new XmlTaggedElem();

	xmldoc.setDocRoot( docroot );

	std::cout << xmldoc.isValid() << "\n";
	std::cout << xmldoc.toString( 0 ) << "\n ************* \n";
}

#endif