#ifndef MOCKBUSINESSMEDIATOR_H
#define MOCKBUSINESSMEDIATOR_H

#include <gmock/gmock.h>
#include "../include/BusinessMediator.h"
#include "../include/EstateOwner.h"
#include "../include/GroceryStore.h"
#include "../include/Restaurant.h"

class MockBusinessMediator : public BusinessMediator {
public:

    MockBusinessMediator() : BusinessMediator(
        *static_cast<EstateOwner*>(nullptr), 
        *static_cast<GroceryStore*>(nullptr), 
        *static_cast<Restaurant*>(nullptr)) {}

    MockBusinessMediator(EstateOwner& e, GroceryStore& g, Restaurant& r)
        : BusinessMediator(e, g, r) {}

    MOCK_METHOD(void, EstateRentPriceChanged, (std::int32_t, std::int32_t), (override));
    MOCK_METHOD(void, GroceryStockChanged, (std::int32_t), (override));
    MOCK_METHOD(void, GroceryPriceChanged, (std::int32_t, std::int32_t), (override));
    MOCK_METHOD(void, FoodIsCooked, (), (override));
};

#endif 
