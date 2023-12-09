#include <iostream>

using namespace std;

class Math {
public:
	static int max(int a, int b) {
		return a > b ? a : b;
	}

	static int max(int a, int b, int c) {
		return max(max(a, b), c);
	}
};

int main() {
	cout << Math::max(4, 2) << endl;
	cout << Math::max(2, 6, 4) << endl;
	return 0;
}