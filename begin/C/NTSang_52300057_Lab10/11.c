#include <stdio.h>
int func(){
    return (double)(char) 5.0;
}
int main(){
    int k = func();
    printf("%d", k);
}