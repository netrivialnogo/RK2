#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Restaurant.h"
#include "../include/BusinessMediator.h"
#include "../include/EstateOwner.h"
#include "../include/GroceryStore.h"

using ::testing::_;

TEST(RestaurantTest, CookFood_NotifiesMediatorWhenOpen) {
    Restaurant restaurant;
    MockBusinessMediator mediator;
    restaurant.SetBusinessMediator(design::AccessKey<BusinessMediator>::createForTesting(), &mediator);
    restaurant.SetIsOpened(design::AccessKey<BusinessMediator>::createForTesting(), true);

    EXPECT_CALL(mediator, FoodIsCooked()).Times(1);
    auto price = restaurant.CookFood();
    EXPECT_GE(price, 0);
}

TEST(RestaurantTest, CookFood_ReturnsNegativeWhenClosed) {
    Restaurant restaurant;
    restaurant.SetIsOpened(design::AccessKey<BusinessMediator>::createForTesting(), false);
    auto price = restaurant.CookFood();
    EXPECT_LT(price, 0);
}
