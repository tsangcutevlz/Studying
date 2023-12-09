#include <iostream>

using namespace std;

void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int arr[], int L, int R)
{
    if (L >= R)
        return;
    int i = L, j = R, x = arr[(L + R) / 2];
    while(i <= j){
        while(i<=R && arr[i] < x) i++;
        while(j>=L && arr[j] > x) j--;
        if(i <= j){
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    quicksort(arr, L, j);
    quicksort(arr, i, R);
}

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}