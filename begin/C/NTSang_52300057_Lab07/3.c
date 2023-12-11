#include<stdio.h>

void swap(int*a, int*b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int arr[], int n) {
    int i, j, maxIndex;
    for (i = 0; i < n - 1; i++) {
        maxIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}

int main(){
    int n, m;
    printf("nhap so phan tu mang: "); scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("nhap phan tu mang thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    printf("\nmang sau khi da sort: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}