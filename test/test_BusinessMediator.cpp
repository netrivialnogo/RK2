#include <gtest/gtest.h>
#include "../include/BusinessMediator.h"
#include "../include/EstateOwner.h"
#include "../include/GroceryStore.h"
#include "../include/Restaurant.h"


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
