#include "ResourceManager.h"


#include <filesystem>
#include <windows.h>

YnovGameEngine::ResourceManager::ResourceManager()
{
	std::string filepath = FindExecutablePath();
	_config = YAML::LoadFile(filepath + "/config.yaml");

	YAML::Node assetnode = _config["assets"];
	for (auto node : assetnode) {
		_assets[node["id"].as<std::string>()] = node["path"].as<std::string>();
	}
}

std::string YnovGameEngine::ResourceManager::FindExecutablePath()
{
	TCHAR buffer[MAX_PATH];
	GetModuleFileName(NULL, buffer, sizeof(buffer));
	// pour avoir le path absolue
	return std::filesystem::path(buffer).parent_path().string();
}

std::string YnovGameEngine::ResourceManager::GetPathFromId(std::string id)
{
	YAML::Node assetnode = _config["assets"];
	for (auto [ID, path] : _assets) {
		if (ID == id) {
			return path;
		}
	}
	return nullptr;
}
