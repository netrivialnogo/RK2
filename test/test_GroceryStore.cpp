#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/GroceryStore.h"
#include "MockBusinessMediator.h"

TEST(GroceryStoreTest, Supply_IncreasesStockAndNotifies) {
    GroceryStore store;
    EstateOwner dummyOwner;
    GroceryStore dummyStore;
    Restaurant dummyRestaurant;
    MockBusinessMediator mediator(dummyOwner, dummyStore, dummyRestaurant);
    
    store.SetBusinessMediator(design::AccessKey<BusinessMediator>::createForTesting(), &mediator);

    EXPECT_CALL(mediator, GroceryStockChanged(10)).Times(1);
    auto newStock = store.Supply(10);
    EXPECT_EQ(newStock, 10);
}
