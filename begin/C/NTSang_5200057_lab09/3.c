#include <stdio.h>
#include <string.h>
int main()
{
    FILE *inputFile, *outputFile;
    char fileName[100];
    printf("enter a file name: ");
    scanf("%s", &fileName);

    if ((inputFile = fopen(fileName, "r")) == NULL)
    {
        printf("Khong the mo tap tin input.inp\n");
        perror("Loi khi mo tap tin: ");
        return 0;
    }
    if ((outputFile = fopen("output03.txt", "w")) == NULL)
    {
        printf("Khong the mo tap tin output01.txt\n");
        perror("Loi khi mo tap tin: ");
        return 0;
    }
    int n;
    fscanf(inputFile, "%d", &n);
    int search;

    printf("----- Menu ------\n");
    printf("1. Binary Search \n");
    printf("2. Normal Search  \n");
    printf("-----------------\n");
    printf("choose one of these search algorithms\n");
    scanf("%d", &search);
    int value;
    printf("enter a value to search for\n");
    scanf("%d", &value);
    int position = -1;
    switch (search)
    {
    case 1:
    {
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            int num;
            fscanf(inputFile, "%d", &num);
            if (num == value)
            {
                position = mid + 1;
                break;
            }
            else if (num < value)
            {
                left = mid + 1;
            }
            else
            {
                right = mid + 1;
            }
        }
        break;
    }
    case 2:
    {
        int num;

        for (int i = 0; i < n; i++)
        {
            fscanf(inputFile, "%d", &num);
            if (num == value){
                position = i + 1;
                break;
            }
        }
    }
    }

    if(position == -1 ){
        fprintf(outputFile, "Not Found!!!\n"); 
    } else {
        fprintf(outputFile, "Position: %d", position); 
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
