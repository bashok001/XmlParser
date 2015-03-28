//*************************************************************************//
// Utilities.h - Various string manipulations needed for XMLParser         //
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
* This package provides various utility functions needed.
*
* Public Interface:
* =================
*	void trimRight( std::string& str,const trimChars& trimChars = trimCharacters ); //Trims trimCharacters from right of string
*	void trimLeft( std::string& str,const trimChars& trimChars = trimCharacters ); //Trims trimCharacters from left of string
*	stringOut &trim( std::string& str,const trimChars& trimChars = trimCharacters ); //Trims trimCharacters on both sides of string
*	stringOut toLower( const std::string str ); //Converts str to lowercase
*	bool equalsIgnoreCase( const std::string a,const std::string b ); //Compares insensitive strings a and b
*	stringOut indentString( int depth ); //Gives indentation string with depth 'depth'
*	~Utilities() {} //Destructor
**
* Required Files:
* ---------------
*   - Utilities.h, Utilities.cpp
*
* Build Process:
* --------------
*   devenv XMLParser.sln /debug rebuild
*
* Maintenance History:
* --------------------
* Only first version out
*/
#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

void title( const std::string& title,char underline = '=' );

class Utilities {
	using trimChars = std::string;
	static trimChars trimCharacters;

	public:
	using stringOut = trimChars;

	void trimRight( std::string& str,const trimChars& trimChars = trimCharacters );
	void trimLeft( std::string& str,const trimChars& trimChars = trimCharacters );
	stringOut &trim( std::string& str,const trimChars& trimChars = trimCharacters );
	stringOut toLower( const std::string str );
	bool equalsIgnoreCase( const std::string a,const std::string b );
	
	stringOut indentString( int depth );
	
	~Utilities() {}
};
#endif