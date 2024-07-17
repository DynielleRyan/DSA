#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INITIAL_TABLE_SIZE 100
#define MAX_PROBES 20
#define LOAD_THRESHOLD 0.65

typedef struct HashTable {
    char color[INITIAL_TABLE_SIZE][20];
    bool occupied[INITIAL_TABLE_SIZE];
    int size;
} HashTable;

int hash(char *color, int table_size) {
    unsigned long hash = 5381;
    int c;

    while ((c = *color++))
        hash = ((hash << 5) + hash) + c;

    return hash % table_size;
}

void initHashTable(HashTable *ht) {
    ht->size = INITIAL_TABLE_SIZE;
    for (int i = 0; i < ht->size; i++) {
        ht->occupied[i] = false;
    }
}

void resizeHashTable(HashTable *ht) {
    int new_size = ht->size * 2;
    char temp[new_size][20];
    bool temp_occupied[new_size];

    for (int i = 0; i < new_size; i++) {
        temp_occupied[i] = false;
    }

    for (int i = 0; i < ht->size; i++) {
        if (ht->occupied[i]) {
            int index = hash(ht->color[i], new_size);
            int probes = 0;
            while (temp_occupied[index]) {
                index = (index + 1) % new_size;
                probes++;
                if (probes >= new_size) {
                    fprintf(stderr, "Error: Hash table is full after resizing.\n");
                    exit(EXIT_FAILURE);
                }
            }
            strcpy(temp[index], ht->color[i]);
            temp_occupied[index] = true;
        }
    }

    ht->size = new_size;
    for (int i = 0; i < ht->size; i++) {
        ht->occupied[i] = temp_occupied[i];
        if (ht->occupied[i]) {
            strcpy(ht->color[i], temp[i]);
        }
    }

    printf("Hash table resized. New size: %d\n", ht->size);
}

void insertClosedLinear(HashTable *ht, char *color) {
    if ((double)ht->size * LOAD_THRESHOLD <= ht->size) {
        resizeHashTable(ht);
    }

    int index = hash(color, ht->size);
    int probes = 0;
    
    while (ht->occupied[index] && probes < MAX_PROBES) {
        index = (index + 1) % ht->size;
        probes++;
    }
    
    if (probes < MAX_PROBES) {
        strcpy(ht->color[index], color);
        ht->occupied[index] = true;
        printf("Inserted '%s' at index %d.\n", color, index);
    } else {
        printf("Could not insert '%s'. Hash table is full.\n", color);
    }
}

bool searchClosedLinear(HashTable *ht, char *color) {
    int index = hash(color, ht->size);
    int probes = 0;
    
    while (ht->occupied[index] && probes < MAX_PROBES) {
        if (strcmp(ht->color[index], color) == 0) {
            return true;
        }
        index = (index + 1) % ht->size;
        probes++;
    }
    return false;
}

void displayHashTableClosed(HashTable *ht) {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < ht->size; i++) {
        if (ht->occupied[i]) {
            printf("%d: %s\n", i, ht->color[i]);
        } else {
            printf("%d: NULL\n", i);
        }
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
        insertClosedLinear(&ht, color);

        printf("Do you want to enter another color? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    displayHashTableClosed(&ht);

    printf("\nEnter a color to search: ");
    scanf("%s", color);

    if (searchClosedLinear(&ht, color)) {
        printf("Color '%s' found in hash table.\n", color);
    } else {
        printf("Color '%s' not found in hash table.\n", color);
    }

    return 0;
}

