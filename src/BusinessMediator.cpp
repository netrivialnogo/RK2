#include "BusinessMediator.h"
#include "EstateOwner.h"
#include "GroceryStore.h"
#include "Restaurant.h"

BusinessMediator::BusinessMediator(EstateOwner& estateOwner, 
                                  GroceryStore& groceryStore, 
                                  Restaurant& restaurant)
    : estateOwner_(estateOwner),
      groceryStore_(groceryStore),
      restaurant_(restaurant) {}

void BusinessMediator::EstateRentPriceChanged(std::int32_t oldPrice, std::int32_t newPrice) {
    groceryStore_.AlterPrice((newPrice - oldPrice) / 10000);
    restaurant_.AlterPrice((newPrice - oldPrice) / 1000);
}

void BusinessMediator::GroceryStockChanged(std::int32_t currentStock) {
    if (currentStock > 0) {
        restaurant_.SetIsOpened(design::AccessKey<BusinessMediator>(), true);
    } else {
        restaurant_.SetIsOpened(design::AccessKey<BusinessMediator>(), false);
    }
}

void BusinessMediator::GroceryPriceChanged(std::int32_t oldPrice, std::int32_t newPrice) {
    restaurant_.AlterPrice(newPrice - oldPrice);
}

void BusinessMediator::FoodIsCooked() {
    groceryStore_.Sell();
}
