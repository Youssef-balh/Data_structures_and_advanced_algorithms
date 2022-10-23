#include <stdio.h>
#include <stdlib.h>

int main()
{

    typedef struct node
    {
        int data;          // store data
        struct node *next; // store memory address of next node
    } nodes;

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

    // ---------------------------
    /* ADD element IN THE BEGINING*/
    nodes *addElement(nodes *head, int elem)
    {
        nodes *new = NULL;
        new = (nodes *)malloc(sizeof(nodes));
        new->data = elem;
        new->next = head;
        return new;
    }
    // ----------------------------
    /* Print element */
    void printlists(nodes * n)
    {
        while (n != NULL)
        {
            printf("%d -> ", n->data);
            n = n->next;
        }
        printf("Null\n");
    }
    // ------------------------------
    /*ADD IN THE END */
    void *endelement(nodes *head, int elem)
    {   
        nodes *end = NULL;
        nodes *lastNode = NULL;
        lastNode = (nodes *)malloc(sizeof(nodes));
        end = (nodes *)malloc(sizeof(nodes));
        end->data = elem;
        end->next = NULL;
        lastNode = head;
        if(head == NULL) {
            head = end;
        } else {
            while (lastNode->next != NULL)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = end;
            
        }
    }

    // ------------------------------
    /* Search node */
    int searchNode(nodes *head, int key) {
        nodes *temp = head;
        temp = (nodes *)malloc(sizeof(nodes));
        while(temp != NULL){
            if (temp->data == key){
                return 1;
            temp = temp->data;
        }    
        return -1;
        }
    }
    // ----------------------------------
    /* Reverse linked list */
    void reverseList(nodes **head) {
        nodes *prev = NULL;
        nodes *current = (*head);
        nodes *next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current; 
            current = next;
        }
        *head = prev;
        
    }
    //-----------------------------------
    /* ADD at certain position */
    void addnodepos(nodes *head,int elem,int pos){
        nodes *temp = head ;
        nodes *temp2 = malloc(sizeof(nodes)); // new node pointer 
        temp2->data = elem;
        temp2->next = NULL;
        pos--;
        while (pos != 1)
        {
            temp = temp->next;
            pos--;
        }
        temp2->next = temp->next;
        temp->next = temp2;
        


    }
    //----------------------------------
    /* Delete element */
    void delete(nodes **head,int pos){
        nodes *prev = (*head);
        nodes *current = (*head);
        if (*head == NULL) {
            printf("List is empyt");
            exit(EXIT_FAILURE);
        } else if (pos == 1){
            *head = current->next;
            free(current);
            current = NULL; 
        } else {
            while (pos != 1)
            {
                prev = current ;
                current = current->next;
                pos--;
            }
            prev->next = current->next;
            free(current);
            current = NULL;
            
        }
    }

    // --------------------------------
    nodes *y = addElement(head,0);

    endelement(y,4);
    printlists(y);
    printlists(head);
    reverseList(&head);
    addnodepos(head,5,2);
    printlists(head);


    if (searchNode(head,5) == 1){
        printf("Element found");
    } else {
        printf("Element not found");
    }
    printf("\n");
    delete(&head,2);
    printlists(head);  
    
    free(head);
    free(second);
    free(third);

    return 0;
}