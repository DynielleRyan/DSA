#include "queue.h"
#include <stdlib.h>
#include <conio.h>

int main(){
    Queue Q;
    Process processData;
    int x, n;

    initQ(&Q);

    printf("\nEnter no. of Processes: ");
    scanf("%d", &n);
    fflush(stdin);

    if(n != 0){
        for(x = 0; x < n; x++){
            printf("\nEnter Process [%d] ID: ", x + 1);
            scanf("%c", &processData.processID);
            printf("Enter Arrival Time: ");
            scanf("%d", &processData.ArrivalTime);
            printf("Enter Burst Time: ");
            scanf("%d", &processData.BurstTime);

            enQ(&Q, processData);
            fflush(stdin);
        }
    } else {
        printf("\n\nProcess: [%d]. terminated!\n\n", n);
        exit(1);
    }

    Process solveVal[n];

    solveWtTt(&Q, solveVal, n);
    displayQ(solveVal, n);
    ganttChart(solveVal, n);

    return 0;
}

