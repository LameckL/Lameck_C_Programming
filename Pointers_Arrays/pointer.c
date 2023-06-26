#include <stdio.h>

/*
 * main - entry point,
 * return: alwways 0
 **/
int main(void)
{
	int a = 20;
	int b = 46;
	int * p, * q;
	int p = &a;
	int q = &b;
	printf("%d\n", a);
	printf("%d\n", b);
	printf("%d\n", p);
	printf("%d\n", q);
	printf("%x\n", &p);
	printf("%x\n", &q);
	return (0);
}

