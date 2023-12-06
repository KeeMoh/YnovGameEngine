#pragma once
#include <yaml-cpp/yaml.h>
#include <map>
#include <string>

namespace YnovGameEngine {
	class ResourceManager
	{
	protected:
		YAML::Node _config;
		std::map<std::string, std::string> _assets;
		std::string FindExecutablePath();
		
	public:
		ResourceManager();
		std::string GetPathFromId(std::string id);
	};
}
