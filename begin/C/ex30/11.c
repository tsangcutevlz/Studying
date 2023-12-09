#include <stdio.h>
#include <math.h>

int main()
{
    int n, arr[100];
    printf("nhap n: ");
    scanf("%d", &n);
    int max;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(i == 0){
            max = arr[0];
            continue;
        }
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    printf("max la: %d", max);
    
    return 0;
}