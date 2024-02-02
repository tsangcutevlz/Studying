#include <stdio.h>

void main()
{
    void foo();
    void f(){
        foo();
    }
    f();
}
void foo(){
    printf("2");
}