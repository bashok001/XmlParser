//*************************************************************************//
// Executive.cpp - Executive (Test case Driver)                              //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyleft © Ashok Bommisetti, 2015                                       //
// No guarantees on anything; But free to modify, copy and distribute      //
// ----------------------------------------------------------------------- //
// Author:      Ashok Bommisetti							               //
// First Published (mm-dd-yyyy): 03-24-2015 			                   //
//*************************************************************************//
#include "Executive.h"
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "../XMLDomParser/XMLDomParser.h"
#include "../XmlTaggedElement/XmlTaggedElem.h"
#include "../XmlTagAttribute/XmlAttr.h"
#include "../FileOut/FileOut.h"

Executive::Executive() {
	_util = new Utilities();

}

void Executive::demoRequirement1() {
	std::cout << "Requirement 1: Not a functional requirement. \n";
	pauseToWait();
	clearScreen();
}

void Executive::demoRequirement2() {
	std::cout << "Requirement 2: Not a functional requirement. \n";
	pauseToWait();
	clearScreen();
}

void Executive::demoRequirement3( const std::string& fileName ) {
	InputParser* inputStrParser;
	InputParser* inputParser;
	static std::string xmldata( "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\
								<?xml-stylesheet type=\"text / xsl\" href=\"style.xsl\"?>\
								<!-- Operating Systems -->\
								<OSes>\
								<OS name=\"Linux\" tagid = \"gem\"/>\
								<OS name=\"Microsoft-Windows-8.1\" tagid = \"gem\">\
								</OS>\
								</OSes>" );
	inputStrParser = new InputParser( xmldata );
	XmlDomParser xmlStrDom( inputStrParser->getParsedInput() );
	title( "Reading XML from String" );
	std::cout << "String is: \n" << inputStrParser->getParsedInput() << "\n\n\n";
	std::cout << "Printing XML Document: \n" << xmlStrDom.getXmlDoc()->toString( 0 );
	pauseToWait();
	clearScreen();
	title( "Reading XML from file" );
	std::ifstream inputFile( fileName );
	inputParser = new InputParser( inputFile );
	XmlDomParser xmlDom( inputParser->getParsedInput() );
	std::cout << "File is: \n" << fileName << "\n\n\n";
	std::cout << "Printing XML Document: \n" << xmlDom.getXmlDoc()->toString( 0 );
	pauseToWait();
	clearScreen();
}

void Executive::demoRequirement4() {
	title( "Demo move operator =" );
	XmlDoc xmlDoc;
	IXmlElem* docroot = new XmlTaggedElem( "root" );
	xmlDoc.setDocRoot( docroot );
	xmlDoc.setValid();
	std::cout << "Printing Document Object \n";
	std::cout << xmlDoc.toString( 0 );
	std::cout << "\nDocument object is at address: " << &xmlDoc << std::endl;
	XmlDoc newXmlDoc;
	IXmlElem* newElemDocRoot = new XmlTaggedElem( "NewRoot" );
	newXmlDoc.setDocRoot( newElemDocRoot );
	newXmlDoc.setValid();
	newXmlDoc = std::move( xmlDoc );
	std::cout << newXmlDoc.toString(0);
	std::cout << "\nNew document object is at address: " << &newXmlDoc << std::endl;
	std::cout << "\nTrying to print Original Document Object - \n";
	std::cout << xmlDoc.toString( 0 );
	pauseToWait();
	clearScreen();
	title( "Demo move Constructor" );
	XmlDoc xmlDocMvConstructorDemo;
	IXmlElem* docRootMvConstructorDemo = new XmlTaggedElem( "MoveConstructorDemoRoot" );
	xmlDocMvConstructorDemo.setDocRoot( docRootMvConstructorDemo );
	xmlDocMvConstructorDemo.setValid();
	std::cout << "Printing Move Constructor Demo Document Object \n";
	std::cout << xmlDocMvConstructorDemo.toString( 0 );
	std::cout << "\nMove Constructor Demo Document Object is at address: " << &xmlDocMvConstructorDemo << std::endl;
	XmlDoc newXmlDocMvConstructorDemo = std::move( xmlDocMvConstructorDemo );
	std::cout << newXmlDocMvConstructorDemo.toString( 0 );
	std::cout << "\nNew Move Constructor Demo Document Object is at address: " << &newXmlDocMvConstructorDemo << std::endl;
	std::cout << "Trying to print Original Move Constructor Demo Document Object - \n";
	std::cout << xmlDocMvConstructorDemo.toString( 0 );
	pauseToWait();
	clearScreen();
}

