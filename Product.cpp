#include "Product.h"
#include "Stock.h"

Product::Product(int &i, string &na, float &p, string &b, Date &ex, int &st)
    : id(i), name(na), price(p), brand(b), expire_date(ex)
{
    Stock::setStock(i, st);
}

void Product::print_product(){
    cout << "Name: " << get_name_of_product() << endl
         << "Id: "  << get_id_of_product() << endl
         << "Brand: "  << get_brand_of_product() << endl
         << "Price: "  << get_price_of_product() << endl
         << "Stock: " << get_stock_of_product() << endl;
         expire_date.print();
         cout << endl;
}

string Product::print_product_in_file(){
    string month, day;
    if(expire_date.getMonth() < 10)
        month = "0" + to_string(expire_date.getMonth());
    else
        month = to_string(expire_date.getMonth());
    if(expire_date.getDay() < 10)
        day = "0" + to_string(expire_date.getDay());
    else
        day = to_string(expire_date.getDay());
    string product_info = "";
    product_info = "Id = " + to_string(get_id_of_product())
         + " Name = " + get_name_of_product()
         + " Brand = " + get_brand_of_product()
         + " Stock = " + to_string(get_stock_of_product())
         + " Price = " + to_string(get_price_of_product())
         + " Date = "
         + to_string(expire_date.getYear()) + "/"
         + month + "/"
         + day;
    return product_info;
}
