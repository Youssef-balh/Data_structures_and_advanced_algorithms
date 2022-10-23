#include<stdio.h>
#include<stdlib.h>
#include<conio.h>



void delete(int *tab,int n,int pos){
    int *p;
    p = tab;
    for (p = tab+pos ; p<tab+n; p++)
    {
        *p = *(p+1);
    }
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

void inverse(int *tab, int n) {
    int *p1;
    int *p2;
    int temp;
    for (p1 = tab , p2 = tab+n-1; p1 < p2; p1++,p2--)
    {
        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }
}

int* merge(int* tab0,int* tab1,int n0,int n1) {
    int i;
    int *p0,*p1;
    int* tab = (int*)malloc((n1+n0)*sizeof(int));

    for (i =0, p0=tab0 ,p1=tab1; p0<(tab0+n0) && p1<(tab1+n1); ++i)
    {
       /* if (*p0 > *p1 ) {
            *(tab+i) = *p1;
            ++p1;
        } else {
            *(tab+i) = *p0;
            ++p0;
        }
        */
        (*p0 > *p1) ? (*(tab+i) = *p1, ++p1 ): (*(tab+i) = *p0, ++p0); 
    }
    if (p0 == tab0 + n0 ){
        while (p1 < tab1 + n1)
        {
            *(tab+i) = *p1;
            ++p1;
        }

    } else {
        while (p0 < tab0 + n0)
        {
            *(tab+i) = *p0;
            ++p0;
        }
    }
    //(p0 == tab0 + n0 ) ? (while (p1 < tab1 + n1){ *(tab+i) = *p1; ++p1;}) : (while (p0 < tab0 + n0){ *(tab+i) = *p0; ++p0;});



    return tab;

}


int main() {
    int* tab,n,pos;
    int tab0[] = {5,8,9,10,23,29};
    int tab1[] ={1,6,7,15,18,24,25,28};

    int n0 = sizeof(tab0)/sizeof(tab0[0]);
    int n1 = sizeof(tab1)/sizeof(tab1[0]);
    int* new = merge(tab0,tab1,n0,n1);

    print_list(new,n0+n1);
    

/*
    printf("Entrer n: ");
    scanf("%d",&n);

    tab = (int*)calloc(n,sizeof(int));
    remplissage(tab,n);
    printf("\nAffichage\n");
    print_list(tab,n);

    //delete
    printf("\nEntrer la position de l element a supprimer: ");
    scanf("%d",&pos);
    delete(tab,n,pos-1);
    n--;
    //affichage
    print_list(tab,n);
    printf("\n");
    //inversement
    inverse(tab,n);
    print_list(tab,n);
*/
    //merge 
    
    
    getch();   
    return 0;
}