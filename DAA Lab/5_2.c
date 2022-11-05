#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int *arr, int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    int temp;
    for (int j = p; j < r; j++)
    {
        if (arr[j] < x)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i + 1];
    arr[i + 1] = arr[r];
    arr[r] = temp;
    return i + 1;
}
void quicksort(int *arr, int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r); // pivot finding
        quicksort(arr, p, q - 1);     /// left sub array
        quicksort(arr, q + 1, r);     // right sub array
    }
}
void swap(int*a,int*b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void reverse(int *arr)
{
    int i = 0, j = 100000 - 1, temp;
    for (; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}




int main()
{
    int sz;
    printf("Enter the size of array::");
    scanf("%d", &sz);
    int randArray[sz], i;
    for (i = 0; i < sz; i++)
        randArray[i] = rand() % 10000;
    printf("\nElements of the array::");
    // printf("Hello");
    clock_t t;
    t = clock();

    // printf("Given array is \n");
    // printArray(randArray,sz);

    quicksort(randArray, 0, sz - 1);
    double time_taken = ((double)t / CLOCKS_PER_SEC);
    printf("\nTime taken=%f secs\n\n", time_taken);

   // reverse(randArray, sz);
    reverse(randArray);
    quicksort(randArray, 0, sz - 1);

    // printf("\nSorted array is \n");
    // printArray(randArray, sz);
    return 0;
}