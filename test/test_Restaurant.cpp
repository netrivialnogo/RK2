#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/Restaurant.h"
#include "MockBusinessMediator.h"

TEST(RestaurantTest, CookFood_ReturnsPriceWhenOpen) {
    Restaurant restaurant;
    restaurant.SetIsOpened(design::AccessKey<BusinessMediator>::createForTesting(), true);
    EXPECT_GE(restaurant.CookFood(), 0);
}

TEST(RestaurantTest, CookFood_ReturnsNegativeWhenClosed) {
    Restaurant restaurant;
    restaurant.SetIsOpened(design::AccessKey<BusinessMediator>::createForTesting(), false);
    EXPECT_LT(restaurant.CookFood(), 0);
}

TEST(RestaurantTest, AlterPrice_ChangesPrice) {
    Restaurant restaurant;
    int oldPrice = restaurant.CookFood(); 
    EXPECT_EQ(restaurant.AlterPrice(100), oldPrice + 100);
}
