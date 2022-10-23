#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {

    int n, i, *tab, max;
    printf("N: ");
    scanf("%d",&n);

    srand(time(NULL));
    tab =(int *)malloc(n*sizeof(int));

    for (i = 0; i < n; i++)
    {
        *(tab+i) = rand();
    }

    max = *tab;
    
    for ( i = 0; i < n; i++)
    {
        printf("%d\t",*(tab+i));
    }
    

    for (i = 0; i < n; i++)
    {
        if(*(tab+i) > max ) {
            max = *(tab+i);
        }
    }
    
    printf("\nmax est %d",max);
    
    free(tab);


    return 0;
}