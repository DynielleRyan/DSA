#include "queue.h"

void initQ(Queue *Q){
    Q->front = 1;
    Q->rear = 0;
}

void enQ(Queue *Q, Process pData){
    if(Q->front == -1){
        Q->front = 0;
    }
    Q->array[++Q->rear] = pData;
}

void displayQ(Process solveVal[], int NProcess){
    int x;
    printf("\nTable: \n");
    printf("\nProcess\tBT\tAT\tCT\tWT\tTT\n");
    for(x = 0; x < NProcess; x++){
        printf("%c\t%d\t%d\t%d\t%d\t%d\n", solveVal[x].processID, solveVal[x].BurstTime, solveVal[x].ArrivalTime, solveVal[x].CompletionTime, solveVal[x].WaitingTime, solveVal[x].TurnAroundTime);
    }
}

void solveWtTt(Queue *Q, Process solveVal[], int NProcess){
    Process temp;
    int CT[NProcess], ST[NProcess], WT[NProcess], TT[NProcess];
    int x, y, currTime = 0;

    for(x = 0; x < NProcess; x++){
        solveVal[x] = Q->array[Q->front + x];
    }
    
    for(x = 0; x < NProcess - 1; x++){
        for(y = 0; y < NProcess - x - 1; y++){
            if(solveVal[y].ArrivalTime > solveVal[y + 1].ArrivalTime){
                temp = solveVal[y];
                solveVal[y] = solveVal[y + 1];
                solveVal[y + 1] = temp;
            }
        }
    }

    for(x = 0; x < NProcess; x++){
        if(currTime < solveVal[x].ArrivalTime){
            currTime = solveVal[x].ArrivalTime;
        }

        ST[x] = currTime;
        CT[x] = currTime + solveVal[x].BurstTime;
        WT[x] = ST[x] - solveVal[x].ArrivalTime;
        TT[x] = CT[x] - solveVal[x].ArrivalTime;
        currTime = CT[x];
    }

    for(x = 0; x < NProcess; x++){
        solveVal[x].CompletionTime = CT[x];
        solveVal[x].WaitingTime = WT[x];
        solveVal[x].TurnAroundTime = TT[x];
    }
}

void ganttChart(Process solveVal[], int NProcess){
    Process temp;
    int CT[NProcess], ST[NProcess];
    int x, y, currTime = 0;

    for(x = 0; x < NProcess - 1; x++){
        for(y = 0; y < NProcess - x - 1; y++){
            if(solveVal[y].ArrivalTime > solveVal[y + 1].ArrivalTime){
                temp = solveVal[y];
                solveVal[y] = solveVal[y + 1];
                solveVal[y + 1] = temp;
            }
        }
    }

    for(x = 0; x < NProcess; x++){
        if(currTime < solveVal[x].ArrivalTime){
            currTime = solveVal[x].ArrivalTime;
        }
        ST[x] = currTime;
        CT[x] = currTime + solveVal[x].BurstTime;
        currTime = CT[x];
    }

    printf("\nGantt Chart:\n");
    printf(" ");
    for(x = 0; x < NProcess; x++){
        for(y = 0; y < solveVal[x].BurstTime - 1; y++){
            printf(" ");
        }
        printf("%c", solveVal[x].processID);

        for(y = 0; y < solveVal[x].BurstTime - 1; y++){
            printf(" ");
        }
        printf("|");
    }

    printf("\n");

    for(x = 0; x < NProcess; x++){
        for(y = 0; y < solveVal[x].BurstTime; y++){
            printf(" ");
        }
    }

    printf("\n%d", ST[0]);
    for(x = 0; x < NProcess; x++){
        printf("%*d", solveVal[x].BurstTime * 2, CT[x]);
    }
    printf("\n");
}

