#include "../include/tradebot/infrastructure/PluginLoader.h"
#include "../include/tradebot/models/MarketData.h"
#include "../infrastructure/Logger.h"
#include <iostream>
#include <vector>
#include <random>
#include <memory>
#include <iomanip>

using tradebot::LOGGER;
using namespace tradebot;

struct TradeAction {
    std::string action; // "BUY" or "SELL"
    double price;
    int tick;
};

int main() {
    std::cout << "================ TRADE BOT SIMULATION ================\n";
    PluginLoader loader;

#ifdef __APPLE__
    std::string pluginPath = "./build/plugins/DummyStrategy/libDummyStrategy.dylib";
#else
    std::string pluginPath = "./build/plugins/DummyStrategy/libDummyStrategy.so";
#endif
    auto strategy = loader.loadPlugin(pluginPath);
    if (!strategy) {
        std::cerr << "Не удалось загрузить стратегию!" << std::endl;
        return 1;
    }

    std::vector<TradeAction> actions;
    double profit = 0.0;
    double lastBuyPrice = 0.0;
    bool hasPosition = false;

    // Генерация 20 случайных цен от 90 до 110
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(90, 110);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nTick | Price   | Action   | Position\n";
    std::cout << "--------------------------------------\n";

    for (int i = 0; i < 20; ++i) {
        double price = dis(gen);
        MarketData data("BTCUSDT", price - 0.5, price + 0.5, price, i); // bid, ask, lastPrice, timestamp
        std::string action = "-";
        std::string pos = hasPosition ? "OPEN" : "CLOSED";

        // Простая стратегия: если цена < 95 — BUY, если > 105 — SELL
        if (price < 95 && !hasPosition) {
            actions.push_back({"BUY", price, i});
            lastBuyPrice = price;
            hasPosition = true;
            action = "BUY";
        } else if (price > 105 && hasPosition) {
            actions.push_back({"SELL", price, i});
            profit += price - lastBuyPrice;
            hasPosition = false;
            action = "SELL";
        }
        std::cout << std::setw(4) << i << " | " << std::setw(7) << price << " | " << std::setw(8) << action << " | " << pos << std::endl;
        strategy->onMarketData(data);
    }

    // Если осталась открытая позиция — закрываем по последней цене
    if (hasPosition) {
        double lastPrice = actions.empty() ? 100.0 : actions.back().price;
        actions.push_back({"SELL", lastPrice, 19});
        profit += lastPrice - lastBuyPrice;
        std::cout << "(Close position) SELL at " << lastPrice << std::endl;
    }

    std::cout << "\n================ TRADE SUMMARY ================\n";
    std::cout << "Action | Tick |   Price\n";
    std::cout << "--------------------------\n";
    for (const auto& act : actions) {
        std::cout << std::setw(6) << act.action << " | " << std::setw(4) << act.tick << " | " << std::setw(7) << act.price << std::endl;
    }
    std::cout << "\nTotal profit: " << profit << std::endl;
    std::cout << "==============================================\n";

    loader.unloadPlugin();
    return 0;
}
