#ifndef MOCKBUSINESSMEDIATOR_H
#define MOCKBUSINESSMEDIATOR_H

#include <gmock/gmock.h>
#include "../include/BusinessMediator.h"

class MockBusinessMediator : public BusinessMediator {
public:
    MOCK_METHOD(void, EstateRentPriceChanged, (std::int32_t, std::int32_t), (override));
    MOCK_METHOD(void, GroceryStockChanged, (std::int32_t), (override));
    MOCK_METHOD(void, GroceryPriceChanged, (std::int32_t, std::int32_t), (override));
    MOCK_METHOD(void, FoodIsCooked, (), (override));
};

#endif 
