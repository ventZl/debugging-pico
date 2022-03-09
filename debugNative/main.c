#include <stdio.h>

long fact(long x)
{
    if (x == 1)
        return 1;
    return x * fact(x - 1);
}

int main(int argc, char ** argv)
{
    int argv1 = 5;
    int n = argv1;
    printf("Factorial of %d is %d\n", n, fact(n));

    return 0;
}