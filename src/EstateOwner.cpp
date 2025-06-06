#include "EstateOwner.h"
#include "BusinessMediator.h"

std::int32_t EstateOwner::SetEstateRentPrice(std::int32_t price)
{
    auto oldPrice = estateRentPrice_;
    estateRentPrice_ = price;
    if (mediator_) mediator_->EstateRentPriceChanged(oldPrice, price);
    return oldPrice;
}

BusinessMediator* EstateOwner::SetBusinessMediator(design::AccessKey<BusinessMediator>, BusinessMediator* mediator)
{
    BusinessMediator* old = mediator_;
    mediator_ = mediator;
    return old;
}
