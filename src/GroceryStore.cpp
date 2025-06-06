#include "GroceryStore.h"
#include "BusinessMediator.h"

std::int32_t GroceryStore::Supply(std::uint16_t count)
{
    stock_ += count;
    if (mediator_) mediator_->GroceryStockChanged(stock_);
    return stock_;
}

std::int32_t GroceryStore::Sell()
{
    if (stock_ <= 0)
    {
        throw std::logic_error("Not in stock.");
    }

    --stock_;
    if (mediator_) mediator_->GroceryStockChanged(stock_);
    return price_;
}

std::int32_t GroceryStore::AlterPrice(std::int32_t priceChange)
{
    auto oldPrice = price_;
    price_ += priceChange;
    if (mediator_) mediator_->GroceryPriceChanged(oldPrice, price_);
    return price_;
}

BusinessMediator* GroceryStore::SetBusinessMediator(design::AccessKey<BusinessMediator>, BusinessMediator* mediator)
{
    BusinessMediator* old = mediator_;
    mediator_ = mediator;
    return old;
}
