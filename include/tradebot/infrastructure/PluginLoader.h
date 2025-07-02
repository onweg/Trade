#pragma once
#include <string>
#include <memory>
#include "../interfaces/IStrategy.h"

namespace tradebot {

class PluginLoader {
public:
    PluginLoader() = default;
    ~PluginLoader();
    // Загружает стратегию из динамической библиотеки
    std::shared_ptr<IStrategy> loadPlugin(const std::string& path);
    // Выгружает стратегию
    void unloadPlugin();
private:
    void* handle_ = nullptr;
    std::shared_ptr<IStrategy> strategy_;
};

} // namespace tradebot
