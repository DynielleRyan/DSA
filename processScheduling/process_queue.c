#include <stdio.h>
#include <stdlib.h>
#include "process_queue.h"

void add_to_queue(Queue* queue, Process process) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->process = process;
    new_node->next = NULL;
    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }
}

Process remove_from_queue(Queue* queue) {
    if (queue->front == NULL) {
        fprintf(stderr, "Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    Node* temp = queue->front;
    Process process = temp->process;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return process;
}

int is_queue_empty(Queue* queue) {
    return (queue->front == NULL);
}

float avg_wait_time(Process* processes, int count) {
    float total_wait_time = 0;
    int i;
    for (i = 0; i < count; ++i) {
        total_wait_time += processes[i].wait;
    }
    return total_wait_time / count;
}

void show_process_table(Process* processes, int count) {
    printf("\nProcess Table:\n");
    printf("-----------------------------------------------------------------\n");
    printf("| Process ID | Arrival Time | Burst Time | Waiting Time | Turnaround Time |\n");
    int i;
    for (i = 0; i < count; ++i) {
        printf("| %10c | %12d | %10d | %12d | %15d |\n",
               processes[i].id, processes[i].arrival, processes[i].burst,
               processes[i].wait, processes[i].turnaround);
    }
    int total_waiting = 0;
    int total_turnaround = 0;
    for (i = 0; i < count; ++i) {
        total_waiting += processes[i].wait;
        total_turnaround += processes[i].turnaround;
    }
    printf("| Total      |..............-............- %12d | %15d |\n", total_waiting, total_turnaround);
    printf("-----------------------------------------------------------------\n");
}

