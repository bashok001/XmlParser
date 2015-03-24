//*************************************************************************//
// InputParser.cpp - Provides operations wrapper on FileSystem in formats    //
//					needed by this app                                     //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyleft © Ashok Bommisetti, 2015                                       //
// No guarantees on anything; But free to modify, copy and distribute      //
// ----------------------------------------------------------------------- //
// Author:      Ashok Bommisetti							               //
// First Published (mm-dd-yyyy): 03-24-2015 			                   //
//*************************************************************************//

#include "InputParser.h"

#include <iostream>
#include <fstream>


InputParser::InputParser( InputParser::inputStr input ) {
	_inputString = _utilities->trim( input );
}

InputParser::InputParser( std::istream& inputFile ) {
	std::string strStore,trimStore;
	while( !inputFile.eof() ) {
		std::getline( inputFile,strStore );
		trimStore += _utilities->trim( strStore );
	}
	_inputString = trimStore;
}

InputParser::~InputParser() {
	_inputString = "";
	delete _utilities;
}

#ifdef TEST_INPUTPARSER

int main(){
	static std::string xmldata( "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\
	<OS name=\"Microsoft-Windows-8.1\">\
		<SetupLanguage>\
			<UILang>en-IN</UILang>\
			<ShowUI>OnError</ShowUI>\
		</SetupLanguage>\
		<SysLocale>en-US</SysLocale>\
		<UserLocale>en-IN</UserLocale>\
	</OS>" );
	InputParser inputP(xmldata);
	std::cout << inputP.getParsedInput();
	std::ifstream in("../TestFolder");
	InputParser inputP1( in );
	std::cout << "\n\n\n"<<inputP1.getParsedInput()<<"\n";
}

#endif