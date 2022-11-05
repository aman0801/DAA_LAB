// C program for Merge Sort 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int*a,int*b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}


void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}
void reverse(int arr[],int n){
    for(int i=0;i<n/2;i++){
        swap(&arr[i],&arr[n-i-1]);
    }
   // printf("Yes done");
}


void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	
	int L[n1], R[n2];

	
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		
		int m = l + (r - l) / 2;

		
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}


int main()
{
    clock_t t;
    t=clock();
    clock_t t1;
    t1=clock();
    clock_t t2;
    t2=clock();
	int sz;
    printf("Enter the size of array::");
    scanf("%d", &sz);
    int randArray[sz], i;
    for (i = 0; i < sz; i++)
        randArray[i] = rand() % 10000;
    printf("\nElements of the array::");
    // printarr(randArray,sz);
    mergeSort(randArray,0,sz);
    // printarr(randArray,sz);
    double time_taken=((double)t/CLOCKS_PER_SEC);
    printf("\nTime taken=%f secs\n\n",time_taken);
    mergeSort(randArray,0,sz);
    // printarr(randArray,sz);
    double time_taken_1=((double)t1/CLOCKS_PER_SEC);
    printf("\nTime taken=%f secs\n\n",time_taken_1);
    reverse(randArray,sz);
    mergeSort(randArray,0,sz);
    // printarr(randArray,sz);
    double time_taken_2=((double)t2/CLOCKS_PER_SEC);
    printf("\nTime taken=%f secs\n\n",time_taken_2);
	return 0;
}
