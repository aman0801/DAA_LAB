#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// bubble sort and insertion sort
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void reverse(int arr[],int n){
    for(int i=0;i<n/2;i++){
        swap(&arr[i],&arr[n-i-1]);
    }
   // printf("Yes done");
}
void InsertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (temp < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d\n", arr[i]);
    }
}
int main()
{
    int sz;
    printf("Enter the size of array::");
    scanf("%d", &sz);
    int randArray[sz], i;
    for (i = 0; i < sz; i++)
        randArray[i] = rand() % 100;
    printf("\nElements of the array::");
    // printf("Hello");
    clock_t t;
    t = clock();
    clock_t t1;
    t1 = clock();
    printf("Before Insertion");
     printarr(randArray,sz);
    InsertionSort(randArray, sz);
    InsertionSort(randArray,sz);
    reverse(randArray,sz);
    printarr(randArray,sz);
    InsertionSort(randArray,sz);
    // printf("after insertion");
     printarr(randArray,sz);
    double time_taken = ((double)t / CLOCKS_PER_SEC);
    printf("\nTime taken=%f secs\n\n", time_taken);

    return 0;
}