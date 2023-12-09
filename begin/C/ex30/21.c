#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, arr[100], brr[100], crr[200];
    printf("nhap n: ");
    scanf("%d", &n);
    printf("nhap m: ");
    scanf("%d", &m);
    int h = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &brr[i]);
    }
    for (int i = 0; i < m+n; i++)
    {
        if(i < n){
            crr[i] = arr[h];
            h++;
        } else {
            crr[i] = brr[k];
            k++;
        }
        printf("%d ", crr[i]);
    }
    
    

    return 0;
}