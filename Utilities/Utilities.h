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

	~Utilities() {}
};
#endif