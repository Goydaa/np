#ifndef STORE_H
#define STORE_H
#include <vector>
#include "Product.h"

class Store {
public:
    std::string name;
    std::vector<Product> products;

    Store(std::string name);
    void addProduct(const std::string& productName, double price, int quantity);
    bool buyProduct(const std::string& productName, int quantity);
    double getProductPrice(const std::string& productName) const;
};

#endif // STORE_H
