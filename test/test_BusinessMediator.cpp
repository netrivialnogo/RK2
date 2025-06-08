#include <gtest/gtest.h>
#include "../include/BusinessMediator.h"
#include "../include/EstateOwner.h"
#include "../include/GroceryStore.h"
#include "../include/Restaurant.h"

TEST(BusinessMediatorTest, EstateRentChange_AffectsPrices) {
    EstateOwner owner;
    GroceryStore store;
    Restaurant restaurant;
    BusinessMediator mediator(owner, store, restaurant);

    owner.SetEstateRentPrice(1000);
    EXPECT_EQ(store.AlterPrice(0), 100);
    EXPECT_EQ(restaurant.AlterPrice(0), 1); 
}

TEST(BusinessMediatorTest, GroceryStock_ControlsRestaurant) {
    EstateOwner owner;
    GroceryStore store;
    Restaurant restaurant;
    BusinessMediator mediator(owner, store, restaurant);

    store.Supply(0);
    EXPECT_LT(restaurant.CookFood(), 0); 

    store.Supply(1);
    EXPECT_GE(restaurant.CookFood(), 0); 
}
