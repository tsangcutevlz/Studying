#include<stdio.h>

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
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == m){
            saveI = i;
        }
    }
    if(saveI != -1){
        printf("%d o vi tri thu %d trong mang", m, saveI);
    } else {
        printf("khong co phan tu trong mang");
    }
    return 0;
}