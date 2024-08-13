#ifndef shuttle_H
#define shuttle_H

typedef struct shuttle
{
    int MisNr;
    unsigned char date[256];
    unsigned char MisName[256];
    int orbiter;
    int launchsite;
    struct shuttle *next;       
    struct shuttle *previous;   
};

#endif