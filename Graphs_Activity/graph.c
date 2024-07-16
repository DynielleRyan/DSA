#include "graph.h"
#include <stdio.h>
#include <stdbool.h>

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {[0 ... MAX_VERTICES-1][0 ... MAX_VERTICES-1] = 0};
int numVertices = 0;
char vertexLabels[MAX_VERTICES] = {'A', 'B', 'C', 'D', 'E'};

void addVertex(void) {
    if (numVertices < MAX_VERTICES) {
        numVertices++;
    } else {
        printf("Maximum number of vertices reached (%d)\n", MAX_VERTICES);
    }
}

void addEdge(int from, int to) {
    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices && from != to) {
        adjacencyMatrix[from][to] = 1;
        adjacencyMatrix[to][from] = 1;
    } else {
        printf("Invalid vertices or trying to add self-loop\n");
    }
}

void deleteVertex(int vertex) {
	int i;
    if (vertex >= 0 && vertex < numVertices) {
        for(i = 0; i < MAX_VERTICES; i++) {
            adjacencyMatrix[vertex][i] = 0;
            adjacencyMatrix[i][vertex] = 0;
        }
    } else {
        printf("Invalid vertex\n");
    }
}

void deleteEdge(int from, int to) {
    if (from >= 0 && from < numVertices && to >= 0 && to < numVertices) {
        adjacencyMatrix[from][to] = 0;
        adjacencyMatrix[to][from] = 0;
    } else {
        printf("Invalid vertices\n");
    }
}

void displayInitialAdjacencyMatrix(void) {
    int i, j;
    printf("  ");
    for (i = 0; i < MAX_VERTICES; i++) {
        printf("%c ", vertexLabels[i]);
    }
    printf("\n");
    for (i = 0; i < MAX_VERTICES; i++) {
        printf("%c ", vertexLabels[i]);
        for (j = 0; j < MAX_VERTICES; j++) {
            if (i == j) {
                printf("  ");
            } else {
                printf("%d ", adjacencyMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

void displayAdjacencyMatrix(void) {
    int i, j;
    printf("  ");
    for (i = 0; i < numVertices; i++) {
        printf("%c ", vertexLabels[i]);
    }
    printf("\n");
    for (i = 0; i < numVertices; i++) {
        printf("%c ", vertexLabels[i]);
        for (j = 0; j < numVertices; j++) {
            if (i == j) {
                printf("  ");
            } else {
                printf("%d ", adjacencyMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

