#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "Store.h"

class Customer {
public:
    std::string name;
    double balance;

    Customer(std::string name, double balance);
    bool purchase(Store& store, const std::string& productName, int quantity);
};

#endif // CUSTOMER_H
