#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/BusinessMediator.h"
#include "../include/EstateOwner.h"
#include "../include/GroceryStore.h"
#include "../include/Restaurant.h"

using ::testing::_;
using ::testing::Return;

class MockEstateOwner : public EstateOwner {
public:
    MOCK_METHOD(std::int32_t, SetEstateRentPrice, (std::int32_t), (override));
};

class MockGroceryStore : public GroceryStore {
public:
    MOCK_METHOD(std::int32_t, AlterPrice, (std::int32_t), (override));
    MOCK_METHOD(std::int32_t, Sell, (), (override));
};

class MockRestaurant : public Restaurant {
public:
    MOCK_METHOD(std::int32_t, AlterPrice, (std::int32_t), (override));
    MOCK_METHOD(void, SetIsOpened, (design::AccessKey<BusinessMediator>, bool), (override));
};

TEST(BusinessMediatorTest, EstateRentPriceChanged) {
    MockEstateOwner owner;
    MockGroceryStore grocery;
    MockRestaurant restaurant;
    
    BusinessMediator mediator(owner, grocery, restaurant);
    
    EXPECT_CALL(grocery, AlterPrice(0)).WillOnce(Return(100));
    EXPECT_CALL(restaurant, AlterPrice(0)).WillOnce(Return(500));
    mediator.EstateRentPriceChanged(10000, 10000);
    
    EXPECT_CALL(grocery, AlterPrice(9)).WillOnce(Return(109));
    EXPECT_CALL(restaurant, AlterPrice(90)).WillOnce(Return(590));
    mediator.EstateRentPriceChanged(10000, 100000);
}

TEST(BusinessMediatorTest, GroceryStockChanged) {
    MockEstateOwner owner;
    MockGroceryStore grocery;
    MockRestaurant restaurant;
    
    BusinessMediator mediator(owner, grocery, restaurant);
    
    EXPECT_CALL(restaurant, SetIsOpened(design::AccessKey<BusinessMediator>(), true)).Times(1);
    mediator.GroceryStockChanged(5);
    
    EXPECT_CALL(restaurant, SetIsOpened(design::AccessKey<BusinessMediator>(), false)).Times(1);
    mediator.GroceryStockChanged(0);
}

TEST(BusinessMediatorTest, GroceryPriceChanged) {
    MockEstateOwner owner;
    MockGroceryStore grocery;
    MockRestaurant restaurant;
    
    BusinessMediator mediator(owner, grocery, restaurant);
    
    EXPECT_CALL(restaurant, AlterPrice(50)).WillOnce(Return(550));
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
