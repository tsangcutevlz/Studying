#include <stdio.h>
#include <math.h>

void deleteDuplicate(int arr[], int n, int brr[]){
    int h = 0;
    for (int i = 0; i < n; i++)
    {
        int flag = 0;
        for (int j = i+1; j < n; j++)
        {   
            if(arr[i] == arr[j]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            brr[h] = arr[i];
            h++;
        }
    }
    for (int i = 0; i < h; i++)
    {
        printf("%d ", brr[i]);
    }
}

int main()
{
    int n, arr[100], brr[1000];
    printf("nhap n: ");
    scanf("%d", &n);
    for (int i = 0; i <n; i++)
    {
        scanf("%d", &arr[i]);
    }
    deleteDuplicate(arr, n, brr);
    return 0;
}