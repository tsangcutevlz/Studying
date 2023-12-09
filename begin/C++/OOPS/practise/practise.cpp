#include <iostream>
using namespace std;

class TrafficCongest
{
private:
    string product;
    string name;
    int year;
    float maxSpeed;

public:
    TrafficCongest()
    {
    }
    TrafficCongest(string product, string name, int year, float maxSpeed) : product(product), name(name), year(year), maxSpeed(maxSpeed) {}

    void setProduct()
    {
        this->product = product;
    }

    string getProduct(string product)
    {
        return product;
    }

    void setName()
    {
        this->name = name;
    }

    string getName(string name)
    {
        return name;
    }

    void setYear()
    {
        this->year = year;
    }

    int getYear(int year)
    {
        return year;
    }

    void setMaxSpeed()
    {
        this->maxSpeed = maxSpeed;
    }

    float getMaxSpeed(float maxSpeed)
    {
        return maxSpeed;
    }
    void display()
    {
        cout << "ten hang: " << this->product << endl;
        cout << "ten xe: " << this->name << endl;
        cout << "nam: " << this->year << endl;
        cout << "toc do toi da: " << this->maxSpeed << endl;
    }
};
int main()
{
    int n;
    string product;
    string name;
    int year;
    float maxSpeed;
    // cout << "nhap so phan tu cua mang: ";
    // cin >> n;

    cin >> product >> name >> year >> maxSpeed;
    TrafficCongest *something[n];

    for (int i = 0; i < n; i++)
    {
        cin >> product >> name >> year >> maxSpeed;
        something[i](product, name, year, maxSpeed);
    }

    something.display();

    return 0;
}