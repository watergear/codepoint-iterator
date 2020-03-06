cmake_minimum_required(VERSION 2.8)

project(CodepointIterator)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})

include_directories(
	src/
)

add_executable(tests 
	test.cpp
	src/codepoint_iterator.cpp
)

target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(tests tests)