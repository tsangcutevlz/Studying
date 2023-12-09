#pragma once
#include <iostream>
using namespace std;


class Author
{
private:
    string name;
    string email;

public:
    Author(){
        
    }
    Author(string name, string email)
    {
        this->name = name;
        this->email = email;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setEmail(string email)
    {
        this->email = email;
    }

    string getEmail(){
        return email;
    }

    string getName(){
        return name;
    }
};