#include<stdio.h>

int main(){
    int n, m, save = -1;
    printf("nhap n: "); scanf("%d", &n);
    printf("nhap m: "); scamf("%d", &m);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
        if(arr[i] == m){
            save = i;
        }
    }

    if(save != -1){
        printf("dap an: %d", save);
    } else {
        printf("khong co trong mang ");
    }
    
    

    return 0;
}