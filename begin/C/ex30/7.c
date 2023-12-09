#include <stdio.h>
#include <math.h>

int count(int n)
{
    int dem = 0;
    while (n > 0)
    {
        dem++;
        n /= 10;
    }
    return dem;
}

int check(int n)
{
    int k = count(n);
    int save = n;
    int sum = 0;
    if (n==1) return true;
    if(n<10) return 0;
    while (n > 0)
    {
        sum += pow(n % 10, k);
        n /= 10;
    }
    if (save == sum)
        return 1;
    return 0;
}

void print(int n){
    for (int i = 1; i <= n; i++)
    {
        if(check(i)){
            printf("%d ", i);
        }
    }
    
}

int main()
{
    int n;
    scanf("%d", &n);
    print(n);
    return 0;
}