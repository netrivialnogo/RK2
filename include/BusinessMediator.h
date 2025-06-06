#ifndef BUSINESSMEDIATOR_H
#define BUSINESSMEDIATOR_H

#include "EstateOwner.h"
#include "GroceryStore.h"
#include "Restaurant.h"

class BusinessMediator {
public:
    BusinessMediator(EstateOwner& estateOwner, GroceryStore& groceryStore, Restaurant& restaurant);

    void EstateRentPriceChanged(std::int32_t oldPrice, std::int32_t newPrice);
    void GroceryStockChanged(std::int32_t currentStock);
    void GroceryPriceChanged(std::int32_t oldPrice, std::int32_t newPrice);
    void FoodIsCooked();

private:
    EstateOwner& estateOwner_;
    GroceryStore& groceryStore_;
    Restaurant& restaurant_;
};

#endif 
