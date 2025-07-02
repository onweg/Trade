#pragma once
#include <string>
#include <vector>
#include "../include/tradebot/models/Order.h"

namespace tradebot {

class OrderManager {
public:
    OrderManager() = default;
    void addOrder(const Order& order) {}
    void cancelOrder(const std::string& orderId) {}
    std::vector<Order> getAllOrders() const { return {}; }
};

} // namespace tradebot
