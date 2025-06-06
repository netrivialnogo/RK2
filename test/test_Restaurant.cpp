#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Restaurant.h"
#include "../include/BusinessMediator.h"

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

TEST(RestaurantTest, MediatorNotification) {
    EstateOwner owner;
    GroceryStore grocery;
    Restaurant restaurant;
    MockBusinessMediator mediator(owner, grocery, restaurant);
    
    restaurant.SetBusinessMediator(design::AccessKey<BusinessMediator>::createForTesting(), &mediator);
    
    EXPECT_CALL(mediator, FoodIsCooked()).Times(1);
    restaurant.CookFood();
}
