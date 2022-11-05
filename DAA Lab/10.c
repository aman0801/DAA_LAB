
#include <limits.h>
#include <stdio.h>


int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;


	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k)
				+ MatrixChainOrder(p, k + 1, j)
				+ p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}

	// Return minimum count
	return min;
}

// Driver code
int main()
{
	int n;
    printf("give n\n");
    scanf("%d", &n);
    int arr[n];
	printf("give array\n");
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    int N = sizeof(arr) / sizeof(arr[0]);
    printf("Minimum number of multiplications is %d ", MatrixChainOrder(arr, 1, N - 1));
	// getchar();
    return 0;
}
//1*2
//2*3
//3*1


