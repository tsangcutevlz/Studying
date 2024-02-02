// #pragma once
#include <iostream>
#include <string>
#include "bronzeCustomer.cpp"
#include "silverCustomer.cpp"
#include "goldenCustomer.cpp"

class Account
{
private:
    int money;

    std::string name;
    std::string taikhoan;
    std::string password;


    static int nextId;
    int id;

public:
    Account() : money(90000), name(""), taikhoan(""), password(""), id() {}
    Account(int money, std::string name, std::string taikhoan, std::string password) : money(money), name(name), taikhoan(taikhoan), password(password)
    {
        id = nextId++;
    }

    // ---------------- Get && Set attributes ----------------
    int getMoney()
    {
        return money;
    }
    int getId() const
    {
        return id;
    }
    std::string getName()
    {
        return name;
    }
    static int getNextId()
    {
        return nextId;
    }

    // std::string getTaikhoan(){
    //     return taikhoan;
    // }
    void setMoney(int money)
    {
        this->money = money;
    }
    void setName(std::string name)
    {
        this->name = name;
    }

    void setTaiKhoan(std::string taikhoan)
    {
        this->taikhoan = taikhoan;
    }

    void setPassword(std::string password)
    {
        this->password = password;
    }
    void sendMoney(int moneySent)
    {
        std::cout << "ban da gui: " << moneySent << " (vnd)" << std::endl;
        setMoney(this->money - moneySent);
    }
    // ---------------- End Get && Set ----------------
    // BRONZE SILVER GOLD TIER CUSTOMER
    void initTier(){
        if(this->money >= 300000){

        }
    }
};