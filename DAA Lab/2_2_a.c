#include <stdio.h>
#include <time.h>   // for clock_t, clock(), CLOCKS_PER_SEC

int GCDEuclid(int a, int b)
{
    int rem;
    while (a > 0)
    {
        rem = b % a;
        b = a;
        a = rem;
    }
    return b;
}

int consecIntegerChecking(int a, int b)
{
    int t;

    if (a > b)
        t = b;
    else
        t = a;
    while (t > 0)
    {
        if (a % t == 0 && b % t == 0)
        {
            return t;
        }
        else
        {
            t--;
        }
    }
    return 0;
}

int primarySchoolMethod(int num1, int num2)
{
    int factor1, factor2;
    int product = 1;

    for (factor1 = 2, factor2 = 2; num1 >= factor1, num2 >= factor2; factor1++, factor2++)
    {
        while (num1 % factor1 == 0 && num2 % factor2 == 0)
        {
            num1 = num1 / factor1;
            num2 = num2 / factor2;

            product = product * factor1;
        }
    }
    return product;
}

int main()
{
    // to store the execution time of code

    clock_t begin = clock();
    // do some stuff here

    // int a, b;
    // printf("Enter value of a and b = ");
    // scanf("%d %d", &a, &b);

    printf("\nGCD of %d and %d by Euclid's algorithm = %d\n", 1621234375, 75, GCDEuclid(162375, 75));

    printf("\nGCD of %d and %d by Consecutive integer checking algorithm = %d\n", 1621234375, 75, consecIntegerChecking(162375, 75));

    printf("\nGCD of %d and %d by using prime factorization method = %d\n", 1621234375, 75, primarySchoolMethod(162375, 75));

    clock_t end = clock();
    
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nThe elapsed time is %f seconds", time_spent);

    return 0;
}
