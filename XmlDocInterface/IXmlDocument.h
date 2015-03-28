//*************************************************************************//
// IXmlDocument.h - Interface for XML Document                             //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyleft © Ashok Bommisetti, 2015                                       //
// No guarantees on anything; But free to modify, copy and distribute      //
// ----------------------------------------------------------------------- //
// Author:      Ashok Bommisetti							               //
// First Published (mm-dd-yyyy): 03-24-2015 			                   //
//*************************************************************************//
/*
* Package Operations:
* ==================
* This package provides interface for XMLDocument
*
* Public Interface:
* =================
*	virtual IXmlElem* getRoot() = 0;
*	virtual std::list<IXmlElem*> getProcessingInstr() = 0;
*	virtual std::list<IXmlElem*> getPrologue() = 0;
*	virtual std::list<IXmlElem*> getEpilogue() = 0;
*	virtual IXmlElem* findElementbyTagId(const std::string& tagIdVal) = 0;
*	virtual std::vector<IXmlElem*> findElementsbyTagName( const std::string& tagIdVal ) = 0;
*
* Required Files:
* ---------------
*   - IXmlDocument.h
*
* Build Process:
* --------------
*   devenv XMLParser.sln /debug rebuild
*
* Maintenance History:
* --------------------
* Only first version out
*/
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