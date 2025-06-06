#include <gtest/gtest.h>
#include "../include/EstateOwner.h"
#include "../include/BusinessMediator.h"

class MockMediator : public BusinessMediator {
public:
    MockMediator() : BusinessMediator(*(EstateOwner*)nullptr, *(GroceryStore*)nullptr, *(Restaurant*)nullptr) {}
    MOCK_METHOD(void, EstateRentPriceChanged, (std::int32_t oldPrice, std::int32_t newPrice), (override));
};

TEST(EstateOwnerTest, SetEstateRentPrice) {
    EstateOwner owner;
    EXPECT_EQ(owner.SetEstateRentPrice(15000), 10000);
    EXPECT_EQ(owner.SetEstateRentPrice(20000), 15000);
}

TEST(EstateOwnerTest, MediatorNotification) {
    EstateOwner owner;
    MockMediator mediator;
    
    owner.SetBusinessMediator(design::AccessKey<BusinessMediator>(), &mediator);
    
    EXPECT_CALL(mediator, EstateRentPriceChanged(10000, 15000)).Times(1);
    owner.SetEstateRentPrice(15000);
}
