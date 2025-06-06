#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/EstateOwner.h"
#include "../include/BusinessMediator.h"

using ::testing::_;

namespace {
    template<typename T>
    design::AccessKey<T> MakeTestAccessKey() {
        struct TestKey : design::AccessKey<T> {
            TestKey() : design::AccessKey<T>() {}
        };
        return TestKey();
    }
}

class MockBusinessMediator : public BusinessMediator {
public:
    MockBusinessMediator() : BusinessMediator(*(EstateOwner*)nullptr, *(GroceryStore*)nullptr, *(Restaurant*)nullptr) {}
    
    MOCK_METHOD(void, EstateRentPriceChanged, (std::int32_t, std::int32_t), (override));
};

TEST(EstateOwnerTest, SetEstateRentPrice) {
    EstateOwner owner;
    EXPECT_EQ(owner.SetEstateRentPrice(15000), 10000);
    EXPECT_EQ(owner.SetEstateRentPrice(20000), 15000);
}

TEST(EstateOwnerTest, MediatorNotification) {
    EstateOwner owner;
    MockBusinessMediator mediator;
    
    owner.SetBusinessMediator(MakeTestAccessKey<BusinessMediator>(), &mediator);
    
    EXPECT_CALL(mediator, EstateRentPriceChanged(10000, 15000)).Times(1);
    owner.SetEstateRentPrice(15000);
}
