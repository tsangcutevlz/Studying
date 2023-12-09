#include <stdio.h>
#include <math.h>

int check(int n)
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0){
            return 0;
        }
    }
    return 1;
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