#include <stdio.h>
#include <string.h>
int main()
{
    FILE *inputFile, *outputFile;
    char fileName[100];

    if ((inputFile = fopen("input02.txt", "r")) == NULL)
    {
        printf("Khong the mo tap tin input.inp\n");
        perror("Loi khi mo tap tin: ");
        return 0;
    }
    if ((outputFile = fopen("output02.txt", "w")) == NULL)
    {
        printf("Khong the mo tap tin output01.txt\n");
        perror("Loi khi mo tap tin: ");
        return 0;
    }

    int arraySize;
    fscanf(inputFile, "%d", &arraySize);
    int arr[arraySize];
    char save[100];
    for (int i = 0; i < arraySize; i++)
    {
        fscanf(inputFile, "%s", save);
        arr[i] = strlen(save);
        fprintf(outputFile, "%d\n", arr[i]);
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
