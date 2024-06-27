#include <stdio.h>

// Function to calculate GCD of two numbers using Euclidean algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate GCD of three numbers recursively
int gcdOfThree(int a, int b, int c) {
    return gcd(gcd(a, b), c);
}

// Driver code
int main() {
    int num1 = 4, num2 = 6, num3 = 8;

    printf("GCD of %d, %d, and %d is: %d\n", num1, num2, num3, gcdOfThree(num1, num2, num3));
      return 0;
}



