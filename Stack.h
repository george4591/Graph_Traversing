//
// Created by gicaCean on 5/18/2021.
//

#ifndef GRAPH_COLEGI_STACK_H
#define GRAPH_COLEGI_STACK_H

#include <stdio.h>

/**
 *  @brief A stack (@b LIFO type)<br>
 *  See <a href="https://en.wikipedia.org/wiki/Stack_(abstract_data_type)">wiki</a> for more help.
 */
struct Stack {
    /**
    *  @brief The array that will hold the values of the stack
    */
    int *stack;
    /**
     *  @brief The index of the last element in the stack
     */
    int last = 0;
    /**
     * @brief The total capacity of the stack(The maximum size it can have)
     */
    int capacity = 0;
    /**
    * @brief Current size of the stack
    */
    int size = 0;
};

/**
 * @brief Function to create a stack
 * @param stack - the stack that will be made
 * @param Size - the size of the stack
 */
void createStack(Stack &stack, int Size) {
    stack.stack = new int[Size];
    stack.capacity = Size;
    stack.size = 0;
    stack.last = 0;
}

/**
 * @brief Function to check if a stack is empty
 * @param stack - the stack that will be checked
 * @return @b true if the stack is empty else @b false
 */
bool isStackEmpty(Stack stack) {
    return stack.size == 0;
}

/**
 *@brief Function to check if a stack is full
 * @param stack - the stack that will be checked
 * @return @b true if the stack is full else @b false
 */
bool isStackFull(Stack stack) {
    return stack.size == stack.capacity;
}

/**
 * @brief Function to put an element into the stack
 * @param stack - the stack in which the value will be inserted
 * @param value - the value which will be inserted
 */
void pushToStack(Stack &stack, int value) {
    // If the stack is not full
    if(!isStackFull(stack)) {
        // Increment the size since we add one element
        stack.size++;
        // Last element index will be ath index size - 1, since we're starting from 0
        stack.last = stack.size - 1;
        // Last value in the array will be the value we insert
        stack.stack[stack.last] = value;
    }
}

/**
 * @brief Function to get the last value in the stack
 * @param stack - the stack that holds the values
 * @return - last element in the stack
 */
int getElementFromStack(Stack stack) {
    return stack.stack[stack.last];
}

/**
 * @brief Function to remove the last value in the stack
 * @param stack - the stack
 */
int popElementFromStack(Stack &stack) {
    if(!isStackEmpty(stack)) {
        stack.last--;
        stack.size--;
    }
}

#endif //GRAPH_COLEGI_STACK_H
