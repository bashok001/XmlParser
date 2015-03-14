#include "../XmlDocInterface/IXmlDocument.h"
#include <string>

class XmlDoc : public IXmlDocument {
	private:
	IXmlTag *_docRoot;

	public:
	XmlDoc();
	virtual ~XmlDoc();
	virtual IXmlTag *getRoot();
	void setDocRoot( IXmlTag *docRoot );
	std::string toString();
};