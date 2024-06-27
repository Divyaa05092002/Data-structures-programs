
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack structure for characters
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the given character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to get the precedence of an operator
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to push an element to the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (stack->top == -1)
        return '\0';
    return stack->array[stack->top--];
}

// Function to peek the top element of the stack
char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, k;

    for (i = 0, k = -1; infix[i]; ++i) {
        // If the character is an operand, add it to the output
        if (isalnum(infix[i]))
            postfix[++k] = infix[i];

        // If the character is '(', push it to the stack
        else if (infix[i] == '(')
            push(stack, '(');

        // If the character is ')', pop and output from the stack until '(' is encountered
        else if (infix[i] == ')') {
            while (peek(stack) != '(')
                postfix[++k] = pop(stack);
            pop(stack); // Remove '(' from the stack
        }

        // If the character is an operator
        else {
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
                postfix[++k] = pop(stack);
            push(stack, infix[i]);
        }
    }

    // Pop all the operators from the stack
    while (!isEmpty(stack))
        postfix[++k] = pop(stack);

    postfix[++k] = '\0'; // Null-terminate the postfix expression
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Driver code
int main() {
    char infix[] = "x^y/(5*z)+2";
    char postfix[50]; // Assuming a max size for the result

    infixToPostfix(infix, postfix);

    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}


