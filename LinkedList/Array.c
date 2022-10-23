#include<stdio.h>
#include<stdlib.h>

int main() {
    struct stagiaire {
        int num;
        char nom[30];
    };
    //s1.num = 1;
    //strcpy(s1.nom,"Khalid"); /* no pointers */
    //s1.nom = "Youssef" /* pointers*/
    //struct stagiaire s1={1,"Youssef"};


    struct stagiaire stagiaires[3];
    for (int i = 0; i <3 ; i++)
    {
        printf("Entrer le numeo d inscription : \n");
        scanf("%d",&stagiaires[i].num);
        printf("Entrer votre nom: \n");
        scanf("%s",&stagiaires[i].nom);
    }

    printf("\n La liste des stagiaires est : ");
    printf("\n------------------\n");

    
    for (int i = 0; i < 3; i++)
    {
        printf("N : %4d | Nom : %s\n",stagiaires[i].num,stagiaires[i].nom);
    }
    
    
    

    return 0;
}