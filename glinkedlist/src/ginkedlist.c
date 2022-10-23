#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "glinkedlist.h"


int g_effectivesize(data_type type, size_t size)
{
    int effectiveSize = 0;
    if (type == INT)
    {
        effectiveSize = size * sizeof(int);
    }
    else if (type == FLOAT)
    {
        effectiveSize = size * sizeof(float);
    }
    else if (type == CHAR)
    {
        effectiveSize = size * sizeof(char);
    }
    return effectiveSize;
}

gNode *g_init(const void *data, data_type type, size_t size)
{
    int effectiveSize = g_effectivesize(type, size);
    gNode *head = (gNode *)malloc(sizeof(gNode));
    head->data = malloc(effectiveSize);
    head->type = type;
    head->next = NULL;
    head->size = size;
    memcpy(head->data, data, effectiveSize);
    return head;
}

void g_print(gNode *head)
{
    while (head != NULL)
    {
        switch (head->type)
        {
        case (INT):
            for (size_t i = 0; i < head->size; i++)
            {   
                if (i == head->size - 1) {
                    printf("%d", *((int *)head->data+i));
                }else {
                    printf("%d-", *((int *)head->data+i));   
                }
            }
            break;
        case (FLOAT):
            for (size_t i = 0; i < head->size; i++)
            {   
                if (i == head->size - 1) {
                    printf("%f", *((float *)head->data+i));
                }else {
                    printf("%f-", *((float *)head->data+i));   
                }
            }
            
            break;
        case (CHAR):
            printf("%s", (char *)head->data);
            break;
        }
        printf(" -> ");
        head = head->next;
    }
    printf("NULL\n");
}

void g_free(gNode *head) {
    gNode *temp = head;
    while (temp != NULL)
    {
        temp = head->next;
        free(head->data);
        free(head);
        head = temp;
    }
    
}

gNode *g_push(gNode *head, const void *data, size_t size, data_type type){
    gNode *new;
    new = (gNode *)malloc(sizeof(gNode));
    int effectivesize = g_effectivesize(type, size);
    if(head == NULL) {
        printf("list vide");
        exit(EXIT_FAILURE);
    }
    new->data = malloc(effectivesize);
    memcpy(new->data, data, effectivesize);
    new->next = head;
    new->type = type;
    new->size = size;
    return new;
}

void *g_push_last(gNode *head, const void *data, size_t size, data_type type)
{
    gNode *last;
    gNode *temp = head;
    last = (gNode *)malloc(sizeof(gNode));
    int effectivesize = g_effectivesize(type, size);
    if (head == NULL)
    {
        printf("List empty: ");
        exit(EXIT_FAILURE);
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = last;
    last->data = malloc(effectivesize);
    last->type = type;
    last->next = NULL;
    last->size = size;
    memcpy(last->data, data, effectivesize);
}

void g_insert(gNode *head,const void *data,int pos,size_t size,data_type type){
    gNode *temp2 = g_init(data,type,size);
    gNode *temp = head;
    pos--;
    while (pos != 1)
    {
        temp = temp->next;
        pos--;
    }
    temp2->next = temp->next;
    temp->next = temp2;

    
}
   
/*int main() {
    char  p[]="hhh";
    char test[] = "hello_world";
    int t[] = {1,2,3,4,5,6};
    int a = 15;
    //size
    int size_tab = sizeof(t)/sizeof(t[0]);
    int size_test = sizeof(test)/sizeof(test[0]);
    int sizep = sizeof(p)/sizeof(p[0]);
    
    gNode *head1 = g_init(p,CHAR,sizep);
    //affichage
    g_print(head1);
    
    g_push_last(head1,test,size_test,CHAR);
    g_push_last(head1,&a,1,INT);
    for (size_t i = 0; i < size_tab; i++)
    {
        g_push_last(head1,&t[i],1,INT);
    }
    g_push_last(head1,t,size_tab,INT);
    g_print(head1);
    
    head1 = g_push(head1,&a,1,INT); 
    
    g_insert(head1,p,5,sizep,CHAR);
    
    
    
    g_print(head1);

    


    return 0;
}



*/