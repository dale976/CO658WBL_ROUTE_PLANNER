#include <gtest/gtest.h>
#include "stack/Stack.h"  // Replace with the actual header file path

// Define a sample class to use with Stack (e.g., Item)
class Item {
public:
    int value;

    Item(int value) : value(value) {}

    // Example function to display item value
    void Display() const {
        std::cout << value << " ";
    }

    // Overload equality operator for Peek and Pop methods
    bool operator==(const Item& other) const {
        return value == other.value;
    }
};

// Test fixture for Stack
class StackTest : public ::testing::Test {
protected:
    Stack<Item>* stack;

    void SetUp() override {
        // Set up initial conditions for each test case
        stack = new Stack<Item>(5);  // Create a stack with maxSize of 5
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
    EXPECT_EQ(topItem->value, 3);  // Assuming last pushed item is on top
}

// Test case for Pop method
TEST_F(StackTest, Pop) {
    Item* poppedItem = stack->Pop();

    ASSERT_TRUE(poppedItem != nullptr);
    EXPECT_EQ(poppedItem->value, 3);  // Assuming last pushed item is popped first
    EXPECT_EQ(stack->Count(), 2);  // Check stack count after popping
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
        stack->Push(new Item(4));  // Push until stack is full
    }

    EXPECT_TRUE(stack->IsFull());
}

// Test case for Count method
TEST_F(StackTest, Count) {
    EXPECT_EQ(stack->Count(), 3);  // Check initial count after SetUp

    stack->Push(new Item(4));
    EXPECT_EQ(stack->Count(), 4);  // Check count after pushing one more item
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}