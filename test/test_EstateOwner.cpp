#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/EstateOwner.h"
#include "../include/GroceryStore.h" 
#include "../include/Restaurant.h"    
#include "MockBusinessMediator.h"

TEST(EstateOwnerTest, SetEstateRentPrice_NotifiesMediator) {
    EstateOwner owner;
    GroceryStore dummyStore;
    Restaurant dummyRestaurant;
    MockBusinessMediator mediator(owner, dummyStore, dummyRestaurant);
    
    owner.SetBusinessMediator(design::AccessKey<BusinessMediator>::createForTesting(), &mediator);

    EXPECT_CALL(mediator, EstateRentPriceChanged(10000, 1000)).Times(1);
    owner.SetEstateRentPrice(1000);
}

TEST(EstateOwnerTest, SetEstateRentPrice_ReturnsOldPrice) {
    EstateOwner owner;
    EXPECT_EQ(owner.SetEstateRentPrice(1000), 0);
}
