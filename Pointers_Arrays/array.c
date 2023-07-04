#include <stdio.h>
/*
 * myarray - function with the array
 * main - entry point
 *Return: 0 success
 */
void myarray(int arr [])
{
	int i;
	for(i = 0; i<10; i++)
	{
		if(arr[i]<50) /*condition to check for value less than 50 in the arr*/
		{
		printf("%d, ", arr[i]);
		}
	}
}
int main(void)
{
	int arr[10] = {21, 45, 21, 56, 54, 89, 20, 67, 47};
	myarray(arr);
	printf("\n");
	return (0);
}
