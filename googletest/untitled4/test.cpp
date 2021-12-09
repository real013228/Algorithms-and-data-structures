#include <gtest/gtest.h>
#include "test.h"

class NodeFixture : public ::testing::Test {
public:
    ~NodeFixture() override { delete l0; }

protected:
    void SetUp() override {
        l0 = new Node();
        list1 = new List();
        node1 = new Node();
    }
    Node *l0, *node1;
    List *list1;
};

TEST_F(NodeFixture, IsNextEmpty){
    EXPECT_EQ(nullptr, l0->next);
    EXPECT_EQ(l0->next, l0->prev);
}

TEST_F(NodeFixture, IsPrevEmpty){
    EXPECT_EQ(nullptr, l0->prev);
    EXPECT_EQ(l0->next, l0->prev);
}

TEST_F(NodeFixture, IsBothEmpty){
    EXPECT_EQ(nullptr, l0->next);
    EXPECT_EQ(nullptr, l0->prev);
    EXPECT_EQ(l0->next, l0->prev);
}

TEST_F(NodeFixture, IsFuncAddCorrect){
    node1 = list1->add("M3101", "KirillSavvinov", nullptr);
    int hashNum = hashIt("M3101");
    EXPECT_EQ(node1->value, "KirillSavvinov");
}