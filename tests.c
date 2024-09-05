#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct shuttle
{
	char MisName[256];
	struct shuttle *next;
	struct shuttle *prev;
};

struct shuttle *head = NULL;
struct shuttle *tail = NULL;

struct shuttle *create_node()
{
	struct shuttle *new_node = (struct shuttle *)malloc(sizeof(struct shuttle));
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

void insert_at_head()
{
	struct shuttle *new_node = create_node();
	if (head == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
}

void insert_at_tail()
{
	struct shuttle *new_node = create_node();
	if (tail == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
	}
}

int compare(struct shuttle *compare1, struct shuttle *compare2)
{
	int result;
	result = strcmp(compare1->MisName,compare2->MisName);
	return result;
}

int main()
{
	insert_at_head();
	for (int i = 0; i < 4; i++)
	{
		insert_at_tail();
	}

  char test_v[5][25] = {"STS-35-B", "STS-99", "STS-35-A", "STS-2", "STS-101"};
	struct shuttle* current = head;
	for (int i = 0; i < 5; i++)
	{
		strcpy(current->MisName, test_v[i]);
		current = current->next;
	}


	struct shuttle *sort1 = head;
	struct shuttle *sort2 = head;
	char temp[256];
	for (int algo_count = 0; algo_count < 4; algo_count++)
	{
	struct shuttle *printhead = head;
		sort2 = sort1->next;
		int result = compare(sort1, sort2);
		if (result > 0)
		{
			printf("-----------------------------------------------\n");
			printf("head: %s, s1: %s, s2: %s, temp: %s\n", printhead->MisName, sort1->MisName, sort2->MisName, temp);
			strcpy(temp,sort1->MisName);
			printf("head: %s, s1: %s, s2: %s, temp: %s\n", printhead->MisName, sort1->MisName, sort2->MisName, temp);
			strcpy(sort1->MisName,sort2->MisName);
			printf("head: %s, s1: %s, s2: %s, temp: %s\n", printhead->MisName, sort1->MisName, sort2->MisName, temp);
			strcpy(sort2->MisName,temp);
			printf("head: %s, s1: %s, s2: %s, temp: %s\n", printhead->MisName, sort1->MisName, sort2->MisName, temp);
		}
		sort1 = sort1->next;
		for(int i = 0; i < 5; i++){
		    printf("%s, ", printhead->MisName);
		    printhead = printhead->next;
		}
		printf("\n");

	}

	return 0;
}