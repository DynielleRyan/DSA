#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


void insertAtBeginning(Node** head_ref, int new_data);
void insertAtEnd(Node** head_ref, int new_data);
void printList(Node* node);

int main() {
    
    Node* head = NULL;

    
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);

    printf("Linked list before insertion at end:\n");
    printList(head);

  
    insertAtEnd(&head, 30);

    printf("\nLinked list after insertion at end:\n");
    printList(head);

    return 0;
}


void insertAtBeginning(Node** head_ref, int new_data) {
   
    Node* new_node = (Node*)malloc(sizeof(Node));

  
    new_node->data = new_data;

   
    new_node->next = (*head_ref);

   
    (*head_ref) = new_node;
}


void insertAtEnd(Node** head_ref, int new_data) {
    
    Node* new_node = (Node*)malloc(sizeof(Node));

  
    new_node->data = new_data;
    new_node->next = NULL;

   
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

  
    last->next = new_node;
}


void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

