#pragma once
#include <string>
#include "Order.h"
#include "MarketData.h"

namespace tradebot {

class IExchangeApi {
public:
    virtual ~IExchangeApi() = default;
    virtual void sendOrder(const Order& order) = 0;
    virtual void cancelOrder(const std::string& orderId) = 0;
    virtual void subscribeMarketData(const std::string& symbol) = 0;
};

} // namespace tradebot 