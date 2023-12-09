#include <stdio.h>
#include <math.h>

int main()
{
    int n, m, arr[100];
    printf("nhap n: ");
    scanf("%d", &n);
    printf("nhap m: ");
    scanf("%d", &m);
    int save;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if(i == m) save = arr[i];
    }
    printf("%d", save);

    
    

    return 0;
}