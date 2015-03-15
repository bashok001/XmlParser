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

std::string XmlDoc::toString() {
	std::string xmlStr;
	xmlStr.append( _procElem->toString() );
	for( auto prologElem : _prologue )
		xmlStr.append( prologElem->toString() );
	xmlStr.append( _docRoot->toString() );
	for( auto epilogElem : _epilogue )
		xmlStr.append( epilogElem->toString() );
	return xmlStr;
}

#ifdef TEST_XMLDOC

int main(){
	
}

#endif