#include <stdio.h>

int count(int n) {
    int save = 0;
    for (int quarters = 0; quarters <= n / 25; quarters++) {
        for (int dimes = 0; dimes <= (n - quarters * 25) / 10; dimes++) {
            for (int nickels = 0; nickels <= (n - quarters * 25 - dimes * 10) / 5; nickels++) {
                save++;
            }
        }
    }
    return save;
}
int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);

    int save = count(n);
    printf("tong so cach: %d", save);


    return 0;
}
