CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    vector_unit_test.cpp
    list_tests.cpp
    ListContainer.cpp
    SelectionSort.cpp
    bubbleSort.cpp
)

ADD_EXECUTABLE(lab
    lab04/main.cpp
    vectorContainer.cpp
    bubbleSort.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
