#include <stdio.h>
#include <math.h>

int countDigits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        n /= 10;
    }
    return count;
}

int check(int n)
{
    int save = 0;
    int digits = countDigits(n);
    while (n > 0)
    {
        save += pow(n % 10, digits);
        n /= 10;
    }
    return save;
}

int main()
{
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if(i == check(i)){
            printf("%d ", i);
        }
    }
    

    return 0;
}