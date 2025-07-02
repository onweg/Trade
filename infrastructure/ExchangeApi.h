#pragma once
#include "../include/tradebot/interfaces/IExchangeApi.h"

namespace tradebot {

class ExchangeApi : public IExchangeApi {
public:
    ExchangeApi() = default;
    void sendOrder(const Order& order) override {}
    void cancelOrder(const std::string& orderId) override {}
    void subscribeMarketData(const std::string& symbol) override {}
};

} // namespace tradebot
