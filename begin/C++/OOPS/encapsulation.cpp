#include<iostream>
using namespace std;

class Rectangle{
private:
    double length;
    double width;
public:
    Rectangle(){

    }
    Rectangle(double length, double width){
        this->length = length;
        this->width = width;
    }
    void setLength(double length){
        this->length = length;
    }
    double getLength(){
        return length;
    }
    void setWidth(double width){
        this->width = width;
    }
    double getWidth(){
        return width;
    }

    double getArea(){
        return width*length;
    }
    double getPerimeter(){
        return (width + length)*2;
    }
};

int main(){
	Rectangle r(4, 5);
	cout << "Area: " << r.getArea() << endl;
	cout << "Perimeter: " << r.getPerimeter() << endl;
	r.setLength(2);
	r.setWidth(3);
	cout << "Area: " << r.getArea() << endl;
	cout << "Perimeter: " << r.getPerimeter() << endl;
	return 0;

    return 0;
}