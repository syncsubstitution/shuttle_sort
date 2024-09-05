#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shuttle.h"

void PrintFinal(struct shuttle* NodeHead);
struct shuttle* NewHeadNode();
void NewTailNode();
int ReadAndSort();
void SwapData(struct shuttle *data1, struct shuttle* data2);
int compare(struct shuttle *compare1, struct shuttle *compare2);

struct shuttle *compare1 = NULL;
struct shuttle *compare2 = NULL;

int compare(struct shuttle *compare1, struct shuttle *compare2)
{
	int CompResult;
	CompResult = strcmp(compare1->MisName,compare2->MisName);
	return CompResult;
}

int ReadAndSort()
{
    struct shuttle* head = NewHeadNode();
    for (int i = 0; i < 134; i++)           //creates 135 "empty" nodes using a separate function
    {
        NewTailNode();
    }

    FILE *ptr;
    ptr = fopen("shuttle_data.txt", "r");

    int read = 0;

    for (int i = 0; i < 2; i++)
    {
        fscanf(ptr, "%*[^\n]\n");       //skip the two leading lines in the file which don't match later formatting requirements
    }

    struct shuttle *current = head;
    while (current != NULL) {           //goes through all nodes and assigns data from file to struct elements
        read = fscanf(ptr,  
        "%d %*c %s %*c %s %*c %s %*c %s", 
                    &current->MisNr,
                    current->date,
                    current->MisName,
                    current->orbiter,
                    current->launchsite);
        current = current->next;
    }

    if (read != 5 && !feof(ptr))        //checks if values were assigned to all 5 struct elements
    {
        printf("error! - %d", read);
    }
    fclose(ptr);

    int LoopCheck = 1;                  
    while(LoopCheck > 0){
        LoopCheck = 1;
        struct shuttle *sort1 = head;
        struct shuttle *sort2 = head;
        for (int algo_count = 0; algo_count < 134; algo_count++)
        {
            sort2 = sort1->next;
            int result = compare(sort1, sort2);     //custom strcmp function
            if (result > 0)
            {
                SwapData(sort1, sort2);             //exchanges values of struct elements
                LoopCheck += result;
            }
            sort1 = sort1->next;
        }
        if (LoopCheck == 1)             //will only be 1 if nothing was added in line 71 (=no more sorting is to be done), so while-loop must end
        {
            LoopCheck = -1;
        }
    }
    PrintFinal(head);
    return 0;
}