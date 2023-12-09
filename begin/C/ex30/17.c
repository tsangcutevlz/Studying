#include <stdio.h>
#include <math.h>

int main()
{
    int n, k, arr[100];
    printf("nhap n: ");
    scanf("%d", &n);
    printf("nhap vi tri can xoa: ");
    scanf("%d", &k);

    for (int i = 0; i <n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n-1; i++)
    {
        if(i>=k){
            printf("%d ", arr[i+1]);
        } else {
            printf("%d ", arr[i]);

        }
    }
    
    return 0;
}