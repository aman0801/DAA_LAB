#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int reverse(int a[],int n)
{
    int temp;
    for(int i=0;i<n/2;i++)
    {
        temp=a[i];
        a[i]=a[n-i];
        a[n-i]=temp;
    }
    return 0;
}
void swap(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void max_heapify(int arr[],int n,int i)
{
    int largest=i,temp;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[left]>arr[largest])
        largest=left;
    if(right<n&&arr[right]>arr[largest])
        largest=right;
    if(largest!=i)
    {
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        max_heapify(arr,n,largest);
    }
}

void build_max_heap(int arr,int n)
{
    for(int i=n/2+1;i>=0;i--)
        max_heapify(arr,n,i);
}

void heap_sort(int arr[],int n)
{
    int temp;
    build_max_heap(arr,n);
    for(int i=n-1;i>=0;i--)
    {
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        max_heapify(arr,i,0);
    }
}

int max_heap_extract(int arr[],int n)
{
    int temp=arr[n];
    n--;
    return temp;
}

void change_max_heap(int arr[],int n,int i,int new)
{
    arr[i]=new;
    heap_sort(arr,n);
}

void insert_max_heap(int arr[],int n,int a)
{
    n++;
    change_max_heap(arr,n,n,a);
}

int delete_max_heap(int arr[],int n,int i)
{
    int temp=arr[i];
    arr[i]=arr[n];
    n--;
    heap_sort(arr,n);
}

void main()
{
    clock_t t1,t2,t3,t4;
    srand(time(0));
    int x,e1,e2,value,new,count=0,n=5000,a[100000];
    for(int i=1;i<100000;i++)
        a[i]=rand();
    t1=clock();
    heap_sort(a,n);
    t2=clock();
    heap_sort(a,n);
    t3=clock();
    reverse(a,n);
    heap_sort(a,n);
    t4=clock();
    printf("\n0-Quit\n1-Enter n random numbers in array\n2-Display Array\n3-Sort Array Max Heap\n4-Reverse Array\n5-Time Complexity to sort Random Array\n");
    printf("6-Time Complexity to sort Sorted Array\n7-Time Complexity to sort Reverse Array\n8-Table for Time Complexity for all cases\n9-Extract Largest element\n10-Change value at node\n11-Insert Element\n12-Delete element\n");
    scanf("%d",&x);
    while(count==0)
    {
        switch(x)
        {
            case 0:
                count=1;
                break;
            case 1:
                for(int i=0;i<n;i++)
                    a[i]=rand();
                    break;
            case 2:
                for(int i=0;i<n;i++)
                    printf("%d\n",a[i]);
                break;
            case 3:
                heap_sort(a,n);
                break;
            case 4:
                reverse(a,n);
                break;
            case 5:
                printf("Time taken to sort random array=%fsecs",(double)(t2-t1)/CLOCKS_PER_SEC);
                break;
            case 6:
                printf("Time Taken to sort sorted array=%fsecs",(double)(t3-t2)/CLOCKS_PER_SEC);
                break;
            case 7:
                printf("Time taken to sort reverse array=%fsecs",(double)(t4-t3)/CLOCKS_PER_SEC);
                break;
            case 8:
                printf("No. of elements|Random Array|Sorted Array|Reverse Array\n");
                printf("\t%d   |%f    |%f    |%f\n",n,(double)(t2-t1)/CLOCKS_PER_SEC,(double)(t3-t2)/CLOCKS_PER_SEC,(double)(t4-t3)/CLOCKS_PER_SEC);
                for(n=10000;n<=50000;n+=5000)
                {
                    for(int i=0;i<n;i++)
                        a[i]=rand();
                    t1=clock();
                    heap_sort(a,n);
                    t2=clock();
                    heap_sort(a,n);
                    t3=clock();
                    reverse(a,n);
                    heap_sort(a,n);
                    t4=clock();
                    printf("\t%d  |%f    |%f    |%f\n",n,(double)(t2-t1)/CLOCKS_PER_SEC,(double)(t3-t2)/CLOCKS_PER_SEC,(double)(t4-t3)/CLOCKS_PER_SEC);
                }
                break;
            case 9:
                printf("\n%d\n",max_heap_extract(a,n));
                break;
            case 10:
                printf("Enter element no. and new value:");
                scanf("%d%d",&e1,&value);
                change_max_heap(a,n,e1,value);
                break;
            case 11:
                printf("Enter new element:");
                scanf("%d",&new);
                insert_max_heap(a,n,new);
                break;
            case 12:
                printf("Enter element no. to be deleted");
                scanf("%d",&e2);
                printf("\nDeleted no. is %d\n",delete_max_heap(a,n,e2));
                break;
            default:
                printf("Enter Valid option\n");
                break;
        }
        if(count==0)
        {
            printf("\n0-Quit\n1-Enter n random numbers in array\n2-Display Array\n3-Sort Array Max Heap\n4-Reverse Array\n5-Time Complexity to sort Random Array\n");
            printf("6-Time Complexity to sort Sorted Array\n7-Time Complexity to sort Reverse Array\n8-Table for Time Complexity for all cases\n9-Extract Largest element\n10-Change value at node\n11-Insert Element\n12-Delete element\n");
            scanf("%d",&x);
        }
    }
}