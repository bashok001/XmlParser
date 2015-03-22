#ifndef IXMLDOCUMENT_H
#define IXMLDOCUMENT_H

#include "../XmlTagInterface/IXmlElem.h"

class IXmlDocument {
	public:
	virtual IXmlElem* getRoot() = 0;
	virtual IXmlElem* getProcessingInstr() = 0;
	virtual std::list<IXmlElem*> getPrologue() = 0;
	virtual std::list<IXmlElem*> getEpilogue() = 0;
};

#endif