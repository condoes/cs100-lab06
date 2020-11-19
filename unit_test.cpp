#include "gtest/gtest.h"

// #include "op_test.hpp"
// #include "Mult_test.hpp"
// #include "Div_test.hpp"
// #include "sub_test.hpp"
// #include "add_test.hpp"
// #include "pow_test.hpp"
// #include "Rand_test.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "../vectorContainer.hpp"
#include "../sort.hpp"
#include "../bubbleSort.hpp"

using namespace std;

TEST(VectContTest, EmptyCont) {
    VectorContainer empty;
    testing::internal::CaptureStdout();
    empty.print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

TEST(VectContTest, EmptyWithSortFunct) {
    BubbleSort* mySort;
    VectorContainer empty(mySort);
    testing::internal::CaptureStdout();
    empty.print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

TEST(VectContTest, addElements) {
    Base* one = new Op(1);
    Base* five = new Op(5);
    Base* negTwo = new Op(-2);
    VectorContainer container;
    container.add_element(one);
    container.add_element(five);
    container.add_element(negTwo);
    EXPECT_EQ(container.at(0)->evaluate(), 1);
    EXPECT_EQ(container.at(1)->evaluate(), 5);
    EXPECT_EQ(container.at(2)->evaluate(), -2);
}

TEST(VectContTest, SIZE) {
    Base* one = new Op(1);
    Base* five = new Op(5);
    Base* negTwo = new Op(-2);
    Container* container = new VectorContainer();
    container->add_element(one);
    container->add_element(five);
    container->add_element(negTwo);
    EXPECT_EQ(container->size(), 3);
}

TEST(VectContTest, print) {
    Base* one = new Op(1);
    Base* five = new Op(5);
    Base* negTwo = new Op(-2);
    Container* container = new VectorContainer();
    container->add_element(one);
    container->add_element(five);
    container->add_element(negTwo);
    testing::internal::CaptureStdout();
    container->print();
    string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1.000000 5.000000 -2.000000 ");
}

TEST(VectContTest, swap) {
    Base* one = new Op(1);
    Base* five = new Op(5);
    Base* negTwo = new Op(-2);
    Base* three = new Op(3);
    Base*  four = new Op(4);

    Container* container = new VectorContainer();
    container->add_element(one);
    container->add_element(five);
    container->add_element(negTwo);
    container->add_element(three);
    container->add_element(four);

    container->swap(0,1);
    container->swap(3,4); 
    EXPECT_EQ(container->at(0)->evaluate(), 5);
    EXPECT_EQ(container->at(1)->evaluate(), 1);
    EXPECT_EQ(container->at(3)->evaluate(), 4);
    EXPECT_EQ(container->at(4)->evaluate(), 3);
}

TEST(VectContTest, nullSort) {
    Container* container = new VectorContainer();
    container->sort();
} 

TEST(VectContTest, SortNums) {
    Base* one = new Op(1);
    Base* five = new Op(5);
    Base* negTwo = new Op(-2);
    Base* three = new Op(3);
    Base*  four = new Op(4);

    Container* container = new VectorContainer(new BubbleSort());
    container->add_element(one);
    container->add_element(five);
    container->add_element(negTwo);
    container->add_element(three);
    container->add_element(four);

    container->sort(); 
    EXPECT_EQ(container->at(0)->evaluate(), -2);
    EXPECT_EQ(container->at(1)->evaluate(), 1);
    EXPECT_EQ(container->at(2)->evaluate(), 3);
    EXPECT_EQ(container->at(3)->evaluate(), 4);
    EXPECT_EQ(container->at(4)->evaluate(), 5);
}

TEST(VectContTest, sort) {
    Op* two = new Op(2);
    Op* five = new Op(5);
    Mult* ten = new Mult(two, five);
    //cout << ten->stringify() << endl;

    Op* negTwo = new Op(-2);
    Op* eight = new Op(8);
    Add* six = new Add(negTwo, eight);
    //cout << six->stringify() << endl;

    Op* twelve = new Op(12);
    Op* one = new Op(1);
    Sub* eleven = new Sub(twelve, one);
    //cout << eleven->stringify() << endl;

    Container* container = new VectorContainer(new BubbleSort());
    container->add_element(ten);
    container->add_element(six);
    container->add_element(eleven);
    //container->print(); cout << endl;
    
    EXPECT_EQ(container->at(0)->evaluate(), 10);
    EXPECT_EQ(container->at(1)->evaluate(), 6);
    EXPECT_EQ(container->at(2)->evaluate(), 11);

    //BubbleSort* mySort;
    //container->set_sort_function(new BubbleSort());
    container->sort();
    
    EXPECT_EQ(container->at(0)->evaluate(), 6);
    EXPECT_EQ(container->at(1)->evaluate(), 10);
    EXPECT_EQ(container->at(2)->evaluate(), 11);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

