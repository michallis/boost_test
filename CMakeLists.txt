cmake_minimum_required(VERSION 3.28)

project(boost_test)

set(CMAKE_CXX_STANDARD 17)
set(Boost_VERSION 1.86.0)
set(GTest_VERSION 1.15.2)

enable_testing()

find_package(Boost ${Boost_VERSION} CONFIG REQUIRED COMPONENTS system)
find_package(GTest CONFIG REQUIRED)

if(GTest_FOUND)
    message(STATUS "==> GTest_FOUND")
    message(STATUS "==> GTest_INCLUDE_DIRS: ${GTEST_INCLUDE_DIRS}")
endif()


if(Boost_FOUND)
    message(STATUS "==> Boost_FOUND")
    message(STATUS "==> Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    include_directories(${Boost_INCLUDE_DIRS} ${GTEST_INCLUDE_DIRS})
    add_executable(boost_test main.cpp)
    add_library(boost_lib main.cpp)
    target_link_libraries(boost_test PRIVATE ${Boost_LIBRARIES} GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main)
    add_test(AllTestsInMain main.cpp)
endif()