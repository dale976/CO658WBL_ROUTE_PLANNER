#include <gtest/gtest.h>
#include "stack/Stack.h"


class Item {
public:
    int value;

    Item(int value) : value(value) {}

    // Example function to display item value
    void Display() const {
        std::cout << value << " ";
    }

    // Overload equality operator for Peek and Pop methods
    bool operator==(const Item& rhd) const {
        return value == rhd.value;
    }
};

// Test Stack
class StackTest : public ::testing::Test {
protected:
    Stack<Item>* stack;

    void SetUp() override {

        stack = new Stack<Item>(10);  // Create a stack with maxSize of 10
        stack->Push(new Item(1));
        stack->Push(new Item(2));
        stack->Push(new Item(3));
    }

    void TearDown() override {
        // Clean up after each test case
        while (!stack->IsEmpty()) {
            delete stack->Pop();
        }
        delete stack;
    }
};

// Test case for Push and Peek methods
TEST_F(StackTest, PushAndPeek) {
    Item* topItem = stack->Peek();

    ASSERT_TRUE(topItem != nullptr);
    EXPECT_EQ(topItem->value, 3);
}

// Test case for Pop method
TEST_F(StackTest, Pop) {
    Item* poppedItem = stack->Pop();

    ASSERT_TRUE(poppedItem != nullptr);
    EXPECT_EQ(poppedItem->value, 3);
    EXPECT_EQ(stack->Count(), 2);
}

// Test case for IsEmpty method
TEST_F(StackTest, IsEmpty) {
    while (!stack->IsEmpty()) {
        delete stack->Pop();
    }

    EXPECT_TRUE(stack->IsEmpty());
}

// Test case for IsFull method
TEST_F(StackTest, IsFull) {
    while (!stack->IsFull()) {
        stack->Push(new Item(4));
    }

    EXPECT_TRUE(stack->IsFull());
}

// Test case for Count method
TEST_F(StackTest, Count) {
    EXPECT_EQ(stack->Count(), 3);

    stack->Push(new Item(4));
    EXPECT_EQ(stack->Count(), 4);
}

// Stress Test
TEST_F(StackTest, stress100) {
    stack = new Stack<Item>(100);
    for (int i = 0; i < 100; i++) {
        stack->Push(new Item(i));
    }
    EXPECT_EQ(stack->Count(), 100);
}

TEST_F(StackTest, stressIsFull) {
    stack = new Stack<Item>(100);
    for (int i = 0; i < 100; i++) {
        stack->Push(new Item(i));
    }
    EXPECT_TRUE(stack->IsFull());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}