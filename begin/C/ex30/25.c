#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, arr[100][100], brr[100][100];
    printf("nhap n: ");
    scanf("%d", &n);
    printf("nhap m: ");
    scanf("%d", &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &brr[i][j]);
        }
    }
    int k;
    if (n > m)
    {
        k = n;
    }
    else
    {
        k = m;
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            printf("%d ", arr[i][j] + brr[i][j]);
        }
        printf("\n");
    }
    return 0;
}