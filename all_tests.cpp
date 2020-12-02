#include "gtest/gtest.h"
#include "list_tests.hpp"
#include "ListContainer.hpp"
#include "vectorContainer.hpp"
#include "vector_unit_test.hpp"
#include "sort.hpp"
#include "base.hpp"


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