void Executive::demoRequirement5( const std::string& fileName,const std::string& tagIdVal ) {
	std::ifstream inputFile( fileName );
	InputParser* inputParser = new InputParser( inputFile );
	XmlDomParser xmlDom( inputParser->getParsedInput() );
	title( "Attribute finder demo" );
	std::cout << "XML Under consideration is: \n";
	std::cout << xmlDom.getXmlDoc()->toString( 0 ) << std::endl;
	std::cout << "\nAttribute key is 'tagid' \n";
	std::cout << "\nFinding the first element with attribute value, " << tagIdVal << ": " << std::endl;
	if( xmlDom.getXmlDoc() != NULL ) {
		auto xmlElement = xmlDom.getXmlDoc()->findElementbyTagId( tagIdVal );
		if( xmlElement != NULL )
			std::cout << xmlElement->tagString() << std::endl;
		else
			std::cout << "No elements found.\n";
	} else {
		xmlDom.getXmlDoc()->toString( 0 );
	}
	pauseToWait();
	clearScreen();
}

void Executive::demoRequirement6( const std::string& fileName,const std::string& tagName ) {
	std::ifstream inputFile( fileName );
	InputParser* inputParser = new InputParser( inputFile );
	XmlDomParser xmlDom( inputParser->getParsedInput() );
	title( "Tag Name finder demo" );
	std::cout << "XML Under consideration is: \n";
	std::cout << xmlDom.getXmlDoc()->toString( 0 ) << std::endl;
	std::cout << "\nFinding elements with tag name, " << tagName << ": " << std::endl;
	auto xmlElements = xmlDom.getXmlDoc()->findElementsbyTagName( tagName );
	if( xmlElements.size() != 0 ) {
		for( auto elem : xmlElements )
			std::cout << elem->tagString() << "\n\n";
	} else
		std::cout << "No elements found.\n";

	pauseToWait();
	clearScreen();
}

void Executive::demoRequirement7( const std::string& fileName ) {
	std::ifstream inputFile( fileName );
	InputParser* inputParser = new InputParser( inputFile );
	XmlDomParser xmlDom( inputParser->getParsedInput() );
	title( "Add child demo" );
	std::cout << "XML Under consideration is: \n";
	std::cout << xmlDom.getXmlDoc()->toString( 0 ) << std::endl;
	XmlTaggedElem* anotherOS = new XmlTaggedElem( "OS" );
	XmlAttr* xmlAttr = new XmlAttr();
	xmlAttr->setName("name");
	xmlAttr->setValue("\"Unix\"");
	anotherOS->addAttribute(xmlAttr);
	bool addSuccess= xmlDom.getXmlDoc()->getRoot()->addChild(anotherOS);
	if( addSuccess ) {
		std::cout << "New XML is: \n";
		std::cout << xmlDom.getXmlDoc()->toString( 0 );
	} else {
		std::cout << "Add child failed.\n";
	}
	pauseToWait();
	clearScreen();
	title( "Remove child demo" );
	std::cout << "XML Under consideration is: \n";
	std::cout << xmlDom.getXmlDoc()->toString( 0 ) << std::endl;
	auto xmlElements=xmlDom.getXmlDoc()->findElementsbyTagName( "os" );
	if( xmlElements.size() > 0 ) {
		bool dropSuccess = xmlDom.getXmlDoc()->getRoot()->removeChild( xmlElements.at( 0 ) );
		if( dropSuccess ) {
			std::cout << "New XML is: \n";
			std::cout << xmlDom.getXmlDoc()->toString( 0 );
		} else {
			std::cout << "Drop child failed.\n";
		}
	} else {
		std::cout << "No children found for the tag to remove";
	}
	pauseToWait();
	clearScreen();
	title( "Add to empty document tree demo" );
	XmlDoc xmlDoc;
	IXmlElem* docroot = new XmlTaggedElem( "EmptyDocRoot" );
	xmlDoc.setDocRoot( docroot );
	xmlDoc.setValid();
	std::cout << xmlDoc.toString( 0 ) << std::endl;
	pauseToWait();
	clearScreen();
}

void Executive::demoRequirement8( const std::string& fileName ) {
	std::ifstream inputFile( fileName );
	InputParser* inputParser = new InputParser( inputFile );
	XmlDomParser xmlDom( inputParser->getParsedInput() );
	std::cout << "XML Under consideration is: \n";
	std::cout << xmlDom.getXmlDoc()->toString( 0 ) << std::endl;
	auto xmlElements = xmlDom.getXmlDoc()->findElementsbyTagName( "os" );
	title( "Get Attributes Demo for first OS tag" );
	if( xmlElements.size() > 0 ) {
		auto attributes = xmlElements.at( 0 )->getAllAttributes();
		if( attributes.size() == 0 )
			std::cout << "No Attributes found on this element. Empty vector returned\n";
		for( auto attr : attributes ) {
			std::cout << "Name: " << attr->getName() << std::endl;
			std::cout << "Value: " << attr->getValue() << std::endl;
			std::cout << "\n\n";
		}
	} else {
		std::cout << "No Elements found to display attributes.\n";
	}
	pauseToWait();
	clearScreen();
	std::cout << "XML Under consideration is: \n";
	std::cout << xmlDom.getXmlDoc()->toString( 0 ) << std::endl;
	title( "Getting children for Second OS Tag" );
	if( xmlElements.size() > 1 ) {
		auto children = xmlElements.at( 1 )->getChildren();
		if( children.size() == 0 )
			std::cout << "No Children found on this element. Empty vector returned\n";
		for( auto child : children ) {
			std::cout << child->tagString();
			std::cout << "\n\n";
		}
	} else {
		std::cout << "Less than 2 elements are found.\n";
	}
	pauseToWait();
	clearScreen();
}

