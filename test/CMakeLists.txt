cmake_minimum_required(VERSION 3.10)

enable_testing()

find_package(GTest REQUIRED)

include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_executable(BusinessMediatorTests
    test_EstateOwner.cpp
    test_GroceryStore.cpp
    test_Restaurant.cpp
)

target_link_libraries(BusinessMediatorTests
    BusinessMediatorLib
    GTest::gtest
    GTest::gtest_main
    GTest::gmock
    GTest::gmock_main
    ${CMAKE_THREAD_LIBS_INIT}
)

add_test(NAME BusinessMediatorTests COMMAND BusinessMediatorTests)
