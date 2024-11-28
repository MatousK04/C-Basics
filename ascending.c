#include<stdio.h>
int main()
#define SIZE 3
{
    int x;
    int y;
    int z;
    int i;
    int A[SIZE];
    printf("ENTER 3 DIGITS!\n");
    for(i = 0; i<SIZE; i++)
    {
        scanf("%d",&A[i]);
    }
    for(i = 0; i<SIZE; i++)
    {
        if(A[0]>A[1])
        {
            x = A[1];
            A[1] = A[0];
            A[0] = x;
        }
        if(A[1]>A[2])
        {
            y = A[1];
            A[1] = A[2];
            A[2] = y;
        }
        if(A[0]>A[2])
        {
            z = A[0];
            A[0] = A[2];
            A[0] = z;
        }
    }
    for(i = 0; i<SIZE; i++)
    {
        printf("%d,",A[i]);
    }

    return 0;
}