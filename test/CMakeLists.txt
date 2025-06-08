add_executable(BusinessMediatorTests
    test_EstateOwner.cpp
    test_GroceryStore.cpp
    test_Restaurant.cpp
    test_BusinessMediator.cpp
    MockBusinessMediator.h
)

target_link_libraries(BusinessMediatorTests
    PRIVATE
    BusinessMediatorLib
    GTest::GTest
    GMock::GMock
    GTest::Main
)

include(GoogleTest)
gtest_discover_tests(BusinessMediatorTests)
