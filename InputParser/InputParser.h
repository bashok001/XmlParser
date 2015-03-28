//*************************************************************************//
// InputParser.h - Parses input provided to the project from file or string//
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
* This package reads input from different sources.

* Public Interface:
* =================
*	InputParser(inputStr inputString) // Constructor that sets up the value in _inputString
*	InputParser(std::istream& inputFile ); // Constructor that sets _inputString from file
*	~InputParser(); // Destructor
*	inputStr getParsedInput() { return _inputString; } // return _inputString
*
* Required Files:
* ---------------
*   - InputParser.h, InputParser.cpp
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