#include "BinaryTreeHeader/BinaryTree.h"
#include <iostream>
#include <gtest/gtest.h>

TEST(TreeTest, SizeTestOne) {
    BMSTU::BinaryTree<int,int> myTree;
    EXPECT_EQ(myTree.Size(), 0);
}

TEST(TreeTest, SizeTestTwo) {
    BMSTU::BinaryTree<int,int> myTree(-1, 0);
    EXPECT_EQ(myTree.Size(), 1);
}

TEST(TreeTest, SizeTestThree) {
    BMSTU::BinaryTree<int,int> myTree;
    for(size_t i = 0; i < 10; i++)
        myTree.Insert(i, 0);
    EXPECT_EQ(myTree.Size(), 10);
}

TEST(TreeTest, ContainsTestOne) {
    BMSTU::BinaryTree<int,int> myTree;
    for(size_t i = 0; i < 10; i++)
        myTree.Insert(i, 0);
    EXPECT_EQ(myTree.Contains(5), 1);
}

TEST(TreeTest, ContainsTestTwo) {
    BMSTU::BinaryTree<int,int> myTree;
    for(size_t i = 0; i < 10; i++)
        myTree.Insert(i, 0);
    EXPECT_EQ(myTree.Contains(15), 0);
}

TEST(TreeTest, PrintTest) {
    BMSTU::BinaryTree<int,int> myTree;
    for(size_t i = 0; i < 10; i++)
        myTree.Insert(i, 0);
    myTree.Print();
    EXPECT_TRUE(1);
}

TEST(TreeTest, HeightTestOne) {
    BMSTU::BinaryTree<int,int> myTree(5, 0);
    EXPECT_EQ(myTree.Height(5), 0);
}

TEST(TreeTest, HeightTestTwo) {
    BMSTU::BinaryTree<int,int> myTree;
    for(size_t i = 0; i < 10; i++)
        myTree.Insert(i, 0);
    EXPECT_EQ(myTree.Height(5), 1);
}

TEST(TreeTest, HeightTestThree) {
    BMSTU::BinaryTree<int,int> myTree;
    for(size_t i = 0; i < 10; i++)
        myTree.Insert(i, 0);
    EXPECT_EQ(myTree.Height(-1), -1);
}

TEST(TreeTest, RemoveTestOne) {
    BMSTU::BinaryTree<int,int> myTree(5,0);
    myTree.Insert(50, 0);
    myTree.Insert(60, 0);
    myTree.Remove(50);
    EXPECT_EQ(myTree.Height(50), -1);
    EXPECT_EQ(myTree.Height(60), 1);
    EXPECT_EQ(myTree.Height(5), 0);
    EXPECT_EQ(myTree.Size(), 2);
}

TEST(TreeTest, RemoveTestTwo) {
    BMSTU::BinaryTree<int,int> myTree(5,0);
    myTree.Remove(5);
    EXPECT_EQ(myTree.Height(5), -1);
    EXPECT_EQ(myTree.Size(), 0);
}



TEST(TreeTest, BalanceTestOne) {
    BMSTU::BinaryTree<int,int> myTree;
    myTree.Insert(3, 0);
    myTree.Insert(2, 0);
    myTree.Insert(1, 0);
    EXPECT_EQ(myTree.Height(2), 1);
    EXPECT_EQ(myTree.Height(3), 0);
    EXPECT_EQ(myTree.Height(1), 0);
}

TEST(TreeTest, BalanceTestTwo) {
    BMSTU::BinaryTree<int,int> myTree;
    myTree.Insert(3,0);
    myTree.Insert(2,0);
    myTree.Insert(6,0);
    myTree.Insert(4,0);
    myTree.Insert(-1,0);
    myTree.Insert(1,0);
    EXPECT_EQ(myTree.Height(3), 2);
    EXPECT_EQ(myTree.Height(1), 1);
    EXPECT_EQ(myTree.Height(6), 1);
    EXPECT_EQ(myTree.Height(-1), 0);
    EXPECT_EQ(myTree.Height(2), 0);
    EXPECT_EQ(myTree.Height(4), 0);
}

TEST(TreeTest, BalanceTestThree) {
    BMSTU::BinaryTree<int,int> myTree;
    for(size_t i = 0; i < 10; i++) {
        myTree.Insert(i, 0);
    }
    EXPECT_EQ(myTree.Height(3), 3);
}

TEST(TreeTest, BalanceTestFour) {
    BMSTU::BinaryTree<int,int> myTree;
    for(size_t i = 0; i < 50; i++) {
        myTree.Insert(i, 0);
    }
    EXPECT_EQ(myTree.Height(0), 0);
}

TEST(TreeTest, DrawTestOne) {
    BMSTU::BinaryTree<int,int> myTree;
    for(size_t i = 0; i < 10; i++)
        myTree.Insert(i, 0);
    myTree.Draw("Tree_One");
    EXPECT_TRUE(1);
}

TEST(TreeTest, DrawTestTwo) {
    BMSTU::BinaryTree<int,int> myTree;
    myTree.Insert(3,0);
    myTree.Insert(2,0);
    myTree.Insert(6,0);
    myTree.Insert(4,0);
    myTree.Insert(-1,0);
    myTree.Insert(1,0);
    myTree.Draw("Tree_Two");
    EXPECT_TRUE(1);
}

TEST(TreeTest, DrawTestThree) {
    BMSTU::BinaryTree<int,int> myTree;
    for(size_t i = 0; i < 10; i+=2)
        myTree.Insert(i, 0);
    for(size_t i = 50; i < 60; i++)
        myTree.Insert(i, 0);
    for(size_t i = 90; i < 100; i+=5)
        myTree.Insert(i, 0);
    myTree.Draw("Three_Three");
    EXPECT_TRUE(1);
}

TEST(TreeTest, DrawTestFour) {
    BMSTU::BinaryTree<int,int> myTree;
    myTree.Insert(-10, 0);
    myTree.Insert(-100, 0);
    myTree.Insert(0, 0);
    myTree.Insert(-15, 0);
    myTree.Insert(5, 0);
    myTree.Insert(10, 0);
    myTree.Insert(-6, 0);
    myTree.Insert(-10, 0);
    myTree.Insert(6, 0);
    myTree.Draw("Tree_Four");
}

TEST(TreeTest, DrawTestFive) {
    BMSTU::BinaryTree<int,int> myTree;
    for(size_t i = 0; i < 200; i++)
        myTree.Insert(i, 0);
    for(size_t i = -1; i > -200; i--)
        myTree.Insert(i, 0);
    myTree.Draw("Tree_Five");
}

TEST(TreeTest, DrawTestSix) {
    BMSTU::BinaryTree<int,int> myTree;
    for(size_t i = 0; i < 500; i++)
        myTree.Insert(i, 0);
    for(size_t i = -1; i > -501; i--)
        myTree.Insert(i, 0);
    myTree.Draw("Tree_Six");
}