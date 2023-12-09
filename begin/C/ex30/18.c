#include <stdio.h>
#include <math.h>

int countDuplicate(int arr[], int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {   
            if(arr[i] == arr[j]){
                count++;
                break;
            }
        }
    }
    return count;
}

int main()
{
    int n, arr[100];
    printf("nhap n: ");
    scanf("%d", &n);
    for (int i = 0; i <n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int countt = countDuplicate(arr, n);
    printf("total: %d", countt);
    return 0;
}