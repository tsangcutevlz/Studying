#include <stdio.h>

int findStep(int n)
{
    if(n == 0) return 1;
    if(n < 0) return 0;
    return findStep(n-1) + findStep(n-2) + findStep(n-3);
}

int main()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    int output = findStep(n);
    printf("ket qua: %d", output);
    return 0;
}