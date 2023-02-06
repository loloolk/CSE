#include <stdio.h>

int factorial(int n) {
    return n == 0 ? 1 : n * factorial(n-1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("The factorial of %d is %d\n", num, factorial(num));
    return 0;
}