#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shuttle.h"

void PrintFinal(struct shuttle* NodeHead);
struct shuttle* NewHeadNode();
void NewTailNode();
void SwapData(struct shuttle *data1, struct shuttle* data2);

struct shuttle *compare1 = NULL;
struct shuttle *compare2 = NULL;

int compare(struct shuttle *compare1, struct shuttle *compare2)
{
	int result;
	result = strcmp(compare1->MisName,compare2->MisName);
	return result;
}

int main(void)
{
    struct shuttle* head = NewHeadNode();
    for (int i = 0; i < 134; i++)
    {
        NewTailNode();
    }

    FILE *ptr;
    ptr = fopen("shuttle_data.txt", "r");

    int read = 0;

    struct shuttle *current = head;
    for (int i = 0; i < 2; i++)
    {
        fscanf(ptr, "%*[^\n]\n");
    }

    while (current != NULL) {
        read = fscanf(ptr, 
        "%d %*c %s %*c %s %*c %s %*c %s", 
                    &current->MisNr,
                    current->date,
                    current->MisName,
                    current->orbiter,
                    current->launchsite);
        current = current->next;
    }

    if (read != 5 && !feof(ptr))
    {
        printf("error! - %d", read);
    }
    fclose(ptr);

    int condition = 1;
    while(condition > 0){
            condition = 1;
        struct shuttle *sort1 = head;
        struct shuttle *sort2 = head;
        char temp[25];
        for (int algo_count = 0; algo_count < 134; algo_count++)
        {
            sort2 = sort1->next;
            int result = compare(sort1, sort2);
            if (result > 0)
            {
                SwapData(sort1, sort2);
                condition += result;
            }
            sort1 = sort1->next;
        }
        if (condition == 1)
        {
            condition = -1;
        }
    }
    PrintFinal(head);
    return 0;
}