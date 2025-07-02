#pragma once
#include "../include/tradebot/models/MarketData.h"
#include "../include/tradebot/models/Order.h"

namespace tradebot {

class TradeEngine {
public:
    TradeEngine() = default;
    void onMarketData(const MarketData& data) {}
    void onOrderUpdate(const Order& order) {}
};

} // namespace tradebot
