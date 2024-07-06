#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trees.h"

NodePtr createNode(Product item) {
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    if (newNode != NULL) {
        newNode->item = item;
        newNode->left = newNode->right = NULL;
    }
    return newNode;
}

NodePtr insert(NodePtr root, Product item) {
    if (root == NULL) {
        return createNode(item);
    }

    if (strcmp(item.prodName, root->item.prodName) < 0) {
        root->left = insert(root->left, item);
    } else if (strcmp(item.prodName, root->item.prodName) > 0) {
        root->right = insert(root->right, item);
    }

    return root;
}

NodePtr minValueNode(NodePtr node) {
    NodePtr current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

NodePtr deleteNode(NodePtr root, char* prodName) {
    if (root == NULL) {
        return root;
    }

    if (strcmp(prodName, root->item.prodName) < 0) {
        root->left = deleteNode(root->left, prodName);
    } else if (strcmp(prodName, root->item.prodName) > 0) {
        root->right = deleteNode(root->right, prodName);
    } else {
        if (root->left == NULL) {
            NodePtr temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NodePtr temp = root->left;
            free(root);
            return temp;
        }

        NodePtr temp = minValueNode(root->right);
        root->item = temp->item;
        root->right = deleteNode(root->right, temp->item.prodName);
    }
    return root;
}

void inorder(NodePtr root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%s ", root->item.prodName);
        inorder(root->right);
    }
}

void preorder(NodePtr root) {
    if (root != NULL) {
        printf("%s ", root->item.prodName);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(NodePtr root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%s ", root->item.prodName);
    }
}

void bfs(NodePtr root) {
    if (root == NULL) {
        return;
    }

    NodePtr queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        NodePtr current = queue[front++];

        printf("%s ", current->item.prodName);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}
