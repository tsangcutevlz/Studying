#include <iostream>
#include <math.h>

using namespace std;

int count(int n){
    int dem = 0;
    while(n>0){
        dem++;
        n/=10;
    }
    return dem;
}

int check(int n)
{
    int k = count(n);
    int save = n;
    int sum = 0;
    while(n>0){
        sum += pow(n%10,k);
        n/=10;
    }
    if(save == sum) return 1;
    return 0;
}

int main()
{
    int n;
    cin >> n;
    if(check(n)){
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}