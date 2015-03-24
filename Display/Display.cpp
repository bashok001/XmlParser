//*************************************************************************//
// Display.cpp - Provides operations wrapper on FileSystem in formats    //
//					needed by this app                                     //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyleft © Ashok Bommisetti, 2015                                       //
// No guarantees on anything; But free to modify, copy and distribute      //
// ----------------------------------------------------------------------- //
// Author:      Ashok Bommisetti							               //
// First Published (mm-dd-yyyy): 03-24-2015 			                   //
//*************************************************************************//

#include "Display.h"
#include <fstream>
#include <iostream>
#include "../InputParser/InputParser.h"

void Display::writeToFile( const outputString& fileName,const outputString& output ) {
	std::ofstream outputFile( fileName,std::ios::trunc );
	outputFile << output;
	outputFile.close();
}


#ifdef TEST_DISPLAY
int main() {
		static std::string xmldata( "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\
								<?xml-stylesheet type=\"text / xsl\" href=\"style.xsl\"?>\
								<!-- Operating Systems -->\
								<!-- Microsoft -->\
								<OSes>\
								<OS name=\"Linux\" tagid = \"gem\"/>\
								<OS name=\"Microsoft-Windows-8.1\" tagid = \"gem\">\
								<SetupLanguage>\
								<UILang tagid=\"ui\">en-IN</UILang>\
								<ShowUI tagid=\"ui\">OnError</ShowUI>\
								</SetupLanguage>\
								<SysLocale>en-US</SysLocale>\
								<UserLocale tagid=\"ui\">en-IN</UserLocale>\
								</OS>\
								</OSes>" );
		InputParser inputP( xmldata );
		Display* dip = new Display();
		dip->writeToFile( "../TestFolder/test.dat",inputP.getParsedInput() );
}
#endif
