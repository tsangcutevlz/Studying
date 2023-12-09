#include <stdio.h>
#include <math.h>

int main()
{
    int n, y = 0, w = 0;
    printf("nhap n: ");
    scanf("%d", &n);
    int save = n;
    while (n >= 365)
    {
        n -= 365;
        y++;
    }
    while (n >= 7)
    {
        n -= 7;
        w++;
    }
    printf("%d = %dy %dw %dd", save, y, w, n);
    return 0;
}