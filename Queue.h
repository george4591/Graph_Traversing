//
// Created by gicaCean on 5/18/2021.
//

#ifndef GRAPH_COLEGI_QUEUE_H
#define GRAPH_COLEGI_QUEUE_H

#include <stdio.h>

/**
 *  @brief A queue (@b FIFO type)<br>
 *  See <a href="https://en.wikipedia.org/wiki/Queue_(abstract_data_type)">wiki</a> for more help.
 */
struct Queue {
    /**
     *  @brief The array that will hold the values of the queue
     */
    int *q;
    /**
     *  @brief The index of the first element in the queue
     */
    int first = 0;
    /**
     *  @brief The index of the last element in the queue
     */
    int last = 0;
    /**
     * @brief The total capacity of the queue(The maximum size it can have)
     */
    int capacity = 0;
    /**
     * @brief Current size of the queue
     */
    int size = 0;
    };

/**
 * @brief Function to create a queue
 * @param queue - the queue that will be made
 * @param Size - the size of the queue
 */
void createQueue(Queue &queue, int Size) {
    // Allocate memory for the queue
    queue.q = new int[Size];
    // Capacity will be the size we put
    queue.capacity = Size;
    // First and last element will be at position 0 at first
    queue.first = 0;
    queue.last = 0;
}

/**
 * @brief Function to check if a queue is empty
 * @param queue - the queue that will be checked
 * @return @b true if the queue is empty else @b false
 */
bool isQueueEmpty(Queue queue) {
    return queue.first == queue.size;
}
/**
 *@brief Function to check if a queue is full
 * @param queue - the queue that will be checked
 * @return @b true if the queue is full else @b false
 */
bool isQueueFull(Queue queue) {
    return queue.size == queue.capacity;
}

/**
 * @brief Function to put an element into the queue
 * @param queue - the queue in which the value will be inserted
 * @param value - the value which will be inserted
 */
void pushToQueue(Queue &queue, int value) {
    // If the queue is not full
    if(!isQueueFull(queue)) {
        // Increment the size
        queue.size++;
        // Last element index will be ath index size - 1, since we're starting from 0
        queue.last = queue.size - 1;
        // Last value in the array will be the value we insert
        queue.q[queue.last] = value;
    }
}

/**
 * @brief Function to get the first value in the queue
 * @param queue - the queue that holds the values
 * @return - first element in the queue
 */
int getElementFromQueue(Queue queue) {
    return queue.q[queue.first];
}

/**
 * @brief Function to remove the first value in the queue
 * @param queue - the queue
 */
int popElementFromQueue(Queue &queue) {
    if(!isQueueEmpty(queue)) {
        // We don't actually remove the value, we just increment the index of the so-called 'first' value;
        queue.first++;
    }
}


#endif //GRAPH_COLEGI_QUEUE_H
