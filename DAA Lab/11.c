#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX 100

typedef struct node {
    int data;
    struct node *left, *right;
} node;

node *newNode(int data) {
    node *temp = (node *) malloc(sizeof(node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d", arr[i]);
    printf("\n");
}

void printCodes(node *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d: ", root->data);
        printArray(arr, top);
    }
}

void huffman(int data[], int freq[], int n) {
    node *left, *right, *top;
    int i, j;
    node *arr[n];
    for (i = 0; i < n; i++)
        arr[i] = newNode(data[i]);
    for (i = 0; i < n - 1; i++) {
        left = arr[0];
        j = 0;
        while (j < n - i - 1) {
            arr[j] = arr[j + 1];
            j++;
        }
        right = arr[0];
        j = 0;
        while (j < n - i - 2) {
            arr[j] = arr[j + 1];
            j++;
        }
        top = newNode(left->data + right->data);
        top->left = left;
        top->right = right;
        arr[n - i - 2] = top;
    }
    int arr1[MAX], top1 = 0;
    printCodes(arr[0], arr1, top1);
}

int main() {
    int n, i;
    printf("Enter the number of characters: ");
    scanf("%d", &n);
    int data[n], freq[n];
    printf("Enter the characters: ");
    for (i = 0; i < n; i++)
        scanf("%d", &data[i]);
    printf("Enter the frequencies of the characters: ");
    for (i = 0; i < n; i++)
        scanf("%d", &freq[i]);
    huffman(data, freq, n);
    return 0;
}