//*************************************************************************//
// XMLDomParser.cpp - Parser that creates a XML Document from a XML String //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyleft © Ashok Bommisetti, 2015                                       //
// No guarantees on anything; But free to modify, copy and distribute      //
// ----------------------------------------------------------------------- //
// Author:      Ashok Bommisetti							               //
// First Published (mm-dd-yyyy): 03-24-2015 			                   //
//*************************************************************************//
#include "XMLDomParser.h"
#include "../FileOut/FileOut.h"
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
	if( isRoot && xmlElemStack.size()==0) {
		_xmlDoc->setValid();
	}
	_xmlDoc->setPrologue( prologList );
	_xmlDoc->setEpilogue( epilogList );
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

bool XmlDomParser::isSelfClosingElem( xmlTokenVector tokVector ) {
	if( tokVector.size() > 2 )
		if( _util->equalsIgnoreCase( tokVector.at( 0 ),"<" ) && _util->equalsIgnoreCase( tokVector.at( tokVector.size() - 2 ),"/" ) && _util->equalsIgnoreCase( tokVector.at( tokVector.size() - 1 ),">" ) )
			return true;
	return false;
}

IXmlElem* XmlDomParser::makeProcElement( xmlTokenVector tokVector ) {
	if( XmlProcElem* xmlProcElement = dynamic_cast< XmlProcElem* > ( XmlPartsFactory::getXmlElement( 1 ) ) ) {
		xmlProcElement->setName( createName(tokVector,2) );
		for( size_t i = getIndex(tokVector,"=")-1; i < tokVector.size() - 2; i++ ) {
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
		for( size_t i = 3; i < tokVector.size() - 2; i++ ) {
			comment.append( tokVector.at( i ) + " " );
		}
		xmlCommentElement->setContent( comment );
		return xmlCommentElement;
	}
	return NULL;
}

void XmlDomParser::addtoXml( std::stack < IXmlElem* >& xmlElemStack,std::vector<std::string> tokens,XmlDoc* xmlDoc ) {
	if( isSelfClosingElem( tokens ) ) {
		handleSelfCloseTag( xmlElemStack,tokens,xmlDoc );
	} else if( isOpenTag( tokens ) ) {
		handleOpenTag( xmlElemStack,tokens,xmlDoc );
	} else if( isClosedTag( tokens ) ) {
		handleCloseTag( xmlElemStack,tokens,xmlDoc );
	} else {
		XmlTaggedElem* topXmlTaggedElem = dynamic_cast< XmlTaggedElem* > ( xmlElemStack.top() );
		std::string content;
		for( auto cnt : tokens )
			content.append( cnt );
		topXmlTaggedElem->setContent( content );
	}
}

void XmlDomParser::handleOpenTag( std::stack < IXmlElem* >& xmlElemStack,std::vector<std::string> tokens,XmlDoc* xmlDoc ) {
	if( XmlTaggedElem* xmlTaggedElement = dynamic_cast< XmlTaggedElem* > ( XmlPartsFactory::getXmlElement( 3 ) ) ) {
		xmlTaggedElement->setName( createName( tokens,1 ) );
		for( size_t i = getIndex( tokens,"=" ) - 1; i < tokens.size() - 1; i++ ) {
			ITagAttr* xmlAttribute = new XmlAttr();
			XmlAttr* xmlAttr = dynamic_cast< XmlAttr* > ( xmlAttribute );
			xmlAttr->setName( tokens.at( i ) );
			i = i + 2;
			xmlAttr->setValue( tokens.at( i ) );
			if( _util->equalsIgnoreCase( xmlAttr->getName(),"tagid" ) ) {
				xmlTaggedElement->setIdAttributeValue(xmlAttr->getValue());
			}
			xmlTaggedElement->addAttribute( xmlAttr );
		}
		if( xmlElemStack.size() > 0 ) {
			XmlTaggedElem* topXmlTaggedElem = dynamic_cast< XmlTaggedElem* > ( xmlElemStack.top() );
			topXmlTaggedElem->addChild( xmlTaggedElement );
		}
		xmlElemStack.push( xmlTaggedElement );
	}
}

void XmlDomParser::handleCloseTag( std::stack < IXmlElem* >& xmlElemStack,std::vector<std::string> tokens,XmlDoc* xmlDoc ) {
	if( xmlElemStack.size() == 1 ) {
		XmlTaggedElem* topXmlTaggedElem = dynamic_cast< XmlTaggedElem* > ( xmlElemStack.top() );
		xmlDoc->setDocRoot( topXmlTaggedElem );
	}
	if( !xmlElemStack.empty() )
		xmlElemStack.pop();
	else {
		//TODO EXCEPTION;
		std::cout << "Not a Valid XML. \n";
		exit( 1 );
	}
}

void XmlDomParser::handleSelfCloseTag( std::stack < IXmlElem* >& xmlElemStack,std::vector<std::string> tokens,XmlDoc* xmlDoc ) {
	if( XmlTaggedElem* xmlTaggedElement = dynamic_cast< XmlTaggedElem* > ( XmlPartsFactory::getXmlElement( 3 ) ) ) {
		std::string nameStore = createName( tokens,1 );
		auto nameFound = nameStore.find( '/' );
		if( nameFound != std::string::npos )
			nameStore.erase( nameFound,1 );
		xmlTaggedElement->setName( nameStore );
		for( size_t i = getIndex( tokens,"=" )-1; i < tokens.size() - 2; i++ ) {
			ITagAttr* xmlAttribute = new XmlAttr();
			XmlAttr* xmlAttr = dynamic_cast< XmlAttr* > ( xmlAttribute );
			xmlAttr->setName( tokens.at( i ) );
			i = i + 2;
			xmlAttr->setValue( tokens.at( i ) );
			if( _util->equalsIgnoreCase( xmlAttr->getName(),"tagid" ) ) {
				xmlTaggedElement->setIdAttributeValue( xmlAttr->getValue() );
			}
			xmlTaggedElement->addAttribute( xmlAttr );
		}
		if( xmlElemStack.size() > 0 ) {
			XmlTaggedElem* topXmlTaggedElem = dynamic_cast< XmlTaggedElem* > ( xmlElemStack.top() );
			topXmlTaggedElem->addChild( xmlTaggedElement );
		}
		xmlElemStack.push( xmlTaggedElement );
		if( xmlElemStack.size() == 1 ) {
			XmlTaggedElem* topXmlTaggedElem = dynamic_cast< XmlTaggedElem* > ( xmlElemStack.top() );
			xmlDoc->setDocRoot( topXmlTaggedElem );
		}
	}
	if( !xmlElemStack.empty() )
		xmlElemStack.pop();
	else {
		//TODO EXCEPTION;
		std::cout << "Not a Valid XML. \n";
		exit( 1 );
	}
		
}

XmlDomParser::XmlString XmlDomParser::createName( xmlTokenVector tokVector, int initElem ) {
	std::string tagName;
	int index = getIndex( tokVector,"=" );
	if( index != std::numeric_limits<int>::max() ) {
		for( int i = initElem; i < index-1; i++ ) {
			tagName += tokVector[ i ];
		}
		return tagName;
	} else {
		for( size_t i = initElem; i < tokVector.size()-1; i++ ) {
			tagName += tokVector[ i ];
		}
		return tagName;
	}
	return "";
}

int XmlDomParser::getIndex( xmlTokenVector tokVector,const std::string& charString ) {
	auto itr = std::find( tokVector.begin(),tokVector.end(),charString );
	if( itr != tokVector.end() ) {
		int index = std::distance( tokVector.begin(),itr );
		return index;
	}
	return std::numeric_limits<int>::max();
}

#ifdef TEST_XMLDOCPARSER

int main() {
	static std::string xmldata( "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\
								<?xml-stylesheet type=\"text / xsl\" href=\"style.xsl\"?>\
								<!-- Operating Systems -->\
								<!-- Microsoft -->\
								<OSes>\
								<OS name=\"xs\" />\
								<OS name=\"Linux\" tagid = \"gem\"/>\
								<OS name=\"Microsoft-Windows-8.1\" tagid = \"gem\">\
								<SetupLanguage>\
								<UILang tagid=\"ui\">en-IN</UILang>\
								<ShowUI tagid=\"ui\">OnError</ShowUI>\
								</SetupLanguage>\
								<SysLocale>en-US</SysLocale>\
								<UserLocale tagid=\"ui\">en-IN</UserLocale>\
								</OS>\
								</OSes>" );
	XmlDomParser xdom( xmldata );
	std::cout<<xdom.getXmlDoc()->toString( 0 );
	
	std::string output;
	auto x = xdom.getXmlDoc()->findElementbyTagId( "gem" );
	if( x!=NULL )
		std::cout << x->tagString() << std::endl << std::endl << std::endl;
	if( x == NULL ) {
		std::cout << "NULL POINTER." << std::endl;
	} else {
		x->toString( 0,output );
		std::cout << output << std::endl;
	}
	std::string outputs;
	std::vector<IXmlElem*> xs = xdom.getXmlDoc()->findElementsbyTagName( "OS" );
	std::cout << xs.size() << "\n\n";
	for( auto a : xs )
		std::cout << a->tagString() << std::endl << std::endl << std::endl;
	if( xs.size() == 0) {
		std::cout << "EMPTY VECTOR." << std::endl;
	} else {
		for( auto a : xs ) {
			a->toString( 0,outputs );
			outputs.append("\n\n");
		}
		std::cout << outputs << std::endl;
	}
}

#endif