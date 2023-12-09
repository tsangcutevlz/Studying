#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> v;
    for (int i = 1; i <= 5; i++) {
        v.push_back(i);
    }

    v.pop_back();

    for (auto x : v) {
        cout << x << " ";
    }
    return 0;
}