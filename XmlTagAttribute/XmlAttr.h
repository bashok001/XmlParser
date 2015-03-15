#include "../XmlAttributeInterface/ITagAttr.h"

class XmlAttr : public ITagAttr {
	private:
	std::string _name;
	std::string _value;
	
	public:
	XmlAttr();
	~XmlAttr();

	virtual std::string &getName();
	void setName( const std::string& name );

	virtual std::string& getValue();
	void setValue( const std::string& value );
};