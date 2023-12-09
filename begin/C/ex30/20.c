#include <stdio.h>
#include <math.h>

void shellSort(int a[], int n){
	int interval, i, j, temp;
	for(interval = n/2; interval > 0; interval /= 2){
		for(i = interval; i < n; i++){
			temp = a[i];
			for(j = i; j >= interval && a[j - interval] > temp; j -= interval){
				a[j] = a[j - interval];				
			}
			a[j] = temp;
		}
    }
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
    shellSort(arr, n);
    int count = 1;
    for (int i = 0; i <= n; i++)
    {
        if(arr[i] == arr[i+1]){
            count++;
        } else {
            printf("[%d] xuat hien: [%d] lan \n", arr[i-1], count);
            count = 1;
        }
    }
    
    return 0;
}