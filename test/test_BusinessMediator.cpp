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

    int oldPrice = restaurant.CookFood();
    owner.SetEstateRentPrice(1000);
    EXPECT_NE(restaurant.CookFood(), oldPrice);
}

TEST(BusinessMediatorTest, GroceryStock_ControlsRestaurant) {
    EstateOwner owner;
    GroceryStore store;
    Restaurant restaurant;
    BusinessMediator mediator(owner, store, restaurant);

    while (store.Supply(0) > 0) {
        store.Sell();
    }
    
    EXPECT_LT(restaurant.CookFood(), 0); 

    store.Supply(1); 
    EXPECT_GE(restaurant.CookFood(), 0); 
}
