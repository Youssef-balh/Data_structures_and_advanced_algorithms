#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<math.h>

int rech_dicho(int array[], int n, int key)
{
    int i, begin = 0, end = n - 1;
    bool found = false;
    do
    {
        i = floor((begin + end) / 2);
        if (array[i] == key)
        {
            found = true;
        }
        else if (array[i] < key)
        {
            begin = i + 1;
        }
        else
        {
            end = i - 1;
        }

    } while (!found);

    return i;
}

int main()
{
    int array[] = {1, 7, 8, 9, 12, 15, 18, 22, 30, 31};
    int size = sizeof(array) / sizeof(array[0]);
    int resultat = rech_dicho(array, size, 30);
    printf("Resultat : %d", resultat);
    printf("\n%d",array[resultat]);
    
}