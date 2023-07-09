#include <stdio.h>
/*
 * 
 * main - entry
 * return: 0 
 */
void pass_by_ref(int *pt)
{
	*pt = 75624;
}
int main(void)
{
	int num = 14;
	printf("Number before calling is %d\n", num);
	pass_by_ref(&num);
	printf("After calling it is %d\n", num);
	return (0);
}
