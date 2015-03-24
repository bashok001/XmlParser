#ifndef INPUTPARSER_H
#define INPUTPARSER_H
#include <string>
#include "../Utilities/Utilities.h"

class InputParser {
	using inputStr = std::string;

	public:
	InputParser(inputStr inputString);
	InputParser(std::istream& inputFile );
	~InputParser();
	inputStr getParsedInput() { return _inputString; }

	private:
	InputParser();
	inputStr _inputString;

	protected:
	Utilities* _utilities = new Utilities();
};
#endif