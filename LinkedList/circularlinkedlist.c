#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;          // store data
    struct node *next; // store memory address of next node
} nodes;

void circularLlist(nodes *head)
{
    nodes *temp = head;
    if (head == NULL)
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
    }
}

void printl(nodes *head)
{
    nodes *temp = head;
    if (head != NULL)
    {
        while (temp != head)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{

    nodes *head = NULL;
    nodes *second = NULL;
    nodes *third = NULL;
    // allocation
    head = (nodes *)malloc(sizeof(nodes));
    second = (nodes *)malloc(sizeof(nodes));
    third = (nodes *)malloc(sizeof(nodes));
    // store data
    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    circularLlist(head);
    printl(head);

    free(head);
    free(second);
    free(third);
    return 0;
}