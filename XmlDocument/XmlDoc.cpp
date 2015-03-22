#include "XmlDoc.h"

XmlDoc::XmlDoc() {
	_docRoot = NULL;
	_procElem = NULL;
	_prologue = {};
	_epilogue = {};
}

XmlDoc::~XmlDoc() {

}

IXmlElem *XmlDoc::getRoot() {
	return _docRoot;
}

void XmlDoc::setDocRoot( IXmlElem *docRoot ) {
	_docRoot = docRoot;
}

IXmlElem* XmlDoc::getProcessingInstr() {
	return _procElem;
}

void XmlDoc::setProcElem( IXmlElem *procElem ) {
	_procElem = procElem;
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

std::string XmlDoc::toString( int depth ) {
	std::string xmlStr;
	//Processing instructions
	if( _procElem != NULL )
		xmlStr.append( _procElem->toString( 0 ) );
	xmlStr.append( "\n" );

	//Preceding Comments
	for( auto prologElem : _prologue ) {
		xmlStr.append( "\n" );
		if( prologElem != NULL )
			xmlStr.append( prologElem->toString( 0 ) );
	}
	//Root Element
	if( _docRoot != NULL )
		xmlStr.append( _docRoot->toString( 0 ) );
	xmlStr.append( "\n" );

	//Ending Comments
	for( auto epilogElem : _epilogue ) {
		xmlStr.append( "\n" );
		if( epilogElem != NULL )
			xmlStr.append( epilogElem->toString( 0 ) );
	}
	return xmlStr;
}

#ifdef TEST_XMLDOC

int main(){

}

#endif