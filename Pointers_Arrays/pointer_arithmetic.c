#include <stdio.h>
#include <stddef.h>
/*
 * main - entry point
 * return: (0) success
int addPointers(int *b, int a)
{
	printf("%ls\n", (wchar_t*)  b + 1);
}
int subtractPointers(int a, int *b, int *c)
{
	a = b - c;
	printf("%d\n", a);
}
**/
int main(void)
{
	int a = 4;
	int d = 3;
	int *b = &a;
	int *c = &d;
	printf("a is: %d %d\n", a, (wchar_t*)  *b);
	printf("address of a: %u\n", &a);
	printf("d is: %d %d\n", d, (wchar_t*)  *c);
	printf("address of d: %u\n", &d);
	/*printf("%ls\n", (wchar_t*)  b + 1);*/
	a = c - b;
	d = b + 1;
	printf("%d\n", a);
	printf("%d\n", d);

	return (0);
}
