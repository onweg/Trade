#pragma once
#include <string>
#include <cstdint>

namespace tradebot {

class MarketData {
public:
    MarketData() = default;
    MarketData(const std::string& symbol, double bid, double ask, double lastPrice, std::int64_t timestamp)
        : symbol_(symbol), bid_(bid), ask_(ask), lastPrice_(lastPrice), timestamp_(timestamp) {}

    const std::string& getSymbol() const { return symbol_; }
    double getBid() const { return bid_; }
    double getAsk() const { return ask_; }
    double getLastPrice() const { return lastPrice_; }
    std::int64_t getTimestamp() const { return timestamp_; }

    void setSymbol(const std::string& symbol) { symbol_ = symbol; }
    void setBid(double bid) { bid_ = bid; }
    void setAsk(double ask) { ask_ = ask; }
    void setLastPrice(double lastPrice) { lastPrice_ = lastPrice; }
    void setTimestamp(std::int64_t timestamp) { timestamp_ = timestamp; }

private:
    std::string symbol_;
    double bid_ = 0.0;
    double ask_ = 0.0;
    double lastPrice_ = 0.0;
    std::int64_t timestamp_ = 0;
};

}