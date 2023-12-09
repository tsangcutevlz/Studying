#include <stdio.h>
#include <math.h>

int check(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if(n % i == 0){
            sum+=i;
        }
    }
    if(n == sum){
        return 1;
    } 
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