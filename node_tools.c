#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shuttle.h"

void Main_Print(char* var_string, int spaces, int bar, int bar_spaces);
void Int_Print(int var_int, int spaces, int bar, int bar_spaces);
struct shuttle *tail = NULL;
struct shuttle *head = NULL;

struct shuttle *MakeNode()              //used to create all nodes, next and prev specified in NewHeadNode and NewTailNode
{
    struct shuttle *NewNode = (struct shuttle *)malloc(sizeof(struct shuttle));
    NewNode->next = NULL;
    NewNode->prev = NULL;
    return NewNode;
}

struct shuttle* NewHeadNode()
{
    struct shuttle *NewNode = MakeNode();
    if (head == NULL)
    {
        head = NewNode;
        tail = NewNode;
    }
    else
    {
        NewNode->next = head;
        head->prev = NewNode;
        head = NewNode;
    }
    return head;
}

void NewTailNode()
{
    struct shuttle *NewNode = MakeNode();
    if (tail == NULL)
    {
        head = NewNode;
        tail = NewNode;
    }
    else
    {
        NewNode->prev = tail;
        tail->next = NewNode;
        tail = NewNode;
    }
}

void PrintFinal(struct shuttle* PrintHead){
    struct shuttle* print = PrintHead;
    printf("Missions-Nr. | Start-Datum | Missionsbezeichnung |  Orbiter   | Startrampe\n-------------------------------------------------------------------------\n");
    for (int printcount = 0; printcount < 135; printcount++)
    {
        Int_Print(print->MisNr, 13, 1, 1);
        Main_Print(print->date, 12, 1, 1);
        Main_Print(print->MisName, 20, 1, 1);
        Main_Print(print->orbiter, 11, 1, 1);
        Main_Print(print->launchsite, 6, 0, 0);
        printf("\n");
        print = print->next;
    }
}

void Main_Print(char* var_string, int spaces, int bar, int bar_spaces)      //ensures alignment with varying string length (copied from my previous fms task)
{
    int length = 0;
    char* temp = var_string;
    printf("%s", temp);
    while (*var_string != '\0'){
        length++;
        var_string++;
    }
    int align = spaces - length;   
    for (int count = 0; count < align; count++){
        printf(" ");            
    }
    if (bar == 1){
        printf("|");
    }
    if (bar_spaces != 0){
        for (int i = 0; i < bar_spaces; i++){
            printf(" ");
        }   
    }
} 

void Int_Print(int var_int, int spaces, int bar, int bar_spaces)    	    //same as Main_Print for variables of type int 
{
    int length;
    if (var_int < 10)
    {length=1;}
    else if (var_int < 100)
    {length=2;}
    else if (var_int < 1000)
    {length=3;}
    printf("%d", var_int);
    int align = spaces - length;   
    for (int count = 0; count < align; count++){
        printf(" ");            
    }
    if (bar == 1){
        printf("|");
    }
    if (bar_spaces != 0){
        for (int i = 0; i < bar_spaces; i++){
            printf(" ");
        }   
    }
}

void SwapNodes(struct shuttle *data1, struct shuttle *data2){               //sorts nodes by redirecting pointers
    if(data1->prev != NULL)
    {data1->prev->next = data2;}
    else
    {head = data2;}
    if(data2->next != NULL)
    {data2->next->prev = data1;}
    else
    {tail = data1;}
    data1->next  = data2->next;
    data2->prev = data1->prev;
    data2->next = data1;
    data1->prev = data2;
}
