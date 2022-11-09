// breadth first search for graphs
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int n;             // number of vertices in the graph
int adj[MAX][MAX]; // adjacency matrix
int visited[MAX];  // array to mark visited vertices

void BFS(int v)
{
    int i;
    int queue[MAX], front, rear;
    front = rear = -1;
    printf("%d ", v);
    visited[v] = 1;
    queue[++rear] = v;
    while (front != rear)
    {
        v = queue[++front];
        for (i = 1; i <= n; i++)
            if (adj[v][i] && !visited[i])
            {
                printf("%d ", i);
                visited[i] = 1;
                queue[++rear] = i;
            }
    }
}

void read_graph()
{
    int i, max_edges, v1, v2, origin;
    printf("Enter number of vertices : ");
    scanf("%d", &n);
    max_edges = n * (n - 1);
    for (i = 1; i <= max_edges; i++)
    {
        printf("Enter edge %d( -1 -1 to quit ) : ", i);
        scanf("%d %d", &v1, &v2);
        if ((v1 == -1) && (v2 == -1))
            break;
        if (v1 >= n || v2 >= n || v1 < 0 || v2 < 0)
        {
            printf("Invalid edge!");
            i--;
        }
        else
            insert_edge(v1, v2);
    }
}

void insert_edge(int v1, int v2)
{
    adj[v1][v2] = 1;
    adj[v2][v1] = 1;
}

int main()
{
    int i;
    read_graph();
    for (i = 0; i < n; i++)
        visited[i] = 0;
    printf("Enter origin : ");
    scanf("%d", &i);
    BFS(i);
    return 0;
}
// Output:

// Enter number of vertices : 4

// Enter edge 1( -1 -1 to quit ) : 0 1

// Enter edge 2( -1 -1 to quit ) : 0 2

// Enter edge 3( -1 -1 to quit ) : 1 2

// Enter edge 4( -1 -1 to quit ) : 2 3

// Enter edge 5( -1 -1 to quit ) : 3 0

// Enter edge 6( -1 -1 to quit ) : -1 -1

// Enter origin : 0

// 0 1 2 3