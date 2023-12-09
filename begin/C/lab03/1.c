#include <stdio.h>

int giaithua(int n){
    int tich = 1;
    for (int i = 1; i <= n; i++)
    {
        tich*=i;
    }
    return tich;
}

float a(int n){
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i/2;
    }
    return sum;
}

int b(int n){
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (2*i + 1)
    }
    return sum;
}
int c(int n){
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += giaithua(i) + 1;
    }
    return sum;
}
int d(int n){
    int sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum *= giaithua(i);
    }
    return sum;
}
float e(int n){
    float sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum *= (2/3)*i;
    }
    return sum;
}
int main(){
    float A, E;
    int B, C, D, n;
    printf("nhap n: "); scanf("%d", &n);

    A = a(n);
    B = b(n);
    C = c(n);
    D = d(n);
    E = e(n);

    printf("dap so cau a: %d", A);
    printf("dap so cau b: %d", B);
    printf("dap so cau c: %d", C);
    printf("dap so cau d: %d", D);
    printf("dap so cau e: %d", E);

    return 0;
}