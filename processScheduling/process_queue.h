#ifndef PROCESS_QUEUE_H
#define PROCESS_QUEUE_H

typedef struct {
    char id;
    int arrival;
    int burst;
    int wait;
    int turnaround;
} Process;

typedef struct Node {
    Process process;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Queue;

void add_to_queue(Queue* queue, Process process);
Process remove_from_queue(Queue* queue);
int is_queue_empty(Queue* queue);
float avg_wait_time(Process* processes, int count);
void show_process_table(Process* processes, int count);

#endif

