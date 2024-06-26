#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>

#define MAX 20

typedef struct{
    char processID;
    int ArrivalTime;
    int BurstTime;
    int CompletionTime;
    int WaitingTime;
    int TurnAroundTime;
} Process;

typedef struct{
    Process array[MAX];
    int front;
    int rear;
} Queue;

void initQ(Queue *Q);
void enQ(Queue *Q, Process pData);
void displayQ(Process solveVal[], int NProcess);
void solveWtTt(Queue *Q, Process solveVal[], int NProcess);
void ganttChart(Process solveVal[], int NProcess);

#endif

