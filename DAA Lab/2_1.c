#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
     clock_t t;
    t=clock();
    // // solution 1
    // int a;
    // printf("Give number");
    // scanf("%d",&a);
    // if(a%2==0){
    //     printf("Even");
    // }else{
    //     printf("odd");
    // }

    // solution 2
    // int a;
    //  int n=0;
    // printf("Give number");
    // scanf("%d", &a);
    // for (int i = 0; i <= n; i++)
    // {
    //     if (a % 2 == 0)
    //     {
    //         printf("Even");
    //        // break;
    //     }
    //     else
    //     {
    //         printf("odd");
    //     }
    // }

    //solution 3
    // int a;
    // printf("Give number");
    // scanf("%d",&a);
    // int n=1;
    // while (n<=1)
    // {
    //     /* code */ 
    //     if (a % 2 == 0)
    //     {
    //         printf("Even");
    //        // break;
    //        n++;
    //     }
    //     else
    //     {
    //         printf("odd");
    //         n++;
    //     }
    // }
    double time_taken=((double)t/CLOCKS_PER_SEC);
    printf("\nTime taken=%f secs\n\n",time_taken);
    


    return 0;
}