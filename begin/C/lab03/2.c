#include <stdio.h>

int main(){

    int n;
    printf("nhap n: "); scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }
    min = arr[0];
    max = arr[0];

    for (int i = 0; i < n - 1; i++)
    {
        if(arr[i] < arr[i+1]){
            max = arr[i+1];
        }
        if(arr[i] > arr[i+1]){
            min = arr[i+1];
        }
    }

    printf("max la: %d\n", max);
    printf("min la: %d", min);
    
    

    return 0;
}