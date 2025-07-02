#pragma once
#include <string>
#include "Order.h"
#include "Trade.h"
#include "MarketData.h"

namespace tradebot {

class IStrategy {
public:
    virtual ~IStrategy() = default;
    virtual void onMarketData(const MarketData& data) = 0;
    virtual void onOrderUpdate(const Order& order) = 0;
    virtual void onTrade(const Trade& trade) = 0;
    virtual std::string getName() const = 0;
};

} // namespace tradebot
