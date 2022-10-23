#ifndef glinkedlist_h
#define glinkedlist_h
#include<stdlib.h>
#include<stdio.h>

typedef enum
{
    INT,
    FLOAT,
    CHAR
} data_type;

typedef struct node
{
    data_type type;
    void *data;
    struct node *next;
    unsigned size;
} gNode;


int g_effectivesize(data_type type, size_t size);

gNode *g_init(const void *data, data_type type, size_t size);

void g_print(gNode *head);

void g_free(gNode *head);

gNode *g_push(gNode *head, const void *data, size_t size, data_type type);

void *g_push_last(gNode *head, const void *data, size_t size, data_type type);

void g_insert(gNode *head,const void *data,int pos,size_t size,data_type type);


#endif