#include<iostream>

using namespace std;

class Array {
public:
	int* arr;
	int n;
	// Khai báo phương thức hủy cho lớp Array
	~Array() {
		cout << "Destructor called" << endl;
		delete[] arr;
	}
};

void someFunc1() {
	Array a;
	a.n = 3;
	a.arr = new int[a.n];
	// Some code	
}
int main() {
	someFunc1();
	return 0;
}