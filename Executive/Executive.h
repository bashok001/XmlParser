//*************************************************************************//
// Executive.h - Executive (Test case Driver)                              //
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
* This package drives all testcases for this project
*
* Public Interface:
* =================
*	Executive(); //Constructor
*	void demoRequirement1(); // Demo for requirement 1
*	void demoRequirement2();// Demo for requirement 2
*	void demoRequirement3( const std::string& fileName );// Demo for requirement 3
*	void demoRequirement4();// Demo for requirement 4
*	void demoRequirement5( const std::string& fileName,const std::string& tagIdVal );// Demo for requirement 5
*	void demoRequirement6( const std::string& fileName,const std::string& tagName );// Demo for requirement 6
*	void demoRequirement7( const std::string& fileName );// Demo for requirement 7
*	void demoRequirement8( const std::string& fileName );// Demo for requirement 8
*	void demoRequirement9( const std::string& fileName );// Demo for requirement 9
*	void demoRequirement10();// Demo for requirement 10
*	void demoRequirement11();// Demo for requirement 11
*	void demoRequirement12();// Demo for requirement 12
***
* Required Files:
* ---------------
*   - Executive.h, Executive.cpp
*
* Build Process:
* --------------
*   devenv XMLParser.sln /debug rebuild
*
* Maintenance History:
* --------------------
* Only first version out
*/
#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "../Utilities/Utilities.h"
#include "../InputParser/InputParser.h"
class Executive {
	public:
	Executive();
	void demoRequirement1();
	void demoRequirement2();
	void demoRequirement3( const std::string& fileName );
	void demoRequirement4();
	void demoRequirement5( const std::string& fileName,const std::string& tagIdVal );
	void demoRequirement6( const std::string& fileName,const std::string& tagName );
	void demoRequirement7( const std::string& fileName );
	void demoRequirement8( const std::string& fileName );
	void demoRequirement9( const std::string& fileName );
	void demoRequirement10();
	void demoRequirement11();
	void demoRequirement12();

	private:
	Utilities* _util;
	
	void clearScreen();
	void pauseToWait();
};

#endif