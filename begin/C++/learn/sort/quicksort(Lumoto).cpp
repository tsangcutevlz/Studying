#include <iostream>

using namespace std;

void swap(int*a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int L, int R){
    int pivot = R;
    int i = L - 1;
    for (int j = L; j < R; j++)
    {
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }

    i++;
    swap(arr[i], arr[pivot]);
    return i;
    
}

void quicksort(int arr[], int L, int R){
    if(L >= R) return;
    int p = partition(arr, L, R);
    quicksort(arr, L, p-1);
    quicksort(arr, p+1, R);
}

int main(){

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quicksort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    


    return 0;
}