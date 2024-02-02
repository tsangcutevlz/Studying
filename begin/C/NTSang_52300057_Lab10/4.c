#include <stdio.h>

union Sti{
    // int nu;
    char m;
};

int main(){
    union Sti s;
    printf("%d", sizeof(s));
    return 0;
}