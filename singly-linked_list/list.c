#include <stdio.h>
#include <stdlib.h>
/*
 * main - entry point
 *
 * Return: 0
 */
int data;
struct node {
	int data;
	struct node *link;
};

int main(void)
{
	struct node *head = malloc(sizeof(struct node));
	head-> data = 16;
	head-> link = NULL;

	struct node *head2 = malloc(sizeof(struct node));
	head2-> data = 17;
	head2-> link = head;

	struct node *head3 = malloc(sizeof(struct node));
	head3-> data = 18;
	head3-> link = head2;

	struct node *current = head3;
	while(current != NULL)
	{
		printf("%d\n", current->data);
		current = current->link;
	}
	free(head);
	free(head2);
	free(head3);
	return (0);
}
