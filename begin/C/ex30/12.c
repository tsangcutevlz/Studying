#include <stdio.h>
#include <math.h>

int main()
{
    int n, arr[100];
    printf("nhap n: ");
    scanf("%d", &n);
    int min;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(i == 0){
            min = arr[0];
            continue;
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    printf("min la: %d", min);
    
    return 0;
}