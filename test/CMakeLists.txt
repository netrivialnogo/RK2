cmake_minimum_required(VERSION 3.10)


enable_testing()


find_package(GTest REQUIRED)
find_package(GMock REQUIRED)


include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${GTEST_INCLUDE_DIRS}
    ${GMOCK_INCLUDE_DIRS}
)


add_executable(BusinessMediatorTests
    test_EstateOwner.cpp
    test_GroceryStore.cpp
    test_Restaurant.cpp
    test_BusinessMediator.cpp
)

target_link_libraries(BusinessMediatorTests
    BusinessMediatorLib
    GTest::GTest
    GMock::GMock
    ${CMAKE_THREAD_LIBS_INIT}
)


add_test(NAME BusinessMediatorTests COMMAND BusinessMediatorTests)
