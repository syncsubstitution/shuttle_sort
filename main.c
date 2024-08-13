#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "shuttle.h"

typedef struct shuttle
{
    int MisNr;
    unsigned char date[256];
    unsigned char MisName[256];
    unsigned char orbiter[256];
    unsigned char launchsite[256];
    unsigned char testdump[256];
    struct shuttle *next;       
    struct shuttle *previous; 
}shuttle;

int main()
{
    //char ch;
    
    shuttle Shuttle_Missions[135];

    FILE* ptr; 
    ptr = fopen("shuttle_data.txt", "r");

    int read = 0;
    int mission = 0;

    do
    {
        read = fscanf(ptr,
        "%d %*c %s %*c %s %*c %s %*c %s", 
        &Shuttle_Missions[mission].MisNr,
        Shuttle_Missions[mission].date,
        Shuttle_Missions[mission].MisName,
        Shuttle_Missions[mission].orbiter,
        Shuttle_Missions[mission].launchsite);
        
        if (read != 5 && !feof(ptr)){
            printf("error! - %d", read);
            return 1;
        }
        mission++;

    } while (!feof(ptr));
    
    fclose(ptr);
    return 0;
}
