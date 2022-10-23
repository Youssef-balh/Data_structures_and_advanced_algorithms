#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int array[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i-1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[%d] = %d\n ", i, array[i]);
    }
}
int main()
{

    int array[] = {7, 1, 3, 9, 0, 2, 5, 4, 11, 10, 12};
    int size = sizeof(array) / sizeof(array[0]);
    bubble_sort(array, size);
    print_array(array,size);

    
    return 0;
}