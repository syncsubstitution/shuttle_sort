#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct shuttle
{
    int MisNr;
    char date[256];
    char MisName[256];
    char orbiter[256];
    char launchsite[256];
    struct shuttle* next;       
    struct shuttle* prev; 
};

struct shuttle* head = NULL;
struct shuttle* tail = NULL;
struct shuttle* compare1 = NULL;
struct shuttle* compare2 = NULL;

struct shuttle* create_node() {
    struct shuttle* new_node = (struct shuttle*)malloc(sizeof(struct shuttle));
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insert_at_head() {
    struct shuttle* new_node = create_node();
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void insert_at_tail() {
    struct shuttle* new_node = create_node();
    if (tail == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}

int comparer(char* string1, char* string2){
    int step = 0;
    char temp1[10];
    char temp2[10];
    strcpy(temp1, string1);
    strcpy(temp2, string2);
    while (temp1[step] != '\0')
    {
        if (temp1[step] == temp2[step])
        {
            step++;
        }
        if (temp1[step] > temp2[step])
        {
            return 1;
        }
        if (temp1[step] < temp2[step])
        {
            return -1;
        }
        
    }
    return 0;    
}

int sorting(struct shuttle* compare1, struct shuttle* compare2){
    //printf("testing %s w. %s", compare1->MisName, compare2->MisName);
    int result = comparer(compare1->MisName, compare2->MisName);
    //printf(" result: %d\n", result);
    return result;
}

int main(void)
{
    insert_at_head();
    for (int i = 0; i < 134; i++){
        insert_at_tail();
    }

    FILE* ptr; 
    ptr = fopen("shuttle_data.txt", "r");

    int read = 0;

    struct shuttle* current = head;
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
    
    if (read != 5 && !feof(ptr)){
        printf("error! - %d", read);
    } 
    fclose(ptr);

int condition = 1;
while(condition > 0){
        condition = 1;
//for(int rep = 0; rep < 5; rep++){
        struct shuttle* sort1 = head;
        struct shuttle* sort2 = head;
        struct shuttle* temp = head;
        for(int algo_count = 0; algo_count < 134; algo_count++){
            sort2 = sort1->next;
            int result = sorting(sort1, sort2);
            if (result > 0)
            {
                printf("overwriting %s with %s, ", sort1->MisName, sort2->MisName);
                strcpy(temp->MisName,sort1->MisName);
                strcpy(sort1->MisName,sort2->MisName);
                strcpy(sort2->MisName,temp->MisName);
                printf("result: %s & %s\n", sort1->MisName, sort2->MisName);
                condition += result;
            }
            sort1 = sort1->next;
        }
        if (condition == 1)
        {
            condition = -1;
        }
        
    }
    /* struct shuttle* print = head;
    for (int printcount = 0; printcount < 133; printcount++)
    {
        printf("%s\n", print->MisName);
        print = print->next;
    }
     */
    return 0;
}