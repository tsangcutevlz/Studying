include <stdio.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void printPermu(char*chuoi, int start, int end)
{
    if(start == end){
        printf("%s", chuoi);
        return;
    }

    for(int i = start; i < end; i++){
        swap(&chuoi[start], &chuoi[i]);
        printPermu(chuoi, start + 1, end);
        swap(&chuoi[start], &chuoi[i]);
    }
}

int main()
{
    char str[100];
    printf("nhap chuoi: ");
    fgets(str,sizeof(str), stdin);
    printPermu(str, 0, strlen(str) - 1);

    return 0;
}