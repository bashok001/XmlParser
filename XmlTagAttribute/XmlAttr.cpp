//*************************************************************************//
// XmlAttr.cpp - Implementation of XMLAttr                                   //
// ver 1.0                                                                 //
// ----------------------------------------------------------------------- //
// copyleft © Ashok Bommisetti, 2015                                       //
// No guarantees on anything; But free to modify, copy and distribute      //
// ----------------------------------------------------------------------- //
// Author:      Ashok Bommisetti							               //
// First Published (mm-dd-yyyy): 03-24-2015 			                   //
//*************************************************************************//
#include "XmlAttr.h"
#include <iostream>

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

XmlAttr::XmlAttr( XmlAttr&& xmlAttr ):_name(""),_value(""){
	_name =std::move(xmlAttr._name);
	_value = std::move( xmlAttr._value);
	xmlAttr._name.clear();
	xmlAttr._value.clear();
}

XmlAttr& XmlAttr::operator=( XmlAttr&& xmlAttribute ) {
	if( this != &xmlAttribute ) {
		_name.clear();
		_value.clear();
		_name = xmlAttribute._name;
		_value = xmlAttribute._value;
		xmlAttribute._name.clear();
		xmlAttribute._value.clear();
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
	XmlAttr* xmla = new XmlAttr();
	xmla->setValue("Value");
	xmla->setName("Name");
	std::cout << xmla->toString();
}

#endif