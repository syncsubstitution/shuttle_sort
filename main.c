#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "shuttle.h"

struct shuttle
{
    int MisNr;
    unsigned char date[256];
    unsigned char MisName[256];
    unsigned char orbiter[256];
    unsigned char launchsite[256];
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


int main(void)
{
    insert_at_head();
    for (int i = 0; i < 135; i++){
        insert_at_tail();
    }

    FILE* ptr; 
    ptr = fopen("shuttle_data.txt", "r");

    int read = 0;

    struct shuttle* current = head;
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
            return 1;
        }
       
    fclose(ptr);
    printf("%d", tail->prev->MisNr);
    return 0;
}