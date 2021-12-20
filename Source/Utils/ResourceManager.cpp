#include "ResourceManager.hpp"

#include <iostream>

void logging::logLoadError(const std_fs::path& path)
{
    std::cerr << "error: Could not load resource: " << path << std::endl;
}

ResourceManager::ResourceManager(std_fs::path path)
    : resourceLocation_(std::move(path))
{
}

const ResourceManager& ResourceManager::getInstance()
{
    static auto instance = []
    {
        ResourceManager instance{std_fs::current_path().parent_path() / "Resources"};
        // Checked once, during static initialization
        if (!std_fs::exists(instance.resourceLocation_))
        {
            std::cerr << "error: Resources directory was not found" << std::endl;
            std::terminate();
        }
        return instance;
    }();
    return instance;
}
