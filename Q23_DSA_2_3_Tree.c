
// Implementation of the AVL tree will be done as: 

#include <stdio.h>
#include <stdlib.h>

#define MAX 3

typedef struct Node {
    int n;                // number of keys
    int keys[MAX];        // keys
    struct Node *child[MAX+1]; // children
} Node;

Node *root = NULL;

// Create new node
Node* createNode(int key, Node *child) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->n = 1;
    newNode->keys[0] = key;
    newNode->child[0] = root;
    newNode->child[1] = child;
    return newNode;
}

// Insert into node
int insertNode(int key, int *upKey, Node *node, Node **newNode) {
    int pos;

    if (node == NULL) {
        *upKey = key;
        *newNode = NULL;
        return 1;
    }

    if (key < node->keys[0])
        pos = 0;
    else if (node->n == 1 || key < node->keys[1])
        pos = 1;
    else
        pos = 2;

    int flag = insertNode(key, upKey, node->child[pos], newNode);

    if (!flag) return 0;

    // If node has space
    if (node->n < 2) {
        for (int i = node->n; i > pos; i--) {
            node->keys[i] = node->keys[i-1];
            node->child[i+1] = node->child[i];
        }

        node->keys[pos] = *upKey;
        node->child[pos+1] = *newNode;
        node->n++;
        return 0;
    }

    // Split node
    int tempKeys[3];
    Node *tempChild[4];

    for (int i = 0; i < 2; i++) tempKeys[i] = node->keys[i];
    for (int i = 0; i < 3; i++) tempChild[i] = node->child[i];

    for (int i = 2; i > pos; i--) {
        tempKeys[i] = tempKeys[i-1];
        tempChild[i+1] = tempChild[i];
    }

    tempKeys[pos] = *upKey;
    tempChild[pos+1] = *newNode;

    int mid = 1;
    *upKey = tempKeys[mid];

    *newNode = (Node*)malloc(sizeof(Node));
    node->n = 1;
    (*newNode)->n = 1;

    node->keys[0] = tempKeys[0];
    node->child[0] = tempChild[0];
    node->child[1] = tempChild[1];

    (*newNode)->keys[0] = tempKeys[2];
    (*newNode)->child[0] = tempChild[2];
    (*newNode)->child[1] = tempChild[3];

    return 1;
}

// Insert function
void insert(int key) {
    int upKey;
    Node *newNode;

    int flag = insertNode(key, &upKey, root, &newNode);

    if (flag)
        root = createNode(upKey, newNode);
}

// Inorder traversal
void inorder(Node *node) {
    if (node) {
        if (node->n == 1) {
            inorder(node->child[0]);
            printf("%d ", node->keys[0]);
            inorder(node->child[1]);
        } else {
            inorder(node->child[0]);
            printf("%d ", node->keys[0]);
            inorder(node->child[1]);
            printf("%d ", node->keys[1]);
            inorder(node->child[2]);
        }
    }
}

int main() {
    int arr[] = {10, 20, 5, 6, 12, 30, 7, 17};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        insert(arr[i]);

    printf("Inorder Traversal:\n");
    inorder(root);

    return 0;
}