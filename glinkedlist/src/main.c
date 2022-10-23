#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "glinkedlist.h"
#include<conio.h>




int main() {
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

    
    getch();

    return 0;
}



