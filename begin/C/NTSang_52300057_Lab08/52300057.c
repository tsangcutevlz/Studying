#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Employee
{
    int id;
    char name[10];
    char sex[10];
    int birthyear;
    int phoneNumber;
    int salary;
};

int compareBirthyear(const void *a, const void *b)
{
    return ((struct Employee *)a)->birthyear - ((struct Employee *)b)->birthyear;
}
int compareSalary(const void *a, const void *b)
{
    return ((struct Employee *)a)->salary - ((struct Employee *)b)->salary;
}

int main()
{
    struct Employee arr[10];
    for (int i = 0; i < 10; i++)
    {

        arr[i].id = i;
        strcpy(arr[i].name, "sang");
        if (i % 2 == 0)
        {
            strcpy(arr[i].sex, "male");
        }
        else
        {
            strcpy(arr[i].sex, "female");
        }
        arr[i].birthyear = 2005 + (10 - i);
        arr[i].phoneNumber = 924093 + i;
        arr[i].salary = 400000 + 100000 * i;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("------ sinh vien %d: --------\n ", i + 1);
        printf("id: %d \n", arr[i].id);
        printf("name: %s \n", arr[i].name);
        printf("sex: %s \n", arr[i].sex);
        printf("birthyear: %d \n", arr[i].birthyear);
        printf("salary: %d \n", arr[i].salary);
        printf("\n \n");
    }

    int find;
    printf("nhap id can tim: ");
    scanf("%d", &find);
    for (int i = 0; i < 10; i++)
    {
        if (arr[i].id == find)
        {
            printf("---- thong tin sinh vien can tim la: ----\n");
            printf("id: %d \n", arr[i].id);
            printf("name: %s \n", arr[i].name);
            printf("sex: %s \n", arr[i].sex);
            printf("birthyear: %d \n", arr[i].birthyear);
            printf("salary: %d \n", arr[i].salary);
            printf("\n\n");
        }
    }
    int countMale = 0;
    int countFemale = 0;

    for (int i = 0; i < 10; i++)
    {
        if (strstr(arr[i].sex, "female"))
        {
            countFemale++;
        }
        else
        {
            countMale++;
        }
    }
    printf("amount of Female: %d\n", countFemale);
    printf("amount of Male: %d", countMale);
    printf("\n\n");
    printf("---- Sort the employee arrray in ascending order of BIRTHYEAR ---- \n \n");

    qsort(arr, 10, sizeof(struct Employee), compareBirthyear);

    for (int i = 0; i < 10; i++)
    {
        printf("------ sinh vien %d: --------\n ", i + 1);
        printf("id: %d \n", arr[i].id);
        printf("name: %s \n", arr[i].name);
        printf("sex: %s \n", arr[i].sex);
        printf("birthyear: %d \n", arr[i].birthyear);
        printf("salary: %d \n", arr[i].salary);
        printf("\n \n");
    }
    printf("----------------------------------------------------------------- \n \n");

    printf("---- Sort the employee arrray in ascending order of SALARY ---- \n \n");

    qsort(arr, 10, sizeof(struct Employee), compareSalary);

    for (int i = 0; i < 10; i++)
    {
        printf("------ sinh vien %d: --------\n ", i + 1);
        printf("id: %d \n", arr[i].id);
        printf("name: %s \n", arr[i].name);
        printf("sex: %s \n", arr[i].sex);
        printf("birthyear: %d \n", arr[i].birthyear);
        printf("salary: %d \n", arr[i].salary);
        printf("\n \n");
    }
    printf("----------------------------------------------------------------- \n \n");

    printf("---- EMPLOYEE WITH MAXIMUN SALARY ---- \n \n");

    int max = 0;

    for (int i = 0; i < 10; i++)
    {
        if (max < arr[i].salary)
        {
            max = arr[i].salary;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (max == arr[i].salary)
        {
            printf("id: %d \n", arr[i].id);
            printf("name: %s \n", arr[i].name);
            printf("sex: %s \n", arr[i].sex);
            printf("birthyear: %d \n", arr[i].birthyear);
            printf("salary: %d \n", arr[i].salary);
            printf("\n \n");
        }
    }
    printf("--------------------------------- \n \n");
    printf("---- THE YOUNGEST EMPLOYEE ---- \n \n");

    int min = 0;

    for (int i = 0; i < 10; i++)
    {
        if (min < arr[i].birthyear)
        {
            min = arr[i].birthyear;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        if (min == arr[i].birthyear)
        {
            printf("id: %d \n", arr[i].id);
            printf("name: %s \n", arr[i].name);
            printf("sex: %s \n", arr[i].sex);
            printf("birthyear: %d \n", arr[i].birthyear);
            printf("salary: %d \n", arr[i].salary);
            printf("\n \n");
        }
    }
    printf("-------------------------------------- \n \n");

    int deleteId;
    printf("------------------------ DELETE ---------------------------\n\n");

    printf("enter an id of Employee you want to delete: ");
    scanf("%d", &deleteId);
    printf("\n \n");
    for (int i = 0; i < 9; i++)
    {
        if (arr[i].id == deleteId)
        {
            continue;
        }
        else
        {
            printf("id: %d \n", arr[i].id);
            printf("name: %s \n", arr[i].name);
            printf("sex: %s \n", arr[i].sex);
            printf("birthyear: %d \n", arr[i].birthyear);
            printf("salary: %d \n", arr[i].salary);
            printf("\n \n");
        }
    }
    printf("----------------------------------------------------------");

    return 0;
}