void Executive::demoRequirement9( const std::string& fileName ) {
	std::ifstream inputFile( fileName );
	InputParser* inputParser = new InputParser( inputFile );
	XmlDomParser xmlDom( inputParser->getParsedInput() );
	std::cout << "XML Under consideration is: \n";
	std::cout << xmlDom.getXmlDoc()->toString( 0 ) << std::endl;
	title( "Getting Name Value Attribute from UILang tag" );
	auto xmlElements = xmlDom.getXmlDoc()->findElementsbyTagName( "uilang" );
	if( xmlElements.size() > 0 ) {
		auto attributes = xmlElements.at( 0 )->getAllAttributes();
		if( attributes.size() == 0 )
			std::cout << "No Attributes found on this element. Empty vector returned\n";
		for( auto attr : attributes ) {
			std::cout << "Name: " << attr->getName() << std::endl;
			std::cout << "Value: " << attr->getValue() << std::endl;
			std::cout << "\n\n";
		}
	} else {
		std::cout << "No Elements found to display attributes.\n";
	}
	pauseToWait();
	clearScreen();
	std::cout << "XML Under consideration is: \n";
	std::cout << xmlDom.getXmlDoc()->toString( 0 ) << std::endl;
	title( "Remove tagid attribute from UILang tag" );
	if( xmlElements.size() > 0 ) {
		if( XmlTaggedElem* xmlTaggedElement = dynamic_cast< XmlTaggedElem* > ( xmlElements.at( 0 ) ) ) {
			bool dropAttributeSuccess = xmlTaggedElement->removeAttribute( "tagid" );
			if( dropAttributeSuccess )
				std::cout << xmlDom.getXmlDoc()->toString( 0 ) << std::endl;
			else
				std::cout << "Remove attribute operation failed";
		}
	} else {
		std::cout << "No Elements found to display attributes.\n";
	}
	pauseToWait();
	clearScreen();
}

void Executive::demoRequirement10() {
	InputParser* inputStrParser;
	static std::string xmldata( "<?xml version=\"1.0\" encoding=\"utf-8\" ?>\
								<?xml-stylesheet type=\"text / xsl\" href=\"style.xsl\"?>\
								<!-- Operating Systems -->\
								<OSes>\
								<OS name=\"Linux\" tagid = \"gem\"/>\
								<OS name=\"Microsoft-Windows-8.1\" tagid = \"gem\">\
								</OS>\
								</OSes>" );
	inputStrParser = new InputParser( xmldata );
	XmlDomParser xmlStrDom( inputStrParser->getParsedInput() );
	title( "Reading XML from String" );
	std::cout << "XML Document Object is: \n" << xmlStrDom.getXmlDoc()->toString( 0 );
	title( "Writing XML to file to TestFolder/Output.xml" );
	FileOut* fileOut = new FileOut();
	fileOut->writeToFile( "TestFolder/Output.xml",xmlStrDom.getXmlDoc()->toString( 0 ) );
	pauseToWait();
	clearScreen();
}

void Executive::demoRequirement11() {
	std::cout << "Requirement 11: Not a functional requirement. \n";
	pauseToWait();
	clearScreen();
}


void Executive::demoRequirement12() {
	std::cout << "Requirement 12: Not a functional requirement. \n";
	pauseToWait();
	clearScreen();
}

void Executive::clearScreen() {
	system( "cls" );
}

void Executive::pauseToWait() {
	system( "pause" );
}

int main( int argc,char** argv ) {
	Executive* exec = new Executive();
	//exec->demoRequirement1();
	//exec->demoRequirement2();
	if( argc > 1 ) {
		exec->demoRequirement3( argv[ 1 ] );
		exec->demoRequirement5( argv[ 1 ],"os" );
		exec->demoRequirement6( argv[ 1 ],"os" );
		exec->demoRequirement7( argv[ 1 ] );
		exec->demoRequirement8( argv[ 1 ] );
		exec->demoRequirement9( argv[ 1 ] );
	} else {
		std::cout << "Requirements 3 5 6 7 8 9 are demonstrated based on file input. Please provide correct fileName as argument. \n";
	}
	exec->demoRequirement4();
	exec->demoRequirement10();
	//exec->demoRequirement11();
	//exec->demoRequirement12();
}