#include <string>

class ITagAttr {
	using attributeC = std::string;

	public:
	virtual attributeC &getName() = 0;
	virtual attributeC &getValue() = 0;
	virtual const attributeC toString() = 0;
};