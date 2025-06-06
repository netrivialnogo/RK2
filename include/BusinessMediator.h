#ifndef BUSINESSMEDIATOR_H
#define BUSINESSMEDIATOR_H

#include <cstdint>  

class EstateOwner;
class GroceryStore;
class Restaurant;

class BusinessMediator {
public:
    virtual ~BusinessMediator() = default;
    virtual void EstateRentPriceChanged(std::int32_t oldPrice, std::int32_t newPrice) = 0;
    virtual void GroceryStockChanged(std::int32_t currentStock) = 0;
    virtual void GroceryPriceChanged(std::int32_t oldPrice, std::int32_t newPrice) = 0;
    virtual void FoodIsCooked() = 0;
};

#endif 
