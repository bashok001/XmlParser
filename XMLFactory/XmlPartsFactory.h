//*************************************************************************//
// XmlPartsFactory.h - Factory that creates elements                       //
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
* This provides a factory that generates concrete classes
* 
* Public Interface:
* =================
* static IXmlElem *getXmlElement( int typeOfXmlElem ); // Creates various types of XML Elements based on typeOfXmlElem
*
* Required Files:
* ---------------
*   - XmlPartsFactory.h, XmlPartsFactory.cpp
*
* Build Process:
* --------------
*   devenv XMLParser.sln /debug rebuild
*
* Maintenance History:
* --------------------
* Only first version out
*/
#ifndef XMLPARTSFACTORY_H
#define XMLPARTSFACTORY_H
#include "../XmlTagInterface/IXmlElem.h"

class XmlPartsFactory {
	public:
	static IXmlElem *getXmlElement( int typeOfXmlElem );
};

#endif