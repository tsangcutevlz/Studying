#include "Customer.cpp"

class Invoice{
private:
    Customer customer;
    int id;
    double amount;
public:
    Invoice(int id, Customer customer, double amount){
        this->id = id;
        this->customer = customer;
        this->amount = amount;
    }

    int getId(){
        return id;
    }
    void setCustomer(Customer customer){
        this->customer = customer;
    }
    Customer getCustomer(){
        return customer;
    }

    double getAmount(){
        return amount;
    }
    void setAmount(double amount){
        this->amount = amount;
    }

    void setId(int id){
        this->id = id;
    }

    string getCustomerName(){
        return customer.getName();
    }

    double getAmountAfterDiscount(){
        return amount - amount * customer.getDiscount() / 100;
    }
};