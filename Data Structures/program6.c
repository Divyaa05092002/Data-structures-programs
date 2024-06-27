#include <stdio.h>
#include <stdlib.h>

// Define the maximum size of the stack
#define MAX 100

// Structure to represent a stack
struct Stack {
    int top;
    int items[MAX];
};

// Function to create a stack and initialize its top
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow. Unable to push %d\n", item);
        return;
    }
    stack->items[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Unable to pop\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Function to display the elements of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    struct Stack* stack = createStack();

    // Push 5, 9, 34, 17, 32 onto the stack
    push(stack, 5);
    push(stack, 9);
    push(stack, 34);
    push(stack, 17);
    push(stack, 32);

    // Display the stack elements before popping
    printf("Stack before popping:\n");
    display(stack);

    // Pop 3 times from the stack and display the popped numbers
    printf("Popped numbers:\n");
    for (int i = 0; i < 3; i++) {
        int poppedNumber = pop(stack);
        if (poppedNumber != -1) {
            printf("%d\n", poppedNumber);
        }
    }

    return 0;
}

