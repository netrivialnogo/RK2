#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <cstdint>
#include "AccessKey.h"

class BusinessMediator;

class Restaurant {
public:
    std::int32_t CookFood();
    std::int32_t AlterPrice(std::int32_t priceChange);
    BusinessMediator* SetBusinessMediator(design::AccessKey<BusinessMediator>, BusinessMediator* mediator);
    void SetIsOpened(design::AccessKey<BusinessMediator>, bool isOpened);

private:
    BusinessMediator* mediator_{ nullptr };
    bool isOpened_{ true };
    std::int32_t price_{ 500 };
};

#endif
