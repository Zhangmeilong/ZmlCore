#pragma once
#include "Interface.h"

namespace zml 
{
	class ZML_API Xml
	{
	public:
		typedef rapidxml::xml_document<char>	XmlDocument;
		typedef rapidxml::xml_node<char>*		XmlNode;
		typedef rapidxml::xml_attribute<char>	XmlAttribute;
		typedef rapidxml::file<char>			XmlFile;
		typedef rapidxml::node_type				XmlNodeType;
	};
}