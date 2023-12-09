#include <stdio.h>
#include <math.h>


void insertionSort(int a[], int n){
    int index, value;
    for (int i = 1; i < n; i++)
    {
        int index = i;
        value = a[i];
        while( index > 0 && a[index-1] > value){
            a[index] = a[index-1];
            index--;
        }
        a[index] = value;
    }
}

int main()
{
    int n, arr[100];
    printf("nhap n: ");
    scanf("%d", &n);
    int save;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(i == m) save = arr[i];
    }
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    

    
    

    return 0;
}