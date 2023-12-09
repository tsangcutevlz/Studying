#include "Author.cpp"
#include <vector>

class Book : public Author
{
private:
    string name;
    double price;
    vector<Author> authors;

public:
    Book(string name, vector<Author> authors, double price)
    {
        this->name = name;
        this->price = price;
        this->authors = authors;
    }

    void setName(string name)
    {
        this->name = name;
    }
    void setPrice(double price)
    {
        this->price = price;
    }

    string getName()
    {
        return name;
    }
    double getPrice()
    {
        return price;
    }

    string getAuthorNames()
    {
        string authorNames = "";
        for (int i = 0; i < authors.size() - 1; i++)
        {
            authorNames += authors[i].getName() + ", ";
        }
        authorNames += authors[authors.size() - 1].getName();
        return authorNames;
    }
};