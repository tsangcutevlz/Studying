#include <stdio.h>
#include <math.h>
int x = 0;
int f(){
    if (x == 0) return x + 1;
    else return x- 1;
}
int g(){
    return x++;
}
int main()
{
    int i = (f() + g()) | g();
    int j = (f() + g()) | g();
    printf("%d\n", i);
    printf("%d\n", j);

    return 0;
}