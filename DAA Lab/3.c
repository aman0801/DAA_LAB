#include <stdio.h>
#include <stdlib.h>
#include <time.h>   
//#include <limits.h>
//selection sort 
void swap(int*a,int*b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void selectionsort(int arr[],int n){
   int i,j,min;
    for ( i = 0; i < n-1; i++)
    {
        
        min=i;  
        for( j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;           
            }
            swap(&arr[min],&arr[i]); 
        }    
    }
    //printf("yes done");
    
}
void printarr(int arr[],int n){
    for (int i = 0; i<n; i++)
    {
        printf(" %d\n",arr[i]);
    }
    
}
void reverse(int arr[],int n){
    for(int i=0;i<n/2;i++){
        swap(&arr[i],&arr[n-i-1]);
    }
   // printf("Yes done");
}
int main(){
     int sz;
   printf("Enter the size of array::");
   scanf("%d",&sz);
   int randArray[sz],i;
   for(i=0;i<sz;i++)
     randArray[i]=rand()%100;
      printf("\nElements of the array::");
//    for(i=0;i<sz;i++)
//    {
//      printf("\nElement number %d::%d",i+1,randArray[i]);
//    }
clock_t t;
    t=clock();
    clock_t t1;
    t1=clock();
    clock_t t2;
    t2=clock();
    printarr(randArray,sz);
    selectionsort(randArray,sz);
    printarr(randArray,sz);
    double time_taken=((double)t/CLOCKS_PER_SEC);
    printf("\nTime taken=%f secs\n\n",time_taken);
    selectionsort(randArray,sz);
    printarr(randArray,sz);
    double time_taken_1=((double)t1/CLOCKS_PER_SEC);
    printf("\nTime taken=%f secs\n\n",time_taken_1);
    reverse(randArray,sz);
    printarr(randArray,sz);
    double time_taken_2=((double)t2/CLOCKS_PER_SEC);
    printf("\nTime taken=%f secs\n\n",time_taken_2);
    return 0;
}