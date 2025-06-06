cmake_minimum_required(VERSION 3.10)

enable_testing()

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(BusinessMediatorTests
    test_EstateOwner.cpp
    test_GroceryStore.cpp
    test_Restaurant.cpp
)

target_link_libraries(BusinessMediatorTests
    PRIVATE
    GTest::GTest
    GTest::Main
    Threads::Threads
    BusinessMediatorLib
)

target_include_directories(BusinessMediatorTests
    PRIVATE ${CMAKE_SOURCE_DIR}/include
)


add_test(NAME BusinessMediatorTests
         COMMAND BusinessMediatorTests)
