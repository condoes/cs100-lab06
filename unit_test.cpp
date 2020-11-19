#include "gtest/gtest.h"

// #include "op_test.hpp"
// #include "Mult_test.hpp"
// #include "Div_test.hpp"
// #include "sub_test.hpp"
// #include "add_test.hpp"
// #include "pow_test.hpp"
// #include "Rand_test.hpp"
#include "./lab-04---composite-pattern-cdo032-galva041-lab4/op.hpp"
#include "./lab-04---composite-pattern-cdo032-galva041-lab4/add.hpp"
#include "./lab-04---composite-pattern-cdo032-galva041-lab4/sub.hpp"
#include "./lab-04---composite-pattern-cdo032-galva041-lab4/Mult.hpp"
#include "ListContainer.hpp"
#include "container.hpp"
#include "base.hpp"
#include "SelectionSort.hpp"
#include "sort.hpp"
#include <iostream>
#include <string>
#include <list>

using namespace std;

TEST(ListConstructorTest, Empty) {
  ListContainer empty;
  testing::internal::CaptureStdout();
  empty.print();
  string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "");
}

TEST(ListAddTest, addElements) {
    Base* one = new Op(1);
    Base* five = new Op(5);
    Base* negTwo = new Op(-2);

    Container* container = new ListContainer();
    container->add_element(one);
    container->add_element(five);
    container->add_element(negTwo);

    EXPECT_EQ(container->at(0)->evaluate(), 1);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), -2);
}

TEST(ListPrintTest, print) {
    Base* one = new Op(1);
    Base* five = new Op(5);
    Base* negTwo = new Op(-2);

    Container* container = new ListContainer();
    container->add_element(one);
    container->add_element(five);
    container->add_element(negTwo);
    testing::internal::CaptureStdout();
    container->print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1.000000 5.000000 -2.000000 ");
}

TEST(ListSortTest, nullSort) {
    Base* one = new Op(1);
    Base* five = new Op(5);
    Base* ten = new Op(10);

    Container* container = new ListContainer();
    container->add_element(one);
    container->add_element(five);
    container->add_element(ten);

    container->sort();
    testing::internal::CaptureStdout();
    cout << "sort function is null- cannot call sort";
    string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "sort function is null- cannot call sort");
    EXPECT_EQ(container->at(0)->evaluate(), 1);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), 10);
}

TEST(ListSortTest, regularSort) {
    Op* one = new Op(1);
    Op* five = new Op(5);
    Add* six = new Add(one, five);
    cout << six->stringify() << endl;

    Op* two = new Op(2);
    Op* eight = new Op(8);
    Mult* sixteen = new Mult(two, eight);
    cout << sixteen->stringify() << endl;

    Op* twelve = new Op(12);
    Op* three = new Op(3);
    Sub* nine = new Sub(twelve, three);
    cout << nine->stringify() << endl;
    
    Container* container = new ListContainer(new SelectionSort());
    container->add_element(six);
    container->add_element(sixteen);
    container->add_element(nine);
    container->print();
    cout<< endl;
  
    EXPECT_EQ(container->at(0)->evaluate(), 6);
    EXPECT_EQ(container->at(1)->evaluate(), 16);
    EXPECT_EQ(container->at(2)->evaluate(), 9);

    //container->set_sort_function(new SelectionSort());
    container->sort();

    EXPECT_EQ(container->at(0)->evaluate(), 6);
    EXPECT_EQ(container->at(1)->evaluate(), 9);
    EXPECT_EQ(container->at(2)->evaluate(), 16);
}

TEST(ListSwapTest, swap) {
    Base* one = new Op(1);
    Base* five = new Op(5);
    Base* negTwo = new Op(-2);
    Base* ten = new Op(10);

    Container* container = new ListContainer();
    container->add_element(one);
    container->add_element(five);
    container->add_element(negTwo);
    container->add_element(ten);

    container->swap(0,3);
    container->swap(1, 2);
    EXPECT_EQ(container->at(0)->evaluate(), 10);
    EXPECT_EQ(container->at(3)->evaluate(), 1);
    EXPECT_EQ(container->at(1)->evaluate(), -2);
    EXPECT_EQ(container->at(2)->evaluate(), 5);
}

TEST(ListAtTest, at) {
    Base* one = new Op(1);
    Base* five = new Op(5);
    Base* negTwo = new Op(-2);
    Base* ten = new Op(10);

    Container* container = new ListContainer();
    container->add_element(one);
    container->add_element(five);
    container->add_element(negTwo);
    container->add_element(ten);

    EXPECT_EQ(container->at(0)->evaluate(), 1);
    EXPECT_EQ(container->at(1)->evaluate(), 5);
    EXPECT_EQ(container->at(2)->evaluate(), -2);
    EXPECT_EQ(container->at(3)->evaluate(), 10);
}

TEST(ListSizeTest, size) {
    Base* one = new Op(1);
    Base* five = new Op(5);
    Base* negTwo = new Op(-2);
    Base* ten = new Op(10);
    Base* six = new Op(6);

    Container* container = new ListContainer();
    container->add_element(one);
    container->add_element(five);
    container->add_element(negTwo);
    container->add_element(ten);
    container->add_element(six);

    EXPECT_EQ(container->size(), 5);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
