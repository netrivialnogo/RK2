#include "Restaurant.h"
#include "BusinessMediator.h"

std::int32_t Restaurant::CookFood()
{
    if (isOpened_)
    {
        if (mediator_) mediator_->FoodIsCooked();
        return price_;
    }
    else
    {
        return -1;
    }
}

std::int32_t Restaurant::AlterPrice(std::int32_t priceChange)
{
    price_ += priceChange;
    return price_;
}

BusinessMediator* Restaurant::SetBusinessMediator(design::AccessKey<BusinessMediator>, BusinessMediator* mediator)
{
    BusinessMediator* old = mediator_;
    mediator_ = mediator;
    return old;
}

void Restaurant::SetIsOpened(design::AccessKey<BusinessMediator>, bool isOpened)
{
    isOpened_ = isOpened;
}
