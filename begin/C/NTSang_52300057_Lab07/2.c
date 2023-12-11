#include<stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int x, int y, int value){
    while(x <= y){
        int z = (x + y) / 2;
        if(arr[z] == value){
            return z;
        }
        else if (arr[z] < value){
            x = z + 1 ;
        } 
        else {
            y = z - 1;
        }
    }
    return -1;
}

int main(){
    int n, m, saveI = -1;
    printf("nhap so phan tu mang: "); scanf("%d", &n);
    printf("nhap phan tu can tim: "); scanf("%d", &m);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("nhap phan tu mang thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    bubbleSort(arr, n);
    saveI = binarySearch(arr, 0, n - 1, m);
    if(saveI != -1){
        printf("%d o vi tri thu %d trong mang", m, saveI + 1);
    } else {
        printf("khong co phan tu trong mang");
    }
    return 0;
}