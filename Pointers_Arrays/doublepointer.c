#include<stdio.h>

/*
 * main - entry point
 * return: 0 success
 * */

int main(void)
{
        int a = 5;
        int *b = &a;
        int **c = &b;

        printf("Value of a is: %d\n", a);
        printf("%d, %d, %d\n", a, *b, **c);
        return (0);
}
