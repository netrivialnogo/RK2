#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/EstateOwner.h"
#include "MockBusinessMediator.h"

TEST(EstateOwnerTest, SetEstateRentPrice_NotifiesMediator) {
    EstateOwner owner;
    MockBusinessMediator mediator;
    owner.SetBusinessMediator(design::AccessKey<BusinessMediator>::createForTesting(), &mediator);

    EXPECT_CALL(mediator, EstateRentPriceChanged(0, 1000)).Times(1);
    owner.SetEstateRentPrice(1000);
}

TEST(EstateOwnerTest, SetEstateRentPrice_ReturnsOldPrice) {
    EstateOwner owner;
    EXPECT_EQ(owner.SetEstateRentPrice(1000), 0);
}
