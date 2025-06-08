#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/GroceryStore.h"
#include "../include/BusinessMediator.h"
#include "../include/EstateOwner.h"
#include "../include/Restaurant.h"

using ::testing::_;

TEST(GroceryStoreTest, Supply_IncreasesStockAndNotifies) {
    GroceryStore store;
    MockBusinessMediator mediator;
    store.SetBusinessMediator(design::AccessKey<BusinessMediator>::createForTesting(), &mediator);

    EXPECT_CALL(mediator, GroceryStockChanged(10)).Times(1);
    auto newStock = store.Supply(10);
    EXPECT_EQ(newStock, 10);
}

TEST(GroceryStoreTest, Sell_DecreasesStockAndNotifies) {
    GroceryStore store;
    store.Supply(5);  
    
    MockBusinessMediator mediator;
    store.SetBusinessMediator(design::AccessKey<BusinessMediator>::createForTesting(), &mediator);

    EXPECT_CALL(mediator, GroceryStockChanged(4)).Times(1);
    auto price = store.Sell();
    EXPECT_GT(price, 0);
}

TEST(GroceryStoreTest, Sell_ThrowsWhenEmpty) {
    GroceryStore store;
    EXPECT_THROW(store.Sell(), std::logic_error);
}


