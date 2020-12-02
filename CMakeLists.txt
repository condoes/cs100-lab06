CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    ListContainer.cpp
    vectorContainer.cpp
    SelectionSort.cpp
    bubbleSort.cpp
    all_tests.cpp
)

ADD_EXECUTABLE(lab
    lab04/main.cpp
    vectorContainer.cpp
    ListContainer.cpp
    bubbleSort.cpp
    SelectionSort.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
