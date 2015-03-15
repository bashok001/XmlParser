#include "../XmlDocInterface/IXmlDocument.h"
#include <string>

class XmlDoc : public IXmlDocument {
	private:
	IXmlElem* _docRoot;
	IXmlElem* _procElem;
	std::list<IXmlElem*> _prologue;
	std::list<IXmlElem*> _epilogue;


	public:
	XmlDoc();
	virtual ~XmlDoc();

	virtual IXmlElem *getRoot();
	void setDocRoot( IXmlElem *docRoot );
	virtual IXmlElem *getProcessingInstr();
	void setProcElem( IXmlElem *procElem );
	virtual std::list<IXmlElem*> getPrologue();
	void setPrologue( std::list<IXmlElem*> prologueElems );
	virtual std::list<IXmlElem*> getEpilogue();
	void setEpilogue( std::list<IXmlElem*> epilogueElems );

	std::string toString();
};