#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void INSERER(int *tab,int m,int n,int pos){
    int *p;
    p = tab;
    for ( p = tab+n-1; p>=tab+pos-1; p--)
    {
        *(p+1) = *p;
    }
    *(p+pos-1) = m;
    
}



void print_list(int *tab, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d -> ",*(tab+i));
    }  
}

void remplissage(int *tab, int n) {
    for (int i = 0; i < n; i++)
    {
        printf("\nt[%d] = ",i);
        scanf("%d",tab+i);
    }  
}

int main() {
    int *tab,i,m,n,NB_MAX;
    NB_MAX= 10;
    printf("Entrer la taille du tableau: ");
    scanf("%d",&n);
    
    tab = (int*)calloc(n,sizeof(int));
    remplissage(tab,n);
    printf("\nAffichage\n");
    print_list(tab,n);

    printf("\nEntrer element a inserer: \n");
    scanf("%d",&m);
    printf("\nEntrer sa position: \n");
    scanf("%d",&i);

    INSERER(tab,m,n,i);
    n++;
    print_list(tab,n);
    
    return 0;
}