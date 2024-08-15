#include <stdio.h>
#include <stdlib.h>

struct node
{
struct node* prev;
int data;
struct node* next;
};
 
struct node* head = NULL;
struct node* tail = NULL;

struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void insert_at_head(int data) {
    struct node* new_node = create_node(data);
    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void insert_at_tail(int data) {
    struct node* new_node = create_node(data);
    if (tail == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}

