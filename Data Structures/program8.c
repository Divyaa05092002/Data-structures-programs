
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the circular queue
struct CircularQueue {
    int data;
    struct CircularQueue* next;
};

// Global pointers for front and rear of the circular queue
struct CircularQueue *front = NULL, *rear = NULL;

// Enqueue operation to insert elements into the circular queue
void enqueue(int new_data) {
    struct CircularQueue* new_node = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    new_node->data = new_data;

    // If the queue is empty
    if (front == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    // Make the queue circular
    rear->next = front;
}

// Dequeue operation to delete elements from the circular queue
void dequeue(int key) {
    struct CircularQueue *temp = front, *prev;

    // If the queue is empty
    if (front == NULL) {
        printf("Circular Queue is empty\n");
        return;
    }

    // Traverse the queue to find the key to be deleted
    do {
        if (temp->data == key) {
            // If the element to be deleted is at the front
            if (temp == front) {
                front = temp->next;
                rear->next = front;
            } else if (temp == rear) { // If the element to be deleted is at the rear
                prev->next = front;
                rear = prev;
            } else { // If the element to be deleted is in between
                prev->next = temp->next;
            }
            free(temp);
            printf("Element %d deleted from Circular Queue\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != front); // Loop until we reach back to the front

    printf("Element %d not found in Circular Queue\n", key);
}

// Print the circular queue
void printCircularQueue() {
    struct CircularQueue* temp = front;
    if (front == NULL) {
        printf("Circular Queue is empty\n");
        return;
    }
    printf("Circular Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

// Driver program
int main() {
    // Enqueue elements into the circular queue
    enqueue(5);
    enqueue(7);
    enqueue(0);
    enqueue(6);
    enqueue(3);
    enqueue(9);

    // Print the circular queue
    printCircularQueue();

    // Delete elements 6, 9, and 5 from the circular queue
    dequeue(6);
    dequeue(9);
    dequeue(5);

    // Print the circular queue after deletion
    printCircularQueue();

    return 0;
}

