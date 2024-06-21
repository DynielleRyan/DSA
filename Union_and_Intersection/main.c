#include <stdio.h>
#include "unionIntersection.h"

int main() {
    Set set1 = {{1, 2, 3}, 3};
    Set set2 = {{2, 3, 4}, 3};
    
    Set unionSet, intersectionSet;
    
    findUnion(&set1, &set2, &unionSet);
    printf("Union of set1 and set2: ");
    displaySet(&unionSet);
    
    findIntersection(&set1, &set2, &intersectionSet);
    printf("Intersection of set1 and set2: ");
    displaySet(&intersectionSet);
    
    return 0;
}

