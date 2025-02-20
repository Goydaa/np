#include "Store.h"

Store::Store(std::string name) : name(name) {}

void Store::addProduct(const std::string& productName, double price, int quantity) {
    for (auto& product : products) {
        if (product.name == productName) {
            product.quantity += quantity;
            return;
        }
    }
    products.emplace_back(productName, price, quantity);
}

bool Store::buyProduct(const std::string& productName, int quantity) {
    for (auto& product : products) {
        if (product.name == productName && product.quantity >= quantity) {
            product.quantity -= quantity;
            return true;
        }
    }
    return false;
}

double Store::getProductPrice(const std::string& productName) const {
    for (const auto& product : products) {
        if (product.name == productName) {
            return product.price;
        }
    }
    return std::numeric_limits<double>::max();
}
