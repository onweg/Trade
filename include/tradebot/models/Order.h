#pragma once
#include <string>

namespace tradebot {

enum class OrderSide { Buy, Sell };
enum class OrderStatus { New, Filled, Cancelled, Rejected };

class Order {
public:
    Order() = default;
    Order(const std::string& id, const std::string& symbol, OrderSide side, double price, double quantity, OrderStatus status)
        : id_(id), symbol_(symbol), side_(side), price_(price), quantity_(quantity), status_(status) {}

    const std::string& getId() const { return id_; }
    const std::string& getSymbol() const { return symbol_; }
    OrderSide getSide() const { return side_; }
    double getPrice() const { return price_; }
    double getQuantity() const { return quantity_; }
    OrderStatus getStatus() const { return status_; }

    void setId(const std::string& id) { id_ = id; }
    void setSymbol(const std::string& symbol) { symbol_ = symbol; }
    void setSide(OrderSide side) { side_ = side; }
    void setPrice(double price) { price_ = price; }
    void setQuantity(double quantity) { quantity_ = quantity; }
    void setStatus(OrderStatus status) { status_ = status; }

private:
    std::string id_;
    std::string symbol_;
    OrderSide side_ = OrderSide::Buy;
    double price_ = 0.0;
    double quantity_ = 0.0;
    OrderStatus status_ = OrderStatus::New;
};

}