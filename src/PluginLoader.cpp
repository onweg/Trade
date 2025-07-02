#include "../include/tradebot/infrastructure/PluginLoader.h"
#include <dlfcn.h>
#include <iostream>

namespace tradebot {

using CreateStrategyFunc = IStrategy*();

PluginLoader::~PluginLoader() {
    unloadPlugin();
}

std::shared_ptr<IStrategy> PluginLoader::loadPlugin(const std::string& path) {
    handle_ = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle_) {
        std::cerr << "[PluginLoader] Failed to load plugin: " << dlerror() << std::endl;
        return nullptr;
    }
    dlerror(); // очистить ошибки
    auto create = (CreateStrategyFunc*)dlsym(handle_, "create_strategy");
    if (!create) {
        std::cerr << "[PluginLoader] Failed to find create_strategy: " << dlerror() << std::endl;
        dlclose(handle_);
        handle_ = nullptr;
        return nullptr;
    }
    strategy_.reset(create());
    return strategy_;
}

void PluginLoader::unloadPlugin() {
    if (handle_) {
        strategy_.reset();
        dlclose(handle_);
        handle_ = nullptr;
    }
}

} // namespace tradebot
