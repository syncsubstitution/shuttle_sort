#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shuttle.h"

void Main_Print(char* var_string, int spaces, int bar, int bar_spaces);
void Int_Print(int var_int, int spaces, int bar, int bar_spaces);
struct shuttle *tail = NULL;
struct shuttle *head = NULL;

struct shuttle *MakeNode()
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
        Main_Print(print->MisName, 20, 1, 2);
        Main_Print(print->orbiter, 10, 1, 1);
        Main_Print(print->launchsite, 10, 0, 0);
        printf("\n");
        print = print->next;
    }
}

void Main_Print(char* var_string, int spaces, int bar, int bar_spaces)
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

void Int_Print(int var_int, int spaces, int bar, int bar_spaces)
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

void SwapData(struct shuttle *data1, struct shuttle *data2){
    int NumTemp = data1->MisNr;
    data1->MisNr = data2->MisNr;
    data2->MisNr = NumTemp;
    char temp[25];
    strcpy(temp, data1->date);
    strcpy(data1->date, data2->date);
    strcpy(data2->date, temp);
    for(int i = 0; i <strlen(temp); i++)
    {temp[i] = 0;}
    strcpy(temp, data1->MisName);
    strcpy(data1->MisName, data2->MisName);
    strcpy(data2->MisName, temp);
    for(int i = 0; i < strlen(temp);i++)
    {temp[i] = 0;}
    strcpy(temp, data1->orbiter);
    strcpy(data1->orbiter, data2->orbiter);
    strcpy(data2->orbiter, temp);
    for(int i = 0; i < strlen(temp); i++)
    {temp[i] = 0;}
    strcpy(temp, data1->launchsite);
    strcpy(data1->launchsite, data2->launchsite);
    strcpy(data2->launchsite, temp);
    for(int i = 0; i < strlen(temp); i++)
    {temp[i] = 0;}
}
