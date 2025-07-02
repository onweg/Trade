#pragma once
#include <string>
#include <cstdint>

namespace tradebot {

class Trade {
public:
    Trade() = default;
    Trade(const std::string& id, const std::string& orderId, const std::string& symbol, double price, double quantity, std::int64_t timestamp)
        : id_(id), orderId_(orderId), symbol_(symbol), price_(price), quantity_(quantity), timestamp_(timestamp) {}

    const std::string& getId() const { return id_; }
    const std::string& getOrderId() const { return orderId_; }
    const std::string& getSymbol() const { return symbol_; }
    double getPrice() const { return price_; }
    double getQuantity() const { return quantity_; }
    std::int64_t getTimestamp() const { return timestamp_; }

    void setId(const std::string& id) { id_ = id; }
    void setOrderId(const std::string& orderId) { orderId_ = orderId; }
    void setSymbol(const std::string& symbol) { symbol_ = symbol; }
    void setPrice(double price) { price_ = price; }
    void setQuantity(double quantity) { quantity_ = quantity; }
    void setTimestamp(std::int64_t timestamp) { timestamp_ = timestamp; }

private:
    std::string id_;
    std::string orderId_;
    std::string symbol_;
    double price_ = 0.0;
    double quantity_ = 0.0;
    std::int64_t timestamp_ = 0;
};

}