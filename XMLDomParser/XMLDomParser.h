#ifndef XMLDOMPARSER_H
#define XMLDOMPARSER_H

#include "../XmlDocument/XmlDoc.h"
#include "../Utilities/Utilities.h"
#include <string>
#include <stack>

class XmlDomParser {
	using XmlString = std::string;
	using xmlTokenVector = std::vector < XmlString > ;

	protected:
	XmlDomParser();

	public:
	XmlDomParser( const XmlString& _xmlString );

	virtual ~XmlDomParser();
	XmlDoc* getXmlDoc();

	private:
	XmlDoc* _xmlDoc;
	Utilities* _util;
	bool isSelfClosingElem( xmlTokenVector tokVector );
	bool isProcElement( xmlTokenVector tokVector );
	bool isCommentElement( xmlTokenVector tokVector );
	bool isOpenTag( xmlTokenVector tokVector );
	bool isClosedTag( xmlTokenVector tokVector );
	void addtoXml( std::stack < IXmlElem* >& xmlElemStack,std::vector<std::string> tokens,XmlDoc* xmlDoc );
	XmlString createName( xmlTokenVector tokVector, int initElem);
	void handleOpenTag( std::stack < IXmlElem* >& xmlElemStack,std::vector<std::string> tokens,XmlDoc* xmlDoc );
	void handleCloseTag( std::stack < IXmlElem* >& xmlElemStack,std::vector<std::string> tokens,XmlDoc* xmlDoc );
	void handleSelfCloseTag( std::stack < IXmlElem* >& xmlElemStack,std::vector<std::string> tokens,XmlDoc* xmlDoc );
	int getIndex( xmlTokenVector tokVector,const std::string& charString );
	
	IXmlElem* makeProcElement( xmlTokenVector tokVector );
	IXmlElem* makeCommentElement( xmlTokenVector tokVector );
	
};

#endif