#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED

#define MAX_SIZE 1000

#include "Cart.h"
#include "Receipt.h"

class Customer{
public:
    Customer(){}
    Customer(int&, string&, string&, string&, float&, unsigned int&);

    void convert_cart_to_receipt();
    float get_total_purchace_amount();

    int get_id_of_customer(){ return id; }
    string get_name_of_customer(){ return name; }
    string get_phone_number_of_customer(){ return phone_number; }
    string get_address_of_customer(){ return address; }
    float get_balance_of_customer(){ return balance; }
    unsigned int get_number_of_receipts(){ return number_of_receipts; }
    Cart &get_cart(){ return cart; }
    //Receipt get_receipt(int id){ return list_of_receipts[id]; }

    void add_receipt(Receipt &r){ list_of_receipts[number_of_calculated_receipts] = r; number_of_calculated_receipts++; }
    void change_stocks_of_cart();
    bool check_balance(Cart&);
    void print_customer();
    string print_customer_in_file();
    string print_receipts(int&);

private:
    int id;
    string name;
    string phone_number;
    Receipt list_of_receipts[MAX_SIZE];
    string address;
    Cart cart;
    float balance;
    float total_amount = 0;
    unsigned int number_of_calculated_receipts = 0;
    unsigned int number_of_receipts = 0;
};

#endif // CUSTOMER_H_INCLUDED
