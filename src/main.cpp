#include <iostream>
#include "BusinessMediator.h"
#include "EstateOwner.h"
#include "GroceryStore.h"
#include "Restaurant.h"

void BuyFood(Restaurant& restaurant)
{
    auto price = restaurant.CookFood();
    if (price >= 0)
    {
        std::cout << "[BuyFood] The price of food : " << price << std::endl;
    }
    else
    {
        std::cout << "[BuyFood] Restaurant was closed because groceries are lack." << std::endl;
    }
}

void SupplyGrocery(GroceryStore& groceryStore, std::uint16_t count)
{
    auto newCount = groceryStore.Supply(count);
    auto oldCount = newCount - count;
    std::cout << "Grocery Stock Changes : " << oldCount << " -> " << newCount << std::endl;
}

void ChangeGroceryPrice(GroceryStore& groceryStore, std::int32_t priceChange)
{
    auto newPrice = groceryStore.AlterPrice(priceChange);
    auto oldPrice = newPrice - priceChange;
    std::cout << "Grocery Price Changes : " << oldPrice << " -> " << newPrice << std::endl;
}

void ChangeEstateRentPrice(EstateOwner& estateOwner, std::int32_t newPrice)
{
    auto oldPrice = estateOwner.SetEstateRentPrice(newPrice);
    std::cout << "EstateRentPrice Changes : " << oldPrice << " -> " << newPrice << std::endl;
}

int main()
{
    EstateOwner estateOwner;
    GroceryStore groceryStore;
    Restaurant restaurant;

    BusinessMediator mediator(estateOwner, groceryStore, restaurant);

    SupplyGrocery(groceryStore, 2);
    groceryStore.Sell();
    BuyFood(restaurant);
    BuyFood(restaurant);
    std::cout << std::endl;

    SupplyGrocery(groceryStore, 3);
    ChangeEstateRentPrice(estateOwner, 1000);
    BuyFood(restaurant);
    ChangeEstateRentPrice(estateOwner, 10000);
    BuyFood(restaurant);
    ChangeEstateRentPrice(estateOwner, 100000);
    BuyFood(restaurant);
    std::cout << std::endl;

    SupplyGrocery(groceryStore, 3);
    ChangeGroceryPrice(groceryStore, 100);
    BuyFood(restaurant);
    ChangeEstateRentPrice(estateOwner, 10000);
    BuyFood(restaurant);
    ChangeGroceryPrice(groceryStore, -100);
    BuyFood(restaurant);
    BuyFood(restaurant);
}
