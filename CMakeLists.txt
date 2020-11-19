CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    lab04/unit_test.cpp
    vectorContainer.cpp
    bubbleSort.cpp
)

ADD_EXECUTABLE(lab
    lab04/main.cpp
    vectorContainer.cpp
    bubbleSort.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)