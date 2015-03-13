#include "Utilities.h"
#include  <iostream>

std::string Utilities::trimCharacters( " \f\n\r\t\v" );

void title( const std::string& title,char underline ) {
	std::cout << "\n  " << title;
	std::cout << "\n " << std::string( title.size() + 2,underline ) <<"\n";
}

void Utilities::trimRight( std::string& str,const trimChars& trimChars ) {
	std::string::size_type pos = str.find_last_not_of( trimChars );
	str.erase( pos + 1 );
}
void Utilities::trimLeft( std::string& str,const trimChars& trimChars ) {
	std::string::size_type pos = str.find_first_not_of( trimChars );
	str.erase( 0,pos );
}

Utilities::stringOut &Utilities::trim( std::string& str,const trimChars& trimChars ) {
	trimLeft( str,trimChars );
	trimRight( str,trimChars );
	return str;
}

Utilities::stringOut Utilities::toLower( const std::string str ) {
	std::string lowerStr = "";
	for( size_t i = 0; i<str.length(); i++ ) {
		lowerStr += ( ( char )tolower( str.at( i ) ) );
	}
	return lowerStr;
}

bool Utilities::equalsIgnoreCase( const std::string strA,const std::string strB ) {
	return( Utilities::toLower( strA ) == Utilities::toLower( strB ) );
}

#ifdef TEST_UTILITIES

int main() {
	Utilities* utils = new Utilities();
	std::string ab = "       Ashok Bom			";
	title( "Ashok and Test" );
	std::cout << "\n+" << ab << "+\n";
	utils->trimRight( ab );
	std::cout << "\n+" << ab << "+\n";
	utils->trimLeft( ab );
	std::cout << "\n+" << ab << "+\n";
	ab = "       Ashok Bom			";
	utils->trim( ab );
	std::cout << "\n+" << ab << "+\n";
	std::cout << "\n" << utils->toLower(ab)<<"\n";
	std::string bc = "ashOK BOM";
	std::cout << utils->equalsIgnoreCase( ab,bc )<<"\n";
}

#endif