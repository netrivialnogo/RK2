#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Restaurant.h"
#include "../include/BusinessMediator.h"
#include "../include/EstateOwner.h"
#include "../include/GroceryStore.h"

using ::testing::_;

class MockBusinessMediator : public BusinessMediator {
public:
    MockBusinessMediator(EstateOwner& e, GroceryStore& g, Restaurant& r)
        : BusinessMediator(e, g, r) {}
    
    MOCK_METHOD(void, FoodIsCooked, (), (override));
};

TEST(RestaurantTest, SetIsOpened) {
    Restaurant restaurant;
    restaurant.SetIsOpened(design::AccessKey<BusinessMediator>::createForTesting(), false);
    restaurant.SetIsOpened(design::AccessKey<BusinessMediator>::createForTesting(), true);
}
