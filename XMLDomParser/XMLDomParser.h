#ifndef XMLDOMPARSER_H
#define XMLDOMPARSER_H

#include <string>

class XmlDomParser {
	using XmlString = std::string;

	protected:
	XmlDomParser();

	public:
	XmlDomParser(const XmlString& _xmlString );
	virtual ~XmlDomParser();

	private:

};

#endif