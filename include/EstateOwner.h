#ifndef ESTATEOWNER_H
#define ESTATEOWNER_H

#include <cstdint>
#include "AccessKey.h"


class BusinessMediator;

class EstateOwner {
public:
    std::int32_t SetEstateRentPrice(std::int32_t price);
    BusinessMediator* SetBusinessMediator(design::AccessKey<BusinessMediator>, BusinessMediator* mediator);

private:
    BusinessMediator* mediator_{ nullptr };
    std::int32_t estateRentPrice_{ 10000 };
};

#endif
