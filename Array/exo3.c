#include<stdio.h>
#include<stdlib.h>


unsigned long int *suite_un(int n) {
    unsigned long int *un;
    un = (unsigned long int*)malloc(n*sizeof(unsigned long int));
    un[0] = 1;
    for (int i = 0; i <= n; i++)
    {
        un[i+1] = 3*un[i]*un[i] + 2*un[i] + 1;        
    }
    return un;
}

int main() {
    int n;
    printf("Entrer la taille: ");
    scanf("%d",&n);

    unsigned long int *un = suite_un(n);
    for (int i = 0; i <= n; i++)
    {
        printf("\t Un[%d] = %lu \n",i,un[i]);
    }


    free(un);
    return 0;
}