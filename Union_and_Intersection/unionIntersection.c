#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

#include "unionIntersection.h" 
	
//create a program to find the union and intersection
// 2 functions that accept 2 sets and find union and intersection
//functions to add or delete value in the set 
//keep the integrity of the 2 inital sets when finding union and intersection
//keep the integrity of the 2 inital sets when finding union and intersection
// display resulting unions and intersections


////////Array implementation


void addValue(Set *set, int value) {
    for (int i = 0; i < set->size; ++i) {
        if (set->elements[i] == value) {
            return;
        }
    }
    
    set->elements[set->size] = value;
    set->size++;
}

void deleteValue(Set *set, int value) {
    for (int i = 0; i < set->size; ++i) {
        if (set->elements[i] == value) {
            for (int j = i; j < set->size - 1; ++j) {
                set->elements[j] = set->elements[j + 1];
            }
            set->size--;
            return;
        }
    }
}

void findUnion(const Set *set1, const Set *set2, Set *result) {
    *result = *set1;
    
    for (int i = 0; i < set2->size; ++i) {
        addValue(result, set2->elements[i]);
    }
}

void findIntersection(const Set *set1, const Set *set2, Set *result) {
    result->size = 0;
    
    for (int i = 0; i < set1->size; ++i) {
        int currentElement = set1->elements[i];
        for (int j = 0; j < set2->size; ++j) {
            if (set2->elements[j] == currentElement) {
                addValue(result, currentElement);
                break;
            }
        }
    }
}

void displaySet(const Set *set) {
    printf("{ ");
    for (int i = 0; i < set->size; ++i) {
        printf("%d ", set->elements[i]);
    }
    printf("}\n");
}

