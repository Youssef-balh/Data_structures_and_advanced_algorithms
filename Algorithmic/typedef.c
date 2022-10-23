#include<stdio.h>
#include<stdlib.h>

int main(){
    typedef struct stagiaire
    {
        char *nom;
        int age;
    }stgr;
    stgr stagiaire1 ={"Khalid",27};
    
    stgr stagiaire2;
    stagiaire2.nom ="Ahmed";
    stagiaire2.age  =23;

    printf("%s / %d \n",stagiaire1.nom,stagiaire1.age);
    printf("%s / %d",stagiaire2.nom,stagiaire2.age);


    return 0;
}