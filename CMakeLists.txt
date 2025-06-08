cmake_minimum_required(VERSION 3.10)
project(BusinessMediatorPattern)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(GTest REQUIRED)
find_package(GMock REQUIRED)  

include_directories(include)


add_library(BusinessMediatorLib STATIC
    src/BusinessMediator.cpp
    src/EstateOwner.cpp
    src/GroceryStore.cpp
    src/Restaurant.cpp
)


add_executable(BusinessMediatorDemo src/main.cpp)
target_link_libraries(BusinessMediatorDemo BusinessMediatorLib)


enable_testing()
add_subdirectory(test)
