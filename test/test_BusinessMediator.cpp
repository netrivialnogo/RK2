#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/BusinessMediator.h"
#include "../include/EstateOwner.h"
#include "../include/GroceryStore.h"
#include "../include/Restaurant.h"

class MockEstateOwner : public EstateOwner {
public:
    MOCK_METHOD(std::int32_t, SetEstateRentPrice, (std::int32_t price), (override));
};

class MockGroceryStore : public GroceryStore {
public:
    MOCK_METHOD(std::int32_t, AlterPrice, (std::int32_t priceChange), (override));
    MOCK_METHOD(std::int32_t, Sell, (), (override));
};

class MockRestaurant : public Restaurant {
public:
    MOCK_METHOD(std::int32_t, AlterPrice, (std::int32_t priceChange), (override));
    MOCK_METHOD(void, SetIsOpened, (design::AccessKey<BusinessMediator>, bool isOpened), (override));
};

TEST(BusinessMediatorTest, EstateRentPriceChanged) {
    MockEstateOwner owner;
    MockGroceryStore grocery;
    MockRestaurant restaurant;
    
    BusinessMediator mediator(owner, grocery, restaurant);
    
    EXPECT_CALL(grocery, AlterPrice(0)).Times(1);
    EXPECT_CALL(restaurant, AlterPrice(0)).Times(1);
    mediator.EstateRentPriceChanged(10000, 10000);
    
    EXPECT_CALL(grocery, AlterPrice(9)).Times(1);
    EXPECT_CALL(restaurant, AlterPrice(90)).Times(1);
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
    
    EXPECT_CALL(restaurant, AlterPrice(50)).Times(1);
    mediator.GroceryPriceChanged(100, 150);
}

TEST(BusinessMediatorTest, FoodIsCooked) {
    MockEstateOwner owner;
    MockGroceryStore grocery;
    MockRestaurant restaurant;
    
    BusinessMediator mediator(owner, grocery, restaurant);
    
    EXPECT_CALL(grocery, Sell()).Times(1);
    mediator.FoodIsCooked();
}
