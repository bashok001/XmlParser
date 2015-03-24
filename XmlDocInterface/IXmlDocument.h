#ifndef IXMLDOCUMENT_H
#define IXMLDOCUMENT_H

#include "../XmlTagInterface/IXmlElem.h"

class IXmlDocument {
	public:
	virtual IXmlElem* getRoot() = 0;
	virtual std::list<IXmlElem*> getProcessingInstr() = 0;
	virtual std::list<IXmlElem*> getPrologue() = 0;
	virtual std::list<IXmlElem*> getEpilogue() = 0;
	virtual IXmlElem* findElementbyTagId(const std::string& tagIdVal) = 0;
	virtual std::vector<IXmlElem*> findElementsbyTagName( const std::string& tagIdVal ) = 0;
};

#endif