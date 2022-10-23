#include<stdio.h>
#include<stdlib.h>
int main() 
{

    struct livre
    {
        char *titre;
        int nbrPages;
        float prix;
    };

    struct livre antigone = {"Antigone",122,5.4}; 

    printf("Le prix du livre est %.2f",antigone.prix); 
    

    return 0;
}