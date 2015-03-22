#include "XMLDomParser.h"

#include "../Tokenizer/Tokenizer.h"
#include "../XmlTokenizer/XmlTokenizer.h"
#include "../XmlProcElement/XmlProcElem.h"
#include "../XMLFactory/XmlPartsFactory.h"
#include "../XmlAttributeInterface/ITagAttr.h"
#include "../XmlTagAttribute/XmlAttr.h"
#include "../XmlCommentElement/XmlCommentElem.h"
#include "../XmlTaggedElement/XmlTaggedElem.h"

XmlDomParser::XmlDomParser( const XmlString& _xmlString ) {
	_util = new Utilities();
	_xmlDoc = new XmlDoc();

	std::list<IXmlElem*> prologList;
	std::list<IXmlElem*> epilogList;

	bool isRoot = false;
	Toker tokenizer( _xmlString,false );
	tokenizer.setMode( Toker::xml );
	XmlParts parts( &tokenizer );
	std::stack < IXmlElem* > xmlElemStack;

	while( parts.get() ) {
		std::cout << "a " << parts.show().c_str() << std::endl;
		if( isProcElement( parts.getToks() ) ) {
			IXmlElem* procElem = makeProcElement( parts.getToks() );
			_xmlDoc->setProcElem( procElem );
		} else if( isCommentElement( parts.getToks() ) ) {
			IXmlElem* commentElem = makeCommentElement( parts.getToks() );
			if( !isRoot )
				prologList.push_back( commentElem );
			else
				epilogList.push_back( commentElem );
		} else {
			isRoot = true;
			addtoXml( xmlElemStack,parts.getToks(),_xmlDoc );
		}
	}
	if( isRoot ) {
		_xmlDoc->setValid();
	}
	_xmlDoc->setPrologue( prologList );
	_xmlDoc->setEpilogue( epilogList );
	std::cout << _xmlDoc->toString( 0 ) << std::endl;
}

XmlDomParser::~XmlDomParser() {
	delete _util;
	delete _xmlDoc;
}

XmlDoc* XmlDomParser::getXmlDoc() {
	return _xmlDoc;
}

bool XmlDomParser::isProcElement( xmlTokenVector tokVector ) {
	if( tokVector.size() > 1 )
		if( _util->equalsIgnoreCase( tokVector.at( 1 ),"?" ) )
			return true;

	return false;
}
bool XmlDomParser::isCommentElement( xmlTokenVector tokVector ) {
	if( tokVector.size() > 1 )
		if( _util->equalsIgnoreCase( tokVector.at( 1 ),"!" ) )
			return true;

	return false;
}

bool XmlDomParser::isOpenTag( xmlTokenVector tokVector ) {
	if( tokVector.size() > 1 )
		if( _util->equalsIgnoreCase( tokVector.at( 0 ),"<" ) )
			if( !_util->equalsIgnoreCase( tokVector.at( 1 ),"/" ) )
				return true;

	return false;
}

bool XmlDomParser::isClosedTag( xmlTokenVector tokVector ) {
	if( tokVector.size() > 1 )
		if( _util->equalsIgnoreCase( tokVector.at( 0 ),"<" ) )
			if( _util->equalsIgnoreCase( tokVector.at( 1 ),"/" ) )
				return true;

	return false;
}

IXmlElem* XmlDomParser::makeProcElement( xmlTokenVector tokVector ) {
	if( XmlProcElem* xmlProcElement = dynamic_cast< XmlProcElem* > ( XmlPartsFactory::getXmlElement( 1 ) ) ) {
		xmlProcElement->setName( tokVector.at( 2 ) );
		for( int i = 3; i < tokVector.size() - 2; i++ ) {
			ITagAttr* xmlAttribute = new XmlAttr();
			XmlAttr* xmlAttr = dynamic_cast< XmlAttr* > ( xmlAttribute );
			xmlAttr->setName( tokVector.at( i ) );
			i = i + 2;
			xmlAttr->setValue( tokVector.at( i ) );
			xmlProcElement->addAttribute( xmlAttr );
		}
		return xmlProcElement;
	}
	return NULL;
}

IXmlElem* XmlDomParser::makeCommentElement( xmlTokenVector tokVector ) {
	if( XmlCommentElem* xmlCommentElement = dynamic_cast< XmlCommentElem* > ( XmlPartsFactory::getXmlElement( 2 ) ) ) {
		std::string comment;
		for( int i = 3; i < tokVector.size() - 2; i++ ) {
			comment.append( tokVector.at( i ) + " " );
		}
		xmlCommentElement->setContent( comment );
		return xmlCommentElement;
	}
	return NULL;
}

void XmlDomParser::addtoXml( std::stack < IXmlElem* >& xmlElemStack,std::vector<std::string> tokens,XmlDoc* xmlDoc ) {
	if( isOpenTag( tokens ) ) {
		if( XmlTaggedElem* xmlTaggedElement = dynamic_cast< XmlTaggedElem* > ( XmlPartsFactory::getXmlElement( 3 ) ) ) {
			xmlTaggedElement->setName( tokens.at( 1 ) );
			for( int i = 2; i < tokens.size() - 1; i++ ) {
				ITagAttr* xmlAttribute = new XmlAttr();
				XmlAttr* xmlAttr = dynamic_cast< XmlAttr* > ( xmlAttribute );
				xmlAttr->setName( tokens.at( i ) );
				i = i + 2;
				xmlAttr->setValue( tokens.at( i ) );
				xmlTaggedElement->addAttribute( xmlAttr );
			}

			if( xmlElemStack.size() > 0 ) {
				XmlTaggedElem* topXmlTaggedElem = dynamic_cast< XmlTaggedElem* > ( xmlElemStack.top() );
				topXmlTaggedElem->addChild( xmlTaggedElement );
			}
			xmlElemStack.push( xmlTaggedElement );
		}
	} else if( isClosedTag( tokens ) ) {

		if( xmlElemStack.size() == 1 ) {
			XmlTaggedElem* topXmlTaggedElem = dynamic_cast< XmlTaggedElem* > ( xmlElemStack.top() );
			xmlDoc->setDocRoot( topXmlTaggedElem );
		}

		xmlElemStack.pop();

	} else {
		XmlTaggedElem* topXmlTaggedElem = dynamic_cast< XmlTaggedElem* > ( xmlElemStack.top() );
		std::string content;
		for( auto cnt : tokens )
			content.append( cnt );
		topXmlTaggedElem->setContent( content );
	}
}

#ifdef TEST_XMLDOCPARSER

int main() {
	static std::string xmldata( "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\
								<!-- Operating Systems -->\
								<!-- Microsoft -->\
								<OSes>\
								<OS name=\"Microsoft-Windows-8.1\">\
								<SetupLanguage>\
								<UILang>en-IN</UILang>\
								<ShowUI>OnError</ShowUI>\
								</SetupLanguage>\
								<SysLocale>en-US</SysLocale>\
								<UserLocale>en-IN</UserLocale>\
								</OS>\
								</OSes>" );
	XmlDomParser xdom( xmldata );
}

#endif