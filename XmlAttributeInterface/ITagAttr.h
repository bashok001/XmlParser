//*************************************************************************//
// ITagAttr.h - Interface for Tag Attributes                                     //
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
* This is a interface for XML Tag attributes
*
* Public Interface:
* =================
*	virtual attributeC &getName() = 0;
*	virtual attributeC &getValue() = 0;
*	virtual const attributeC toString() = 0;
*
* Required Files:
* ---------------
*   - ITagAttr.h
*
* Build Process:
* --------------
*   devenv XMLParser.sln /debug rebuild
*
* Maintenance History:
* --------------------
* Only first version out
*/
#ifndef ITAGATTR_H
#define ITAGATTR_H

#include <string>

class ITagAttr {
	using attributeC = std::string;

	public:
	virtual attributeC &getName() = 0;
	virtual attributeC &getValue() = 0;
	virtual const attributeC toString() = 0;
};

#endif