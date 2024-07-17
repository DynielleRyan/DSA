#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 100

typedef struct Node {
    char color[20];
    struct Node *next;
} Node;

typedef struct HashTable {
    Node *table[TABLE_SIZE];
} HashTable;

int hash(char *color) {
    unsigned long hash = 5381;
    int c;

    while ((c = *color++))
        hash = ((hash << 5) + hash) + c;

    return hash % TABLE_SIZE;
}

void initHashTable(HashTable *ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

void insertOpen(HashTable *ht, char *color) {
    int index = hash(color);
    
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    strcpy(newNode->color, color);
    newNode->next = NULL;

    if (ht->table[index] == NULL) {
        ht->table[index] = newNode;
    } else {
        newNode->next = ht->table[index];
        ht->table[index] = newNode;
    }
}

bool searchOpen(HashTable *ht, char *color) {
    int index = hash(color);
    Node *current = ht->table[index];
    
    while (current != NULL) {
        if (strcmp(current->color, color) == 0) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void displayHashTable(HashTable *ht) {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node *current = ht->table[i];
        printf("%d: ", i);
        while (current != NULL) {
            printf("%s -> ", current->color);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    HashTable ht;
    initHashTable(&ht);

    char color[20];
    char choice;

    do {
        printf("Enter a color to insert into hash table: ");
        scanf("%s", color);
        insertOpen(&ht, color);

        printf("Do you want to enter another color? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    displayHashTable(&ht);

    printf("\nEnter a color to search: ");
    scanf("%s", color);

    if (searchOpen(&ht, color)) {
        printf("Color '%s' found in hash table.\n", color);
    } else {
        printf("Color '%s' not found in hash table.\n", color);
    }

    return 0;
}

