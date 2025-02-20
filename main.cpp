#include <iostream>
#include <vector>
#include "Store.h"
#include "Customer.h"

Store* findCheapestStore(const std::vector<Store>& stores, const std::string& productName) {
    Store* cheapestStore = nullptr;
    double minPrice = std::numeric_limits<double>::max();

    for (const auto& store : stores) {
        double price = store.getProductPrice(productName);
        if (price < minPrice) {
            minPrice = price;
            cheapestStore = const_cast<Store*>(&store);
        }
    }
    return cheapestStore;
}

int main() {
    Store store1("TechMart");
    Store store2("ElectroWorld");

    store1.addProduct("Laptop", 1200.0, 5);
    store1.addProduct("Mouse", 20.0, 50);

    store2.addProduct("Laptop", 1100.0, 3);
    store2.addProduct("Mouse", 18.0, 30);

    Customer customer("Alice", 2000.0);

    std::vector<Store> stores = { store1, store2 };
    Store* cheapest = findCheapestStore(stores, "Laptop");
    if (cheapest) {
        std::cout << "The cheapest store for Laptop is: " << cheapest->name << "\\n";
    }

    if (customer.purchase(*cheapest, "Laptop", 1)) {
        std::cout << customer.name << " bought a Laptop from " << cheapest->name << "\\n";
    }
    else {
        std::cout << "Purchase failed.\\n";
    }

    return 0;
}

