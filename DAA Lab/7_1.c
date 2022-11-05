#include <stdio.h>
#include <stdlib.h>

// void swap(int *a, int *b)
// {
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }
// void reverse(int arr[], int n)
// {
//     for (int i = 0; i < n / 2; i++)
//     {
//         swap(&arr[i], &arr[n - i - 1]);
//     }
//     // printf("Yes done");
// }
// void BubbleSort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(&arr[j], &arr[j + 1]);
//             }
//         }
//     }
// }

int BinarySearch(int arr[],int h,int l,int x){
    // BubbleSort(arr,h);
    // int mid = (l+h)/2;
    int mid = (l + (h - l)) / 2;

    if(l<=h){
        if(arr[mid]==x){
            printf("h");
            return mid;
        }
         if(arr[mid]<x)
            return BinarySearch(arr,h,mid+1,x);
            else
              return BinarySearch(arr,mid-1,l,x);
    }
    return -1;
}





int main()
{
    int n;
    int x;
    printf("give number to find");
    scanf("%d",&x);
    printf("give size");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

   
   int b = BinarySearch(arr,n-1,0,x);
  
   printf("index is: %d",b);
    
    return 0;
}

// #include <stdio.h>
// #include<stdlib.h>
// void getdata(int *a,int n)
// {
//    for(int i=0; i<n;i++)
//    {
//      scanf("%d",&a[i]);
//    }
//    }
//    void insertionSort(int array[], int n) 
// { 
//     int i, element, j; 
//     for (i = 1; i < n; i++) 
//     { 
//     element = array[i];
//      j = i - 1; 
//     while (j >= 0 && array[j] > element) 
//     { 
//             array[j + 1] = array[j]; 
//             j = j - 1; 
//         } 
//         array[j + 1] = element; 
//     } 
//     }
// int binarySearch(int array[], int x, int low, int high) 
// {
//   if (high >= low) 
//   {
//     int mid = low + (high - low) / 2;
//     if (array[mid] == x)
//       return mid;
//     if (array[mid] > x)
//       return binarySearch(array, x, low, mid - 1);
//     return binarySearch(array, x, mid + 1, high);
//   }
//   return -1;
// }
// void display( int arr[], int n)
// {
// for(int i=0; i<n ;i++)
// printf("%d ",arr[i]);
// }
// int main() 
// {
// int n;
// printf("Enter size ");
// scanf("%d",&n);
//   int array[n];
//   getdata(array,n);
//   insertionSort(array,n);
//   display(array,n);
//   int x ;
//   printf("\nEnter search ");
//   scanf("%d",&x);
//   int result = binarySearch(array, x, 0, n - 1);
//   if (result == -1)
//     printf("Not found");
//   else
//     printf(" index %d", result);
// }