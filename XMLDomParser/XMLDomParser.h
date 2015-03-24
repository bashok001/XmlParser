//*************************************************************************//
// XMLDomParser.h - Provides operations wrapper on FileSystem in formats    //
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
#ifndef XMLDOMPARSER_H
#define XMLDOMPARSER_H

#include "../XmlDocument/XmlDoc.h"
#include "../Utilities/Utilities.h"
#include <string>
#include <stack>

class XmlDomParser {
	using XmlString = std::string;
	using xmlTokenVector = std::vector < XmlString > ;

	protected:
	XmlDomParser();

	public:
	XmlDomParser( const XmlString& _xmlString );

	virtual ~XmlDomParser();
	XmlDoc* getXmlDoc();

	private:
	XmlDoc* _xmlDoc;
	Utilities* _util;
	bool isSelfClosingElem( xmlTokenVector tokVector );
	bool isProcElement( xmlTokenVector tokVector );
	bool isCommentElement( xmlTokenVector tokVector );
	bool isOpenTag( xmlTokenVector tokVector );
	bool isClosedTag( xmlTokenVector tokVector );
	void addtoXml( std::stack < IXmlElem* >& xmlElemStack,std::vector<std::string> tokens,XmlDoc* xmlDoc );
	XmlString createName( xmlTokenVector tokVector, int initElem);
	void handleOpenTag( std::stack < IXmlElem* >& xmlElemStack,std::vector<std::string> tokens,XmlDoc* xmlDoc );
	void handleCloseTag( std::stack < IXmlElem* >& xmlElemStack,std::vector<std::string> tokens,XmlDoc* xmlDoc );
	void handleSelfCloseTag( std::stack < IXmlElem* >& xmlElemStack,std::vector<std::string> tokens,XmlDoc* xmlDoc );
	int getIndex( xmlTokenVector tokVector,const std::string& charString );
	
	IXmlElem* makeProcElement( xmlTokenVector tokVector );
	IXmlElem* makeCommentElement( xmlTokenVector tokVector );
	
};

#endif