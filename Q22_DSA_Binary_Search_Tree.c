
// Write a program to implement the binary search tree using the array 

# include <stdio.h> 
#define SIZE 100 

int tree[SIZE]; 

// In itial Tree 
void init() { 
    for (int i = 0; i < SIZE; i++) 
        tree[i] = -1; 
} 

// Insert Element  
void insert(int value, int index) {
    if (index >= SIZE) {
        printf("Tree Overflow\n"); 
        return; 
    }


    if (tree[index] == -1) {
        tree[index] = value;
        return;
    }

    if (value < tree[index])
        insert(value, 2 * index + 1);
    else
        insert(value, 2 * index + 2);
} 

// Inorder traversal
void inorder(int index) {
    if (index >= SIZE || tree[index] == -1)
        return;

    inorder(2 * index + 1);
    printf("%d ", tree[index]);
    inorder(2 * index + 2);
}

int main() {
    init();

    insert(50, 0);
    insert(30, 0);
    insert(70, 0);
    insert(20, 0);
    insert(40, 0);
    insert(60, 0);
    insert(80, 0);

    printf("Inorder Traversal: ");
    inorder(0);

    return 0;
}
