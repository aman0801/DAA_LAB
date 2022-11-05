#include<stdio.h>
#include<stdlib.h>
void activity(int s[],int f[],int n)
{
    int j=0;
    printf("%d ",j);
    int i;
    for(i=1;i<n;i++)
    {
        if(s[i]>=f[j])
        {
            printf("%d",i);
            j=i;
        }
    }
}
int main()
{
    int s[]={1,3,4,5,2,9};
    int f[]={5,7,8,9,10,14};
    int n = sizeof(s)/sizeof(s[0]);
    activity(s,f,n);
    return 0;
}