#include <stdio.h>
#include <math.h>

void find(int matrix[100][100], int n, int low[100][100], int high[100][100])
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i < j)
                low[i][j] = 0;
            if (i == j)
                low[i][j] = 1;
            if (i > j)
                high[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i <= j)
            {
                high[i][j] = matrix[i][j];
                for (k = 0; k < i; k++)
                {
                    high[i][j] -= low[i][k] * high[k][j];
                }
            }
            else
            {
                low[i][j] = matrix[i][j] / high[j][j];
                for (k = 0; k < j; k++)
                {
                    low[i][j] -= (low[i][k] * high[k][j]) / high[j][j];
                }
            }
        }
    }
}

// Hàm để tính định thức từ phân rã LU
int dinhThuc(int low[100][100], int high[100][100], int n)
{
    int det = 1.0;
    for (int i = 0; i < n; i++)
    {
        det *= high[i][i];
    }
    return det;
}

int main()
{
    int n;
    int matrix[100][100];
    printf("nhap n: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", &matrix[i][j]);
        }
    }

    int low[100][100], high[100][100];

    find(matrix, n, low, high);

    int det = dinhThuc(low, high, n);

    printf("\n");
    printf("Định thức của ma trận là: %lf\n", det);

    return 0;
}