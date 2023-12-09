#include <iostream>


using namespace std;
bool check(int n)
{
    int save = n;
    if(n < 10) return true;
    int help = 0;
    while(save > 0){
        help += save%10;
        help*=10;
        save /=10;
    }
    if(help /10 == n) return true;

    return false;
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