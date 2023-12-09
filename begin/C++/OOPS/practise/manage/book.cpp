#pragma once
#include<iostream>

using namespace std;

class Book{
private:
    string nameBook;
    string nameAuthor;
    int numberBook;
public:
    Book(){

    }

    Book(string nameBook, string nameAuthor, int numberBook): nameBook(namebook), nameAuthor(nameAuthor), numberBook(numberBook) {}

    string getNameBook(){
        return nameBook;
    }
    string getNameAuthor(){
        return nameAuthor;
    }
    int getNumberBook(){
        return numberBook;
    }

};