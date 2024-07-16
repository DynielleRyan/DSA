#include <stdio.h>
#include "graph.h"

int main(void) {
    printf("Initial Adjacency Matrix:\n");
    displayInitialAdjacencyMatrix();

    addVertex();
    addVertex();
    addVertex();
    addVertex();
    addVertex();

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(0, 3);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);

    printf("\nAdjacency Matrix after adding edges:\n");
    displayAdjacencyMatrix();

    deleteEdge(1, 3);
    printf("\nAdjacency Matrix after deleting edge B-D:\n");
    displayAdjacencyMatrix();

    deleteVertex(2);
    printf("\nAdjacency Matrix after deleting vertex C:\n");
    displayAdjacencyMatrix();

    return 0;
}

