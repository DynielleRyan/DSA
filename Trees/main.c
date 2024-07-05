#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trees.h"



// Main function to demonstrate the functionality
int main() {
    NodePtr root = NULL;
    Product p1 = {"Product1", 10.0, 5, {1, 1, 2023}};
    Product p2 = {"Product2", 15.0, 3, {1, 2, 2024}};
    Product p3 = {"Product3", 7.0, 10, {1, 3, 2025}};
    
    root = insert(root, p1);
    root = insert(root, p2);
    root = insert(root, p3);

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("BFS Traversal: ");
    bfs(root);
    printf("\n");

    root = deleteNode(root, "Product2");
    printf("Inorder Traversal after deletion: ");
    inorder(root);
    printf("\n");

    return 0;
}
