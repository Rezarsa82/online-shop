#ifndef STORE_H_INCLUDED
#define STORE_H_INCLUDED

#define MAX_SIZE 1000
#include "Date.h"
#include "Product.h"
#include "Customer.h"
#include "Stock.h"
#include "Receipt.h"
#include <fstream>
#include <string>

class Store{
public:
    Store(Date);
    ~Store();

    void check_out(int);
    void add_cusotmer();
    void add_product();
    void view_products() ;
    void save_to_file();
    void sales_report(string, string);

    static void add_to_product_by_file(string&, string&, string&, string&, string&, string&);
    static void add_to_customer_by_file(string&, string&, string&, string&, string&, string&);
    static void set_number_of_products(int p){ number_of_products = p; }
    static unsigned int get_number_of_products(){ return number_of_products; }
    static void set_number_of_customers(int c){ number_of_customers = c; }
    static unsigned int get_number_of_customers(){ return number_of_customers; }
    static Product &get_product(int i){ return list_of_products[i]; }
    static Customer &get_customer(int i){ return list_of_customers[i]; }
    static void set_date_of_today(Date &d){ date_of_today = d; }
    static Date get_date_of_today(){ return date_of_today; }
    static void end_of_day(){ date_of_today.tick(); }
    static void tick(){ date_of_today.tick(); }

private:
    static Product list_of_products[MAX_SIZE];
    static Customer list_of_customers[MAX_SIZE];
    static unsigned int number_of_products;
    static unsigned int number_of_customers;
    static Date date_of_today;
};

#endif // STORE_H_INCLUDED
