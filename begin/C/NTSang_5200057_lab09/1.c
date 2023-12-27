#include <stdio.h>

int main()
{
    FILE *inputFile, *outputFile;

    if ((inputFile = fopen("input01.txt", "r")) == NULL)
    {
        printf("Khong the mo tap tin input.txt\n");
        perror("Loi khi mo tap tin: ");
        return 0;
    }
    if ((outputFile = fopen("output01.txt", "w")) == NULL)
    {
        printf("Khong the mo tap tin output01.txt\n");
        perror("Loi khi mo tap tin: ");
        return 0;
    }

    int arraySize;
    fscanf(inputFile, "%d", &arraySize);
    int arr[arraySize];
    int sum = 0;
    for (int i = 0; i < arraySize; i++)
    {
        fscanf(inputFile, "%d", &arr[i]);
        sum += arr[i];
    }
    
    fprintf(outputFile, "sum: %d", sum);

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
