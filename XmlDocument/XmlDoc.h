//*************************************************************************//
// XmlDoc.h - Provides operations wrapper on FileSystem in formats    //
//					needed by this app                                     //
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
* This package is intended to help students in CSE687 - Object Oriented Design
* get started with Project #2 - XML Document Model.  It uses C++11 constructs,
* most noteably std::shared_ptr.  The XML Document Model is essentially
* a program-friendly wrapper around an Abstract Syntax Tree (AST) used to
* contain the results of parsing XML markup.
*
* Public Interface:
* =================
*
*
* Required Files:
* ---------------
*   - Display.h, Display.cpp
*
* Build Process:
* --------------
*   devenv XMLParser.sln /debug rebuild
*
* Maintenance History:
* --------------------
* Only first version out
*/
#ifndef XMLDOC_H
#define XMLDOC_H

#include "../XmlDocInterface/IXmlDocument.h"
#include "../Utilities/Utilities.h"
#include <string>
#include <vector>

class XmlDoc : public IXmlDocument {
	
	public:
	XmlDoc();
	XmlDoc( XmlDoc& xmlDoc );
	XmlDoc& XmlDoc::operator=( XmlDoc& xmlDoc );
	XmlDoc& XmlDoc::operator=( XmlDoc&& xmlDoc );
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
	std::string toString( int depth );

	private:
	IXmlElem* _docRoot;
	std::list<IXmlElem*> _procElem;
	std::list<IXmlElem*> _prologue;
	std::list<IXmlElem*> _epilogue;
	Utilities* _util;
	bool _valid;
	IXmlElem* recursiveFind( const std::string& tagIdVal,IXmlElem* elem );
	std::vector<IXmlElem*> recursiveElemsFind( const std::string& tagName,IXmlElem* elem );

};

#endif