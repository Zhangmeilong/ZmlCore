#include "Xml.h"
#include "../Date/Date.h"

using namespace zml;

void Xml::CreateDefaultConf(const std::string& strConfFile)
{
	std::ofstream out(strConfFile, std::ios::trunc | std::ios::binary);
	if (out.is_open()) 
	{
		out.close();
	}
	else 
	{
		return;
	}
	XmlDocument document;
	XmlNode node_pi = document.allocate_node(XmlNodeType::node_pi, "xml version='1.0' encoding='utf-8'");
	document.append_node(node_pi);

	//application
	XmlNode node_comment_app = document.allocate_node(XmlNodeType::node_comment, "Application", "应用程序名称");
	document.append_node(node_comment_app);
	std::string strDate = Date::currentDate().toString();
	XmlAttribute attr_app = document.allocate_attribute("date", strDate.c_str());
	XmlNode node_app = document.allocate_node(XmlNodeType::node_element, "Application");
	node_app->append_attribute(attr_app);
	document.append_node(node_app);
	//fps
	XmlNode node_comment_fps = document.allocate_node(XmlNodeType::node_comment, "FPS", "帧率");
	node_app->append_node(node_comment_fps);
	XmlNode node_fps = document.allocate_node(XmlNodeType::node_element, "FPS", "30");
	node_app->append_node(node_fps);

	out.open(strConfFile, std::ios::trunc | std::ios::binary);
	if (out.is_open()) 
	{
		out << document;
		out.close();
	}
}