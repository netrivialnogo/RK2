#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/GroceryStore.h"
#include "../include/BusinessMediator.h"

using ::testing::_;

class MockBusinessMediator : public BusinessMediator {
public:
    MockBusinessMediator() : BusinessMediator(*(EstateOwner*)nullptr, *(GroceryStore*)nullptr, *(Restaurant*)nullptr) {}
    
    MOCK_METHOD(void, GroceryStockChanged, (std::int32_t), (override));
    MOCK_METHOD(void, GroceryPriceChanged, (std::int32_t, std::int32_t), (override));
};

TEST(GroceryStoreTest, Supply) {
    GroceryStore store;
    EXPECT_EQ(store.Supply(5), 5);
    EXPECT_EQ(store.Supply(3), 8);
}

TEST(GroceryStoreTest, Sell) {
    GroceryStore store;
    store.Supply(2);
    EXPECT_EQ(store.Sell(), 100);
    EXPECT_EQ(store.Sell(), 100);
    EXPECT_THROW(store.Sell(), std::logic_error);
}

TEST(GroceryStoreTest, AlterPrice) {
    GroceryStore store;
    EXPECT_EQ(store.AlterPrice(50), 150);
    EXPECT_EQ(store.AlterPrice(-30), 120);
}

TEST(GroceryStoreTest, MediatorNotifications) {
    GroceryStore store;
    MockBusinessMediator mediator;
    
    store.SetBusinessMediator(design::AccessKey<BusinessMediator>(), &mediator);
    
    EXPECT_CALL(mediator, GroceryStockChanged(5)).Times(1);
    store.Supply(5);
    
    EXPECT_CALL(mediator, GroceryStockChanged(4)).Times(1);
    store.Sell();
    
    EXPECT_CALL(mediator, GroceryPriceChanged(100, 150)).Times(1);
    store.AlterPrice(50);
}
