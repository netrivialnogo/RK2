#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/BusinessMediator.h"
#include "../include/EstateOwner.h"
#include "../include/GroceryStore.h"
#include "../include/Restaurant.h"

using namespace testing;

class MockEstateOwner : public EstateOwner {
public:
    MOCK_METHOD(std::int32_t, SetEstateRentPrice, (std::int32_t), (override));
    MOCK_METHOD(BusinessMediator*, SetBusinessMediator, 
               (design::AccessKey<BusinessMediator>, BusinessMediator*), (override));
};

class MockGroceryStore : public GroceryStore {
public:
    MOCK_METHOD(std::int32_t, Supply, (std::uint16_t), (override));
    MOCK_METHOD(std::int32_t, Sell, (), (override));
    MOCK_METHOD(std::int32_t, AlterPrice, (std::int32_t), (override));
    MOCK_METHOD(BusinessMediator*, SetBusinessMediator,
               (design::AccessKey<BusinessMediator>, BusinessMediator*), (override));
};

class MockRestaurant : public Restaurant {
public:
    MOCK_METHOD(std::int32_t, CookFood, (), (override));
    MOCK_METHOD(std::int32_t, AlterPrice, (std::int32_t), (override));
    MOCK_METHOD(void, SetIsOpened, (design::AccessKey<BusinessMediator>, bool), (override));
    MOCK_METHOD(BusinessMediator*, SetBusinessMediator,
               (design::AccessKey<BusinessMediator>, BusinessMediator*), (override));
};

TEST(BusinessMediatorTest, EstateRentPriceChanged) {
    MockEstateOwner owner;
    MockGroceryStore grocery;
    MockRestaurant restaurant;
    BusinessMediator mediator(owner, grocery, restaurant);

    EXPECT_CALL(grocery, AlterPrice(_)).WillOnce(Return(100));
    EXPECT_CALL(restaurant, AlterPrice(_)).WillOnce(Return(500));
    
    mediator.EstateRentPriceChanged(10000, 10000);
}

TEST(BusinessMediatorTest, GroceryStockChanged) {
    MockEstateOwner owner;
    MockGroceryStore grocery;
    MockRestaurant restaurant;
    BusinessMediator mediator(owner, grocery, restaurant);

    auto testKey = design::AccessKey<BusinessMediator>::createForTesting();
    EXPECT_CALL(restaurant, SetIsOpened(testKey, true)).Times(1);
    mediator.GroceryStockChanged(5);

    EXPECT_CALL(restaurant, SetIsOpened(testKey, false)).Times(1);
    mediator.GroceryStockChanged(0);
}

TEST(BusinessMediatorTest, GroceryPriceChanged) {
    MockEstateOwner owner;
    MockGroceryStore grocery;
    MockRestaurant restaurant;
    BusinessMediator mediator(owner, grocery, restaurant);

    EXPECT_CALL(restaurant, AlterPrice(_)).WillOnce(Return(550));
    mediator.GroceryPriceChanged(100, 150);
}

TEST(BusinessMediatorTest, FoodIsCooked) {
    MockEstateOwner owner;
    MockGroceryStore grocery;
    MockRestaurant restaurant;
    BusinessMediator mediator(owner, grocery, restaurant);

    EXPECT_CALL(grocery, Sell()).WillOnce(Return(100));
    mediator.FoodIsCooked();
}
