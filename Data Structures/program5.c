#include <stdio.h>
#include <stdlib.h>

// Node structure for a polynomial term
struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coefficient, int exponent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

// Function to add a term to the polynomial
void addTerm(struct Node** poly, int coefficient, int exponent) {
    struct Node* newNode = createNode(coefficient, exponent);
    newNode->next = *poly;
    *poly = newNode;
}

// Function to print the polynomial
void printPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coefficient, poly->exponent);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node* temp;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            addTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            addTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0)
                addTerm(&result, sum, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        addTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        addTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    // Reverse the result list to maintain the order
    struct Node* prev = NULL;
    struct Node* current = result;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    result = prev;

    return result;
}

// Driver code
int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Create first polynomial: 6x^3 + 10x^2 + 0x + 5
    addTerm(&poly1, 5, 0);
    addTerm(&poly1, 0, 1);
    addTerm(&poly1, 10, 2);
    addTerm(&poly1, 6, 3);

    // Create second polynomial: 4x^2 + 2x + 1
    addTerm(&poly2, 1, 0);
    addTerm(&poly2, 2, 1);
    addTerm(&poly2, 4, 2);

    printf("First polynomial: ");
    printPolynomial(poly1);

    printf("Second polynomial: ");
    printPolynomial(poly2);

    struct Node* sum = addPolynomials(poly1, poly2);

    printf("Sum of polynomials: ");
    printPolynomial(sum);

    return 0;
}

