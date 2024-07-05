#ifndef TREES
#define TREES

typedef struct{
	int day;
	int month;
	int year;
}Date;

typedef struct{
	char prodName[20];
	float prodPrice;
	int prodQty;
	Date expDate;	
}Product;

typedef struct node{
	Product item;
	struct node *left, *right;
}NodeType, *NodePtr;

NodePtr createNode(Product item);
NodePtr insert(NodePtr root, Product item);
NodePtr minValueNode(NodePtr node);
NodePtr deleteNode(NodePtr root, char* prodName);
void inorder(NodePtr root);
void preorder(NodePtr root);
void postorder(NodePtr root);
void bfs(NodePtr root);

#endif




