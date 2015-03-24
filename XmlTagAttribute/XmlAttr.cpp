//*************************************************************************//
// XmlAttr.cpp - Provides operations wrapper on FileSystem in formats    //
//					needed by this app                                     //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyleft © Ashok Bommisetti, 2015                                       //
// No guarantees on anything; But free to modify, copy and distribute      //
// ----------------------------------------------------------------------- //
// Author:      Ashok Bommisetti							               //
// First Published (mm-dd-yyyy): 03-24-2015 			                   //
//*************************************************************************//
#include "XmlAttr.h"

XmlAttr::XmlAttr() {
	_name = "";
	_value = "";
}

XmlAttr::~XmlAttr() {
	_name.clear();
	_value.clear();
}

XmlAttr::XmlAttr(const XmlAttr& xmlAttr ) {
	_name = xmlAttr._name;
	_value = xmlAttr._value;
}

XmlAttr& XmlAttr::operator=( XmlAttr&& xmlAttribute ) {
	if( this != &xmlAttribute ) {
		_name = xmlAttribute._name;
		_value = xmlAttribute._value;
		xmlAttribute._name.clear();
		xmlAttribute._value.clear();
		delete &xmlAttribute;
	}
	return *this;
}


XmlAttr& XmlAttr::operator=( XmlAttr& xmlAttribute ) {
	_name = xmlAttribute._name;
	_value = xmlAttribute._value;
	return *this;
}

std::string& XmlAttr::getName() {
	return _name;
}

void XmlAttr::setName( const std::string& name ) {
	_name = name;
}

std::string& XmlAttr::getValue() {
	return _value;
}

void XmlAttr::setValue( const std::string& value ) {
	_value = value;
}

const std::string XmlAttr::toString() {
	return std::string(" "+_name+" = "+_value+" ");
}

#ifdef TEST_XMLATTR

int main() {

}

#endif