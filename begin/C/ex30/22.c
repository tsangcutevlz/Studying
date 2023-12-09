#include <stdio.h>
#include <math.h>

int main()
{
    int n,arr[100], brr[100], crr[100];
    printf("nhap n: ");
    scanf("%d", &n);
    int h = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i] % 2 == 0){
            brr[h] = arr[i]; h++;
        } else {
            crr[k] = arr[i]; k++;
        }
    }
    for (int i = 0; i < h; i++)
    {
        printf("%d ", brr[i]);
    }
    printf("\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d ", crr[i]);
    }
    
    

    

    
    

    return 0;
}