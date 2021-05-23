#include <stdio.h>
#include "Graph.h"

int main() {
    Graph g;
    createGraph(g, 6);

    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 3);
    addEdge(g, 3, 2);
    addEdge(g, 3, 5);
    addEdge(g, 2, 5);
    addEdge(g, 1, 4);

    printAdjMatrix(g);
    printf("\n------------Breadth First Traversal------------\n");
    bfs(g, 0);

    printf("\n------------Depth First Traversal------------\n");
    dfs(g, 0);

    return 0;
}
