#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *tab, int n)
{
    int temp, i, j;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (*(tab + i) > *(tab + j))
            {
                temp = *(tab + i);
                *(tab + i) = *(tab + j);
                *(tab + j) = temp;
            }
        }
    }
}
void print_array(int *tab, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", *(tab + i));
    }
}

int main()
{
    int n, i, *array;
    printf("N: ");
    scanf("%d", &n);
    float comparaison = n + (n * (n - 1)) / (float)2 + (n * (n + 1)) / (float)2 - 1;

    //Remplissage
    srand(time(NULL));
    array = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        *(array + i) = rand();
    }

    print_array(array,n);
    bubble_sort(array,n);
    printf("\nSorted: \n");
    
    print_array(array,n);



    free(array);

    return 0;
}