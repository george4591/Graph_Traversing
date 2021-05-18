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
     * It is just the number of edges it has
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
    * @brief Adds a vertex to the graph
    * @param v - first edge of the vertex
    * @param u - second edge of the vertex
*/
void addVertex(Graph &graph, int v, int u) {
    // if the the edge numbers are less than the size of the graph
    // then that means that is a correct vertex and we can add it to the adjacency matrix
    if (v < graph.size && u < graph.size) {
        graph.adjMatrix[v][u] = 1;
        graph.adjMatrix[u][v] = 1;
    }
    else {
        printf("\nCannot add a vertex that has edges with a number bigger than the number of edges the graph has.");
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
        int edge = getElementFromQueue(q);
        printf("%d ", edge);

        // For every edge that the graph has
        for (int currentEdge = q.first; currentEdge < graph.size; currentEdge++) {
            // We're checking if there is a vertex between the edge got from the queue and the current edge
            // And if there is a vertex then we're checking if the current edge has already been visited
            if (graph.adjMatrix[edge][currentEdge] && !visited[currentEdge]) {
                // If the condition is true then we're pushing the currentEdge in the queue
                // and we mark it as visited
                pushToQueue(q, currentEdge);
                visited[currentEdge] = true;
            }
        }
        // After we finish checking all the other edges with the edge got from the queue
        // then we're gonna pop(remove) that edge from the queue and we're gonna continue
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
        // We're getting the edge from the stack and printing it
        int edge = getElementFromStack(st);
        printf("%d ", edge);
        // Then since we've printed it, we no longer need it in the stack so we're removing it
        popElementFromStack(st);
        for (int currentEdge = 0; currentEdge < graph.size; currentEdge++) {
            // We're checking if there is a vertex between the edge got from the queue and the current edge
            // And if there is a vertex then we're checking if the current edge has already been visited
            if (graph.adjMatrix[edge][currentEdge] && !visited[currentEdge]) {
                // If the condition is true then we're pushing the currentEdge in the queue
                // and we mark it as visited
                pushToStack(st, currentEdge);
                visited[currentEdge] = true;
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
