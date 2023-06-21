#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include "Date.h"
#include "Stock.h"

using namespace std;

class Product{
public:
    Product(){}
    Product(int&, string&, float&, string&, Date&, int&);

    int get_id_of_product(){ return id; }
    string get_name_of_product(){ return name; }
    string get_brand_of_product(){ return brand; }
    float get_price_of_product(){ return price; }
    Date get_date_of_product(){ return expire_date; }
    int get_stock_of_product(){ return Stock::get_stock_of_product(get_id_of_product()); }

    void print_product();
    string print_product_in_file();

private:
    int id;
    string name;
    float price;
    string brand;
    Date expire_date;
};


#endif // PRODUCT_H_INCLUDED
