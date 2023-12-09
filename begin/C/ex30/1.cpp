#include <iostream>
using namespace std;

int giaithua(int n)
{
    if (n == 1)
        return 1;
    else
        return n * giaithua(n - 1);
}

float a(int n)
{
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum / 2;
}

int b(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += 2 * i + 1;
    }
    return sum;
}

float c(int n)
{
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (float) (i + 1) / (i + 2);
    }
    return sum;
}

int d(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += giaithua(i) + 1;
    }
    return sum;
}

int e(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int f(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += giaithua(i);
    }
    return sum;
}

float g(int n)
{
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum*2/3;
}

int h(int n)
{
}

int main()
{
    int n;
    cin >> n;
   cout << a(n) << endl;cout << b(n) << endl;cout << c(n) << endl;cout << d(n) << endl;cout << e(n) << endl;cout << f(n) << endl;cout << g(n) << endl;cout << h(n) << endl;

    return 0;
}