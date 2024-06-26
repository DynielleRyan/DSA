#include <stdio.h>
#include "process_queue.h"

int main() {
    int num_processes;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    Process processes[num_processes];
    int i;

    for (i = 0; i < num_processes; ++i) {
        processes[i].id = 'A' + i;
        printf("Enter arrival time for process %c: ", processes[i].id);
        scanf("%d", &processes[i].arrival);
        printf("Enter burst time for process %c: ", processes[i].id);
        scanf("%d", &processes[i].burst);
        processes[i].wait = 0;
        processes[i].turnaround = 0;
    }

    Queue queue = {.front = NULL, .rear = NULL};
    int current_time = 0;

    for (i = 0; i < num_processes; ++i) {
        while (current_time < processes[i].arrival) {
            current_time++;
        }
        add_to_queue(&queue, processes[i]);
        current_time += processes[i].burst;
        Process completed_process = remove_from_queue(&queue);
        completed_process.wait = current_time - completed_process.arrival - completed_process.burst;
        completed_process.turnaround = current_time - completed_process.arrival;
        processes[i] = completed_process;
    }

    show_process_table(processes, num_processes);
    float average_waiting_time = avg_wait_time(processes, num_processes);
    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);

    return 0;
}


