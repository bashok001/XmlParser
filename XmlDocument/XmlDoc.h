#ifndef XMLDOC_H
#define XMLDOC_H

#include "../XmlDocInterface/IXmlDocument.h"
#include "../Utilities/Utilities.h"
#include <string>
#include <vector>

class XmlDoc : public IXmlDocument {
	private:
	IXmlElem* _docRoot;
	std::list<IXmlElem*> _procElem;
	std::list<IXmlElem*> _prologue;
	std::list<IXmlElem*> _epilogue;
	Utilities* _util;
	bool _valid;
	IXmlElem* recursiveFind( const std::string& tagIdVal,IXmlElem* elem );
	std::vector<IXmlElem*> recursiveElemsFind( const std::string& tagName,IXmlElem* elem );

	public:
	XmlDoc();
	virtual ~XmlDoc();
	virtual IXmlElem *getRoot();
	void setDocRoot( IXmlElem *docRoot );
	virtual std::list<IXmlElem *> getProcessingInstr();
	void setProcElem( IXmlElem * procElem );
	virtual std::list<IXmlElem*> getPrologue();
	void setPrologue( std::list<IXmlElem*> prologueElems );
	virtual std::list<IXmlElem*> getEpilogue();
	void setEpilogue( std::list<IXmlElem*> epilogueElems );
	void setValid() { _valid = true; }
	bool isValid() { return _valid; }
	IXmlElem* findElementbyTagId( const std::string& tagIdVal );
	std::vector<IXmlElem*> findElementsbyTagName( const std::string& tagIdVal );
	std::string toString(int depth);
};

#endif