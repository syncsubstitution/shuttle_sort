#include <stdio.h>
#include <stdlib.h>

struct node* AddAtEnd(struct node* head, int data);
struct node* AddToEmpty(struct node* head, int data);
struct node* CreateList(struct node* head);

struct node
{
    struct node* prev;
    int data;
    struct node* next;
};

int main(void){
    struct node* head = NULL;
    struct node* ptr;
    head = CreateList(head);

    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    return 0;
}

struct node* CreateList(struct node* head){
    int n, data, i;
    printf("No. of Nodes: ");
    scanf("%d", &n);

    printf("\nEnter Node 1 Data: ");
    scanf("%d", &data);

    head = AddToEmpty(head, data);

    for (i = 1; i < n; i++)     
    {
        printf("\nEnter node %d data: ", i+1);
        scanf("%d", &data);
        head = AddAtEnd(head, data);
    }
    return head;
}

struct node* AddToEmpty(struct node* head, int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node* AddAtEnd(struct node* head, int data){
    struct node* temp, *tp;
    temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    tp = head;

    while(tp->next != NULL){
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;
}
