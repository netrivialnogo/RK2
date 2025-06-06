#ifndef BUSINESSMEDIATOR_H
#define BUSINESSMEDIATOR_H

#include <cstdint>

class EstateOwner;
class GroceryStore;
class Restaurant;

class BusinessMediator {
public:
    BusinessMediator(EstateOwner& estateOwner, GroceryStore& groceryStore, Restaurant& restaurant);
    virtual ~BusinessMediator() = default;
    
    virtual void EstateRentPriceChanged(std::int32_t oldPrice, std::int32_t newPrice);
    virtual void GroceryStockChanged(std::int32_t currentStock);
    virtual void GroceryPriceChanged(std::int32_t oldPrice, std::int32_t newPrice);
    virtual void FoodIsCooked();

protected:
    EstateOwner& estateOwner_;
    GroceryStore& groceryStore_;
    Restaurant& restaurant_;
};

#endif
