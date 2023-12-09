#include <stdio.h>
#include <math.h>
int main()
{
    int a, i = 0;
    int arr[20];
    printf("nhap a: ");
    scanf("%d", &a);
    while (a != 0)
    {
        if(a & 1){arr[i] = 1;} 
        else {arr[i] = 0;}
        a = a >> 1;
        i++;
    }
    for (int j = i-1; j >= 0 ; j--)
    {
        printf("%d", arr[j]);
    }
    return 0;
}