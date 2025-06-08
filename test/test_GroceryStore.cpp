#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/GroceryStore.h"
#include "MockBusinessMediator.h"

TEST(GroceryStoreTest, Supply_IncreasesStock) {
    GroceryStore store;
    EXPECT_EQ(store.Supply(10), 10);
}

TEST(GroceryStoreTest, Sell_DecreasesStock) {
    GroceryStore store;
    store.Supply(5);
    store.Sell();
    EXPECT_EQ(store.Supply(0), 4); 
}

TEST(GroceryStoreTest, Sell_ThrowsWhenEmpty) {
    GroceryStore store;
    EXPECT_THROW(store.Sell(), std::logic_error);
}

TEST(GroceryStoreTest, AlterPrice_ChangesPrice) {
    GroceryStore store;
    EXPECT_EQ(store.AlterPrice(100), 100);
}
