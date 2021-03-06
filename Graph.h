//
// Created by gicaCean on 5/18/2021.
//

#ifndef GRAPH_COLEGI_GRAPH_H
#define GRAPH_COLEGI_GRAPH_H

#include <stdio.h>
#include "Queue.h"
#include "Stack.h"

/**
 *  @brief A graph
 */
struct Graph {
    /**
     * @brief The adjacency matrix for the graph.<br>
     * See <a href="https://en.wikipedia.org/wiki/Adjacency_matrix">wiki</a> for more help
     */
    int **adjMatrix;
    /**
     * @brief This is the size of the graph
     * It is just the number of vertices it has
     */
    int size;
};

/**
     * @brief Graph constructor which takes the number of vertices
     * and allocates the memory for the adjacency matrix and the size
     * of the graph
     * @param graph - the graph that will be constructed
     * @param num_vertices - number of vertices that the graph will have
*/
void createGraph(Graph &graph, int num_vertices) {
    graph.adjMatrix = new int *[num_vertices];  // allocate the matrix
    for (int it = 0; it < num_vertices; it++) {
        graph.adjMatrix[it] = new int[num_vertices]{0};
    }
    graph.size = num_vertices; // the size of the graph is the number of vertices passed in
}

/**
    * @brief Adds an edge to the graph
    * @param v - first edge of the vertex
    * @param u - second edge of the vertex
*/
void addEdge(Graph &graph, int v, int u) {
    // if the the vertex numbers are less than the size of the graph
    // then that means that is a correct vertex and we can add it to the adjacency matrix
    if (v < graph.size && u < graph.size) {
        graph.adjMatrix[v][u] = 1;
        graph.adjMatrix[u][v] = 1;
    }
    else {
        printf("\nCannot add an edge that has vertices with a number bigger than the number of vertices the graph has.");
    }
}

/**
     * @brief Performs the breadth first search algorithm
     * @param start - starting node
*/
void bfs(Graph &graph, int start) {
    // We're creating a queue here, check Queue.h for implementation
    Queue q;
    createQueue(q, graph.size);
    // We're making an array of bools(type that can hold only true or false)
    // to check if a specific node has been visited
    bool visited[graph.size];
    // We're pushing the starting node in the queue and marking it as visited
    pushToQueue(q, start);
    visited[start] = true;

    // While the queue is not empty
    while (!isQueueEmpty(q)) {
        // We're getting the edge from the queue and printing it
        int vertex = getElementFromQueue(q);
        printf("%d ", vertex);

        // For every vertex that the graph has
        for (int currentVertex = q.first; currentVertex < graph.size; currentVertex++) {
            // We're checking if there is an edge between the vertex got from the queue and the current vertex
            // And if there is a vertex then we're checking if the current vertex has already been visited
            if (graph.adjMatrix[vertex][currentVertex] && !visited[currentVertex]) {
                // If the condition is true then we're pushing the currentVertex in the queue
                // and we mark it as visited
                pushToQueue(q, currentVertex);
                visited[currentVertex] = true;
            }
        }
        // After we finish checking all the other vertices with the vertex got from the queue
        // then we're gonna pop(remove) that vertex from the queue and we're gonna continue
        // with the next one in the queue(if there is one)
        popElementFromQueue(q);
    }
}
/**
    * @brief Performs the depth first search algorithm
    * @param start - starting node
*/
void dfs(Graph &graph, int start) {
    // We're creating a stack here, check Stack.h for implementation
    Stack st;
    createStack(st, graph.size);
    // We're making an array of bools(type that can hold only true or false)
    // to check if a specific node has been visited
    bool visited[graph.size];
    // We're pushing the starting node in the stack and marking it as visited
    pushToStack(st, start);
    visited[start] = true;

    // While the stack is not empty
    while (!isStackEmpty(st)) {
        // We're getting the vertex from the stack and printing it
        int vertex = getElementFromStack(st);
        printf("%d ", vertex);
        // Then since we've printed it, we no longer need it in the stack so we're removing it
        popElementFromStack(st);
        for (int currentVertex = 0; currentVertex < graph.size; currentVertex++) {
            // We're checking if there is an edge between the vertex got from the queue and the current vertex
            // And if there is a vertex then we're checking if the current vertex has already been visited
            if (graph.adjMatrix[vertex][currentVertex] && !visited[currentVertex]) {
                // If the condition is true then we're pushing the currentVertex in the queue
                // and we mark it as visited
                pushToStack(st, currentVertex);
                visited[currentVertex] = true;
            }
        }
    }
}

/**
     * @brief Prints the adjacency matrix to the screen
     */
void printAdjMatrix(Graph &graph) {
    for (int row = 0; row < graph.size; row++) {
        for (int col = 0; col < graph.size; col++)
            printf("%d ", graph.adjMatrix[row][col]);
        printf("\n");
    }
}


#endif //GRAPH_COLEGI_GRAPH_H
