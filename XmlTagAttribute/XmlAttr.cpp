#include "XmlAttr.h"

XmlAttr::XmlAttr() {
	_name = "";
	_value = "";
}

XmlAttr::~XmlAttr() {
	
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

#ifdef TEST_XMLATTR

int main() {

}

#endif