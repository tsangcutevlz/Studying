#include <stdio.h>
#include <math.h>
void swap(int*a, int*b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, arr[100];
    printf("nhap n: ");
    scanf("%d", &n);
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = n-1; i > n/2; i--)
    {
        swap(&arr[i], &arr[j]);
        j++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    

    return 0;
}