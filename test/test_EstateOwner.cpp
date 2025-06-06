#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/EstateOwner.h"
#include "../include/BusinessMediator.h"
#include "../include/GroceryStore.h"
#include "../include/Restaurant.h"

using ::testing::_;

class MockBusinessMediator : public BusinessMediator {
public:
    MockBusinessMediator(EstateOwner& e, GroceryStore& g, Restaurant& r)
        : BusinessMediator(e, g, r) {}
    
    MOCK_METHOD(void, EstateRentPriceChanged, (int32_t, int32_t), (override));
};

TEST(EstateOwnerTest, SetEstateRentPrice) {
    EstateOwner owner;
    EXPECT_EQ(owner.SetEstateRentPrice(15000), 10000);
}

TEST(EstateOwnerTest, MediatorNotification) {
    EstateOwner owner;
    GroceryStore grocery;
    Restaurant restaurant;
    MockBusinessMediator mediator(owner, grocery, restaurant);
    
    owner.SetBusinessMediator(design::AccessKey<BusinessMediator>::createForTesting(), &mediator);
    
    EXPECT_CALL(mediator, EstateRentPriceChanged(10000, 15000)).Times(1);
    owner.SetEstateRentPrice(15000);
}
