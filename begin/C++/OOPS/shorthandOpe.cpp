#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    // Nạp chồng toán tử +=
    void operator+=(const Complex& other) {
        real += other.real;
        imag += other.imag;
    }

    void display() const {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

int main() {
    Complex c1(2.0, 3.0);
    Complex c2(1.0, 1.0);

    c1 += c2; // Sử dụng toán tử +=
    c1.display(); // Kết quả sẽ là 3 + 4i

    return 0;
}