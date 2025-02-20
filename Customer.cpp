#include "Customer.h"

Customer::Customer(std::string name, double balance) : name(name), balance(balance) {}

bool Customer::purchase(Store& store, const std::string& productName, int quantity) {
    double price = store.getProductPrice(productName);
    if (price == std::numeric_limits<double>::max() || balance < price * quantity) {
        return false;
    }
    if (store.buyProduct(productName, quantity)) {
        balance -= price * quantity;
        return true;
    }
    return false;
}
