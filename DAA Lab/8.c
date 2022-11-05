#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if(a>b){
        return a;
    }else{
        return b;
    }
}
int knapSack(int w, int wt[], int val[], int n)

{

    if (n == 0 || w == 0)
    {
        return 0;
    }

    if (wt[n-1] <= w)
    {
        return max(val[n - 1] + knapSack(w - wt[n - 1], wt, val, n - 1), knapSack(w, wt, val, n - 1));
    }

    else if (wt[n - 1] > w)
    {
        return knapSack(w, wt, val, n - 1);
    }
}
int main()
{
    int wt[] = {4, 5, 1};
    int val[] = {1, 2, 3};
    int a = knapSack(4, wt, val, 3);
    printf("the value of knapsack is %d", a);
    return 0;
}