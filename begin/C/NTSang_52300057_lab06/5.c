#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printPermutations(int arr[], int size, int n)
{
    if (size == 1)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            swap(&arr[i], &arr[size - 1]);
            printPermutations(arr, size - 1, n);
            swap(&arr[i], &arr[size - 1]);
        }
    }
}

int main()
{
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    int digits[10];
    int count = 0;
    while (n > 0)
    {
        digits[count] = n % 10;
        n /= 10;
        count++;
    }
    printf("Các hoán vị là:\n");
    printPermutations(digits, count, count);

    return 0;
}
