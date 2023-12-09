#include <stdio.h>
#include <math.h>

int main()
{
    int n, arr[100];
    printf("nhap n: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i] < 0)
            sum+=arr[i];
    }
    printf("sum la: %d", sum);
    
    return 0;
}