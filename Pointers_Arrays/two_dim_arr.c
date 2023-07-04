#include <stdio.h>
/*
 * main - entry point
 * Return: (0) success
 */
int main(void)
{
	int multi [4][3]; /*array declaration*/
	int i, j;
	for(i = 0; i<4; i++)
	{
		for(j =0; j<3; j++)
		{
			printf("Enter a value for array [%d][%d]:", i, j);
			scanf("%d", &multi[i][j]);
				}
			}
printf("2D array values\n");
for(i = 0; i<4; i++)
{
	for(j = 0; j<3; j++)
	{
		printf("%d, ", multi[i][j]);
		if(j==2)
		{
			printf("\n");
			}
		}
	}
	return (0);
}
