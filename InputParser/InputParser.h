//*************************************************************************//
// InputParser.h - Provides operations wrapper on FileSystem in formats    //
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
#ifndef INPUTPARSER_H
#define INPUTPARSER_H
#include <string>
#include "../Utilities/Utilities.h"

class InputParser {
	using inputStr = std::string;

	public:
	InputParser(inputStr inputString);
	InputParser(std::istream& inputFile );
	~InputParser();
	inputStr getParsedInput() { return _inputString; }

	private:
	InputParser();
	inputStr _inputString;

	protected:
	Utilities* _utilities = new Utilities();
};
#endif