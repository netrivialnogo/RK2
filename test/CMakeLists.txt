
add_executable(BusinessMediatorTests
    test_EstateOwner.cpp
    test_GroceryStore.cpp
    test_Restaurant.cpp
    test_BusinessMediator.cpp
)


target_link_libraries(BusinessMediatorTests
    PRIVATE
    BusinessMediatorLib
    GTest::gtest
    GTest::gmock
    GTest::gtest_main 
)

include(GoogleTest)
gtest_discover_tests(BusinessMediatorTests)
