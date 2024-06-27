
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // For isdigit function

// Stack structure for integers
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element to the stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return -1; // If the stack is empty, return -1 (error case)
}

// Function to evaluate postfix expression
int evaluatePostfix(char* exp) {
    struct Stack* stack = createStack(strlen(exp));
    int i, op1, op2;

    for (i = 0; exp[i]; ++i) {
        // If the character is a digit, push it to the stack
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');

        // If the character is an operator, pop two operands from the stack, perform the operation, and push

        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            op2 = pop(stack);
            op1 = pop(stack);

            switch (exp[i]) {
                case '+': push(stack, op1 + op2); break;
                case '-': push(stack, op1 - op2); break;
                case '*': push(stack, op1 * op2); break;
                case '/': push(stack, op1 / op2); break; // Assuming operands are always integers and non-zero

            }
        }
    }

    // The final result will be at the top of the stack
    return pop(stack);
}

// Driver code
int main() {
    char postfix[] = "5 3 + 8 2 - *";
    int result = evaluatePostfix(postfix);

    printf("Postfix expression: %s\n", postfix);
    printf("Result: %d\n", result);

    return 0;
}

