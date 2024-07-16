#ifndef GRAPH_H
#define GRAPH_H

#define MAX_VERTICES 5

extern int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
extern int numVertices;
extern char vertexLabels[MAX_VERTICES];

void addVertex(void);
void addEdge(int from, int to);
void deleteVertex(int vertex);
void deleteEdge(int from, int to);
void displayInitialAdjacencyMatrix(void);
void displayAdjacencyMatrix(void);

#endif // GRAPH_H

