#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <filesystem>
#include <tuple>

namespace std_fs = std::filesystem;

namespace logging
{

void logLoadError(const std_fs::path& path);

};

class ResourceManager
{
private:
    explicit ResourceManager(std_fs::path path);

public:
    static const ResourceManager& getInstance();

    static const auto& getLocation()
    {
        return ResourceManager::getInstance().resourceLocation_;
    }

    template <typename ResourceType>
    static ResourceType load(const std_fs::path& path)
    {
        ResourceType resource;
        if (!resource.loadFromFile(getLocation() / path))
        {
            logging::logLoadError(path);
            std::terminate();
        }
        return resource;
    }

private:
    std::filesystem::path resourceLocation_;
};

#endif  // RESOURCEMANAGER_HPP
