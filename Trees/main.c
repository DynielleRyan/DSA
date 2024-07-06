#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trees.h"

int main() {
    NodePtr root = NULL;
    int choice;
    char name[20];
    float price;
    int qty;
    int day, month, year;

    do {
        printf("1. Insert Product\n");
        printf("2. Delete Product\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. BFS Traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter product price: ");
                scanf("%f", &price);
                printf("Enter product quantity: ");
                scanf("%d", &qty);
                printf("Enter expiry date (dd mm yyyy): ");
                scanf("%d %d %d", &day, &month, &year);
                Product p = {0};
                strncpy(p.prodName, name, sizeof(p.prodName) - 1);
                p.prodPrice = price;
                p.prodQty = qty;
                p.expDate.day = day;
                p.expDate.month = month;
                p.expDate.year = year;
                root = insert(root, p);
                break;
            case 2:
                printf("Enter product name to delete: ");
                scanf("%s", name);
                root = deleteNode(root, name);
                break;
            case 3:
                inorder(root);
                printf("\n");
                break;
            case 4:
                preorder(root);
                printf("\n");
                break;
            case 5:
                postorder(root);
                printf("\n");
                break;
            case 6:
                bfs(root);
                printf("\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
