#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Enqueue operation
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// Dequeue operation
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node* temp = front;
    printf("Dequeued element: %d\n", front->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

// Peek operation
void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

// Display queue
void display() {
    struct Node* temp = front;

    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();

    peek();

    dequeue();
    display();

    return 0;
}