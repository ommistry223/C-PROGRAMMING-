#include<stdio.h>
void BubbleShort(int A[],int n)
{
    int i,j ,temp;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}
int main()
{
    int A[5],n;
    n=sizeof(A)/sizeof(A[0]);

    for(int i = 0; i < 5; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &A[i]);
    }
    printf("There is Before Bubble Short Enter element is :");
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }

    BubbleShort(A,n);
    printf("\nThere is After Bubble Short Enter element is :");
    for(int i = 0; i < 5; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    return 0;
}
