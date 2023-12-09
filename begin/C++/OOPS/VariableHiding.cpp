#include <iostream>

using namespace std;

class SuperClass {
public:
	int x = 10;
	
	virtual void display() {
		cout << x << endl;
	}
};

class SubClass : public SuperClass {
public:
	int x = 20;

	void display() {
		cout << x << endl;
	}
};

int main() {
	SuperClass* s = new SubClass();
	cout << s->x << endl;
	s->display();
	return 0;
}