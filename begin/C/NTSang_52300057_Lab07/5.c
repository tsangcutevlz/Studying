#include<stdio.h>
#include <string.h>
int main(){
    int n;
    char s[100];
    char arr[100][100];
    printf("nhap so phan tu mang: "); scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(strcmp(arr[i], arr[j]) < 0){
                strcpy(s, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], s);
            }
        }
        
    }
    printf("danh sach hoc sinh sau khi da sort: \n ");
    for (int i = 0; i < n; i++)
    {
        printf("%s ", arr[i]);
    }
    
    
    return 0;
}