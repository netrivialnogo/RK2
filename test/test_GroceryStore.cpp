#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/GroceryStore.h"
#include "../include/BusinessMediator.h"
#include "../include/EstateOwner.h"
#include "../include/Restaurant.h"

using ::testing::_;

class MockBusinessMediator : public BusinessMediator {
public:
    MockBusinessMediator(EstateOwner& e, GroceryStore& g, Restaurant& r)
        : BusinessMediator(e, g, r) {}
    
    MOCK_METHOD(void, GroceryStockChanged, (int32_t), (override));
    MOCK_METHOD(void, GroceryPriceChanged, (int32_t, int32_t), (override));
};

TEST(GroceryStoreTest, Supply) {
    GroceryStore store;
    EXPECT_EQ(store.Supply(5), 5);
}

TEST(GroceryStoreTest, MediatorNotifications) {
    EstateOwner owner;
    GroceryStore store;
    Restaurant restaurant;
    MockBusinessMediator mediator(owner, store, restaurant);
    
    store.SetBusinessMediator(design::AccessKey<BusinessMediator>::createForTesting(), &mediator);
    
    EXPECT_CALL(mediator, GroceryStockChanged(5)).Times(1);
    store.Supply(5);
}
