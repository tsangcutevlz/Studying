#include<stdio.h>
#include<math.h>

int solve1a(int n){
    if (n == 0) return 0; 
    return (2*n - 1 ) + solve1a(n-1);
}

float solve1b(int n){
    if (n == 1) return 0.5;
    return (float)(n * 0.5) + solve1b(n-1);
}
int solve1c1(int n){
    if (n == 1) return 1;
    return n * solve1c1(n-1);
}
int solve1c2(int n){
    if (n == 0) return 0;
    return solve1c1(n) + solve1c2(n-1);
}
float solve1d(int n){
    if (n == 0) return 0;
    return (float)(sqrt(n)) + solve1d(n-1);
}
int solve1e(int n){
    if (n == 0) return 1;
    return solve1e(n) * solve1c1(n-1);
}

int main(){
    int n; printf("nhap n: "); scanf("%d", &n);
    int output1a = solve1a(n);
    float output1b = solve1b(n);
    int output1c = solve1c2(n);
    float output1d = solve1d(n);
    int output1e = solve1e(n);
    printf("ket qua 1a la: %d\n", output1a);
    printf("ket qua 1b la: %f\n", output1b);
    printf("ket qua 1c la: %d\n", output1c);
    printf("ket qua 1d la: %f\n", output1d);
    printf("ket qua 1e la: %d\n", output1e);
    return 0;
}