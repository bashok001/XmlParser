#include "XmlDoc.h"

XmlDoc::XmlDoc() {
	_docRoot = NULL;
	_procElem = {};
	_prologue = {};
	_epilogue = {};
	_valid = false;
}

XmlDoc::~XmlDoc() {

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
	_procElem.push_back(procElem);
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

}

#endif