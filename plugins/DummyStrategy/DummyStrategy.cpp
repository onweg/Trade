#include "../../include/tradebot/interfaces/IStrategy.h"
#include "../../include/tradebot/models/Order.h"
#include "../../infrastructure/Logger.h"
#include <iostream>
#include <memory>

namespace tradebot {

class DummyStrategy : public IStrategy {
public:
    DummyStrategy() = default;
    void onMarketData(const MarketData& data) override {
        double price = data.getLastPrice();
        if (price > 100) {
            LOGGER() << "[DummyStrategy] Signal: BUY order at price " << price << std::endl;
        } else if (price < 95) {
            LOGGER() << "[DummyStrategy] Signal: SELL order at price " << price << std::endl;
        }
    }
    void onOrderUpdate(const Order& order) override {
        LOGGER() << "[DummyStrategy] Order update: " << order.getId() << std::endl;
    }
    void onTrade(const Trade& trade) override {
        LOGGER() << "[DummyStrategy] Trade: " << trade.getId() << std::endl;
    }
    std::string getName() const override {
        return "DummyStrategy";
    }
};

// Экспортируемая функция для загрузки плагина
extern "C" IStrategy* create_strategy() {
    return new DummyStrategy();
}

} // namespace tradebot
