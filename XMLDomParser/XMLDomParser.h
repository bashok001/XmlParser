#ifndef XMLDOMPARSER_H
#define XMLDOMPARSER_H

#include "../XmlDocument/XmlDoc.h"
#include <string>

class XmlDomParser {
	using XmlString = std::string;

	protected:
	XmlDomParser();

	public:
	XmlDomParser( const XmlString& _xmlString );
	virtual ~XmlDomParser();
	XmlDoc* getXmlDoc();

	private:
	XmlDoc* _xmlDoc = new XmlDoc();
};

#endif