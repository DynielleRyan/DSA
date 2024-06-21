#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

#ifndef UNION_INTERSECTION_H
#define UNION_INTERSECTION_H



typedef struct {
    int elements[MAX_SIZE];
    int size;
} Set;


void addValue(Set *set, int value);
void deleteValue(Set *set, int value);
void findUnion(const Set *set1, const Set *set2, Set *result);
void findIntersection(const Set *set1, const Set *set2, Set *result);
void displaySet(const Set *set);

#endif
