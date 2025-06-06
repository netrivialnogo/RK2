#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Restaurant.h"
#include "../include/BusinessMediator.h"

using ::testing::_;

class MockBusinessMediator : public BusinessMediator {
public:
    MockBusinessMediator() : BusinessMediator(*(EstateOwner*)nullptr, *(GroceryStore*)nullptr, *(Restaurant*)nullptr) {}
    
    MOCK_METHOD(void, FoodIsCooked, (), (override));
};

TEST(RestaurantTest, CookFood) {
    Restaurant restaurant;
    EXPECT_GE(restaurant.CookFood(), 0);
}

TEST(RestaurantTest, AlterPrice) {
    Restaurant restaurant;
    EXPECT_EQ(restaurant.AlterPrice(100), 600);
    EXPECT_EQ(restaurant.AlterPrice(-50), 550);
}

TEST(RestaurantTest, SetIsOpened) {
    Restaurant restaurant;
    restaurant.SetIsOpened(design::AccessKey<BusinessMediator>(), false);
    EXPECT_EQ(restaurant.CookFood(), -1);
    restaurant.SetIsOpened(design::AccessKey<BusinessMediator>(), true);
    EXPECT_GE(restaurant.CookFood(), 0);
}

TEST(RestaurantTest, MediatorNotification) {
    Restaurant restaurant;
    MockBusinessMediator mediator;
    
    restaurant.SetBusinessMediator(design::AccessKey<BusinessMediator>(), &mediator);
    
    EXPECT_CALL(mediator, FoodIsCooked()).Times(1);
    restaurant.CookFood();
}
