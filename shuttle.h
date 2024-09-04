#ifndef shuttle_H
#define shuttle_H

struct shuttle
{
    int MisNr;
    char date[256];
    char MisName[256];
    char orbiter[256];
    char launchsite[256];
    struct shuttle *next;
    struct shuttle *prev;
};


#endif