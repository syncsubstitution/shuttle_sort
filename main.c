#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "shuttle.h"

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

void display_forward() {
    struct shuttle* current = head;
    while (current != NULL) {
        printf("%d ", current->MisNr);
        current = current->next;
    }
    printf("n");
}

int sorting(struct shuttle* compare1, struct shuttle* compare2);

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
        // return 1;
    } 
    fclose(ptr);

    struct shuttle* sort = head;
    for (int sort1 = 0; sort1 < 135; sort1++){
        struct shuttle* temp = sort;
        printf("currently sorting: %s vs %s \n", sort->MisName, sort->next->MisName);
        if (sorting(sort, sort->next) > 0)
        {
            strcpy(sort->MisName,temp->MisName);
            strcpy(sort->next->MisName,sort->MisName);
            strcpy(temp->MisName,sort->next->MisName);
        }
        sort = sort->next;
    }
    
    printf("%d\n%s", head->MisNr, tail->launchsite);
    return 0;
}

int sorting(struct shuttle* compare1, struct shuttle* compare2){
    if(strcmp(compare1->MisName, compare2->MisName) > 0){
    return 1;
    }
    else 
    return -1;
}