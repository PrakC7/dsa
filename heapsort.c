#include <stdio.h>

void maxHeapify_top(int A[], int n, int i)
{
    int P_Node = i;
    int left = 2*P_Node + 1;
    int right = 2*P_Node + 2;

    if(left < n && A[left] > A[P_Node])
        P_Node = left;

    if(right < n && A[right] > A[P_Node])
        P_Node = right;

    if(P_Node != i)
    {
        int temp = A[i];
        A[i] = A[P_Node];
        A[P_Node] = temp;
        maxHeapify_top(A, n, P_Node);
    }
}

void buildHeap(int A[], int n)
{
    for(int i = n/2 - 1; i >= 0; i--)
        maxHeapify_top(A, n, i);
}

int main()
{
    int A[9], P_Node;

    for(int i = 0; i < 9; i++)
        scanf("%d", &A[i]);

    buildHeap(A, 9);

    scanf("%d", &P_Node);

    A[0] = P_Node;
    maxHeapify_top(A, 9, 0);

    for(int i = 0; i < 9; i++)
        printf("%d ", A[i]);

    return 0;
}
