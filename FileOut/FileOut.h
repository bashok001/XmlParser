#ifndef FILEOUT_H
#define FILEOUT_H
#include <string>
//*************************************************************************//
// FileOut.h - Output file writer 											//
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
* This package supports writing to a file
*
* Public Interface:
* =================
* void writeToFile(const outputString& fileName, const outputString& output) // Writes output to file 'fileName'
* 
* Required Files:
* ---------------
*   - FileOut.h, FileOut.cpp
*
* Build Process:
* --------------
*   devenv XMLParser.sln /debug rebuild
*
* Maintenance History:
* --------------------
* Only first version out
*/
class FileOut {
	using outputString = std::string;

	public:
	void writeToFile(const outputString& fileName, const outputString& output);
};

#endif
