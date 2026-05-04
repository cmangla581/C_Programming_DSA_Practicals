// Write a program to create and traverse Binary tree using array 

# include <stdio.h> 

#define SIZE 100 

int tree[SIZE]; 

// Pre order Traversal 
void preorder(int i){
    if (tree[i] == -1 || i >= SIZE) 
       return; 

    printf("%d ", tree[i]); 
    preorder(2*i + 1);       
    preorder(2*i + 2); 
}

int main() {
    int n,i ; 

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Initialize tree
    for(i = 0; i < SIZE; i++)
        tree[i] = -1;

    printf("Enter elements (use -1 for NULL):\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &tree[i]);
    }

    printf("Preorder Traversal: ");
    preorder(0);

    return 0;
}

