#include <stdio.h>

int palindrome(int num)
{
    int remainder, reverse = 0;
    while (num > 0)
    {
        remainder = num % 10;
        reverse = reverse * 10 + remainder;
        num /= 10;
    }
    return reverse;
}
int main()
{
    int num, reverse=0;
    
    printf("Enter an integer \n");
    scanf("%d", &num);
    reverse = palindrome(num);
    printf("reverse %d", reverse);
    
    if (num == reverse){
        printf("Number is a palindrome \n");}
    else{
        printf("Number is not a palindrome \n");}
        return 0;
}