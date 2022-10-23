#include<stdio.h>
#include<stdlib.h>

int main() {
    typedef struct node {
        nodes *prev;
        int data;
        nodes *next;
    }nodes;

    nodes *head = (nodes*)malloc(sizeof(nodes));
    nodes *second = (nodes*)malloc(sizeof(nodes));
    nodes *third = (nodes*)malloc(sizeof(nodes));
    
    head->prev = NULL;
    head->data = 2;
    head->next = second

    second->prev = head;
    second->data = 3;
    second->next = NULL;


    void insertHead(int x) {
        nodes *temp = (nodes *)malloc(sizeof(nodes));
        
        
    }




    return 0;


}