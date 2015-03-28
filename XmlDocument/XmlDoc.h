//*************************************************************************//
// XmlDoc.h - Provides XMLDocument                                         //
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
* Provides support for creation of XMLDocument
*
* Public Interface:
* =================
*	XmlDoc(); // Constructor
*	XmlDoc( XmlDoc& xmlDoc ); //Copy constructor
*	XmlDoc( XmlDoc&& xmlDoc ); // Move constructor
*	XmlDoc& XmlDoc::operator=( XmlDoc& xmlDoc ); //copy assignment operator
*	XmlDoc& XmlDoc::operator=( XmlDoc&& xmlDoc ); // move assignment operator
*	
*	virtual ~XmlDoc(); // Destructor
*	virtual IXmlElem *getRoot(); // Returns doc root element
*	void setDocRoot( IXmlElem *docRoot ); //Setter doc root
*	virtual std::list<IXmlElem *> getProcessingInstr(); // return processing instructions
*	void setProcElem( IXmlElem * procElem ); //add a proc element
*	virtual std::list<IXmlElem*> getPrologue(); // get all prolog elements
*	void setPrologue( std::list<IXmlElem*> prologueElems ); //add a prolog elem
*	virtual std::list<IXmlElem*> getEpilogue(); //  get all epilog elements
*	void setEpilogue( std::list<IXmlElem*> epilogueElems ); // add a epilog elem
*	void setValid() // Sets this XMLDocument as a valid XmlDocument
*	bool isValid() // Returns if the XMLDocument is valid
*	IXmlElem* findElementbyTagId( const std::string& tagIdVal ); //Find elements based on Attribute value of tagid attribute
*	std::vector<IXmlElem*> findElementsbyTagName( const std::string& tagName ); //Find list of elements with tagName = 'tagName'
*	std::string toString( int depth ); //ToString() with descendants filled
*
* Required Files:
* ---------------
*   - XmlDoc.h, XmlDoc.cpp
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
	XmlDoc( XmlDoc&& xmlDoc );
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