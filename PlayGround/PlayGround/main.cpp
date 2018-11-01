#include <stdio.h>
void insert_sort(int A[])
{
    int n, i, max, temp;
    n = sizeof(A) / sizeof(A[0]);
    while (n > 0)
    {
        max = 0;
        for (i = 1; i <= n; i++)
        {
            if (A[i] > A[max])
            {
                max = i;
            }
            temp = A[n];
            A[n] = A[i];
            A[i] = temp;
            n--;
        }
    }
}


int main(void) {
    
}
