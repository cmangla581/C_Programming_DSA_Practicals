// Impplement the stack using array 

#include <stdio.h> 
# define  MAX 100 

int stack[MAX]; 
int top = -1; 

// Push Operation 
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
    printf("%d pushed to stack\n", x);
}

// Pop operation
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped from stack\n", stack[top--]);
}

// Peek operation
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", stack[top]);
}

// Display stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    
    display();
    
    peek();
    
    pop();
    pop();
    
    display();
    
    return 0;
}